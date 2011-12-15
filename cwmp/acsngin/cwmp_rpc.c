
#include "soapH.h"
#include "log.h"

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__Inform(
	struct soap* soap, 
	struct _cwmp__Inform *cwmp__Inform, 
	struct _cwmp__InformResponse *cwmp__InformResponse)
{
	char message[256] = "RPC Inform Received";
	
	log2db(soap, message);
	
	cwmp__InformResponse->MaxEnvelopes = 1;
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__TransferComplete(
	struct soap* soap, 
	struct _cwmp__TransferComplete *cwmp__TransferComplete, 
	struct _cwmp__TransferCompleteResponse *cwmp__TransferCompleteResponse)
{
	char message[256] = "RPC TransferComplete Received";
	
	log2db(soap, message);

	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__AutonomousTransferComplete(
	struct soap* soap, 
	struct _cwmp__AutonomousTransferComplete *cwmp__AutonomousTransferComplete, 
	struct _cwmp__AutonomousTransferCompleteResponse *cwmp__AutonomousTransferCompleteResponse)
{
	char message[256] = "RPC AutonomousTransferComplete Received";
	
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__Kicked(
	struct soap* soap, 
	struct _cwmp__Kicked *cwmp__Kicked, 
	struct _cwmp__KickedResponse *cwmp__KickedResponse)
{
	char message[256] = "RPC Kicked Received";
	
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__RequestDownload(
	struct soap* soap, 
	struct _cwmp__RequestDownload *cwmp__RequestDownload, 
	struct _cwmp__RequestDownloadResponse *cwmp__RequestDownloadResponse)
{
	char message[256] = "RPC RequestDownload Received";
	
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__Fault(
	struct soap* soap, 
	struct _cwmp__Fault *cwmp__Fault)
{
	char message[256] = "RPC Fault Received";
	
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetRPCMethods(
	struct soap* soap, 
	struct _cwmp__GetRPCMethodsResponse *cwmp__GetRPCMethodsResponse)
{
	char message[256] = "RPC GetRPCMethods Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__SetParameterValues(
	struct soap* soap, struct _cwmp__SetParameterValuesResponse *cwmp__SetParameterValuesResponse)
{
	char message[256] = "RPC SetParameterValues Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetParameterValues(
	struct soap* soap, struct _cwmp__GetParameterValuesResponse *cwmp__GetParameterValuesResponse)
{
	char message[256] = "RPC GetParameterValues Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetParameterNames(
	struct soap* soap, struct _cwmp__GetParameterNamesResponse *cwmp__GetParameterNamesResponse)
{
	char message[256] = "RPC GetParameterNames Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__SetParameterAttributes(
	struct soap* soap, struct _cwmp__SetParameterAttributesResponse *cwmp__SetParameterAttributesResponse)
{
	char message[256] = "RPC SetParameterAttributes Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetParameterAttributes(
	struct soap* soap, struct _cwmp__GetParameterAttributesResponse *cwmp__GetParameterAttributesResponse)
{
	char message[256] = "RPC GetParameterAttributes Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__AddObject(
	struct soap* soap, struct _cwmp__AddObjectResponse *cwmp__AddObjectResponse)
{
	char message[256] = "RPC AddObject Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__DeleteObject(
	struct soap* soap, struct _cwmp__DeleteObjectResponse *cwmp__DeleteObjectResponse)
{
	char message[256] = "RPC DeleteObject Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__Download(
	struct soap* soap, struct _cwmp__DownloadResponse *cwmp__DownloadResponse)
{
	char message[256] = "RPC Download Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__Reboot(
	struct soap* soap, struct _cwmp__RebootResponse *cwmp__RebootResponse)
{
	char message[256] = "RPC Reboot Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetQueuedTransfers(
	struct soap* soap, struct _cwmp__GetQueuedTransfersResponse *cwmp__GetQueuedTransfersResponse)
{
	char message[256] = "RPC GetQueuedTransfers Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__ScheduleInform(
	struct soap* soap, struct _cwmp__ScheduleInformResponse *cwmp__ScheduleInformResponse)
{
	char message[256] = "RPC ScheduleInform Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__SetVouchers(
	struct soap* soap, struct _cwmp__SetVouchersResponse *cwmp__SetVouchersResponse)
{
	char message[256] = "RPC SetVouchers Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetOptions(
	struct soap* soap, struct _cwmp__GetOptionsResponse *cwmp__GetOptionsResponse)
{
	char message[256] = "RPC GetOptions Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__Upload(
	struct soap* soap, struct _cwmp__UploadResponse *cwmp__UploadResponse)
{
	char message[256] = "RPC Upload Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__FactoryReset(
	struct soap* soap, struct _cwmp__FactoryResetResponse *cwmp__FactoryResetResponse)
{
	char message[256] = "RPC FactoryReset Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetAllQueuedTransfers(
	struct soap* soap, struct _cwmp__GetAllQueuedTransfersResponse *cwmp__GetAllQueuedTransfersResponse)
{
	char message[256] = "RPC GetAllQueuedTransfers Response Received";
	log2db(soap, message);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__EmptyPost(
	struct soap* soap, 
	struct _cwmp__Fault *cwmp__Fault, struct _cwmp__KickedResponse *cwmp__KickedResponse)
{
	char message[256] = "RPC Fault Received";
	log2db(soap, message);
	return SOAP_OK;
}

