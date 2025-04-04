// Disclaimer: This file is entirely
// Generated by OpenAI's ChatGPT-4, February 2025

#include <iostream>
#include <memory> // For unique_ptr

class MyClass {
public:
    MyClass() { std::cout << "MyClass Constructor\n"; }
    ~MyClass() { std::cout << "MyClass Destructor\n"; }

    void display() { std::cout << "Hello from MyClass\n"; }
};

int main() {
    // Creating a unique_ptr to manage the object
    std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();

    ptr->display();  // Using the object through the unique_ptr

    // No need to delete the object, it will be automatically destroyed when ptr goes out of scope

    return 0;
}
