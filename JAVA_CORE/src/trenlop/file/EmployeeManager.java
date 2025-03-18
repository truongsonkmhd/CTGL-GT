package trenlop.file;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class EmployeeManager {
    private static final String FILE_NAME = "employees.txt";
    private List<Employee> employees = new ArrayList<>();

    public void addEmployee(String name, double salary) {
        employees.add(new Employee(name, salary));
        System.out.println("Nhân viên đã được thêm.");
    }

    public void saveToFile() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_NAME))) {
            for (Employee emp : employees) {
                writer.write(emp.toString());
                writer.newLine();
            }
            System.out.println("Dữ liệu đã được lưu vào file.");
        } catch (IOException e) {
            System.err.println("Lỗi khi lưu file: " + e.getMessage());
        }
    }

    public void readFromFile() {
        employees.clear();
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(", ");
                if (parts.length == 2) {
                    employees.add(new Employee(parts[0], Double.parseDouble(parts[1])));
                }
            }
            System.out.println("Dữ liệu đã được đọc từ file.");
        } catch (IOException e) {
            System.err.println("Lỗi khi đọc file: " + e.getMessage());
        }
    }

    public void displayEmployees() {
        System.out.println("Danh sách nhân viên:");
        for (Employee emp : employees) {
            System.out.println(emp);
        }
    }

    public static void main(String[] args) {
        EmployeeManager manager = new EmployeeManager();

        manager.addEmployee("Nguyen Van A", 5000);
        manager.addEmployee("Tran Thi B", 7000);

        manager.saveToFile();
        manager.readFromFile();
        manager.displayEmployees();
    }
}

