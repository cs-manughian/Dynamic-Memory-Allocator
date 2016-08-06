/*
* Author:    Cosima Manughian-Peter
* Class:     CECS 424
* Assigment: Lab 1
* File Name: allocator.c
* Purpose:   Create a dynamic memory allocator (heap manager).
*            Use a simple free list system of heap allocation.
* Due Date:  September 9, 2015
*/
#include "allocator.h"
#include <stdlib.h>
#include <math.h>


//Global variables
const int SIZE_OF_VOID_PTR = sizeof(void*);
const int SIZE_OF_OVERHEAD = sizeof(int) + sizeof(void*);

//Global pointer to Block at head of free list
Block *free_head;


void my_initialize_heap(int size)
{
	//Use malloc to initialize a buffer of size (param) 
	//to use in the custom allocator.
	free_head = (Block *)malloc(size);

	//Set the initial block size
	free_head->block_size = size - SIZE_OF_OVERHEAD;

	//Set initial next block to null
	free_head->next_block = 0;

	//Initialize data pointer
	free_head->data = ((char*)free_head + SIZE_OF_OVERHEAD);
}

//Fills an allocation request of size (param) bytes
//and returns a pointer to the data portion of the block
//used to satisfy the request
void* my_alloc(int size)
{
	//First, the data size must be a multiple of (void*) size

	//Take the ceiling of the data size / (void*) size
	//to know which multiple of (void*) to use
	double dblSizeAsMultiple = ceil((double)size / (double)SIZE_OF_VOID_PTR);

	//Calculate the number of bytes to allocate for
	//the requested size and cast to integer
	int sizeAsMultiple = (int)(dblSizeAsMultiple * SIZE_OF_VOID_PTR);


	//Iterate through free list
	//First initialize pointers
	Block *currBlock = free_head;
	Block *prevBlock = 0;

	while (currBlock)
	{
		//If this block fits the size we want to allocate
		//(Uses the first fit heuristic)
		if (currBlock->block_size >= sizeAsMultiple)
		{

			//See if the excess space in the data portion is sufficient to fit another block
			// excess space = size of free block - size of space to alloc	
			int excessSpace = currBlock->block_size - sizeAsMultiple;

			//if splittable
			if (excessSpace >= (SIZE_OF_OVERHEAD + SIZE_OF_VOID_PTR))
			{
					//Split the data portion of the block we found
					//into the sizeAsMultiple and left over data	
					currBlock->block_size = sizeAsMultiple;

					//Initialize new block using leftover data
					//Cast to char to do arithmetic
					Block *new_split_block = (Block *)((char*)currBlock + SIZE_OF_OVERHEAD + sizeAsMultiple);
					new_split_block->block_size = excessSpace;

					//Initialize data pointer
					new_split_block->data = ((char*)new_split_block + SIZE_OF_OVERHEAD);

					//Link the new (split) block into the free list
					//by making the new block the head of the free list 
					//and linking its next pointer to what used to be 
					//the head of the list.
					if (currBlock == free_head)
					{
						//new_split_block->next_block = currBlock->next_block;
						//currBlock->next_block = new_split_block;
						free_head = new_split_block;
					}
					else
					{
						new_split_block->next_block = currBlock->next_block;
						prevBlock->next_block = new_split_block;
					}
				
			}
			else
			{
					//Unlink allocated block, currBlock, from free list
					if (currBlock == free_head)
					{
						free_head = currBlock->next_block;
					}
					else
					{
						prevBlock->next_block = currBlock->next_block;
					}

					currBlock->next_block = 0;
			}

			//Initialize data pointer
			currBlock->data = ((char*)currBlock + SIZE_OF_OVERHEAD);

			//Return a pointer to the data portion of the block
			//used to satisfy the allocation request
			return currBlock->data;
		}
		else
		{
			//Keep searching through list
			prevBlock = currBlock;
			currBlock = currBlock->next_block;
		}

	}

	//If no blocks can be found, returns 0 (null)
	return 0;
}


//Deallocates a value that was allocated on the heap
void my_free(void *data)
{
	//Find block with this data pointer

	//First calculate it's offset from the beginning of its block struct
	Block *currBlock = (Block *)((char*)data - SIZE_OF_OVERHEAD);

	//Point its next pointer to the head's next block
	currBlock->next_block = free_head;

	//Point the current head of the free list to the
	//block that's being freed
	free_head = currBlock;

}
