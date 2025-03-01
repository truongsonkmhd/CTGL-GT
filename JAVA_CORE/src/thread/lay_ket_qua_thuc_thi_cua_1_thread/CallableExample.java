package thread.lay_ket_qua_thuc_thi_cua_1_thread;

import java.util.concurrent.*;

public class CallableExample {
    public static void main(String[] args) throws ExecutionException, InterruptedException {
        ExecutorService executor = Executors.newSingleThreadExecutor();

        Callable<Integer> task = () -> {
            int sum = 0;
            for (int i = 1; i <= 10; i++) {
                sum += i;
            }
            return sum;
        };

        Future<Integer> future = executor.submit(task);

        System.out.println("Kết quả: " + future.get()); // Kết quả: 55

        executor.shutdown();
    }
}