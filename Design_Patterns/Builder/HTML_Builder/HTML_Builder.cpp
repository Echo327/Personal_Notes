// Builder Design Pattern Example
// HTML file Builder
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
};

struct HTML_Builder
{
    HTML_Element root;

    HTML_Builder(string root_tag)
    {
        root.tag = root_tag;
    }

    void add_child(string child_tag, string child_content)
    {
        HTML_Element child{child_tag, child_content};
        root.elements.emplace_back(child);
    }

    string str() const { return root.str(); }
};

int main() {
    HTML_Builder builder{"ul"};
    builder.add_child("li","hello");
    builder.add_child("li","world");

    cout << builder.str() << endl;

    return 0;
}