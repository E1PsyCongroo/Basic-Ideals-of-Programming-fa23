#include "asserts.h"
#include "2048.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Returns true if actual is equal to true
    Othewise, will return false with this message:
    "Assertion error: expected (msg) to be true, but got false"
*/
bool assert_true(char *msg, bool actual) {
    if (!actual) {
        printf("Assertion error: expected %s to be true, but got false\n", msg);
        return false;
    }
    else {
        return true;
    }
}

/*
    Returns true if actual is equal to false
    Othewise, will return false with this message:
    "Assertion error: expected (msg) to be false, but got true"
*/
bool assert_false(char *msg, bool actual) {
    if (actual) {
        printf("Assertion error: expected %s to be false, but got true\n", msg);
        return false;
    }
    else {
        return true;
    }
}

/*
    Returns true if expected is equal to actual
    Otherwise, will return false with this message:
    "Assertion error: expected (msg) to be (expected) but got (actual)"
*/
bool assert_equals_char(char *msg, char expected, char actual) {
    if (expected != actual) {
        printf("Assertion error: expected %s to be %c but got %c\n", msg, expected, actual);
        return false;
    }
    else {
        return true;
    }
}

/*
    Returns true if expected is equal to actual
    Otherwise, will return false with this message:
    "Assertion error: expected (msg) to be (expected) but got (actual)"
*/
bool assert_equals_int(char *msg, int expected, int actual) {
    if (expected != actual) {
        printf("Assertion error: expected %s to be %d but got %d\n", msg, expected, actual);
        return false;
    }
    else {
        return true;
    }
}

/*
    Returns true if expected is equal to actual
    Otherwise, will return false with this message:
    "Assertion error: expected (msg) to be (expected) but got (actual)"
*/
bool assert_equals_unsigned_int(char *msg, unsigned int expected, unsigned int actual) {
    if (expected != actual) {
        printf("Assertion error: expected %s to be %d but got %d\n", msg, expected, actual);
        return false;
    }
    else {
        return true;
    }
}

/*
    Returns true if expected is equal to actual
    Otherwise, will return false with this message:
    "Assertion error: expected (msg) to be (expected) but got (actual)"
*/
bool assert_equals_bool(char *msg, bool expected, bool actual) {
    if (expected != actual) {
        printf("Assertion error: expected %s to be %s but got %s\n", msg, expected ? "true" : "false", actual ? "true" : "false");
        return false;
    }
    else {
        return true;
    }
}

/*
    Returns true if expected is equal to actual
    Otherwise, will return false with this message:
    "Assertion error: expected (msg) to be (expected) but got (actual)"
*/
bool assert_equals_str(char *msg, char *expected, char *actual) {
    if (strcmp(expected, actual)) {
        printf("Assertion error: expected %s to be %s but got %s\n", msg, expected, actual);
        return false;
    }
    else {
        return true;
    }
}

bool assert_equals_board(char *msg, int expected[][BOARD_SIZE]) {
    bool equal_flag = true;
    for (int i = 0; i < BOARD_SIZE && equal_flag; i++) {
        for (int j = 0; j < BOARD_SIZE && equal_flag; j++) {
            if (expected[i][j] != board[i][j]) {
                equal_flag = false;
            }
        }
    }
    if (!equal_flag) {
        printf("Assertion error: expected %s to be\n", msg);
        printf("--------------------\n");
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%5d", expected[i][j]);
            }
            putchar('\n');
        }
        printf("but got: \n");
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
        return false;
    }
    return true;
}

bool assert_is_finished(char *msg, bool expected) {
    if (is_finished() != expected) {
        printf("Assertion error: expected %s to be %s but got %s\n", msg, expected ? "true" : "false", is_finished() ? "true" : "false");
        return false;
    }
    else
    return true;
}