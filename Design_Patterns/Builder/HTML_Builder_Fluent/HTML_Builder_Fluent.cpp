// Builder Design Pattern Example
// HTML file Builder with Fluent interface
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct HTML_Element
{
    string tag, content;
    vector<HTML_Element> elements;
    const size_t indent_size = 2;

    HTML_Element() {}

    HTML_Element(const string &tag, const string &content) : tag(tag), content(content) {}

    string str(int indent = 0) const
    {
        ostringstream oss;

        // Open Tag
        oss << string(indent_size*indent, ' ') << "<" << tag << ">" << endl;
        
        // Content
        // Sub-Elements
        for (const auto& e : elements)
        {
            oss << e.str(indent + 1);
        }

        // Text
        if (content.size() > 0)
        {
            oss << string(indent_size*(indent + 1), ' ') << content << endl;
        }

        // Closing Tag
        oss << string(indent_size*indent, ' ') << "</" << tag << ">" << endl;

        return oss.str();
    }

    // Example: In order to make Builder more apparent to API user
    // static HTML_Builder build(string root_name)
    // {
    //     return {root_name};
    // }

    // Alternatively, to force users to use builder,
    // change variables and constructors to private in an HTML_Element class
    // with friend class HTML_Builder
    // Same for HTML_Builder, one could make constructors private so it's not visible to the user

};

struct HTML_Builder
{
    HTML_Element root;

    HTML_Builder(string root_tag)
    {
        root.tag = root_tag;
    }

    // Fluid interface: add_child should return pointer reference instead of void
    HTML_Builder& add_child(string child_tag, string child_content)
    {
        HTML_Element child{child_tag, child_content};
        root.elements.emplace_back(child);
        // Fluid Interface: Return reference
        // Alternatively, return pointer itself instead of reference to work with pointers directly
        return *this;
    }

    string str() const { return root.str(); }

    // To allow to create HTML Element using build + add_child
    operator HTML_Element() const { return root;}
};

int main() {
    HTML_Builder builder{"ul"};

    // Fluid interface allows stacking add_child
    builder.add_child("li","hello").add_child("li","world");

    cout << builder.str() << endl;

    // build and add_child at the same time
    // auto builder2 = HTML_Element::build("ul").add_child("li","oh");

    // This requires adding an operator as HTML_Builder is returned
    // HTML_Element element = HTML_Element::build("ul").add_child("li","oh");

    return 0;
}