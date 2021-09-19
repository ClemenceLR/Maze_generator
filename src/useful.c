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

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "useful.h"
#include "cell.h"

int random_int(int max){
	/*The random number we are going to generate*/
	int random_number;
	srand(time(NULL));
	random_number = rand()%max;
	return random_number;
}

int random_int_not_time_based(int max){
	int random_number;

	return rand()%max;
}

int cell_table_size(cell* cell_table){
	/* Counter */
	int cpt = 0;
	/* The cell we will use to bowse the list*/
	cell bowse_cells;

	bowse_cells = cell_table[cpt];
	while(bowse_cells.id != -1){
			cpt+=1;
			bowse_cells = cell_table[cpt];
	}

	return cpt;
}

int int_table_size(int* int_table){
	/* Counter */
	int cpt = 0;
	/* The cell we will use to bowse the list*/
	int bowse_cells;

	bowse_cells = int_table[cpt];
	while(bowse_cells != -1){
			cpt+=1;
			bowse_cells = int_table[cpt];
	}
	return cpt;
}

int check_if_already_existing(int id_to_check,int* ids_left){
	/* Index to bowse the list */
	int index;
	/* The size of the list */
	int size = int_table_size(ids_left);

	for(index = 0 ; index< size; index++){
		if(ids_left[index] == id_to_check){
			return 1;
		}
	}

	return 0;


}

void clear_buffer() 
{ 
    int char_to_empty; 
  
    do { 
    	char_to_empty = getchar(); 
    } while (char_to_empty != '\n' && char_to_empty != EOF); 
}

void clear_buffer_table(char *buffer, int size){
	int index;

	for(index=0 ; index <size; index++){
		buffer[index] = ' ';
		if(index == size-1){
			buffer[index] = '\0';
		}
	}

}
