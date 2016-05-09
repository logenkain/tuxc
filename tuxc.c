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

  if (argv[2] && strlen(argv[2]) < PACKAGELENGTH){
		strcpy(package, argv[2]);
	}
	else{
		help();
		return 1;
	}

	// Load package manager specific shit here

	// make command = the base command... So if someone does 'tuxc s foobar'
	// in the case of XBPS, command will equal "xbps-query -Rs" We add the space later
  
	int example;
  
	char *searchCommand;
	char *syncCommand;
	char *installCommand;
	char *removeCommand;
	char *cleanCommand;

	if (strcmp(switches, "s") == 0 || 
			strcmp(switches, "S") == 0 ||
			strcmp(switches, "-s") == 0 ||
			strcmp(switches, "-S") == 0){
		strcpy(command, searchCommand);
	}

	else if (strcmp(switches, "i") == 0 ||
			strcmp(switches, "I") == 0 ||
			strcmp(switches, "-i") == 0 ||
			strcmp(switches, "-I") == 0){
		strcpy(command, installCommand);
	}

	
	////////////////////////////////////////

	
	strcat(command, " ");
	strcat(command, package);
  
	if (DEBUG==TRUE){
		printf("%s\n", command);
	}
	
//	system(command);
	return 0;
}

//***********Definitions*************

void help(void){
	printf("This is the future help file!!!\n");
}
