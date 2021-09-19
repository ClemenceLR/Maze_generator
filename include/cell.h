#ifndef CELL_H
#define CELL_H
#include "cell.h"

/** Structure of a cell, used to buid the maze
 * @param id : the id of the cell
 * @param content : the character contained by the cell : path : _ / player : o / wall : #
 * @param column : the column coordonate of the cell in the maze
 * @param line : the line coordonate of the cell in the maze
 * */
typedef struct{
	int id;
	char content; 
	int column;
	int line;
} cell;

#endif
