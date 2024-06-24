#include "operators.h"

double add(double num1, double num2) {
	return num1 + num2;
}

double substract(double num1, double num2) {
	return num1 - num2;
}

double multiply(double num1, double num2) {
	return num1 * num2;
}

double divide(double num1, double num2) {
	if(num2 == 0) {
		printf("\nEncountered division by zero. Exiting the program.\n");
		exit(1);
	}
	return num1 / num2;
}

double ln(double num) {
	if(num <= 0) {
		printf("\nThe number arguement of a log() cannot be negative or 0.\n");
		exit(1);
	}
	return log(num);
}

double logorithm(double num, double base) {
	if(num <= 0) {
		printf("\nThe number arguement of a log() cannot be negative or 0.\n");
		exit(1);
	}
	if(base <= 0) {
		printf("\nThe base of a log() cannot be negative or 0.\n");
		exit(0);
	}
	if(base == 1) {
		printf("\nThe base of log() cannot be 1.\n");
		exit(1);
	}
	return log(num) / log(base);
}

double num_pi() {
	return 3.14159;
}

double num_e() {
	return 2.71828;
}