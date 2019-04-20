# Tuxc
## A Small portable package manager wrapper  


## Usage:  

```
tux [options] [packages]

[Options]       [Description]

i  | install    Install Package(s)
ri | reinstall  Reinstall Package(s)
r  | remove     Remove Package(s)
s  | search     Search for Packages
p  | purge      Remove package(s) and associated files
u  | upgrade    Perform System Upgrade
c  | clean      Clean Package Cache
su | sup        Sync and Upgrade
```

## Supported Package Managers

* apt
* brew
* dnf
* eopkg
* equo
* pacman
* pkgman
* xbps-install
* yum
* zypper


  
## Building & Installing:  
### Dependencies:  

* git
* lua5.3
* lua5.3-dev
* clang ('make CC=gcc' to use gcc)
* make
* pkg-config

### Distro Specific Commands:

#### Ubuntu/Debian:  
  
```
$ apt install -y clang make pkg-config lua5.3-dev

```  

#### Arch Linux:  

```
$ sudo pacman -Sy git make clang pkg-config lua53

```  

#### Solus:  

```
$ sudo eopkg it clang make lua-devel glibc-devel pkg-config
```

#### Void Linux:  

```  
$ sudo xbps-install -S clang make lua-devel pkg-config glibc-devel 

```

### Compile:
```  
$ git clone http://github.com/logenkain/tuxc.git  
$ cd tuxc  
$ make  
$ make install  
```    

## Removing Using Make:  

```
$ make uninstall
```

## Install Script:  



> **_Note: This script only supports the distros listed below_**  

> **_Note: tuxc is already included in the Void Linux repositories_**

* Fedora
* Solus
* Debian & derivatives

> **_Note: install.sh requires root privileges_**
```
$ git clone https://github.com/logenkain/tuxc.git
$ cd tuxc/INSTALL && ./install.sh
```
Once the script completes, the tuxc binary can be found at:

```
/usr/bin/tux
```

Or just simply type the following in a terminal (without $):

```
$ tux
```






  
	
## Creating Custom Templates  

If you are using a distribution that Tuxc does not support; a blank template is provided for you to add support.  

Simply edit the **custom_template** file in ```/usr/share/tuxc/package_managers```  

The contents of the file are as follows:

```  
searchCommand = ""  
syncCommand = ""  
installCommand = ""  
reinstallCommand = ""  
removeCommand = ""  
purgeCommand = ""  
upgradeCommand = ""  
cleanCommand=""  
supCommand=""
```  

Between the quotes of each variable, type the corresponding command of your package manager  

**_Example:_**

```
searchCommand = "pacman -Ss"
```

Once each command is entered, save the file as:

**_/usr/share/tuxc/package_managers/myPkgMngr_** 


> **_Note: No file extension is required and your custom template will be ignored if a file extension is added_**

**_Example:_**

```
$ cp custom_template pacman
```
Then edit the new file with your favorite text editor 
> **_Note: The name of the file must be the same as the package manager binary_**

```
$ vim pacman
```

## Issues:

Please report any issues in the issue tracker


