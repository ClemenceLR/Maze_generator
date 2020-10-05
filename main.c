#include <stdio.h>
#include <stdlib.h>
#include "display_maze.h"
#include "cell.h"
#include "maze_allocation_func.h"
#include "maze_generation.h"

/* Main of the programm : manage the game system
 * */
int main(int argc, char* argv[]){
	int verif_ligne =0;
	int verif_colonne =0;
	if(argc <2){
		printf("Veuillez entrer deux arguments colonnes et ligne svp\n");
		return 1;
	}

	printf("Que souhaitez vous faire ?\n ");


	verif_ligne = atoi(argv[1]);
	verif_colonne = atoi(argv[2]);
	if(verif_colonne && verif_ligne){
		cell** maze;
		maze = create_maze_area(maze, verif_ligne, verif_colonne);
		display_char_maze(maze, verif_ligne, verif_colonne);
		free_maze(maze);
		return 0;
	}else{
		printf("Veuillez entrer des valeurs numériques valables svp\n");
		return 1;
	}
}
//Rendre le programme dynmique.
//Todo trouver formule math pour calculer le nb d'id
