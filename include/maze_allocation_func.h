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
#ifndef MAZE_ALLOC_H
#define MAZE_ALLOC_H
#include "maze_allocation_func.h"
#include "cell.h"

/** Dynamically allocates the memory space needed for the maze
 * @param maze : pointer on the maze memory space
 * @param line_m : line dimension of the maze
 * @param column_m : column dimension of the maze
 */
cell** allocate_space_maze(cell** maze, int line_m,int column_m);

/** Free the memory space allocated to the matrix
 * @param maze : pointer on the maze memory space
 */
void free_maze(cell** maze);

/** Fill the maze cells with initiation values : id of the cells + content of the cells
 * @param maze : pointer on the maze memory space
 */
void fill_maze(cell** maze);

/** Create the maze with the ids of the firsts holes
 * Mandatory to initialize the maze
 * @param maze : pointer on the maze memory space
 */
void place_holes(cell** maze);


#endif