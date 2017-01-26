SHELL=/bin/sh
PREFIX=/usr

#OBJS specifies which files to compile as part of the project
OBJS = tuxc.c lib/logenlib.c

#CC specifies which compiler to use
CC = clang

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppress all warnings
COMPILER_FLAGS = -Wall

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = `pkg-config --cflags --libs lua`

#OBJ_NAME specifies the name of our executable
OBJ_NAME = tuxc

#This is the target that compiles our executable
all	:	$(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
install :
	mkdir -p ${DESTDIR}${PREFIX}/share/${OBJ_NAME}
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f ${OBJ_NAME} ${DESTDIR}${PREFIX}/bin/tux
	cp -R -f package_managers ${DESTDIR}${PREFIX}/share/${OBJ_NAME}/package_managers
uninstall :
	rm ${DESTDIR}${PREFIX}/bin/tux
	rm -r ${DESTDIR}${PREFIX}/share/${OBJ_NAME}/package_managers
	rmdir ${DESTDIR}${PREFIX}/share/${OBJ_NAME}
clean :
	rm ${OBJ_NAME}
