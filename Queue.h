// FILE:  Queue.h
// WRITTEN BY: Hugh C. Lauer, Worcester Polytechnic Institute, lauer@cs.wpi.edu, April 17, 2011

// An interface to a simple queue implementation.
//		This is intended to be implemented either by a linked list
//		or by a fixed-size array. The client does not know which

#ifndef QUEUE_H
#define QUEUE_H

#include "Simulation.h"

#if defined QUEUE_ELEMENT

//	The actual interface definition for the queue begins here. It uses QUEUE_ELEMENT
//		as a type

void initQueue();       // initializes the queue

int queueEmpty(void);	//	returns TRUE if the queue is empty, FALSE if not

int enqueue(QUEUE_ELEMENT e);	// Adds a copy of the argument to the tail of the queue
								// Returns TRUE if successful, FALSE if not

int dequeue(QUEUE_ELEMENT *e);	// Removes the first element from the queue and stores it
								//	 into the location pointed to by e
								// Returns TRUE if successful, FALSE if not

int maxQueueLength(void);		// Returns the maximum number of elements that have been
								//	 stored in the queue at one time

int currentQueueLength(void);	// Returns the number of elements currently in the queue

//	End of interface definition

#else

#error	"A type for the queue element must have been defined."

#endif

#endif
