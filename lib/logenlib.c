#define KRED  "\x1B[31m"
#define KNRM  "\x1B[0m"

#define MAXLINE 1000
#define TRUE 1
#define FALSE 0

#include "logenlib.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <lauxlib.h>
#include <lualib.h>
#include <lua.h>


/* Check if file exists in:
 * /usr/local/sbin:/usr/local/bin:/usr/bin:/usr/sbin:/sbin:/bin
 */
int check_bin(char *file, int debug);

// Handle lua errors
void l_error (lua_State *L, const char *fmt, ...);    

/*Load config files. Additional arguments should be char arrays or pointers
 * improve this lib by having it autodetect if number or letter
 */
void load_config(char *filename, int number_of_args, ...);

int check_bin(char *file, int debug)
{

	int flag=0;
	int i;
	char path[MAXLINE];

	char *dirs[6];
  dirs[0] = "/usr/local/sbin/";
	dirs[1] = "/usr/local/bin/";
	dirs[2] = "/usr/bin/";
	dirs[3] = "/usr/sbin/";
	dirs[4] = "/sbin/";
	dirs[5] = "/bin/";
	
	for (i=0; i<5; i++ ){
		
		strcpy(path, dirs[i]);
		strcat(path,file);
		
		if (access( path, F_OK ) != -1 ) {
			flag = 1;
			if (debug == TRUE){
				printf("%s FOUND @ %s. Ending check.\n", file, path);
			}
			break;
			}
	}
	
	if (flag == 1) {
		return 0;
	}

	if (flag == 0 && debug == TRUE) {
		printf("%s Not Found!\n",file);
		return 1;
	}

	return 1;
}

/* Load global strings from <filename> */

void load_config(char *filename, int number_of_args, ...){
  int i =1;
  char *temp[number_of_args];

  va_list opt_args;

  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  if (luaL_loadfile(L, filename) || lua_pcall(L, 0, 0, 0))
    l_error(L, "cannot run configuration file: %s",
        lua_tostring(L, -1));
  va_start(opt_args, number_of_args);

  for(i = 0; i < number_of_args; i++)
  {
		temp[i] = va_arg(opt_args, char*);
    lua_getglobal(L, temp[i]);
    if (!lua_isstring(L, (i+1))){
          l_error(L, "%s WARNING: Missing variable: \"%s\"%s\n",KRED, temp[i], KNRM);
					strcpy(temp[i], " ");
          continue;
          }
    strcpy(temp[i], lua_tostring(L, (i+1) ));
  }
  va_end(opt_args);

  lua_close(L);
}

void l_error (lua_State *L, const char *fmt, ...) {
  va_list argp;
  va_start(argp, fmt);
  vfprintf(stderr,fmt, argp);
}
