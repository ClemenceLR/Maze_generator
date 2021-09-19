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
#ifndef PLAYER_H
#define PLAYER_H
#include "player.h"

/** Structure of a player 
 * @param column : position of the player
 * @param line : the position of the player
 * @param score : store the score of the player
 * */
typedef struct{
	int column;
	int line;
	int score;
} player;

/** Structure of a player score : 
 * @param pseudo
 * @param score
*/
typedef struct{
	char pseudo[400];
	int score;
}player_score;

#endif
