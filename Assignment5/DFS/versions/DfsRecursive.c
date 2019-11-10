#include<stdio.h>
#include "constructAdjMatForG.h"

struct graph
{
       int adjMat[MAX_NODES][MAX_NODES];
       int n;
}G;

void dfsTraversal(int adjMat[][MAX_NODES],int noOfNodes,int visited[],int start)
{
  visited[start]=1;
  printf(" %d ",start);
  for(int i=1;i<=noOfNodes;i++)
    if(!visited[i]&& adjMat[start][i])
      dfsTraversal(adjMat,noOfNodes,visited,i);
      
}



int main()
{
  int i,start,componentNo=0;
  int visited[MAX_NODES];
  printf("\nEnter the number of nodes in graph G\n");
  scanf("%d",&G.n);
  printf("\nGetting vertex pair num-num(1-to max 15 nodes)for adding edge\nEnter 0-0 to quit\n");
  addEdge(G.adjMat,G.n);
  printf("\n The adjacency matrix for the entered graph is\n");
  printAdjacencyMatrix(G.adjMat,G.n);
  printf("\n Enter the starting vertex for DFS traversal:");
  scanf("%d",&start);
  for(int i=1;i<=G.n;i++)
    visited[i]=0;
  printf("\n DFS traversal for connected components:\n");
  printf("\n---------CONNECTED COMPONENT %d------------\n",++componentNo);
  dfsTraversal(G.adjMat,G.n,visited,start);
  for(int i=1;i<=G.n;i++)
    {
     
      if(!visited[i])
	{
	  printf("\n -----------CONNECTED COMPONENT %d-----\n",++componentNo); 
	  dfsTraversal(G.adjMat,G.n,visited,i);
	}
    }
  printf("\n\n");
  return 0;
}
