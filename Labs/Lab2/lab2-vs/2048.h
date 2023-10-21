#ifndef _2048_H
#define _2048_H

#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 4
extern int board[BOARD_SIZE][BOARD_SIZE];
enum direction{UP, DOWN, LEFT, RIGHT, NONE};

/* run the game */
void run_game(void);
/* initialize the board */
void initialize_board(void);
/* generate randon number at board */
void generate_number(void);
/* get the direciton from keyboard input */
enum direction choose_direction(void);
/* print the game board */
void print_board(void);

/* helper function */
void swap(int *a, int *b);
/* determine if the game is over */
bool is_finished(void);
/* move left */
bool move_and_merge_left(void);
/* move right */
bool move_and_merge_right(void);
/* move up */
bool move_and_merge_up(void);
/* move down */
bool move_and_merge_down(void);

#endif