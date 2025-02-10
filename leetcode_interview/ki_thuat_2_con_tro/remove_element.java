package ki_thuat_2_con_tro;

import java.util.Arrays;

public class remove_element {

    public static int remove(int[] a , int x) {
        int k = 0;
        for(int i = 0 ; i < a.length; i++){
            if(a[i] != x){
                a[k] = a [i];
                k++;
            }
        }
        return  k;
    }

   // cách khác không dùng 2 còn trỏ :

    public static int remove2(int[] a , int x) {
        int n = a.length;
        for(int i = 0 ; i <n; i++){
            if(a[i] == x){
                for(int j = i ; j <= n - 2; ){ // do phan tu n-1 khong doi duoc cho phan tu nao nua
                    a[j] = a[j + 1];
                }
                n--;
            } else {
                i++;
            }


        }
        return -1;
    }

    public static void main(String[] args) {
        int[] a = {1,2,3,2,3,4};
        int newLength = remove(a, 2);

        System.out.println("New length: " + newLength);
        System.out.println("Modified array: " + Arrays.toString(Arrays.copyOf(a, newLength)));
    }
}
