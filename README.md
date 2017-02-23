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
sudo apt-get install git make pkg-config clang lua5.3 liblua5.3-dev  
```  

#### Arch Linux  

```
sudo pacman -Sy git make clang pkg-config lua53  
```  

#### Void Linux  

```  
sudo xbps-install -S git make pkg-config clang lua53 lua53-devel  
```

### Build
```  
git clone http://github.com/logenkain/tuxc.git  
cd tuxc  
make  
make install  
```  

### Packages  

#### Void Linux  

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
	
##Creating templates  

If you are using a distribution that Tuxc does not support, a blank template is provided to add support.  

Simply edit the 'custom_template' file in ```/usr/share/tuxc/package_managers```  


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

Fill out the template according to your package manager's commands and save the file in the ```/usr/share/tuxc/package_managers/<pkgmanagername>```  

Where 'pkgmanagername' is replaced with the name of your package manager such as as 'apt-get',pacman, xbps-install etc  

Make sure you use the actual command name as tuxc will match the filenames of templates to those contained in /usr/bin