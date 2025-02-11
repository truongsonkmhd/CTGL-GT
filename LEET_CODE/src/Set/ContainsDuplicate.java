package Set;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/*Input: nums = [1,2,3,1]
Output: true
Input: nums = [1,2,3,4]
Output: false*/

public class ContainsDuplicate {
    public static boolean containsDuplicate(int[] nums){
        Set<Integer> mySet = new HashSet<>();
        for(int n : nums){
            // way_1:
            if(!mySet.contains(n)){
                mySet.add(n);
            } else {
                return true;
            }
            //way_2:
            /*if(mySet.add(n)){// vi set ko nhan phan tu trung nhau, nen trung se ko add nua
                return true;
            }*/
        }
        return false;
    }

    public static boolean containsDuplicateWay3(int[] nums){
        Arrays.sort(nums);
        int i = 0;
        int n = nums.length - 1;
        while (i < n -1){
            if(nums[i] == nums[i+1]) return true;
            i++;
        }
        return false;
    }

    public static void main(String[] args) {
        int[] nums = {1,2,3,5};
        System.out.println(containsDuplicate(nums));
    }
}
