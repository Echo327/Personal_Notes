#pragma once

#include <string>

class PersonAddressBuilder : public PersonBuilderBase
{
    typedef PersonAddressBuilder Self;
public:
    PersonAddressBuilder(Person& person) : PersonBuilderBase(person) {}

    Self& at(std::string home_address)
    {
        person.home_address = home_address;
        return *this;
    }

    Self& with_postcode(std::string post_code)
    {
        person.post_code = post_code;
        return *this;
    }

    Self& in(std::string city)
    {
        person.city = city;
        return *this;
    }
};
