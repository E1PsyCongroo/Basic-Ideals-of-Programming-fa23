//------------------------------------------------------------------------------
/*  Grammar:
    Expression:
        Term
        Term "+"|"-" Term ...
    Term:
        Primary
        Primary "*"|"/" Primary ...
    Primary:
        Number
        "(" Expression ")"
    Number:
        floating-point-literal
*/
//------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Token {
    char kind;        // what kind of token
    double value;     // for numbers: a value
} Token;

typedef struct Token_Buffer {
    Token token;
    bool full;
} Token_Buffer;

void put_back(Token_Buffer* tb, Token t);               // put token back to token_buffer
Token get_token(Token_Buffer* tb);                      // get token from token_buffer or stdin
double expression(Token_Buffer* tb);                    // read and evaluate a Expression
double term(Token_Buffer* tb);                          // read and evaluate a Term
double primary(Token_Buffer * tb);                      // read and evaluate a Primary
void error(char* str);

int main(void) {
    Token_Buffer tb = { .full = false, .token = { 0, 0 } };
    Token t = { 0, 0 };
    double val = 0;
    while (true) {
        t = get_token(&tb);
        if (t.kind == 'q') {
            break;
        }
        if (t.kind == ';') {
            printf("= %f\n", val);
        }
        else {
            put_back(&tb, t);
            val = expression(&tb);
        }
    }
    printf("calculator exit\n");
    return 0;
}

void error(char* str) {
    printf(str);
    putchar('\n');
    exit(1);
}

void put_back(Token_Buffer* tb, Token t) {
    // TODO
}

Token get_token(Token_Buffer* tb) {
    // TODO
}

double expression(Token_Buffer* tb) {
    // TODO
}

double term(Token_Buffer* tb) {
    // TODO
}

double primary(Token_Buffer * tb) {
    // TODO
}

