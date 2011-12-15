#ifndef _DATABASE_H_
#define _DATABASE_H_

int database_connect();
int database_disconnect();
inline MYSQL * get_sql_sock();
inline MYSQL * get_sql_instance();

#endif /* ~_DATABASE_H_ */

