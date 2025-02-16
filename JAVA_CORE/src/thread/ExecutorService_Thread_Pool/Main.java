package thread.ExecutorService_Thread_Pool;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {
    /*
    * Khi cần quản lý nhiều thread, chúng ta nên sử dụng ExecutorService để tối ưu hoá việc tạo
    * và quản lý thread. ExecutorService sử dụng các Thread Pool để tái sử dụng thread,
    * giúp cải thiện hiệu suất và tiết kiệm tài nguyên hệ thống
    * */

    public static void main(String[] args) {
        // Tạo một Thread Pool với 3 thread
        ExecutorService executor = Executors.newFixedThreadPool(6);

        // Thực thi các tác vụ
        for (int i = 0 ; i < 5 ; i++){
            executor.submit(() ->{
                System.out.println("Thread" + Thread.currentThread().getName() + "is running.");
            });
        }
        // Đóng ExecutorService
        executor.shutdown();
    }
}
