// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// define template class
template <class T>
class Arithmetic
{
public:
    Arithmetic(T a, T b);
    ~Arithmetic();
    T add();
    T sub();

private:
    T a;
    T b;
};

template<class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template<class T>
Arithmetic<T>::~Arithmetic()
{
}

template<class T>
T Arithmetic<T>::add()
{
    return a + b;
}

template<class T>
T Arithmetic<T>::sub()
{
    return a - b;
}
// define rectangle class
class Rectangle
{
public:
    Rectangle()
    {
        length = 0;
        width = 0;
    }
    Rectangle(int l, int w)
    {
        length = l;
        width = w;
    }
    void setLength(int l)
    {
        length = l;
    }
    void setWidth(int w)
    {
        width = w;
    }
    int getLength()
    {
        return length;
    }
    int getWidth()
    {
        return width;
    }
    int area()
    {
        return length * width;
    }
private:
    int length;
    int width;
};

int main()
{
  // create an instance of the class
    Rectangle r(8, 8);
    cout << "r.getLength(): " << r.getLength() << endl;
    cout << "r.getWidth(): " << r.getWidth() << endl;
    cout << "Area: " << r.area() << endl << endl;

    // create instance of templated class
    Arithmetic<int> ar(2, 2);
    cout << "ar.sub(): " << ar.sub() << endl;

    Arithmetic<float> br(2.2, 2.2);
    cout << "br.add(): " << br.add() << endl;
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
