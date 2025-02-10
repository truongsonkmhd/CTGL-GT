package mang2chieu;

public class Mang_2_Chieu {
    public static int maximumWealth(int[][] a){
        int soKhachHang = a.length;
        int soNganHang = a[0].length;
        int[] tongTaiSan = new int[soKhachHang];
        for(int i = 0; i < soKhachHang; i++){
            int tinhTongHang1 = 0;
            for (int j = 0 ; j < soNganHang; j++){
                tinhTongHang1 += a[i][j];
            }
            tongTaiSan[i] = tinhTongHang1;
        }

        for (int i = 0 ; i < soKhachHang ; i++){
            System.out.println("Tong tai san KH" + i + ":" +tongTaiSan[i]);
        }
        int max = 0;
        for(int i = 0 ; i < soKhachHang ; i++){
            if(tongTaiSan[i] > max){
                max = tongTaiSan[i];
            }
        }
        return max;
    }

    public static void main(String[] args) {
        int [][] a = { {1,2,3} , {3,2,1}}; // khoi tao khi da biet truoc cac phan tu
        int [][] b = new int [2][3];

        System.out.println(maximumWealth(a));

        /*int soHang = a.length; // 2
        int soCot = a[0].length; // 3
        System.out.println("So hang " + soHang);
        System.out.println("So cot: " + soCot);

        for(int i = 0 ; i < soHang ; i++){
            for(int j = 0 ; j < soCot ; j++){
                System.out.println(a[i][j] + " ");
            }
        }
        System.out.println();*/
    }
}
