package mvc_tutorial;

import java.util.List;

public class PizzaBUS { // controller
    private PizzaDAO pizzaDAO = new PizzaDAO();

    public List<Pizza> getAllPizzas() {
        return pizzaDAO.getAllPizzas();
    }

    public void addPizza(int id, String name, double price) {
        Pizza pizza = new Pizza(id, name, price);
        pizzaDAO.addPizza(pizza);
    }
}
