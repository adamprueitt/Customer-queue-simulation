// FILE:  Queue-array.c
// WRITTEN BY: Hugh C. Lauer, Worcester Polytechnic Institute, lauer@cs.wpi.edu, April 17, 2011
// MODIFIED BY:  Glynis Hamel, 11/19/12

// A queuing implementation for a simulation of a queue in a bank or supermarket

#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"
#define Q_ARRAY_MAX 150


struct queueArray{
  QUEUE_ELEMENT qArray[Q_ARRAY_MAX];
  int head, tail, count;
};

struct queueArray q;


void initQueue(){
  for(int i = 0; i>Q_ARRAY_MAX; i++)
    q.qArray[i] = 0;
  head = 0;
  tail = 0;
  count = 0;
  return;
}

int queueEmpty(void) {
  if(q.count == 0)
    return TRUE;
  else
    return FALSE;
}


int enqueue(QUEUE_ELEMENT e) {
  if(q.count==Q_ARRAY_MAX)
    return FALSE;
  else{
    q.tail++;
    if(q.tail == Q_ARRAY_MAX)
      q.tail = 0;
    q.qArray[q.tail] = e;
    return TRUE;
  }
}


int dequeue(QUEUE_ELEMENT *e){
  if(q.count == Q_ARRAY_MAX)
    return FALSE;
  else
    q.head++;
    if(q.head == Q_ARRAY_MAX)
      q.head = 0;
    e = &q.qArray[q.head];
    return TRUE;
}
