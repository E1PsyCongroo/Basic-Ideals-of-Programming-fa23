#include "2048.h"

int board[BOARD_SIZE][BOARD_SIZE];

void generate_number(void) {
    int empty_space[BOARD_SIZE * BOARD_SIZE][2];
    int count = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                empty_space[count][0] = i;
                empty_space[count][1] = j;
                count++;
            }
        }
    }

    if (count > 0) {
        int index = rand() % count;
        int x = empty_space[index][0];
        int y = empty_space[index][1];
        board[x][y] = (rand() % 2 + 1) * 2;
    }
}

enum direction choose_direction(void) {
    char dir = _getch();
    switch (dir) {
    case 'A': case 'a':
        return LEFT;
    case 'W': case 'w':
        return UP;
    case 'S': case 's':
        return DOWN;
    case 'D': case 'd':
        return RIGHT;
    default:
        return NONE;
    }
}

void print_board(void) {
    system("cls");
    printf("-------------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        putchar('|');
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != 0) {
                printf("%5d|", board[i][j]);
            }
            else {
                printf("     |");
            }
        }
        putchar('\n');
    }
    printf("-------------------------\n");
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void initialize_board(void) {
    /* to do */
}

bool is_finished(void) {
    bool flag_2048 = false;
    bool flag_no_space = true;

    /* to do */

    return flag_2048 || flag_no_space;
}

bool move_and_merge_left(void) {
    /* to do */
    return false;
}

bool move_and_merge_right(void) {
    /* to do */
    return false;
}

bool move_and_merge_up(void) {
    /* to do */
    return false;
}

bool move_and_merge_down(void) {
    /* to do */
    return false;
}

void run_game(void) {
    /*After completing, delete the following line to start the game.*/
    return 0;

    srand(time(0));
    initialize_board();
    generate_number();
    generate_number();
    print_board();
    enum direction direction;
    bool generate_flag = false;
    while (1) {
        while ((direction = choose_direction()) == NONE) {
            direction = choose_direction();
        }
        switch (direction) {
        case UP:
            generate_flag = move_and_merge_up();
            break;
        case DOWN:
            generate_flag = move_and_merge_down();
            break;
        case LEFT:
            generate_flag = move_and_merge_left();
            break;
        case RIGHT:
            generate_flag = move_and_merge_right();
            break;
        }
        if (is_finished()) {
            break;
        }
        if (generate_flag) generate_number();
        print_board();
    }
}

