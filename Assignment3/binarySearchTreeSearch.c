#include<stdio.h>
#include<stdlib.h>
#include"QueueinC/queueImpl.h"
#include<math.h>
#define MAX_SIZE 30

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

//print in inorder i.e data in leftsubtree followed by data in root and data in leftsubtree at every level 
void printNodes(struct node* root)
{
  if(root==NULL)
    return;
  printNodes(root->left);
  printf(" %d ",root->data);
  printNodes(root->right);
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
  printf("\nEnter the element to be searched for:");
  scanf("%d",&key);
  if(searchKey(root,key))
    printf("\nKey %d is present in BST",key);
  else
  printf("\nKey is not present in constructed BST");
  printf("\n");
  return 0;
}

