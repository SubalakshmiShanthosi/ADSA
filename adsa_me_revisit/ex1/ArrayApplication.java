package src;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class ArrayApplication {
    public static int linearSearch(List<Integer> inputArray, int start, int dataOne)
    {
        int index= IntStream.range(start, inputArray.size()).filter(i -> Integer.valueOf(dataOne).equals(Integer.valueOf(inputArray.get(i)))).findFirst().orElse(-1);
        return index;
    }


    public static void insertmiddle(List<Integer> inputArray,int data, int after)
    {
        inputArray.add(after+1,data);
    }


    public static void insertafterdata(List<Integer> inputArray, int dataOne, int dataTwo, int start){
       int temp=0;
       int size = inputArray.size()+1;
       while(start< size)
       {
        int incidenceIndex = linearSearch(inputArray, start, dataOne);
        System.out.println("incIndex: "+incidenceIndex);
        if(inputArray.get(incidenceIndex)== dataOne && incidenceIndex !=-1)
            {
                insertmiddle(inputArray, dataTwo, incidenceIndex);
                start+=2;
            }
        else{
            temp+=1;
            start+=1;
        }
       }
       if(temp==size){
        System.out.println("Key is not found in sequence");
       }
         
    }


    static <T> List<Integer> linearSearch(T obj, List<T> list) {
    final List<Integer> indexList = new ArrayList<>();
    for (int i = 0; i < list.size(); i++) {
        if (obj.equals(list.get(i))) {
            indexList.add(i);
        }

    }
    if(indexList.size()==0)
    {
        indexList.add(-1);
    }
    return indexList;
}




   
    public static void main(String args[]) throws IOException
    {
        BufferedReader inStReader = new BufferedReader(new InputStreamReader(System.in));
        List<Integer> inputArray = Stream.of(inStReader.readLine().split("\\s+")).map(Integer::valueOf).collect(Collectors.toList());
        int dataOne = inputArray.get(inputArray.size()-2);
        int dataTwo = inputArray.get(inputArray.size()-1);
        inputArray = inputArray.stream().limit(inputArray.size()-2).collect(Collectors.toList());
        insertafterdata(inputArray, dataOne, dataTwo, 0);
        System.out.println(inputArray.toString());
}
}
