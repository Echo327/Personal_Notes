#include <iostream>
#include <string>
using namespace std;

// Decorator
struct Logger
{
    string name;

    template <typename Func, typename... Args>
    auto operator()(Func func, Args... args)
    {
        cout << "Entering " << name << endl;
        auto result = func(args...);
        cout << "Exiting " << name << endl;
        return result;
    }

    Logger(const string &name) : name(name) {}
};

// Function to be decorated
double add(double a, double b)
{
    cout << a << " + " << b << " = " << (a + b) << endl;
    return a + b;
}

int main()
{
    Logger log("AdditionFunction");
    double result = log(add, 3.5, 2.5);
    double result2 = log(add, 5, 2);

    cout << "Result: " << result << endl;
    cout << "Result2: " << result2 << endl;
    return 0;
}
