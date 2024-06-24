#include "token.h"
#include <stdio.h>

int postfix_calculator(char *str)
{
    int token_count = 0;
    tokenization(str, &token_count);
    return 1;
}

int main()
{
    char str[100];
    printf("Enter a postfix expression: ");
    fgets(str, 100, stdin);

    int result = postfix_calculator(str);
    printf("Result: %d\n");
    return 0;
}


/*

int main(){
    char str[] = {"pi3+e-"};
    int token_count;
    token_t *tokens = tokenization(str, &token_count);

    for (int i=0; i < token_count; i++){
        if (tokens[i].type == 0) {
            printf("Operator: %d [%d]\n", tokens[i].value, i);
        } 
        else{
            printf("Number: %d [%d]\n", tokens[i].value, i);
        }
    }
    printf("Number of tokens: %d", token_count);

    free(tokens);
    return 0;
}

*/