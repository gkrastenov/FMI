#include <iostream>
using namespace std;

int main()
{
    int rows;
    int cols;
    cout << "rows: ";
    cin >> rows;

    cout << "cols: ";
    cin >> cols;

    if (cols>10)
    {
        cout << "Incorrect input\n";
        return 0;
    }
    char** matrix = new char* [rows]; // Rows

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new char[cols]; // Columns
    }

    // Set matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
           cout<< matrix[i][j];
        }
        cout << endl;
    }
    int counter = 0;

    // horizontal
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            if (matrix[i][j] == 'u' && matrix[i][j + 1] == 'p')
            {
                counter++;
            }
        }
    }

    // vertical
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows-1; i++)
        {
            if (matrix[i][j] == 'u' && matrix[i+1][j] == 'p')
            {
                counter++;
            }
        }
    }

    cout << counter << endl;
    // Destruction
    for (int i = 0; i < cols; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix; 
}
