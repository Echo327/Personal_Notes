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
    // Constructor private; cannot be accessed by Factory outside of Point
    Point(float x, float y) : x(x), y(y) {}
    
    float x, y;
    
public:

        // for printing
        friend ostream &operator<<(ostream &os, const Point&p) {
            os << "x = " << p.x << ", y = " << p.y;
            return os;
        }
        
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

};

// Moved inside Point class to provide access to private members
// without breaking OCP
// struct PointFactory
// {
//     static Point NewCartesian(float x, float y)
//     {
//         return {x, y};
//     };
    
//     static Point NewPolar(float r, float theta)
//     {
//         return { r*cos(theta), r*sin(theta) };
//     }
// };

int main()
{
    // This notation allows user to see at first glance that we are going through a Factory
    auto p = Point::PointFactory::NewPolar(5, M_PI_4);
    
    cout << p << endl;
    
    return 0;
}
