#include<stdio.h>
#define MAX_SIZE 30
using namespace std;

/* print contents of array within given indices
 */
void print(int input[],int start,int end)
  {
    for(int i=start;i<end;i++)
      printf("%d ",input[i]);
   
  }
/* print contents post every merge method call
 */
void printIntermediateIter(int input[],int start,int end,int size)
{
  //print(input,start,end);
  for(int i=start;i<end;i++)
    printf("%2d ",input[i]);
  print(input,end,size);
  printf("\n");
	 
}
/*merge algorithm -> using a temporary array to place the subsequences minimum
 *of input[0..middle] and input[middle+1 ...end] post comparision in appropriate * position. temp[] array contents are copied back to input[] 
 */
void merge(int input[],int start,int middle,int end,int size)
{
  int i=start,j=middle+1,k;
  int temp[size];
  printf("\nmerge(array,%d,%d,%d)\n",start,middle,end);
  for(k=start;k<=end;k++)
    temp[k]=input[k];
  for(k=start;k<=end;k++)
    {
      if(i>middle)
	input[k]=temp[j++];
      else if(j>end)
	input[k]=temp[i++];
      else if(temp[i]<temp[j])
	input[k]=temp[i++];
      else
	input[k]=temp[j++];
    }
  
  printIntermediateIter(input,start,end,size);
}

/* mergeSort algorithm -> partition the n-element sequence to be sorted into 
 *two subsequences of n/2 elements each and sort the two subsequence recursively
 *using mergesort.
 *
 */

void mergeSort(int input[],int start,int end,int size)
{
   if(end<=start) 
     {
       return;
     }
      int middle=start+(end-start)/2;
      mergeSort(input,start,middle,size);
      mergeSort(input,middle+1,end,size);
      merge(input,start,middle,end,size);
}

int main()
{
  int input[MAX_SIZE],size;
  printf("\nEnter the number of elements in sequence\n");
  scanf("%d",&size);
  printf("Enter the elements in sequence:\n");
  for(int i=0;i<size;i++)
    scanf("%d",&input[i]);
  mergeSort(input,0,size-1,size);
  printf("\nElements in sorted sequence is:\n");
  for(int i=0;i<size;i++)
    printf("%d  ",input[i]);
  printf("\n");
  return 0;
}
