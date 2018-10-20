#include <iostream>
#define MAX_SIZE 50
using namespace std;

/* 
 *insertElementInMiddle(int input[],int size,int start,int end,int key)
 * macro which runs between start and end indices of input[0..size] assumes that the array grows within MAX_SIZE,
 * shift elements one position to the right , insert the key in input[start].
 */
void insertElementInMiddle(int input[],int start,int end,int key)
{ 
  for(int i=start;i<=end;i++)
    input[i+1]=input[i];
  input[start]=key;
  return start+1;
}

/*
 *linear search algorithm - sequentially trace the array to find the presence of
 *"key" in input[0..n] and print the position of it's occurences.
 */

void linearSearch(int input[],int start,int size,int key)
{
  int i=0,flag=0;
  for(i=start;i<(int)(*(&input+1)-input);i++)
    {
      if(input[i]==key)
	{
	cout<<"Key found at position:"<<i+1<<endl;
	insertElementInMiddle(input,i+1,(*(&input+1)-input)+1,key);
	flag++;
	}
    }
  if(flag!=0)
    {
       cout<<"Array after consecutive key position alteration:"<<endl;
       for(i=0;i<size+flag;i++)
         cout<<input[i]<<" ";
    }
  if(flag==0)
    cout<<"The given key:"<<key<<" is not present in the sequence!"<<endl;
}

int main()
{
  int input[MAX_SIZE],size,key;
  cout<<"Enter the number of elements in the sequence"<<endl;
  cin>>size;
  cout<<"Enter the elements in sequence:"<<endl;
  for(int i=0;i<size;i++)
    cin>>input[i];
  cout<<"Enter the key whose presence is to be tested!"<<endl;
  cin>>key;
  linearSearch(input,0,size,key);
  //Testcase two - when key is not present in the sequence
  /*
  int inputTwo[]={5,7,2,1,7};
  int keyTwo=3;
  cout<<"Testcase two - key not present in the sequence -{5,7,2,1,7};key=3"<<endl;
  linearSearch(inputTwo,5,keyTwo);
  */  
  return 0;
}

