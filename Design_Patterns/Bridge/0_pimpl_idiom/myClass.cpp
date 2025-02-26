// MyClass.cpp (Actual Implementation)
// This file does not even need to be shipped to the client
// it can contain a lot of private (secret) methods
// and a compiled version only is shipped to the client
// (along with the header with only the public implementation available)
// This way also this file can be changed and shipped to the client without needing the
// client to recompile their code to make use of a new version
#include "MyClass.hpp"
#include <iostream>

class MyClass::Impl {
public:
    void doSomething() {
        std::cout << "Doing something in Impl!" << std::endl;
    }
};

MyClass::MyClass() : pImpl(std::make_unique<Impl>()) {}

MyClass::~MyClass() = default;

void MyClass::doSomething() {
    pImpl->doSomething();
}
