package Map;


import java.util.HashMap;
import java.util.Map;

public class Practive {
    public static void main(String[] args) {
        int[] arr =  {1,2,3,1,1,2};
        Map<Integer,Integer> myMap = new HashMap<>();
        for(int i : arr){
            if(!myMap.containsKey(i)){
                // i chua xuat hien trong map
                myMap.put(i,1);
            } else {
                // i da xuat hien truoc do
                int soLanXuatHien = myMap.get(i);
                soLanXuatHien++;
                myMap.put(i,soLanXuatHien);
            }
        }

        for (Map.Entry entry :  myMap.entrySet()){
            System.out.println(entry.getKey() + ":" + entry.getValue());
        }
    }

}
