CC = gcc
CPPFLAGS = -Wall -Wextra -ansi -pedantic
CFLAGS = -I./include -c -g
OBJS =  main.c
LIBS = maze.c maze.h

main : $(OBJS)
	$(CC) $(OBJS) -o $(LIBS)
