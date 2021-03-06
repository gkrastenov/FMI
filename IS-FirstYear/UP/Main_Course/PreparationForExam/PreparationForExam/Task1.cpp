#include <iostream>
using namespace std;


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
// 0 0 ; // 1 1 ; // 2 2
// 2 0 // 1 1 // 0 3
int sumOfDiagonals(int* matrix[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            // Condition for principal diagonal 
            if (i == j)
                sum += matrix[i][j];

            // Condition for secondary diagonal 
            if ((i + j) == (length - 1))
                sum += matrix[i][j];
        }
    }

    if ((length%2 == 0) == false)
         sum -= matrix[length / 2][length / 2];

    return sum;
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
    int sum = sumOfDiagonals(matrix, n);

    bool result = true;
    while (sum > 0 )
    {
        if (sum < 2)
        {
            break;
        }

        if (sum % 2 == 0)
        {
            sum = sum / 2;
        }
        else {
            result = false;
            break;
        }
    }

    cout << boolalpha << result << endl;
    //Destruction
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i]; // Delete columns
    }
    delete[] matrix; // Delete Rows
}