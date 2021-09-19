/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex 
 * 
 * This file is owned by ENSICAEN students. No portion of this 
 * document may be reproduced, copied or revised without written 
 * permission of the authors.
 */

/*
 * @author  Clemence Le Roux
 * @version 1.1
 * @date    12/10/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include "maze_allocation_func.h"
#include "cell.h"

int LINE_LENGTH ;
int COLUMN_LENGTH;

cell** allocate_space_maze(cell** maze, int line_m,int column_m){
	int column;
	LINE_LENGTH = line_m;
	COLUMN_LENGTH = column_m;
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
			maze[column][line].content = 'X';
			maze[column][line].line = column;
			maze[column][line].column = line;
		}
	}
	maze[1][0].content = ' ';
	maze[COLUMN_LENGTH-2][LINE_LENGTH-1].content = ' ';
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