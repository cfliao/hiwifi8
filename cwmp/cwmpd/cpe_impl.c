
#include "soapH.h"


SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetRPCMethods(
	struct soap* soap, 
	struct _cwmp__GetRPCMethods *cwmp__GetRPCMethods, 
	struct _cwmp__GetRPCMethodsResponse *cwmp__GetRPCMethodsResponse)
{
        static struct MethodList method;
        static char *list[14] = {
               "GetRPCMethods",
               "SetParameterValues",
               "GetParameterValues",
               "GetParameterNames",
               "SetParameterAttributes",
               "GetParameterAttributes",
               "DeleteObject",
               "Reboot",
               "Download",
               "AddObject",
               "Upload",
               "FactoryReset",
               "GetQueuedTransfers",
               "ScheduleInform"
        };
        cwmp__GetRPCMethodsResponse->MethodList = &method;
        cwmp__GetRPCMethodsResponse->MethodList->__size = 14;
        cwmp__GetRPCMethodsResponse->MethodList->__ptrstring = &list[0];
	return SOAP_OK;
}
	
SOAP_FMAC5 int SOAP_FMAC6 __cwmp__SetParameterValues(
	struct soap* soap, 
	struct _cwmp__SetParameterValues *cwmp__SetParameterValues, 
	struct _cwmp__SetParameterValuesResponse *cwmp__SetParameterValuesResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetParameterValues(
	struct soap* soap, 
	struct _cwmp__GetParameterValues *cwmp__GetParameterValues, 
	struct _cwmp__GetParameterValuesResponse *cwmp__GetParameterValuesResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetParameterNames(
	struct soap* soap, 
	struct _cwmp__GetParameterNames *cwmp__GetParameterNames, 
	struct _cwmp__GetParameterNamesResponse *cwmp__GetParameterNamesResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__SetParameterAttributes(
	struct soap* soap, 
	struct _cwmp__SetParameterAttributes *cwmp__SetParameterAttributes, 
	struct _cwmp__SetParameterAttributesResponse *cwmp__SetParameterAttributesResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetParameterAttributes(
	struct soap* soap, 
	struct _cwmp__GetParameterAttributes *cwmp__GetParameterAttributes, 
	struct _cwmp__GetParameterAttributesResponse *cwmp__GetParameterAttributesResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__AddObject(
	struct soap* soap, 
	struct _cwmp__AddObject *cwmp__AddObject, 
	struct _cwmp__AddObjectResponse *cwmp__AddObjectResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__DeleteObject(
	struct soap* soap, 
	struct _cwmp__DeleteObject *cwmp__DeleteObject, 
	struct _cwmp__DeleteObjectResponse *cwmp__DeleteObjectResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__Download(
	struct soap* soap, 
	struct _cwmp__Download *cwmp__Download, 
	struct _cwmp__DownloadResponse *cwmp__DownloadResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__Reboot(
	struct soap* soap, 
	struct _cwmp__Reboot *cwmp__Reboot, 
	struct _cwmp__RebootResponse *cwmp__RebootResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetQueuedTransfers(
	struct soap* soap, 
	struct _cwmp__GetQueuedTransfers *cwmp__GetQueuedTransfers, 
	struct _cwmp__GetQueuedTransfersResponse *cwmp__GetQueuedTransfersResponse)
{
	return 0;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__ScheduleInform(
	struct soap* soap, 
	struct _cwmp__ScheduleInform *cwmp__ScheduleInform, 
	struct _cwmp__ScheduleInformResponse *cwmp__ScheduleInformResponse)
{
	return 0;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__SetVouchers(
	struct soap* soap, 
	struct _cwmp__SetVouchers *cwmp__SetVouchers, 
	struct _cwmp__SetVouchersResponse *cwmp__SetVouchersResponse)
{
	return 0;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetOptions(
	struct soap* soap, 
	struct _cwmp__GetOptions *cwmp__GetOptions, 
	struct _cwmp__GetOptionsResponse *cwmp__GetOptionsResponse)
{
	return 0;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__Upload(
	struct soap* soap, 
	struct _cwmp__Upload *cwmp__Upload, 
	struct _cwmp__UploadResponse *cwmp__UploadResponse)
{
	return 0;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__FactoryReset(
	struct soap* soap, 
	struct _cwmp__FactoryReset *cwmp__FactoryReset, 
	struct _cwmp__FactoryResetResponse *cwmp__FactoryResetResponse)
{
	return 0;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetAllQueuedTransfers(
	struct soap* soap, 
	struct _cwmp__GetAllQueuedTransfers *cwmp__GetAllQueuedTransfers, 
	struct _cwmp__GetAllQueuedTransfersResponse *cwmp__GetAllQueuedTransfersResponse)
{
	return 0;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__Fault(struct soap* soap, struct _cwmp__Fault *cwmp__Fault)
{
	return SOAP_OK;
}

