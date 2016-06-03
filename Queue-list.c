// FILE:  Queue-list.c
// WRITTEN BY: Hugh C. Lauer, Worcester Polytechnic Institute, lauer@cs.wpi.edu, April 17, 2011
// MODIFIED BY:  Glynis Hamel 11/1/9/12

// A queuing implementation for a simulation of a queue in a bank or supermarket

#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"



struct queueList{
  QUEUE_ELEMENT data;
  struct queueList *next;
};

struct queueList *head, *tail;



void initQueue(){
  head = NULL;
  tail = NULL;
  return;
}

int queueEmpty(void){
  if(head == NULL && tail == NULL)
    return TRUE;
  else
    return FALSE;
}

int enqueue(QUEUE_ELEMENT e){
  struct queueList *p;
  p = malloc(sizeof(struct queueList));
  if(p == NULL)
    return FALSE;
  else{
    p->data = e;
    p->next = NULL;
    if(queueEmpty(void) == TRUE){
      head = p;
      tail = p;
    }
    else{
      tail->next = p;
      tail = p;
    }
    return TRUE;
  }
}


int dequeue(QUEUE_ELEMENT *e){
  struct queueList *p = head;
  if(head == NULL)
    return FALSE;
  else{
    e = malloc(sizeof(QUEUE_ELEMENT));
    *e = head->data;
    head = head->next;
    free(*p);
    return TRUE;
}
