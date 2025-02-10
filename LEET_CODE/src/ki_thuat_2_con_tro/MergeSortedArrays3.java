package ki_thuat_2_con_tro;
// de bai
/*
 * input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * output [1,2,3,4,5,6]
 * */

import java.util.Arrays;

public class MergeSortedArrays3 {
    public static void meger(int[] nums1, int m , int[] nums2 , int n) {
        int i = m - 1;
        int j = n - 1;
        int k = (m + n) - 1;

        while (k >= 0) {
            if (j < 0) {
                nums1[k] = nums1[i];
                i--;
            } else if (i < 0) {
                nums1[k] = nums2[j];
                j--;
            } else if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

    }

    public static void main(String[] args) {
        int[] n1 = {1, 2, 3, 0, 0, 0};
        int[] n2 = {2, 5, 6};

        meger(n1, 3, n2, 3);
        System.out.println(Arrays.toString(n1)); // Output: [1, 2, 2, 3, 5, 6]
    }
}
