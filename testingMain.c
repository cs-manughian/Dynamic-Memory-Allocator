/*
* Author:    Cosima Manughian-Peter
* Class:     CECS 424
* Assigment: Lab 1
* File Name: testingMain.c
* Purpose:   Test the allocator and use it to solve 
*            a standard deviation problem.
* Due Date:  September 9, 2015
*/
#include "standardDeviation.h"
#include "allocator.h"
#include <stdio.h>
#include <math.h>


int main() {


	/*

	//-----------------------//
	//-----TEST ALLOCATOR----//
	//-----------------------//
	
	my_initialize_heap(10000);

	//Test 1
	//-----------------------//
	printf("\n***TEST 1***\n\n");

	int *p, *r;
	p = my_alloc(sizeof(int));
	printf("Address of int pointer: 0x%X in hex and %d in dec \n", p, p);
	my_free(p);
	
	r = my_alloc(sizeof(int));
	printf("Address of int pointer:  0x%X in hex and %d in dec \n", r, r);
	//-----------------------//



	//Test 2
	//-----------------------//
	printf("\n***TEST 2***\n\n");

	int *q, *s;
	q = my_alloc(sizeof(int));
	s = my_alloc(sizeof(int));
	printf("Address of int pointer 1: 0x%X in hex and %d in dec\n", q, q);
	printf("Address of int pointer 2: 0x%X in hex and %d in dec\n", s, s);
	printf("Size of overhead + int: %d \n", SIZE_OF_OVERHEAD + sizeof(int));
	//-----------------------//



	//Test 3
	//-----------------------//
	printf("\n***TEST 3***\n\n");

	int *x, *t, *v;
	x = my_alloc(sizeof(int));
	t = my_alloc(sizeof(int));
	v = my_alloc(sizeof(int));

	printf("Address of int pointer 1: 0x%X in hex and %d in dec\n", x, x);
	printf("Address of int pointer 2: 0x%X in hex and %d in dec\n", t, t);
	printf("Address of int pointer 3: 0x%X in hex and %d in dec\n", v, v);
	my_free(t);

	double *y;
	y = my_alloc(sizeof(double));
	printf("Address of double pointer: 0x%X in hex and %d in dec\n", y, y);

	int *w = my_alloc(sizeof(int));
	printf("Address of int pointer: 0x%X in hex and %d in dec\n", w, w);
	//-----------------------//



	//Test 4
	//-----------------------//
	printf("\n***TEST 4***\n\n");
	char *c;
	int *z;
	c = my_alloc(sizeof(char));
	z = my_alloc(sizeof(int));
	printf("Address of char pointer: 0x%X in hex and %d in dec \n", c, c);
	printf("Address of int pointer:  0x%X in hex and %d in dec \n", z, z);
	//-----------------------//
	


	//Test 5
	//-----------------------//
	printf("\n***TEST 5***\n\n");

	int *myArray = my_alloc(100*sizeof(int));
	int *f = my_alloc(sizeof(int));
	*f = 13;

	printf("Address of array: 0x%X in hex and %d in dec \n", myArray, myArray);
	printf("Address of int: 0x%X in hex and %d in dec \n", f, f);
	printf("Value of int: %d in dec \n", *f);

	my_free(myArray);

	printf("Address of int: 0x%X in hex and %d in dec \n", f, f);
	printf("Value of int: %d in dec \n", *f);

	//-----------------------//

	*/

	//--------------------------------------//
	//---SOLVE STANDARD DEVIATION PROBLEM---//
	//--------------------------------------//


	int    numberOfIntegers = 0;
	int    currentInput = 0;
	double stdDeviation = 0;

	my_initialize_heap(10000);

	//First get user input 

	//Get the size of the array
	printf("Please enter a positive integer: ");
	scanf_s("%d", &numberOfIntegers);

	//Allocate space for an array of entered integers
	int *stdDevArray = my_alloc(numberOfIntegers * sizeof(int));

	//Read integers into the array
	for (int i = 0; i < numberOfIntegers; i++)
	{
		printf("Please enter an integer to put into the array: ");
		scanf_s("%d", &stdDevArray[i]);
	}


	// Calculate standard deviation of integers
	//   Formula:
	//   sqrt( 1/n * summation( xi - u )^2, 1 to n ),
	//   where xi = integers entered and u = total arithmetic mean
	stdDeviation = calculateStdDeviation(stdDevArray, numberOfIntegers);

	//Print the standard deviation
	printf("The standard deviation is : %f ", stdDeviation);
	

	system("pause");

	return 0;
}
