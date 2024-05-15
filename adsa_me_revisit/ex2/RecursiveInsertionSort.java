package ex2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class RecursiveInsertionSort {
    

    public static void insertionSort(int[] inputArray, int n)
    {
        if(n>0)
        {   
            insertionSort(inputArray, n-1);
            int x = inputArray[n];
            int j = n-1;
            while(j>=0 && inputArray[j]>x)
            {
                inputArray[j+1] = inputArray[j];
                j = j-1;
            }
            inputArray[j+1] = x;
        }
    }
    public static void main(String[] args) throws IOException {
         BufferedReader bin = new BufferedReader(new InputStreamReader(System.in));
        int[] inputArray = Arrays.stream(bin.readLine().split("\\s+")).mapToInt(Integer::parseInt).toArray();
        insertionSort(inputArray,inputArray.length-1);
        System.out.println(Arrays.toString(inputArray));
       
    }
}
