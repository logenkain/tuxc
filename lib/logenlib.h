#ifndef LOGENLIB_H_INCLUDED
#define LOGENLIB_H_INCLUDED

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

#endif

