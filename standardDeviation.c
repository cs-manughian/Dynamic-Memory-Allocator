/*
* Author:    Cosima Manughian-Peter
* Class:     CECS 424
* Assigment: Lab 1
* File Name: standardDeviation.c
* Purpose:   Use allocator to solve a standard deviation
*            problem.
* Due Date:  September 9, 2015
*/
#include "standardDeviation.h"


double calculateMean(int *array, int length)
{
	double mean = 0;
	double sum = 0;

	//Calculate the mean:
	//First sum the integers in the array
	for (int i = 0; i < length; i++)
	{
		sum = sum + array[i];
	}

	//Second, divide by the total number of integers
	mean = sum / (double)length;

	return mean;
}


double calculateStdDeviation(int *array, int length)
{
	// Calculate standard deviation of integers
	//   Formula:
	//   sqrt( 1/n * summation(( xi - u )^2), 1 to n ),
	//   where xi = integers entered and u = total arithmetic mean
	//   and n is the size of the array

	double mean = calculateMean(array, length);
	double summation = 0;
	double stdDev = 0;

	//First calculate summation(( xi - u )^2)
	for (int i = 0; i < length; i++)
	{
		summation = summation + (array[i] - mean)*(array[i] - mean);
	}

	//Calculate the standard deviation
	stdDev = summation / (double)length;
	stdDev = sqrt(stdDev);

	return stdDev;
}
