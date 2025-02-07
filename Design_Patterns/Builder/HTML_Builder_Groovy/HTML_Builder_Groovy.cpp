// Builder Design Pattern Example
// HTML file Builder using uniform initialisation syntax
// create a domain-specific language that ressembles HTML code a lot
// in the eyes of the user

#include <iostream>
#include <vector>
using namespace std;

struct Tag
{
    string name, text;
    vector<Tag> children;
    vector<pair<string,string>> attributes;

    // Note: Operator overload for printing Tag
    friend ostream &operator<<(ostream &os, const Tag &tag)
    {
        // Note: Opening Tag
        os << "<" << tag.name;
        
        // Note: Attributes in Tag
        for (const auto& att : tag.attributes)
            os << " " << att.first << "=\"" << att.second << "\"";

        // Note: Close Opening Tag
        if (tag.children.size() == 0 && tag.text.length() == 0)
        {
            os << "/>" << endl;
        }
        else
        {
            // Note: Sub-Items (Content)
            os << ">" << endl;

            if (tag.text.length())
                os << tag.text << endl;

            for (const auto& child : tag.children)
                os << child;

            // Note: Closing Tag
            os << "</" << tag.name << ">" << endl;
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

    return 0;
}