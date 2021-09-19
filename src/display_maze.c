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
#include "display_maze.h"
#include "cell.h"
#include "useful.h"
#include "maze_allocation_func.h"

int LINE_LENGTH;
int COLUMN_LENGTH;

void display_maze(cell** maze){
	/* index to access the line of the matrix */
	int line;
	/* index to access column of the matrix */
	int column;

	for(column=0;column<COLUMN_LENGTH; column++){
		for(line=0;line<LINE_LENGTH; line++){
			printf("%d",maze[column][line].id);
		}
		printf("\n");
	}
}

void display_char_maze(cell** maze){
	/* index to access the line of the matrix */
	int line;
	/* index to access column of the matrix */
	int column;
	for(column=0;column<COLUMN_LENGTH; column++){
		for(line=0;line<LINE_LENGTH; line++){
			printf("%c",maze[column][line].content);
		}
		printf("\n");
	}
}

void display_cell_table(cell* cell_table){
	/* index to access the cells of the table */
	int line;
	line =0;
		while(cell_table[line].id != -1){
			line+=1;
		}
		printf("\n");
}

int init_dimension(int line, int column){
	/* Setting the global variable LINE_LENGTH */
	LINE_LENGTH = line;
	/* Setting the global variable COLUMN_LENGTH */
	COLUMN_LENGTH = column;
}

int get_maze_line(){
	return LINE_LENGTH;
}

int get_maze_column(){
	return COLUMN_LENGTH;
}