package codePtit_java_core;

import java.util.List;
import java.util.Scanner;
import java.util.LinkedList;

public class tim_kiem_phan_tu_nho_thu2_trong_mang {
    // Cách không dùng sắp xếp:

    public static double timMinThuHai(List<Integer> a, int n) {
        double smallest = Double.MAX_VALUE;
        double secondSmallest = Double.MAX_VALUE;

        // Tìm phần tử nhỏ nhất
        for (int i = 0; i < n; i++) {
            if (a.get(i) < smallest) {
                smallest = a.get(i);
            }
        }

        // Tìm phần tử nhỏ thứ 2
        for (int i = 0; i < n; i++) {
            if (a.get(i) != smallest && a.get(i) < secondSmallest) {
                secondSmallest = a.get(i);
            }
        }

        // Nếu không tìm được phần tử nhỏ thứ 2
        if (secondSmallest == Double.MAX_VALUE) {
            System.out.println("Không có phần tử nhỏ thứ 2 trong mảng.");
            return -1;
        }

        return secondSmallest;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Nhập số phần tử của mảng
        System.out.print("Nhập số phần tử của mảng: ");
        int n = scanner.nextInt();

        // Khởi tạo List để lưu các phần tử
        List<Integer> a = new LinkedList<>();

        // Nhập các phần tử vào mảng
        System.out.println("Nhập các phần tử của mảng:");
        for (int i = 0; i < n; i++) {
            System.out.print("Phần tử thứ " + (i + 1) + ": ");
            a.add(scanner.nextInt());
        }

        // Tìm phần tử nhỏ thứ 2
        double secondSmallest = timMinThuHai(a, n);

        if (secondSmallest != -1) {
            System.out.println("Phần tử nhỏ thứ 2 trong mảng là: " + secondSmallest);
        }
    }
}
