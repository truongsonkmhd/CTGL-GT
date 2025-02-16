package thread.ExecutorService_Thread_Pool;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/*
-executor.submit(): Gửi một tác vụ (task) vào thread pool để thực thi. Tác vụ được định nghĩa bằng lambda expression.
-executor.shutdown(): Đóng ExecutorService sau khi tất cả các tác vụ đã được gửi. Phương thức này không chấp nhận thêm
tác vụ mới nhưng cho phép các tác vụ đang chạy hoàn thành.*/
public class OrderProcessingSystem {

    public static void main(String[] args) {
        // Tạo thread pool với 6 thread
        ExecutorService executor = Executors.newFixedThreadPool(6);

        // Danh sách đơn hàng cần xử lý
        int[] orderIds = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};

        // Gửi các tác vụ xử lý đơn hàng vào thread pool
        for (int orderId : orderIds) {
            executor.submit(() -> processOrder(orderId));
        }

        // Đóng ExecutorService sau khi tất cả các tác vụ đã được gửi
        executor.shutdown();
    }

    // Phương thức xử lý đơn hàng
    private static void processOrder(int orderId) {
        System.out.println("Processing order " + orderId + " by " + Thread.currentThread().getName());
        try {
            // Giả lập thời gian xử lý đơn hàng
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Order " + orderId + " processed by " + Thread.currentThread().getName());
    }
}