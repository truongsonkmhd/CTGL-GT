package exception.sample;

class MyCheckedException extends Exception {
    // Constructor mặc định
    public MyCheckedException() {
        super("Đây là một ngoại lệ kiểm tra tùy chỉnh!");
    }

    // Constructor với thông báo lỗi tùy chỉnh
    public MyCheckedException(String message) {
        super(message);
    }
}