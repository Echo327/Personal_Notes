#include <iostream>
#include <memory>

// Base interface
class Drink {
public:
    virtual std::string getDescription() const = 0;
    virtual double getCost() const = 0;
    virtual ~Drink() = default;
};

// Concrete components
class Coffee : public Drink {
public:
    std::string getDescription() const override { return "Coffee"; }
    double getCost() const override { return 2.0; }
};

class Tea : public Drink {
public:
    std::string getDescription() const override { return "Tea"; }
    double getCost() const override { return 3.0; }
};

// Decorator base class
class DrinkDecorator : public Drink {
protected:
    std::unique_ptr<Drink> drink;
public:
    DrinkDecorator(std::unique_ptr<Drink> d) : drink(std::move(d)) {}
};

// Concrete decorators
class Milk : public DrinkDecorator {
public:
    Milk(std::unique_ptr<Drink> d) : DrinkDecorator(std::move(d)) {}
    std::string getDescription() const override { return drink->getDescription() + " + Milk"; }
    double getCost() const override { return drink->getCost() + 1.5; }
};

class Sugar : public DrinkDecorator {
public:
    Sugar(std::unique_ptr<Drink> d) : DrinkDecorator(std::move(d)) {}
    std::string getDescription() const override { return drink->getDescription() + " + Sugar"; }
    double getCost() const override { return drink->getCost(); }
};

int main() {
    std::unique_ptr<Drink> myDrink = std::make_unique<Milk>(std::make_unique<Sugar>(std::make_unique<Coffee>()));
    std::cout << myDrink->getDescription() << " costs $" << myDrink->getCost() << std::endl;
    return 0;
}
