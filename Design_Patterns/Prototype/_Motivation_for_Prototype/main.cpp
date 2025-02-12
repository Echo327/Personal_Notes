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
    Employee jack{"Jack Doe", new Address{"High Rd", "AC", 327}};
    Employee horace{"Horace Doe", new Address{"High Rd", "AC", 327}};
    Employee jane{"Jane Smith", new Address{"Low Rd", "DC", 723}};
    Employee jean{"Jean Smith", new Address{"Low Rd", "DC", 723}};

    cout << john << endl;
    cout << jack << endl;
    cout << jane << endl;

    // Making a new one from an existing entry
    Employee jimmy = john;
    jimmy.name = "Jimmy Doe";
    jimmy.address->suite = 666;
    cout << john << endl;
    cout << jimmy << endl;
    // Here setting the suite for Jimmy actually modifies John's address too
    // Prototype aims to avoid such scenarios
    // and makes it easier to create copies of an object

    return 0;
}