package Set;

import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.TreeSet;

public class SET {
    public static void main(String[] args) {
        Set<Integer> myIntSet =  new HashSet<>();
        Set<Integer> myIntSet1 =  new TreeSet<>();
        Set<Integer> myIntSet2 =  new LinkedHashSet<>();

        myIntSet2.add(1);
        myIntSet2.add(4);
        myIntSet2.add(5);
        myIntSet2.add(2);

         for (Integer integer: myIntSet2){
             System.out.println(integer);
         }
    }
}
