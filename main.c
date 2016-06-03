// FILE:  main.c
// WRITTEN BY: Hugh C. Lauer, Worcester Polytechnic Institute, lauer@cs.wpi.edu, April 17, 2011

// A demonstration project to simulate a queue in, say, a supermarket or a bank.

#include <stdio.h>
#include <stdlib.h>			// Provides atol, rand, etc.
#include <ctype.h>			// Provides tolower, etc.
#include "Simulation.h"		// accesses the Simulation function
#include "Statistics.h"		// Gathers and prints statistics about the simulation

int main(int argc, char **argv) 
{
	int verbose = 0;			//	controls printing out gory detail
	int seed = 1;				//	seed for random number generator
	double simTime = 720;		//	number of minutes to simulate
	double meanInterval = 2.0;	//	interval between arrivals
	double meanServiceTime = 2;	//	mean time to serve one customer
    int i;     // for loop control variable

	for (i = 1; i < argc; i++) {
		switch (i) {
			case 1:	simTime = atof(argv[1]);
					break;
			case 2: meanInterval = atof(argv[2]);
					break;
			case 3:	meanServiceTime = atof(argv[3]);
					break;
			case 4:	seed = atoi(argv[4]);
					srand(seed);
					break;
			case 5:	if (tolower(*argv[5]) == 'v')
						verbose = 1;
					break;
			default: printf("Usage: PA5 simTime interval serviceTime seed verbose\n");
					 printf("Using defaults\n");
					 break;
		}	//	switch (i)


	}	//	for (i ...

	Simulation(simTime, meanInterval, meanServiceTime, verbose);

	PrintStatistics(simTime);

	printf("Type any key to exit.\n");
	getchar();

    return 0;
}	// main(int argc, char **argv)

