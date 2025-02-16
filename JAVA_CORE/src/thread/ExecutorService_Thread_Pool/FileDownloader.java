package thread.ExecutorService_Thread_Pool;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class FileDownloader {

    public static void main(String[] args) {
        // Tạo thread pool với 4 thread
        ExecutorService executor = Executors.newFixedThreadPool(4);

        // Danh sách các URL cần tải
        String[] fileUrls = {
                "https://example.com/file1.zip",
                "https://example.com/file2.zip",
                "https://example.com/file3.zip",
                "https://example.com/file4.zip",
                "https://example.com/file5.zip"
        };

        // Gửi các tác vụ tải file vào thread pool
        for (String url : fileUrls) {
            executor.submit(() -> downloadFile(url));
        }

        // Đóng ExecutorService sau khi tất cả các tác vụ đã được gửi
        executor.shutdown();
    }

    // Phương thức tải file
    private static void downloadFile(String url) {
        System.out.println("Downloading file from " + url + " by " + Thread.currentThread().getName());
        try {
            // Giả lập thời gian tải file
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("File downloaded from " + url + " by " + Thread.currentThread().getName());
    }
}