#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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


void printIntermediate(int heap[],int pos1,int size)
{
  printIntermediateIter(heap,pos1,-1,size);
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
  printf("\n\n ---- BOTTOMUP MINHEAP OPERATIONS ----\n\n");
  printf("\nEnter your choice (1-4, enter 4 to quit)");
  printf("\n 1.Give the sequence of elements with which minheap is to be constructed");
  printf("\n 2.Increase key for a element in the constructed minheap");
  printf("\n 3.Print the contents of minheap constructed");
  printf("\n 4. Exit\n");
  printf("\n ---------------------------");
  printf("\n Please Enter your choice:");
  scanf("%d",&choice);
  if (choice==4)
    exit(0);
  return choice;
}

/*print the contents of the minHeap heap[1...count] which is constructed post constructMinHeap call. 
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
        // If left child is smaller, return false 
      if (heap[leftChild(i)] < heap[i]) 
	return false; 
      
        // If right child is smaller, return false 
      if (rightChild(i) < count && heap[rightChild(i)] < heap[i]) 
	return false; 
    } 
    return true; 
} 


void heapIncreaseKey(int heap[],int count,int index,int key)
{
  int minIndex;
  //When leaf node without value insert key directly at index
  printf("\nGiven key %d is found at index %d in minheap\n",key,index);
  if(2*index>count)
    heap[index]=key;
  while(2*index < count)
    {
      int lfChild=2*index;
      int rtChild=2*index+1;
      int minIndex=lfChild;
      if(rtChild<count && heap[rtChild]<heap[lfChild])
	minIndex=rtChild;
      if(heap[minIndex] < key)
	{
	  heap[index]=key;
	  exchange(heap,minIndex,index);
	  printIntermediateIter(heap,minIndex,index,count);
	  index=minIndex;
	}
      else
        {
	  heap[index]=key;
	  printIntermediate(heap,index,count);
	  //Done with increaseKey break
          index=count;
	}
	
    }
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



int size_toint(size_t value) {
    return (value <= INT_MAX) ? (int)((ssize_t)value) : -1;
}


int heap_size(int heap[])
{
 size_t heapSize = *(&heap + 1) - heap;
 int size=size_toint(heapSize);
 return size;
}

int findIndexInMinHeap(int heap[],int count,int key)
{
for(int i=1;i<=count;i++)
    if(heap[i]==key)
          return i;
return INT_MIN;
}


int main()
{
  int heap[MAX_SIZE],count;
  int choice;
    do
    {
      choice=getChoiceFromUser();
      switch(choice)
	{
	case 1:
	    printf("\n1.Give the sequence of elements with which minheap is to be constructed\n");
	    printf("\nEnter the number of elements in sequence\n");
	    scanf("%d",&count);
	    printf("\nEnter the elements in sequence with which minheap is to be constructed\n");
	    for(int i=1;i<=count;i++)
	      scanf("%d",&heap[i]);
	    printf("\nConstructing minHeap from given sequence:\n");
	    constructMinHeap(heap,count);
            printf("\nMin heap in level order format on heap[]:\n");
	    printMinHeap(heap,count);
	    break;
	case 2:
	    int increasedKey,currentKey,index;
	    printf("\n 2.Increase key for a element in the constructed minheap");
	    printf("\n Enter the element whose key is to be increased in minheap\n");
	    scanf("%d",&currentKey);
	    index=findIndexInMinHeap(heap,count,currentKey);
	    if(index==-1)
	      {
	      printf("\nThe entered key is not present in minheap\n \n ");
	      break;
	      count=getChoiceFromUser();
	      }
	    printf("\n Enter IncreaseKey for key=%d to increase its priority in minheap\n",currentKey);
	    scanf("%d",&increasedKey);
	    printf("\n Calling IncreaseKey for the %d with %d\n",currentKey,increasedKey);
            printf("\n -------------------------------------------------------------\n");
	    heapIncreaseKey(heap,count,index,increasedKey);
	    printf("\nThe altered min heap after increasing the priority for key=%d to alteredKey=%d\n",currentKey,increasedKey);
	    printMinHeap(heap,count);
	    break;
	case 3:
	    printf("\n Print the contents of the minheap");
	    printMinHeap(heap,count);
            break;
	default:
	    printf("\n You have entered a wrong choice enter again(1-4)");
	    choice=getChoiceFromUser();
	    break;
	}
      
    }while(choice<=3);
  return 0;
}
