#pragma once

#include <string>
#include "PersonBuilder.hpp"

class PersonProBuilder : public PersonBuilderBase
{
        typedef PersonProBuilder Self;
public:
    PersonProBuilder(Person& person) : PersonBuilderBase(person) {}

    Self& works_for(std::string company)
    {
        person.company = company;
        return *this;
    }

    Self& as(std::string position)
    {
        person.position = position;
        return *this;
    }

    Self& gets_paid(int annual_income)
    {
        person.annual_income = annual_income;
        return *this;
    }
};