#include <iostream>
using namespace std;

// Swapping two elements
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}

void quickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

// Average case O(nlogn) When the array is balanced partitoned.Worst case O(n^2), 
// worst-case behavior for quicksort occurs when the partition method produces one subproblem 
// with n-1 elements and one with 0 elements.
int main()
{
    int array[] = { 2,6,5,1,3,4 };
    int len = sizeof(array) / sizeof(array[0]);
    quickSort(array, 0, len - 1);

    // printing sorted array
    for (int i = 0;i < len;i++)
        cout << array[i] << " ";
}