#ifndef US_INPUT_H
#define US_INPUT_H

/** Handle the user input in the menu (number between 1 and 4)
 */
int user_input_menu();

/** Handle the user input for the maze dimensions 
 */
int user_input_int();

/** Handle the user input for the name of the file to load
 * @param file_name : table of chars
 */
void user_input_string(char file_name[]);

/** Check if the user entered a forbiden character
 * @param file_name
*/
int check_points(char *file_name);
/** Check if the user move is in the allowed characters
 * @param move
*/
int check_move(char move);

/** Handle the user move input
*/
int user_input_char();

#endif