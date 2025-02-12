// Did not compile to check, missing boost (followed course instructions to the letter only)
// TO-DO: Compile and run after boost install

#include <iostream>
#include <string>
#include <memory>
using namespace std;
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
using namespace boost;

struct Address
{
    string street, city;
    int suite;

    Address() {}

    Address(const string& street, const string& city, const int& suite) :
        street(street), city(city), suite(suite) {}

    friend ostream& operator<<(ostream& os, const Address& address)
    {
        os << "Lives at " << address.suite << " " << address.street
            << ", " << address.city << ".\n";
        return os;
    };

private:
    friend class serialization::access;

    // needed for Employee serialization
    template class<archive>
    void serialize(archive& ar, const unsigned version)
    {
        ar & street;
        ar & city;
        ar & suite;
    }

};

struct Employee
{
    string name;
    Address* address;

    Employee() {}

    Employee(const string& name, Address* address) :
        name(name), address(address) {}

    ~Employee() {delete address;}

    friend ostream& operator<<(ostream& os, const Employee& Employee)
    {
        os << "Name : " << Employee.name << "\n" << *Employee.address;
        return os;
    };
private:
    friend class serialization::access;

    template class<archive>
    void serialize(archive& ar, const unsigned version)
    {
        ar & name;
        ar & address;
    }
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
    auto clone = [] (const Employee& e)
    {
        ostringstream oss;
        archive::text_oarchive oa(oss);
        oa << c;
        string s = oss.str();
        cout << s << endl;

        istringstream iss(s);
        archive::text_iarchive ia(iss);
        Employee result;
        ia >> result;
        return result;
    }

    auto john = EmployeeFactory::new_main_office_employee("John", 68);
    auto jane = clone(*john);
    jane.name = "Jane";
    cout << *john << endl << *jane << endl;

    return 0;
}
