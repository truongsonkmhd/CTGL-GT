package list_arraylist_c_cong_cong;
/*
Bạn được cho hai mảng số nguyên nums1và nums2, được sắp xếp theo thứ tự không giảm ,
và hai số nguyên mvà n, biểu thị số phần tử trong nums1và nums2tương ứng.
Hợp nhất nums1 và nums2thành một mảng duy nhất được sắp xếp theo thứ tự không giảm .

Ví dụ 1:

Đầu vào: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 Đầu ra: [1,2,2,3,5,6]
 Giải thích: Các mảng chúng ta đang hợp nhất là [1,2,3] và [2,5,6]. 
Kết quả của việc hợp nhất là [ 1 , 2 ,2, 3 ,5,6] với các phần tử được gạch chân đến từ nums1.
Ví dụ 2:

Đầu vào: nums1 = [1], m = 1, nums2 = [], n = 0
 Đầu ra: [1]
 Giải thích: Các mảng chúng ta đang hợp nhất là [1] và []. 
Kết quả của việc hợp nhất là [1].
Ví dụ 3:

Đầu vào: nums1 = [0], m = 0, nums2 = [1], n = 1
 Đầu ra: [1]
 Giải thích: Các mảng chúng ta đang hợp nhất là [] và [1]. 
Kết quả của việc hợp nhất là [1]. 
Lưu ý rằng vì m = 0 nên không có phần tử nào trong nums1. Số 0 chỉ ở đó để đảm bảo kết quả hợp nhất có thể vừa với nums1.
 
 */

 import java.util.Arrays;

 public class MergeSortedArrays {
     public static void merge(int[] nums1, int m, int[] nums2, int n) {
         int i = m - 1; // con trỏ cho nums1
         int j = n - 1; // con trỏ cho nums2
         int k = m + n - 1; // con trỏ cho vị trí cuối cùng của nums1
 
         // So sánh từ cuối các phần tử trong nums1 và nums2, rồi chèn phần tử lớn hơn vào cuối nums1
         while (j >= 0 && i >= 0) {
             if (nums1[i] > nums2[j]) {
                 nums1[k] = nums1[i];
                 i--; k--;
             } else {
                 nums1[k] = nums2[j];
                 j--; k--;
             }
         }
         while(j>=0){
            nums1[k] = nums2[j];
            j--; k--;
         }
     }
 
     public static void mergeVer2(int[] nums1, int m , int[] nums2 , int n){
         for(int j = 0, i = m; j < n ; j++ ){
             nums1[i] = nums2[j];
             i++;
         }
         Arrays.sort(nums1);
 
     }
 
     public static void main(String[] args) {
         int[] nums1 = {1,2,3,0,0,0};
         int m = 3;
         int[] nums2 = {5,8,3};
         int n = 3;
 
         merge(nums1, m, nums2, n);
 
         // In kết quả
         for (int num : nums1) {
             System.out.print(num + " ");
         }
     }
 }
 