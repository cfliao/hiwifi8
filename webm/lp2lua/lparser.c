#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lparser.h"

#define IOWRITE "io.write([[%s]])\n"
#define STATEMENT	"%s\n"
#define VARIANT "io.write(tostring(%s))\n"

int lp2lua(FILE *lp_file, FILE *lua_file)
{
	int ch, len = 0;
	int lua = 0, thesis1 =0, thesis2 = 0, string = 0;
	          /* ( )         [ ] */
	int string_type = 0; /* 1: "       2: ' */
	int stmt_type = 0; /* 1: statement 2: variant */
	char buf[BUFSIZ];

	while ((ch = fgetc(lp_file)) != EOF) {
		if(lua) {
			switch(ch) {
				case '{':
					if(string)
						buf[len++] = ch;
					else if(!stmt_type)
						stmt_type = 1;
					else {
						buf[len] = 0;
						printf("parse error\n%s", buf);
						len = 0; lua = 0; string = 0; string_type =0; stmt_type = 0; thesis1=0; thesis2=0;
					}
					break;
				case '}':
					if(string)
						buf[len++] = ch;
					else if(stmt_type == 1 && thesis1 == 0 && thesis2 == 0) {
						buf[len] = '\0';
						fprintf(lua_file, STATEMENT, buf);
						len = 0; lua = 0; string = 0; string_type =0; stmt_type = 0; thesis1=0; thesis2=0;
					}
					else {
						buf[len] = 0;
						printf("parse error\n%s", buf);
						len = 0; lua = 0; string = 0; string_type =0; stmt_type = 0; thesis1=0; thesis2=0;
					}
					break;
				case '(':
					if(stmt_type == 0 && !string)
						thesis1 = 1;
					buf[len++] = ch;
					break;
				case ')':
					if(stmt_type == 0 && !string)
						thesis1 = 0;
					buf[len++] = ch;
					break;
				case '[':
					if(stmt_type == 0 && !string)
						thesis2 = 1;
					buf[len++] = ch;
				case ']':
					if(stmt_type == 0 && !string)
						thesis2 = 0;
					buf[len++] = ch;
					break;
				case '@':
					if(stmt_type == 0 && !string) {
						if(!thesis1 && !thesis2) {
							buf[len] = '\0';
							fprintf(lua_file, VARIANT, buf);
							len = 0; lua = 0; string = 0; string_type =0; stmt_type = 0; thesis1=0; thesis2=0;
						}
						lua = 1;
					}
					break;
				case '"':
					if(stmt_type == 0 && !string) {
						if(!thesis1 && !thesis2) {
							buf[len] = '\0';
							fprintf(lua_file, VARIANT, buf);
							len = 0; lua = 0; string = 0; string_type =0; stmt_type = 0; thesis1=0; thesis2=0;
						}
						else {
							string = 1;
							string_type = 1;
						}
					}
					else if(string_type == 1 && len && buf[len-1] != '\\') {
						/* string close */
						string = 0;
						string_type = 0;
					}
					buf[len++] = ch;
					break;
				case '\'':
					if(!string) {
						string = 1;
						string_type = 2;
					}
					else if(string_type == 2 && len && buf[len-1] != '\\') {
						/* string close */
						string = 0;
						string_type = 0;
					}
					buf[len++] = ' ';
					buf[len++] = ch;
					break;
				case ';':
				case '\n':
				case '\r':
				case ' ':
				case ',':
				case '<':
					if(!string && !thesis1 && !thesis2 && stmt_type == 0) {
						/* lua close */
						buf[len] = '\0';
						fprintf(lua_file, VARIANT, buf);
						len = 0; lua = 0; string = 0; string_type =0; stmt_type = 0; thesis1=0; thesis2=0;
					}
					buf[len++] = ch;
					break;
				case '@':
					if(len == 0) {
						len = 0;
						lua = 0; string = 0; string_type =0; stmt_type = 0; thesis1=0; thesis2=0;
					}
					buf[len++] = ch;
					break;
				default:
					buf[len++] = ch;
					break;
			}
		}
		else if(ch == '@') {
			if(len > 0) {
				buf[len] = '\0';
				fprintf(lua_file, IOWRITE, buf);
			}
			lua = 1; len = 0;
		}
		else {
			buf[len++] = ch & 0xff;
			if (len == ((int) sizeof(buf)-1)) {
				buf[len] = '\0';
				fprintf(lua_file, IOWRITE, buf);
				len = 0;
			}
		}
	}

	if(len) {
		buf[len] = '\0';
		fprintf(lua_file, IOWRITE, buf);
	}

	return 0;
}
