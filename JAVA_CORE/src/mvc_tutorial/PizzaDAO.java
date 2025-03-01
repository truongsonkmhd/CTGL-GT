package mvc_tutorial;

import java.util.ArrayList;
import java.util.List;

public class PizzaDAO {
    private List<Pizza> pizzaList = new ArrayList<>();

    public PizzaDAO() {
        pizzaList.add(new Pizza(1, "Pepperoni", 10.5));
        pizzaList.add(new Pizza(2, "Margherita", 9.0));
        pizzaList.add(new Pizza(3, "Hawaiian", 11.0));
    }

    public List<Pizza> getAllPizzas() {
        return pizzaList;
    }

    public void addPizza(Pizza pizza) {
        pizzaList.add(pizza);
    }
}
