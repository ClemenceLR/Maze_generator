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
 * Testing the functions of maze_game
 * @author  Clemence Le Roux
 * @version 1.1
 * @date    24/10/2020
 */

#include "minunit.h"
#include "files_manager.h"
#include "cell.h"
#include "game_manager.h"
#include "display_maze.h"
#include "user_input.h"
#include "useful.h"
#undef MINUNIT_EPSILON
#define MINUNIT_EPSILON 1E-2

void test_setup(void) {
}

void test_teardown(void) {
}

/* Test the limit cases of this function */
MU_TEST(check_points_test){
    mu_assert(-1 == check_points("./salut"),"Forbidden name");
    mu_assert(-1 == check_points("hehehe/"),"Forbidden name");
    mu_assert(1 == check_points("test"),"Allowed name");
}
MU_TEST(check_move_test){
    int mv = check_move('h');
    mu_assert(0 == mv,"Forbidden char");
    mv = check_move('/');
    mu_assert(0 == mv,"Forbidden char");
    mv =check_move('a');
    mu_assert(1 == mv,"Allowed char");
    mv = check_move('z');
    mu_assert(1 == mv,"Allowed char");
    mv = check_move('q');
    mu_assert(1 == mv,"Allowed char");
    mv = check_move('s');
    mu_assert(1 == mv,"Allowed char");
    mv = check_move('d');
    mu_assert(1 == mv,"Allowed char");

}

MU_TEST(cell_initialisation){
    cell cell_test = {-1,'T',1,2};
    mu_assert(-1 == cell_test.id,"Test id");
    mu_assert('T' == cell_test.content ,"Test content");
    mu_assert(1 == cell_test.column,"Test column");
    mu_assert(2 == cell_test.line,"Test line");
}

MU_TEST(cell_table_size_test){
    cell cell_table[4];
    cell end_cell = {-1,' '};
    cell normal_cell = {1,'X'};
    cell_table[0] = normal_cell;
    cell_table[1] = normal_cell;
    cell_table[2] = normal_cell;
    cell_table[3] = end_cell;
    mu_assert(3 == cell_table_size(cell_table),"Test cell table size");
}

MU_TEST(int_table_size_test){
    int table[4] = {1,36,42,-1};
    mu_assert(3 == int_table_size(table),"Test table size");
}

MU_TEST(check_if_already_existing_test){
    int table[10] = {1,52,64,68,90,15,48,92,64,-1};
    mu_assert(0 == check_if_already_existing(42,table),"Item not registered");
    mu_assert(0 == check_if_already_existing(100,table),"Item not registered");
    mu_assert(1 == check_if_already_existing(90,table),"Item already registered");
    mu_assert(1 == check_if_already_existing(64,table),"Item already registered");

}


MU_TEST_SUITE(test_suite) {
   /* MU_SUITE_CONFIGURE(&test_setup, &test_teardown);*/
    printf("-----Tests user_input.c-----\n");
    MU_RUN_TEST(check_points_test);
    MU_RUN_TEST(check_move_test);
    printf("\n-----Tests cell structure-----\n");
    MU_RUN_TEST(cell_initialisation);
    printf("\n-----Tests useful.c-----\n");
    MU_RUN_TEST(cell_table_size_test);
    MU_RUN_TEST(int_table_size_test);
    MU_RUN_TEST(check_if_already_existing_test);

}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
