#include<stdio.h>
#include"constructAdjMatForG.h"
void addEdge(int adjMax[][MAX_NODES],int noOfNodes);
void addEdge(int adjMat[][MAX_NODES],int noOfNodes)
{
  int source,dest;
   do {
      scanf("%d%*c%d",&source,&dest);
      if(source!=0 && dest!=0)
	{
	  adjMat[source][dest]=1;
	  adjMat[dest][source]=1;
	}
       }while(source!=0 && dest!=0);

  for(int i=1;i<=noOfNodes;i++)
    for(int j=1;j<=noOfNodes;j++)
      {
	if(adjMat[i][j]!=1 && i!=j)
	  adjMat[i][j]=0;
	if(i==j)
	  adjMat[i][j]=0;
      }
}
 

void printAdjacencyMatrix(int adjMat[][MAX_NODES],int noOfNodes)
{
   for(int i=1;i<=noOfNodes;i++)
   { 
    for(int j=1;j<=noOfNodes;j++)
      printf(" %d ",adjMat[i][j]);
    printf("\n");
   }
}
/*  
int main()
{
  int adjMat[MAX_NODES][MAX_NODES],noOfNodes;
  char inputNodeOne,inputNodeTwo;
  printf("\nEnter the number of nodes in graph G\n");
  scanf("%d",&noOfNodes);
  printf("\nGetting vertex pair num-num(1-to max 14 nodes)for adding edge\nEnter 0-0 to quit\n");
  addEdge(adjMat,noOfNodes);
  printf("\n The adjacency matrix for the entered graph is\n");
  printAdjacencyMatrix(adjMat,noOfNodes);
  return 0;
}
*/
