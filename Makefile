CC = gcc
CFLAGS = -I./include -O1
OBJS =  main.c
SRC_PATH = ./src/
SAVE_PATH = ./saves/
LIBS_PATH = ./include/
TEST_PATH = ./src/test/
CTFLAGS = -I/../../include -01

maze_exe : $(SRC_PATH)display_maze.o $(SRC_PATH)files_manager.o $(SRC_PATH)game_manager.o $(SRC_PATH)main.o $(SRC_PATH)maze_allocation_func.o $(SRC_PATH)maze_generation.o $(SRC_PATH)useful.o $(SRC_PATH)user_input.o $(LIBS_PATH)player.h
	$(CC) -o $@ $^ 

display_maze.o : $(SRC_PATH)display_maze.c
	$(CC) $(CFLAGS) -o $@ $<

files_manager.o : $(SRC_PATH)files_manager.c
	$(CC) $(CFLAGS) -o $@ $<

game_manager.o : $(SRC_PATH)game_manager.c
	$(CC) $(CFLAGS) -o $@ $<

main.o : $(SRC_PATH)main.c
	$(CC) $(CFLAGS) -o $@ $<

maze_allocation_func.o : $(SRC_PATH)maze_allocation_func.c
	$(CC) $(CFLAGS) -o $@ $<

useful.o : $(SRC_PATH)useful.c
	$(CC) $(CFLAGS) -o $@ $<

user_input.o : $(SRC_PATH)user_input.c
	$(CC) $(CFLAGS) -o $@ $<

maze_generation.o : $(SRC_PATH)maze_generation.c
	$(CC) $(CFLAGS) -o $@ $<

test_maze_game.o: $(TEST_PATH)test_maze_game.c
	$(CC) $(CTFLAGS) -o $@ $^
clear : 
	-rm $(SRC_PATH)*.o

clear_test:
	-rm $(SRC_PATH)*.o
	-rm $(TEST_PATH)*.o

test : $(TEST_PATH)test_maze_game.o $(SRC_PATH)display_maze.o $(SRC_PATH)files_manager.o $(SRC_PATH)game_manager.o $(SRC_PATH)maze_allocation_func.o $(SRC_PATH)maze_generation.o $(SRC_PATH)useful.o $(SRC_PATH)user_input.o $(LIBS_PATH)player.h
	$(CC) -o $@ $^
