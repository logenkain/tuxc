#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "lib/logenlib.h"

#define MAXLINE 1024
#define SWITCHLENGTH 10
#define PACKAGELENGTH 50
#define TRUE 1
#define FALSE 0


void help(void);

int DEBUG=TRUE;

//Main

int main(int argc, char *argv[])
{
	int i;
	char *pkgMgr;
	char switches[SWITCHLENGTH];
	char package[PACKAGELENGTH];
	char command[MAXLINE];

	//Add package managers to check for
  char *packageManagers[] = {
	  "xbps-install", "apt-get",
	  "pacman", "yum"
  };
	
	//Check which package manager exists
	for (i=0; i < sizeof(packageManagers) / sizeof(packageManagers[0]); i++) {
    
		if (check_bin(packageManagers[i],DEBUG ) == 0){
			pkgMgr = packageManagers[i];
			break;
		}
	}

  
	if (argv[1] && strlen(argv[1]) < SWITCHLENGTH){
		strcpy(switches, argv[1]);
	}
	else{
		help();
		return 1;
	}

	// Add package manager specific shit here

	// Probably just use some sort of struct
	

	////////////////////////////////////////

	// placeholders
  if (argv[2] && strlen(argv[2]) < PACKAGELENGTH){
		strcpy(package, argv[2]);
	}
	else{
		help();
		return 1;
	}
	// end placeholders

  strcat(command, pkgMgr);
	strcat(command, " ");
	strcat(command, switches);
	strcat(command, " ");
	strcat(command, package);
  if (DEBUG==TRUE){
		printf("%s\n", command);
	}
	
//	system(command);
  printf("%d and %s\n",argc, argv[1]);	
	printf("the size of argv[1] is %lu\n", strlen(argv[1]));
	
	return 0;
}

//***********Definitions*************

void help(void){
	printf("This is the future help file!!!\n");
}
