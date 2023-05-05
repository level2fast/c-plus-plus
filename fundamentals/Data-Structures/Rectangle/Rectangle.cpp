// Rectangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
std::map<std::string, int> rec1 = {
            { "x", 2 },
            { "y", 4 },
            { "w", 5 },
            { "h", 12 } };
std::map<std::string, int> rec2 = {
            { "x", 1 },
            { "y", 5 },
            { "w", 7 },
            { "h", 14 } };

std::map<std::string, int> compareRectangle(std::string x, std::string w, std::string y, std::string h)
{
    std::map<std::string, int> overlap;
    // Use min and max function to find
    // the min of the max's and max's of the 
    // min
    int min_x_plus_w = std::min(rec1[x] + rec1[w], rec2[x] + rec2[w]);
    int max_x_plus_x = std::max(rec1[x], rec2[x]);

    int min_y_plus_h = std::min(rec1[y] + rec1[h], rec2[y] + rec2[h]);
    int max_y_plus_y = std::max(rec1[y], rec2[y]);

    if (rec2[x] > rec1[x] && rec2[x] < min_x_plus_w)
    {
        int overlap_x = rec2[x];
        int overlap_w = min_x_plus_w;
        cout << "overlap_x: " << overlap_x << endl << "overlap_w: " << overlap_w << endl;
        overlap[x] = overlap_x;
    }

    return overlap;
}
int main()
{


   

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
