// Factory Method / Abstract Factory
// Simple Example: 2D point in space

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <ostream>

using namespace std;

enum class PointType
{
    cartesian,
    polar
};

class Point
{
    // friend class PointFactory; // allows Factory acces to constructor but violates Open-Closed Principle (OCP)
    // alternatively make constructor public as below to not break OCP
    
public:
    Point(float x, float y) : x(x), y(y) {}
    
    // public:
        float x, y;
        
        // for printing
        friend ostream &operator<<(ostream &os, const Point&p) {
            os << "x = " << p.x << ", y = " << p.y;
            return os;
        }
};

// Dedicated Factory (to separare concerns)
// concrete, not abstract
// not present in Gang of Four
class PointFactory
{
    PointFactory() {}
    public:
    static Point NewCartesian(float x, float y)
    {
        return {x, y};
    };
    
    static Point NewPolar(float r, float theta)
    {
        return { r*cos(theta), r*sin(theta) };
    }
};

int main()
{
    // requires friend class as variables are private
    // violates Open-Closed Principle
    auto p = PointFactory::NewPolar(5, M_PI_4);
    
    cout << p << endl;
    
    // Making the constructor public also allows direct point creation
    Point p2{2,3};
    cout << p2 << endl;
    
    return 0;
}
