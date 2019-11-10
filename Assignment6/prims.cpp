#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
#define TEMP 0
#define PERM 1
#define FALSE 0
#define TRUE 1
#define infinity 9999

struct vdata
{
	int index;
	int cost;
};

struct heap
{
	struct vdata *data;
	int size;
	int capacity;
}*H;

struct heap *createheap(int size)
{
	struct heap *H;
	H=(struct heap *)malloc(sizeof(struct heap));
	H->size=0;
	H->capacity=size;
	H->data=(struct vdata *)malloc(sizeof(struct vdata)*(size+1));
	H->data[0].cost=-99999;
	return H;
}

int mini(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

void insert(struct heap *H,int cost,int index)
{
	int i;
	for(i=H->size+1;H->data[i/2].cost>cost;i/=2)
	{
		H->data[i].cost=H->data[i/2].cost;
		H->data[i].index=H->data[i/2].index;
	}
	H->data[i].cost=cost;
	H->data[i].index=index;
	H->size++;
}

int deletemin(struct heap *H)
{
	int minindex=H->data[1].index;
	int i=1;
	int Child;
	struct vdata temp;
	temp.cost=H->data[H->size].cost;
	temp.index=H->data[H->size].index;
	if(H->size<=0)
		return -1;
    H->size--;
    for( i = 1; i * 2 <= H->size; i = Child )
    {
        /* Find smaller child */
        Child = i * 2;
        if( Child != H->size && H->data[ Child + 1 ].cost< H->data[ Child ].cost )
        Child++;
        /* Percolate one level */
        if( temp.cost> H->data[Child].cost )
        {
            H->data[ i ].cost = H->data[ Child ].cost;
            H->data[ i ].index = H->data[ Child ].index;
        }
        else
        break;
    }

	H->data[i].cost=temp.cost;
	H->data[i].index=temp.index;
	return minindex;
}

void create_graph();
void display();
int maketree( );
int all_perm( struct node state[ MAX ] );
struct node
{
    int predecessor;
    int dist; /*Distance from predecessor */
    int status;
};
 
struct edge
{
        int u;
        int v;
};
struct edge tree[ MAX ];//tree is an array of t edges
int adj[ MAX ][ MAX ];
int n;
int wt_tree, count;
int main()
{
    int i, j;
    int path[ MAX ];
    
 
    
 
    create_graph();
    printf( "Adjacency matrix is :\n" );
    display();         
    count = maketree();
 
    printf( "Weight of spanning tree is : %d\n", wt_tree );
    printf( "Edges to be included in spanning tree are : \n" );
 
    for ( i = 1;i <= count;i++ )
        {
            printf( "%d->", tree[ i ].u );
            printf( "%d\n", tree[ i ].v );
        }
    getch();
    return 0;
} /*End of main()*/
 
void create_graph()
{
    int i, max_edges, origin, destin, wt;
 
    printf( "Enter number of vertices : " );
    scanf( "%d", &n );
    max_edges=n*(n-1)/2;
 
    for ( i=1;i<=max_edges;i++ )
    {
            printf( "Enter edge %d(0 0 to quit) : ", i );
            scanf( "%d %d", &origin, &destin );
            if ((origin==0)&&(destin==0))
                break;
 
            printf( "Enter weight for this edge : " );
 
            scanf( "%d", &wt );
 
            if ( (origin > n) ||( destin > n )||( origin <= 0 )||( destin <= 0) )
            {
                    printf( "Invalid edge!\n" );
                    i--;
            }
            else
            {
                    adj[ origin ][ destin ] = wt;
                    adj[ destin ][ origin ] = wt;
            }
     }
     if(i<n-1)
     {
            printf( "Spanning tree is not possible\n" );
            exit( 1 );
     }
} 
 
void display()
{
    int i, j;
    for ( i = 1;i<=n;i++ )
    {
            for ( j = 1;j <= n;j++ )
                printf( "%3d", adj[ i ][ j ] );
 
            printf( "\n" );
     }
} 

                     
 
int maketree()
{
 
    struct node state[ MAX ];
    int i, k, min, count, current, newdist;
    int m;
    int u1, v1;
    wt_tree = 0;
    /*Make all nodes temporary*/
 
    for ( i = 1;i <= n;i++ )
    {
        state[ i ].predecessor = 0;
        state[ i ].dist = infinity;
        state[ i ].status = TEMP;
    }
 
    /*Make first node permanent*/
    state[ 1 ].predecessor = 0;
    state[ 1 ].dist = 0;
    state[ 1 ].status = PERM;
    /*Start from first node*/
    current = 1;
    count = 0; /*count represents number of nodes in tree */
    while ( all_perm( state ) != TRUE )  /*Loop till all the nodes become PERM*/
    {
             for (i=1;i<=n;i++)
             {
                    if (adj[current][i]>0&&state[i].status==TEMP)
                    {
                            if ( adj[current][i] < state[i].dist )
                            {
                                    state[i].predecessor = current;
                                    state[i].dist = adj[current][i];
                            }
                    }
             } 
             
            for ( i = 1;i <= n;i++ )
            {
                printf("\nstate[ %d ].predecessor:%d",i,state[ i ].predecessor);
                printf("\tstate[ %d ].dist:%d",i,state[ i ].dist);
                printf("\tstate[ %d ].status:%d",i,state[ i ].status);
            }printf("\n\n");
            /*Search for temporary node with minimum distance
            and make it current node*/
           /* min = infinity;
            for ( i = 1;i <= n;i++ )
            {
                    if ( state[ i ].status == TEMP && state[ i ].dist < min )
                    {
                            min = state[ i ].dist;
                            current = i;
                    }
            } */
            H=createheap(n);
            for(i=0;i<=n;i++)
            {
                 if ( state[ i ].status == TEMP )
                    insert(H,state[ i ].dist,i);
            }
            current=deletemin(H);
            state[ current ].status = PERM;
             /*Insert this edge(u1,v1) into the tree */
            u1 = state[ current ].predecessor;
            v1 = current;
            count++;
            tree[ count ].u = u1;
            tree[ count ].v = v1;
            /*Add wt on this edge to weight of tree */
            wt_tree = wt_tree + adj[ u1 ][ v1 ];
        } 
    return ( count );
} 
 
/*This function returns TRUE if all nodes are permanent*/
 
int all_perm( struct node state[ MAX ] )
{
    int i;
 
    for ( i = 1;i <= n;i++ )
        if ( state[ i ].status == TEMP )
            return FALSE;
 
    return TRUE;
} /*End of all_perm()*/
