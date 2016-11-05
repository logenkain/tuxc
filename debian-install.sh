#!/bin/bash

echo -n "Installing required dependencies..."

apt-get install -y lua5.2-dev lua5.2 gcc



if [ ! -f ./tuxc ];then
    printf "Building executable...\n"
    make
    printf "Installing...\n"
    make install
else
    printf "Cleaning build environment...\n"
    make clean
    printf "Building executable...\n"
    make
    printf "Installing...\n"
    make install
fi
  
