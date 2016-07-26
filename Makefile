PREFIX=/usr

#OBJS specifies which files to compile as part of the project
OBJS = tuxc.c lib/liblogen.a

#CC specifies which compiler to use
CC = clang

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppress all warnings
COMPILER_FLAGS = -Wall

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -llua5.3

#OBJ_NAME specifies the name of our executable
OBJ_NAME= tuxc

#This is the target that compiles our executable
all	:	$(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
install :
	mkdir -p ${PREFIX}/share/tuxc
	cp tuxc ${PREFIX}/share/tuxc/
	cp -R package_managers ${PREFIX}/share/tuxc/
	ln -si ${PREFIX}/share/tuxc/tuxc ${PREFIX}/bin/tux
uninstall :
	rm ${PREFIX}/bin/tux
	rm -r ${PREFIX}/share/tuxc/package_managers
	rm ${PREFIX}/share/tuxc/tuxc
	rm -r ${PREFIX}/share/tuxc
clean :
	rm tuxc

