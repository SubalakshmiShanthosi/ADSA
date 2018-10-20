#include<iostream>
#define MAX_SIZE 30
using namespace std;

void insertionSort(int input[],int size)
{
  int i=1,j,temp;
  while(i<size)
    {
      j=i;
      while(j>0 && input[j-1] > input[j])
	{
	  temp=input[j-1];
	  input[j-1]=input[j];
	  input[j]=temp;
	  j-=1;
	}
      i+=1;
    }

  cout<<"Elements in ascending order:"<<endl;
  for(i=0;i<size;i++)
    cout<<input[i]<<"  ";

}
int main()
{
  int input[MAX_SIZE],size;
  cout<<"Enter the number of elements in sequence"<<endl;
  cin>>size;
  cout<<"Enter the elements in sequence:"<<endl;
  for(int i=0;i<size;i++)
    cin>>input[i];
  insertionSort(input,size);
  return 0;
}
