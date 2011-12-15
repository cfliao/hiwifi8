
#include "cwmp_namespaces.h"
#include "httpget.h"

#include <mysql/mysql.h>

#include "session.h"
#include "database.h"


#include "cwmp_acs_stub.c"


SOAP_FMAC5 int SOAP_FMAC6 __cwmp__Inform(
	struct soap* soap, 
	struct _cwmp__Inform *cwmp__Inform, 
	struct _cwmp__InformResponse *cwmp__InformResponse)
{
	unsigned long ip = 0;
	char buf[256];
	
	ip = soap->ip;
	
	sprintf(buf, "insert into log values(0, '%ld.%ld.%ld.%ld', NULL, 1, '%s', '%s')", 
				(ip >>24)&0xFF, (ip >>16)&0xFF, (ip >>8)&0xFF, ip &0xFF, 
				cwmp__Inform->DeviceId->SerialNumber, __func__);
	if(mysql_query(get_sql_sock(), buf)) {
		DBGLOG(TEST, SOAP_MESSAGE(fdebug, "insert log failed\n%s\n", mysql_error(get_sql_instance())));
			return SOAP_OK;
	}

	cwmp__InformResponse->MaxEnvelopes = 1;
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__TransferComplete(
	struct soap* soap, 
	struct _cwmp__TransferComplete *cwmp__TransferComplete, 
	struct _cwmp__TransferCompleteResponse *cwmp__TransferCompleteResponse)
{
	char buf[256];
	unsigned long ip = 0;
	ip = soap->ip;
	
	sprintf(buf, "insert into log values(0, '%ld.%ld.%ld.%ld', NULL, 1, '0', '%s')", 
				(ip >>24)&0xFF, (ip >>16)&0xFF, (ip >>8)&0xFF, ip &0xFF, __func__);
	if(mysql_query(get_sql_sock(), buf)) {
		DBGLOG(TEST, SOAP_MESSAGE(fdebug, "insert log failed\n%s\n", mysql_error(get_sql_instance())));
			return SOAP_OK;
	}

	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__AutonomousTransferComplete(
	struct soap* soap, 
	struct _cwmp__AutonomousTransferComplete *cwmp__AutonomousTransferComplete, 
	struct _cwmp__AutonomousTransferCompleteResponse *cwmp__AutonomousTransferCompleteResponse)
{
	char buf[256];
	unsigned long ip = 0;
	ip = soap->ip;

	sprintf(buf, "insert into log values(0, '%ld.%ld.%ld.%ld', NULL, 1, '0', '%s')", 
				(ip >>24)&0xFF, (ip >>16)&0xFF, (ip >>8)&0xFF, ip &0xFF, __func__);
	if(mysql_query(get_sql_sock(), buf)) {
		DBGLOG(TEST, SOAP_MESSAGE(fdebug, "insert log failed\n%s\n", mysql_error(get_sql_instance())));
			return SOAP_OK;
	}
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__Kicked(
	struct soap* soap, 
	struct _cwmp__Kicked *cwmp__Kicked, 
	struct _cwmp__KickedResponse *cwmp__KickedResponse)
{
	char buf[256];
	unsigned long ip = 0;
	ip = soap->ip;

	sprintf(buf, "insert into log values(0, '%ld.%ld.%ld.%ld', NULL, 1, '0', '%s')", 
				(ip >>24)&0xFF, (ip >>16)&0xFF, (ip >>8)&0xFF, ip &0xFF, __func__);
	if(mysql_query(get_sql_sock(), buf)) {
		DBGLOG(TEST, SOAP_MESSAGE(fdebug, "insert log failed\n%s\n", mysql_error(get_sql_instance())));
			return SOAP_OK;
	}
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__RequestDownload(
	struct soap* soap, 
	struct _cwmp__RequestDownload *cwmp__RequestDownload, 
	struct _cwmp__RequestDownloadResponse *cwmp__RequestDownloadResponse)
{
	char buf[256];
	unsigned long ip = 0;
	ip = soap->ip;

	sprintf(buf, "insert into log values(0, '%ld.%ld.%ld.%ld', NULL, 1, '0', '%s')", 
				(ip >>24)&0xFF, (ip >>16)&0xFF, (ip >>8)&0xFF, ip &0xFF, __func__);
	if(mysql_query(get_sql_sock(), buf)) {
		DBGLOG(TEST, SOAP_MESSAGE(fdebug, "insert log failed\n%s\n", mysql_error(get_sql_instance())));
			return SOAP_OK;
	}
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__Fault(
	struct soap* soap, 
	struct _cwmp__Fault *cwmp__Fault)
{
	char buf[256];
	unsigned long ip = 0;
	ip = soap->ip;

	sprintf(buf, "insert into log values(0, '%ld.%ld.%ld.%ld', NULL, 1, '0', '%s')", 
				(ip >>24)&0xFF, (ip >>16)&0xFF, (ip >>8)&0xFF, ip &0xFF, __func__);
	if(mysql_query(get_sql_sock(), buf)) {
		DBGLOG(TEST, SOAP_MESSAGE(fdebug, "insert log failed\n%s\n", mysql_error(get_sql_instance())));
			return SOAP_OK;
	}
	return SOAP_OK;
}

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

