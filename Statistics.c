// FILE:  Statistics.c
// WRITTEN BY: Hugh C. Lauer, Worcester Polytechnic Institute, lauer@cs.wpi.edu, April 17, 2011

// Statistics gathering module for simulation of a queue in a bank or supermarket.

#include <stdio.h>
#include <math.h>
#include "Statistics.h"

static double waitSum = 0;
static double waitSumSquared = 0;
static double maxWait = 0;

static int count = 0;

void GatherStatistics(const Customer c, const int verbose) {
	double waitTime = c.startTime + c.serviceTime - c.arrivalTime;
	double waitSquared = waitTime * waitTime;

	count++;

	if (waitTime > maxWait)
		maxWait = waitTime;

	waitSum += waitTime;
	waitSumSquared += waitSquared;

}	// void GatherStatistics(Customer)


void PrintStatistics(const double simTime) {

	double meanWait = count ? waitSum / count : 0;
	double stdDev = count ? sqrt(waitSumSquared / count - meanWait * meanWait) : 0;

	printf("Total simulation time is %0.2f units of time.\n", simTime);
	printf("Number of customers served = %d.\n", count);
	if (count == 0)
		return;
	printf("Average customer wait time (arrival to completion of service) = %0.2f units.\n",
		meanWait);
	printf("Standard deviation of customer wait times = %0.2f.\n\n", stdDev);


}	// void PrintStatistics(void)
