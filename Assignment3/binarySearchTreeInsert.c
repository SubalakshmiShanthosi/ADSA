#include<stdio.h>
#include<stdlib.h>
#include"QueueinC/queueImpl.h"
#include<math.h>
#define MAX_SIZE 30

typedef struct node *pointer;
typedef struct node
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

//print in inorder i.e data in leftsubtree followed by data in root and data in leftsubtree at every level 
void printNodes(struct node* root)
{
  if(root==NULL)
    return;
  printNodes(root->left);
  printf(" %d ",root->data);
  printNodes(root->right);
}


int height(struct node* aNode)
{
  if(aNode==NULL)
    return -1;
  else
    return 1+ (int)fmax((float)height(aNode->left),(float)height(aNode->right));
}

int countNodes(struct node* root)
{
  if(root==NULL)
    return 0;
  return 1+ countNodes(root->left) + countNodes(root->right);
}


int main()
{
  int size,key;
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
  printf("\nInOrder traversal of elements in BST is given as:\n");
  printNodes(root);
  /*
  printf("\n Level order traversal of BST is given below:\n");
  printLevelOrder(root,size);
  printf("\nNumber of nodes in BST which is constructed: %d",countNodes(root));
  printf("\nThe height of BST: %d",height(root));
  */
  printf("\n");
  return 0;
}
