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


void printPath(int predecessor[],int oneVertex,int anotherVertex)
{
  if(anotherVertex==oneVertex)
    printf("\n Path: %d ",oneVertex);
  else if(predecessor[anotherVertex]<=0)
    {
      printf("\n No path between %d and %d\n",oneVertex,anotherVertex);
      return;
    }
  else 
   {
      printPath(predecessor,oneVertex,predecessor[anotherVertex]);
      printf("  %d",anotherVertex);
   }
  return;
}

void findStAndEndIndArr(int predecessor[],int noOfNodes,int start,int *endIndOfComp)
{
    int subSeqLength = 1;
    int longest = 1;
    int indexStart = 0;
    int indexEnd = 0;

    for (int i=start; i <=noOfNodes-1; i++)
    {
        if (predecessor[i] !=0 && predecessor[i + 1]==0)//We need to nextIndex element is zero
        {
            subSeqLength++;//if it is we increment
            if (subSeqLength > longest)//we assign the longest and new bounds
            {
                longest = subSeqLength;
                *endIndOfComp = i + 2 - subSeqLength;//make sure the index start is correct
                indexEnd = i + 2;
            }

        } 
        else
            subSeqLength = 1;//else re-initiate the straight length
    }
    if(subSeqLength==1 && *endIndOfComp==0)
           *endIndOfComp=start+1;
}


void displayPathAndDistance(int visited[],int distance[],int predecessor[],int startIndex,int endIndex,int noOfNodes)
{
  if(endIndex>G.n)
    endIndex=G.n;
  printPath(predecessor,startIndex,endIndex);
  printf("\n\n");
  printf("\n\nDistance to reach %d from source:%d is %d",endIndex,startIndex,distance[endIndex]);
}

void printPathAndDisArr(int distance[],int path[],int noOfNodes)
{
  printf("\n Predecessor matrix:\n");
  for(int i=1;i<=noOfNodes;i++)
    printf("%d ",path[i]);
  printf("\n distance matrix:\n");
  for(int i=1;i<=noOfNodes;i++)
    printf(" %d ",distance[i]);  
  
}

void bfs(int start,int visited[],int distance[],int predecessor[])
{
     int i,temp,endIndex;   
     struct queue* queue=initQueue(G.n);
     enqueue(queue,start);
     visited[start]=1;
     while(isempty(queue)==0)
     { 
          temp=dequeue(queue);
          printf("\n visiting %d\n",temp);
          for(i=1;i<=G.n;i++)
	    {
             if(G.adjMat[temp][i] && visited[i]==0)
              {
		visited[i]=1;
		distance[i]=distance[temp]+1;
		printf("\ndistance between (%d,%d) is %d",temp,i,distance[i]);
		predecessor[i]=temp;
		if(i==G.n)
		  break;
		enqueue(queue,i);
              }
	    }
	  
     }
     //printPathAndDisArr(distance,predecessor,G.n);
}



int main()
{
  int i,start;
    int visited[MAX_NODES],distance[MAX_NODES],predecessor[MAX_NODES],componentNo=0;
    char inputNodeOne,inputNodeTwo;
    printf("\nEnter the number of nodes in graph G\n");
    scanf("%d",&G.n);
    printf("\nGetting vertex pair num-num(1-to max 15 nodes)for adding edge\nEnter 0-0 to quit\n");
    addEdge(G.adjMat,G.n);
    printf("\n The adjacency matrix for the entered graph is\n");
    printAdjacencyMatrix(G.adjMat,G.n);
    for(i=1;i<=G.n;i++)
      visited[i]=0;
    for(i=1;i<=G.n;i++)
      distance[i]=0;
    for(i=1;i<=G.n;i++)
      predecessor[i]=0;
    printf("\n Enter the source vertex:\n");
    scanf("%d",&start);
    if(start >G.n|| start<=0)
      printf("\n invalid start vertex!\n");
    printf("\n---------Shortest predecessor using BFS traversal for the connected components in the graph with start vertex=%d ------\n",start);
    printf("\nConnected Component %d :\n",++componentNo);
    int endIndOfComp=0,startIndex=start;
    bfs(start,visited,distance,predecessor);
    printf("\n Path from source to destination for this connected component:\n");
    findStAndEndIndArr(predecessor,G.n,start,&endIndOfComp);
    printf("\n %d,%d\n",startIndex,endIndOfComp);
    printf("\n\n----------PATH AND DISTANCE FOR CONNECTED COMPONENTS----");
    printf("\n\n----------CONNECTED COMPONENT %d --------------",componentNo);
    findStAndEndIndArr(predecessor,G.n,start,&endIndOfComp);
    displayPathAndDistance(visited,distance,predecessor,start,endIndOfComp,G.n);
    printf("\n\n-------------------------------------------------------\n");
    for(i=endIndOfComp;i<=G.n;i++)
     {
      //Calling BFS for nodes which arent reachable from start with direct edge 
      if(!visited[i])
             {
             printf("\n\n----------CONNECTED COMPONENT %d --------------",++componentNo);
	     bfs(i,visited,distance,predecessor);
	     endIndOfComp=0;
	     findStAndEndIndArr(predecessor,G.n,i,&endIndOfComp);
	     displayPathAndDistance(visited,distance,predecessor,i,endIndOfComp,G.n);  
	     printf("\n\n");
     	     }
     }
    printf("\n");
    return 0;
}
