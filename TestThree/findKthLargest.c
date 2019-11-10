#include<stdio.h>
#define MAX_SIZE 20

/* findKthLargestElement - gets two sorted arrays in ascending order returns kth largest element after merging the two
 */

int findKthLargestElement(int inputOne[],int size1,int inputTwo[],int size2,int k)
{
  int i=size1-1,j=size2-1,kthLargest=0;
  while(i>=0 && j>=0 && k>0)
    {
      if(inputOne[i] == inputTwo[j] && inputOne[i-1] > inputTwo[j-1])
	{
	  kthLargest=inputTwo[j];
	  i=i-1;
	}
     
      else if(inputOne[i]>inputTwo[j])
	{
	  kthLargest=inputOne[i];
	  i=i-1;
	  k=k-1;
	}
      else if(inputTwo[j]>inputOne[i])
	{
	  kthLargest=inputTwo[j];
	  j=j-1;
	  k=k-1;
	}
	
    }
  return kthLargest;
}

int main()
{
  int inputOne[MAX_SIZE],size1,inputTwo[MAX_SIZE],size2,k;
  printf("\nEnter the number of elements in the sequence one:");
  scanf("%d",&size1);
  printf("\nEnter the elements in sequence one in ascending order:\n");
  for(int i=0;i<size1;i++)
    scanf("%d",&inputOne[i]);
  printf("\nEnter the number of elements in the sequence two:");
  scanf("%d",&size2);
  printf("\nEnter the elements in sequence two in ascending order:\n");
  for(int i=0;i<size2;i++)
    scanf("%d",&inputTwo[i]);
  printf("\n Enter k for which kth largest element is to be found after merging sequence one and two:");
  scanf("%d",&k);
  if(k>size1+size2)
    printf("\nNot possible to find %d'th largest element when combined sorted array consist of only %d elements",k,size1+size2); 
  int kthLargest=findKthLargestElement(inputOne,size1,inputTwo,size2,k);
  printf("\nkthLargest element is:%d",kthLargest);
  printf("\n");
  return 0;
}
