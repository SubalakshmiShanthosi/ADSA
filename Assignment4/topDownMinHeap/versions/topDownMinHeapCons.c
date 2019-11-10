#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 30
#define ANSI_COLOUR_BLUE "\x1b[34m"
#define ANSI_COLOUR_RESET   "\x1b[0m"


/* print the swapped contents for reconstruction using heapify method which is ccalled recursively as highlighted terms.
 * ANSI_COLOUR_BLUE - \x1b[34m ANSI_COLOUR_RESET - \x1b[0m
 */
void printIntermediateIter(int heap[],int pos1,int pos2,int size)
{
  
  for(int i=1;i<=size;i++)
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


int getChoiceFromUser()
{
  int choice;
  printf("\n ----- BOTTOMUP MINHEAP OPERATIONS ---- \n");
  printf("\nEnter your choice (1-3, enter 3 to quit)");
  printf("\n 1.Give the sequence of elements with which minheap is to be constructed");
  printf("\n 2.Print the contents of minheap constructed");
  printf("\n 3. Exit\n");
  printf("\n ---------------------------");
  printf("\n Please Enter your choice:");
  scanf("%d",&choice);
  if (choice==3)
    exit(0);
  return choice;
}

/*print the contents of the minHeap heap[0...count-1] which is constructed post constructMinHeap call. 
 */
void printMinHeap(int heap[],int count)
{
  for(int i=1;i<=count;i++)
    printf(" %d ",heap[i]);
}

void exchange(int heap[],int positionOne,int positionTwo)
{
  int temp=heap[positionOne];
  heap[positionOne]=heap[positionTwo];
  heap[positionTwo]=temp;
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


void heapify(int heap[],int position,int count)
{
  int  j=2*position;
  if(j>count)
    return;
  if(j<count && heap[j]>heap[j+1])
    j++;
  if(heap[position]<heap[j])
    return;
  printIntermediateIter(heap,position,j,count);
  exchange(heap,position,j);
  heapify(heap,j,count);
}

void constructMinHeap(int heap[],int count)
{
  for(int i=count/2;i>=1;i--)
    heapify(heap,i,count);
}


int main()
{
  int heap[MAX_SIZE],count;
  int choice;

  while(choice=getChoiceFromUser()<=3)
    {
      switch(choice)
	{
	case 1:
	    printf("\n1.Give the sequence of elements with which minheap is to be constructed");
	    printf("\nEnter the number of elements in sequence\n");
	    scanf("%d",&count);
	    printf("\nEnter the elements in sequence with which minheap is to be constructed\n");
	    for(int i=1;i<=count;i++)
	      scanf("%d",&heap[i]);
	    printf("\nConstructing minHeap from given sequence:\n");
	    constructMinHeap(heap,count);
            printf("\nMin heap in level order format on heap[]:");
	    printMinHeap(heap,count);
	    break;
	case 2:
	  printf("\n Print the contents of the minheap\n");
	  printMinHeap(heap,count);
	  break;
	default:
	  printf("\n You have entered a wrong choice enter again(1-3)");
	  choice=getChoiceFromUser();
	  break;
	}
      
    }
  return 0;
}
