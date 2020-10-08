#include <stdio.h>
#include <stdlib.h>
#include "display_maze.h"
#include "cell.h"
#include "maze_allocation_func.h"
#include "maze_generation.h"
#include "user_input.h"

/* Main of the programm : manage the game system
 *
 */
int main(int argc, char* argv[]){
	int verif_ligne =0;
	int verif_colonne =0;
	int input_u =0;
	int maze_to_free =0;
	int quit =1;
	cell** maze;


	while(1){
		printf("Que souhaitez vous faire ?\n 1) Créer un labyrinthe\n 2) Charger un labyrinthe\n 3) Jouer\n 4) Quitter\n");
		input_u = user_input_menu();
		printf("Input u %d", input_u);
		switch (input_u){
			case 1:
				verif_colonne = 29;
				verif_ligne = 9;
				if(verif_colonne && verif_ligne){
					maze = create_maze_area(maze, verif_ligne, verif_colonne);
					display_char_maze(maze, verif_ligne, verif_colonne);
					//CREATE
					//SAVE
					//CHARGE 
					//MENU AGAIN
					maze_to_free = 1;
				}
				break;
			case 2:
				printf("WIP chargement du labyrinthe\n");
				//maze_to_free = 1;
				break;
			case 3:
				printf("WIP Play module\n");
				break;
			case 4:
				quit = 1;
				break;
			default :
				break;
		}
		if(quit == 1){
			printf("Vous allez quitter le programme\n");
			break;
		}
	}

	if(maze_to_free == 1){
			free_maze(maze);
		}
	return 0;
}
//Rendre le programme dynmique.
//Todo trouver formule math pour calculer le nb d'id
