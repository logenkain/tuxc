#ifndef LOGENLIB_H_INCLUDED
#define LOGENLIB_H_INCLUDED
#include<lua.h>
#include<stdio.h>

int check_bin(char*, int debug);
void load_config(char *filename, int number_of_args, ...);
void l_error (lua_State *L, const char *fmt, ...);
#endif
