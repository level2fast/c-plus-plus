// Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct Rectangle
{
    int length;
    int width;
    //char padding[3];
    char x;
}r1,r2,r3;

int main()
{
    r2 = { 5,5 };
    r1.length = 20;
    r1.width = 22;
    std::cout <<" r1.length"<< r1.length << std::endl;
    std::cout << "r1.width" << r1.width << std::endl;
    std::cout << "r2.width" << r2.length << std::endl;
    std::cout << "r2.width" << r2.width << std::endl;

    std::cout << "sizeof(r1)" << sizeof(r1) << std::endl;
    std::cout << "sizeof(r2)" << sizeof(r2) << std::endl;

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
