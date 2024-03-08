#include "Matrix.h"

int main()
{
    MatrixType matrix[1000];
    int numberOfMatrices = 0;
    int userInput;
    bool valid = true;

    do
    {
        cout << "\nEnter the corresponding number for your desired operation:\n"
             << "1 - get a new matrix\n"
             << "2 - add two matrices\n"
             << "3 - subtract a matrix from another\n"
             << "4 - multiply two matrices\n"
             << "5 - print matrix\n"
             << "6 - end the program\n";
        cin >> userInput;

        if (userInput == 1)
        {
            int rows, cols;

            cout << "A matrix with 0X0 is created. Enter the number of rows and the number of columns for this new matrix:\n";

            cout << "Enter the number of rows: ";
            cin >> rows;
            cout << "Enter the number of cols: ";
            cin >> cols;

            if (numberOfMatrices < 10)
            {
                matrix[numberOfMatrices].SetSize(rows, cols);

                cout << "Enter the values:\n";
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        int value;
                        cin >> value;
                        matrix[numberOfMatrices].StoreItem(value, i, j);
                    }
                }

                numberOfMatrices++;
                cout << "Thank you. You now have total " << numberOfMatrices << " matrices in system.\n";
            }

            else
            {
                cout << "Maximum number of matrices reached.\n";
            }
        }

        else if (userInput == 2)
        {
            int a, b, c;

            cout << "Suppose that you want to perform C = A + B.\n";

            cout << "Enter A: ";
            cin >> a;
            cout << "Enter B: ";
            cin >> b;
            cout << "Enter C: ";
            cin >> c;

            if (a >= 0 && a < numberOfMatrices && b >= 0 && b < numberOfMatrices && c >= 0 && c < numberOfMatrices)
            {
                if (matrix[a].AddSubCompatible(matrix[b]))
                {
                    matrix[a].Add(matrix[b], matrix[c]);
                    cout << "Matrices " << a << " and " << b << " are added, and the result is stored in matrix " << c << ".\n";
                }
                else
                {
                    cout << "The operation is not compatible.\n";
                }
            }

            else
            {
                cout << "The input is invalid.\n";
            }
        }

        else if (userInput == 3)
        {
            int a, b, c;

            cout << "Suppose that you want to perform C = A - B.\n";

            cout << "Enter A: ";
            cin >> a;
            cout << "Enter B: ";
            cin >> b;
            cout << "Enter C: ";
            cin >> c;

            if (a >= 0 && a < numberOfMatrices && b >= 0 && b < numberOfMatrices && c >= 0 && c < numberOfMatrices)
            {
                if (matrix[a].AddSubCompatible(matrix[b]))
                {
                    matrix[a].Sub(matrix[b], matrix[c]);
                    cout << "Matrix " << b << " is subtracted from matrix " << a << ", and the result is stored in matrix " << c << ".\n";
                }
                else
                {
                    cout << "The operation is not compatible.\n";
                }
            }

            else
            {
                cout << "The input is invalid.\n";
            }
        }

        else if (userInput == 4)
        {
            int a, b, c;

            cout << "Suppose that you want to perform C = A * B.\n";

            cout << "Enter A: ";
            cin >> a;
            cout << "Enter B: ";
            cin >> b;
            cout << "Enter C: ";
            cin >> c;

            if (a >= 0 && a < numberOfMatrices && b >= 0 && b < numberOfMatrices && c >= 0 && c < numberOfMatrices)
            {
                if (matrix[a].MultCompatible(matrix[b]))
                {
                    matrix[a].Mult(matrix[b], matrix[c]);
                    cout << "Matrices " << a << " and " << b << " are multiplied, and the result is stored in matrix " << c << ".\n";
                }
                else
                {
                    cout << "The operation is not compatible.\n";
                }
            }

            else
            {
                cout << "The input is invalid.\n";
            }
        }

        else if (userInput == 5)
        {
            int matrixNumber;

            cout << "Enter the matrix number for printing:\n";
            cin >> matrixNumber;

            if (matrixNumber >= 0 && matrixNumber < numberOfMatrices)
            {
                cout << "The matrix " << matrixNumber << " is:\n";
                matrix[matrixNumber].Print();
            }
            else
            {
                cout << "The input is invalid.\n";
            }
        }

        else if (userInput == 6)
        {
            cout << "\nGoodBye, thank you!!" << endl;
            break;
        }

        else
        {
            cout << "The input is invalid.\n";
        }

    } while (valid);

    return 0;
}