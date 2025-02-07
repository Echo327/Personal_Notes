#include <string>
#include <ostream>
#include <vector>
#include <iostream>
using namespace std;

struct Code_Element
{
    string class_name, name, str;
    vector<Code_Element> elements;
    const size_t indent_size = 2;

    Code_Element() {}

    Code_Element(const string& class_name) : class_name(class_name) {}

    Code_Element(const string& name, const string& str) : name(name), str(str) {}
};

class CodeBuilder
{
    Code_Element root;

public:
    CodeBuilder() {};

    CodeBuilder(const string& class_name)
    {
        root.class_name = class_name;
    }

CodeBuilder& add_field(const string& name, const string& type)
{
    Code_Element child{name, type};
    root.elements.emplace_back(child);
    return *this;
}

void print_code_element(ostream& os, const Code_Element& elem, size_t indent = 0) const
{
    string indent_str(indent, ' ');

    if (!elem.class_name.empty()) {
        os << indent_str << "class " << elem.class_name << endl;
        os << "{" << endl;
    }

    indent++;

    if (!elem.elements.empty()) {
        for (size_t i = 0; i < elem.elements.size(); ++i) {
            const auto& field = elem.elements[i];
            os << string(root.indent_size * indent, ' ') << field.str << " " << field.name << ";" << endl;

            if (i == elem.elements.size() - 1) {
                os << indent_str << "};" << endl;
            }
        }

        for (const auto& child : elem.elements) {
            print_code_element(os, child, indent + root.indent_size);
        }
    }
    else
    {
        if (!elem.class_name.empty()) {
            os << indent_str << "};" << endl;
        }
    }
}

friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
    {
        obj.print_code_element(os, obj.root);
        return os;
    }
};

int main()
{
    CodeBuilder cb("Person");

    cb.add_field("name", "string").add_field("age", "int");

    cout << cb << endl;

    CodeBuilder cb2("Empty");

    cout << cb2 << endl;

    return 0;
}