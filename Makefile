#OBJS specifies which files to compile as part of the project
OBJS = tuxc.c lib/liblogen.a

#CC specifies which compiler to use
CC = clang

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppress all warnings
COMPILER_FLAGS = -Wall

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -llua

#OBJ_NAME specifies the name of our executable
OBJ_NAME= tuxc

#This is the target that compiles our executable
all	:	$(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
install :
	mkdir /usr/share/tuxc
	cp tuxc /usr/share/tuxc/
	cp -R package_managers /usr/share/tuxc/
	ln -si /usr/share/tuxc/tuxc /usr/bin/tux
uninstall :
	rm /usr/bin/tux
	rm -r /usr/share/tuxc/package_managers
	rm /usr/share/tuxc/tuxc
	rm -r /usr/share/tuxc
clean :
	rm tuxc

