#include <iostream>
#include "matrix.h"

using namespace std;

bool in_column(int col, int num)
{

    return 
}

bool in_row()
{

}

bool in_box()
{

}

Matrix solver(Matrix sudoku)
{
    Matrix solution = sudoku;

    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            
        }
    }

    return solution;
}

int main(){

    Matrix A(9,9,0);

    cin>>A;

    // Output result
    Matrix B = solver(A);
    cout<<B;

    return 0;
}
