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

function getDeps() {
  printf "${LGREEN}Installing required dependencies...${NC}\n"

  apt-get install -y lua5.2-dev lua5.2 gcc
}


function installTuxc() {
  if [ ! -f /usr/bin/tux ];then
      printf "${LGREEN}Building executable...${NC}\n"
      make
      printf "${LGREEN}Installing...${NC}\n"
      make install
    else
      printf "${LGREEN}Cleaning build environment...${NC}\n"
      make clean
      printf "${LGREEN}Building executable...${NC}\n"
      make
      printf "${LGREEN}Installing...${NC}\n"
      make install
  fi

}

function uninstallTuxc() {
  if [ ! -f /usr/bin/tux ];then
    printf "${LRED}Tux is not installed${NC}\n"
    exit

  else
    printf "${LRED}Uninstalling...${NC}\n"

    make uninstall

    if [ ! -f /usr/bin/tux ];then
      printf "${LGREEN}Tux is uninstalled${NC}\n"
    else
      printf "${LRED}There was a problem removing Tux from your system${NC}\n"
    fi
  fi
}


case ${1} in

  install | -i)
    checkRoot
    installTuxc
  ;;

  uninstall | -u)
    checkRoot
    uninstallTuxc
  ;;

  * | help | -h)

    echo """
    Name: Tux

    Usage: ${0} [option]


    [Options]               [Description]

    install,   -i         install tux
    uninstall, -u       uninstall tux
    help,      -h            this message
          """
  ;;
esac
