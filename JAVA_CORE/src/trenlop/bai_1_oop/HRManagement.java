package trenlop.bai_1_oop;

import java.util.*;

public class HRManagement {
    private static List<Employee> employees = new ArrayList<>();
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("+---------------------Menu------------------------+");
            System.out.println("1. Nhập danh sách nhân viên");
            System.out.println("2. Xuất danh sách nhân viên");
            System.out.println("3. Tìm kiếm nhân viên theo mã NV");
            System.out.println("4. Xóa nhân viên theo mã nhập vào");
            System.out.println("5. Tìm nhân viên theo khoảng lương");
            System.out.println("6. Sắp xếp nhân viên theo họ tên");
            System.out.println("7. Sắp xếp nhân viên theo thu nhập");
            System.out.println("8. Xuất 5 nhân viên có thu nhập cao nhất");
            System.out.println("0. Thoát");
            System.out.println("+-----------------------------------------------+");
            System.out.print("Chọn chương trình: ");
            choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1 -> addEmployee();
                case 2 -> displayEmployees();
                case 3 -> searchEmployee();
                case 4 -> deleteEmployee();
                case 5 -> searchBySalaryRange();
                case 6 -> sortByName();
                case 7 -> sortByIncome();
                case 8 -> displayTop5Employees();
                case 0 -> System.out.println("Thoát chương trình.");
                default -> System.out.println("Lựa chọn không hợp lệ.");
            }
        } while (choice != 0);
    }

    private static void addEmployee() {
        System.out.print("Nhập loại nhân viên (1-Hành chính, 2-Tiếp thị, 3-Trưởng phòng): ");
        int type = scanner.nextInt();
        scanner.nextLine();
        Employee employee = null;

        if (type == 1) {
            employee = new AdministrativeEmployee();
        } else if (type == 2) {
            employee = new MarketingEmployee();
        } else if (type == 3) {
            employee = new Manager();
        }

        if (employee != null) {
            employee.input(scanner);
            employees.add(employee);
        }
    }

    private static void displayEmployees() {
        for (Employee e : employees) {
            e.display();
        }
    }

    private static void searchEmployee() {
        System.out.print("Nhập mã nhân viên cần tìm: ");
        String id = scanner.nextLine();
        for (Employee e : employees) {
            if (e.getId().equalsIgnoreCase(id)) {
                e.display();
                return;
            }
        }
        System.out.println("Không tìm thấy nhân viên.");
    }

    private static void deleteEmployee() {
        System.out.print("Nhập mã nhân viên cần xóa: ");
        String id = scanner.nextLine();
        employees.removeIf(e -> e.getId().equalsIgnoreCase(id));
    }

    private static void searchBySalaryRange() {
        System.out.print("Nhập lương tối thiểu: ");
        double min = scanner.nextDouble();
        System.out.print("Nhập lương tối đa: ");
        double max = scanner.nextDouble();
        scanner.nextLine();
        for (Employee e : employees) {
            if (e.getIncome() >= min && e.getIncome() <= max) {
                e.display();
            }
        }
    }

    private static void sortByName() {
        employees.sort(Comparator.comparing(Employee::getName));
    }

    private static void sortByIncome() {
        employees.sort(Comparator.comparingDouble(Employee::getIncome));
    }


    private static void displayTop5Employees() {
        employees.stream()
                .sorted(Comparator.comparingDouble(Employee::getIncome).reversed())
                .limit(5)
                .forEach(Employee::display);
    }
}
