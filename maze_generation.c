#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "cell.h"
#include "useful.h"
#include "maze_allocation_func.h"
#include "maze_generation.h"

#define LINE_LENGTH 23
#define COLUMN_LENGTH 9
#define MAX_NEIGHBOURS 4

cell** create_maze_area(cell** maze){
	//given an adress build a table of walls
	maze = allocate_space_maze(maze); 
	fill_maze(maze);
	place_holes(maze);
	display_maze(maze);
	create_maze_path(maze);

	
	return maze; //TO CHANGE ?
}


void create_maze_path(cell** maze){
	int flag = 0;
	int direction;
	int id_for_opening;
	int cpt;
	int column;
	int line;
	int* ids_left;
	int* ids;
	int sum_id =0;
	int* p_sum_id = &sum_id;
	cell* cell_group;
	cell* neighbour_cells;
	/*Debug var*/
	cell parcourir_cells;

	do{	
		cpt =0;
		direction = random_int(4); //0 : top : 1 right : 2 bottom 3 : left
		ids = count_ids(maze);
		ids_left = list_ids_left(ids,p_sum_id); // list of all the ids available
	    id_for_opening = random_int(sum_id);
	    //printf("Id for opening %d\n",id_for_opening);
		cell_group = list_cells_of_a_group(maze,id_for_opening); //List all the cells of the chosen group	
	
		/*CELL_GROUP EST DEFINI ICI*/
		// Debug cells group
		//int length = cell_table_size(cell_group);
		//printf("Size of table %d ", length);
		
		neighbour_cells = list_available_surrounding_cells(maze, cell_group);
		// Debug cells group
		//int length = cell_table_size(neighbour_cells);
		//printf("Size of table %d \n", length);
		printf("Over\n");
	    //LISTER TOUTES LES CASES CASES AUTOUR DU GROUPE CHOISI
	    //CHOISIR UNE CASE ALEATOIRE DANS LA LISTE DES CASES AUTOUR DU GROUPE
	    //CHANGER LES ID DE LA CASE CHOISIE + LE # + TOUTES LES CASES DU MEME GROUPE QUE LA CASE CHOISIE
		//is_opening_possible(id_opening,direction); //VÉRIFIER SI ON A LE DROIT OU PAS
		flag =1;

		//OUVRIR UN MUR OU RECOMMENCER
		//VERIFIER LES ID DES CASES -> SI TOUTES LE MÊME ID FLAG = 1
		
	}while(flag == 0);
}


//---------------------------------------------------------A refaire
int* count_ids(cell** maze){		
	int column;
	int line;
	int cpt;
	int sum_id =0;
	int* ids = (int*)calloc(44,sizeof(int)); //TODO remplacer par 1 
	 
	for(column=0;column<COLUMN_LENGTH; column++){
		for(line=0;line<LINE_LENGTH; line++){ // Realloc +1
			if(maze[column][line].id !=0){
				ids[maze[column][line].id]+=1; 
			}
		}
	}
	//TODO structure int taille_tab; int tab[taille_tab]	
	return ids;
	/* Keep for debug
	for(int i=0;i<44;i++){
		printf("%d",ids[i]);
	}
	printf("\n");
	return 1;
	*/	
	
}

int* list_ids_left(int* ids,int* p_sum_id){
	*p_sum_id =0;
	int cpt;
	int cpt2 =0;
	
	for(cpt = 0; cpt<44; cpt++){
		if(ids[cpt]!=0){
			*p_sum_id +=1;
		}
	}
	
	int* ids_left = (int*)calloc(*p_sum_id,sizeof(int));

	for(cpt = 0; cpt<44; cpt++){
		if(ids[cpt]!=0){
			ids_left[cpt2] = cpt;
			cpt2++;
		}
	}
	
	free(ids);
	/* Keep for debug
	for(int i=0;i<sum_id;i++){
		printf("%d",ids_left[i]);
	}
	printf("\n");
	*/
	return ids_left;

}

//------------------------------------------------------------------------------------TODO A refaire

//LISTER TOUTES LES CASES DU GROUPE CHOISI
cell* list_cells_of_a_group(cell** maze,int id){
	int column;
	int line;
	int index =0;
	cell end_cell = {-1};

	cell* cell_group = (cell*)calloc(44,sizeof(cell)); //TODO remplacer par 1 

	//todo allouer de l'espace pour une cellule
	for(column=0;column<COLUMN_LENGTH; column++){
		for(line=0;line<LINE_LENGTH; line++){ 
			if(maze[column][line].id == id){ 
				if(index !=0){//realloc

				}
				cell_group[index] = maze[column][line];
				index+=1;
			}
		}
	}
	cell_group[index] = end_cell;

	return cell_group;
}

cell* list_available_surrounding_cells(cell** maze, cell* cell_group){
	cell available_for_opening[44];
	cell* cleaned_list;
	cell neighbours[MAX_NEIGHBOURS];
	int index;
	int size;
	//USED FOR DEBUG
	//display_maze(maze);
	display_cell_table(cell_group);
	int group_id = cell_group[0].id; 
	printf("Group id : %d\n", group_id);
	int cpt =0;
	cell to_check;
	cell end_cell ={-1};
	int check =0;
	available_for_opening[cpt] = end_cell;
	printf("AFO %d\n",available_for_opening[cpt].id);
	size = cell_table_size(cell_group);
	printf("Size : %d\n",size);

	//-------------------------------------------------------------------------------------------------------------------------------------------------OK UNTIL HERE
	for(index=0; index<size; index++){ // All the cases except problematic cases
//			if(cell_group[index].column >1 && cell_group[index].line >1 && cell_group[index].column < COLUMN_LENGTH-2 && cell_group[index].column < LINE_LENGTH-2 ){
				//We put all the possiblity 
				//Top
				to_check = maze[cell_group[index].column][cell_group[index].line-2];
						check = check_if_already_registered(to_check, available_for_opening);
						if(check == 1){
							printf("Hy\n");
							available_for_opening[cpt] = to_check;
							cpt+=1;
							available_for_opening[cpt] = end_cell;
						}
						available_for_opening[cpt] = to_check;
						cpt +=1;
						available_for_opening[cpt] = end_cell;

				//Left
				to_check = maze[cell_group[index].column+2][cell_group[index].line];
						check = check_if_already_registered(to_check, available_for_opening);
						if(check == 1){
							available_for_opening[cpt] = to_check;
							cpt+=1;
							available_for_opening[cpt] = end_cell;
						}
				available_for_opening[cpt] = to_check;
				cpt +=1;
				available_for_opening[cpt] = end_cell;

				//Bottom
				to_check = maze[cell_group[index].column][cell_group[index].line+2];
						check = check_if_already_registered(to_check, available_for_opening);
						if(check == 1){
							available_for_opening[cpt] = to_check;
							cpt+=1;
							available_for_opening[cpt] = end_cell;
						}
				available_for_opening[cpt] = to_check;
				cpt +=1;
				available_for_opening[cpt] = end_cell;

				//Right
				to_check =maze[cell_group[index].column-2][cell_group[index].line];
						check = check_if_already_registered(to_check, available_for_opening);
						if(check == 1){
							available_for_opening[cpt] = to_check;
							cpt+=1;
							available_for_opening[cpt] = end_cell;
						}
				available_for_opening[cpt] = to_check;
				cpt +=1;
				available_for_opening[cpt] = end_cell;
				
		//	}
	}	


	available_for_opening[cpt] = end_cell;
	cleaned_list  =  remove_forbidden_cells(&available_for_opening[0], group_id);

	return &cleaned_list[0]; 

}


cell* remove_forbidden_cells(cell* available_for_opening, int group_id){ 
	cell cleaned_list[44];
	cell end_cell = {-1};
	int cpt =0;
	int index;
	int size = cell_table_size(available_for_opening);
	for(index = 0; index < size; index++){
		if(available_for_opening[index].id != group_id){
			if((available_for_opening[index].column !=0) && 
			(available_for_opening[index].column !=COLUMN_LENGTH-1) && 
			(available_for_opening[index].line !=0) && 
			(available_for_opening[index].line !=LINE_LENGTH-1)){
				cleaned_list[cpt] = available_for_opening[index];
				printf("Cleaned : %d\n" ,cleaned_list[cpt].id);
				cpt+=1;
			}
		}

	}

	cleaned_list[cpt] = end_cell;
	return cleaned_list;
}

//TODO FIND NEIGHBOURS
void find_cell_neighbours(cell** maze, cell* neighbours,cell cell_concerned){
	int cpt=0;
	if(cell_concerned.column == 1 || cell_concerned.column == COLUMN_LENGTH-2 || cell_concerned.line == 1 || cell_concerned.line == LINE_LENGTH-2){ //We isulate the specific sides : first line, first column, last line, last column
		if(cell_concerned.column == 1 && cell_concerned.line == 1){ 
			neighbours[cpt] = return_right_cell(maze, cell_concerned);
			cpt+=1;
			neighbours[cpt] = return_bottom_cell(maze, cell_concerned);

		}else if(cell_concerned.column == 1 && cell_concerned.line == LINE_LENGTH-2){
			neighbours[cpt] = return_top_cell(maze, cell_concerned);
			cpt+=1;
			neighbours[cpt] = return_right_cell(maze, cell_concerned);

		}else if(cell_concerned.column == COLUMN_LENGTH-2 && cell_concerned.line == 1){
			neighbours[cpt] = return_left_cell(maze, cell_concerned);
			cpt+=1;
			neighbours[cpt] = return_bottom_cell(maze, cell_concerned);

		}else if(cell_concerned.column == COLUMN_LENGTH-2 && cell_concerned.line == LINE_LENGTH-2){
			neighbours[cpt] = return_left_cell(maze, cell_concerned);
			cpt+=1;
			neighbours[cpt] = return_top_cell(maze, cell_concerned);

		}else if(cell_concerned.column == 1){
			neighbours[cpt] = return_top_cell(maze,cell_concerned);
			cpt+=1;
			neighbours[cpt] = return_right_cell(maze,cell_concerned);
			cpt+=1;
			neighbours[cpt] = return_bottom_cell(maze, cell_concerned);
			cpt+=1;

		}else if(cell_concerned.column == COLUMN_LENGTH-2){
			neighbours[cpt] = return_top_cell(maze,cell_concerned);
			cpt+=1;
			neighbours[cpt] = return_left_cell(maze,cell_concerned);
			cpt+=1;
			neighbours[cpt] = return_bottom_cell(maze, cell_concerned);
			cpt+=1;
		}else if(cell_concerned.line == 1){
			neighbours[cpt] = return_left_cell(maze,cell_concerned);
			cpt+=1;
			neighbours[cpt] = return_right_cell(maze,cell_concerned);
			cpt+=1;
			neighbours[cpt] = return_bottom_cell(maze, cell_concerned);
			cpt+=1;
		}else {
			neighbours[cpt] = return_left_cell(maze,cell_concerned);
			cpt+=1;
			neighbours[cpt] = return_right_cell(maze,cell_concerned);
			cpt+=1;
			neighbours[cpt] = return_top_cell(maze, cell_concerned);
			cpt+=1;
		}

	}else{
		neighbours[cpt] = return_top_cell(maze,cell_concerned);
		cpt+=1;
		neighbours[cpt] = return_right_cell(maze,cell_concerned);
		cpt+=1;
		neighbours[cpt] = return_bottom_cell(maze, cell_concerned);
		cpt+=1;
		neighbours[cpt] = return_left_cell(maze,cell_concerned);
	}

}


cell return_left_cell(cell** maze, cell find_left){
	return maze[find_left.column-2][find_left.line];
}

cell return_right_cell(cell** maze, cell find_right){
	return maze[find_right.column+2][find_right.line];

}

cell return_top_cell(cell** maze, cell find_top){
	return maze[find_top.column][find_top.line+2];

}

cell return_bottom_cell(cell** maze, cell find_bottom){
	return maze[find_bottom.column][find_bottom.line-2];
}
//FIND WALL (double parcours en fonction de l'id)
