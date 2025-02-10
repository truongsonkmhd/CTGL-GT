import java.util.Scanner;

public class GT1007_Kiem_Tra_Fibonacci {
    // kiem tra n nhap vao co phai la Fibonacci ko?
    /*
    * Dòng đầu tiên đưa vào số lượng bộ test T.
    Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số nguyên dương n.
    T, n thỏa mãn ràng buộc :1 ≤ T ≤ 100; 0≤n≤1018.*/
    public static Scanner ip = new Scanner(System.in);
    public static long[] fibo = new long[100];

    public static void prepareData(){
        fibo[0]= 0;
        fibo[1]= 1;
        for (int i = 2; i < 100 ; i++){
            fibo[i] = fibo[i-2] + fibo[i - 1];
        }
    }

    public static boolean isFibo(long n) {
        for (long i : fibo) {
            if (i == n) {
                return true;
            } else if (i > n) { // vì dãy fibo luôn số sau luôn lớn hơn , nên không có trường hợp  i < n
                return false;
            }
        }
        return false;
    }
    public static void testCase(){
        long n = ip.nextLong();
        if (isFibo(n)){
            System.out.println("YES");
        } else {
            System.out.println("No");
        }
    }

    public static void main(String[] args) {
        prepareData();
        int T = ip.nextInt();
        while (T-->0){
            testCase();
        }
    }
}
