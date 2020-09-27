#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "cell.h"
#include "useful.h"

#define LINE_LENGTH 23
#define COLUMN_LENGTH 9

cell** create_maze_area(cell** maze){
	//given an adress build a table of walls
	maze = allocate_space_maze(maze); 
	fill_maze(maze);
	place_holes(maze);
	display_maze(maze);
	create_maze_path(maze);

	
	return maze; //TO CHANGE ?
}

cell** allocate_space_maze(cell** maze){
	int line;
	int column;
	
	maze = (cell **)calloc(COLUMN_LENGTH,sizeof(cell*));
	if(maze == NULL){
		printf("The allocation of the maze whent wrong\n");
		exit(EXIT_FAILURE);
	}else{
		for(column=0; column<COLUMN_LENGTH;column++){
			maze[column]=(cell *)calloc(LINE_LENGTH,sizeof(cell));
				if(maze[column] == NULL){
					printf("The allocation of the maze line whent wrong\n");
				}
			}
		}
	
	return maze;
}

void free_maze(cell** maze){
	int line;
	int column;
	for(column=0; column<COLUMN_LENGTH;column++){	
		cell* currentPtr = maze[column];
		free(currentPtr);
	}
	free(maze);
}

void fill_maze(cell** maze){
	int line;
	int column;
	for(column=0;column<COLUMN_LENGTH; column++){
		for(line=0;line<LINE_LENGTH; line++){
			maze[column][line].content = '#';
			maze[column][line].column = column;
			maze[column][line].line = line;
		}
	}
}

void place_holes(cell** maze){
	int line;
	int column;
	int count =0;

	for(column=1;column<COLUMN_LENGTH; column+=2){
		for(line=1;line<LINE_LENGTH; line+=2){
			maze[column][line].id = count;
			maze[column][line].content = ' ';
			count +=1;
		}
	}
}

void display_maze(cell** maze){
	int line;
	int column;
	
	for(column=0;column<COLUMN_LENGTH; column++){
		for(line=0;line<LINE_LENGTH; line++){
			printf("%c",maze[column][line].content);
		}
		printf("\n");
	}
}

void create_maze_path(cell** maze){
	int flag = 0;
	int direction;
	int id_for_opening;
	int column;
	int line;
	int* ids_left;
	int* ids;
	int sum_id =0;
	int* p_sum_id = &sum_id;
	
	do{
		direction = random_int(4); //0 : top : 1 right : 2 bottom 3 : left
		ids = count_ids(maze);
		ids_left = list_ids_left(ids,p_sum_id); // list of all the ids available
	    id_for_opening = random_int(sum_id);
	    printf("Id for opening %d\n",id_for_opening);
	    //LISTER TOUTES LES CASES DU GROUPE CHOISI
	    //LISTER TOUTES LES CASES CASES AUTOUR DU GROUPE CHOISI
	    //CHOISIR UNE CASE ALEATOIRE DANS LA LISTE DES CASES AUTOUR DU GROUPE
	    //CHANGER LES ID DE LA CASE CHOISIE + LE # + TOUTES LES CASES DU MEME GROUPE QUE LA CASE CHOISIE
		//is_opening_possible(id_opening,direction); //VÉRIFIER SI ON A LE DROIT OU PAS
		flag =1;

		//OUVRIR UN MUR OU RECOMMENCER
		//VERIFIER LES ID DES CASES -> SI TOUTES LE MÊME ID FLAG = 1
		
	}while(flag == 0);
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

int* count_ids(cell** maze){		
	int column;
	int line;
	int cpt;
	int sum_id =0;
	int* ids = (int*)calloc(44,sizeof(int));
	 
	for(column=0;column<COLUMN_LENGTH; column++){
		for(line=0;line<LINE_LENGTH; line++){
			if(maze[column][line].id !=0){
				ids[maze[column][line].id]+=1;
			}
		}
	}
		
	return ids;
	/* Keep for debug
	for(int i=0;i<44;i++){
		printf("%d",ids[i]);
	}
	printf("\n");
	return 1;
	*/
	
}

int is_opening_possible(int opening, int direction){
		
}
