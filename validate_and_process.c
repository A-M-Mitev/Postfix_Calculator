#include "validate_and_process.h"

// Returns 1 after successful validation.
int validate(token_t* tokens, int token_count) {
	int stack_size = 0;
	for(int i = 0; i < token_count; ++i) {
		if(tokens[i].type == 1) {
			++stack_size;
		}
		else {
			operators_t curr_op = tokens[i].value;
                        switch (curr_op) {
                        case ADD:
			    	if(stack_size < ADD_ARG) {
					printf("Not enough arguements for token[%d]", i + 1);
					return 0;
				}
				else stack_size -= ADD_ARG - 1;
				break; 
                        case SUB:
				if(stack_size < SUB_ARG) {
					printf("Not enough arguements for token[%d]", i + 1);
					return 0;
				}
				else stack_size -= SUB_ARG - 1;
				break; 
                        case MUL:
				if(stack_size < MUL_ARG) {
					printf("Not enough arguements for token[%d]", i + 1);
					return 0;
				}
				else stack_size -= MUL_ARG - 1;
				break; 
                        case DIV:
				if(stack_size < DIV_ARG) {
					printf("Not enough arguements for token[%d]", i + 1);
					return 0;
				}
				else stack_size -= DIV_ARG - 1;
				break;
                        case LN:
				if(stack_size < LN_ARG) {
					printf("Not enough arguements for token[%d]", i + 1);
					return 0;
				}
				else stack_size -= LN_ARG - 1;
				break;
                        case LOG:
				if(stack_size < LOG_ARG) {
					printf("Not enough arguements for token[%d]", i + 1);
					return 0;
				}
				else stack_size -= LOG_ARG - 1;
				break;
                        case PI:
				if(stack_size < PI_ARG) {
					printf("Not enough arguements for token[%d]", i + 1);
					return 0;
				}
				else stack_size -= PI_ARG - 1;
				break;
                        case E:
				if(stack_size < E_ARG) {
					printf("Not enough arguements for token[%d]", i + 1);
					return 0;
				}
				else stack_size -= E_ARG - 1;
				break;
                        default:
                                printf("Invalid operation in token[%d]", i + 1);
				return 0;
                                break;
                        }
		}
	}
	if(stack_size > 1) {
		printf("More than 1 numbers left in stack after all operations");
		return 0;
	}else if(stack_size < 1) {
		printf("Less than 1 numbers left in stack after all operations");
		return 0;
	}
	return 1;
}

double process(token_t* token_arr, int token_count) {
	stack_t* stack = initStack();
	for(int i = 0; i < token_count; ++i) {
		if(token_arr[i].type) {
			pushback(stack, token_arr[i].value);
		}
		else {
			operators_t curr_op = token_arr[i].value;
                        switch (curr_op) {
                        case ADD:
				pushback(stack, add(popback(stack), popback(stack)));
				break;
                        case SUB:
				pushback(stack, substract(popback(stack), popback(stack)));
				break;
                        case MUL:
				pushback(stack, multiply(popback(stack), popback(stack)));
				break; 
                        case DIV:
				pushback(stack, divide(popback(stack), popback(stack)));
				break;
                        case LN:
				pushback(stack, ln(popback(stack)));
				break;
                        case LOG:
				pushback(stack, logorithm(popback(stack), popback(stack)));
				break;
                        case PI:
				pushback(stack, num_pi());
				break;
                        case E:
				pushback(stack, num_e());
				break;
                        }
		}
	}
	double result = popback(stack);
	free(stack);
	return result;
}