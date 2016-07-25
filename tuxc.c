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

/* Must be set to FALSE for production!!!
 */
int DEBUG=FALSE;

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

	char searchCommand[50]="searchCommand";
	char syncCommand[50]="syncCommand";
	char installCommand[50]="installCommand";
	char reinstallCommand[50]="reinstallCommand";
	char removeCommand[50]="removeCommand";
	char cleanCommand[50]="cleanCommand";
	char purgeCommand[50]="purgeCommand";
	char upgradeCommand[50]="upgradeCommand";
	char supCommand[50]="supCommand";
  
	char *filename;

	switch(DEBUG) {
		case TRUE:
			filename = "package_managers/xbps-install";
			break;
		case FALSE:
			filename = "/usr/share/tuxc/package_managers/xbps-install";
			break;
		default:
			filename = "/usr/share/tuxc/package_managers/xbps-install";
			break;
	}

	


	load_config(filename, 9, &searchCommand, &syncCommand, &installCommand,
													&reinstallCommand, &removeCommand, &cleanCommand, 
													&purgeCommand, &upgradeCommand, &supCommand);



	if (strcmp(switches, "s") == 0 ||
			strcmp(switches, "-s") == 0 ||
			strcmp(switches, "search") == 0 ||
			strcmp(switches, "--search") == 0){
		strcpy(command, searchCommand);
		if (argc < 3){
			strcat(command, " \"\"");
		}
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
		if (argc < 3){
			help();
		}
		strcpy(command, installCommand);
	}
	else if (strcmp(switches, "ri") == 0 ||
			strcmp(switches, "-ri") == 0 ||
			strcmp(switches, "reinstall") == 0 ||
			strcmp(switches, "--reinstall") == 0){
		if (argc < 3){
			help();
		}
		strcpy(command, reinstallCommand);
	}
	else if (strcmp(switches, "r") == 0 ||
			strcmp(switches, "-r") == 0 ||
			strcmp(switches, "remove") == 0 ||
			strcmp(switches, "--remove") == 0){
		if (argc < 3){
			help();
		}
		strcpy(command, removeCommand);
	}
	else if (strcmp(switches, "p") == 0 ||
			strcmp(switches, "-p") == 0 ||
			strcmp(switches, "purge") == 0 ||
			strcmp(switches, "--purge") == 0){
		if (argc < 3){
			help();
		}
		strcpy(command, purgeCommand);
	}
	else if (strcmp(switches, "u") == 0 ||
			strcmp(switches, "-u") == 0 ||
			strcmp(switches, "upgrade") == 0 ||
			strcmp(switches, "--upgrade") == 0){
		if (argc < 3){
			help();
		}
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
		printf("The complete command is: %s\n", command);
	}

	system(command);
	return 0;
}

//***********Definitions*************

void help(void){
	printf("\n\n");
	printf("Usage: tuxc [options] [packages]\n\n");

	printf("\ti  | -i | install    Install Package(s)\n");
	printf("\tri | -ri| reinstall  Reinstall Package(s)\n");
	printf("\tr  | -r | remove     Remove Package(s)\n");
	printf("\ts  | -s | search     Search for Packages\n");
	printf("\tp  | -p | purge      Remove package(s) and associated files\n");
	printf("\tu  | -u | upgrade    Perform System Upgrade\n");
	printf("\tc  | -c | clean      Clean Package Cache\n");
	printf("\tsu | su | sup        Sync and Upgrade\n\n");
	exit(0);
}
