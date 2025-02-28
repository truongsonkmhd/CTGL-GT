package thread.synchronized_practive;

public class Counter {

    /*
    * Trong môi trường multithreading, nếu nhiều thread cùng truy cập vào một tài nguyên chung có thể xảy ra các vấn đề đồng bộ
    * Để tránh điều này chúng ta có thể sử dụng từ khoá "synchronized" để đảm bảo rằng chỉ một threa có thể truy cập tài nguyên
    * đó tại một thời điểm
    * */
    private int count = 0;

    // đồng bộ hoá phương thức
    public synchronized  void increment(){
        count++;
    }

    public int getCount() {
        return count;
    }
}
