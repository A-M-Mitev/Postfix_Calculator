#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include "operators.h"

typedef struct Token
{
    char type; // 1 -> number; 0 -> operator
    int value;
} token_t;

token_t *tokenization(char *str, int *token_count);

#endif