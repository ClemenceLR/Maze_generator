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
#include "user_input.h"
#include "useful.h"

int user_input_menu(){
    int user_input =0;
    int user_input_clear = 0;
    do{ 
        user_input_clear = scanf("%d",&user_input);
        clear_buffer();

        if(user_input_clear !=1 ||(user_input <=0 || user_input >=5)){
            printf("Veuillez entrer une valeur entière entre 1 et 4 svp\n");
        }
    } while(user_input <=0 || user_input >=5);
    return user_input;
}

int user_input_int(){
 int user_input =0;
    int user_input_clear = 0;
    do{ 
        user_input_clear = scanf("%d",&user_input);
        clear_buffer();

        if(user_input_clear !=1){
            printf("Veillez entrer une valeur entière svp\n");
        }
        else if(user_input %2 ==0){
            printf("Veuillez entrer une valeur impaire svp\n");
        }else if(user_input <=3) {
            printf("Veuillez entrer une valeur supérieure à 3 svp\n");
        }
    } while((user_input_clear !=1) ||(user_input <=3)||(user_input %2 ==0));
    return user_input;
}

void user_input_string(char file_name[128]){
    int user_input_clear = 0;
    int user_input_legit = 0;
    do{ 
        user_input_clear = scanf("%s",file_name);
        clear_buffer();
        if (user_input_clear == 1){
            user_input_legit = check_points(file_name);
        }
        if(user_input_clear !=1 || user_input_legit !=1){
            printf("Veuillez entrer un nom de fichier valide svp (pas de points, slashs ) \n");
        }
    } while(user_input_clear !=1 || user_input_legit !=1);
}

int check_points(char * file_name){
    int size;
    int index;

    size = strlen(file_name);
    for(index =0; index<size; index++){
        if(file_name[index] == '.' || file_name[index] == '/'){
            
            return -1;
        }
    }

    return 1;
}

int user_input_char(){
    char user_move;
    int user_input_clear;
    int user_input_legit;

    user_move =0;
    user_input_clear =0;
    user_input_legit =0;

    do{ 
        user_input_clear = scanf("%c",&user_move);
        clear_buffer();
        if (user_input_clear == 1){
            user_input_legit = check_move(user_move);
        }
        if(user_input_clear !=1 || user_input_legit !=1){
            printf("Veuillez entrer un charactère valide svp (zqsd)\n");
        }else{
            switch (user_move){
                case 'z':
                    return 1;
                    break;
                case 'q':
                    return 2;
                    break;
                case 's':
                    return 3;
                    break;
                case 'd':
                    return 4;
                    break;
                case 'a':
                    return 5;
                    break;
            }
        }
    } while(user_input_clear !=1 || user_input_legit !=1);

    return 0;
}

int check_move(char move){
    if(move != 'z' && move != 'q' && move !='s' && move != 'd' && move != 'a'){
        return 0;
    }

    return 1;
}
