package exception;

public class Main {
    public static void main(String[] args) {
        int ketqua = add(0,3);
        System.out.println(ketqua);
    }

    static int add(int a, int b){
        if(a == 0) {
            throw new InvalidParamException("khong cho phep gia tri 0");
        }
        return a + b;
    }
}
