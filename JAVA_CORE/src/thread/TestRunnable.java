package thread;

public class TestRunnable extends ABC implements Runnable {
    @Override
    public void run(){
        for (int i = 0 ; i < 100; i++){
            System.out.println("TetThread is running " + i);
        }
    }
}
