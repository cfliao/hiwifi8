#ifndef _SESSION_H_
#define _SESSION_H_

inline void init_session_env();
inline const char * get_cookie_domain();
inline const char * get_cookie_path();
inline const int get_cookie_expire();

void new_session_id(char * sessionid, int strength);

int session2database(struct soap* soap, const char *sessionid);
int chk_session_valid(struct soap* soap, const char *sessionid);
int chk_session_valid(struct soap* soap, const char *sessionid);

#endif /* ~_SESSION_H_ */
