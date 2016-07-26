#ifndef LOGENLIB_H_INCLUDED
#define LOGENLIB_H_INCLUDED
#include<lua5.3/lua.h>

/**
 * Check common bin files (does not use PATH variable
 */
int check_bin(char*, int debug);
/**
 * Load a config file with lua (currently only supports strings)
 */
void load_config(char *filename, int number_of_args, ...);

void l_error (lua_State *L, const char *fmt, ...);
#endif
