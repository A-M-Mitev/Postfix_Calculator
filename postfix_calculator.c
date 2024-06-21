#include <stdio.h>

union name
{
    int number;
    enum operators operator;
};

typedef struct
{
    int type; // neka 0 e za operator, 1 e za number
}Token ;

int *tokenization(char *str, int *token_count)
{
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    //duljina na str

    Token *tokens = (Token *)malloc(length * sizeof(Token)); //(Token *) e za da e ot tip struct Token
    *token_count = 0; //

    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {

        }
    }
}

int postfix_calculator(char *str)
{
    int token_count = 0;
    tokenization(str, &token_count);
    return 1;
}

int main()
{
    char str[100];
    union name;
    printf("Enter a postfix expression: ");
    gets(str);

    int result = postfix_calculator(str);
    printf("Result: %d\n")
    return 0;
}