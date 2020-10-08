CC = gcc
CPPFLAGS = -Wall -Wextra -ansi -pedantic
CFLAGS = -I./include -c -g
OBJS =  main.c
LIBS = display_maze.c display_maze.h cell.c cell.h useful.c useful.h maze_allocation_func.c maze_allocation_func.h maze_generation.c maze_generation.h user_input.c user_input.h

main : $(OBJS)
	$(CC) $(OBJS) -o maze_exe $(LIBS)
