
#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

template <typename Type> class MatrixOps;
template <typename Type> ostream& operator << (ostream&, const MatrixOps<Type>&);

template <typename Type>
class MatrixOps
{
    friend ostream& operator<< <> (ostream& output, const MatrixOps<Type>&);

public:
    void  calculateDeterminant();
    const MatrixOps<Type>& operator=(const MatrixOps<Type>&);
    const MatrixOps<Type> operator+(const MatrixOps<Type>&);
    const MatrixOps<Type> operator-(const MatrixOps<Type>&);
    const MatrixOps<Type> operator*(const MatrixOps<Type>&);

    MatrixOps(int rowSize, int columnSize, string file = "size.txt");
    MatrixOps(const MatrixOps<Type> &matrixTwo);

    ~MatrixOps();
private:
    int rows;
    int columns;
    Type **p;
    Type determinant;
};

template <typename Type> ostream& operator<< (ostream& matrixOut, const MatrixOps<Type>& matrixTwo)
{
    for (int i = 0; i < matrixTwo.rows; ++i)
    {
        for(int k = 0; k < matrixTwo.columns; ++k)
        {
            cout << matrixTwo.p[i][k]<< " ";

        }
        cout << endl;
    }

    if (matrixTwo.determinant != 0)
    {
        cout << "Determinant of Matrices: " << matrixTwo.determinant << endl;
    }

    return matrixOut;


}

template <typename Type>
void MatrixOps<Type>::calculateDeterminant()
{
	determinant = p[0][0]*(p[1][1]*p[2][2]-p[1][2]*p[2][1])-p[0][1]*(p[1][0]*p[2][2]-p[1][2]*p[2][0])+p[0][2]*(p[1][0]*p[2][1]-p[1][1]*p[2][0]);

}

template <typename Type>
const MatrixOps<Type> MatrixOps<Type>::operator+(const MatrixOps<Type>& matrixTwo)
{
    if (rows != matrixTwo.rows || columns != matrixTwo.columns)
    {
        cout << "Matrix Specifications Error(same size)\n";

        return *this;
    }

    MatrixOps<Type> matrixThree(matrixTwo.rows, matrixTwo.columns);

    for (int i = 0; i < rows; ++i)
    {
        for(int k = 0; k < columns; ++k)
        {
            matrixThree.p[i][k] = p[i][k] + matrixTwo.p[i][k];
        }
    }

    return matrixThree;
}

template <typename Type>
const MatrixOps<Type>& MatrixOps<Type>::operator=(const MatrixOps<Type>& matrixTwo)
{
    if(this != &matrixTwo)
    {

        for (int i = 0; i < rows; ++i)
        {
            delete [] p[i];
        }

        delete []p;

        rows = matrixTwo.rows;
        columns = matrixTwo.columns;

        p = new Type *[rows];

        for (int i = 0; i < rows; ++i)
        {
            p[i] = new Type [columns];

            for(int k =0; k < columns; ++k)
            {
                p[i][k] = matrixTwo.p[i][k];
            }
        }
    }

    return *this;
}

template <typename Type>
const MatrixOps<Type> MatrixOps<Type>::operator*(const MatrixOps<Type>& matrixTwo)
{
    if (columns != matrixTwo.rows)
    {
        cout << "Columns of First Matrix != Rows of Second Matrix\n";
        return *this;
    }

    MatrixOps<Type> matrixThree(rows, matrixTwo.columns);

    for (int i = 0; i < rows; ++i)
    {
        for(int k = 0; k < matrixTwo.columns; ++k)
        {
            for(int j = 0; j < columns; ++j)
            {
                matrixThree.p[i][k] += p[k][j] * matrixTwo.p[j][k];
            }
        }
    }
    return matrixThree;
}

template <typename Type>
const MatrixOps<Type> MatrixOps<Type>::operator-(const MatrixOps<Type>& matrixTwo)
{
    if (rows != matrixTwo.rows || columns != matrixTwo.columns)
    {
        cout << "Matrix Specifications Error(same size)\n";
        return *this;
    }

    MatrixOps<Type> matrixThree(matrixTwo.rows, matrixTwo.columns);

    for (int i = 0; i < rows; ++i)
    {
        for(int k = 0; k < columns; ++k)
        {
           matrixThree.p[i][k] = p[i][k] - matrixTwo.p[i][k];
        }
    }

    return matrixThree;

}



template <typename Type>
MatrixOps<Type>::MatrixOps(const MatrixOps<Type>& matrixTwo)
{
    rows = matrixTwo.rows;
    columns = matrixTwo.columns;

    p = new Type *[rows];

    for (int i = 0; i < rows; ++i)
    {
        p[i] = new Type [columns];

        for(int k = 0; k < columns; ++k)
        {
            p[i][k] = matrixTwo.p[i][k];
        }
    }

    determinant = matrixTwo.determinant;

}

template <typename Type>
MatrixOps<Type>::MatrixOps(int rowSize, int columnSize, string file)
{

    fstream fin;
    fin.open(file);

    rows = rowSize;
    columns = columnSize;

    p = new Type *[rows];
    for (int i = 0; i < rows; ++i)
    {
        p[i] = new Type [columns];

        for(int k =0 ; k < columns; ++k)
        {
            fin >> p[i][k];
        }
    }

    determinant = 0;
    fin.close();
}

template <typename Type>
MatrixOps<Type>::~MatrixOps()
{
    for (int i = 0; i < rows; ++i)
    {
        delete [] p[i];
    }

    delete []p;
}

#endif /* HEADER_H_ */
