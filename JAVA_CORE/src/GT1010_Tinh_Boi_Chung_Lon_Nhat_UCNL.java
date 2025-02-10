import java.util.Scanner;

public class GT1010_Tinh_Boi_Chung_Lon_Nhat_UCNL {
    public static Scanner ip = new Scanner(System.in);

    public static long gcd(long a, long b) {
        while (b != 0) {
            long x = a % b;
            a = b;
            b = x;
        }
        return a;
    }

    public static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    public static void testCase() {
        int a = ip.nextInt();
        int b = ip.nextInt();
        System.out.println(lcm(a, b) + " " + gcd(a, b));
    }

    public static void main(String[] args) {
        int T = ip.nextInt();
        while (T-- > 0) {
            testCase();
        }
    }
}
