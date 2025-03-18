package trenlop.bai_1_oop;

import java.util.Scanner;

abstract class Employee {
    protected String id;
    protected String name;
    protected double salary;

    public Employee() {}

    public void input(Scanner scanner) {
        System.out.print("Nhập ID: ");
        this.id = scanner.nextLine();
        System.out.print("Nhập tên: ");
        this.name = scanner.nextLine();
        System.out.print("Nhập lương: ");
        this.salary = scanner.nextDouble();
        scanner.nextLine();
    }
    public abstract double getIncome();

    public double getTax() {
        double income = getIncome();
        if (income < 9000000) {
            return 0;
        } else if (income <= 15000000) {
            return income * 0.1;
        } else {
            return income * 0.12;
        }
    }

    public void display() {
        System.out.println("ID: " + id + ", Name: " + name + ", Income: " + getIncome() + ", Tax: " + getTax());
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }
}

