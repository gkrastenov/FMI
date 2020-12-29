#include<iostream>
using namespace std;
int main()
{
    int num[100];
    int i, j, temp;

    cout << "Enter Length : \n";
    int len;
    cin >> len;

    for (i = 0; i < len; ++i)
        cin >> num[i];

    string condition;
    cin >> condition;
    if (condition == "descending")
    {
        for (i = 0; i < len; ++i)  \
        {
            for (j = i + 1; j < len; ++j)
            {
                if (num[i] < num[j])
                {
                    temp = num[i];
                    num[i] = num[j];
                    num[j] = temp;
                }
            }
        }
    }

    if (condition == "ascending")
    {
        for (i = 0; i < len; ++i)  \
        {
            for (j = i + 1; j < len; ++j)
            {
                if (num[i] > num[j])
                {
                    temp = num[i];
                    num[i] = num[j];
                    num[j] = temp;
                }
            }
        }
    }

    cout << "\r\n";
    // printing array
    for (i = 0; i < len; i++)
    {
        cout << num[i];
        cout << " ";
    }
}