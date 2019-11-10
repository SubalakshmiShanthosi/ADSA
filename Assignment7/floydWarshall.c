#include<stdio.h>
int a[10][10],n,e,v,i,j,k,p[10][10],d[10][10];
void directed(int n);
void Predecesor(int n);
void distance(int n);


void floydwarshall(int a[10][10],int n)
{
	
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			d[i][j]=a[i][j];
			
			p[i][j]=i;
		}
	}
	for(k=1;k<=n;k++)
	{	
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(d[i][j]==0)
				{
					p[i][j]=0;
				}
				
				if((d[i][k]+d[k][j])<d[i][j])
				{
					
					d[i][j]=d[i][k]+d[k][j];
					
					p[i][j]=k;
					
				}
			}
		}

	}
	printf("\nDistance matrix\n");
	distance(n);	
	printf("\nThe Predecesor matrix\n");
	Predecesor(n);	
}
void directed(int n)
{
	int v1,v2,w;
	 e = n*(n-1);	 
	for(i=1; i<=e; i++)
  		{
        		printf("Enter edge %d (v1,v2)( -1 -1 to quit ) : ",i);
        		scanf("%d %d",&v1,&v2);
			printf("\nEnter the weights");
			scanf("%d",&w);
 		        if((v1 == -1) && (v2== -1) && (w==0))
        		    break;
 		       
			else
     	                           a[v1][v2]=w;
	   	 }
	     
}
void distance(int n)
{

	for(i=1;i<=n;i++)
    	{
        	for(j=1;j<=n;j++)
		{
           	 	printf("%d\t",d[i][j]);
				
		}
        	printf("\n");
			
    	}
}
void Predecesor(int n)
{
	for(i=1;i<=n;i++)
    	{
        	for(j=1;j<=n;j++)
		{
           	 	printf("%d\t",p[i][j]);
				
		}
        	printf("\n");
			
    		}
}
void main()
{
	printf("\n\nFlord-warshall's");
	printf("\nEnter the no of edges:");
	scanf("%d",&e);
	printf("Enter the no of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		    a[i][j]=0;
	}	
	directed(n);
	printf("\nThe adjcent matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{ 
			   printf(" %d ",a[i][j]);
		}	
	        printf("\n");
	}
	floydwarshall(a,n);
}
