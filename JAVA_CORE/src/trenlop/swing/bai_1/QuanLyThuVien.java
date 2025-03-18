/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package trenlop.swing.bai_1;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author User
 */
public class QuanLyThuVien {
    
    
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<TheMuon>  dsTheMuon = new ArrayList<>();
        
        System.err.print("Nhap so luong the muon : ");
        int n = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < n; i++) {
            System.err.println("Nhap thong tin the muon thu " + (i+1)+":");
            TheMuon theMuon = new TheMuon();
            theMuon.nhapThongTin(scanner);
            dsTheMuon.add(theMuon);
        }
        
        System.out.println("\nThong tin cac the muon:");
        for(TheMuon theMuon : dsTheMuon){
        theMuon.hienThiThongTin();
            System.out.println("-------------------");
        }
        
        System.out.println("\nThong tin the muon cua sinh vien lop CNTT");
        for(TheMuon theMuon : dsTheMuon){
            if("CNTT".equalsIgnoreCase(theMuon.getSinhVien().getLop())){
                theMuon.hienThiThongTin();
                System.out.println("----------------");
            }
        }
        
        System.out.println("\n Thong tin the muon sach qua han");
        for(TheMuon theMuon : dsTheMuon){
            if(theMuon.getHanTra().compareTo(LocalDate.now().toString()) > 0){
                theMuon.hienThiThongTin();
                System.out.println("------------------");
            }
        }
        
        scanner.close();
    }
}
