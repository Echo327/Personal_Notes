#pragma once
#include "HotDrink.hpp"
#include "HotDrinkFactory.hpp"
#include <map>
using namespace std;

class DrinkFactory
{
    // possible as they all "share" make()
    map<string, unique_ptr<HotDrinkFactory>> hot_factories;
public:
    DrinkFactory()
    {
        hot_factories["coffee"] = make_unique<CoffeeFactory>();   
        hot_factories["tea"] = make_unique<TeaFactory>();
    }
    
    // interface for asking for a drink
    unique_ptr<HotDrink> make_drink(const string& name)
    {
        auto drink = hot_factories[name]->make();
        // set as 200 in the example only as a shortcut
       // either take in as argument
       // or determine w.r.t. drink
        drink->prepare(200);
        return drink;
    }
};
