#pragma once
#include <iostream>
using namespace std;

// Family of products, in this case Hot Drinks
struct HotDrink
{
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
    void prepare(int volume) override {
        cout << "Tea bag put in " << volume << " ml of hot water." << endl; 
    };
};

struct Coffee : HotDrink
{
    void prepare(int volume) override {
        cout << "Soluble coffee put in " << volume << " ml of hot water." << endl; 
    };
};
