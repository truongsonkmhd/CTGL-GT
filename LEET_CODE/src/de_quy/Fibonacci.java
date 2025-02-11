package de_quy;

public class Fibonacci {
   // làm kiểu dùng đệ quy
    public static int Fibo(int n){
        // 1.Bai toan cơ so
        if(n <= 2){
            return 1;
        }
        // cong thuc quy nap
        int Fn = Fibo(n - 1) + Fibo(n -  2);
        return Fn;
    }

    // lam kieu dung mang:
    static int[] F = new int[1000];
    public static int Fibo2(int n){
        if(F[n] != 0){
            return F[n];
        }
        System.out.println("Can tinh F["+ n +"]");
        if(n <= 2){
            F[1] = 1;
            F[2] = 2;
            return 1;
        }
        F[n] = Fibo2(n-1) + Fibo2(n-2);
        return F[n];
    }
}
