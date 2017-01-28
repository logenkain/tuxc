# Tuxc
## A Small portable package manager wrapper  




  
## Install  
### Dependencies  

* git
* lua5.3
* lua5.3-dev
* clang ('make CC=gcc' to use gcc)
* make
* pkg-config

### Distro specific

#### Ubuntu/debian  

```  
sudo apt-get install git make clang lua5.3 liblua5.3-dev  
```  

#### Arch Linux  

```
sudo pacman -Sy git make clang lua53  
```  

#### Void Linux  

```  
sudo xbps-install -S git make clang lua53 lua53-devel  
```

### Build
```  
git clone http://github.com/logenkain/tuxc.git  
cd tuxc  
make  
make install  
```  

### Packages  

#### Void Linux  (pending package acceptance)

```  
sudo xbps-install -S tuxc  
```  


## Usage  


Usage: tux [options] [packages]

	[Options]       [Description]

	i  | install    Install Package(s)
	ri | reinstall  Reinstall Package(s)
	r  | remove     Remove Package(s)
	s  | search     Search for Packages
	p  | purge      Remove package(s) and associated files
	u  | upgrade    Perform System Upgrade
	c  | clean      Clean Package Cache
	su | sup        Sync and Upgrade  
