package trenlop;

import java.util.Scanner;

import static trenlop.QLSV.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("\n--- QUẢN LÝ SINH VIÊN ---");
            System.out.println("1. Nhập danh sách sinh viên");
            System.out.println("2. Xuất danh sách sinh viên");
            System.out.println("3. Tìm sinh viên theo mã SV");
            System.out.println("4. Cập nhật thông tin sinh viên");
            System.out.println("5. Xóa sinh viên theo CMND");
            System.out.println("6. Sắp xếp danh sách theo họ tên giảm dần");
            System.out.println("0. Thoát");
            System.out.print("Chọn chức năng: ");
            int choice = Integer.parseInt(sc.nextLine());

            switch (choice) {
                case 1 -> nhapSinhVien();
                case 2 -> xuatSinhVien();
                case 3 -> timSinhVien();
                case 4 -> capNhatSinhVien();
                case 5 -> xoaSinhVien();
                case 6 -> sapXepSinhVien();
                case 0 -> System.exit(0);
                default -> System.out.println("Lựa chọn không hợp lệ!");
            }
        }
    }

}
