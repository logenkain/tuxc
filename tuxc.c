#include <stdio.h>
#include <unistd.h>
#include <string.h>

int check_file(char *pkg_mgr);

//Main

int main(int argc, char *argv[])
{
	int i;
	char *mgr;

  char *pkg_mgr[] = {
	  "xbps-install", "apt-get",
	  "pacman", "yum"
  };
	
	for (i=0; i < sizeof(pkg_mgr) / sizeof(pkg_mgr[0]); i++) {
    
		if (check_file(pkg_mgr[i]) == 1){
			break;
		}
	}
printf("%s\n", pkg_mgr[i]);	



	return 0;	
}

//***********Definitions*************

int check_file(char *pkg_mgr)
{

	char pathToFolder[] = "/usr/bin/";
	char *path;
	
	path = strcat(pathToFolder,pkg_mgr);
	
	
	if (access( path, F_OK ) != -1 ) {
		printf( "%s exists\n", path);
		return 1;
	}else{
		printf( "%s does NOT exist\n", path);
	}
}
