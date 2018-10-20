#include <iostream>
#define MAX_SIZE 50
using namespace std;

/* 
 *insertElementInMiddle(int input[],int size,int position,int key)
 * macro which runs between size+1 and position+1 of input[0..size] assumes that the array grows within MAX_SIZE,
 * shift elements one position to the right , insert the key in input[position+1].
 */
void insertElementInMiddle(int input[],int *size,int position,int key)
{ 
  for(int i=*size+1;i>=position+1;i--)
    input[i]=input[i-1];
  input[position+1]=key;
  *size+=1;
}


/*
 *makeKeyConsecutive - linearly trace array for presence of key. if found insert key after the current position
 */
void makeKeyConsecutive(int input[],int start,int size,int key)
{
  int temp;
  while(start<size)
  {
  if(input[start]==key)
    {
      insertElementInMiddle(input,&size,start,key);
      start+=2;
    }
  else
    {
      temp+=1;
      start+=1;
    }
  }

  if(temp==size)
    cout<<"Key is not found in sequence"<<endl;
  else
    {
      cout<<"Altered sequence is:"<<endl;
      for(int i=0;i<size;i++)
	cout<<input[i]<<"  ";
    }
}

int main()
{
  int input[MAX_SIZE],size,key;
  cout<<"Enter the number of elements in the sequence"<<endl;
  cin>>size;
  cout<<"Enter the elements in sequence:"<<endl;
  for(int i=0;i<size;i++)
    cin>>input[i];
  cout<<"Enter the key whose presence is to be made consecutive!"<<endl;
  cin>>key;
  makeKeyConsecutive(input,0,size,key);
  //Testcase two - when key is not present in the sequence
  int inputTwo[]={5,7,2,1,7};
  int keyTwo=3;
  cout<<"\nTestcase two - key not present in the sequence -{5,7,2,1,7};key=3\n";
  makeKeyConsecutive(inputTwo,0,5,keyTwo);  
  return 0;
}

