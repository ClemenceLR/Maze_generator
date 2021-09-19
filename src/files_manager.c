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
#include <string.h>
#include "files_manager.h"
#include "cell.h"
#include "useful.h"
#include "maze_allocation_func.h"
#include "display_maze.h"
#include "player.h"

void save_maze(cell** maze, int line_m, int column_m,char* file_name){
    int column; 
    int line;
    char to_add;
    FILE* file_address;
    char* extension;

    column = 0;
    line = 0;
    to_add = ' ';
    file_address = NULL;
    extension = ".cfg";

    strcat(file_name,extension);
    char file_path[400] = "./save/";
    strcat(file_path,file_name);
    file_address = fopen(file_path, "w");
    if(file_address == NULL){
        printf("L'ouverture du fichier pour la sauvegarde a échoué\n");
    }
    /*Add the line and the column on the first line of the file*/
    fprintf(file_address,"%d",line_m);
    fputc('\n', file_address);
    fprintf(file_address,"%d",column_m);
    fputc('\n', file_address);

    for (column =0; column<column_m;column++){
        for(line=0; line<line_m;line++){
            to_add = maze[column][line].content;
            fputc(to_add,file_address);
        }
        fputc('\n',file_address);
    }

    fclose(file_address);
}


cell** load_maze(char* file_name,int* flag){
    FILE* file_address;
    cell** maze;
    int index;
    int line_m;
    int column_m;
    int column;
    int check_scanf;
    char* extension;

    file_address = NULL;
    line_m = 0;
    column_m = 0;
    column = -1;
    maze = NULL;
    extension = ".cfg";
    check_scanf = 0;

    strcat(file_name,extension);
    char file_path[400] = "./save/";
    strcat(file_path,file_name);

    file_address = fopen(file_path,"r");
    if(file_address == NULL){
        printf("L'ouverture du fichier pour le chargement a échoué\n");
        *flag = 0;
        return maze;
    }

    check_scanf = fscanf(file_address,"%d %d", &line_m,&column_m);
    if(check_scanf == 0){
        printf("La lecture du score s'est mal passée\n");
    }
    char buffer[line_m+2];
    maze = allocate_space_maze(maze, line_m,column_m);
	init_dimension(line_m,column_m);

    while(fgets(buffer,line_m+2, file_address)!=NULL && column<column_m){
        if(column != -1){
            for (index=0; index<line_m+2; index++){
                maze[column][index].content = buffer[index];    
            }
        }

        column++;
    }

    *flag =1;
    fclose(file_address);
    return maze;
}

int load_score(int player_score){
    FILE* file_address = NULL;
    char file_path[400] = "./save/scores_table.score";
    char buffer[100];
    int index;
    int score;
    int check_scanf;

    check_scanf =0;
    score =0;
    file_address = NULL;

    file_address = fopen(file_path,"r");
    if(file_address == NULL){
        printf("L'ouverture du fichier pour le chargement des scores a échoué\n");
    }

    for(index = 0; index<10; index++){
        check_scanf = fscanf(file_address,"%d %s", &score,buffer);
        if(check_scanf == 0){
            printf("Le chargement du score s'est mal passée\n");
        }
        if(score < player_score){
            return 1;
        }
    } 

    return 0;
}

void save_score(int p_score, char *p_pseudo){
    FILE* file_address;
    player_score scores_table[10];
    char file_path[400] = "./save/scores_table.score";
    char buffer[100];
    int index;
    int score;
    int recordable;
    int flag;
    int check_scanf;

    score = 0;
    recordable = 0;
    flag = 0;
    check_scanf = 0;

    file_address = fopen(file_path,"r");
    if(file_address == NULL){
        printf("L'ouverture du fichier pour la sauvegarde du score a échoué\n");
    }
    for(index = 0; index<10; index++){
        check_scanf = fscanf(file_address,"%d %s", &score,buffer);
        if(check_scanf == 0){
            printf("La lecture du score s'est mal passée\n");
        }
        scores_table[index].pseudo[0] = '\0'; /* It is mandatory to initialize each player pseudo with /0 to avoid file corruption */
        strcat(scores_table[index].pseudo,buffer);
        scores_table[index].score = score;
        if(score < p_score){
            recordable = 1;
        }
    } 
    fclose(file_address);

    file_address = fopen(file_path,"w+");
    if(file_address == NULL){
        printf("L'ouverture en écriture du fichier a échoué\n");
    }
    for(index =0; index<10; index++){
        if(flag == 0 && scores_table[index].score < p_score){
            fprintf(file_address,"%d %s",p_score, p_pseudo);
            fputc('\n', file_address);
            flag = 1;  
        }
        fprintf(file_address,"%d %s",scores_table[index].score, scores_table[index].pseudo);
        fputc('\n', file_address);
    }   
    fclose(file_address);
}


void display_scores(){
    FILE* file_address;
    char file_path[400] = "./save/scores_table.score";
    char buffer[100];
    int score;
    int index;
    int check_scanf;

    file_address = NULL;
    score =0;
    check_scanf =0;

    printf("----------SCORES-----------\n");
    file_address = fopen(file_path,"r");
    if(file_address == NULL){
        printf("L'ouverture du fichier pour l'affichage des scores a échoué\n");
    }

    for(index = 0; index<10; index++){
        check_scanf = fscanf(file_address,"%d %s", &score,buffer);
        if(check_scanf == 0){
            printf("L'affichage du score s'est mal passé\n");
        }
        printf("Score : %d Player : %s\n", score,buffer);
    } 
    printf("---------------------------\n");

    fclose(file_address);
}
