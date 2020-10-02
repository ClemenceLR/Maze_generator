#ifndef USEFUL_H
#define USEFUL_H
#include "cell.h"

/* Generates a random number between 0 and 206
 * 
 */
int random_int(int max);
int cell_table_size(cell* cell_table);
int int_table_size(int* int_table);
int check_if_already_registered(cell to_check, cell* group_saved);

#endif
