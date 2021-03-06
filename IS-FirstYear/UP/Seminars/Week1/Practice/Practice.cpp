#include<iostream>
#include<cmath> 
#include<string>

using namespace std;

// Exercise 1
void MagicNumber()
{
    cout << "Помолете приятел да си намисли число ";
    int n;
    cin >> n;
    cout << "Нека прибави към него 2, да умножи по 5, сега да прибави 15, и отново да умножи по 2. ";
    cout << "Попитайте го за резултата?";
    cout << ((n + 2) * 5 + 15) * 2;
    cout << "Познах ли числото?";
}

// Exercise 2
float CalculateTriangleArea(float a, float b, float c)
{
    if (a < 0 || b < 0 || c < 0 ||
        (a + b <= c) || a + c <= b ||
        b + c <= a)
    {
        cout << "Not a valid trianglen";
        exit(0);
    }
    float s = (a + b + c) / 2;
    float area = sqrt(s * (s - a) *
        (s - b) * (s - c));

    cout << "Area is:  " << area << "\n";
    return area;
}

// Exercise 3
int NAND(int A, int B)
{
    // INPUT : A and B
    // OUTPUT : A NAND B
    if (A == B == 1)
    {
        return 0;
    }

    return 1;
}

// Exercise 4
int SwapAndSubtractionTwoParams(int x, int y)
{

    x = x + y;
    y = x - y;
    x = x - y;

    return x - y;
}

// Exercise 5
int ReturnKSymbol(int x, int k)
{
    string s = to_string(x);
    return  int(s[k - 1]) - 48; // In ASCII code, the numbers (digits) start from 48
}
int main() {
    // CalculateTriangleArea(3,4,5);
    // ReturnKSymbol(13719272,5);
    // SwapAndSubtractionTwoParams(5,1);
    // MagicNumber();
    // NAND(1,1);
}


