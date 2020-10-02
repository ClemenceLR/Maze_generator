#ifndef MAZE_ALLOC_H
#define MAZE_ALLOC_H
#include "maze_allocation_func.h"
#include "cell.h"

/* Dynamically allocates the memory space needed for the maze
 * @param maze : pointer on the maze memory space
 */
cell** allocate_space_maze(cell** maze);


/* Free the memory space allocated to the matrix
 * @param maze : pointer on the maze memory space
 */
void free_maze(cell** maze);

/* Fill the maze cells with initiation values : id of the cells + content of the cells
 * @param maze : pointer on the maze memory space
 */
void fill_maze(cell** maze);

/* Create the maze with the ids of the firsts holes
 * Necessary to initialize the maze
 */
void place_holes(cell** maze);


#endif