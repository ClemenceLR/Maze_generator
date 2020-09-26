CC = gcc
CPPFLAGS = -Wall -Wextra -ansi -pedantic
CFLAGS = -I./include -c -g
OBJS =  main.c
LIBS = maze.c maze.h cell.c cell.h

main : $(OBJS)
	$(CC) $(OBJS) -o maze_exe $(LIBS)
