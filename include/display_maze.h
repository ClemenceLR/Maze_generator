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
#ifndef DISPLAY_MAZE_H
#define DISPLAY_MAZE_H
#include "cell.h"

/** Display the id of the maze cells in the console
 * @param maze : pointer on the maze memory space
 */
void display_maze(cell** maze);

/** Display the content of a table of cells
* @param cell_table : table of cell structures
*/
void display_cell_table(cell* cell_table);

/** Display the content of the maze cells in the console, the main maze apearance.
* @param maer : pointer on the maze memory space
* @line_m : size of a maze line
* @column_m : size of a maze column
*/
void display_char_maze(cell** maze);

/** Initialize the dimentions of the maze, stored in global variables
* @param line
* @param column
*/
int init_dimension(int line, int column);

/** Return the maze line dimensions
*/
int get_maze_line();

/** Return the maze column dimensions
*/
int get_maze_column();


#endif


