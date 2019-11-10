#include<stdio.h>
#include "constructAdjMatForG.h"
#include "stackImpl.h"

struct graph
{
       int adjMat[MAX_NODES][MAX_NODES];
       int n;
}G;



void dfs(int start,int visited[])
{
     int i,temp;   
     visited[start]=1;
     initstack(G.n);
     push(start);
     while(isempty()==0)
     { 
          temp=pop();
          printf(" %d ", temp);
          for(i=1;i<=G.n;i++)
             if(G.adjMat[temp][i] && visited[i]==0)
              {
                   visited[i]=1;
                   push(i);
              }
     }
}

int main()
{
    int i;
    int visited[MAX_NODES];
    int componentNo=0;
    char inputNodeOne,inputNodeTwo;
    printf("\nEnter the number of nodes in graph G\n");
    scanf("%d",&G.n);
    printf("\nGetting vertex pair num-num(1-to max 15 nodes)for adding edge\nEnter 0-0 to quit\n");
    addEdge(G.adjMat,G.n);
    printf("\n The adjacency matrix for the entered graph is\n");
    printAdjacencyMatrix(G.adjMat,G.n);
    for(i=1;i<=G.n;i++)
      visited[i]=0;
    printf("\n---------DFS traversal for the graph with connected components using stack------\n");
    for(i=1;i<=G.n;i++)
     {
        if(!visited[i])
             {
             printf("\nConnected Component %d :\n",++componentNo);
             dfs(i,visited);
     	     }
     }
    printf("\n");
    return 0;
}
