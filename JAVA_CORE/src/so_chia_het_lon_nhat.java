import java.util.Scanner;

public class so_chia_het_lon_nhat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        //cho 2 so nguyen duong a va b, tìm so chia het cho b lon nhat va khong vượt quá a, khong dùng vòng lặp

        /*if (a > b){
            int soCanTim = (a/b)*b;
            System.out.print("So can tim la:" + soCanTim);
        }*/

        //cho 2 so nguyen duong a va b, tìm so chia het cho b nho nhat va lon hon hoac bang a, khong dùng vòng lặp

        if (a > b){
            if (a%b!=0){
                int soCanTim = (a/b)*b + b;
                System.out.print("So can tim la:" + soCanTim);
            } else{
                System.out.print("So can tim la:" + a);
            }

        }

    }


}
