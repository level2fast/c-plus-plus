// Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <exception>
using namespace std;

class myexception : public exception
{
    virtual const char* what() const throw()
    {
        return "Exception occured: n must be greater than or equal to 1";
    }
} myex;
void indirect_recur2(int n);
void indirect_recur(int n);

// Taylor Series
double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return 1;

    r = e(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
}

// recursive function that executes a statement prior to 
// making recursive call
void recursive_func2(int n)
{
    // write base case
    if (n > 0)
    {
        // make recursive call
        cout <<"recursive_func2(int n):"<< n << endl;
        recursive_func2(n - 1);
        
    }
}

// recursive function that executes a statement after 
// making recursive call
void recursive_func1(int n)
{
    // write base case
    if (n > 0)
    {
        // make recursive call
        recursive_func1(n - 1);
        cout <<"recursive_func1(int n)"<< n << endl;
    }
}

// recursive function that makes use of a static variable
// static variable is incremented with each recursive call
// and then added to the return value as each call is popped
// off the call stack. This could also be done with a global 
// variable.
int recursive_func_static_var(int n)
{
    static int x = 0;
    // write base case
    if (n > 0)
    {
        x++;
        // make recursive call
        int retval = recursive_func_static_var(n - 1) + x;
        cout << "retval: " << retval << endl;
        return retval;
    }
    return 0;
}
void tree_recursion(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        tree_recursion(n - 1);
        tree_recursion(n - 1);
    }
}

void indirect_recur2(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        indirect_recur(n / 2);
    }

}
void indirect_recur(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        indirect_recur2(n / 2);
    }

}

int nested_recur(int n)
{
    if (n > 100)
        return n - 10;
    return nested_recur(nested_recur(n + 11));

}

// function to find the sum of natural numbers
int sum(int n)
{
    if (n == 0)
        return 0;
    return sum(n - 1) + n;
}

// Write recursive function to find the factorial
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        try
        {
            throw myex;
        }
        catch (exception& e)
        {
            cout << "fact(int n): " << e.what() << endl;
            return -1;
        }
    }
    else
    {
        return fact(n - 1) * n;
    }
    
}

// write a recursive function to computer the power Ex: b^e
int power(int b, int e)
{
    if (e == 0)
    {
        return 1;
    }
    return power(b, e - 1) * b;
}
int power1(int b, int e)
{
    if (e == 0)
        return 1;
    if (e % 2 == 0)
        return power1(b*b, e / 2) ;
    return b * power1(b * b, (e - 1) / 2);
}
int main()
{
        // call recursive function. Pay special attention to 
        // the order that the integers are printed out.

        // Types of recursion:
        // 1. Tail Recursion: if function calls itself and the function all
        // is the last function in the call.
        // Example:
        cout << "Tail Recursion: recursive_func2(5)" << endl;
        recursive_func2(5);
        cout << endl;
        // 2. Head Recursion: all the processing is done at return time. The function
        // does no processing before making the recursive call 
        // Example:
        cout << "Head Recursion: recursive_func1(5)" << endl;
        recursive_func1(5);
        cout << endl;
        // 3. Tree Recursion: a function that calls itself more than one time.
        // Makes 2^(n+1) - 1 number of calls so Time complexity: O(2^n) for this example.
        // Space complexity: O(n)
        // Example:
        cout << "tree_recursion(5): " << endl;
        tree_recursion(5);
        cout << endl;

        // 4. Indirect Recursion
        // Example:
        cout << "indirect_recur(20): " << endl;
        indirect_recur(20);
        cout << endl;
        // 5. Nested Recursion
        // Example:
        int r;
        r = nested_recur(200);
        cout <<"nested_recur(200): "<< r << endl << endl;

        // 6. Sum of N Recursion
        int result = sum(5);
        cout << "Sum of N Recursion: sum(5): "<< result << endl << endl;

        // 7. Recursive function for finding factorial
        int result_fact = fact(-1);
        cout << "Recursive function for finding factorial: fact(0): " << result_fact << endl << endl;

        // 8. Power recurstion
        int result_power = power(2, 9);
        cout << "Recursive function for computing power b^e: power(2,9): " << result_power << endl << endl;
        int result_power1 = power(2, 9);
        cout << "Fast Recursive function for computing power b^e: power1(2,9): " << result_power1 << endl << endl;

        // static variable and recursion
        cout << "recursive_func_static_var(5):" << recursive_func_static_var(5)<<endl<<endl;

        // Taylor series recursive call e()
        cout << "Recursive function for computing Taylor Series: " << e(4, 15) << endl << endl;

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
