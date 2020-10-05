#ifndef DISPLAY_MAZE_H
#define DISPLAY_MAZE_H
#include "cell.h"

/* Display the maze in the console
 * @param maze : pointer on the maze memory space
 */
void display_maze(cell** maze);

void display_cell_table(cell* cell_table);

void display_char_maze(cell** maze, int line_m, int column_m);


#endif


