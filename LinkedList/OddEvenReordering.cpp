#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
  int data;
  struct node* next;
};

struct node* createNode(int value,struct node* head)
{
  struct node* temp=(struct node*)malloc(sizeof(struct node));
  struct node* ptr=(struct node*)malloc(sizeof(struct node));
  temp->data=value;
  temp->next=NULL;
  if(head->data==0)
    {
      head=temp;
    }
  else
    {
      ptr=head;
      while(ptr->next!=NULL)
	{
	  ptr=ptr->next;
	}
      ptr->next=temp;
    }
  return head;
}

void printLinkedList(struct node* temp)
{
  while(temp!=NULL)
    {
      cout<<temp->data<<"-->";
      temp=temp->next;
      if(temp->next==NULL)
	{
	  cout<<temp->data<<".";
	  break;
	}
    }
}

void groupOddFollowedByEvenPos(struct node* head)
{
  struct node* last=head;
  struct node* first=head;

  while(last->next!=NULL)
    last=last->next;

  struct node* ptr=last;
  while(first!=last)
    {
      struct node* replace=first->next;
      ptr->next=replace;
      first->next=replace->next;
      replace->next=NULL;
      ptr=replace;
      first=first->next;
    }
  
}

int main()
{
  int size,key;
  cout<<"Enter number of elements in the sequence"<<endl;
  cin>>size;
  cout<<"Enter elements in sequence"<<endl;
  struct node* head=(struct node*)malloc(sizeof(struct node));
  struct node* temp;
  for(int i=0;i<size;i++)
    {
      int element;
      cin>>element;
      head=createNode(element,head);
    }
  temp=head;
  printLinkedList(temp);
  temp=head;
  cout<<"Altered linked list after grouping odd positioned followed by even elements is:"<<endl;
  groupOddFollowedByEvenPos(temp);
  printLinkedList(temp);
  cout<<endl;
  return 0;
}
