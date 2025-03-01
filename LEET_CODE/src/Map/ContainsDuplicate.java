package Map;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

/*
[1,2,3,1] -> true
[1,2,3,4] -> false
[1,1,1,3,3,4,3,2,4,2] -> true
*/
public class ContainsDuplicate {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer,Integer> component = new HashMap<>();

        for (int num : nums) {
            if (component.containsKey(num)) {
                return true;
            }
            component.put(num, 1);
        }

        return false;
    }
    // c2 dùng set

    public boolean containsDuplicateUseSet(int[] nums){
        Set<Integer> set = new HashSet<>();

        for(int num : nums){
            if(set.contains(num)){
                return true;
            }
            set.add(num);
        }
        return false;
    }

    public static void main(String[] args) {
        ContainsDuplicate containsDuplicate = new ContainsDuplicate();
        int[] nums = {1,2,3,4};
        System.out.println(containsDuplicate.containsDuplicate(nums));
    }
}
