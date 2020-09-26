#include <stdio.h>
#include "maze.h"
#include "cell.h"

/* Main of the programm : manage the game system
 * */
int main(int argc, char* argv[]){
	cell** maze;
	maze = create_maze_area(maze);
	free_maze(maze);
	return 0;
}
