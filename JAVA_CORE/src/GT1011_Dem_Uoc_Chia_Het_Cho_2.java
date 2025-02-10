import java.util.Scanner;

public class GT1011_Dem_Uoc_Chia_Het_Cho_2 {
    public static Scanner ip  = new Scanner(System.in);

    public static void testCase(){
        int n = ip.nextInt();
        int cnt = 0;

        for (int i = 1; i<= Math.sqrt(n);i++){
            if(n%i == 0){
                if (i%2==0){
                    cnt++;
                }
                if((n/i)%2==0 && i != Math.sqrt(n)){ // i != Math.sqrt(n) => loại trừ trường hợp đã trùng
                    cnt++;
                }
            }
        }

        // không tối ưu
      /*  for (int i = 1; i<= n;i++){
            if(n%i == 0){
                if (i%2==0){
                    cnt++;
                }
            }
        }*/

        if(cnt < 1){
            System.out.println("No Data");
        } else {
            System.out.println(cnt);
        }

    }

    public static void main(String[] args) {
        int T = ip.nextInt();
        while (T-->0){
            testCase();
        }
    }
}
