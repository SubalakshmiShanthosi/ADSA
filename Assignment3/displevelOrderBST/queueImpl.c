#include<stdio.h>
#include "queueImpl.h"
#include<stdlib.h>
#include<limits.h>

struct node** createQueue(int *front,int *rear,int capacity)
{
  struct node** queue=(struct node**)malloc(sizeof(struct node*)*capacity);
  *front=0;
  *rear=0;
  return queue;
}


int isEmpty(struct Queue* queue)
{
  return queue->size==0?1:0;
}

int isFull(struct Queue* queue)
{
  return queue->rear==queue->front+1?1:0;
}

void enqueue(struct node** queue,int *rear,struct node *new_node)
{
  queue[*rear]=new_node;
  (*rear)++; 
}

struct node* dequeue(struct node** queue,int *front)
{
  (*front)++;
  return queue[*front-1];
}



/*
int main()
{
  int numEle;
  printf("\nEnter the number of elements with which queue is to be constructed");
  scanf("%d",&numEle);
  struct Queue* queue=createQueue(numEle);
  printf("\nEnter elements of queue:\n");
  for(int i=0;i<numEle;i++)
    {
      int queueEle;
      scanf("%d",&queueEle);
      enqueue(queue,queueEle);
    }
  printf("\nDequeued elements in order:");
  for(int i=0;i<numEle;i++)
    printf(" %d ",dequeue(queue));
  printf("\n");
  return 0;
}
*/
