
SOAP_FMAC5 int SOAP_FMAC6 __cwmp__EmptyPost(
	struct soap* soap, 
	struct _cwmp__Fault *cwmp__Fault, 
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetRPCMethods(
	struct soap* soap, 
	struct _cwmp__GetRPCMethodsResponse *cwmp__GetRPCMethodsResponse)
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__SetParameterValues(
	struct soap* soap, 
	struct _cwmp__SetParameterValuesResponse *cwmp__SetParameterValuesResponse)
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetParameterValues(
	struct soap* soap, 
	struct _cwmp__GetParameterValuesResponse *cwmp__GetParameterValuesResponse)
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetParameterNames(
	struct soap* soap, 
	struct _cwmp__GetParameterNamesResponse *cwmp__GetParameterNamesResponse)
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__SetParameterAttributes(
	struct soap* soap, 
	struct _cwmp__SetParameterAttributesResponse *cwmp__SetParameterAttributesResponse)
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetParameterAttributes(
	struct soap* soap, 
	struct _cwmp__GetParameterAttributesResponse *cwmp__GetParameterAttributesResponse)
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__AddObject(
	struct soap* soap, 
	struct _cwmp__AddObjectResponse *cwmp__AddObjectResponse)
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__DeleteObject(
	struct soap* soap, 
	struct _cwmp__DeleteObjectResponse *cwmp__DeleteObjectResponse)
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__Download(
	struct soap* soap, 
	struct _cwmp__DownloadResponse *cwmp__DownloadResponse)
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__Reboot(
	struct soap* soap, 
	struct _cwmp__RebootResponse *cwmp__RebootResponse)
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetQueuedTransfers(
	struct soap* soap, 
	struct _cwmp__GetQueuedTransfersResponse *cwmp__GetQueuedTransfersResponse)
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__ScheduleInform(
	struct soap* soap, 
	struct _cwmp__ScheduleInformResponse *cwmp__ScheduleInformResponse)
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__SetVouchers(
	struct soap* soap, 
	struct _cwmp__SetVouchersResponse *cwmp__SetVouchersResponse)
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetOptions(
	struct soap* soap, 
	struct _cwmp__GetOptionsResponse *cwmp__GetOptionsResponse)
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__Upload(
	struct soap* soap, 
	struct _cwmp__UploadResponse *cwmp__UploadResponse)
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__FactoryReset(
	struct soap* soap, 
	struct _cwmp__FactoryResetResponse *cwmp__FactoryResetResponse)
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

SOAP_FMAC5 int SOAP_FMAC6 __cwmp__GetAllQueuedTransfers(
	struct soap* soap, 
	struct _cwmp__GetAllQueuedTransfersResponse *cwmp__GetAllQueuedTransfersResponse)
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
