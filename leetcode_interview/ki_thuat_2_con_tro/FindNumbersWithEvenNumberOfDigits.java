package ki_thuat_2_con_tro;
/*
* input:  nums = [12,345,2,6,7890] // 12 có 2 chữ số , 7890 có 2 chữ só nên thoả mãn!
* output : 2
* */
public class FindNumbersWithEvenNumberOfDigits {
    public static int findNumbers(int[] nums){
        int bienDem = 0 ;
        for(int a : nums){
            int soLuongChuSo = tinhSoChuSo(a);
            if(soLuongChuSo % 2 == 0) {
                bienDem++;
            }
        }
         return bienDem;
    }

    public static int tinhSoChuSo(int a) {
        int bienDem = 0;

        while (a != 0){
            a= a/10;
            bienDem ++;
        }

        return bienDem;
    }
    public static int daoNguocSo(int a){
        int ketQua = 0;
        while (a != 0) {
            int soChuSo = a % 10;
            ketQua = ketQua*10 + soChuSo;
            a /= 10;
        }
        return ketQua;
    }
    public static void main(String[] args) {
            int[] nums = {12,345,2,6,7890};
            System.out.println( "result:" +findNumbers(nums));
            System.out.println(daoNguocSo(12345));
    }
}
