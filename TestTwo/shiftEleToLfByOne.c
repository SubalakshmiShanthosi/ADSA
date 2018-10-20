#include<stdio.h>
#include<math.h>
#define MAX_SIZE 30

/*Given an array of integers and size,shift elements one position to left i.e)  *array[i]=array[i-1] for all i in 0<i<size 
 */
void shiftEleToLfByOne(int array[],int size)
{
  int temp[size];
  for(int i=size-1;i>=0;i--)
    temp[(i-1)%size]=array[i];
  temp[size-1]=array[0];
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
  printf("\nThe altered sequence after shifting elements one position to left is\n");
  shiftEleToLfByOne(array,size);
  return 0;
}
