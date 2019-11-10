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
  
  for(int i=0;i<size;i++)
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


int heap_size(int heap[])
{
     return *(&heap+1)-heap;
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
  printf("\n ---- BOTTOMUP MINHEAP OPERATIONS -- \n");
  printf("\nEnter your choice (1-5, enter 6 to quit)");
  printf("\n 1.Give the sequence of elements with which minheap is to be constructed");
  printf("\n 2.Decrease key for a element in the constructed minheap");
  printf("\n 3.Print the contents of minheap constructed");
  printf("\n 4. Exit\n");
  printf("\n ---------------------------");
  printf("\n Please Enter your choice:");
  scanf("%d",&choice);
  if (choice==4)
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


void heapify(int heap[],int position,int count)
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
      heapify(heap,min,count);
    }
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


void heapDecreaseKey(int heap[], int index, int key)
{
  if(key > heap[index])
    {
      printf("New key must be lesser than the input at index");
      return;
    }
  heap[index]= key;
   //Adjust heap to restore heapOrder property
 while(index > 1 && heap[parent(input,index)] < heap[index])
   {
     exchange(input,index,parent(input,index)); 
     if(index!=1)
     index=parent(input,index);
   }
}


void constructMinHeap(int heap[],int count)
{
  for(int i=count/2;i>=1;i--)
    heapify(heap,i,count);
}


int size_toint(size_t value) {
    return (val <= INT_MAX) ? (int)((ssize_t)value) : -1;
}


int heap_size(int heap[])
{
 size_t heapSize = *(&heap + 1) - heap;
 int size=size_toint(heapSize);
 return size;
}


int main()
{
  int heap[MAX_SIZE],count;
  int choice=getChoiceFromUser();

  while(choice=getChoiceFromUser() <=4)
    {
      switch(choice)
	{
	case 1:
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
	    break;
	case 2:
	    int decreasedKey,currentKey;
	    printf("\n 2.Decrease key for a element in the constructed minheap");
	    printf("\n Enter the number whose key is to be decreased in minheap");
	    scanf("%d",&currentKey);
	    int index=findIndexInMinHeap(heap,count,currentKey);
	    if(index==-1)
	      {
	      printf("\nThe entered key is not present in minheap\n \n ");
	      break;
	      count=getChoiceFromUser();
	      }
	    printf("\n Enter decreaseKey for key=%d to decrease its priority in minheap",currentKey);
	    scanf("%d",&decreaseKey);
	    printf("\n Calling decreaseKey for the %d with %d",currentKey,decreaseKey);
            printf("\n -------------------------------------------------------------");
	    heapDecreaseKey(heap,index,decreaseKey);
	    printf("\nThe altered min heap after decreasing the priority for key=%d to alteredKey=%d",currentKey,decreaseKey);
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
      
    }
  return 0;
}
