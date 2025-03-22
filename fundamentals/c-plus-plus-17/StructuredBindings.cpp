// Like a reference, a structured binding is an alias to an existing object.
// Unlike a reference, a structured binding does not have to be of a reference type.
#include <iostream>

int main()
{
    // basic usage, binds a to the "x" and "y" variables
    int a[2] = {1, 2};
    auto [x, y] = a;

    auto &[xr, yr] = a; // xr refers to a[0], yr refers to a[1]

        return 0;
}
