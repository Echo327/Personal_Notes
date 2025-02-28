#include <iostream>
#include <string>
using namespace std;

struct Flower {
    virtual string str() = 0;
    virtual ~Flower() = default;
};

struct Rose : Flower {
    string str() override {
        return "A rose";
    }
};

// Decorator: RedFlower
struct RedFlower : Flower {
    Flower& flower;

    RedFlower(Flower& f) : flower(f) {}

    string str() override {
        string description = flower.str();
        if (description.find("red") == string::npos) {
            if (description.find("blue") != string::npos) {
                return description + " and red";
            }
            return description + " that is red";
        }
        return description; // Avoid duplicates
    }
};

// Decorator: BlueFlower
struct BlueFlower : Flower {
    Flower& flower;

    BlueFlower(Flower& f) : flower(f) {}

    string str() override {
        string description = flower.str();
        if (description.find("blue") == string::npos) {
            if (description.find("red") != string::npos) {
                return description + " and blue";
            }
            return description + " that is blue";
        }
        return description; // Avoid duplicates
    }
};

int main() {
    Rose rose;
    RedFlower red_rose{rose};
    BlueFlower blue_red_rose{red_rose};
    BlueFlower blue_rose{rose};
    RedFlower red_blue_rose{blue_rose};

    cout << rose.str() << endl;            // "A rose"
    cout << red_rose.str() << endl;        // "A rose that is red"
    cout << blue_red_rose.str() << endl;   // "A rose that is red and blue"
    cout << blue_rose.str() << endl;       // "A rose that is blue"
    cout << red_blue_rose.str() << endl;   // "A rose that is blue and red"

    return 0;
}
