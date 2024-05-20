import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class SelectionSort {
    

    public static void exchange(int[] inputArray,int indexOne,int indexTwo)
    {
        int temp = inputArray[indexOne];
        inputArray[indexOne]=inputArray[indexTwo];
        inputArray[indexTwo] =temp;
    }

    public static void selectionSort(int[] inputArray)
    {
       
        for(int i=0;i<inputArray.length;i++){
            int minIndex=i;
            for(int j=i+1;j<inputArray.length;j++)
            {
                if(inputArray[j]<inputArray[minIndex])
                    minIndex=j;

            

            }
            exchange(inputArray,i,minIndex );
        }
    }

    public static void main(String[] args) throws IOException

    {
        BufferedReader bin = new BufferedReader(new InputStreamReader(System.in));
        int[] inputArray = Arrays.stream(bin.readLine().split("\\s+")).mapToInt(Integer::parseInt).toArray();
        selectionSort(inputArray);
        System.out.println("After sorting in ascending order:");
        System.out.print(Arrays.toString(inputArray));
    }
}
