
#include <iostream>
using namespace std;

void swap(int* first, int* second)
{
    int* temp = first;
    first = second;
    second = temp;
}

void func(int* matrix[], int length)
{
    int upperRowIndex = 0;
    int upperColIndex = 0;

    int index = 1;
    int current = matrix[0][1];
    for (int i = 0; i < length; i++)
    {
        for (int j = index; j < length; j++)
        {
            if (matrix[i][j] > current)
            {
                upperRowIndex = i;
                upperColIndex = j;
                current = matrix[i][j];
            }
        }
        index++;
    }

    int downRowIndex = 0;
    int downColIndex = 0;
    int indexDiagonal = 0;
    current = matrix[1][0];
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (j == indexDiagonal)
            {
                break;
            }
            if (matrix[i][j] > current)
            {
                downRowIndex = i;
                downColIndex = j;
                current = matrix[i][j];
            }
        }
        indexDiagonal++;
    }

    swap(matrix[downRowIndex][downColIndex], matrix[upperRowIndex][upperColIndex]);
}

void setMatrix(int* matrix[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cin >> matrix[i][j];
        }
    }
}
int main()
{
    //Creation
    int n;
    cout << "n: ";
    cin >> n;

    int** matrix = new int* [n]; // Rows

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n]; // Columns
    }

    setMatrix(matrix, n);
    func(matrix, n);

    //Print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j];
        }
        cout << "\n";
    }
    //Destruction
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i]; // Delete columns
    }
    delete[] matrix; // Delete Rows
}