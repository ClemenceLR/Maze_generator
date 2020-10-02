
#include "cell.h"

/* Initialise the creation of the maze, from the allocation to the creation of the walls
 * @param maze : pointer on the maze memory space
 */
void maze_generator(cell** maze);

/* Creates a table of cells of the size 9 * 23 ans stock it at the adress given
 * @param maze : pointer on the maze memory space
 */
cell** create_maze_area(cell** maze);


/* Create the path of the maze with the algorithm given using cell id
 * @param maze : pointer on the maze memory space
 */
void create_maze_path(cell** maze);

/*Create and return a table of all the ids left in the maze
* @param maze : pointer on the maze memory space
*/
int* count_ids(cell** maze);

/* Get all the id left in the maze and place it in a table
 * 
 */
int* list_ids_left(int* ids,int* sum_id);

/* Create and return the table of cells that has the same id than the id passed in param 
*
*/
cell* list_cells_of_a_group(cell** maze,int id);

/* List all the cells available for connection arround the group
*
*/
cell* list_available_surrounding_cells(cell** maze, cell* cell_group);

/* Return the group of neighbour cells of the chosen group if there are no neighbor will return a table of one empty cell
*
*/
cell* remove_forbidden_cells(cell* available_for_opening, int group_id);

/* Find all the neighbour cells for one cell (manage critical cases : borders)
*
*/
void find_cell_neighbours(cell** maze, cell* neighbours,cell cell_concerned);

/* Return the cell at the left of the cell passed in param
*/
cell return_left_cell(cell** maze, cell find_left);

/* Return the cell at the right of the cell passed in param
*/
cell return_right_cell(cell** maze, cell find_right);

/* Return the cell at the top of the cell passed in param
*/
cell return_top_cell(cell** maze, cell find_top);

/* Return the cell at the bottom of the cell passed in param
*/
cell return_bottom_cell(cell** maze, cell find_bottom);