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
}

int check_if_already_registered(cell to_check, cell* group_saved){
	int index;
	int size = cell_table_size(group_saved);
	cell current_cell;
	printf("I'm in the check size : %d\n",size);
	for(index = 0 ; index< size; index++){
		current_cell = group_saved[index];
		if(current_cell.column == to_check.column && current_cell.line == to_check.line){
			return 0;
		}
	}

	return 1;


}