// FILE:  Simulation.c
// WRITTEN BY: Hugh C. Lauer, Worcester Polytechnic Institute, lauer@cs.wpi.edu, April 17, 2011

// A demonstration project to simulate a queue in, say, a supermarket or a bank.


#include <stdio.h> 
#include <stdlib.h>		// Provides rand and srand
#include <assert.h>     // Provides assert

#include "Simulation.h"	// The header defining the Simulation module
#include "Queue.h"		// The header file defining the Queue interface
#include "Statistics.h"	// The header file defining the statistic gathering package

// The following function gets a new customer whose average arrival after the previous customer
//	 is given by the first argument and whose average service time is given by the second argument
Customer GetNextArrival(const double meanInterval, const double meanServiceTime,
			const int verbose);	
 

void Simulation(const double simTime, const double meanInterval, 
		const double meanServiceTime, const int verbose) {

	double currentTime = 0;				// The simulation clock!
	//	int serving = 0;					// TRUE if a customer is currently being served

        initQueue();

	while (currentTime < simTime || ! queueEmpty()) {

		Customer current, next;
		double finishTime;

		if (queueEmpty()) {
			current = GetNextArrival(meanInterval, meanServiceTime, verbose);
			if (current.arrivalTime >= simTime)
				break;		// We are done. The next arrival comes too late
			currentTime = current.startTime = current.arrivalTime;	// update the current
												// to the start of this arrival
		} else {
			dequeue(&current);
			if (current.arrivalTime > currentTime)
				currentTime = current.arrivalTime;
			current.startTime = currentTime;	// start now!
			
		}	//	if (queueEmpty() ... else ...

		finishTime = current.startTime + current.serviceTime;
		if (verbose)
			printf("Customer that arrived at %0.2f starting service at %0.2f.\n", 
				current.arrivalTime, current.startTime);
		
		//	Now allow more customers to arrive while the current one is being served
		do {
			next = GetNextArrival(meanInterval, meanServiceTime, verbose);
			if (next.arrivalTime < simTime)
				enqueue(next);
		} while (next.arrivalTime < finishTime && next.arrivalTime < simTime);
		
		//	Now we can step the clock ahead to the finish time of the current customer
		currentTime = finishTime;
		if (verbose)
			printf("Customer that started at %0.2f finished at %0.2f.\n", 
				current.startTime, finishTime);
		GatherStatistics(current, verbose);

	}	// while (currentTime < simTime ...)

}	// void Simulation(...)

Customer GetNextArrival(const double meanInterval, const double meanServiceTime, const int verbose) {
	Customer c;
	static double previousArrivalTime = 0;

	double thisInterval = (double) rand() / RAND_MAX * 2 * meanInterval;
	c.arrivalTime = previousArrivalTime + thisInterval;
	previousArrivalTime = c.arrivalTime;

	c.serviceTime = (double) rand() / RAND_MAX * 2 * meanServiceTime;
	c.startTime = 0;	//	a placeholder until this customer is actually served

	if (verbose)
		printf("New customer arrived at %0.2f, service time = %0.2f.\n", c.arrivalTime, c.serviceTime);
	
	return c;

}	// Customer GetNextArrival(...)
