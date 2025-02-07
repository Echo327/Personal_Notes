// Factory Method / Abstract Factory
// Simple Example: 2D point in space
//! Will not compile, see Singleton

#include <iostream>
#include <cmath>
#include <ostream>

using namespace std;

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
        
       // This is called an inner factory because PointFactory is inner class to Point
       // see Singleton for concrete application of this line as choice of implementation
       // PointFactory needs to be instanciated for this to work
       //  Alternatively, other choices of implementation include a getFactory method, etc.
       // Implementation is open to variation
        static PointFactory Factory;

private:
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

int main()
{
    // This notation allows user to see at first glance that we are going through a Factory
    auto p = Point::Factory.NewCartesian(3, 4);
    
    cout << p << endl;
    
    return 0;
}
