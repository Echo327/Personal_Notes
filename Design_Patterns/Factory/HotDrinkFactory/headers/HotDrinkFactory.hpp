#pragma once
#include "HotDrink.hpp"
#include <memory>

// Factories corresponding to family of products
struct HotDrinkFactory // Abstract Factory
{
    // virtual so every child has to define the behaviour of make
    virtual unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override {
        return make_unique<Tea>();
    };
};

struct CoffeeFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override {
        return make_unique<Coffee>();
    };
};
