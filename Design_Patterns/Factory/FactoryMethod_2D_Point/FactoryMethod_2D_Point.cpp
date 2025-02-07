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

//! Pb with Constructor
//! \param a is either x or rho
//! \param b is either y or theta
//! \param type needs to be specified
// struct Point
// {
//     Point(float a, float b, PointType type = PointType::cartesian)
//     {
//         switch(type)
//         {
//             case PointType::cartesian:
//                 x = a;
//                 y = b;
//             case PointType::polar:
//                 x = a *cos(b);
//                 y = a *sin(b);
//             default:
//                 return -1;
//         }
//     }
// };

class Point
{
    // Does not allow use of constructor (Point p{1,2}) as it's private
    Point(float x, float y) : x(x), y(y) {}
    
    public:
        float x, y;
        
        // Factory Method
        static Point NewCartesian(float x, float y)
        {
            // Modern C++ infers Point from return type of the method itself
            // return Point{x, y};
            return {x, y};
        };
        
        static Point NewPolar(float r, float theta)
        {
            return { r*cos(theta), r*sin(theta) };
        }
        
        // for printing
        friend ostream &operator<<(ostream &os, const Point&p) {
            os << "x = " << p.x << ", y = " << p.y;
            return os;
        }
};

int main()
{
    auto p = Point::NewPolar(5, M_PI_4);
    cout << p << endl;
    
    return 0;
}
