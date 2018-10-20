#include<stdio.h>
#define MAX_SIZE 30

void findSumEqualToX(int array[],int size,int x)
{
  int i=0,j=size-1;
  while(i<=j)
    {
      if(array[i]+array[j] == x)
	{
	  printf("%d , %d",array[i],array[j]);
	  break;
	}
      else if(array[i]+array[j] < x)
	i=i+1;
      else
	j=j-1;
    }
}

int main()
{
  int array[MAX_SIZE],size,x;
  printf("Enter the number of elements in sequence\n");
  scanf("%d",&size);
  printf("\nEnter the elements in sequence in sorted order:\n");
  for(int i=0;i<size;i++)
    scanf("%d",&array[i]);
  printf("\nEnter the value x: which is to be expressed as sum of two other integers from array[]\n");
  scanf("%d",&x);
  findSumEqualToX(array,size,x);
  printf("\n");
  return 0;
}
