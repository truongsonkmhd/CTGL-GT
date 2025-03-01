package mvc_tutorial;


import java.util.List;

public class PizzaGUI {
    public static void main(String[] args) {
        PizzaBUS pizzaBUS = new PizzaBUS();

        // Hiển thị danh sách Pizza
        System.out.println("Danh sách Pizza:");
        List<Pizza> pizzas = pizzaBUS.getAllPizzas();
        for (Pizza p : pizzas) {
            System.out.println("ID: " + p.getId() + " | " + p.getName() + " | Giá: $" + p.getPrice());
        }

        // Thêm một Pizza mới
        pizzaBUS.addPizza(4, "BBQ Chicken", 12.5);
        System.out.println("\nĐã thêm Pizza mới!");

        // Hiển thị lại danh sách
        System.out.println("\nDanh sách Pizza sau khi thêm:");
        pizzas = pizzaBUS.getAllPizzas();
        for (Pizza p : pizzas) {
            System.out.println("ID: " + p.getId() + " | " + p.getName() + " | Giá: $" + p.getPrice());
        }
    }
}
