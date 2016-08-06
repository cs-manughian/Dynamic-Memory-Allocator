/*
* Author:    Cosima Manughian-Peter
* Class:     CECS 424
* Assigment: Lab 1
* File Name: allocator.h
* Due Date:  September 9, 2015
*/
#pragma once


//Global variables
extern const int SIZE_OF_VOID_PTR;
extern const int SIZE_OF_OVERHEAD;


//Structures
typedef struct Block{
	int	          block_size;
	struct Block *next_block;	
	void         *data;
}Block;

//Function prototypes
void my_initialize_heap(int size);
void* my_alloc(int size);
void my_free(void *data);

