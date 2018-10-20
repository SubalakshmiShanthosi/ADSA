#include<stdio.h>
#define MAX_SIZE 30

/*Given an array of integers and size,shift elements one position to right i.e)  *array[i+1]=array[i] for all i in 0<i<size 
 */
void shiftEleToRtByOne(int array[],int size)
{
  int temp[size];
  for(int i=0;i<size;i++)
    temp[(i+1)%size]=array[i];

  for(int i=0;i<size;i++)
    array[i]=temp[i];
}

/* call shiftEleToRtByOne x times 
 */
void shiftEleToRtByXPos(int array[],int size,int x)
{
  for(int i=1;i<=x;i++)   
    shiftEleToRtByOne(array,size);
}

int main()
{
  int array[MAX_SIZE],size,x;
  printf("Enter the number of elements in sequence\n");
  scanf("%d",&size);
  printf("\nEnter the elements in sequence:\n");
  for(int i=0;i<size;i++)
    scanf("%d",&array[i]);
  printf("\nEnter the value of x:");
  scanf("%d",&x);
  printf("\nThe altered sequence after shifting each element x position to the right is\n");
  shiftEleToRtByXPos(array,size,x);
  for(int i=0;i<size;i++)
    printf("%d ",array[i]);
  return 0;
}
