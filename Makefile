CC = gcc
CPPFLAGS = -Wall -Wextra -ansi -pedantic
CFLAGS = -I./include -c -g
OBJS =  main.c
LIBS = maze.c maze.h cell.c cell.h useful.c useful.h maze_allocation_func.c maze_allocation_func.h maze_generation.c maze_generation.h

main : $(OBJS)
	$(CC) $(OBJS) -o maze_exe $(LIBS)
