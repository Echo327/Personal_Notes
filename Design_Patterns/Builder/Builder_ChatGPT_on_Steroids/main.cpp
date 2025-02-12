#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>

class ClassBuilder {
private:
    std::string className;
    std::vector<std::string> variables;
    std::vector<std::string> methods;
    std::set<std::string> variableNames;
    std::set<std::string> methodNames;

public:
    // Set the class name
    ClassBuilder& name(const std::string& name) {
        if (name.empty()) {
            throw std::invalid_argument("Class name cannot be empty.");
        }
        className = name;
        return *this;
    }

    // Add a variable (attribute)
    ClassBuilder& add_variable(const std::string& varType, const std::string& varName) {
        if (varName.empty()) {
            throw std::invalid_argument("Variable name cannot be empty.");
        }

        // Ensure unique variable names
        if (variableNames.find(varName) != variableNames.end()) {
            throw std::invalid_argument("Variable name \"" + varName + "\" is already defined.");
        }

        // Add to list of variables and ensure the name is tracked
        variables.push_back(varType + " " + varName + ";");
        variableNames.insert(varName);
        return *this;
    }

    // Add a method
    ClassBuilder& add_method(const std::string& methodSignature, const std::string& methodBody) {
        if (methodNames.find(methodSignature) != methodNames.end()) {
            throw std::invalid_argument("Method \"" + methodSignature + "\" is already defined.");
        }

        // Add to list of methods and ensure the signature is tracked
        methods.push_back(methodSignature + " {\n" + methodBody + "\n}");
        methodNames.insert(methodSignature);
        return *this;
    }

    // Generate and return the full C++ class definition
    std::string build() const {
        std::string classCode;
        
        if (className.empty()) {
            throw std::runtime_error("Class name is not set.");
        }

        classCode += "class " + className + " {\nprivate:\n";
        
        // Add variables
        for (const auto& var : variables) {
            classCode += "    " + var + "\n";
        }

        classCode += "\npublic:\n";

        // Add methods
        for (const auto& method : methods) {
            classCode += "    " + method + "\n";
        }

        classCode += "};\n";
        return classCode;
    }
};

int main() {
    try {
        // Dynamically build the Person class with edge case handling in the builder
        ClassBuilder builder;
        std::string personClassCode = builder
            .name("Person")  // Set the class name
            .add_variable("std::string", "name")  // Add a variable
            .add_variable("int", "age")  // Add another variable
            .add_method("Person(std::string inputName, int inputAge)", 
                        "name(inputName), age(inputAge) {}")  // Add the constructor
            .add_method("std::string getName() const", "return name;")  // Add a getter
            .add_method("int getAge() const", "return age;")  // Add another getter
            .add_method("void displayInfo() const", 
                        "std::cout << \"Name: \" << name << \", Age: \" << age << std::endl;")  // Add a display method
            .build();

        // Output the generated class code
        std::cout << personClassCode << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
