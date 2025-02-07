// This is generated using ChatGPT-4o and copied as is

#include <iostream>
#include <vector>
#include <string>

class ClassGenerator {
private:
    std::string class_name;
    std::vector<std::pair<std::string, std::string>> fields;  // stores (type, name) of fields
    std::vector<std::pair<std::string, std::string>> methods;  // stores (signature, body) of methods

public:
    // Constructor to set class name
    ClassGenerator(const std::string& name) : class_name(name) {}

    // Method to add a field to the class
    void addField(const std::string& field_type, const std::string& field_name) {
        fields.push_back({field_type, field_name});
    }

    // Method to add a method with its body
    void addMethod(const std::string& method_signature, const std::string& method_body) {
        methods.push_back({method_signature, method_body});
    }

    // Method to print the generated C++ code for this class
    void printClass() const {
        // Print the class definition
        std::cout << "class " << class_name << " {\n";
        std::cout << "private:\n";

        // Print all fields
        for (const auto& field : fields) {
            std::cout << "    " << field.first << " " << field.second << ";\n";
        }

        std::cout << "public:\n";

        // Print the constructor (a default constructor)
        std::cout << "    " << class_name << "() {}\n";

        // Print all methods with their bodies
        for (const auto& method : methods) {
            std::cout << "    " << method.first << " {\n";
            std::cout << "        " << method.second << "\n";
            std::cout << "    }\n";
        }

        std::cout << "};\n";
    }
};

int main() {
    // Create a ClassGenerator for a class named "Person"
    ClassGenerator personClass("Person");

    // Add some fields
    personClass.addField("std::string", "name");
    personClass.addField("int", "age");

    // Add some methods with body
    personClass.addMethod("void setName(const std::string& newName)", "name = newName;");
    personClass.addMethod("void setAge(int newAge)", "age = newAge;");
    personClass.addMethod("std::string getName() const", "return name;");
    personClass.addMethod("int getAge() const", "return age;");

    // Print the C++ code representation of the generated class
    personClass.printClass();

    return 0;
}
