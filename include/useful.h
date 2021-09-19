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

#ifndef USEFUL_H
#define USEFUL_H
#include "cell.h"

/** Generates a random number between 0 and 206
 * The random number is picked based on the time
 * @param max : the maximum number to be picked randomly 
 */
int random_int(int max);

/** Generates a random number between 0 and 206
 * @param max : the maximum number to be picked randomly 
 */
int random_int_not_time_based(int max);


/** Count the size of a table of cells
* @param cell_table
*/
int cell_table_size(cell* cell_table);

/** Count the table size of a table of integers
* @param int_table
*/
int int_table_size(int* int_table);

/** Checks if the id has already been registered in the given list
* @param id_to_check
* @param ids_left
*/
int check_if_already_existing(int id_to_check,int* ids_left);

/** Clear the scanf buffer
*/
void clear_buffer() ;

/** Clear a char table
 * @param buffer : the buffer to clear
 * @param size : the size of the buffer we want to clear
 */
void clear_buffer_table(char *buffer, int size);

#endif
