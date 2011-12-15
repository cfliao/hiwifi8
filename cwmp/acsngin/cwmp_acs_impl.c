#include "soapH.h"

#include <mysql/mysql.h>
#include "database.h"
#include "session.h"

#include "cwmp_namespaces.h"

void *process_request(void *p)
{
	struct soap *soap;
	soap = (struct soap*)p;
	
	pthread_detach(pthread_self());
	soap->recv_timeout = 300; // Timeout after 5 minutes stall on recv
	soap->send_timeout = 60; // Timeout after 1 minute stall on send
	if (soap_serve(soap) != SOAP_OK) { // process RPC request 
		printf("%s: ", __func__);
		soap_print_fault(soap, stderr); // print error
	}
	soap_destroy(soap);
	soap_end(soap);
	soap_free(soap);
	return NULL;
}

int main(int argc, char **argv)
{
	struct soap soap, *tsoap;
	pthread_t tid;
	
	int m, s, i;
	//soap_init2(&soap, SOAP_IO_KEEPALIVE, SOAP_IO_KEEPALIVE);
	soap_init(&soap);

#ifdef WITH_COOKIES
	// Cookie Support Initial
	init_session_env();
	soap.cookie_domain = get_cookie_domain();
	soap.cookie_path = get_cookie_path();
#endif

	//soap.max_keep_alive = 100; // at most 100 call per keep-alive session
	//soap.accept_timeout = 90; // Option: let server time out after 1.5 minutes of inactivity

	/*
	soap.cookie_max = 10;
	soap.cookie_domain = "...";
	soap.cookie_path = "/";	//the path which is used to filter/set cookies with this destination */

	if(!database_connect())
		return -1;
	
#ifdef WITH_FASTCGI
	//soap_getenv_cookies(&soap); // CGI app: grab cookies from 'HTTP COOKIE' env var
	return soap_serve(&soap);
#else

	m = soap_bind(&soap, NULL, 8080, 100);
	if(m < 0) {
		soap_print_fault(&soap,stderr);
		return -1;
	}
	else {
		fprintf(stderr, "Socket connection successful: master socket = %d\n", m);
		for (i = 1; ; i++) {
			s = soap_accept(&soap);
			if (s < 0) {
				soap_print_fault(&soap, stderr);
				break;
			}
			
			fprintf(stderr, "%d: connection from IP=%d.%d.%d.%d socket=%d\n", i,
					(int)((soap.ip>>24)&0xFF), 
					(int)((soap.ip>>16)&0xFF), 
					(int)((soap.ip>>8)&0xFF), 
					(int)(soap.ip&0xFF), s);

			tsoap = soap_copy(&soap);
			pthread_create(&tid, NULL, (void *(*)(void*))process_request, (void*)tsoap);
		}
	}

	/*
	soap_destroy(&soap); // clean up class instances
	soap_end(&soap); // clean up everything and close socket
	soap_free(&soap); */
	
	soap_done(&soap); // close master socket and detach context
#endif

}

