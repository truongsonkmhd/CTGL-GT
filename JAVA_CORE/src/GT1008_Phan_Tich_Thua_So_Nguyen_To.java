import java.util.Scanner;

    public class GT1008_Phan_Tich_Thua_So_Nguyen_To {
        public static Scanner ip = new Scanner(System.in);

        /*
        *
    3

    60                      Test 1: 2(2) 3(1) 5(1)

    128                     Test 2: 2(7)

    10000                   Test 3: 2(4) 5(4)
    */
        public static void testCase(int t) {
            int N = ip.nextInt();
            int n = N;
            System.out.printf("Test %d: ", t);
            for (int i = 2; i <= Math.sqrt(N); i++) {
                int cnt = 0;
                while (n % i == 0) {
                    cnt++;
                    n /= i;
                }
                if (cnt != 0) {
                    System.out.printf("%d(%d) ", i, cnt);
                }
            }
            if (n != 1) { // truong hop khi n la so nguyen to
                System.out.printf("%d(%d) ", n, 1);
            }

            System.out.println();
        }

        public static void main(String[] args) {
            int T = ip.nextInt();
            for (int i = 1; i <= T; i++) {
                testCase(i);
            }
        }
    }
