// FILE:  simulation.h
// WRITTEN BY: Hugh C. Lauer, Worcester Polytechnic Institute, lauer@cs.wpi.edu, April 17, 2011

// Gather statistics about the simulator of a queue in a supermarket or bank

#include "Simulation.h"

#ifndef STATISTICS_H
#define STATISTICS_H

void GatherStatistics(const Customer c, const int verbose);		// accumulates statistical information from one customer

void PrintStatistics(const double simTime);

#endif
