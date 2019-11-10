#include<stdio.h>
#include<stdlib.h>
#include"constructAdjMatForG.h"
#define INFINITY 999

struct queue     
{
   int rear,front;
   int *array;
   int capacity;
};
struct graph
{
       int adjMat[MAX_NODES][MAX_NODES];
       int n;
}G;

struct queue* initQueue(int cap)
{
struct queue* queue=(struct queue*)malloc(sizeof(struct queue));
queue->array=(int*)malloc(cap*sizeof(int));
queue->capacity=cap;
queue->rear=queue->front=-1;
return queue;
}

void enqueue(struct queue *q,int x)
{
   if(q->front==-1)
           q->front=q->rear=0;
   else
           ++(q->rear);
   q->array[q->rear]=x;
}

int isempty(struct queue *q)
{
    if(q->rear==q->front-1)
      return 1;
    return 0;
}

int dequeue(struct queue *q)
{ 
     if(isempty(q)==0) 
        { 
         q->front++;
         return q->array[q->front-1];
	}
}


void bfs(int start,int visited[])
{
     int i,temp;   
     visited[start]=1;
     struct queue* queue=initQueue(G.n);
     enqueue(queue,start);
     while(isempty(queue)==0)
     { 
          temp=dequeue(queue);
          printf(" %d ", temp);
          for(i=1;i<=G.n;i++)
             if(G.adjMat[temp][i] && visited[i]==0)
              {
                   visited[i]=1;
                   enqueue(queue,i);
              }
     }
}

int main()
{
    int i;
    int visited[MAX_NODES];
    char inputNodeOne,inputNodeTwo;
    printf("\nEnter the number of nodes in graph G\n");
    scanf("%d",&G.n);
    printf("\nGetting vertex pair num-num(1-to max 15 nodes)for adding edge\nEnter 0-0 to quit\n");
    addEdge(G.adjMat,G.n);
    printf("\n The adjacency matrix for the entered graph is\n");
    printAdjacencyMatrix(G.adjMat,G.n);
    for(i=1;i<=G.n;i++)
      visited[i]=0;
    printf("\n---------BFS traversal for the connected components of the graph------\n");
    bfs(1,visited);
    for(i=1;i<=G.n;i++)
     {
        if(!visited[i])
             bfs(i,visited);
     }
    printf("\n");
    return 0;
}
