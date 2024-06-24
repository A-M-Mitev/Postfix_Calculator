#include "token.h"
#include "validate_and_process.h"

double postfix_calculator(char *str)
{
    int token_count = 0;
    token_t* token_arr = tokenization(str, &token_count);
    if(validate(token_arr, token_count) == 0) {
	exit(1);
    }
    double result = process(token_arr, token_count);
    free(token_arr);
    return result;
}

int main()
{
    char str[256];
    printf("\nEnter a postfix expression: ");
    fgets(str, 256, stdin);

    double result = postfix_calculator(str);
    printf("\nResult: %lf\n", result);
    return 0;
}