package codePtit_java_core;
import java.util.Scanner;

public class GT1013_Tong_Uoc_So_Nguyen {

        public static int sumPrimeFactors(int n) {
            int sum = 0;
            for (int i = 2; i <= Math.sqrt(n); i++) {
                while (n % i == 0) { // Nếu i là xước nguyên tố của n
                    sum += i; // Cộng i vào tổng
                    n /= i; // Giảm n đi
                }
            }
            // Nếu n còn lại là số nguyên tố
            if (n > 1) {
                sum += n;
            }
            return sum;
        }

        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Nhập số N: ");
            int N = scanner.nextInt();

            int totalSum = 0;
            System.out.println("Nhập dãy các số nguyên:");
            for (int i = 0; i < N; i++) {
                int num = scanner.nextInt();  // Nhập từng số trong dãy
                totalSum += sumPrimeFactors(num);  // Cộng tổng các thừa số nguyên tố
            }

            System.out.println("Tổng các thừa số nguyên tố là: " + totalSum);
        }

}
