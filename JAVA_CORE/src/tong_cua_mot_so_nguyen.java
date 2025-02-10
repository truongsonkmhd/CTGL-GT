import java.util.Scanner;

public class tong_cua_mot_so_nguyen {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int sum = 0;
        while (n!=0){
            sum +=sum%10;
            n /= 10;
        }
        System.out.print("Tong cua 1 so nguyen la: " + sum);
    }
}
