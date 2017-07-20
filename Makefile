SHELL = /bin/sh
PREFIX ?= /usr
LUA_53 = /usr/include/lua5.3
#OBJS specifies which files to compile as part of the project
OBJS = tuxc.c lib/logenlib.c

#CC specifies which compiler to use
CC = clang

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppress all warnings
COMPILER_FLAGS = -Wall

#LINKER_FLAGS specifies the libraries we're linking against

ifeq ($(wildcard $(LUA_53)),) # No lua5.3 dir in /usr/include? Link without it!
    LINKER_FLAGS = `pkg-config --cflags --libs lua`

else # Hmm, I guess there was a 5.3 dir...probably Debian based.
    LINKER_FLAGS = `pkg-config --cflags --libs lua5.3`
endif

#OBJ_NAME specifies the name of our executable
OBJ_NAME = tuxc

#This is the target that compiles our executable
all	:	$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(COMPILER_FLAGS) $(LDFLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
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
