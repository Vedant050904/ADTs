#include "Matrix.h"

// Function Implementations

MatrixType::MatrixType()
{
    numRows = 0;
    numCols = 0;
}

void MatrixType::SetSize(int rowSize, int colSize)
{
    numRows = rowSize;
    numCols = colSize;
}

void MatrixType::StoreItem(int item, int row, int col)
{
    values[row][col] = item;
}

void MatrixType::Add(MatrixType otherOperand, MatrixType &result)
{
    if (!AddSubCompatible(otherOperand))
    {
        cout << "Matrices are not compatible for addition." << endl;
    }

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            result.StoreItem(values[i][j] + otherOperand.values[i][j], i, j);
        }
    }
}

void MatrixType::Sub(MatrixType otherOperand, MatrixType &result)
{
    if (!AddSubCompatible(otherOperand))
    {
        cout << "Matrices are not compatible for substraction." << endl;
    }

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            result.StoreItem(values[i][j] - otherOperand.values[i][j], i, j);
        }
    }
}

void MatrixType::Mult(MatrixType otherOperand, MatrixType &result)
{
    if (!MultCompatible(otherOperand))
    {
        cout << "Matrices are not compatible for multiplication." << endl;
    }

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < otherOperand.numCols; j++)
        {
            int sum = 0;
            for (int k = 0; k < numCols; k++)
            {
                sum += values[i][k] * otherOperand.values[k][j];
            }
            result.StoreItem(sum, i, j);
        }
    }
}

void MatrixType::Print()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            cout << values[i][j] << " ";
        }
        cout << endl;
    }
}

bool MatrixType::AddSubCompatible(MatrixType otherOperand)
{
    return (numRows == otherOperand.numRows && numCols == otherOperand.numCols);
}

bool MatrixType::MultCompatible(MatrixType otherOperand)
{
    return (numCols == otherOperand.numRows);
}