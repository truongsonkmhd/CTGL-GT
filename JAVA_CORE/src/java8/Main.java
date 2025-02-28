package java8;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Main m = new Main();
        List<User> userList = m.getUser();

        // Filter để lọc theo giới tính
        userList.stream().filter(user ->
                user.getGender().equals(Gender.male)
        ).forEach(System.out::println);

        // lay dia cchi cua gtinh nữ, và không trùng (distinct))
        List<String> address = userList.stream().filter(user -> user.getGender().equals(Gender.female)).map(User::getAddress).distinct().toList();
        System.out.println(address);

        String s =" aba";
        String s2 = "cbv.    ";

        System.out.println(s2.stripTrailing());// xoa khoang trang cuoi
        System.out.println(s2.stripLeading());// xoa khoang trang dau

    }

    List<User> getUser() {
        //old:
        User user1 = new User(1l, "son", "1234", Gender.female, "hnoi");
        User user2 = new User(2l, "son", "1234", Gender.female, "hue");
        User user3 = new User(3l, "son", "1234", Gender.female, "hue");

        List<User> users = new ArrayList<>();
        users.add(user1);
        users.add(user2);
        users.add(user3);
        // return users
        // mew
        return List.of(new User(1l, "son", "1234", Gender.female, "hnoi"),
                new User(1l, "son", "1234", Gender.female, "hnoi"),
                new User(1l, "son", "1234", Gender.female, "hnoi"));
    }

    class User {
        Long id;
        String username;
        String password;
        Gender gender;
        String address;

        public User() {
        }

        public User(Long id, String username, String password, Gender gender, String address) {
            this.id = id;
            this.username = username;
            this.password = password;
            this.gender = gender;
            this.address = address;
        }

        public void setId(Long id) {
            this.id = id;
        }

        public void setUsername(String username) {
            this.username = username;
        }

        public void setPassword(String password) {
            this.password = password;
        }

        public void setGender(Gender gender) {
            this.gender = gender;
        }

        public void setAddress(String address) {
            this.address = address;
        }

        public Long getId() {
            return id;
        }

        public String getUsername() {
            return username;
        }

        public String getPassword() {
            return password;
        }

        public Gender getGender() {
            return gender;
        }

        public String getAddress() {
            return address;
        }

        @Override
        public String toString() {
            return "User{" +
                    "id=" + id +
                    ", username='" + username + '\'' +
                    ", password='" + password + '\'' +
                    ", gender=" + gender +
                    ", address='" + address + '\'' +
                    '}';
        }
    }


    enum Gender {
        male, female, other
    }
}
