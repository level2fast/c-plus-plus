// TimeComplexity_BigO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int A[10][10];
int B[10][10];

// describe Big O for this fucntion
int sum(int A[], int n)
{
    int s, i;
    s = 0; // time - 1 
    for (i = 0; i < n; i++) // time n + 1
    {
        s = s + A[i]; // time - n
    }

    return s; // time - 1 

    // Time function: 1/(f(n) = 2n+3)
    // Big O: O(n)
}

// calculate the Big O for this function//
void add(int n)
{
    int i, j;
    int c[10][10];
    for (i = 0; i < n; i++) // time n + 1
    {
        for (j = 0; j < n; j++) // time - n(n+1)
        {
            c[i][j] = A[i][j] + B[i][j]; // time - nxn
        }
    }

    // Time function: f(n) = 2n^2 + 2n + 1
    // Big O: O(n^2)

}

// Describe big O for this fucntion
void swap(int& a, int& b)
{
    int temp = a; // time - 1
    a = b;        // time - 1
    b = temp;     // time - 1
    // Time Function: f(n) = 3n^0
    // O(1)
    // Big O: O(n^0) = O(1)
}

void fun2()
{
    int i, n;
    n = 90;
    for (i = 0; i < n; i++) // time n + 1
    {
        i = 1; // time - n
    }
    // Time function: f(n) = 2n+1
    // Big O: O(n)
}
// Describe the Big O for this function
void fun1()
{
    // First determine Big O of fun2
    fun2(); // Big O(n)
    // Time function
}

int main()
{
    /*Counter variables for the loop*/
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            A[i][j] = 10;
            B[i][j] = 10;
        }
    }

    
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
