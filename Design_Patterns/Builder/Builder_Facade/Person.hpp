#pragma once
#include <iostream>
#include <string>

class PersonBuilder;

class Person
{
    // Personal Information
    std::string name = "this dude";
    std::string home_address, post_code, city;

    // Professional Information
    std::string company, position;
    int annual_income{0};

public:
    static PersonBuilder create();

    friend class PersonBuilder;
    friend class PersonAddressBuilder;
    friend class PersonProBuilder;

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << "Home Address : " << person.home_address << std::endl
            << "Post Code : " << person.post_code << std::endl
            << "City : " << person.city << std::endl
            << "Company : " << person.company << std::endl
            << "Position : " << person.position << std::endl
            << "Annual Income : " << person.annual_income << std::endl;
        return os;
    }

};