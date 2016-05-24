#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib/logenlib.h"

#define MAXLINE 2048
#define SWITCHLENGTH 10
#define PACKAGELENGTH 1000
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
	char package[PACKAGELENGTH] = "FALSE";
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

		for (i=3; i < argc; i++){
			if (strlen(package) + strlen(argv[i]) + 1 < PACKAGELENGTH){
					strcat(package, " ");
					strcat(package, argv[i]);
			}
			else{
				printf("Too many packages, chill out bro\n");
				return 1;
			}
		}
	}

	else if (strcmp(argv[1], "s")){
		//do nothing
	}

	// Load package manager specific shit here

	// make command = the base command... So if someone does 'tuxc s foobar'
	// in the case of XBPS, command will equal "xbps-query -Rs" We add the space later

	char *searchCommand;
	char *syncCommand;
	char *installCommand;
	char *reinstallCommand;
	char *removeCommand;
	char *cleanCommand;
	char *purgeCommand;
	char *upgradeCommand;
	char *supCommand;

/* The following will be praised from a file in the future
 * this is only temporary
 */

	searchCommand = "xbps-query -Rs";
	syncCommand = "xbps-install -S";
	installCommand = "xbps-install";
	reinstallCommand = "xbps-install -f";
	removeCommand = "xbps-remove";
	purgeCommand = "xbps-remove -R";
	upgradeCommand = "xbps-install -Su";
	cleanCommand="xbps-remove -O";
	supCommand="xbps-install -Su";

	/*End temporary code
	 */

	if (strcmp(switches, "s") == 0 ||
			strcmp(switches, "-s") == 0 ||
			strcmp(switches, "search") == 0 ||
			strcmp(switches, "--search") == 0){
		strcpy(command, searchCommand);
	}

	else if (strcmp(switches, "sy") == 0 ||
			strcmp(switches, "-sy") == 0 ||
			strcmp(switches, "sync") == 0 ||
			strcmp(switches, "--sync") == 0){
		strcpy(command, syncCommand);
	}
	else if (strcmp(switches, "i") == 0 ||
			strcmp(switches, "-i") == 0 ||
			strcmp(switches, "install") == 0 ||
			strcmp(switches, "--install") == 0){
		strcpy(command, installCommand);
	}
	else if (strcmp(switches, "ri") == 0 ||
			strcmp(switches, "-ri") == 0 ||
			strcmp(switches, "reinstall") == 0 ||
			strcmp(switches, "--reinstall") == 0){
		strcpy(command, reinstallCommand);
	}
	else if (strcmp(switches, "r") == 0 ||
			strcmp(switches, "-r") == 0 ||
			strcmp(switches, "remove") == 0 ||
			strcmp(switches, "--remove") == 0){
		strcpy(command, removeCommand);
	}
	else if (strcmp(switches, "p") == 0 ||
			strcmp(switches, "-p") == 0 ||
			strcmp(switches, "purge") == 0 ||
			strcmp(switches, "--purge") == 0){
		strcpy(command, purgeCommand);
	}
	else if (strcmp(switches, "u") == 0 ||
			strcmp(switches, "-u") == 0 ||
			strcmp(switches, "upgrade") == 0 ||
			strcmp(switches, "--upgrade") == 0){
		strcpy(command, upgradeCommand);
	}
	else if (strcmp(switches, "c") == 0 ||
			strcmp(switches, "-c") == 0 ||
			strcmp(switches, "clean") == 0 ||
			strcmp(switches, "--clean") == 0){
		strcpy(command, cleanCommand);
	}

	else if (strcmp(switches, "sup") == 0 ||
			strcmp(switches, "-Su") == 0 ||
			strcmp(switches, "su") == 0 ||
			strcmp(switches, "--sync-upgrade") == 0){
		strcpy(command, supCommand);
	}
	
	else{
		help();
		return 1;
	}

	////////////////////////////////////////

	/*Prevent catting an empty variable
	 */

	if (strcmp(package,"FALSE")){
		strcat(command, " ");
	  strcat(command, package);
	}

	if (DEBUG==TRUE){
		printf("%s\n", command);
	}

	system(command);
	return 0;
}

//***********Definitions*************

void help(void){
	printf("This is the future help file!!!\n");
}
