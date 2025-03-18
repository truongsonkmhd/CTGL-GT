/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package trenlop.swing.bai_1;

import java.util.Scanner;

/**
 *
 * @author User
 */
public class SinhVien {
    private String maSinhVien;
    private String hoTen;
    private int namSinh;
    private String lop;

    public SinhVien(String maSinhVien, String hoTen, int namSinh, String lop) {
        this.maSinhVien = maSinhVien;
        this.hoTen = hoTen;
        this.namSinh = namSinh;
        this.lop = lop;
    }
    

    public SinhVien() {
    }

    public String getMaSinhVien() {
        return maSinhVien;
    }

    public String getHoTen() {
        return hoTen;
    }

    public int getNamSinh() {
        return namSinh;
    }

    public String getLop() {
        return lop;
    }

    public void setMaSinhVien(String maSinhVien) {
        this.maSinhVien = maSinhVien;
    }

    public void setHoTen(String hoTen) {
        this.hoTen = hoTen;
    }

    public void setNamSinh(int namSinh) {
        this.namSinh = namSinh;
    }

    public void setLop(String lop) {
        this.lop = lop;
    }

    public void nhapThongTin(Scanner scanner){
        System.out.print("Nhap ma sinh vien: ");
        maSinhVien = scanner.nextLine();
        System.out.print("Nhap ho ten sinh vien: ");
        hoTen = scanner.nextLine();
        System.out.print("Nhap lop: ");
        lop = scanner.nextLine();
        System.out.print("Nhap nam Sinh sinh vien: ");
        namSinh = Integer.parseInt(scanner.nextLine());
    }
    
    public void hienThiThongTin(){
        System.out.println("Ma sinh vien:" + maSinhVien);
        System.out.println("Ho ten :" + hoTen);
        System.out.println("Lop :" + lop);
        System.out.println("Nam sinh :" + namSinh);
    }
    
   
   public void suaThongTin() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhập họ tên mới: ");
        this.hoTen = sc.nextLine();
        System.out.print("Nhập ngày sinh mới : ");
        this.namSinh =Integer.parseInt(sc.nextLine());
        System.out.print("Nhập lop mới: ");
     
    }

  
    
}