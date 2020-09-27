#include <time.h>
#include <stdlib.h>
#include "useful.h"
int random_int(int max){
	srand(time(NULL));
	int random_number = rand()%max;
	return random_number;
}
