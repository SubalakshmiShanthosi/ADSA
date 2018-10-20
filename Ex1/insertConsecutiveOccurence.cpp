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
  cout<<"\nEnter the key whose occurence is to be made consecutive"<<endl;
  cin>>key;
  temp=head;
    while(temp!=NULL)
    { 

      if(temp->data==key)
    { 
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=key;
    newNode->next=temp->next;
    temp->next=newNode;
    temp=temp->next->next;
    }
    else 
     temp=temp->next;
    }
    temp=head;
    cout<<"Altered sequence is"<<endl;
    printLinkedList(temp);
    return 0;
}
