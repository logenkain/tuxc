#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int check_file(char *pkg_mgr);
void help(void);

int DEBUG=1;

//Main

int main(int argc, char *argv[])
{
	int i = 0;
	char *PKM;
	char switches[10];
	char package[50];
	char command[100];
  

	//Add package managers to check for
  char *pkg_mgr[] = {
	  "xbps-install", "apt-get",
	  "pacman", "yum"
  };
	
	for (i=0; i < sizeof(pkg_mgr) / sizeof(pkg_mgr[0]); i++) {
    
		if (check_file(pkg_mgr[i]) == 0){
			PKM = pkg_mgr[i];
			break;
		}
	}
	if (DEBUG == 1){
		printf ("%s\n",PKM);
	}


	// placeholders
	strcpy(switches, "doctor"); 
  strcpy(package, "test package");
	// end placeholders

  strcat(command, PKM);
	strcat(command, " ");
	strcat(command, switches);
	strcat(command, " ");
	strcat(command, package);
	
	printf("%s\n", command);
	
//	system(command);
	
	return 0;
}

//***********Definitions*************

int check_file(char *pkg_mgr)
{

	char pathToFolder[] = "/usr/bin/";
	char *path;
	
	path = strcat(pathToFolder,pkg_mgr);
	
	
	if (access( path, F_OK ) != -1 ) {
		return 0;
	}else{
		return 1;
	}
}

void help(void){
	printf("This is the future help file!!!\n");
}
