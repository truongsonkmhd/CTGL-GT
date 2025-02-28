package trenlop;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static trenlop.KiemTraDieuKien.*;


public class QLSV {
    static Scanner sc = new Scanner(System.in);
    static List<SinhVien> students = new ArrayList<>();

    public static void nhapSinhVien() {
        System.out.print("Nhập số lượng sinh viên: ");
        int n = Integer.parseInt(sc.nextLine());

        for (int i = 0; i < n; i++) {
            System.out.println("Nhập thông tin sinh viên thứ " + (i + 1) + ":");

            String masv;
            do{
                System.out.print("Mã SV: ");
                 masv = sc.nextLine();
                if (!validateMsv(masv)) {
                    System.out.println("Mã SV không hợp lệ!");
                }
            }while (!validateMsv(masv));

            String hoTen;
            do{
                System.out.print("Họ tên: ");
                 hoTen = sc.nextLine();
            } while(!validateName(hoTen));


            String email;
            do {
                System.out.print("Email: ");
                email = sc.nextLine();
                if (!validateEmail(email)) {
                    System.out.println("Email không hợp lệ!");
                }
            } while (!validateEmail(email));

            String soDT;
            do {
                System.out.print("Số điện thoại: ");
                soDT = sc.nextLine();
                if (!validatePhone(soDT)) {
                    System.out.println("Số điện thoại không hợp lệ!");
                }
            } while (!validatePhone(soDT));

            String cmnd;
            do {
                System.out.print("CMND/CCCD: ");
                cmnd = sc.nextLine();
                if (!validateCMND(cmnd)) {
                    System.out.println("CMND/CCCD không hợp lệ!");
                }
            } while (!validateCMND(cmnd));

            students.add(new SinhVien(masv, hoTen, email, soDT, cmnd));
        }
    }

    public static void xuatSinhVien() {
        for (SinhVien sv : students) {
            System.out.println(sv);
        }
    }

    public static void timSinhVien() {
        System.out.print("Nhập mã sinh viên cần tìm: ");
        String masv = sc.nextLine();
        for (SinhVien sv : students) {
            if (sv.masv.equals(masv)) {
                System.out.println("Tìm thấy: " + sv);
                return;
            }
        }
        System.out.println("Không tìm thấy sinh viên!");
    }

    public static void xoaSinhVien() {
        System.out.print("Nhập CMND của sinh viên cần xóa: ");
        String cmnd = sc.nextLine();
        students.removeIf(sv -> sv.cmnd.equals(cmnd));
        System.out.println("Xóa thành công!");
    }

    public static void capNhatSinhVien() {
        System.out.print("Nhập mã sinh viên cần cập nhật: ");
        String masv = sc.nextLine();
        for (SinhVien sv : students) {
            if (sv.masv.equals(masv)) {
                System.out.print("Nhập họ tên mới: ");
                sv.hoTen = sc.nextLine();
                System.out.print("Nhập email mới: ");
                sv.email = sc.nextLine();
                System.out.print("Nhập SĐT mới: ");
                sv.soDT = sc.nextLine();
                System.out.print("Nhập CMND mới: ");
                sv.cmnd = sc.nextLine();
                System.out.println("Cập nhật thành công!");
                return;
            }
        }
        System.out.println("Không tìm thấy sinh viên!");
    }

    public static void sapXepSinhVien() {
        //c1
       // mergeSort(students, 0, students.size() - 1);
        //c2
        students.sort((s1, s2) -> s2.hoTen.compareToIgnoreCase(s1.hoTen));

        System.out.println("Danh sách sau khi sắp xếp:");
        xuatSinhVien();
    }

    public static void mergeSort(List<SinhVien> list, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(list, left, mid);
            mergeSort(list, mid + 1, right);
            merge(list, left, mid, right);
        }
    }

    public static void merge(List<SinhVien> list, int left, int mid, int right) {
        List<SinhVien> leftList = new ArrayList<>(list.subList(left, mid + 1));
        List<SinhVien> rightList = new ArrayList<>(list.subList(mid + 1, right + 1));
        int i = 0, j = 0, k = left;
        while (i < leftList.size() && j < rightList.size()) {
            if (leftList.get(i).hoTen.compareToIgnoreCase(rightList.get(j).hoTen) >= 0) {
                list.set(k++, leftList.get(i++));
            } else {
                list.set(k++, rightList.get(j++));
            }
        }
        while (i < leftList.size()) list.set(k++, leftList.get(i++));
        while (j < rightList.size()) list.set(k++, rightList.get(j++));
    }
}