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
}

/*Call shiftEleToLfByOne x times
 */
void shiftEleToLfByXPos(int array[],int size,int x)
{
  for(int i=1;i<=x;i++)
    shiftEleToLfByOne(array,size);
}

int main()
{
  int array[MAX_SIZE],size,x;
  printf("Enter the number of elements in sequence\n");
  scanf("%d",&size);
  printf("\nEnter the elements in sequence:\n");
  for(int i=0;i<size;i++)
    scanf("%d",&array[i]);
  printf("\nEnter the number of positions to which the array elements are to be shifted to left:");
  scanf("%d",&x);
  printf("\nThe altered sequence after shifting elements x positions to left is\n");
  shiftEleToLfByXPos(array,size,x);
  for(int i=0;i<size;i++)
    printf("%d ",array[i]);
  return 0;
}
