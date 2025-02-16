package exception.sample;

class MyUncheckedException extends RuntimeException {
    // Constructor mặc định
    public MyUncheckedException() {
        super("Đây là một ngoại lệ không kiểm tra tùy chỉnh!");
    }

    // Constructor với thông báo lỗi tùy chỉnh
    public MyUncheckedException(String message) {
        super(message);
    }
}