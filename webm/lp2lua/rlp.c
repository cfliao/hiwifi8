#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <lua5.1/lua.h>
#include <lua5.1/lualib.h>
#include <lua5.1/lauxlib.h>

#define IOWRITE "io.write([[%s]])\n"
#define STATEMENT	"%s\n"
#define VARIANT "io.write(tostring(%s))\n"

int lp2lua(FILE *lp_file, FILE *lua_file)
{
	int ch, len;
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
					//if(!stmt_type) stmt_type = 2;
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
			if (len == (int) sizeof(buf)) {
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

#define TMP_FILE "/tmp/abcdef.lua"

int main() {
        int error;
        char *filepath = NULL;
        FILE *lp_file, *lua_file;

        lua_State *L = NULL;

        filepath = getenv("PATH_TRANSLATED");
        if(!filepath) {
                fprintf(stdout, "Content-type: text/html\r\n\r\n");
                fprintf(stdout, "failed to get envenrioment\n");
                return -1;
        }

        lp_file = fopen(filepath, "r");
        if(!lp_file) {
                fprintf(stdout, "Content-type: text/html\r\n\r\n");
                fprintf(stdout, "failed to open %s\n", filepath);
                return -1;
        }

        lua_file = fopen(TMP_FILE, "w");
        if(!lua_file) {
                fprintf(stdout, "Content-type: text/html\r\n\r\n");
                fprintf(stdout, "failed to create temp file: %s\n", filepath);
                fclose(lp_file);
                return -1;
        }

		lp2lua(lp_file, lua_file);
		fclose(lp_file);
		fclose(lua_file);

		setenv("RENDER_BODY", TMP_FILE, 1);
		L = lua_open();
        luaL_openlibs(L);
        error = luaL_dofile(L, "/www/clp_base.clua");
        if(L) lua_close(L);
        return 0;
}
