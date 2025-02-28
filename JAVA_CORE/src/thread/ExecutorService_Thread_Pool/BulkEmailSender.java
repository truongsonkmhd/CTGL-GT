package thread.ExecutorService_Thread_Pool;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
//Hệ thống gửi email hàng loạt
public class BulkEmailSender {

    public static void main(String[] args) {
        // Tạo thread pool với 5 thread
        ExecutorService executor = Executors.newFixedThreadPool(5);

        // Danh sách email người dùng
        String[] userEmails = {
                "user1@example.com",
                "user2@example.com",
                "user3@example.com",
                "user4@example.com",
                "user5@example.com",
                "user6@example.com",
                "user7@example.com"
        };

        // Gửi các tác vụ gửi email vào thread pool
        for (String email : userEmails) {
            executor.submit(() -> sendEmail(email));
        }

        // Đóng ExecutorService sau khi tất cả các tác vụ đã được gửi
        executor.shutdown();
    }

    // Phương thức gửi email
    private static void sendEmail(String email) {
        System.out.println("Sending email to " + email + " by " + Thread.currentThread().getName());
        try {
            // Giả lập thời gian gửi email
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Email sent to " + email + " by " + Thread.currentThread().getName());
    }
}