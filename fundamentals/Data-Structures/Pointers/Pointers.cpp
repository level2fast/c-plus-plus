// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Person
{
    char *Name;
    short Age;
};
struct Rectangle
{
    int length;
    int width;
};
// Memory structure
//
//  -----------------------
// |       HEAP            |
// |                       |
// |                       |
// -------------------------
// |       STACK           |
// |                       |
// |                       |
// -------------------------
// |    PROGRAM MEMORY     |
// |                       |
// |                       |
// -------------------------
int main()
{
    // declare a variable
    int a = 10;
    // declare a pointer to a variable
    int *p;
    cout << "intialize pointer  to point to address of 'a' integer variable" << endl;
    // intialize pointer  to point to address of "a" integer variable
    p = &a;
    cout << "p = &a;" << endl;
    cout << "a: " << a << endl;
    cout << "*p: " << *p << endl
         << endl;

    cout << "allocate memory on the heap in c fashion" << endl;
    // allocate memory on the heap in c fashion
    int *heap_mem;
    cout << "   heap_mem = (int*)malloc(sizeof(int));" << endl;
    heap_mem = (int *)malloc(sizeof(int));
    cout << "memory is now declared on the heap" << endl;
    // memory is now declared on the heap
    cout << "initialize int variable" << endl;
    cout << "   *heap_mem = 20" << endl;
    // initialize int variable
    *heap_mem = 20;
    cout << "dereference pointer to view memory" << endl;
    cout << "   *heap_mem: " << *heap_mem << endl;
    cout << endl
         << endl;

    cout << "allocate memory on the heap in c++ fashion" << endl;
    // allocate memory on the heap in c++ fashion
    cout << "   int *cpp_heap_mem = new int();" << endl;
    int *cpp_heap_mem = new int();
    // initialize int variable
    cout << "initialize int variable" << endl;
    cout << "   *cpp_heap_mem = 30" << endl;
    *cpp_heap_mem = 30;
    cout << "dereference pointer to view memory" << endl;
    cout << "   *cpp_heap_mem:" << *cpp_heap_mem << endl;
    cout << endl;

    cout << "create pointer to an array" << endl;
    // create pointer to an array
    int b[5] = {1, 2, 3, 4, 5};
    int *ptr;
    ptr = b;
    for (int i = 0; i < 5; i++)
        cout << ptr[i] << endl;

    cout << endl;

    cout << "create an array on the heap" << endl;
    // create an array on the heap
    cout << "int* ptr2 = (int*)malloc(sizeof(int) * 5)" << endl;
    int *ptr2 = (int *)malloc(sizeof(int) * 5);
    ptr2[0] = 1;
    ptr2[1] = 1;
    ptr2[2] = 1;
    ptr2[3] = 1;
    ptr2[4] = 1;
    for (int i = 0; i < 5; i++)
        cout << ptr2[i] << endl;

    free(ptr2);

    int *ptr3;
    ptr3 = new int[5];
    ptr3[0] = 1;
    ptr3[1] = 1;
    ptr3[2] = 1;
    ptr3[3] = 1;
    ptr3[4] = 1;
    delete[] ptr3;

    cout << endl
         << "printing pointer size" << endl;
    // pointer size
    int *p_int;
    char *p_char;
    float *p_float;
    double *p_double;
    cout << "int* p_int; sizeof(p_int): " << sizeof(p_int) << endl;
    cout << "char* p_char; sizeof(p_char): " << sizeof(p_char) << endl;
    cout << "float* p_float; sizeof(p_float): " << sizeof(p_float) << endl;
    cout << "double* p_double; sizeof(p_double): " << sizeof(p_double) << endl;

    // pointer to structure c fashion
    Rectangle r = {1, 2};
    Rectangle *r_ptr = &r;
    cout << "r_ptr->length: " << r_ptr->length << endl;
    cout << "r_ptr->width: " << r_ptr->width << endl;
    Rectangle *rect_ptr = (Rectangle *)malloc(sizeof(Rectangle));
    rect_ptr->length = 3;
    rect_ptr->width = 4;

    // pointer to structure c++ fashion
    Rectangle *r_ptr1 = new Rectangle();
    r_ptr1->length = 0;
    r_ptr1->width = 0;

    // Each C++ expression is characterized by two independent properties: a type and a value category.
    // In C++, every expression is either an lvalue or an rvalue.
    // l-values
    // Declaring the variable
    int a{10};

    // Declaring reference to
    // already created variable
    int &b = a; // l-value reference

    // r-values
    int &&rref = 20; // r-value reference

    // l-value object reference example
    // Declare a Person object.
    Person myFriend;

    // Declare a reference to the Person object.
    Person &rFriend = myFriend;

    // Set the fields of the Person object.
    // Updating either variable changes the same object.
    myFriend.Name = "Bill";
    rFriend.Age = 40;

    // Print the fields of the Person object to the console.
    cout << rFriend.Name << " is " << myFriend.Age << endl;
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
