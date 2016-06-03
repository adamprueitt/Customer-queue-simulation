// FILE:  Simulation.h
// WRITTEN BY: Hugh C. Lauer, Worcester Polytechnic Institute, lauer@cs.wpi.edu, April 17, 2011

// A demonstration project to simulate a queue in, say, a supermarket or a bank.


#ifndef SIMULATION_H
#define SIMULATION_H

void Simulation(const double simTime, const double meanInterval,
		const double meanServiceTime, const int verbose);

struct customer {
	double arrivalTime;
	double startTime;
	double serviceTime;
};	//	struct customer

typedef struct customer Customer;

//	The following will be used by the implementation of the queue module
#define QUEUE_ELEMENT Customer

#endif
