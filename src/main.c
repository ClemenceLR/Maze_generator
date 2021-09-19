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
#include "display_maze.h"
#include "cell.h"
#include "maze_allocation_func.h"
#include "maze_generation.h"
#include "user_input.h"
#include "files_manager.h"
#include "game_manager.h"

/* Main of the programm : manage the game system
 *
 */
int main(){
	int line;
	int column;
	int input_u;
	int maze_to_free;
	int quit;
	int flag;
	int save;
	int check_system;
	char file_name[128];
	cell** maze;
	line = 0;
	column = 0;
	input_u = 0;
	maze_to_free = 0;
	quit = 0;
	save = 0;
	flag = 0;
	check_system = 0;

	while(1){
		printf("Que souhaitez vous faire ?\n 1) Créer un labyrinthe\n 2) Charger un labyrinthe\n 3) Jouer\n 4) Quitter\n");
		input_u = user_input_menu();
		switch (input_u){
			case 1:
				printf("Vous allez créer votre labyrinthe \n");
				printf("Quel nom voulez vous donner à votre fichier ?\n");
				user_input_string(file_name);
				printf("Combien de lignes souhaitez vous avoir ? \n");
				line = user_input_int();
				printf("Combien de colonnes souhaitez vous avoir ? \n");
				column = user_input_int();
				maze = create_maze_area(maze, column,line, file_name); 
				display_char_maze(maze);
				flag =1;
				maze_to_free = 1;
				break;
			case 2:
				printf("Liste des sauvegardes existantes \n");
				check_system = system("cd save && ls *.cfg | sed -e 's/\.cfg$//'");
				if(check_system == 1){
            		printf("La commande shell s'est mal passée\n");
        		}
				printf("Quel fichier souhaitez vous charger ?\n");
				user_input_string(file_name);
				maze = load_maze(file_name, &flag);
				display_char_maze(maze);
				maze_to_free = 1;
				break;
			case 3:
				if(flag==0){
					printf("Il n'y a pas encore de labyrinthe crée, nous allons en générer un\n");
					printf("Quel nom voulez vous donner à ce labyrinthe ?\n");
					
					user_input_string(file_name);
					maze = create_maze_area(maze,23,9,file_name);
					display_char_maze(maze);
					flag = 1;
					maze_to_free = 1;
				}
				play(maze);
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
