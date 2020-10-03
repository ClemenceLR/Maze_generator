#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "cell.h"
#include "useful.h"
#include "maze_allocation_func.h"

#define LINE_LENGTH 23
#define COLUMN_LENGTH 9

void display_maze(cell** maze){
	int line;
	int column;
	
	for(column=0;column<COLUMN_LENGTH; column++){
		for(line=0;line<LINE_LENGTH; line++){
			//printf("%c",maze[column][line].content);
			printf("%d",maze[column][line].id);
		}
		printf("\n");
	}
}

void display_char_maze(cell** maze){
	int line;
	int column;
	
	for(column=0;column<COLUMN_LENGTH; column++){
		for(line=0;line<LINE_LENGTH; line++){
			printf("%c",maze[column][line].content);
			//printf("%d",maze[column][line].id);
		}
		printf("\n");
	}
}

void display_cell_table(cell* cell_table){
	int line=0;
		while(cell_table[line].id != -1){
			//printf("%d ", cell_table[line].id);
			line+=1;
		}
		printf("\n");
}