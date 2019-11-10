#include<stdio.h>
#include "queueImpl.h"
#include<stdlib.h>
#include<limits.h>
struct Queue
{
  int front;
  int rear;
  int capacity;
  int size;
  int* array;
};

struct Queue* createQueue(int capacity)
{
  struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
  queue->front=-1;
  queue->capacity=capacity;
  queue->rear=-1;
  queue->size=0;
  queue->array=(int*)malloc(sizeof(int)*queue->capacity);
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

void enqueue(struct Queue* queue,int item)
{
  if(isFull(queue))
    {
      printf("\nQueue is full:");
      return;
    }
  if(queue->rear == -1)
      queue->front=0;
  queue->rear=queue->rear+1;
  queue->array[queue->rear]=item;
  queue->size = queue->size + 1; 
}

int dequeue(struct Queue* queue)
{
  if(isEmpty(queue))
    {
      printf("Queue is empty!\n");
      return INT_MIN;
    }
  int frontEle=queue->array[queue->front];
  queue->front=queue->front+1;
  queue->size=queue->size-1;
  return frontEle;
}

int front(struct Queue* queue)
{
  if(isEmpty(queue))
    {
      printf("Queue is empty!\n");
      return INT_MIN;
    }
  return queue->array[queue->front];
}


int rear(struct Queue* queue) 
 {
   if(isEmpty(queue))
    {
      printf("Queue is empty!\n");
      return INT_MIN;
    }
  return queue->array[queue->rear];
   
 }

void display(struct Queue *queue)
{
	int temp=queue->front,i;
	if(!isEmpty(queue))
	{
		printf("Contents of queue are:\n");
		for(i=0;i<queue->size;i++)
		{
			printf("%d\t",queue->array[temp++]);
		}
	}
	else
		printf("Queue is empty!!");
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
