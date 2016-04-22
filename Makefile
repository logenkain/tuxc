#OBJS specifies which files to compile as part of the project
OBJS = tuxc.c

#CC specifies which compiler to use
CC = cc 

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppress all warnings
COMPILER_FLAGS = -Wall

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS =

#OBJ_NAME specifies the name of our executable
OBJ_NAME= tuxc

#This is the target that compiles our executable
all	:	$(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

