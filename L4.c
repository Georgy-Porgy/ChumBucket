
#define _USE_MATH_DEFINES
#include "pch.h"
#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main()
{
	test_add();
	test_sub();
	test_mul();
	test_div();
	test_sin();
	test_cos();
}


float add(float num1, float num2) {
	float value;
	value = num1 + num2;
	return value;
}
float sub(float num1, float num2) {
	float value;
	value = num1 - num2;
	return value;
}
float mul(float num1, float num2) {
	float value;
	value = num1 * num2;
	return value;
}
float div(float num1, float num2) {
	float value;
	value = num1 / num2;
	return value;
}

float msin(float angle) {
	float value;
	value = sin(M_PI * angle / 180 - 0);


	return value;
}
float mcos(float angle) {
	float value;
	value = cos(M_PI * angle / 180.0);
	return value;
}
void test_add(void)
{
	printf("Test 1: \n\t 2.5+8.4 Oczekiwano: 4.1, \n\t a uzyskano: %g\n", add(2.1, 2.0));
	printf("Test 2: \n\t 0.1+0 Oczekiwano: 0.1, \n\t a uzyskano: %g\n", add(0.1, 0.0));
	printf("Test 3: \n\t 2.09+0.05 Oczekiwano: 2.14, \n\t a uzyskano: %g\n", add(2.09, 0.05));
	printf("Test 4: \n\t 2.77+5 Oczekiwano: 7.77, \n\t a uzyskano: %g\n", add(2.77, 5.0));
	printf("Test 5: \n\t 42+0 Oczekiwano: 42, \n\t a uzyskano: %g\n", add(42, 0));
	printf("Test 6: \n\t 0.0000000001+0 Oczekiwano: 0,0000000001, \n\t a uzyskano: %.12f\n", add(0.0000000001, 0.0));

}
void test_sub(void) {
	printf("Test 1: \n\t 4.5-2.5 Oczekiwano: 2, \n\t a uzyskano: %g\n", sub(4.5, 2.5));
	printf("Test 2: \n\t 0..1-0 Oczekiwano: 0.1, \n\t a uzyskano: %g\n", sub(0.1, 0.0));
	printf("Test 3: \n\t 2.09-0.05 Oczekiwano: 2.04, \n\t a uzyskano: %g\n", sub(2.09, 0.05));
	printf("Test 4: \n\t 5-2.77 Oczekiwano: 2.23, \n\t a uzyskano: %g\n", sub(5, 2.77));
	printf("Test 5: \n\t 42-0 Oczekiwano: 42, \n\t a uzyskano: %g\n", sub(42, 0));
	printf("Test 6: \n\t 0.0000000001-0 Oczekiwano: 0,0000000001, \n\t a uzyskano: %.12f\n", sub(0.0000000001, 1.0));
}
void test_mul(void) {
	printf("Test 1: \n\t 2.5*8.4 Oczekiwano: 21, \n\t a uzyskano: %g\n", mul(2.5, 8.4));
	printf("Test 2: \n\t 0.1*0 Oczekiwano: 0, \n\t a uzyskano: %g\n", mul(0.1, 0.0));
	printf("Test 3: \n\t 2.09*0.05 Oczekiwano: 0.1045, \n\t a uzyskano: %g\n", mul(2.09, 0.05));
	printf("Test 4: \n\t 2.77*5 Oczekiwano: 13.85, \n\t a uzyskano: %g\n", mul(2.77, 5));
	printf("Test 5: \n\t 42*0 Oczekiwano: 42, \n\t a uzyskano: %g\n", mul(42, 0));
	printf("Test 6: \n\t 0.0000000001*0 Oczekiwano: 0, \n\t a uzyskano: %.12f\n", mul(0.0000000001, 0.0));
}
void test_div(void) {
	printf("Test 1: \n\t 8.9/2 Oczekiwano: 4.45, \n\t a uzyskano: %g\n", div(8.9, 2));
	printf("Test 2: \n\t 0.1/5 Oczekiwano: 0.02, \n\t a uzyskano: %g\n", div(0.1, 5.0));
	printf("Test 3: \n\t 2.09/0.05 Oczekiwano: 41,8, \n\t a uzyskano: %g\n", div(2.09, 0.05));
	printf("Test 4: \n\t 2.77/5 Oczekiwano: 0.554, \n\t a uzyskano: %g\n", div(2.77, 5));
	printf("Test 5: \n\t 42/2 Oczekiwano: 21, \n\t a uzyskano: %g\n", div(42, 2));
	printf("Test 6: \n\t 0.0000000001/10 Oczekiwano: 0,00000000001, \n\t a uzyskano: %.12f\n", div(0.0000000001, 10.0));
}

void test_sin(void) {
	printf("Test 1: \n\t sin(0) Oczekiwano: 0, \n\t a uzyskano: %2.2f\n", msin(0.0));
	printf("Test 2: \n\t sin(90) Oczekiwano: 1, \n\t a uzyskano: %2.2f\n", msin(90.0));
	printf("Test 3: \n\t sin(180) Oczekiwano: 0, \n\t a uzyskano: %2.2f\n", msin(180.0));
	printf("Test 4: \n\t sin(360) Oczekiwano: 0, \n\t a uzyskano: %2.2f\n", msin(360.0));
	printf("Test 5: \n\t sin(30) Oczekiwano: 0.5, \n\t a uzyskano: %2.2f\n", msin(30.0));
	printf("Test 6: \n\t sin(270) Oczekiwano: -1, \n\t a uzyskano: %2.2f\n", msin(270.0));
}
void test_cos(void) {
	printf("Test 1: \n\t cos(0) Oczekiwano: 1, \n\t a uzyskano: %2.2f\n", mcos(0.0));
	printf("Test 2: \n\t cos(90) Oczekiwano: 0, \n\t a uzyskano: %2.2f\n", mcos(90.0));
	printf("Test 3: \n\t cos(180) Oczekiwano: -1, \n\t a uzyskano: %2.2f\n", mcos(180.0));
	printf("Test 4: \n\t cos(360) Oczekiwano: 1, \n\t a uzyskano: %2.2f\n", mcos(360.0));
	printf("Test 5: \n\t cos(60) Oczekiwano: 0.5, \n\t a uzyskano: %2.2f\n", mcos(60.0));
	printf("Test 6: \n\t cos(270) Oczekiwano: 0, \n\t a uzyskano: %2.2f\n", mcos(270.0));

}
