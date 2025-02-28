package thread;

public class Main {

    public static void main(String[] args) throws InterruptedException {

        Thread thread1 = new TestThread();
        Thread thread2 = new TestThread();

        thread1.start();
        thread2.start();

        TestRunnable testRunnable = new TestRunnable();
        Thread thread3 = new Thread(testRunnable);
        Thread thread4 = new Thread(testRunnable);
        thread3.start();

        Thread.sleep(1);
        thread4.start();
    }
}
