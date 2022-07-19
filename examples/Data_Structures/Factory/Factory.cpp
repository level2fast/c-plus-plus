// Factory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
// Why do we need the Factory design pattern?
// - Object creation logic becomes to convoluted
// - Constructor is not descriptive
// - Object creation
//
// In summary the Factory design pattern is about having a component
// solely responsible for the wholesale creation of objects.

#include<cmath>
#include <iostream>
using namespace std;

// Factory Method design pattern

class Point
{
public:
    Point(float x, float y) :x(x), y(y) {}


    float x, y;
    static Point newCartesian(float x, float y)
    {
        return { x,y };
    }
    static Point newPolar(float r, float theta)
    {
        return { r*cos(theta),r*sin(theta) };
    }
    friend ostream& operator<<(ostream& os, const Point& point)
    {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
};

struct PointFactory
{
    static Point newCartesian(float x, float y)
    {
        return { x,y };
    }
    static Point newPolar(float r, float theta)
    {
        return { r * cos(theta),r * sin(theta) };
    }
};



// Inner Factory
class Point_IF
{
public:
    Point_IF(float x, float y) :x(x), y(y) {}


    float x, y;
    static Point_IF newCartesian(float x, float y)
    {
        return { x,y };
    }
    static Point_IF newPolar(float r, float theta)
    {
        return { r * cos(theta),r * sin(theta) };
    }
    friend ostream& operator<<(ostream& os, const Point_IF& point)
    {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
    static PointFactory Factory;
private:
    struct PointFactory_inner
    {
        static Point_IF newCartesian(float x, float y)
        {
            return { x,y };
        }
        static Point_IF newPolar(float r, float theta)
        {
            return { r * cos(theta),r * sin(theta) };
        }
    };
};
int main()
{
    // Example of Factory Design Pattern
    
    // Use PointFactory to create a new point
    auto pf = PointFactory::newCartesian(3, 3);
    cout << pf << endl;
    
    // Use static function to create new Point
    auto p = Point::newPolar(5, 3.14);
    cout << p << endl;

    // Example of inner factory 
    auto pf_inner = Point_IF::Factory.newCartesian(3, 3);
    cout << pf_inner << endl;

    // Abstract Factory

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
