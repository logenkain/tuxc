#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib/logenlib.h"
#include <dirent.h>

#define MAXLINE 2048
#define SWITCHLENGTH 10
#define PACKAGELENGTH 1000
#define TRUE 1
#define FALSE 0

void help(void);

// Set to TRUE for debug information
int DEBUG=FALSE;

//Main

int main(int argc, char *argv[])
{
	int i;
	int	PKG_MGR_FOUND = FALSE;
	char switches[SWITCHLENGTH];
	char package[PACKAGELENGTH] = "FALSE";
	char command[MAXLINE];
	char filepath[MAXLINE];
	int number_of_package_managers = 0;

	//Add package managers to check for
  char *packageManagers[25];

	//make this a function

	char *template_path;
	template_path = "package_managers";
	DIR *d;
  struct dirent *dir;

	d = opendir(template_path);

	if (!d){
		template_path = "/usr/share/tuxc/package_managers";
		closedir(d);
		d = opendir(template_path);
	}

	if (d)
	{
		i=0;
		while ((dir = readdir(d)) != NULL)
		{

			if (strcmp(dir->d_name, ".") == 0 ||
					strcmp(dir->d_name, "..") == 0)
			{
				continue;
			}
			else{

				packageManagers[i] = dir->d_name;

				if (DEBUG == TRUE) {
				  printf("Added %s to array\n", packageManagers[i]);
			  }

				i++;
				number_of_package_managers = i;
			}

		}


		closedir(d);
	}

	//

	//Check which package manager exists
	for (i=0; i < number_of_package_managers; i++) {

		if (check_bin(packageManagers[i],DEBUG ) == 0)
		{
			PKG_MGR_FOUND = TRUE;
			strcpy(filepath, template_path);
			strcat(filepath, "/");
			strcat(filepath, packageManagers[i]);

			if (DEBUG == TRUE){
				printf("%s\n", filepath);
			}

			break;
		}
	}

	/*This should be a bug tracker, not my email. Fix once ported to not gitbutter.pw*/

	if (PKG_MGR_FOUND == FALSE){
		printf("\nYou're distribution package manager was not found\n");
		printf("Chances are that you use some crazy esoteric Linux Distro\n");
		printf("Feel free to send me an email at: \n");
		printf("logen@sudotask.com\n");
		printf("or simply hack your own template file at:\n\n");
		printf("/usr/share/tuxc/package_managers\n");
		exit(0);

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

	char searchCommand[50]="searchCommand";
	char syncCommand[50]="syncCommand";
	char installCommand[50]="installCommand";
	char reinstallCommand[50]="reinstallCommand";
	char removeCommand[50]="removeCommand";
	char cleanCommand[50]="cleanCommand";
	char purgeCommand[50]="purgeCommand";
	char upgradeCommand[50]="upgradeCommand";
	char supCommand[50]="supCommand";

	if (DEBUG == TRUE){
		printf("This is filepath: %s\n", filepath);
	}
	load_config(filepath, 9, searchCommand, syncCommand, installCommand,
													reinstallCommand, removeCommand, cleanCommand,
													purgeCommand, upgradeCommand, supCommand);

	if (strcmp(switches, "s") == 0 ||
			strcmp(switches, "-s") == 0 ||
			strcmp(switches, "search") == 0 ||
			strcmp(switches, "--search") == 0){
		strcpy(command, searchCommand);

		if (argc > 3){
			printf("\nSearch command only takes one argument!\n\n");
			exit(1);
		}

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

	printf("Tux: a drop in package manager wrapper\n\n");

	printf("Usage: tux [options] [packages]\n\n");

  printf("\t[Options]       [Description]\n\n");
	printf("\ti  | install    Install Package(s)\n");
	printf("\tri | reinstall  Reinstall Package(s)\n");
	printf("\tr  | remove     Remove Package(s)\n");
	printf("\ts  | search     Search for Packages\n");
	printf("\tp  | purge      Remove package(s) and associated files\n");
	printf("\tu  | upgrade    Perform System Upgrade\n");
	printf("\tc  | clean      Clean Package Cache\n");
	printf("\tsu | sup        Sync and Upgrade\n\n");
	exit(0);
}
