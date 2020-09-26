#ifndef CELL_H
#define CELL_H
#include "cell.h"

/* Structure of a cell, used to buid the maze
 * @param id : the id of the cell
 * @param content : the character contained by the cell : path : _ / player : o / wall : #
 * */
typedef struct{
	int id;
	char content; //wall = 219 path = 0
	char top_cell_content;
	char right_cell_content;
	char left_cell_content;
	char bottom_cell_content;
} cell;

#endif
