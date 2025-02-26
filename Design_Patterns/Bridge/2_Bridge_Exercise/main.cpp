#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Renderer Interface
struct Renderer {
    virtual string what_to_render_as() const = 0;
    virtual ~Renderer() = default;
};

// Concrete Implementations
struct VectorRenderer : Renderer {
    string what_to_render_as() const override {
        return "as lines";
    }
};

struct RasterRenderer : Renderer {
    string what_to_render_as() const override {
        return "as pixels";
    }
};

// Shape Abstraction (Bridge)
struct Shape {
    string name;
    shared_ptr<Renderer> renderer;

    Shape(string name, shared_ptr<Renderer> renderer)
        : name(move(name)), renderer(move(renderer)) {}

    virtual string str() const {
        return "Drawing " + name + " " + renderer->what_to_render_as();
    }

    virtual ~Shape() = default;
};

// Concrete Shapes
struct Triangle : Shape {
    Triangle(shared_ptr<Renderer> renderer)
        : Shape("Triangle", move(renderer)) {}
};

struct Square : Shape {
    Square(shared_ptr<Renderer> renderer)
        : Shape("Square", move(renderer)) {}
};

// Main Function
int main() {
    auto rasterRenderer = make_shared<RasterRenderer>();
    auto vectorRenderer = make_shared<VectorRenderer>();

    Triangle triangle(rasterRenderer);
    Square square(vectorRenderer);

    cout << triangle.str() << endl; // Drawing Triangle as pixels
    cout << square.str() << endl;   // Drawing Square as lines

    return 0;
}
