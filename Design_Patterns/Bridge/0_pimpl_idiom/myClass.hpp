// MyClass.h (Header File)
#ifndef MYCLASS_H
#define MYCLASS_H

#include <memory>

class MyClass {
public:
    MyClass();
    ~MyClass();

    void doSomething();

private:
    class Impl;              // Forward declaration
    std::unique_ptr<Impl> pImpl;  // Pointer to the implementation
};

#endif // MYCLASS_H
