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
#include "game_manager.h"
#include "cell.h"
#include "player.h"
#include "display_maze.h"
#include "user_input.h"
#include "files_manager.h"

int LINE_LENGTH ;
int COLUMN_LENGTH;

void play(cell** maze){
    int flag;
    int win;
    int cpt;
    int check_system;
    int register_score;
    char pseudo[200];
    cell next_cell;
    int move_ok;

    LINE_LENGTH = get_maze_line();
    COLUMN_LENGTH = get_maze_column();
    flag = 0;
    win = 0;
    move_ok = 0;
    player p = {1,0,0};
    maze[p.column][p.line].content = 'o';
    check_system = 0;

    check_system = system("clear");
    if(check_system == 1){
      printf("Le clear n'a pas pu être effectué\n");  
    }
    printf("Bienvenue dans le module de jeu\nDéplacez vous avec les touches zqsd (a pour quitter) du clavier pour sortir du labyrinthe.\n");

    while( win ==0){
        display_char_maze(maze);
        printf("SCORE : %d\n", p.score);
        while(move_ok ==0){
            printf("A vous de jouer : \n");
            move_ok = user_input_char();
        }
        check_system = system("clear");
        if(check_system == 1){
            printf("Le clear n'a pas pu être effectué\n");  
        }
      
        if(move_ok == 5){
            maze[p.column][p.line].content = ' ';
            break;
        }
        check_user_move(maze,&p,move_ok);
        win = is_win(p.column,p.line);
        p.score +=1;
        move_ok = 0;
    }

    if(win == 1) {
        printf("Félicitations vous avez gagné\n");
        printf("Votre score final est de : %d \n",p.score);
        register_score = load_score(p.score);
        if(register_score == 1 ){
            printf("Vous avez un des 10 premiers scores, nous allons l'enregistrer ! \nIndiquez nous votre pseudo svp\n");
            user_input_string(pseudo);
            save_score(p.score,pseudo);

        }
        display_scores();
        maze[p.column][p.line].content = ' ';
    }


}

int is_win(int line, int column){
    if (line == (COLUMN_LENGTH-2) && column == (LINE_LENGTH-1)){
        return 1;
    }
    return 0; 

}

void check_user_move(cell **maze,player* p, int move){
    switch(move){
            case 1:
                if(maze[p->column-1][p->line].content == 'X'){
                    printf("Déplacement haut impossible \n");
                }else{   
                    update_score(p,maze[p->column-1][p->line]);
                    maze[p->column-1][p->line].content = 'o';
                    maze[p->column][p->line].content = ' ';
                    p->column = p->column-1;
                }
                break;

            case 2:
                if( maze[p->column][p->line-1].content == 'X'){
                    printf("Déplacement gauche impossible \n");
                }else{
                    update_score(p,maze[p->column][p->line-1]);
                    maze[p->column][p->line-1].content = 'o';
                    maze[p->column][p->line].content = ' ';
                    p->line = p->line-1;
                }
                break;
            case 3:
                if(maze[p->column+1][p->line].content == 'X'){
                    printf("Déplacement bas impossible \n");
                }else{
                    update_score(p, maze[p->column+1][p->line]);
                    maze[p->column+1][p->line].content = 'o';
                    maze[p->column][p->line].content = ' ';
                    p->column = p->column+1;
                }
                break;
            case 4:
                if(maze[p->column][p->line+1].content == 'X'){
                    printf("Déplacement droite impossible \n");
                }else{
                    update_score(p, maze[p->column][p->line+1]);
                    maze[p->column][p->line+1].content = 'o';
                    maze[p->column][p->line].content = ' ';
                    p->line = p->line+1;
                }
                break;
        }
}

void update_score(player* p, cell to_check){
    if(to_check.content == '*'){
        p->score += 20;
    }else if(to_check.content == '-'){
        p->score -=10;
    }
}


