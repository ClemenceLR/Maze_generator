#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "cell.h"
#include "useful.h"
#include "maze_allocation_func.h"
#include "maze_generation.h"

#define LINE_LENGTH 23
#define COLUMN_LENGTH 9
#define MAX_NEIGHBOURS 5

cell** create_maze_area(cell** maze){
	//given an adress build a table of walls
	maze = allocate_space_maze(maze); 
	fill_maze(maze);
	place_holes(maze);
	create_maze_path(maze);
	display_char_maze(maze);
	//TODO ADD ENTRY - OUT
	
	return maze; //TO CHANGE ?
}


void create_maze_path(cell** maze){
	int flag = 0;
	int id_for_opening;
	int cpt;
	int column;
	int line;
	int size = 0;
	int ids_left[44];
	cell cell_picked;
	cell cell_group[44];
	cell* cleaned_neighbours;
	cell available_for_opening[44];
	/*Debug var*/
	cell parcourir_cells;

	do{	
		cpt =0;
		list_ids_left(maze,ids_left); // list of all the ids available
		//printf("Table size of ids left %d\n" , int_table_size(ids_left));
	    id_for_opening = ids_left[random_int(int_table_size(ids_left))];
		size = int_table_size(ids_left);
		//printf("ID FOR OP %d", id_for_opening);
		if(id_for_opening == 0){
			id_for_opening =1;
		}
		//id_for_opening = 44;
	    //printf("Id for opening %d\n",id_for_opening);
		list_cells_of_a_group(maze,id_for_opening,cell_group); //List all the cells of the chosen group	
	
		/*CELL_GROUP EST DEFINI ICI*/
		// Debug cells group
		//int length = cell_table_size(cell_group);
		//printf("Size of table %d ", length);
		
		list_available_surrounding_cells(maze, cell_group,available_for_opening);
		cell_picked = available_for_opening[random_int(cell_table_size(available_for_opening))];
		//printf("Cell picked %d\n",cell_picked.id);
		break_wall(maze, id_for_opening, cell_picked.id);
		// Debug cells group
		//int length = cell_table_size(neighbour_cells);
		//printf("Size of table %d \n", length);
		//printf("Over\n");
		
	}while(size >2);
}


//---------------------------------------------------------A refaire

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

//------------------------------------------------------------------------------------TODO A refaire

//LISTER TOUTES LES CASES DU GROUPE CHOISI
void list_cells_of_a_group(cell** maze,int id, cell* cell_group){
	int column;
	int line;
	int index =0;
	cell end_cell = {-1};

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
	cell neighbours[44];
	cell end_cell ={-1};

	int index;
	int index_afo;
	int reset;
	int size;
	//USED FOR DEBUG
	//display_maze(maze);
	//display_cell_table(cell_group);
	int group_id = cell_group[0].id; 
	//printf("Group id : %d\n", group_id);
	int cpt =0;
	int check =0;
	available_for_opening[cpt] = end_cell;
	//printf("AFO %d\n",available_for_opening[cpt].id);
	size = cell_table_size(cell_group);
	//printf("Size : %d\n",size);
	index_afo =0;

	for(index=0; index<size; index++){ 
		find_cell_neighbours(maze,neighbours,cell_group[index]);
		while(neighbours[cpt].id !=-1 && neighbours[cpt].id != group_id){
			//printf("Neighbour found for %d is %d\n",cell_group[index].id,neighbours[cpt].id);
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
	cell end_cell = {-1};
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
//FIND WALL (double parcours en fonction de l'id)
void break_wall(cell** maze, int id_origin, int id_target){
	cell origin_group[44];
	cell target_group[44];
	cell neighbours[44];
	int column_wall_to_open;
	int line_wall_to_open;
	int size_of_neighbours;
	int size_of_target_group = 0;
	int cpt;
	int cpt2;
	int found =0;
	int neighbour_column = 0;
	int neighbour_line = 0;
	int target_line = 0;
	int target_column = 0;

	//parcourir toutes les cellules du groupe d'origine
	list_cells_of_a_group(maze,id_origin, origin_group);
	list_cells_of_a_group(maze,id_target, target_group);
	//printf("Mur entre %d et %d\n", id_origin, id_target);
	size_of_target_group = cell_table_size(target_group);
	//printf("SIZE TARGET GROUP: %d\n", size_of_target_group);
	
	
	for(cpt =0; cpt<=size_of_target_group; cpt++){
		find_cell_neighbours(maze, neighbours,target_group[cpt]);
		//printf("Start loop \n");
		size_of_neighbours = cell_table_size(neighbours);
		//printf("Size of neigh : %d \n", size_of_neighbours);
		for(cpt2=0;cpt2<size_of_neighbours;cpt2++){
			//printf("ID OF NEIG %d\n", neighbours[cpt2].id);
			if(neighbours[cpt2].id == id_origin){
				found = 1;
				neighbour_column = neighbours[cpt2].column;
				neighbour_line = neighbours[cpt2].line;
				target_column = target_group[cpt].column;
				target_line = target_group[cpt].line;
				break;
			}
		}
		if(found ==1){
			break;
		}
	}
	//printf("target line %d target col %d\n", target_line, target_column);
	//printf("neighbour line %d neighb line %d\n", neighbour_column,neighbour_line);

	column_wall_to_open= (target_group[cpt].column + neighbours[cpt2].column)/2;
	//printf("Wall to open coll %d\n", column_wall_to_open);
	line_wall_to_open= (target_group[cpt].line + neighbours[cpt2].line)/2;
	//printf("Wall to open line %d\n", line_wall_to_open);

	maze[line_wall_to_open][column_wall_to_open].content = ' ';
	//maze[line_wall_to_open][column_wall_to_open].id = id_origin;
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
