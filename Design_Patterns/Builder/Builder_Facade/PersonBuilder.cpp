#include "PersonBuilder.hpp"
#include "PersonAddressBuilder.hpp"
#include "PersonProBuilder.hpp"

PersonBuilderBase::PersonBuilderBase(Person &person) : person(person) {}

PersonBuilder::PersonBuilder() : PersonBuilderBase(p) {}

PersonAddressBuilder PersonBuilderBase::lives() const {
    return PersonAddressBuilder{person};
}

PersonProBuilder PersonBuilderBase::works() const {
    return PersonProBuilder{person};
}