# Make file for Programming Assignment 5
# WRITTEN BY: Hugh C. Lauer
# MODIFIED BY: Glynis Hamel, November 19, 2012
#
# This makefile is used as follows to regenerate files for two versions of the customer
#	service simulation program. One version uses a queue implementation based on a
#	linked list, and the other uses an implementation based on an array.
#
# There are two separate primary targets -- PA5-list and PA5-array
# Correspondingly, there are two C implementations of the queue interface which is defined by
#	Queue.h, namely Queue-list.c and Queue-array.c
# All of the rest of the files are shared between the two implementations
#
#	"make all" generates both targets.

CFLAGS = -g -Wall

all: PA5-list PA5-array

PA5-list: Queue-list.o Simulation.o Statistics.o main.o
	gcc $(CFLAGS) -lm Queue-list.o Simulation.o Statistics.o main.o -o PA5-list 

PA5-array: Queue-array.o Simulation.o Statistics.o main.o
	gcc $(CFLAGS) -lm Queue-array.o Simulation.o Statistics.o main.o -o PA5-array 

*.o: *.h *.c
	gcc -c $(CFLAGS) *.c

clean:
	rm -f *.o PA5-list PA5-array
	echo "Make clean completed."




# DO NOT DELETE
Queue-array.o: Queue.h Simulation.h
Queue-list.o: Queue.h Simulation.h
Simulation.o: Simulation.h Queue.h Statistics.h
Statistics.o: Statistics.h Simulation.h
main.o: main.c Simulation.h Statistics.h
