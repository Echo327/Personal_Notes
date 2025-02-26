#include <iostream>

// Base class
class Drink {
public:
    std::string description = "Unknown Drink";
    virtual std::string getDescription() const { return description; }
    virtual double getCost() const { return 0.0; }
};

// Concrete classes
class Coffee : public Drink {
public:
    Coffee() { description = "Coffee"; }
    double getCost() const override { return 2.0; }
};

class Tea : public Drink {
public:
    Tea() { description = "Tea"; }
    double getCost() const override { return 3.0; }
};

// Static decorator using templates
template <typename T>
class Milk : public T {
public:
    std::string getDescription() const override { return T::getDescription() + " + Milk"; }
    double getCost() const override { return T::getCost() + 1.5; }
};

template <typename T>
class Sugar : public T {
public:
    std::string getDescription() const override { return T::getDescription() + " + Sugar"; }
    double getCost() const override { return T::getCost(); }
};

int main() {
    Milk<Sugar<Coffee>> myDrink;
    std::cout << myDrink.getDescription() << " costs $" << myDrink.getCost() << std::endl;
    return 0;
}
