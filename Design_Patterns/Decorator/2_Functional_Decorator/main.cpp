#include <iostream>
#include <functional>

// Base function type
using DrinkMaker = std::function<std::string()>;
using CostCalculator = std::function<double()>;

// Functional decorators
DrinkMaker addMilk(DrinkMaker baseDrink) {
    return [baseDrink]() { return baseDrink() + " + Milk"; };
}

CostCalculator addMilkCost(CostCalculator baseCost) {
    return [baseCost]() { return baseCost() + 1.5; };
}

DrinkMaker addSugar(DrinkMaker baseDrink) {
    return [baseDrink]() { return baseDrink() + " + Sugar"; };
}

CostCalculator addSugarCost(CostCalculator baseCost) {
    return [baseCost]() { return baseCost(); };
}

int main() {
    // Base functions
    DrinkMaker coffee = []() { return "Coffee"; };
    CostCalculator coffeeCost = []() { return 2.0; };

    // Apply functional decorators
    DrinkMaker myDrink = addMilk(addSugar(coffee));
    CostCalculator myDrinkCost = addMilkCost(addSugarCost(coffeeCost));

    std::cout << myDrink() << " costs $" << myDrinkCost() << std::endl;
    return 0;
}
