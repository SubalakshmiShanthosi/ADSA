#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 30
#define ANSI_COLOUR_BLUE "\x1b[34m"
#define ANSI_COLOUR_RESET   "\x1b[0m"


void printIntermediate(int heap[],int pos1,int size)
{
  printIntermediateIter(heap,pos1,-1,size);
}



/* print the swapped contents for reconstruction using heapify method which is ccalled recursively as highlighted terms.
 * ANSI_COLOUR_BLUE - \x1b[34m ANSI_COLOUR_RESET - \x1b[0m
 */
void printIntermediateIter(int heap[],int pos1,int pos2,int size)
{
  
  for(int i=0;i<size;i++)
    {
      if(i==pos1 || i==pos2)
      printf(ANSI_COLOUR_BLUE "%d " ANSI_COLOUR_RESET,heap[i]);
      else
      printf("%d ",heap[i]);
    }
   printf("\n");	 
}



int leftChild(int position)
{
  return 2*position;
}

int rightChild(int position)
{
  return 2*position+1;
}

int parent(int position)
{
  return position/2;
}



/*print the contents of the minHeap heap[0...count-1] which is constructed post constructMinHeap call. 
 */
void printMinHeap(int heap[],int count)
{
  for(int i=1;i<=count;i++)
    printf(" %d ",heap[i]);
}

void exchange(int input[],int positionOne,int positionTwo)
{
  int temp=input[positionOne];
  input[positionOne]=input[positionTwo];
  input[positionTwo]=input[positionOne];
}

/*isHeap is a function to check if heapOrder property is preserved for all the nodes
 */
bool isHeap(int heap[],  int count) 
{ 
    // Start from root and go till the last internal 
    // node 
    for (int i=1; i<=(count-2)/2; i++) 
    { 
        // If left child is greater, return false 
      if (heap[leftChild(i)] < heap[i]) 
	return false; 
      
        // If right child is greater, return false 
      if (rightChild(i) < count && heap[rightChild(i)] < heap[i]) 
	return false; 
    } 
    return true; 
} 

void heapifyDown(int heap[],int position,int count)
{
  
  int left=leftChild(position);
  int right=rightChild(position);
  int min=position;
  if(left<=count && heap[left] < heap[position])
    min=left;
  if(right<=count && heap[right] < heap[min])
    min=right;
  if(min!=position)
    {
      exchange(heap,position,min);
      printIntermediateIter(heap,position,min,count);
      heapifyDown(heap,min,count);
    }
}


void constructMinHeap(int heap[],int count)
{
  for(int i=count/2;i>=1;i--)
    {
      heapifyDown(heap,i,count);
    }
}

int findIndexInMinHeap(int heap[],int count,int key)
{
  for(int i=0;i<count;i++)
    if(heap[i]==key)
      return i;
  return -1;
}


void heapSort(int heap[],int size)
{
  for(int i=size;i<=2;i++)
    {
      exchange(&heap[1],&heap[i]);
      size=size-1;
    }
  heapifyDown(heap,1,size);
}


int main()
{
  int heap[MAX_SIZE],count;
 
  printf("\n1.Give the sequence of elements with which minheap is to be constructed");
  printf("\nEnter the number of elements in sequence");
  scanf("%d",&count);
  printf("\nEnter the elements in sequence with which minheap is to be constructed");
  for(int i=1;i<=count;i++)
    scanf("%d",&heap[i]);
  printf("\nConstructing minHeap from given sequence:\n");
  constructMinHeap(heap,count);
  printf("\nMin heap in level order format on heap[]:");
  printMinHeap(heap,count);
  printf("\nSorted using heapsort algorithm with the constructed minheap:\n");
  heapSort(heap,count);
  printHeap(heap,count);
  printf("\n");
  return 0;
}
