#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 30
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
