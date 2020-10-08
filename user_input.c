#include <stdio.h>
#include <stdlib.h>
#include "user_input.h"

int user_input_menu(){
    char user_input[2];
    int user_input_converted =0;
    do{
        fgets(user_input,2,stdin);        
        user_input_converted= atoi(user_input);
        if(user_input_converted <=0 || user_input_converted >=5){
            printf("Veuillez entrer une valeur entière entre 1 et 4 svp\n");
        }
        
    } while(user_input_converted <=0 || user_input_converted >=5);
    return user_input_converted;
}