package trenlop.bai_1_oop;

import java.util.Scanner;

class AdministrativeEmployee extends Employee {
    public void input(Scanner scanner) {
        super.input(scanner);
    }

    @Override
    public double getIncome() {
        return salary;
    }
}

