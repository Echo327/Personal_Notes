#include <iostream>
using namespace std;

// Note: All of the data is static

class Printer
{
    static int id;

    void print_id(){cout << "ID = " << id << endl;}
public:
    int get_id() {return id;}
    void set_id(int new_id) {id = new_id; print_id();}
    void increment_id(){++id; print_id();}
    void decrement_id(){--id; print_id();}
};

int Printer::id = 0;

int main()
{
    Printer p1;
    cout << "printer 1 id is" << p1.get_id() << endl;

    // p2 will use the same data as p1
    Printer p2;
    p2.increment_id();
    cout << "printer 1 id is " << p1.get_id() << endl;
    cout << "printer 2 id is" << p2.get_id() << endl;

    return 0;
}