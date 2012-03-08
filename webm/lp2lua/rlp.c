#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <lua5.1/lua.h>
#include <lua5.1/lualib.h>
#include <lua5.1/lauxlib.h>

#include "lparser.h"

#define TMP_FILE "/tmp/abcdef.lua"

int main(int argc, char **argv) {
        int error;
        char *filepath = NULL;
        FILE *lp_file = NULL, *lua_file = NULL;
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
        error = luaL_dofile(L, "/www/rlp_base");
        if(L) lua_close(L);
        return 0;
}
