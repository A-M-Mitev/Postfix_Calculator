#ifndef VALIDATE_AND_PROCESS_H
#define VALIDATE_AND_PROCESS_H

#include "token.h"
#include "stack.h"
#include "operators.h"

int validate(token_t* tokens, int token_count);

double process(token_t* token_arr, int token_count);

#endif