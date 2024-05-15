import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class MergeSort {
    
    public static final String ANSI_RED = "\u001B[31m";
    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_GREEN = "\u001B[32m";

    public static int[] mergedTwoSortedArr(int[]firstHalf,int[] secondHalf)
    {   
        int[] sorted = new int[firstHalf.length + secondHalf.length];

        int i = 0;
		int j = 0;
		int k = 0;
        while (i < firstHalf.length && j < secondHalf.length) {

			if (firstHalf[i] < secondHalf[j]) {
          		sorted[k] = firstHalf[i];
				k++;
				i++;
			} else {
                /*Print Intermediate Iteration */
          		
				sorted[k] = secondHalf[j];
				k++;
				j++;
			}
		}

		if (i == firstHalf.length) {

			while (j < secondHalf.length) {
                /*Print Intermediate Iteration */
				sorted[k] = secondHalf[j];
				k++;
				j++;
			}
		}

		if (j == secondHalf.length) {

			while (i <firstHalf.length) {
                /*Print Intermediate Iteration */
				sorted[k] = firstHalf[i];
				k++;
				i++;
			}
		}

        return sorted;
    }

    public static int[] mergeSort(int[] inputUnSrtedArr, int loIndex, int hiIndex)
    {
        if(loIndex == hiIndex)
        {
            int[] br = new int[1];
            br[0] = inputUnSrtedArr[loIndex];
            return br;
        }

        int middle = (loIndex+hiIndex)/2;
        int [] firstHalf = mergeSort(inputUnSrtedArr, loIndex, middle);
        int[] secondHalf = mergeSort(inputUnSrtedArr, middle+1, hiIndex);
        System.out.print("First Half:--  "+ Arrays.toString(firstHalf));
        System.out.print("\t\t");
        System.out.print("Second Half:--  "+Arrays.toString(secondHalf));
        System.out.println();
      
        int[] mergedArr = mergedTwoSortedArr(firstHalf,secondHalf);
        return mergedArr;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bin = new BufferedReader(new InputStreamReader(System.in));
        int[] inputUnSortedArr = Arrays.stream(bin.readLine().split("\\s+")).mapToInt(Integer::parseInt).toArray();
        int[]sortedArray = mergeSort(inputUnSortedArr, 0,inputUnSortedArr.length-1);
        System.out.println(Arrays.toString(sortedArray));
    }
}
