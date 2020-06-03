OBJS = src/*.cpp
CC = g++
LINKER_FLAGS = -lSDL2 -lSDL2_image
OBJ_NAME = demo

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
