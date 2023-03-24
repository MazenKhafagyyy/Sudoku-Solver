/* 
---------------------------------------------------
Name : Mazen Khafagy
SID: 1709867
CCID : mkhafagy
AnonID : 1000318443
CMPUT 275 , Winter 2023

Assessment: Weekly Exercice #5 (Matrix Class)
---------------------------------------------------
*/

#include <iostream>
using namespace std;

class Matrix {
public:

    // Constructors.

    // Constructor using a float value to fill entire matrix.
    Matrix(size_t num_rows, size_t num_columns, float init);

    // Constructor using a float array to fill matrix.
    Matrix(size_t num_rows, size_t num_columns, float * arr_ptr);

    // Deepcopy constructor.
    Matrix(const Matrix& rhs);

    // Destructor.
    ~Matrix();

    // Operator Overloading.

    // Matrix Addition.
    Matrix operator+ (const Matrix& rhs);

    // Matrix Subtraction.
    Matrix operator- (const Matrix& rhs);

    // Matrix Multiplication.
    Matrix operator* (const Matrix& rhs);

    // Matrix Negation.
    Matrix operator- ();

    // Matrix Value Setting and Getting.
    float* operator[] (size_t index);           //Setter
    float* operator[] (size_t index) const;     //Getter

    // Insertion and Extraction Overloading.
    // Used friend keyword to use private and protected members.       
    friend ostream& operator<< (ostream& out, const Matrix& matrix_out);
    friend istream& operator>> (istream& in, Matrix& matrix_in);

    // Matrix Transpose Method.
    Matrix transpose();

private:

    // Number of rows and columns in matrix.
    size_t rows, columns;

    // Two-dimensional array to store values of matrix.
    float ** values;

};
