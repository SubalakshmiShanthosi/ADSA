#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
  int data;
  struct node* left;
  struct node* right;
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

void printNodes(struct node *root,int size)
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
    free(queue);
}

//move left or right in BST till reaching for minimum or maximum node,where direction is given by 'L' or 'R' 
struct node*  minOrMaxBST(struct node* aNode,char direction)
{
  if(direction == 'L')
    {
      while(aNode->left !=NULL)
	aNode=aNode->left;
      return aNode;
    }
  else
    {
      while(aNode->right !=NULL)
	aNode=aNode->right;
      return aNode;
    }
}

struct node* search(struct node* root,int key)
{
  if(root==NULL || key==root->data)
    return root;
  if(key<root->data)
    return search(root->left,key);
  else
    return search(root->right,key);
}

/*deleteNode( root reference, key) -> deletes a node by freeing its allocated space and does balancing to restore BST property ,
 * deletion case 1: deleting a leaf node -> make parent pointer to it null and  free space 
 * deletion case 2: when left and right child are present find max of left subtree replace the data of it to the element , free space of the max node
 * deletion case 3: when the node has only right child make its parent point to it's right successor 
 * deletion case 4: when a node has only one left child make its parent point to
 * the left successor
 */
struct node* deleteNode(struct node* root,int keyDel)
{
  if(root==NULL)
    return NULL;
  if(keyDel < root->data)
    root=deleteNode(root->left,keyDel);
  else if(keyDel > root->data)
    root=deleteNode(root->right,keyDel);
  else
    {
      
      if(root->left == NULL)
	{
	  struct node* temp=root->right;
	  free(root);
	  return temp;
	}
      else if(root->right == NULL)
	{
	  struct node* temp=root->left;
	  free(root);
	  return temp;
	}
      else
	{
	  struct node* temp=minOrMaxBST(root->left,'R');
	  root->data=temp->data;
	  root->right=deleteNode(root->right,temp->data);
	}
    }
  return root;
}

//search for the data in the BST
bool searchKey(struct node* root,int key)
{
  while(root!=NULL)
    {
      if(key==root->data)
	return true;
      else if(key<root->data)
	root=root->left;
      else if (key>root->data)
	root=root->right;
    }
  return false;
}


//print in inorder i.e data in leftsubtree followed by data in root and data in leftsubtree at every level 
void printInOrderNodes(struct node* root)
{
  if(root==NULL)
    return;
  printInOrderNodes(root->left);
  printf(" %d ",root->data);
  printInOrderNodes(root->right);
}

int main()
{
  int size,aElementToDelete,key;
  struct node* root=NULL;
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
  printNodes(root,size);
  
  printf("\nEnter the number which is to be removed from the constructed BST:\n");
  scanf("%d",&aElementToDelete);
  deleteNode(root,aElementToDelete);
  printf("\nAfter deleting %d ,Altered BST in InOrder format is:\n",aElementToDelete);
  printInOrderNodes(root);
  printf("\n Enter the key to be searched for:");
  scanf("%d",&key);
   if(searchKey(root,key))
     printf("\nKey %d is present in BST",key);
   else
     printf("\nKey is not present in constructed BST");
   
  printf("\n");
  return 0;
}
