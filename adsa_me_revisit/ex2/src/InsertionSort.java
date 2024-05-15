import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class InsertionSort {
     
    public static final String ANSI_RED = "\u001B[31m";
    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_GREEN = "\u001B[32m";

    public static void swapElementsOnArray(int[] inputArray,int indexOne, int indexTwo)
    {
        int temp = inputArray[indexOne];
        inputArray[indexOne] = inputArray[indexTwo];
        inputArray[indexTwo] = temp;
    }


    public static void printIntermediate(int[] inputArray, int indexOne,int indexTwo, String consoleColString){
       
        for(int index=0;index<inputArray.length;index++){
            if(index==indexOne){
                if(consoleColString=="RED")
                    System.out.print(ANSI_RED+inputArray[index]+" "+ANSI_RESET);
                else
                    System.out.print(ANSI_GREEN+inputArray[index]+" "+ANSI_RESET);
            }
            else if(index == indexTwo)
            {
                if(consoleColString=="GREEN")
                    System.out.print(ANSI_GREEN+inputArray[index]+" "+ANSI_RESET);
                else
                    System.out.print(ANSI_RED+inputArray[index]+" "+ANSI_RESET);
            }
            else
                System.out.print(inputArray[index]+" ");
        }  
        System.out.println("");
    }
    

    public static void insertionSort(int[] inputArray){
        int start=1;
        int slideIndex=0; 
        
        while(start<inputArray.length)
        {
            slideIndex=start;
            while(slideIndex>0 && inputArray[slideIndex-1] > inputArray[slideIndex])
            {
                printIntermediate(inputArray,slideIndex-1,slideIndex,"RED");
                swapElementsOnArray(inputArray,slideIndex,slideIndex-1);
                printIntermediate(inputArray,slideIndex-1,slideIndex,"GREEN");
                slideIndex= slideIndex-1;
            }

            start+=1;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bin = new BufferedReader(new InputStreamReader(System.in));
        int[] inputArray = Arrays.stream(bin.readLine().split("\\s+")).mapToInt(Integer::parseInt).toArray();
        insertionSort(inputArray);
        System.out.println(Arrays.toString(inputArray));
    }
}
