package trenlop.bai_1_oop;

import java.util.Scanner;

class MarketingEmployee extends Employee {
    private double sales;
    private double commissionRate;

    public void input(Scanner scanner) {
        super.input(scanner);
        System.out.print("Nhập doanh số: ");
        this.sales = scanner.nextDouble();
        System.out.print("Nhập tỷ lệ hoa hồng: ");
        this.commissionRate = scanner.nextDouble();
        scanner.nextLine();
    }

    @Override
    public double getIncome() {
        return salary + (sales * commissionRate);
    }
}