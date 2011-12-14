#include <stdio.h>

void generateSessionID(char * sessionid, int strength)
{
	register i = 0;
	srand(time(0));

	for(i = 0; i < strength && i < 4; i++) 
		sprintf(sessionid + i*32, "%08X%08X\0%08X%08X", rand(), rand(), rand(), rand());

	//sprintf(sessionid, "1234567890");
}

