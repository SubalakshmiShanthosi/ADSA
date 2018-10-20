#include<stdio>
#define MAX_SIZE 30

/*Constructing MinHeap from input feed in levelOrder format rootelement,left-child   
 * right-child and assumed to be complete --> store it in linear ADT array 
 */

/* given constructed MinHeap and a position of current node return value at parent   
 * node of current node
 */
int parent(int array[],int position)
{
  return array[position/2];
}

/*given constructed MinHeap and a position of current node return value at left      
 * child of node 
 */
int left(int array[],int position)
{
  return array[2*position];
}
/* given constructed MinHeap and a position of current node return value at right    
 *  child of node
 */
int right(int array[],int position)
{
  return array[2*position+1];
}

/* In minheap the root element is the minimum node and the nodes in next level's are greater than that,first element is minimum 
 */
int minElement(int array[])
{
  return array[1];
}
/* insert into a minHeap : steps place the value to be inserted in  the end of array and restore Minheap property
 * by percolateUp to max the minimum element present at root element 
 */

void insert(int heap[],int size, 


int main()
{
  int array[MAX_SIZE],size;
  printf("\nEnter the number of elements with which minHeap is to be constructed:\n");
  scanf("%d",&size);
  printf("\nEnter the elements  in minHeap in level order format:\n");
  for(int i=1;i<=size;i++)
    scanf("%d",&array[i]);
  constructHeap(array,size);
  return 0;
}
