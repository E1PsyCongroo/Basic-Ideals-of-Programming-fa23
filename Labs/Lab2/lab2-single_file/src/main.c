#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "2048.h"
#include "asserts.h"

void test_all(void);
bool test_is_finished(void);
bool test_initialize_board(void);
bool test_move_and_merge_left(void);
bool test_move_and_merge_right(void);
bool test_move_and_merge_up(void);
bool test_move_and_merge_down(void);

int main(void) {
    char choice, ch;
    printf("%-35s%-35s\n", "1. play 2048", "2. run all test");
    printf("%-35s%-35s\n", "3. run test_initialize_board", "4. run test_is_finished");
    printf("%-35s%-35s\n", "5. run test_move_and_merge_left", "6. run test_move_and_merge_right");
    printf("%-35s%-35s\n", "7. run test_move_and_merge_up", "8. run test_move_and_merge_down");
    printf("input number to chooce:\n");
    choice = getchar();
    while ((ch = getchar()) != '\n') continue;
    switch (choice) {
    case '1':
        run_game();
        break;
    case '2':
        test_all();
        break;
    case '3':
        test_initialize_board();
        break;
    case '4':
        test_is_finished();
        break;
    case '5':
        test_move_and_merge_left();
        break;
    case '6':
        test_move_and_merge_right();
        break;
    case '7':
        test_move_and_merge_up();
        break;
    case '8':
        test_move_and_merge_down();
        break;
    default:
        printf("please input the number to chooce\n");
    }
    return 0;
}

void test_all(void) {
    if(test_initialize_board() &&
        test_is_finished() &&
        test_move_and_merge_left() &&
        test_move_and_merge_right() &&
        test_move_and_merge_down() &&
        test_move_and_merge_up()) {
        printf("all test pass\n");
    }
    else {
        printf("test fail\n");
    }
}

bool test_initialize_board(void) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 2;
        }
    }
    initialize_board();
    int expected[BOARD_SIZE][BOARD_SIZE] = { 0 };
    bool result = assert_equals_board("test_initialize_board", expected);
    if (result) {
        printf("test_initialize_board pass\n");
    }
    else {
        printf("test_initialize_board fail\n");
    }
    return result;
}

bool test_is_finished(void) {
    initialize_board();
    bool result = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 2;
        }
    }
    result &= assert_is_finished("test_is_finished_1", true);

    initialize_board();
    result &= assert_is_finished("test_is_finished_2", false);

    board[0][0] = 2048;
    result &= assert_is_finished("test_is_finished_3", true);

    if (result) {
        printf("test_is_finished pass\n");
    }
    else {
        printf("test_is_finished fail\n");
    }

    return result;
}

bool test_move_and_merge_left(void) {
    bool result = true;
    bool generate_flag;

    initialize_board();
    board[0][2] = board[0][3] = 2;
    /*  board:
    0   0   2   2
    0   0   0   0
    0   0   0   0
    0   0   0   0
    */
    int expected1[BOARD_SIZE][BOARD_SIZE] = {{4, 0, 0, 0},
                                             {0, 0, 0, 0},
                                             {0, 0, 0, 0},
                                             {0, 0, 0, 0},};

    bool expected1_flag = true;
    generate_flag= move_and_merge_left();
    result &= assert_equals_board("test_move_and_merge_left_1", expected1);
    result &= assert_equals_bool("test_move_and_merge_left_1_generate_flag", generate_flag, expected1_flag);

    initialize_board();
    board[0][0] = 4;
    board[0][2] = board[0][3] = 2;
    /*  board:
    4   0   2   2
    0   0   0   0
    0   0   0   0
    0   0   0   0
    */
    int expected2[BOARD_SIZE][BOARD_SIZE] = {{4, 4, 0, 0},
                                             {0, 0, 0, 0},
                                             {0, 0, 0, 0},
                                             {0, 0, 0, 0},};
    bool expected2_flag = true;
    generate_flag= move_and_merge_left();
    result &= assert_equals_board("test_move_and_merge_left_2", expected2);
    result &= assert_equals_bool("test_move_and_merge_left_2_generate_flag", generate_flag, expected2_flag);

    initialize_board();
    board[0][1] = board[0][2] = board[0][3] = 2;
    /*  board:
    0   2   2   2
    0   0   0   0
    0   0   0   0
    0   0   0   0
    */
    int expected3[BOARD_SIZE][BOARD_SIZE] = {{4, 2, 0, 0},
                                             {0, 0, 0, 0},
                                             {0, 0, 0, 0},
                                             {0, 0, 0, 0},};
    bool expected3_flag = true;
    generate_flag= move_and_merge_left();
    result &= assert_equals_board("test_move_and_merge_left_3", expected3);
    result &= assert_equals_bool("test_move_and_merge_left_3_generate_flag", generate_flag, expected3_flag);

    initialize_board();
    board[0][0] = board[0][1] = 2;
    board[0][2] = board[0][3] = 4;
    /*  board:
    2   2   4   4
    0   0   0   0
    0   0   0   0
    0   0   0   0
    */
    int expected4[BOARD_SIZE][BOARD_SIZE] = {{4, 8, 0, 0},
                                             {0, 0, 0, 0},
                                             {0, 0, 0, 0},
                                             {0, 0, 0, 0},};
    bool expected4_flag = true;
    generate_flag= move_and_merge_left();
    result &= assert_equals_board("test_move_and_merge_left_4", expected4);
    result &= assert_equals_bool("test_move_and_merge_left_4_generate_flag", generate_flag, expected4_flag);

    initialize_board();
    board[0][0] = 16;
    board[0][1] = 8;
    board[0][2] = 4;
    board[0][3] = 2;
    /*  board:
    16  8   4   2
    0   0   0   0
    0   0   0   0
    0   0   0   0
    */
    int expected5[BOARD_SIZE][BOARD_SIZE] = {{16, 8, 4, 2},
                                             {0, 0, 0, 0},
                                             {0, 0, 0, 0},
                                             {0, 0, 0, 0},};
    bool expected5_flag = false;
    generate_flag= move_and_merge_left();
    result &= assert_equals_board("test_move_and_merge_left_5", expected5);
    result &= assert_equals_bool("test_move_and_merge_left_5_generate_flag", generate_flag, expected5_flag);

    if (result) {
        printf("test_move_and_merge_left pass\n");
    }
    else {
        printf("test_move_and_merge_left fail\n");
    }
    return result;
}


bool test_move_and_merge_right(void) {
    bool result = true;
    // to do, delete the following two lines of code to write tests
    assert_false("test_move_and_merge_right todo", true);
    return false;

    if (result) {
        printf("test_move_and_merge_right pass\n");
    }
    else {
        printf("test_move_and_merge_right fail\n");
    }
    return result;
}

bool test_move_and_merge_up(void) {
    bool result = true;
    // to do, delete the following two lines of code to write tests
    assert_false("test_move_and_merge_up todo", true);
    return false;

    if (result) {
        printf("test_move_and_merge_up pass\n");
    }
    else {
        printf("test_move_and_merge_up fail\n");
    }
    return result;
}

bool test_move_and_merge_down(void) {
    bool result = true;
    // to do, delete the following two lines of code to write tests
    assert_false("test_move_and_merge_down todo", true);
    return false;

    if (result) {
        printf("test_move_and_merge_down pass\n");
    }
    else {
        printf("test_move_and_merge_down fail\n");
    }
    return true;
}
