#include<stdio.h>
#include "constructAdjMatForG.h"
#include<stdbool.h>
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
    if(visited[i]==0 && adjMat[start][i])
      dfsTraversal(adjMat,noOfNodes,visited,i);
      
}

bool search(int adjMat[][MAX_NODES],int noOfNodes,int visited[], int current, int target)
{

    if (current==0|| target==0)
      return false;

    visited[current]=1;

    if (current == target)
      return true;

   for(int i=1;i<=noOfNodes;i++)
     {
       if(visited[i]==0 && adjMat[current][i] && search(adjMat,noOfNodes,visited,i,target))
       {
       return true;
       }
     }

   return false;    
}

int main()
{
  int i,start,end,componentNo=0;
  int visited[MAX_NODES];
  printf("\nEnter the number of nodes in graph G\n");
  scanf("%d",&G.n);
  printf("\nGetting vertex pair num-num(1-to max 15 nodes)for adding edge\nEnter 0-0 to quit\n");
  addEdge(G.adjMat,G.n);
  printf("\n The adjacency matrix for the entered graph is\n");
  printAdjacencyMatrix(G.adjMat,G.n);
  printf("\n Enter the starting vertex for DFS traversal:");
  scanf("%d",&start);
  printf("\n Enter the terminal vertex for DFS traversal:");
  scanf("%d",&end);
  for(int i=1;i<=G.n;i++)
    visited[i]=0;
  printf("\n DFS traversal to search if path exists between %d,%d:\n",start,end);
  //printf("\n---------CONNECTED COMPONENT %d------------\n",++componentNo);
  bool ans=search(G.adjMat,G.n,visited,start,end);
  printf("%s",ans?"true":"false");
  printf("\n\n");
  return 0;
}
