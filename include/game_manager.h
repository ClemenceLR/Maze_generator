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
#ifndef GAME_H
#define GAME_H
#include "cell.h"
#include "player.h"

/** Manage a game of maze
 * @param maze : pointer on the maze memory space
 * @param save : the name 
*/
void play(cell** maze);

/** Check if the player is on the exit of the maze
* @param line : player line coordonate
* @param column : player column coordonate
*/
int is_win(int line, int column);

/** Check if the player is allowed to do his move
* @param maze : pointer on the maze memory space
* @param player : player structure
* @param move : wanted move
*/
void check_user_move(cell **maze,player* p, int move);

/** Update the score of the player
* @param player : player structure
* @param to_check : the cell from whom we want to check the content
*/
void update_score(player* p, cell to_check);

#endif