#include <stdio.h>
#include <mysql/mysql.h>

#include "stdsoap2.h"
#include "session.h"
#include "database.h"

#define COOKIE_DOMAIN "192.168.154.128"
#define COOKIE_PATH "/"


char cookie_domain[256];
char cookie_path[256];

inline void init_session_env()
{
	*cookie_domain = 0x00;
	*cookie_path = 0x00;

	strcpy(cookie_domain, COOKIE_DOMAIN);
	strcpy(cookie_path, COOKIE_PATH);
}

inline const char * get_cookie_domain()
{
	return cookie_domain;
}

inline const char * get_cookie_path()
{
	return cookie_path;
}

inline const int get_cookie_expire()
{
	return 30;
}

void new_session_id(char * sessionid, int strength)
{
	register i = 0;
	srand(time(0));

	for(i = 0; i < strength && i < 4; i++) 
		sprintf(sessionid + i*32, "%08X%08X\0%08X%08X", rand(), rand(), rand(), rand());
}

int session2database(struct soap* soap, const char *sessionid)
{
	unsigned long ip;
	char sql[256];

	MYSQL *sock;
	MYSQL_RES *res;

	ip = soap->ip;
	sock = get_sql_sock();

	// clear old session;
	sprintf(sql, "delete from session where Ip='%ld.%ld.%ld.%ld'", 	(ip >>24)&0xFF, (ip >>16)&0xFF, (ip >>8)&0xFF, ip &0xFF);
	mysql_query(sock, sql);
	
	sprintf(sql, "insert into session values('%s', '%ld.%ld.%ld.%ld', '', NULL)",
				sessionid,
				(ip >>24)&0xFF, (ip >>16)&0xFF, (ip >>8)&0xFF, ip &0xFF);

	
	if(mysql_query(sock, sql)) {
		DBGLOG(TEST, SOAP_MESSAGE(fdebug, "failed to add session entry:%s\n", sessionid));
		return SOAP_OK;
	}

	return 0;
}

int chk_session_valid(struct soap* soap, const char *sessionid)
{
	char sql[256];
	unsigned long ip;
	MYSQL *sock;
	MYSQL_RES *res;

	ip = soap->ip;
	sock = get_sql_sock();
	
	sprintf(sql, "select * from session where ID='%s' and Ip='%ld.%ld.%ld.%ld'",
				sessionid,
				(ip >>24)&0xFF, (ip >>16)&0xFF, (ip >>8)&0xFF, ip &0xFF);
	
	if(mysql_query(sock, sql)) {
		DBGLOG(TEST, SOAP_MESSAGE(fdebug, "failed query session: %s\n", sessionid));
		return SOAP_OK;
	}

	if(!(res = mysql_store_result(sock)))
		return 0;

	return mysql_num_rows(res);
	
}

