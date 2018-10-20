#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;

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
  if(aNode==NULL)
     aNode= createNode(value);
  if(value==aNode->data)
    return aNode;
  if(value<aNode->data)
    aNode->left=insertNode(aNode->left,value);
  else
    aNode->right=insertNode(aNode->right,value);
  return aNode;
}


//printLevelOrder prints elements at every level of a binary search tree
void printLevelOrder(struct node* root,int noOfEle)
{
  std::queue<node*> lOqueue;
  if(!root)
    return;
  lOqueue.push(root);
  while(1)
    {
      root=lOqueue.front();
      if(root!=NULL)
	{
	  printf(" %d ",root->data);
	  lOqueue.pop();
	  if(root->left!= NULL)
	    lOqueue.push(root->left);
	  if(root->right!=NULL)
	    lOqueue.push(root->right);
	}
      else
	break;
    }
  cout<<endl;
}



//move left or right in BST till leave for minimum or maximum node,where direction is given by 'L' or 'R' 
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
 * 
 * deletion case 4: when a node has only one left child make its parent point to
 * the left successor
 *
 *
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
	  struct node* temp=minOrMaxBST(root,'R');
	  root->data=temp->data;
	  free(temp);
	  root->right=deleteNode(root->right,temp->data);
	}
    }
  return root;
}




int main()
{
  int noOfEle,aElement,aElementToDelete;
  cout<<"\nEnter the number of elements in sequence:";
  cin>>noOfEle;
  struct node* root=NULL;
  cout<<"\nEnter the elements in sequence:";
  for(int i=1;i<=noOfEle;i++)
    {
    cin>>aElement;
    root=insertNode(root,aElement);
    }
  printLevelOrder(root,noOfEle);
  cout<<"Minimum element is"<<minOrMaxBST(root,'L')->data<<endl;
  cout<<"Maximum element is"<<minOrMaxBST(root,'R')->data<<endl;
  cout<<"\n\nEnter the number which is to be removed from the constructed BST"<<endl;
  cin>>aElementToDelete;
  deleteNode(root,aElementToDelete);
  cout<<"After deleting"<<aElementToDelete<<"Altered BST in level order is:"<<endl;
  printLevelOrder(root,noOfEle);
  cout<<endl;
  return 0;
}
