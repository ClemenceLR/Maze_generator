#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "useful.h"
#include "cell.h"

int random_int(int max){
	srand(time(NULL));
	int random_number = rand()%max;
	return random_number;
}

int cell_table_size(cell* cell_table){
	int cpt = 0;
	cell parcourir_cells = cell_table[cpt];
	while(parcourir_cells.id != -1){
			cpt+=1;
			parcourir_cells = cell_table[cpt];
	}

	return cpt;
}

int int_table_size(int* int_table){
	int cpt = 0;
	int parcourir_cells = int_table[cpt];
	while(parcourir_cells != -1){
			cpt+=1;
			parcourir_cells = int_table[cpt];
	}
	return cpt;
}

int check_if_already_existing(int id_to_check,int* ids_left){
	int index;
	int size = int_table_size(ids_left);
	//printf("Size table id : %d\n", size);
	int current_cell;

	for(index = 0 ; index< size; index++){
		if(ids_left[index] == id_to_check){
			return 1;
		}
	}

	return 0;


}