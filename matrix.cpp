#include "matrix.h"

/*
Description: Constructs the matrix using a singular float value.

Arguments:
    row_size (size_t): Rows of the matrix.
    columns_size (size_t): Columns of the matrix.
    init (float): The value to be added to all rows and columns of the matrix.
*/

Matrix::Matrix(size_t rows_size, size_t columns_size, float init) 
{
    rows = rows_size;
    columns = columns_size;

    // Allocates memory for the bigger array.
    values = new float*[rows];
    for (int i = 0; i < rows; i++)
    {
        // Allocates memomry for each one of the smaller array.
        values[i] = new float[columns];
    }

    // Nested for loop to assign values to matrix (2-Dimensional array).
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            values[i][j] = init;
        }
    }
}

/*
Description: Constructs the matrix using a float array.

Arguments:
    row_size (size_t): Rows of the matrix.
    columns_size (size_t): Columns of the matrix.
    arr_ptr (float*): A pointer that points to the first element in the array.
*/
Matrix::Matrix(size_t rows_size, size_t columns_size, float * arr_ptr)
{
    rows = rows_size;
    columns = columns_size;

    values = new float*[rows];
    size_t index = 0;
    for (size_t i = 0; i < rows; i++)
    {
        values[i] = new float[columns];
    }

    for (size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
        {
            values[i][j] = *(arr_ptr+index);
            index++;
        }
    }
}

/*
Description: Constructs a deepcopy of another matrix object.

Arguments:
    rhs (const Matrix%): Another matrix object to make a deepcopy of.
*/
Matrix::Matrix(const Matrix& rhs)
{
    rows = rhs.rows;
    columns = rhs.columns;

    values = new float*[rows];
    for (int i = 0; i < rows; i++)
    {
        values[i] = new float[columns];
    }

    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            values[i][j] = rhs.values[i][j];
        }
    }
}

/*
Description: Destructor of the class implementation.
*/
Matrix::~Matrix()
{
    for (size_t i = 0; i < rows; i++)
    {
        // Deallocates memory of each smaller array.
        delete[] values[i];
    }

    // Deallocates memory of the biggger array.
    delete[] values;
}

/*
Description: Overloads the "+" operator for matrix addition.

Arguments:
    rhs (const Matrix%): The other matrix to be added to our original one.

Returns:
    modified_matrix (Matrix): The summation is stored here.
*/
Matrix Matrix::operator+ (const Matrix& rhs)
{
    // Constructs a new matrix to store the values in.
    Matrix modified_Matrix(rows, columns, 0.0);

    for (size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
        {
            // Adds each value in the matrix to the passed matrix then stores 
            // it in a new one.
            modified_Matrix.values[i][j] = values[i][j] + rhs.values[i][j];
        }
    }

    return modified_Matrix;
}

/*
Description: Overloads the "-" operator for matrix subtraction.

Arguments:
    rhs (const Matrix%): The other matrix to be subtracted from our original 
    one.

Returns:
    modified_matrix (Matrix): The result is stored here.
*/
Matrix Matrix::operator- (const Matrix& rhs)
{
    Matrix modified_Matrix(rows, columns, 0.0);

    for (size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
        {
            modified_Matrix.values[i][j] = values[i][j] - rhs.values[i][j];
        }
    }
    
    return modified_Matrix;
}

/*
Description: Overloads the "-" operator for matrix negation.

Returns:
    modified_matrix (Matrix): The negation is stored here.
*/
Matrix Matrix::operator- ()
{
    Matrix modified_Matrix(rows, columns, 0.0);

    for (size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
        {
            modified_Matrix.values[i][j] = values[i][j] * -1;
        }
    }
    
    return modified_Matrix;
}

/*
Description: Overloads the "*" operator for matrix multiplication.

Arguments:
    rhs (const Matrix%):The other matrix to be multiplied by our original one.

Returns:
    modified_matrix (Matrix): The result is stored here.
*/
Matrix Matrix::operator* (const Matrix& rhs)
{
    Matrix modified_Matrix(rows, rhs.columns, 0.0);

    for (size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < rhs.columns; j++)
        {
            for(size_t k = 0; k < columns; k++)
            {
                modified_Matrix.values[i][j] += values[i][k] * rhs.values[k][j];
            }
        }
    }

    return modified_Matrix;
}

/*
Description: Method to return the transpose of the matrix.

Returns:
    modified_matrix (Matrix): The transpose is stored here.
*/
Matrix Matrix::transpose()
{
    Matrix modified_Matrix(columns, rows, 0.0);

    for (int i = 0; i < modified_Matrix.rows; i++)
    {
        for(int j = 0; j < modified_Matrix.columns; j++)
        {
            modified_Matrix.values[i][j] = values[j][i];
        }
    }
    
    return modified_Matrix;
}

/*
Description: Overloads the "[]" operator for setting and getting indvidual 
    values inside our matrix by returning a pointer to the first element of a
    certain smaller array inside our bigger array depending on index.

Arguments:
    index (size_t): Index of the smaller array.

Returns:
    values[index] (float*): Returns a pointer to the smaller array.
*/
//SETTER
float* Matrix::operator[] (size_t index)
{
    return values[index];
}

//GETTER
float* Matrix::operator[] (size_t index) const 
{
    return values[index];
}

/*
Description: Overloads the ">>" operator to extract values into matrix from
    stream using the istream class.

Arguments:
    in (istream&): Object from istream class with values from stream.
    matrix_in (Matrix&): Matrix where values will be added to.

Returns:
    in (istream&): Object from class istream class.
*/
istream& operator>>(istream& in, Matrix& matrix_in)
{
	for (size_t	i = 0; i < matrix_in.rows; i++)
    {
		for (size_t j = 0; j < matrix_in.columns; j++)
        {
			in >> matrix_in.values[i][j];
		}
	}
	return in;
}

/*
Description: Overloads the "<<" operator to insert values into stream from
    matrix using the ostream class.

Arguments:
    out (ostream&): Object from ostream class.
    matrix_out (const Matrix&): matrix to get the values from and add to
        ostream object to insert to stream.

Returns:
    out (ostream&): Object from class istream with matrix values.
*/
ostream& operator<<(ostream& out, const Matrix& matrix_out)
{
    for (size_t i = 0; i < matrix_out.rows; i++)
    {
        for (size_t j = 0; j < matrix_out.columns; j++)
        {
            out << matrix_out.values[i][j];
            if (j != matrix_out.columns-1)
            {
                out << " ";
            }
        }

        if (i != matrix_out.rows-1)
        {
            out << endl;
        }
    }
    return out;
}
