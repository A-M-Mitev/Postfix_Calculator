all: token.o operators.o stack.o validate_and_process.o postfix_calculator.exe postfix_calculator.out

token.o: token.h token.c
	gcc -c token.c

operators.o: operators.h operators.c
	gcc -c operators.c

stack.o: stack.h stack.c
	gcc -c stack.c

validate_and_process.o: operators.o stack.o validate_and_process.h validate_and_process.c
	gcc -c validate_and_process.c

postfix_calculator.exe: token.o validate_and_process.o postfix_calculator.c
	gcc postfix_calculator.c token.o operators.o stack.o validate_and_process.o -o postfix_calculator.exe

postfix_calculator.out: token.o validate_and_process.o postfix_calculator.c
	gcc postfix_calculator.c token.o operators.o stack.o validate_and_process.o -o postfix_calculator.out

clean1:
	del -f *.o *.exe *.out

clean2:
	rm -f *.o *.exe *.out
