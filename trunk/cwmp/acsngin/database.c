#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

#include "database.h"

MYSQL sql_instance, *sql_sock;

int database_connect()
{
	mysql_init(&sql_instance);

	if(!(sql_sock = mysql_real_connect(&sql_instance, "localhost", "root", "12345678",
					"acs", 0, NULL, 0))) 
	return -1;
}

int database_disconnect()
{
	mysql_close(sql_sock);
}

inline MYSQL * get_sql_sock()
{
	return (MYSQL*)sql_sock;
}

inline MYSQL * get_sql_instance()
{
	return &sql_instance;
}


