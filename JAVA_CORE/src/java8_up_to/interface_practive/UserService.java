package java8_up_to.interface_practive;

public interface UserService {
    String companyName = "Amazon";

    int addUser();
    void updateUser();
    void deleteUser();

    default void printMessage(){
        System.out.println("UserService printMessage");
    }

    static void doSomething(){
        System.out.println("UserService doSomething");
    }

}
