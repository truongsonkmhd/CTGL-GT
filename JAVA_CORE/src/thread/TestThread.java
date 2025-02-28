package thread;

public class TestThread extends Thread{
    // không kết thừa được lớp khác nữa vì đã kết thừa Thread(java có đa kế thừa) nên dùng implement Runnable
    @Override
    public void run(){
        for (int i = 0 ; i < 100; i++){
            System.out.println("TetThread is running " + i);
        }
    }
}
