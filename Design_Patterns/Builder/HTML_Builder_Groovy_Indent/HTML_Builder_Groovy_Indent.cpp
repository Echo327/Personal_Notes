// Builder Design Pattern Example
// HTML file Builder using uniform initialisation syntax
// create a domain-specific language that ressembles HTML code a lot
// in the eyes of the user

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const size_t indent_size = 2;

struct Tag
{
    string name, text;
    vector<Tag> children;
    vector<pair<string,string>> attributes;

    // Note: Operator overload for printing Tag
    friend ostream &operator<<(ostream &os, const Tag &tag)
    {
        static int indent = 0;

        // Note: Opening Tag
        os << string(indent_size*indent, ' ') << "<" << tag.name;
        
        // Note: Attributes in Tag
        for (const auto& att : tag.attributes)
            os << " " << att.first << "=\"" << att.second << "\"";

        indent++;

        // Note: Close Opening Tag
        if (tag.children.empty() && tag.text.empty())
        {
            os << "/>" << endl;
        }
        else
        {
            // Note: Sub-Items (Content)
            os << ">" << endl;

            if (!tag.text.empty())
            {
                indent++;
                os << string(indent_size*indent, ' ') << tag.text << endl;
            }

            for (const auto& child : tag.children)
            {
                os << string(indent_size*indent, ' ') << child;
                indent--;
            }

            // Note: Closing Tag
            indent--;
            os << string(indent_size*indent, ' ') << "</" << tag.name << ">" << endl;
        }
        
        return os;
    }

    protected:
    public:
        Tag(const string &name, const string &text) : name(name), text(text) {}

        Tag(const string &name, const vector<Tag> &children)
          : name(name), children(children) {}
};

// Paragraph
struct P : Tag
{
    P(const string &text) : Tag("p", text) {}

    P(initializer_list<Tag> children)
      : Tag{"p", children} {}
};

struct A : Tag
{
    A(const string &text) : Tag("a", text) {}

    A(initializer_list<Tag> children)
      : Tag{"a", children} {}
};

struct IMG : Tag
{
    explicit IMG(const string &url) : Tag{"img", ""}
    {
        attributes.emplace_back(make_pair("src", url));
    }
};

int main()
{
    cout <<
        P {
            IMG { "https://www.google.com/images/branding/googlelogo/2x/googlelogo_color_272x92dp.png" }
        }
    << endl;

    cout <<
        P {
            A {
                "test text"
            }
        }
    << endl;

    return 0;
}
