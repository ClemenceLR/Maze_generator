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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "display_maze.h"
#include "cell.h"
#include "useful.h"
#include "maze_allocation_func.h"
#include "maze_generation.h"
#include "files_manager.h"

#define MAX_NEIGHBOURS 5
int LINE_LENGTH;
int COLUMN_LENGTH;
int NUMBER_ID;

cell** create_maze_area(cell** maze, int line, int column, char* file_name){
	LINE_LENGTH = line;
	COLUMN_LENGTH = column;
	NUMBER_ID = (LINE_LENGTH/2) * (COLUMN_LENGTH/2);
	maze = allocate_space_maze(maze, LINE_LENGTH, COLUMN_LENGTH); 
	fill_maze(maze);
	place_holes(maze);
	create_maze_path(maze);
    init_dimension(line, column);
	place_items(maze);
	save_maze(maze, LINE_LENGTH, COLUMN_LENGTH,file_name);
	return maze;
}


void create_maze_path(cell** maze){
	int id_for_opening;
	int size = 0;
	int ids_left[NUMBER_ID];
	cell cell_picked;
	cell cell_group[NUMBER_ID];
	cell available_for_opening[NUMBER_ID];

	do{	
		list_ids_left(maze,ids_left); 
	    id_for_opening = ids_left[random_int(int_table_size(ids_left))];
		size = int_table_size(ids_left);
		if(id_for_opening == 0){
			id_for_opening =1;
		}
		list_cells_of_a_group(maze,id_for_opening,cell_group); 
		
		list_available_surrounding_cells(maze, cell_group,available_for_opening);
		cell_picked = available_for_opening[random_int(cell_table_size(available_for_opening))];
		break_wall(maze, id_for_opening, cell_picked.id);
				
	}while(size >2);

}



void list_ids_left(cell** maze,int* ids_left){
	int cpt, cpt2,cpt3;
	ids_left[0] = -1;
	cpt3 = 0;
	for(cpt = 1; cpt<COLUMN_LENGTH-1; cpt+=2){
		for(cpt2 =1; cpt2<LINE_LENGTH-1; cpt2+=2){
			if(maze[cpt][cpt2].id !=0 && !check_if_already_existing(maze[cpt][cpt2].id,ids_left)){
				ids_left[cpt3] = maze[cpt][cpt2].id;
				ids_left[cpt3+1] = -1;
				cpt3++;
			}
		}
	}
	
}


void list_cells_of_a_group(cell** maze,int id, cell* cell_group){
	int column;
	int line;
	int index =0;
	cell end_cell = {-1, ' ',0,0};

	for(column=0;column<COLUMN_LENGTH; column++){
		for(line=0;line<LINE_LENGTH; line++){ 
			if(maze[column][line].id == id && maze[column][line].id != 0){ 
				cell_group[index] = maze[column][line];
				index+=1;
			}
		}
	}
	cell_group[index] = end_cell;

}

void list_available_surrounding_cells(cell** maze, cell* cell_group, cell* available_for_opening){
	/* Table with the cell / group cell neighbours */
	cell neighbours[NUMBER_ID];
	/* Create an end cell to close the list */
	cell end_cell ={-1, ' ',0,0};
	/* index used to bowse the list */
	int index;
	int index_afo;
	int cpt;
	/* Size of the table */
	int size;
	int group_id;

 	group_id = cell_group[0].id; 
	cpt =0;
	available_for_opening[cpt] = end_cell;
	size = cell_table_size(cell_group);
	index_afo =0;

	for(index=0; index<size; index++){ 
		find_cell_neighbours(maze,neighbours,cell_group[index]);
		while(neighbours[cpt].id !=-1 && neighbours[cpt].id != group_id){
			available_for_opening[index_afo] = neighbours[cpt];
			index_afo +=1;
			cpt+=1;
		}
		cpt=0;
	}	
	available_for_opening[index_afo] = end_cell;
	

}

void find_cell_neighbours(cell** maze, cell* neighbours,cell cell_concerned){
	int cpt=0;
	cell end_cell = {-1, ' ',0,0};
	cell temp;
	if(cell_concerned.column != 1){
		temp = return_left_cell(maze,cell_concerned);
		if(cell_concerned.id != temp.id){
			neighbours[cpt] = temp;
			cpt+=1;
		}
	}	
	if(cell_concerned.line != 1){
		temp = return_top_cell(maze,cell_concerned);
		if(cell_concerned.id != temp.id){
			neighbours[cpt] = temp;
			cpt+=1;
		}
	}
	if(cell_concerned.column != LINE_LENGTH-2){
		temp = return_right_cell(maze,cell_concerned);
		if(cell_concerned.id != temp.id){
			neighbours[cpt] = temp;
			cpt+=1;
		}
	}
	if(cell_concerned.line != COLUMN_LENGTH-2){
		temp = return_bottom_cell(maze,cell_concerned);
		if(cell_concerned.id != temp.id){
			neighbours[cpt] = temp;
			cpt+=1;
		}
	}

	neighbours[cpt]= end_cell;

}


cell return_left_cell(cell** maze, cell find_left){
	return maze[find_left.line][find_left.column-2];
}

cell return_right_cell(cell** maze, cell find_right){
	return maze[find_right.line][find_right.column+2];

}

cell return_top_cell(cell** maze, cell find_top){
	return maze[find_top.line-2][find_top.column];

}

cell return_bottom_cell(cell** maze, cell find_bottom){
	return maze[find_bottom.line+2][find_bottom.column];
}
void break_wall(cell** maze, int id_origin, int id_target){
	cell origin_group[NUMBER_ID];
	cell target_group[NUMBER_ID];
	cell neighbours_group[NUMBER_ID];
	cell target_neighbours[5];
	cell cleared_target_neighbours[4];
	cell end_cell = {-1,' ',' '};
	cell target;
	cell neighbour;

	int column_wall_to_open;
	int line_wall_to_open;
	int size_of_neighbours;
	int size_of_target_group = 0;
	int cpt;
	int cpt2;
	int index;
	int found =0;
	int neighbour_column;
	int neighbour_line;
	int target_line;
	int target_column;
	int size;
	int neighbours_col_lin[120];
	int target_col_lin[120];
	int rand;
	index =0;
	cpt2 =0;
	list_cells_of_a_group(maze,id_origin, origin_group); //The cells of the original group
	list_available_surrounding_cells(maze, origin_group,neighbours_group); //The neighbours of the group

	size_of_neighbours = cell_table_size(neighbours_group); //We are going to check all the potential neighbours of the group so lets say 3 by cell
	for(cpt =0; cpt<=size_of_neighbours; cpt++){ //In all the neighbours
		//We find and isolates the ones with target id
		if(neighbours_group[cpt].id == id_target){
			target_group[cpt2] = neighbours_group[cpt];
			cpt2 ++;
		}
	}
	target_group[cpt2] = end_cell;
	size_of_target_group = cell_table_size(target_group);
	rand = random_int_not_time_based(size_of_target_group);
	target = target_group[rand];
	find_cell_neighbours(maze, target_neighbours,target);
	size = cell_table_size(target_neighbours);
	cpt2 = 0;
	for(cpt = 0; cpt <size;cpt++){
		if(target_neighbours[cpt].id == id_origin){
			cleared_target_neighbours[cpt2] = target_neighbours[cpt];
			cpt2++;
		}
	}
	cleared_target_neighbours[cpt2] = end_cell;
	size_of_target_group = cell_table_size(cleared_target_neighbours);
	rand = random_int_not_time_based(size_of_target_group);
	neighbour = cleared_target_neighbours[rand];

	column_wall_to_open= (target.column + neighbour.column)/2;
	line_wall_to_open= (target.line + neighbour.line)/2;
	
	list_cells_of_a_group(maze,id_target,target_group);
	maze[line_wall_to_open][column_wall_to_open].content = ' ';
	change_target_id(maze,target_group, id_origin);
}

void change_target_id(cell** maze,cell* target_group,int id_origin){
	int size_of_target_group;
	int cpt;

	size_of_target_group = cell_table_size(target_group);
	for(cpt =0; cpt<size_of_target_group; cpt++){
			maze[target_group[cpt].line][target_group[cpt].column].id = id_origin;
	}

}

void place_items(cell** maze){
	int items_number = (COLUMN_LENGTH+1) /2 ;
	int malus = items_number/2;
	int coef =0;
	if(LINE_LENGTH > COLUMN_LENGTH){ /* Creating a size to stock the available path, as close as possible of the real path number, the coef is calculated on the biggest length (col or line)*/
		coef = LINE_LENGTH *((LINE_LENGTH-1)/2);
	}else{
		coef = COLUMN_LENGTH * ((COLUMN_LENGTH-1)/2);
	}
	cell path_allowed[coef];

	get_path_cells(maze,path_allowed);
	place_bonus_malus(maze, path_allowed,malus, '*');
	get_path_cells(maze,path_allowed);
	place_bonus_malus(maze, path_allowed,malus, '-');
}

void place_bonus_malus(cell** maze, cell* path_allowed,int item_num, char item_char){
	int size;
	int cpt;
	int pick;
	size = cell_table_size(path_allowed);
	for(cpt =0; cpt<item_num+5;cpt++){
		pick = random_int_not_time_based(size);
		maze[path_allowed[pick].column][path_allowed[pick].line].content = item_char;
	}
}

void get_path_cells(cell** maze, cell* path_allowed){
	cell end_cell = {-1, ' ',0,0};
	int line;
	int column;
	int index;
	index=0;

	for(column=0;column<COLUMN_LENGTH-1; column++){
		for(line=0;line<LINE_LENGTH-1; line++){
			if((maze[column][line].content == ' ') && !(column == 1 && line == 0)){
				cell test = {5,' ',column,line};
				path_allowed[index] = test;
				index +=1;
			}
		}
	}
	path_allowed[index] = end_cell;
}