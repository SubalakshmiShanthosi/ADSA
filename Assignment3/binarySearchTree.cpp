#include<iostream>
#include<set>
#include<queue>
#define MAX_SIZE 30
using namespace std;

struct node
{
  int data;
  struct node* left;
  struct node* right;
};

//createNode
struct node* createNode(int value)
{
  struct node* newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=value;
  newNode->left=NULL;
  newNode->right=NULL;
  return newNode;
}

//makeNodeLeftChild
struct node* makeLeft(struct node* aNode,struct node* anotherNode)
{
aNode->left=anotherNode;
return aNode;
}

//makeNodeRightChild
struct node* makeRight(struct node* aNode,struct node* anotherNode)
{
aNode->right=anotherNode;
return aNode;
}

/* insert value node into a BST rooted by aNode
 */
struct node* insertBST(struct node* aNode,int value)
{
struct node* newNode=createNode(value);
if(aNode==NULL)
  aNode=newNode;
 else if( value < aNode->value)
   aNode->left=insertBST(aNode->left,value);
   else if(value > aNode->value)
     aNode->right=insertBST(aNode->right,value);
return aNode;
}



int main()
{
int size,aElement;
  cout<<"Enter number of elements which are to be taken for BST construction"<<endl;
  cin>>size;
  struct node* root=NULL;
  cout<<"Enter the elements with which a BST is to be constructed";
  for(int i=1;i<=size;i++)
    {
      cin>>aElement;
      root=insertBST(root,aElement);
    }
printBST(root);
  return 0;
}
