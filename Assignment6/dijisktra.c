
//dijkstra's algorithm
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define INFINITY 32000
struct node1
{      int adj,distance;
       struct node1* next;
};
typedef struct node1* list;
struct node
{      char name[10];
       int dist,known,path;
       list l;
};
int n;
typedef struct node* Table;
int find(list l,int k)
{   
    list temp=l->next;
    while(temp)
        if(temp->adj==k)
            return temp->distance;
        else
            temp=temp->next;
    return INFINITY;
} 
Table create(Table t)
{      
    int i,ch;char str[10];list temp;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    t=(Table)malloc(sizeof(struct node)*n);
    for(i=0;i<n;i++)
    {
        printf("Enter the name of point %d:",i+1);
        scanf("%s",t[i].name);
        t[i].l=(list)malloc(sizeof(struct node1));
        t[i].l->next=NULL;
        t[i].dist=INFINITY;
        t[i].known=0;
        t[i].path=-1;
    }
    for(i=0,ch=1;i<n;i++,ch=1)
        while(ch)
        {
            printf("\nDo you want to continue?(0 to exit):");
            scanf("%d",&ch);
            if(ch)
            {
                printf("\nEnter the point which %s points to:",t[i].name);
                scanf("%s",str);
                for(ch=0;ch<n;ch++)
                    if(stricmp(t[ch].name,str)==0&&ch!=i)
                    { 
                        if(find(t[ch].l,i)==INFINITY)
                        {
                            temp=(list)malloc(sizeof(struct node1));
                            printf("\nEnter the distance from %s to %s:",t[i].name,t[ch].name);
                            scanf("%d",&(temp->distance));
                            temp->adj=ch;
                            temp->next=t[i].l->next;
                            t[i].l->next=temp;
                            break;
                        }
                        else
                        {
                            printf("\nSorry!%s already points to %s",t[ch].name,t[i].name);
                        }
                    }
                if(ch==n)
                    printf("\nInvalid point!");
                ch=1;
            }
        }
    return t;
}
int retmin(Table t)
{   
    int min=INFINITY,pos=-1,i;
    for(i=0;i<n;i++)
        if(t[i].known==0&&t[i].dist<min)
        {
            min=t[i].dist;
            pos=i;
        }
    return pos;
}
void disp(Table t)
{    int i;list temp;
     printf("\nPoint\tKnown\tDistance\tPath");
     for(i=0;i<n;i++)
     {   printf("\n%s\t",t[i].name);
         printf("%d\t%d\t%s",t[i].known,t[i].dist,t[t[i].path].name);
     }
}
void printpath(int v,Table t)
{    
    while(t[v].path!=-1)
    {
        printf("%s<---",t[v].name);
        v=t[v].path;
    }
    printf("%s",t[v].name);
} 
void dijkstra(Table t)
{    
    int i,start,cur,d;char str[10];list temp;
    printf("\nEnter the vertex for start:");
    scanf("%s",str);
    for(i=0;i<n;i++)
        if(stricmp(t[i].name,str)==0)
        {
            start=i;break;
        }
    if(i==n)
    {
        printf("\nSorry!Vertex not found!");
        return;
    }
    t[start].dist=0;
    cur=start;
    while(cur!=-1)
    { 
        t[cur].known=1;
        temp=t[cur].l->next;
        while(temp)
        {
            d=find(t[cur].l,temp->adj);
            if(!t[temp->adj].known)
                if(t[cur].dist+ d <t[temp->adj].dist)
                {  
                    t[temp->adj].dist=t[cur].dist+d;
                    t[temp->adj].path=cur;
                }
            temp=temp->next;
        }
        disp(t);
        cur=retmin(t);
    }
    printf("\nMinimum Path from %s:",t[start].name);
    for(i=0;i<n;i++)
        if(i!=start)
        {
            printf("\nTo %s:",t[i].name);
            printpath(i,t);
        }
}  
void freetable(Table t)
{    int i;list temp;
     for(i=0;i<n;i++)
     { 
       temp=t[i].l;
       while(temp)
       {
        t[i].l=t[i].l->next;
        free(temp);
        temp=t[i].l;
       }
     }
     free(t);
}
int main()
{   Table t;
    t=create(t);
    dijkstra(t);
    freetable(t);
    getch();
}
