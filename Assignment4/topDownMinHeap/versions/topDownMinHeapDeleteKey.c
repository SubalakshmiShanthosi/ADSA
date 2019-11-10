#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
  printf("\n ---- BOTTOMUP MINHEAP OPERATIONS -- \n");
  printf("\nEnter your choice (1-4, enter 4 to quit)");
  printf("\n 1.Give the sequence of elements with which minheap is to be constructed");
  printf("\n 2.DeleteKey for a element in the constructed minheap");
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
void printHeap(int heap[],int count)
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



void heapDecreaseKey(int heap[], int index, int key)
{
  if(key > heap[index])
    {
      printf("New key must be lesser than the input at index");
      return;
    }
  heap[index]= key;
   //Adjust heap to restore heapOrder property
 while(index > 1 && heap[parent(index)] < heap[index])
   {
     exchange(heap,index,parent(index));
     printIntermediate(heap,index,parent(index));
     if(index!=1)
     index=parent(index);
   }
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


int extractMin(int heap[],int *count)
{
  if(*count <=0)
    return INT_MAX;
  if(*count==1)
    {
      *count--;
      return heap[1];
    }
  int minElement=heap[1];
  heap[1]=heap[*count];
  //neglect INT_MAX
  *count=*count-1;
  heapifyDown(heap,1,*count);
  return minElement;
}

/*
int deletemin(int heap[],int *count)
{
	int min,d,l=1; 
	min=heap[l];
	heap[l]=heap[count];
	*count=count-1;
	heapifyDown(heap,count,*count);
	return min;
}
*/


void deleteKey(int heap[],int index,int *count)
{
  heap[index]=heap[*count];
  heapifyDown(heap,index,*count);
  *count=*count-1;
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

int findIndexInMinHeap(int heap[],int count,int key)
{
  for(int i=1;i<=count;i++)
    if(heap[i]==key)
      return i;
  return -1;
}



void constructMinHeap(int heap[],int count)
{
  for(int i=count/2;i>=1;i--)
    heapifyDown(heap,i,count);
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
	    printHeap(heap,count);
	    break;
	case 2:
	    int index;
	    bool flag;
	    printf("\n 2.Delete a key from constructed minHeap:\n");
	    printf("\nEnter key which is to be removed from min heap\n");
	    int keyToBeDel;
            scanf("%d",&keyToBeDel);
	    index=findIndexInMinHeap(heap,heap_size(heap),keyToBeDel);
	    count=heap_size(heap);
	    if(index==-1)
	      {
	        printf("\nThe entered key is not present in minheap\n Please enter the choice once again!:\n");
		choice=getChoiceFromUser();
		break;
	      }
	    deleteKey(heap,index,&count);
	      printf("\n The altered minheap post deletion of element=%d from minHeap:\n",keyToBeDel);
	     printHeap(heap,count);   
	    break;
	case 3:
	    printf("\n Print the contents of the minheap\n");
	    printHeap(heap,count);
            break;
	default:
	    printf("\n You have entered a wrong choice enter again(1-4)");
	    choice=getChoiceFromUser();
            break;
	}
      
    }while(choice<=3);
  return 0;
}
