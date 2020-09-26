#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "cell.h"
#define LINE_LENGTH 23
#define COLUMN_LENGTH 9

cell** create_maze_area(cell** maze){
	//given an adress build a table of walls
	maze = allocate_space_maze(maze); 
	fill_maze(maze);
	display_maze(maze);
	
	return maze; //A CHANGER
}

cell** allocate_space_maze(cell** maze){
	int line;
	int column;
	
	maze = (cell **)calloc(COLUMN_LENGTH,sizeof(cell*));
	if(maze == NULL){
		printf("The allocation of the maze whent wrong\n");
		exit(EXIT_FAILURE);
	}else{
		for(column=0; column<COLUMN_LENGTH;column++){
			maze[column]=(cell *)calloc(LINE_LENGTH,sizeof(cell));
				if(maze[column] == NULL){
					printf("The allocation of the maze line whent wrong\n");
				}
			}
		}
	
	return maze;
}

void fill_maze(cell** maze){
	int line;
	int column;
	
	for(column=0;column<COLUMN_LENGTH; column++){
		for(line=0;line<LINE_LENGTH; line++){
			maze[column][line].content = '#';
		}
	}
}

void display_maze(cell** maze){
	int line;
	int column;
	
	for(column=0;column<COLUMN_LENGTH; column++){
		for(line=0;line<LINE_LENGTH; line++){
			printf("%c",maze[column][line].content);
		}
		printf("\n");
	}
}


void free_maze(cell** maze){
	int line;
	int column;
	for(column=0; column<COLUMN_LENGTH;column++){	
		cell* currentPtr = maze[column];
		free(currentPtr);
	}
	free(maze);
}

