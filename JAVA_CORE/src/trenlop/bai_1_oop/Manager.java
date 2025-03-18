package trenlop.bai_1_oop;

import java.util.Scanner;

class Manager extends Employee {
    private double responsibilitySalary;

    public void input(Scanner scanner) {
        super.input(scanner);
        System.out.print("Nhập lương trách nhiệm: ");
        this.responsibilitySalary = scanner.nextDouble();
        scanner.nextLine();
    }

    @Override
    public double getIncome() {
        return salary + responsibilitySalary;
    }
}