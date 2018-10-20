#include<iostream>
#define MAX_SIZE 30
using namespace std;

/*merge algorithm -> using a temporary array to place the subsequences minimum
 *of input[0..middle] and input[middle+1 ...end] post comparision in appropriate * position. temp[] array contents are copied back to input[] 
 */
void merge(int input[],int temp[],int start,int middle,int end)
{
  int i=start,j=middle+1,k;
  for(k=start;k<=end;k++)
    {
      if(i>middle)
	temp[k]=input[j++];
      else if(j>end)
	temp[k]=input[i++];
      else if(input[i]<input[j])
	temp[k]=input[i++];
      else
	temp[k]=input[j++];
    }
  for(int i=start;i<=end;i++)
    {
      input[i]=temp[i];
    }
  
}


/* mergeSort algorithm -> partition the n-element sequence to be sorted into 
 *two subsequences of n/2 elements each and sort the two subsequence recursively
 *using mergesort.
 *
 */

void mergeSort(int input[],int temp[],int start,int end)
{
   if(end<=start) 
     {
       return;
     }
      int middle=start+(end-start)/2;
      mergeSort(input,temp,start,middle);
      mergeSort(input,temp,middle+1,end);
      merge(input,temp,start,middle,end);
}

int main()
{
  int input[MAX_SIZE],temp[MAX_SIZE],size;
  cout<<"Enter the number of elements in sequence"<<endl;
  cin>>size;
  cout<<"Enter the elements in sequence:"<<endl;
  for(int i=0;i<size;i++)
    cin>>input[i];
  mergeSort(input,temp,0,size-1);
  cout<<"Elements in sorted sequence is:"<<endl;
  for(int i=0;i<size;i++)
    cout<<input[i]<<"  ";
  return 0;
}
