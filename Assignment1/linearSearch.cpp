#include <iostream>
using namespace std;

/*
 *linear search algorithm - sequentially trace the array to find the presence of
 *"key" in input[0..n] and print the position of it's occurences.
 */
void linearSearch(int input[],int size,int key)
{
  int i;
  while(i<size)
    {
      if(input[i]==key)
	{
	cout<<"Key found at position:"<<i+1<<endl;
	}
    }
}


int main()
{
  int input[30],size,key;
  cout<<"Enter the number of elements in the sequence"<<endl;
  cin>>size;
  cout<<"Enter the elements in sequence:"<<endl;
  for(int i=0;i<size;i++)
    cin>>input[i];
  cout<<"Enter the key whose presence is to be tested!"<<endl;
  cin>>key;
  linearSearch(input,size,key);
  //Testcase two - when key is not present in the sequence
  /*
  int inputTwo[]={5,7,2,1,7};
  int keyTwo=3;
  cout<<"Testcase two - key not present in the sequence -{5,7,2,1,7};key=3"<<endl;
  linearSearch(inputTwo,5,keyTwo);
  */  
  return 0;
}
