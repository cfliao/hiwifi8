#include <stdio.h>
#include "lparser.h"

int main(int argc, char **argv)
{
	FILE *fp = NULL;
	
	fp = fopen(argv[1], "r");
	if(!fp) return -1;

	fprintf(stdout, "Begin Parsing...\n");
	
	lp2lua(fp, stdout);
	
	fclose(fp);
}
