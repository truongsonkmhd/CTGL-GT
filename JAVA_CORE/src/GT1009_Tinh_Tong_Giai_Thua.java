import java.util.Scanner;

public class GT1009_Tinh_Tong_Giai_Thua {

    public static Scanner ip = new Scanner(System.in);

    public static void main(String[] args) {
        testCase();
    }

    private static void testCase() {
        long tmp = 1,res = 0;
        long n = ip.nextLong();
        for (int i = 1 ; i<= n ; i++){
            tmp *= i;
            res += tmp;
        }
        System.out.println("Tong giai thua la: ");
        System.out.println(res);
    }
}
