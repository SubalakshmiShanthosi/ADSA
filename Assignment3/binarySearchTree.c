#include<stdio>
#define MAX_SIZE 30

/*Constructing BST from input feed in levelOrder format rootelement,left-child   * right-child and assumed to be complete --> store it in linear ADT array 
 */

/* given constructed bst and a position of current node return value at parent   * node of current node
 */
int parent(int array[],int position)
{
  return array[position/2];
}

/*given constructed bst and a position of current node return value at left      * child of node 
 */
int left(int array[],int position)
{
  return array[2*position];
}
/* given constructed bst and a position of current node return value at right    *  child of node
 */
int right(int array[],int position)
{
  return array[2*position+1];
}


int main()
{
  int array[MAX_SIZE],size;
  printf("\nEnter the number of nodes in BST:\n");
  scanf("%d",&size);
  printf("\nEnter the nodes of BST in level order format:\n");
  for(int i=1;i<=size;i++)
    scanf("%d",&array[i]);
  // constructBST(array,size);
  return 0;
}
