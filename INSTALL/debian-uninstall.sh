#!/bin/bash

# Colors
RED='\033[0;31m'
LRED="\033[1;31m"
BLUE="\033[0;34m"
LBLUE="\033[1;34m"
GREEN="\033[0;32m"
LGREEN="\033[1;32m"
YELLOW="\033[1;33m"
CYAN="\033[0;36m"
LCYAN="\033[1;36m"
PURPLE="\033[0;35m"
LPURPLE="\033[1;35m"
BWHITE="\e[1m"
NC='\033[0m' # No Color


function checkRoot() {
  if [[ $EUID -ne 0 ]]; then
    printf "${LRED}This script must be run as root${NC}\n" 1>&2
     exit 1
  fi
}



function askUninstall() {

    printf "${LRED}Are you sure you want to uninstall Tuxc? [y/n]${NC} "
    read choice
    
    if [ "${choice}" = y ] || [ "${choice}" = Y ] || [ "${choice}" = yes ] || [ "${choice}" = "YES" ];then
        uninstallTuxc
    else
        printf "${LCYAN}Uninstall aborted!${NC}\n"
    fi


}


function uninstallTuxc() {
  if [ ! -f /usr/bin/tux ];then
    printf "${LRED}Tux is not installed${NC}\n"
    exit

  else
    printf "${LRED}Uninstalling...${NC}\n"

    make uninstall -C ../

    if [ ! -f /usr/bin/tux ];then
      printf "${LGREEN}Tux is uninstalled${NC}\n"
    else
      printf "${LRED}There was a problem removing Tux from your system${NC}\n"
    fi
  fi
}


function removeDeps() {
    printf "${LRED}Do you want to remove all dependencies? [y/n]:${NC} "
    read choice

    if [ "${choice}" = y ] || [ "${choice}" = Y ] || [ "${choice}" = yes ] || [ "${choice}" = "YES" ];then
        apt-get -y remove clang make pkg-config lua5.3-dev
    else
        printf "${LCYAN}Keeping dependencies\n${NC}"
        exit 0;
    fi


}

checkRoot
askUninstall
removeDeps
