
#include <stdio.h>

#include "stdsoap2.h"

#include <mysql/mysql.h>
#include "database.h"

int log2db(struct soap* soap, char *message)
{
	char buf[256];
	register unsigned long ip = 0;

	ip = soap->ip;
	sprintf(buf, "insert into log values(0, '%ld.%ld.%ld.%ld', NULL, 1, '0', '%s')", 
			(ip >>24)&0xFF, (ip >>16)&0xFF, (ip >>8)&0xFF, ip &0xFF, message);

	if(mysql_query(get_sql_sock(), buf)) {
		DBGLOG(TEST, SOAP_MESSAGE(fdebug, "insert log failed\n%s\n", mysql_error(get_sql_instance())));
		return SOAP_OK;
	}

	return 0;
}

