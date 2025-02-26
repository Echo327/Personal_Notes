#include <iostream>
#include <vector>

// Component: Abstract Expression
class Expression {
public:
    virtual double evaluate() const = 0; // Common interface
    virtual ~Expression() {}
};

// Leaf: Number
class Number : public Expression {
private:
    double value;
public:
    explicit Number(double val) : value(val) {}
    double evaluate() const override {
        return value;
    }
};

// Composite: Operation (e.g., Addition, Multiplication)
class Operation : public Expression {
private:
    char op; // '+' or '*'
    std::vector<Expression*> operands;
public:
    explicit Operation(char operation) : op(operation) {}

    void addOperand(Expression* operand) {
        operands.push_back(operand);
    }

    double evaluate() const override {
        if (operands.empty()) return 0;

        double result;
        if (op == '*')
        {
            result = 1;
        }
        else
        {
            result = 0;
        }

        for (const auto& operand : operands) {
            if (op == '+')
            {
                result += operand->evaluate();
            }
            else if (op == '*')
            {
                result *= operand->evaluate();
            }
        }
        return result;
    }

    ~Operation() {
        for (Expression* operand : operands) {
            delete operand;
        }
    }
};

int main() {
    Expression* five = new Number(5);
    Expression* two = new Number(2);
    Expression* three = new Number(3);

    // (2 * 3)
    Operation* multiply = new Operation('*');
    multiply->addOperand(two);
    multiply->addOperand(three);

    // 5 + (2 * 3)
    Operation* add = new Operation('+');
    add->addOperand(five);
    add->addOperand(multiply);

    // Evaluating: 5 + (2 * 3) = 11
    std::cout << "Result: " << add->evaluate() << std::endl;

    delete add; // here, this also deletes "multiply"

    return 0;
}
