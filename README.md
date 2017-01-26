# Tuxc
## A Small portable package manager wrapper  




  
## Install  
### Dependencies  

* git
* lua5.2
* lua5.2-dev
* clang (edit to use gcc)
* make

### Distro specific

#### Ubuntu/debian  

```  
sudo apt-get install git make clang lua5.2 lua5.2-dev  
```  

#### Arch Linux  

```
sudo pacman -Sy git make clang lua52  
```  

#### Void Linux  

```  
sudo xbps-install -S git make clang lua52 lua52-devel  
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




    


