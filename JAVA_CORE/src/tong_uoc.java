public class tong_uoc {
    public static long tongUoc(long n) {
        long sum = 0;
        for (long i = 1; i <= (int)Math.sqrt(n);i++){
            if(n%i==0){
                sum+=i;
                if(i != n/i) sum +=n/i;
            }
        }
        return sum;
    }

}
