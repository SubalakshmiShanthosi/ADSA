#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define ANSI_COLOUR_BLUE "\x1b[34m"
#define ANSI_COLOUR_RESET   "\x1b[0m"

#define MIN_ELEMENT -99
struct heap
{
	int cap,size;
	int *arr;
};

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


void exchange(int heap[],int positionOne,int positionTwo)
{
  int temp=heap[positionOne];
  heap[positionOne]=heap[positionTwo];
  heap[positionTwo]=temp;
}


/*initalise the heap as a linear array with number of elements as capacity+1
 *heap linear array will have a sentinal value -99 at it's zero index.
 *the heap elements are at index 1...capacity+1
 */
struct heap * initialize(int capacity)
{
	struct heap *h;
	h=(struct heap *)malloc(sizeof(struct heap));
	h->arr=(int *)malloc((capacity+1)*sizeof(int));//no element stored at position 0 heap index from heap[1...capacity+1].
	h->cap=capacity;
	h->size=0;
	h->arr[0]=MIN_ELEMENT;
	return h;
}
/*check if there is no elements present in the heap array i.e) size is zero
 */
int isempty(struct heap *h)
{
	return h->size==0?1:0;
}

/*check if all the memory spaces in heap array are filled 
 */
int isfull(struct heap * h)
{
	return h->size==h->cap?1:0;
}

/*insert the element into the heap by comparing to the parent's node value and percolateUp when element is found lesser
 */
void insert(struct heap **h,int element)
{
	int i;
	//printf("\n bottomup insertion values are i:%d,parent:%d",(*h)->size,
	for(i=++(*h)->size;(*h)->arr[i/2]>element;i/=2)
		(*h)->arr[i]=(*h)->arr[i/2];
	(*h)->arr[i]=element;
}

/*delete minimum  element from the priority queue.percolating the hole down
 */
int deletemin(struct heap **h)
{
  int i,child;
  int min,last;
  //Picking heap first and last elements
  min=(*h)->arr[1];
  last=(*h)->arr[(*h)->size--];
  for(i=1;2*i<=(*h)->size;i=child)
    {
      //left child of element at index i 
      child=2*i;
      //Check if right child of element at index i is less than child(left)
      if(child!=(*h)->size && (*h)->arr[child+1]<(*h)->arr[child])
	child++; //<- making right child as minimum child element
      //Compare if it is less than that of the last element in the minheap
      if(last>(*h)->arr[child])
	{
	  printf("element at index i=%d is replaced with element at minIndex:%d as %d",i,child,(*h)->arr[child]);
	  (*h)->arr[i]=(*h)->arr[child];
	}
      else
	break;
    }
  //adjust the last element to that of this
  printf("\n lastElement:%d to index i:%d",last,i);
  (*h)->arr[i]=last;
  return min;
}

/*makeempty reinintialise an empty instance for the capacity.
 */
struct heap * makeempty(struct heap *h,int capacity)
{
  h=initialize(capacity);
  return h;
}


/*dispose will free the memory space allocated for heap
 */
void dispose(struct heap *h,int capacity)
{
  h=makeempty(h,capacity);
  free(h);
}

/*sort the elements of heap in ascending order using successive deletemin call and insert it into the new constructed minheap and dispose/free the memory space allocated for existing minheap
 *
 */
struct heap* heapsort(struct heap *h)
{
  struct heap *h1;
  int k,i;
  h1=initialize(h->cap);
  h1->size=h->size;
  printf("After performing heapsort on the contents of the priority queue \n");
  for(i=1;i<=h1->size;i++)
    {
      k=deletemin(&h);
      h1->arr[i]=k;
      printf(" %d \t",h1->arr[i]);
    }
  dispose(h,h1->cap);
  return h1;
}

void display(struct heap *h)
{
  int i;
  if(isempty(h))
    {
      printf("Heap is empty!!");
      return;
    }
  printf("The elements of the queue are: \n");
  for(i=1;i<=h->size;i++)
    printf("%d\t",h->arr[i]);
  printf("\n");
}

int findmin(struct heap *h)
{
	return h->arr[1];
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
 while(index >= 1 && heap[index/2] < heap[index])
   {
     exchange(heap,index,index/2); 
     if(index!=1)
     index=index/2;
   }
}

void heapIncreaseKey(int heap[],int count,int index,int key)
{
  int minIndex;
  //When leaf node without value insert key directly at index
  printf("\nGiven key %d is found at index %d in minheap\n",key,index);
  if(2*index>count)
    heap[index]=key;
  while(2*index <= count)
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
          index=count+1;
	}
	
    }
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
	struct heap *h;
	int ch,data,n;
	int currentKey,index;
	printf("Enter the size of the priority queue: ");
	scanf("%d",&n);
	h=initialize(n);
	while(1)
	{
	  printf("\n\nMINHEAP BOTTOMUP CONSTRUCTION MENU:\n\t");
	  printf("\n\t1.Insert\n\t2.Find min\n\t3.Delete Min \n\t");
	  printf("4.DecreaseKey for a node in binary heap \n\t\n\t5.Increase Key for a node in binary heap\n\t");
	  printf("6.Display the contents of minheap \n\t\n\t 7.Sort elements using heap sort algorithm \n\t8.Make minHeap empty\n\t9.Delete Queue and exit\n");

	  printf("\n Please enter your Choice:\n");
	  scanf("%d",&ch);
	  switch(ch)
	    {
	    case 1:
	      if(isfull(h))
		printf("Error:Priority Queue is full!!\n");
	      else
		{
		  printf("Enter the element to be inserted:\n");
		  scanf("%d",&data);
		  insert(&h,data);
		  display(h);
		}
	      break;
	     case 2:
	      if(isempty(h))
		printf("Priority Queue is empty!!");
	      else
		printf("Minimum element is : %d",findmin(h));
	      break;
         
	    case 3:
	      if(isempty(h))
		printf("Error:Priority Queue is empty!!\n");
	      else
		{
		  deletemin(&h);
		  display(h);
		}
	      break;
	    case 4:
	      int decreasedKey;
	      printf("\n 4.Decrease key for a element in the constructed minheap");
	      printf("\n Enter the number whose key is to be decreased in minheap");
	      scanf("%d",&currentKey);
	      index=findIndexInMinHeap(h->arr,h->size,currentKey);
	      if(index==-1)
		{
		printf("\nThe entered key is not present in minheap\n \n ");
		break;
		}
	      printf("\n Enter decreaseKey for key=%d to decrease its priority in minheap",currentKey);
	      scanf("%d",&decreasedKey);
	      printf("\n Calling decreaseKey for the %d with %d",currentKey,decreasedKey);
	      printf("\n -------------------------------------------------------------");
	      heapDecreaseKey(h->arr,index,decreasedKey);
	      printf("\nThe altered min heap after decreasing the priority for key=%d to alteredKey=%d",currentKey,decreasedKey);
	      display(h);
	      break;     
	    case 5:
	      int increasedKey;
	      printf("\n 5.Increase key for a element in the constructed minheap");
	      printf("\n Enter the element whose key is to be increased in minheap\n");
	      scanf("%d",&currentKey);
	      index=findIndexInMinHeap(h->arr,h->size,currentKey);
	      if(index==-1)
		{
		  printf("\nThe entered key is not present in minheap\n \n ");
		  break;
		  //count=getChoiceFromUser();
		}
	      printf("\n Enter IncreaseKey for key=%d to increase its priority in minheap\n",currentKey);
	      scanf("%d",&increasedKey);
	      printf("\n Calling IncreaseKey for the %d with %d\n",currentKey,increasedKey);
	      printf("\n -------------------------------------------------------------\n");
	      heapIncreaseKey(h->arr,h->size,index,increasedKey);
	      printf("\nThe altered min heap after increasing the priority for key=%d to alteredKey=%d\n",currentKey,increasedKey);
	      display(h);
	      break; 	      
	    case 6:
              printf("\nDisplay the contents of minheap\n");
              display(h);
              break;    
	      
	    case 7:
	      if(isempty(h)==1)
		printf("Sort not possible-Queue is empty\n");
	      else
		h=heapsort(h);
	      break;
            case 8:
	      if(isempty(h))
		printf("Priority Queue is already empty!!");
	      else
		{
		  h=makeempty(h,n);
		  printf("Priority Queue made empty!!");
		}					
	      break;
         
	    case 9:
	      dispose(h,n);
	      exit(1);
	      break;
	    default:
	      printf("Enter correct menu option!!");
	    }
	}
	return 0;
}
