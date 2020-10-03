#include <stdio.h>
#include <stdlib.h>
#include "maze_allocation_func.h"
#include "cell.h"

#define LINE_LENGTH 23
#define COLUMN_LENGTH 9

cell** allocate_space_maze(cell** maze){
	int column;
	
	maze = (cell **)calloc(COLUMN_LENGTH,sizeof(cell*));
	if(maze == NULL){
		printf("The allocation of the maze went wrong\n");
		exit(EXIT_FAILURE);
	}else{
		for(column=0; column<COLUMN_LENGTH;column++){
			maze[column]=(cell *)calloc(LINE_LENGTH,sizeof(cell));
				if(maze[column] == NULL){
					printf("The allocation of the maze line went wrong\n");
				}
			}
		}
	
	return maze;
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

void fill_maze(cell** maze){
	int line;
	int column;
	for(column=0;column<COLUMN_LENGTH; column++){
		for(line=0;line<LINE_LENGTH; line++){
			maze[column][line].content = '#';
			maze[column][line].line = column; //TODO Change
			maze[column][line].column = line;
		}
	}
}

void place_holes(cell** maze){
	int line;
	int column;
	int count =1;

	for(column=1;column<COLUMN_LENGTH; column+=2){
		for(line=1;line<LINE_LENGTH; line+=2){
			maze[column][line].id = count;
			maze[column][line].content = ' ';
			count +=1;
		}
	}
}