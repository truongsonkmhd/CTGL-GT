package Array;

import java.lang.reflect.Array;
import java.util.Arrays;

public class Third_Maximum_Number {

    //way 1:
    //1.xây dựng 1 mảng maxArr tăng dần luôn lưu 4 phần tử lớn nhất.
    // -> sử dụng kĩ thuật sắp xếp chèn(inserttion sort)
    //2. Trả về kết quả chỉ cần xét mảng maxArr
    public static void printArr(long[] arr) {
        for (long num : arr) {
            System.out.print(num + ", ");
        }
        System.out.println();
    }

    public static void insert(long[] maxArr, int val) {
        for (int i = 0; i < maxArr.length; i++) {
            if (val == maxArr[i]) { // Ignore duplicates
                return;
            } else if (val > maxArr[i]) { // Insert value in correct position
                for (int j = maxArr.length - 1; j > i; j--) {
                    maxArr[j] = maxArr[j - 1];
                }
                maxArr[i] = val;
                printArr(maxArr);
                break;
            }
        }
    }

    public static int thirdMax(int[] a) {
        long[] maxArr = {Long.MIN_VALUE, Long.MIN_VALUE, Long.MIN_VALUE};

        for (int num : a) {
            insert(maxArr, num);
        }

        return (maxArr[2] == Long.MIN_VALUE) ? (int) maxArr[0] : (int) maxArr[2];
    }

    //way2 :
    public static int thirdMaxV2(int[] nums){
            Arrays.sort(nums);
            int n = nums.length;
            int count = 1;
            if (nums.length > 2) {
                for (int i = n - 1; i > 0; i--) {
                    if (nums[i] != nums[i - 1]) {
                        count++;
                    }
                    if (count == 3) {
                        return nums[i - 1];
                    }
                }
            }

            return nums[n - 1];
    }

    public static void main(String[] args) {
        int[] ar = {2, 2, 4, 1,3,7};
        System.out.println(thirdMax(ar)); // Output: 1
    }
}
