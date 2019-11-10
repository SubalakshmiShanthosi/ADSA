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


int getChoiceFromUser()
{
  int choice;
  printf("\n ---- BOTTOMUP MINHEAP OPERATIONS -- \n");
  printf("\nEnter your choice (1-8, enter 8 to quit)");
  printf("\n 1.Give the sequence of elements with which minheap is to be constructed");
  printf("\n 2.Decrease key for a element in the constructed minheap");
  printf("\n 3.Increase key for a element which is present in the constructed minheap");
  printf("\n 4.Extract minimum/root of the minheap and restore heaporder property");
  printf("\n 5.DeleteKey which will remove the key from the minheap");
  printf("\n 6.FindMin which will return the root of minheap");
  printf("\n 7.Print the contents of minheap constructed");
  printf("\n 8. Exit\n");
  printf("\n --------------------------------------");
  printf("\n Please Enter your choice:");
  scanf("%d",&choice);
  if (choice==8)
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
     printIntermediateIter(heap,index,parent(index));
     if(index!=1)
     index=parent(index);
   }
}

void heapIncreaseKey(int heap[],int count,int index,int key)
{
  int minIndex;
  //When leaf node without value insert key directly at index
  if(2*index>count)
    heap[index]=key;
  while(2*index < count)
    {
      int leftChild=leftChild(index);
      int rightChild=rightChild(index);
      int minIndex=leftChild;
      if(rightChild<count && heap[rightChild]<heap[leftChild])
	minIndex=rightChild;
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
	  //Done with increaseKey break the loop
          index=count;
	}
	
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

int findMin(int heap[])
{
  return heap[1];
}

bool deleteKey(int heap[],int index,int *count)
{
  heapDecreaseKey(heap,index,INT_MIN);
  int min=extractMin(heap,*count);
  return min==INT_MIN;
}

int main()
{
  int heap[MAX_SIZE],count;
  int choice=getChoiceFromUser();
  while(choice=getChoiceFromUser() <=6)
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
	      choice=getChoiceFromUser();
	      }
	    if(!isHeap(heap,heap_size(heap))
	       constructMinHeap(heap,heap_size(heap));
	    printf("\n Enter decreaseKey for key=%d to decrease its priority in minheap",currentKey);
	    scanf("%d",&decreaseKey);
	    printf("\n Calling decreaseKey for the %d with %d",currentKey,decreaseKey);
            printf("\n -------------------------------------------------------------");
	    heapDecreaseKey(heap,index,decreaseKey);
	    printf("\nThe altered min heap after decreasing the priority for key=%d to alteredKey=%d",currentKey,decreaseKey);
	    printMinHeap(heap,count);
	    break;
	case 3:
	    int increaseKey,currentKey;
	    printf("\n 3.Increase key for a element in the constructed minheap");
	    printf("\n Enter the number whose key is to be increased in minheap");
	    scanf("%d",&currentKey);
	    int index=findIndexInMinHeap(heap,count,currentKey);
	    if(index==-1)
	      {
		printf("\nThe entered key is not present in minheap\n Please enter the choice once again!: ");
		choice=getChoiceFromUser();
		break;
	      }
	    if(!isHeap(heap,heap_size(heap))
	       constructMinHeap(heap,heap_size(heap));
	    printf("\n Enter increaseKey for key=%d to increase its priority in minheap:",currentKey);
	    scanf("%d",&increaseKey);
	    heapIncreaseKey(heap,index,increaseKey);
	    printf("\nThe altered minheap after increasing the priority for key=%d to alteredKey=%d",currentKey,decreaseKey);
	    printMinHeap(heap,count);
	    break;
	case 4:
	       printf("\nExtract minimum/root of minheap and reconstruct minheap to ensure heaporder property\n");
	    int extractMinEle;
	    count=heap_size(heap);
	       if(count == MAX_SIZE)
		 {
		   printf("\n Initial sequence is not entered! please give 1 to construct heap:");
		   choice=getChoiceFromUser();
		   break;
		 }
	    if(!isHeap(heap,heap_size(heap))
	       constructMinHeap(heap,count);
	    printf("\n 4.Extract minimum element/root of minheap");
	    extractMinEle=extractMin(heap,&count);
	    printf("\n The altered minheap post deletion of root element:");
	    printHeap(heap,&count);
	    printf("\n The extracted minimum element from the minheap is: %d",extractMinEle);
	    break;
	case 5:
	    int keyToBeDel;
	    printf("\n Delete the element which is present in the minHeap");
	    scanf("%d",&keyToBeDel);
	    int index=findIndexInMinHeap(heap,heap_size(heap),currentKey);
	    count=heap_size(heap);
	    if(index==-1)
	      {
	        printf("\nThe entered key is not present in minheap\n Please enter the choice once again!: ");
		choice=getChoiceFromUser();
		break;
	      }
	    bool flag=deleteKey(heap,index,&count);
	    if(flag)
	      printf("\n The altered minheap post deletion of element=%d from minHeap:",keyToBeDel);
	    printHeap(heap,&count);   
	    break;
	case 6:
	    printf("\n Find the minimum/root of minHeap:");
	    printf("\n The minimum/root of minheap is:%d",findMin(heap));
            break;
	case 7:
	    printf("\n Display the contents of minheap:");
	    if(!isHeap(heap,heap_size(heap))
	       constructMinHeap(heap,count);
	    printHeap(heap,heap_size(heap));
	    break;
        default:
	    printf("\nPlease enter a option again:");
	    choice=getChoiceFromUser();
	    break;
	}
	     
    }
  return 0;
}
