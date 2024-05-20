
/*
 * h-sorting array
 * How to h-sort an array
 * We use insertion sort and go h-back every stride
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class ShellSort {
    

public static void exchange(int[]inputArray,int indexOne, int indexAnother)
{
    int temp = inputArray[indexOne];
    inputArray[indexOne] = inputArray[indexAnother];
    inputArray[indexAnother] = temp;
}

/*  h-sorted array approach selecting h as => 3h+1 where h's starting value is 1
 * Adaptive insertion sort with sliding back every h-indexes and sorting the elements by h-sorting strides. 
 * 
 * 
 */
  public static void shellSort(int[] inputArray)
  {
    int h=1; 
    while(h<inputArray.length/3)
        h= 3*h+1;
    while(h>=1)
    {
        for(int i=h;i<inputArray.length;i++)
        {
            for(int j=i;j>=h && inputArray[j-h]> inputArray[j];j-=h)
                exchange(inputArray, j, j-h);
        }
        h=h/3;
    }
    
  }


    public static void main(String[] args) throws IOException {
        BufferedReader bin = new BufferedReader(new InputStreamReader(System.in));
        int[] inputArray = Arrays.stream(bin.readLine().split("\\s+")).mapToInt(Integer::parseInt).toArray();
        shellSort(inputArray);
        System.out.println(Arrays.toString(inputArray));
    }
}
