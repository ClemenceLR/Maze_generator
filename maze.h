#ifndef MAZE_H
#define MAZE_H
#include "cell.h"
/* Creates a table of cells of the size 9 * 23 ans stock it at the adress given
 * @param maze : pointer on the maze memory space
 */
cell** create_maze_area(cell** maze);

/* Initialise the creation of the maze, from the allocation to the creation of the walls
 * @param maze : pointer on the maze memory space
 */
void maze_generator(cell** maze);

/* Dynamically allocates the memory space needed for the maze
 * @param maze : pointer on the maze memory space
 */
cell** allocate_space_maze(cell** maze);

/* Fill the maze cells with initiation values : id of the cells + content of the cells
 * @param maze : pointer on the maze memory space
 */
void fill_maze(cell** maze);

/* Display the maze in the console
 * @param maze : pointer on the maze memory space
 */
void display_maze(cell** maze);

/* Free the memory space allocated to the matrix
 * @param maze : pointer on the maze memory space
 */
void free_maze(cell** maze);
#endif
