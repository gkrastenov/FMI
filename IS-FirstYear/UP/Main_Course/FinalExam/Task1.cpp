// Task 1

#include <iostream>
using namespace std;

int main()
{

    //Creation
    int n;
    cout << "n: ";
    cin >> n;

    if (n < 3)
    {
        cout << "Incorrect input\n";
        return 0 ;
    }

    int** matrix = new int* [n]; // Rows

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n]; // Columns
    }

    // Set matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // purvi kvadrant
    int firstSum = 0;
    int firstDiagonal = 1;
    int secondDiagonal = 1;
    int index = n / 2 + 1;

    for (int i = 0; i < n / 2 ; i++)
    {
        for (int j = index; j < n; j++)
        {
            firstDiagonal *= matrix[i][j];
            break;
        }
        index++;
    }

    index = n - 1;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = index; j >= 0; j--)
        {
            secondDiagonal *=  matrix[i][j];
            break;
        }
        index--;
    }

    firstSum = firstDiagonal - secondDiagonal;

    // vtori kvadrant
    firstDiagonal = 1;
    secondDiagonal = 1;
    int secondSum = 0;

    index = 0;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = index; j < n; j++)
        {
            firstDiagonal *= matrix[i][j];
            break;
        }
        index++;
    }

    index = n/2 - 1;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = index; j >= 0; j--)
        {
            secondDiagonal *= matrix[i][j];
            break;
        }
        index--;
    }

    secondSum = firstDiagonal - secondDiagonal;

    // treti kvadrant
    firstDiagonal = 1;
    secondDiagonal = 1;
    int thirdSum = 0;

    index = 0;
    for (int i = n/2 + 1 ; i < n; i++)
    {
        for (int j = index; j < n; j++)
        {
            firstDiagonal *= matrix[i][j];
            break;
        }
        index++;
    }

    index = n / 2 - 1;
    for (int i = n / 2 + 1; i < n; i++)
    {
        for (int j = index; j >= 0; j--)
        {
            secondDiagonal *= matrix[i][j];
            break;
        }
        index--;
    }

    thirdSum = firstDiagonal - secondDiagonal;


    // fourth kvadrant
    firstDiagonal = 1;
    secondDiagonal = 1;
    int fourSum = 0;

    index = n / 2+ 1;
    for (int i = n / 2 + 1; i < n; i++)
    {
        for (int j = index; j < n; j++)
        {
            firstDiagonal *= matrix[i][j];
            break;
        }
        index++;
    }

    index = n - 1;
    for (int i = n / 2 + 1; i < n; i++)
    {
        for (int j = index; j >= 0; j--)
        {
            secondDiagonal *= matrix[i][j];
            break;
        }
        index--;
    }

    fourSum = firstDiagonal - secondDiagonal;


    // Destruction
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i]; // Delete columns
    }
    delete[] matrix; // Delete Rows

    if (firstSum == thirdSum && secondSum == fourSum)
    {
        cout << boolalpha << true;
    }
    else {
        cout << boolalpha << false;
    }
}