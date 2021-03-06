#include <iostream>
using namespace std;

int inputSum;

bool recursionSum(int* arr, int index, int sum , int len)
{
	if (inputSum == sum )
	{
		return true;
	}

	if (index == len)
	{
		return false;
	}
	sum += arr[index];
	// count++;
	return recursionSum(arr, index + 1, sum, len);

}

int main()
{
    int n;
    cin >> n;
    
    int const MAX_SIZE = 50;
    int arr[MAX_SIZE];

    if (n<4)
    {
        cout << "Invalid input\n";
    }
    else {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cin >> inputSum;
    }

	recursionSum(arr, 0, 0, n-1);
}
