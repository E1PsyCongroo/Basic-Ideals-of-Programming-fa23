#ifndef _ASSERTS_H
#define _ASSERTS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "2048.h"

bool assert_true(char* msg, bool actual);
bool assert_false(char* msg, bool actual);
bool assert_equals_bool(char* msg, bool expected, bool actual);
bool assert_equals_char(char* msg, char expected, char actual);
bool assert_equals_int(char* msg, int expected, int actual);
bool assert_equals_unsigned_int(char* msg, unsigned int expected, unsigned int actual);
bool assert_equals_board(char* msg, int expected[][BOARD_SIZE]);
bool assert_is_finished(char*msg, bool expected);

#endif
