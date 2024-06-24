#ifndef OPERATORS_H
#define OPERATORS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ADD_ARG 2
#define SUB_ARG 2
#define MUL_ARG 2
#define DIV_ARG 2
#define LN_ARG 1
#define LOG_ARG 2
#define PI_ARG 0
#define E_ARG 0

typedef enum Operators {
	ADD = '+',
	SUB = '-',
	MUL = '*',
	DIV = '/',
	LN = 'l' + 'n',
	LOG = 'l' + 'o' + 'g',
	PI = 'p' + 'i',
	E = 'e'
}operators_t;

double add(double, double);
double substract(double, double);
double multiply(double, double);
double divide(double, double);
double ln(double);
double logorithm(double, double);
double num_pi();
double num_e();
#endif