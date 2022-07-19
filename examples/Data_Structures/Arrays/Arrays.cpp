// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    // create an array on the stack
    int A[10];

    // create an arary on the heap
    int* p = (int*) malloc(sizeof(int) * 10);

    // create a 2D array on stack
    int two_d_arr[3][5] = { {1,2,3,4,5},{1,2,3,4,5} ,{1,2,3,4,5} };
    
    // create 2D array on heap

    // rows created on stack and array created on heap
    int* ptr_to_row[3];
    ptr_to_row[0] = (int*)malloc(sizeof(int)*3);
    ptr_to_row[1] = (int*)malloc(sizeof(int) * 3);
    ptr_to_row[2] = (int*)malloc(sizeof(int) * 3);

    // rows are created in heap and array is created in heap
    int** ptr_to_row_heap = (int**)malloc(sizeof(int*)*3);
    ptr_to_row_heap[0] = (int*)malloc(sizeof(int) * 3);
    ptr_to_row_heap[1] = (int*)malloc(sizeof(int) * 3);
    ptr_to_row_heap[2] = (int*)malloc(sizeof(int) * 3);

    

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
