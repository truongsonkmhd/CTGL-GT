package Map;

import java.util.HashMap;
import java.util.Map;

public class FirstUniqueCharacterInAString {
    public int firstUniqChar(String s) {

        Map<Character,Integer> myCountMap = new HashMap<>();

        for(int i = 0 ; i < s.length(); i++) {
            char c  = s.charAt(i);
            if(!myCountMap.containsKey(c)){
                myCountMap.put(c,1);
            } else {
                myCountMap.put(c , myCountMap.get(c) + 1);
            }
        }

        for(int i = 0 ; i < s.length() ; i++){
            char c = s.charAt(i);
            if(myCountMap.get(c) == 1) {
                return i;
            }
        }
        return -1;
    }

    public int firstUniqCharV2(String s) {

        Map<Character,Integer> map = new HashMap<>();

        char[] cha =  s.toCharArray();
        for(char c : cha){
            map.put(c,map.getOrDefault(c,0) + 1); // dung ham nay ko phai tao gia tri ban dau
        }
        for(int i = 0 ; i < s.length() ; i++){
            char c = s.charAt(i);
            if(map.get(c) == 1) {
                return i;
            }
        }
        return -1;
    }
}
