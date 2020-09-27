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

/* Create the path of the maze with the algorithm given using cell id
 * 
 */
void create_maze_path(cell** maze);

/* Create the maze with the ids of the firsts holes
 * Necessary to initialize the maze
 */
void place_holes(cell** maze);

/* Check if the opening of the wall is possible or if it's not
 */
int is_opening_possible(int opening, int direction);

/* Get all the id left in the maze and place it in a table
 * 
 */
int* list_ids_left(int* ids,int* sum_id);

int* count_ids(cell** maze);
#endif


