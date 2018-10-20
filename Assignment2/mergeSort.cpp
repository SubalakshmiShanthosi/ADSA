#include<iostream>
#define MAX_SIZE 30
using namespace std;


/*printIntermediateIter -> prints altered elements in input[] on recursive calls
 *of merge highlighted in different colour
 */
void printIntermediateIter(int input[],int start,int middle,int end,int size)
{
  int i;
  cout<<"\nmerge("<<start<<","<<middle<<","<<end<<") ";
  for(i=0;i<start-1;i++)
    cout<<input[i]<<" ";
  for(i=start;i<=end;i++)
    cout<<"\x1b[35m"<<input[i]<<"\x1b[0m"<<" ";
  for(i=end+1;i<size;i++)
    cout<<input[i]<<" ";
}

/*merge algorithm -> using a temporary array to place the subsequences minimum
 *of input[0..middle] and input[middle+1 ...end] post comparision in appropriate
 * position. temp[] array contents are copied back to input[] 
 */
void merge(int input[],int start,int middle,int end,int size)
{
  int i=start,j=middle+1,k;
  int temp[size];
  for(k=start;k<=end;k++)
    temp[k]=input[k];
  for(k=start;k<=end;k++)
    {
      if(i>middle)
	input[k]=temp[j++];
      else if(j>end)
	input[k]=temp[i++];
      else if(temp[i]<temp[j])
	input[k]=temp[i++];
      else
	input[k]=temp[j++];
    }
  printIntermediateIter(input,start,middle,end,size);
}


/* mergeSort algorithm -> partition the n-element sequence to be sorted into 
 *two subsequences of n/2 elements each and sort the two subsequence recursively
 *using mergesort.
 *
 */

void mergeSort(int input[],int start,int end,int size)
{
   if(end<=start) 
     {
       return;
     }
      int middle=start+(end-start)/2;
      mergeSort(input,start,middle,size);
      mergeSort(input,middle+1,end,size);
      merge(input,start,middle,end,size);
}

int main()
{
  int input[MAX_SIZE],size;
  cout<<"Enter the number of elements in sequence"<<endl;
  cin>>size;
  cout<<"Enter the elements in sequence:"<<endl;
  for(int i=0;i<size;i++)
    cin>>input[i];
  mergeSort(input,0,size-1,size);
  cout<<"\nElements in sorted sequence is:"<<endl;
  for(int i=0;i<size;i++)
    cout<<input[i]<<"  ";
  cout<<"\n";
  return 0;
}
