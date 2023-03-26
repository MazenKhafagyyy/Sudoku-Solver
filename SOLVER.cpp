#include <iostream>
#include <fstream>
#include "matrix.h"

#define N 9

using namespace std;

bool isPresentInCol(int col, int num, Matrix &sudoku){ //check whether num is present in col or not
    for (int row = 0; row < N; row++)
        if (sudoku[row][col] == num)
            return true;
    return false;
}

bool isPresentInRow(int row, int num, Matrix &sudoku){ //check whether num is present in row or not
    for (int col = 0; col < N; col++)
        if (sudoku[row][col] == num)
            return true;
    return false;
}

bool isPresentInBox(int boxStartRow, int boxStartCol, int num, Matrix &sudoku){
//check whether num is present in 3x3 box or not
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (sudoku[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}

bool findEmptyPlace(int &row, int &col, Matrix &sudoku){ //get empty location and update row and column
   for (row = 0; row < N; row++)
      for (col = 0; col < N; col++)
         if (sudoku[row][col] == 0) //marked with 0 is empty
            return true;
   return false;
}

bool isValidPlace(int row, int col, int num, Matrix &sudoku){
    //when item not found in col, row and current 3x3 box
    return !isPresentInRow(row, num, sudoku) && !isPresentInCol(col, num, sudoku) && !isPresentInBox(row - row%3 ,
col - col%3, num, sudoku);
}

bool solveSudoku(Matrix &sudoku){
    int row, col;

    if (!findEmptyPlace(row, col, sudoku))
        return true; //when all places are filled
    for (int num = 1; num <= 9; num++){ //valid numbers are 1 - 9
        if (isValidPlace(row, col, num, sudoku)){ //check validation, if yes, put the number in the grid
            sudoku[row][col] = num;
            if (solveSudoku(sudoku)) //recursively go for other rooms in the grid
                return true;
            sudoku[row][col] = 0; //turn to unassigned space when conditions are not satisfied
        }
    }
   return false;
}

int main(){

    Matrix sudoku(9,9,0);
    ifstream fin("input.txt", ios::in);
    ofstream fout("solution.txt", ios::out);
    
    for (int i = 0; i < 81; i++)
    {
        fin>>sudoku;
    }

    if (solveSudoku(sudoku) == true)
        for (int row = 0; row < N; row++){
            for (int col = 0; col < N; col++){
                if(col == 3 || col == 6)
                    fout << " | ";
                fout << sudoku[row][col] <<" ";
            }
        if(row == 2 || row == 5){
            fout << endl;
            for(int i = 0; i<N; i++)
                fout << "---";
      }
      fout << endl;
   }
    else
       fout << "No solution exists";
}