#include <iostream>
#include <string>
#include <memory>
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

    ~Employee() {delete address;}

    friend ostream& operator<<(ostream& os, const Employee& Employee)
    {
        os << "Name : " << Employee.name << "\n" << *Employee.address;
        return os;
    };
};

// Prototype - Main Office (Option 1)
// Implementation not explicit enough
// Employee p("", new Address{"68 Main Road", "Not Nice", 0});

// Making a factory is more explicit
// Making constructors in Address and Employee private can also force users
// to go through the factory and therefore the prototype
struct EmployeeFactory{
    static unique_ptr<Employee> new_employee(const string& name, const int& suite,
        const Employee& prototype)
    {
        auto output =  make_unique<Employee>(prototype);
        output->name = name;
        output->address->suite = suite;
        return output;  
    };

public:
    static unique_ptr<Employee> new_main_office_employee(const string& name, const int& suite)
    {
        static Employee p("", new Address{"Main Road", "Not Nice", 0});
        return new_employee(name, suite, p);
    };

    static unique_ptr<Employee> new_aux_office_employee(const string& name, const int& suite)
    {
        static Employee p("", new Address{"Aux Road", "Nice Invert", 0});
        return new_employee(name, suite, p);
    };
};

int main()
{
    auto john = EmployeeFactory::new_main_office_employee("John Doe", 68);
    auto frank = EmployeeFactory::new_aux_office_employee("Frank Dough", 96);
    cout << *john << endl;
    cout << *frank << endl;

    return 0;
}
