package codePtit_java_core;

import java.util.Scanner;

public class tong_day_so {
//        Sn = -1 + 2 - 3 + 4 -5 + 6 +...+ (-1)^n.n
    //vd(n = 10) Sn = -1 + 2 -3 +4 -5 + 6 -7+ 8 -9 +10 => số lẻ trước sẽ âm, chẵn thì trước dương
public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long n = sc.nextLong();
    if(n % 2 == 0){
        System.out.print(n/2);
    } else {
        System.out.print((n-1)/2 - n);
    }
}

}
