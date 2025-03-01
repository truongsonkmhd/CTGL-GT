package Map.practive;

import java.util.*;

public class Sap_dat_day_so {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt(); // Số lượng test case

        while (T-- > 0) {
            int n = sc.nextInt(); // Số phần tử trong mảng
            int[] arr = new int[n];
            HashSet<Integer> seen = new HashSet<>();

            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            List<Integer> result = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                if (!seen.contains(arr[i])) {
                    result.add(arr[i]);
                    seen.add(arr[i]);
                } else {
                    result.add(-1);
                }
            }

            for (int num : result) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
