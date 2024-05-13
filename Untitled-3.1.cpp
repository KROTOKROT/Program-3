#include <iostream>
#include <string>

class Product {
private:
    double calories_per_100g; 
    double weight;           

public:
    Product(double calories, double weight) : calories_per_100g(calories), weight(weight) {}

    std::string getInfo() const {
        return "Продукт: " + std::to_string(weight) + " грамм, " +
               std::to_string(calories_per_100g) + " ккал на 100 грамм.";
    }

    double getTotalCalories() const {
        return (weight / 100.0) * calories_per_100g;
    }
};

int main() {
    double calories, weight;
    std::cout << "Введите калорийность на 100г продукта: ";
    std::cin >> calories;
    std::cout << "Введите вес продукта в граммах: ";
    std::cin >> weight;

    Product product(calories, weight);

    std::cout << product.getInfo() << std::endl;

    std::cout << "Общая калорийность продукта: " << product.getTotalCalories() << " ккал" << std::endl;

    return 0;
}