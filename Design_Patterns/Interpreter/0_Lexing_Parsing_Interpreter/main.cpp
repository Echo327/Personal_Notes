#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <stdexcept>

// Lexer class to tokenize the input
class Lexer {
public:
    std::vector<std::string> lex(const std::string& expression) {
        std::vector<std::string> tokens;
        std::stringstream ss(expression);
        std::string token;

        while (ss >> token) {
            tokens.push_back(token);
        }

        return tokens;
    }
};

// Parser takes the tokens from the lexer and
// arranges them according to the grammar rules.
// It checks for syntax errors and converts the sequence
// of tokens into a meaningful structure (AST or simple representation)
class Parser {
public:
    // Parse the tokens and build an expression structure
    std::vector<std::string> parse(const std::vector<std::string>& tokens) {
        // In this example, we expect a simple binary operation (e.g., "a+b")
        if (tokens.size() != 3) {
            throw std::invalid_argument("Invalid expression format.");
        }
        
        return tokens;  // For simplicity, just return the tokens as a parsed expression
    }
};

// Interpreter class to evaluate the parsed expression
class Interpreter {
private:
    std::map<std::string, int> variables;  // Stores variable values (like 'a' and 'b')

public:
    // Method to interpret the parsed expression (a vector of tokens)
    int interpret(const std::vector<std::string>& parsedExpression) {
        std::string var1 = parsedExpression[0];
        std::string op = parsedExpression[1];
        std::string var2 = parsedExpression[2];

        // Lookup variables (e.g., 'a' and 'b') in the variables map
        int value1 = variables[var1];  // Find the value of 'a' (if defined)
        int value2 = variables[var2];  // Find the value of 'b' (if defined)

        // Perform the operation based on the operator
        if (op == "+") {
            return value1 + value2;
        } else {
            std::cerr << "Unknown operator: " << op << std::endl;
            return 0;
        }
    }

    void assign(const std::string& variable, int value) {
        variables[variable] = value;
    }
};

int main() {
    Lexer lexer;
    Parser parser;
    Interpreter interpreter;

    // Assign values to variables
    interpreter.assign("a", 5);
    interpreter.assign("b", 10);

    // Tokenize the expression "a + b" into [a, +, b]
    std::string expression = "a + b";
    std::vector<std::string> tokens = lexer.lex(expression);

    // Parse the tokens to create a structured expression (here, just return tokens)
    std::vector<std::string> parsedExpression = parser.parse(tokens);

    // Interpret the parsed expression
    int result = interpreter.interpret(parsedExpression);  // Interprets the tokens as "a + b"

    std::cout << "Result of a + b: " << result << std::endl;  // Should print 15

    return 0;
}
