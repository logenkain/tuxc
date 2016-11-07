PREFIX=/usr

#OBJS specifies which files to compile as part of the project
OBJS = tuxc.c lib/logenlib.c

#CC specifies which compiler to use
#CC = clang

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppress all warnings
COMPILER_FLAGS = -Wall

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -llua5.2 -I/usr/include/lua5.2/

#OBJ_NAME specifies the name of our executable
OBJ_NAME= tuxc

#This is the target that compiles our executable
all	:	$(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
install :
	mkdir -p ${PREFIX}/share/${OBJ_NAME}
	cp tuxc ${PREFIX}/share/${OBJ_NAME}/
	cp -R package_managers ${PREFIX}/share/${OBJ_NAME}/
	ln -si ${PREFIX}/share/${OBJ_NAME}/${OBJ_NAME} ${PREFIX}/bin/tux
uninstall :
	rm ${PREFIX}/bin/tux
	rm -r ${PREFIX}/share/${OBJ_NAME}/package_managers
	rm ${PREFIX}/share/${OBJ_NAME}/${OBJ_NAME}
	rm -r ${PREFIX}/share/${OBJ_NAME}
clean :
	rm ${OBJ_NAME}

