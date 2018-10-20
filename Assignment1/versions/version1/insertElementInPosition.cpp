#include <iostream>
#define MAX_SIZE 30
using namespace std;

/* 
 *insertElementInMiddle(int input[],int size,int position,int key)
 * macro which runs between size+1 and position+1 of input[0..size] assumes that the array grows within MAX_SIZE,
 * shift elements one position to the right , insert the key in input[position].
 */
void insertElementAtPosition(int input[],int *size,int position,int key)
{
  for(int i=*size+1;i>=position+1;i--)
    input[i]=input[i-1]; 
  input[position]=key;
  *size+=1;
}

int main()
{
  int input[MAX_SIZE],size,key,position;
  cout<<"Enter the number of elements in the sequence"<<endl;
  cin>>size;
  cout<<"Enter the elements in sequence:"<<endl;
  for(int i=0;i<size;i++)
    cin>>input[i];
  cout<<"Enter the position after which the element is to be inserted";
  cin>>position;
  cout<<"Enter the key which is to be inserted!"<<endl;
  cin>>key;
  insertElementAtPosition(input,&size,position,key);
  for(int i=0;i<size;i++)
    cout<<input[i]<<" ";
  return 0;
}
