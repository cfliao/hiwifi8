#include <stdio.h>

#define IOWRITE "io.write([[%s]])\n"
#define STATEMENT	"%s\n"
#define VARIANT "io.write(tostring(%s))\n"

int main(int argc, char **argv)
{
	FILE *fp = NULL;
	int ch, len, in_lua = 0, has_pair=0,in_ssi_tag = 0;
	int in_parenthesis = 0, in_quotes = 0, in_string = 0;	
	
	int lua = 0, thesis1 =0, thesis2 = 0, thesis3 = 0, string = 0;
	          /* ( )         [ ] */
	int string_type = 0; /* 1: "       2: ' */
	int stmt_type = 0; /* 1: statement 2: variant */
	char buf[BUFSIZ];

	fp = fopen(argv[1], "r");
	if(!fp) return -1;

	fprintf(stdout, "Begin Parsing...\n");

	while ((ch = fgetc(fp)) != EOF) {
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
						fprintf(stdout, STATEMENT, buf);
						len = 0; lua = 0; string = 0; string_type =0; stmt_type = 0; thesis1=0; thesis2=0;
					}
					else {
						buf[len] = 0;
						printf("parse error\n%s", buf);
						len = 0; lua = 0; string = 0; string_type =0; stmt_type = 0; thesis1=0; thesis2=0;
					}
					break;
				case '(':
					if(!string)
						thesis1 = 1;
					buf[len++] = ch;
					break;
				case ')':
					if(!string)
						thesis1 = 0;
					buf[len++] = ch;
					break;
				case '[':
					if(!string) 
						thesis2 = 1;
					buf[len++] = ch;
				case ']':
					if(!string)
						thesis2 = 0;
					buf[len++] = ch;
					break;
				case '"':
					if(!string) {
						string = 1;
						string_type = 1;
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
						fprintf(stdout, VARIANT, buf);
						len = 0; lua = 0; string = 0; string_type =0; stmt_type = 0; thesis1=0; thesis2=0;
					}
					else {
						buf[len++] = ch;
					}
					break;
				default:
					//if(!stmt_type) stmt_type = 2;
					buf[len++] = ch;
					break;
			}
		}
		else if(ch == '@') {
			if(len > 0) {
				buf[len] = '\0';
				fprintf(stdout, IOWRITE, buf);
			}
			lua = 1; len = 0;
		}
		else {
			buf[len++] = ch & 0xff;
			if (len == (int) sizeof(buf)) {
				buf[len] = '\0';
				fprintf(stdout, IOWRITE, buf);
				len = 0;
			}
		}
	}

	if(len) {
		buf[len] = '\0';
		fprintf(stdout, IOWRITE, buf);
	}
	fclose(fp);
}
