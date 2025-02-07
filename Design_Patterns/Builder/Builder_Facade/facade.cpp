// Builder Facade is a Design Pattern
// for when multiple builders to build one object are required

#include <iostream>
#include "Person.hpp"
#include "PersonBuilder.hpp"
#include "PersonAddressBuilder.hpp"
#include "PersonProBuilder.hpp"
using namespace std;

int main() {
    Person p = Person::create()
        .lives()
            .at("327 Echo Road")
            .with_postcode("D8S G2H")
            .in("Hell")
        .works()
            .works_for("Compy")
            .as("Pig")
            .gets_paid(37e4);

    cout << p << endl;

    return 0;
}
