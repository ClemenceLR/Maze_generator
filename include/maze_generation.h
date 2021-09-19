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
#ifndef MAZE_GEN
#define MAZE_GEN
#include "cell.h"

/** Initialise the creation of the maze, from the allocation to the creation of the walls
 * @param maze : pointer on the maze memory space
 */
void maze_generator(cell** maze);

/** Creates a table of cells of the size 9 * 23 ans stock it at the adress given
 * @param maze : pointer on the maze memory space
 */
cell** create_maze_area(cell** maze, int line, int column, char* file_name);


/** Create the path of the maze with the algorithm given using cell id
 * @param maze : pointer on the maze memory space
 */
void create_maze_path(cell** maze);

/** Create and return a table of all the ids left in the maze
* @param maze : pointer on the maze memory space
*/
int* count_ids(cell** maze);

/** Get all the id left in the maze and place it in a table
* @param maze : pointer on the maze memory space
* @param ids_left : pointer of the table containing the list of the ids left
 */
void list_ids_left(cell** maze,int* ids_left);

/** Create and return the table of cells that has the same id than the id passed in param 
* @param maze : pointer on the maze memory space
* @param id : id of the cells we look for
* @param group : pointer on a table of cells
*/
void list_cells_of_a_group(cell** maze,int id,cell* group);

/** List all the cells available for connection arround the group
* @param maze : pointer on the maze memory space
* @param group : pointer on a table of cells
* @param available_for_opening : pointer on a table of cells that we will be able to pick
*/
void list_available_surrounding_cells(cell** maze, cell* cell_group, cell* available_for_opening);

/** Find all the neighbour cells for one cell (manage critical cases : borders)
* @param : the id of the cell we look for
* @param neighbours : the list of neighbours of the cells
*/
cell* remove_redundent_cells(int group_id, cell* neighbours);

/** Return the cell at the left of the cell passed in param
*
* @param find_left : the cell we search the left neighbour for
*/
cell return_left_cell(cell** maze, cell find_left);

/** Return the cell at the right of the cell passed in param
* @param maze : pointer on the maze memory space
* @param find_left : the cell we search the right neighbour for
*/
cell return_right_cell(cell** maze, cell find_right);

/** Return the cell at the top of the cell passed in param
* @param maze : pointer on the maze memory space
* @param find_left : the cell we search the top neighbour for
*/
cell return_top_cell(cell** maze, cell find_top);

/** Return the cell at the bottom of the cell passed in param
* @param maze : pointer on the maze memory space
* @param find_left : the cell we search the bottom neighbour for
*/
cell return_bottom_cell(cell** maze, cell find_bottom);

/** Find and save the neighbour cells of the cell passend in params
* @param maze : pointer on the maze memory space
* @param neighbours
* @param cell_concerned
*/
void find_cell_neighbours(cell** maze, cell* neighbours,cell cell_concerned);

/** Pick the wall to break between two groups of cells
* @param maze : pointer on the maze memory space
* @param id_origin 
* @param id_target
*/
void break_wall(cell** maze, int id_origin, int id_target);

/** Change the id of the target group to create a bigger group of origin id
* @param maze : pointer on the maze memory space
* @param id_origin 
* @param id_target
*/
void change_target_id(cell** maze,cell* target_group,int id_origin);

/** Manager to place the bonus / malus items on the maze
* @param maze : pointer on the maze memory space

*/
void place_items(cell** maze);
/** Place the bonus / malus items on the maze
* @param maze : pointer on the maze memory space
* @param path_allowed : table with all the path cells available to put an item in
* @param item_num : number of items to place
* @param item_char : the char of the item to place
*/
void place_bonus_malus(cell** maze, cell* path_allowed,int item, char item_char);

/** Get all the cells available to recieve a bonus / malus
* @param maze : pointer on the maze memory space
* @param path_allowed : table with all the path cells available to put an item in
*/
void get_path_cells(cell** maze, cell* path_allowed);
#endif