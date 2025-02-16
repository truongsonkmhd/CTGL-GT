package thread.synchronized_practive;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Counter counter = new Counter();

        Thread thread1 = new Thread(()->{
            for(int i = 0; i < 10000 ; i ++){
                counter.increment();
                System.out.println("thread1:" + counter.getCount());
            }
        });

        Thread thread2 = new Thread(()->{
            for(int i = 0; i < 10000 ; i ++){
                counter.increment();
                System.out.println("thread2:" + counter.getCount());
            }
        });

        thread1.start();
        thread2.start();

        // đợi cả hai thread hoàn thành
        thread1.join();
        thread2.join();

        System.out.println("Final count: " + counter.getCount());

    }
}
