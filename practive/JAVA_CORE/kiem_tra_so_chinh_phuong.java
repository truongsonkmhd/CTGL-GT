package codePtit_java_core;

import java.util.Scanner;

public class kiem_tra_so_chinh_phuong {
    public static boolean chinhPhuong(int n ){
        int can  =  (int)Math.sqrt(n);
        return can * can == n;
    }
    public static void main(String[] args) {
        Scanner sc = new  Scanner(System.in);
        float n = sc.nextFloat();
        if (chinhPhuong((int)n)){

        } else  {

        }
    }
}
