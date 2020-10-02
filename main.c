#include <stdio.h>
#include "maze.h"
#include "cell.h"
#include "maze_allocation_func.h"
#include "maze_generation.h"

/* Main of the programm : manage the game system
 * */
int main(int argc, char* argv[]){
	cell** maze;
	maze = create_maze_area(maze);
	free_maze(maze);
	return 0;
}
