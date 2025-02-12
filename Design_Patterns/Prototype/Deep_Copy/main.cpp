#include <iostream>
#include <string>
using namespace std;

struct Address
{
    string street, city;
    int suite;

    Address(const string& street, const string& city, const int& suite) :
        street(street), city(city), suite(suite) {}

    friend ostream& operator<<(ostream& os, const Address& address)
    {
        os << "Lives at " << address.suite << " " << address.street
            << ", " << address.city << ".\n";
        return os;
    };
};

struct Employee
{
    string name;
    Address* address;

    Employee(const string& name, Address* address) :
        name(name), address(address) {}

    // Copy Constructor - Deep Copy
    Employee(Employee& other) :
        name(other.name),
        address(new Address{
            other.address->street, other.address->city, other.address->suite
        })
    {
    }

    friend ostream& operator<<(ostream& os, const Employee& Employee)
    {
        os << "Name : " << Employee.name << "\n" << *Employee.address;
        return os;
    };
};

int main()
{
    // Same addresses, different names
    Employee john{"John Doe", new Address{"High Rd", "AC", 327}};
    Employee jane{"Jane Smith", new Address{"Low Rd", "DC", 723}};

    cout << john << endl;
    cout << jane << endl;

    Employee jimmy = john; // Shallow Copy in absence of Deep Copy constructor
    jimmy.name = "Jimmy Doe";
    jimmy.address->suite = 666;
    cout << john << endl;
    cout << jimmy << endl;

    // John acts as a prototype here
    Employee frank{john}; // Deep Copy
    frank.name = "Frank Doe";
    frank.address->suite = 99;
    cout << john << endl;
    cout << frank << endl;

    return 0;
}