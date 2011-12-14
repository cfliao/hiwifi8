
#include <stdio.h>
#include <stdlib.h>

#include "soapH.h"
#include "acs.h"
#include "cwmp_namespaces.h"

#include <time.h>

int cwmp__Inform(struct soap *soap, char *endpoint, unsigned int RetryCount)
{
	static struct SOAP_ENV__Header header;
	static struct _cwmp__ID cwmp__ID;
	static char sid[16];
	int ret = 0;

	struct _cwmp__Inform req;
	struct _cwmp__InformResponse resp;

	memset(&req, 0, sizeof(struct _cwmp__Inform));
	memset(&header, 0, sizeof(struct SOAP_ENV__Header));
	memset(&cwmp__ID, 0, sizeof(struct _cwmp__ID));

	soap->header = &header;
	soap->header->cwmp__ID = &cwmp__ID;
	
	sprintf(sid, "%d", rand());
	cwmp__ID.__item = sid;

	req.DeviceId = cwmp_getDeviceId();
	req.MaxEnvelopes = 1;
	time(&(req.CurrentTime));
	req.RetryCount = RetryCount;
//	req.ParameterList = cwmp_get_ParameterValueList();

	//req.Event = cwmp_getEventList();
	
	//soap_putcookies(soap, "acs.hiwifi.net", "/", 1);

	ret = soap_call___cwmp__Inform(soap, endpoint,
							NULL, &req, &resp);

 	if(ret == SOAP_OK) printf("Inform Ok\n");
	return ret;

}

int main(int argc, char **argv)
{
	int ret = 0;
	int session = 1, retry = 0, wait = 0;
	
	char *endpoint = "http://192.168.154.128:8080";

	/* data model 初始化*/

	/* attribute 初始化 */

	/* Global List 初始化*/

	/* 获取STUN信息并初始化*/

	/* 初始化UDPServer */

	/* 初始化TCPServer */

	struct soap *soap;
	struct soap soap2;
	
	soap = &soap2;
	
	soap_init2(soap, SOAP_IO_KEEPALIVE, SOAP_IO_KEEPALIVE);
	soap->keep_alive = 300;
	soap->recv_timeout = 60;

//	soap->userid = "user";
//	soap->passwd = "user";

	do {
		if(SOAP_OK == cwmp__Inform(soap, endpoint, retry)) {
			fprintf(stdout, "Inform Success\n");
			break;
		}
		else if(soap->error == 401) {
			fprintf(stderr, "Faild to Authenticate\n");
		}

		fprintf(stderr, "Faild to Send Inform\n");
		soap_destroy(soap);

		/* Wait a moment. see TR-069 Amendment 3, Table 3. Page 29 of 197 */
		wait = (rand() %6 + 5) * (1+retry);
		fprintf(stderr, "Waiting %d seconds\n", wait);
		sleep(wait);
	
	} while(++retry < 10);

	for(;;){		
		fprintf(stdout, "Send Empty Post to ACS\n");
		if(SOAP_OK != soap_send___cwmp__EmptyPost(soap, endpoint)) {
			fprintf(stderr, "%s: failed to send__cwmp__EmptyPost\n", __func__);
			soap_print_fault(soap,stderr);
			continue;
		}

		fprintf(stdout, "Receive RPC from ACS\n");
		soap_serve(soap, endpoint);
		if(soap->error && soap->error != 204) {
			soap_print_fault(soap,stderr);
		}

		//soap_destroy(soap);

		if(soap->error == 502 || soap->error == 402 || soap->error == 204)
			break;
		
	}

	return 0;
}

