/* Check if file exists in:
 * /usr/local/sbin:/usr/local/bin:/usr/bin:/usr/sbin:/sbin:/bin
 */

#define MAXLINE 1000
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <unistd.h>
#include <string.h>

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

	if (flag == 0) {
		printf("%s Not Found!\n",file);
		return 1;
	}

	return 1;
}

