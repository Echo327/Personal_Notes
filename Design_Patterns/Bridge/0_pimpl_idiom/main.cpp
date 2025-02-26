#include "MyClass.hpp"

// Changes in the implementation in myClass do not require recompiling the dependent code here.

int main() {
    MyClass obj;
    obj.doSomething();
    return 0;
}
