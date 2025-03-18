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
public class TheMuon {
    private int soPhieuMuon;
    private String ngayMuon;
    private String hanTra;
    private int soHieuSach;
    private SinhVien sinhVien;

    public TheMuon() {
    }

    public TheMuon(int soPhieuMuon, String ngayMuon, String hanTra, int soHieuSach, SinhVien sinhVien) {
        this.soPhieuMuon = soPhieuMuon;
        this.ngayMuon = ngayMuon;
        this.hanTra = hanTra;
        this.soHieuSach = soHieuSach;
        this.sinhVien = sinhVien;
    }

    public int getSoPhieuMuon() {
        return soPhieuMuon;
    }

    public String getNgayMuon() {
        return ngayMuon;
    }

    public String getHanTra() {
        return hanTra;
    }

    public int getSoHieuSach() {
        return soHieuSach;
    }

    public SinhVien getSinhVien() {
        return sinhVien;
    }

    public void setSoPhieuMuon(int soPhieuMuon) {
        this.soPhieuMuon = soPhieuMuon;
    }

    public void setNgayMuon(String ngayMuon) {
        this.ngayMuon = ngayMuon;
    }

    public void setHanTra(String hanTra) {
        this.hanTra = hanTra;
    }

    public void setSoHieuSach(int soHieuSach) {
        this.soHieuSach = soHieuSach;
    }

    public void setSinhVien(SinhVien sinhVien) {
        this.sinhVien = sinhVien;
    }
    
    
    public void nhapThongTin(Scanner scanner){
        System.out.print("Nhap so phieu muon: ");
        soPhieuMuon =Integer.parseInt(scanner.nextLine());
        System.out.print("Nhap ngay muon: ");
        ngayMuon = scanner.nextLine();
        System.out.print("Nhap han Tra: ");
        hanTra = scanner.nextLine();
        System.out.print("Nhap so Hieu Sach : ");
        soHieuSach = Integer.parseInt(scanner.nextLine());
        System.out.println("Nhap thong tin sinh vien: ");
        sinhVien = new SinhVien();
        sinhVien.nhapThongTin(scanner);
               
    }
    
    public void hienThiThongTin(){
        System.out.println("So phieu muon: "+ soPhieuMuon);
        System.out.println("Ngay muon: " + ngayMuon);
        System.out.println("Han tra: " + hanTra);
        System.out.println("So hieu sach: " + soHieuSach);
        System.out.println("Thong tin sinh vien");
         sinhVien.hienThiThongTin();
    }
    
    
    
}
