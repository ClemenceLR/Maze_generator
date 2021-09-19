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
#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include "cell.h"

/** Save the content of the maze in a .cfg file
* @param maze : pointer on the maze memory space
* @param line : size of the line
* @param column : size of the column
* @param name : pointer on the name we want to give to the file
*/
void save_maze(cell** maze,int line, int column,char* name);

/** Load the maze from the file given in param
* @param file_name: the name of the file to open
* @param flag : used to know if a maze have been already loaded
*/
cell** load_maze(char* file_name, int* flag);

/** Load the scores register, check if the player has made a recordable score
 * @param p_score : the integer corresponding to the score of the player
*/
int load_score(int p_score);

/** Record the player's score in the score file
 * @param p_score : the player's score
 * @param p_pseudo : the player's pseudo
*/
void save_score(int p_score, char *p_pseudo);

/** Display the content of the score file
 */
void display_scores();

#endif