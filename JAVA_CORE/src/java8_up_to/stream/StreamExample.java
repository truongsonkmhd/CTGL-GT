package java8_up_to.stream;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class StreamExample {
    public static void main(String[] args) {
        List<Product> products = Arrays.asList(
                new Product(1, "Laptop", 1200),
                new Product(2, "Phone", 800),
                new Product(3, "Tablet", 500),
                new Product(4, "Monitor", 300),
                new Product(5, "Keyboard", 100),
                new Product(6, "Mouse", 50),
                new Product(7, "Headphone", 200)
        );

        // 1. Lọc sản phẩm có giá trên 500
        List<Product> expensiveProducts = products.stream()
                .filter(p -> p.getPrice() > 500).toList();
        System.out.println("🔹 Sản phẩm có giá trên 500:");
        expensiveProducts.forEach(System.out::println);

        // 2. Lấy danh sách tên sản phẩm
        List<String> productNames = products.stream()
                .map(Product::getName).toList();
        System.out.println("\n🔹 Danh sách tên sản phẩm:");
        productNames.forEach(System.out::println);

        // 3. Sắp xếp sản phẩm theo giá giảm dần
        List<Product> sortedProducts = products.stream()
                .sorted(Comparator.comparing(Product::getPrice).reversed()).toList();
        System.out.println("\n🔹 Sản phẩm sau khi sắp xếp theo giá giảm dần:");
        sortedProducts.forEach(System.out::println);

        // 4. Bỏ qua 2 sản phẩm đầu tiên, lấy 3 sản phẩm tiếp theo
        List<Product> skippedProducts = products.stream()
                .skip(2)
                .limit(3).toList();
        System.out.println("\n🔹 Bỏ qua 2 sản phẩm đầu tiên, lấy 3 sản phẩm tiếp theo:");
        skippedProducts.forEach(System.out::println);

        // 5. Loại bỏ phần tử trùng lặp (distinct)
        List<Double> distinctPrices = products.stream()
                .map(Product::getPrice)
                .distinct().toList();
        System.out.println("\n🔹 Danh sách giá tiền không trùng:");
        distinctPrices.forEach(System.out::println);

        // 6. Tìm sản phẩm đầu tiên có giá trên 500
        Optional<Product> firstExpensive = products.stream()
                .filter(p -> p.getPrice() > 500)
                .findFirst();
        System.out.println("\n🔹 Sản phẩm đầu tiên có giá trên 500: " + firstExpensive.orElse(null));

        // 7. Tìm bất kỳ sản phẩm nào có giá dưới 300
        Optional<Product> anyCheapProduct = products.stream()
                .filter(p -> p.getPrice() < 300)
                .findAny();
        System.out.println("\n🔹 Một sản phẩm giá dưới 300: " + anyCheapProduct.orElse(null));

        // 8. Kiểm tra điều kiện
        boolean allExpensive = products.stream().allMatch(p -> p.getPrice() > 50);
        boolean anyExpensive = products.stream().anyMatch(p -> p.getPrice() > 1000);
        boolean noneTooCheap = products.stream().noneMatch(p -> p.getPrice() < 50);
        System.out.println("\n🔹 Có phải tất cả sản phẩm giá > 50? " + allExpensive);
        System.out.println("🔹 Có sản phẩm nào giá > 1000? " + anyExpensive);
        System.out.println("🔹 Không có sản phẩm nào giá < 50? " + noneTooCheap);

        // 9. Tổng giá trị tất cả sản phẩm (reduce)
        double totalPrice = products.stream()
                .map(Product::getPrice)
                .reduce(0.0, Double::sum);
        System.out.println("\n🔹 Tổng giá trị sản phẩm: " + totalPrice);

        /*VD2*/
        int product = Arrays.asList(1, 2, 3, 4, 5)
                .stream()
                .reduce(1, (a, b) -> a * b);
        System.out.println("Tích các số: " + product); // Kết quả: 120
        /*VD3*/

        int max =  Arrays.asList(1, 7, 3, 9, 5)
                .stream()
                .reduce(Integer.MIN_VALUE, Integer::max);
        System.out.println("Giá trị lớn nhất: " + max); // Kết quả: 9
        /*VD4*/
        String result = Arrays.asList("Java", "8", "Stream", "API")
                .stream()
                .reduce("", (a, b) -> a + " " + b);
        System.out.println("Chuỗi kết quả: " + result.trim()); // Kết quả: "Java 8 Stream API"


        // 10. Gộp danh sách sản phẩm với danh sách khác (concat)
        List<Product> extraProducts = Arrays.asList(new Product(8, "Speaker", 400), new Product(9, "Charger", 50));
        List<Product> combinedList = Stream.concat(products.stream(), extraProducts.stream()).toList();
        System.out.println("\n🔹 Danh sách sau khi gộp:");
        combinedList.forEach(System.out::println);

        // 11. FlatMap: Danh sách danh mục sản phẩm
        List<List<Product>> categories = Arrays.asList(
                Arrays.asList(new Product(10, "Smartwatch", 600), new Product(11, "Fitness Tracker", 300)),
                Arrays.asList(new Product(12, "Camera", 1500), new Product(13, "Drone", 2000))
        );

        List<Product> allProducts = categories.stream()
                .flatMap(List::stream).toList();
        System.out.println("\n🔹 Danh sách sản phẩm sau khi dùng flatMap:");
        allProducts.forEach(System.out::println);

        // 12. Nhóm sản phẩm theo khoảng giá (groupingBy)
        Map<String, List<Product>> groupedProducts = products.stream()
                .collect(Collectors.groupingBy(p -> {
                    if (p.getPrice() < 300) return "Giá rẻ";
                    else if (p.getPrice() < 1000) return "Tầm trung";
                    else return "Cao cấp";
                }));

        System.out.println("\n🔹 Nhóm sản phẩm theo khoảng giá:");
        groupedProducts.forEach((category, productList) -> {
            System.out.println("  " + category + ": " + productList);
        });
    }
}