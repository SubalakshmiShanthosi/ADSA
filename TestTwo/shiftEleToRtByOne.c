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

  for(int i=0;i<size;i++)
    printf("%d ",array[i]);
}

int main()
{
  int array[MAX_SIZE],size;
  printf("Enter the number of elements in sequence\n");
  scanf("%d",&size);
  printf("\nEnter the elements in sequence:\n");
  for(int i=0;i<size;i++)
    scanf("%d",&array[i]);
  printf("\nThe altered sequence after shifting elements one position to right is\n");
  shiftEleToRtByOne(array,size);
  return 0;
}
