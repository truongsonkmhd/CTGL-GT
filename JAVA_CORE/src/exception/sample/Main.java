package exception.sample;

public class Main {
    public static void main(String[] args) {
        try {
            throw new MyCheckedException("Lỗi tùy chỉnh!");
        } catch (MyCheckedException e) {
            System.out.println(e.getMessage());
        }

        throw new MyUncheckedException("Lỗi không kiểm tra!");

    }
}
