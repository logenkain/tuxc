PREFIX=/usr

#OBJS specifies which files to compile as part of the project
OBJS = tuxc.c lib/logenlib.c

#CC specifies which compiler to use
CC = clang

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppress all warnings
COMPILER_FLAGS = -Wall

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -llua5.2 -I/usr/include/lua5.2/

#OBJ_NAME specifies the name of our executable
OBJ_NAME = tuxc

#This is the target that compiles our executable
all	:	$(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
install :
	mkdir -p ${DESTDIR}${PREFIX}/share/${OBJ_NAME}
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f ${OBJ_NAME} ${DESTDIR}${PREFIX}/share/${OBJ_NAME}/${OBJ_NAME}
	cp -R -f package_managers ${DESTDIR}${PREFIX}/share/${OBJ_NAME}/package_managers
	ln -s ${DESTDIR}${PREFIX}/share/${OBJ_NAME}/${OBJ_NAME} ${DESTDIR}${PREFIX}/bin/tux
uninstall :
	unlink ${DESTDIR}${PREFIX}/bin/tux
	rm -r ${DESTDIR}${PREFIX}/share/${OBJ_NAME}/package_managers
	rm ${DESTDIR}${PREFIX}/share/${OBJ_NAME}/${OBJ_NAME}
	rm -r ${DESTDIR}${PREFIX}/share/${OBJ_NAME}
clean :
	rm ${OBJ_NAME}
