#include <stdio.h>
#include "token.h"

token_t *tokenization(char *str, int *token_count)
{
    int length = 0;
    while (str[length] != '\n')
    {
        length++;
    }
    token_t *tokens = (token_t *)malloc(length * sizeof(token_t));
    *token_count = 0;

    int flag = -1;
    // kazva do sega kakvo sme vuvejdali
    // 2 -> space, 1 -> number; 0 -> operator, -1 -> nothing

    for (int i = 0; str[i] != '\n'; ++i)
    {
        if(str[i] != ' '){
            if (flag == 1)
            {
                if (str[i] >= '0' && str[i] <= '9'){
                    tokens[*token_count].value *= 10;
                    tokens[*token_count].value += str[i] - '0';
                }
                else{
                    *token_count += 1;
                    tokens[*token_count].value = str[i];
                    tokens[*token_count].type = 0;
                    flag = 0;
                }
            }
            else{
                if (flag == 0){
                    if (str[i] >= '0' && str[i] <= '9'){
                        *token_count += 1;
                        tokens[*token_count].value = str[i] - '0';
                        tokens[*token_count].type = 1;
                        flag = 1;
                    }
                    else{
                        operators_t prev_op = tokens[*token_count].value;
                        switch (prev_op)
                        {
                            case ADD: 
                            case SUB:
                            case MUL:
                            case DIV:
                            case LN:
                            case LOG:
                            case PI:
                            case E: 
                                *token_count += 1;
                                tokens[*token_count].value = str[i];
                                tokens[*token_count].type = 0;
                                break;
                            default:
                                tokens[*token_count].value += str[i];
                                break;
                        }
                    }
                }
                else{
                    if (str[i] >= '0' && str[i] <= '9'){
                        if(flag != -1){
                            *token_count += 1;
                        }
                        tokens[*token_count].value = str[i] - '0';
                        tokens[*token_count].type = 1;
                        flag = 1;
                    }
                    else{
                        if(flag != -1){
                            *token_count += 1;
                        }
                        tokens[*token_count].value = str[i];
                        tokens[*token_count].type = 0;
                        flag = 0;
                    }
                }
            }
        }
        else{
            flag = 2;
        }
    }
    *token_count += 1;
    return tokens;
}
