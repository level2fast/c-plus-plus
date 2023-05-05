// Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// pass params by value
int add(int a, int b)
{
    int c = a + b;
    return c;
}

// pass params by address
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// pass params by reference
void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// pass array to function
void arrfunc(int temp[] )
{
    cout<<"arrfunc() temp[0]:" << temp[0] << endl << endl;
}


struct Rectangle
{
    int length;
    int width;
};
void struct_func(Rectangle r)
{
    cout << "struct_func_ptr(): r.length: " << r.length << endl;
    cout << "struct_func_ptr(): r.widht: " << r.width << endl << endl;
}
void struct_func(Rectangle* r)
{
    cout << "struct_func(): r->length: " << r->length << endl;
    cout << "struct_func(): r->widht: " << r->width << endl << endl;
}
void struct_func_byref(Rectangle &r)
{
    r.length = 10;
    r.width = 10;
}
struct Rectangle* struct_func_rect()
{
    Rectangle* ptr;
    ptr = new Rectangle();
    ptr->length = 9;
    ptr->width = 90;
    return ptr;
}
int main()
{
    // call add function
    int num = add(1, 1);
    cout << "num: " << num << endl;

    // parameter passing

    // call by value
    add(2, 2);

    // call by address
    int* a = new int(1);
    int* b = new int(2);
    cout << "call by address" << endl;
    cout << "Before swap " << endl << "a: " << *a << endl << "b: " << *b << endl;
    swap(a, b);
    cout << "After swap " << endl << "a: " << *a << endl << "b: " << *b << endl << endl;

    // call by reference
    cout << "call by reference" << endl;
    int aa = 9;
    int bb = 0;
    cout << "before swap " << endl << "aa: " << aa << endl <<"bb: "<< bb << endl;
    swap(aa, bb);
    cout << "After swap " << endl << "aa: " << aa << endl << "bb: " << bb << endl << endl;

    // Pass an array as a parameter
    cout << "Pass an array as a parameter" << endl;

    int arr[3] = { 0 };
    arrfunc(arr);

    // pass structure as a parameter
    Rectangle r = {2,2};

    // pass struct to function by value
    cout << "pass struct to function by value" << endl;
    struct_func(r);

    // call function that passes struct by reference
    cout << "call function that passes struct by reference" << endl;
    struct_func_byref(r);
    cout << "new r.length: " << r.length << endl << "new r.width: " << r.width << endl << endl;

    // call function that passes struct by address
    cout << "call function that passes struct by address" << endl;
    struct_func(&r);

    // call function that returns Rectangle as pointer
    cout << "call function that returns Rectangle as pointer" << endl;
    Rectangle *temp = struct_func_rect();
    cout << "temp->length: " << temp->length << endl <<"temp->width: "<< temp->width<<endl<<endl;

    return 0;
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
