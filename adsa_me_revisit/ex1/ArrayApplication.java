import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import java.util.List;
public class ArrayApplication{


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
        List<Integer> resultList = linearSearch(dataOne,inputArray);
        System.out.println(resultList);

    }
}