package thread.thread_safe;

import java.util.Vector;

public class VectorExample {
    public static void main(String[] args) {
        Vector<Integer> vector = new Vector<>();

        Runnable task = () -> {
            for (int i = 0; i < 1000; i++) {
                vector.add(i);
            }
        };

        Thread thread1 = new Thread(task);
        Thread thread2 = new Thread(task);

        thread1.start();
        thread2.start();

        try {
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Vector size: " + vector.size()); // Kết quả luôn là 2000
    }
}