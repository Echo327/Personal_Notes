// Abstract Factory
// Example: Hot Drink Machine

#include <iostream>
using namespace std;
#include "headers/DrinkFactory.hpp"

// Without Abstract Factory, it would be an IF
// unique_ptr<HotDrink> make_drink(string type)
// {
//     unique_ptr<HotDrink> drink;
//     if (type == "tea)
//     {
//       drink = make_unique<Tea>();
//       drink->prepare(200);
//     }
//     else
//     ...
//     return drink;
//     // for call in main
//     // auto d = make_drink("tea");
    
// };

int main()
{
    DrinkFactory df;

    auto c = df.make_drink("tea");

    auto c2 = df.make_drink("coffee");

    auto c3 = df.make_drink("tea");
    
    return 0;
}
