public class so_nguyen_to {
    private static boolean nguyenTo(int n){
        if (n < 2) return false;
        for(int i= 2; i <= Math.sqrt(n); i++){
            if (n%i==0) return false;
        }
        return true;
    }
}
