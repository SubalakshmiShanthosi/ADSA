#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node node;
typedef struct node *pointer;
struct node
{
  int data;
  pointer left;
  pointer right;
};


struct node* createNode(int value)
{
  struct node* aNewNode=(struct node*)malloc(sizeof(struct node));
  aNewNode->data=value;
  aNewNode->left=NULL;
  aNewNode->right=NULL;
}


struct node* insertNode(struct node* aNode,int value)
{
  if(aNode == NULL)
    return createNode(value);
  if(value==aNode->data)
    return aNode;
  if(value<aNode->data)
    aNode->left=insertNode(aNode->left,value);
  else
    aNode->right=insertNode(aNode->right,value);

  return aNode;
}
struct node** createQueue(int *front,int *rear,int capacity)
{
  struct node** queue=(struct node**)malloc(sizeof(struct node*)*capacity);
  *front=0;
  *rear=0;
  return queue;
}


void enqueue(struct node** queue,int *rear,struct node *new_node)
{
  queue[*rear]=new_node;
  (*rear)++; 
}

struct node* dequeue(struct node** queue,int *front)
{
  (*front)++;
  return queue[*front-1];
}

void printLevelOrder(struct node *root,int size)
{
    int rear, front; 
    struct node **queue = createQueue(&front, &rear,size); 
    if(root==NULL)
      {
        printf("\nNo nodes in BST to display");
	return;
      }
    struct node *temp = root; 
  
    while (temp) 
    { 
        printf("%d ", temp->data); 
	
        /*Enqueue left child */
        if (temp->left) 
            enqueue(queue, &rear, temp->left); 
  
        /*Enqueue right child */
        if (temp->right) 
            enqueue(queue, &rear, temp->right); 
  
        /*Dequeue node and make it temp_node*/
        temp = dequeue(queue, &front);
       
    } 

}


int main()
{
  int size,key;
  struct node *root=NULL;
  printf("\nEnter the number of elements with which BST is to be created:");
  scanf("%d",&size);
  printf("\nEnter the elements in BST:");
  for(int i=0;i<size;i++)
    {
      int aElement;
      scanf("%d",&aElement);
      root=insertNode(root,aElement); 
    }
  printf("\nLevelOrder traversal of elements in BST is given as:\n");
  printLevelOrder(root,size);
  printf("\n");
  return 0;
}
