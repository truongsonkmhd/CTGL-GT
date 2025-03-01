package binary_search_or_linear_search;

public class Solution {
    /*
    * Tìm kiếm tuần tự: Khi mảng nhỏ hoặc không sắp xếp.
    Tìm kiếm nhị phân: Khi mảng lớn và đã được sắp xếp, giúp tăng tốc độ tìm kiếm đáng kể.
    👉 Ví dụ thực tế

    Tìm kiếm tuần tự: Tìm số điện thoại trong danh bạ ngẫu nhiên.
    Tìm kiếm nhị phân: Tìm từ trong từ điển (vì đã sắp xếp theo bảng chữ cái).
🚀 Kết luận: Tìm kiếm nhị phân nhanh hơn nhiều trên dữ liệu lớn, nhưng cần mảng*/
    // độ phức tạp : O(n) // bộ nhớ sử dụng : O(1) (chỉ dùng một biến để so sánh)
    public static int lSearch(int[] a, int key){
        //Áp dụng thực tế	Khi dữ liệu nhỏ hoặc chưa sắp xếp.
        int i = 0;
        while (i < a.length){
            if(a[i] == key){
                return i;
            }
        }
        return -1;
    }
    public static int search(int[] a, int key) {
        int n = a.length;
        return bSearch(a, key, 0, n - 1); // right phải là n - 1
    }

    // cách dùng đệ quy // độ phức tạp : O(log(n)) // bộ nhớ sử dụng : O(1)
    public static int bSearch(int[] a, int key, int left, int right) {
        //Áp dụng thực tế Khi dữ liệu lớn và đã được sắp xếp trước.

        if (left > right) {
            return -1;
        }
        System.out.println("Searching key: " + key + " in range [" + left + ", " + right + "]");

        int iMid = (right + left) / 2; // Tránh tràn số

        if (key == a[iMid]) {
            return iMid;
        } else if (key < a[iMid]) {
            return bSearch(a, key, left, iMid - 1); // Giới hạn right đúng
        } else {
            return bSearch(a, key, iMid + 1, right); // Giới hạn left đúng
        }
    }

    // cách dùng vòng lặp // độ phức tạp : O(log(n)) // bộ nhớ sử dụng : O(1)
    public static int bSearch2(int[] a, int key, int iLeft, int iRight){
        int idMid = (iRight + iLeft) / 2;
        while (iLeft <= iRight){
            if (key == a[idMid]){
                return idMid;
            } else if(key > a[idMid]){
                iLeft = idMid + 1;
            } else if(key < a[idMid]){
                iRight = idMid - 1;
            }
        }
         return  -1;
    }
    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5, 6, 7};
        System.out.println("Index of 5: " + search(nums, 5)); // Output: 4
    }
}
