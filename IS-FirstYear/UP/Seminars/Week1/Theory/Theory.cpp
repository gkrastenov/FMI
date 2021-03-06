#include<cmath> 
#include<iostream>
#include<string> 
#include<algorithm>  // max()

using namespace std;
/// <summary>
/// p) цифрите на трицифреното естествено число х образуват строго растяща или строго намаляваща редица
/// </summary>
bool methodP(int number)
{
    double a = number / 100;
    double b = (number / 10) % 10;
    double c = number % 10;

    double q1 = a / b;
    double q2 = b / c;

    return q1 == q2;
}

/// <summary>
/// //б) уравнението аx ^ 2 + bx + c = 0 (a != 0) няма реални корени
/// </summary>
bool methodB(int a, int b, int c)
{
    double D = (b * b) - (4 * a * c);
    if (D<0)
    {
        return true; // Няма реални корени
    }
    return false;

}

/// <summary>
/// в Интервала [0;1]
/// </summary>
bool methodJ(int x)
{
    return x >= 0 && x <= 1;
}

/// <summary>
/// // да се дели на 4 и 7
/// </summary>
bool methodA(int x)
{
    return (x % 4 == 0 && x % 7 == 0);
}

/// <summary>
/// // к) поне една от булевите променливи x и y има стойност true
/// </summary>
bool methodK(bool x, bool y)
{
    return (x == true || y == true);
}

/// <summary>
/// л) и двете променливи x и y имат стойност true
/// </summary>
bool methodL(bool x, bool y)
{
    return (x == true && y == true);
}

/// <summary>
/// м) нито едно от числата a, b, c не е положително
/// </summary>
bool methodM(int x, int y, int z)
{
    return (x < 0 && y < 0 && z < 0);
}

/// <summary>
/// н) цифрата 7 влиза в записа на положителното трицифрено число р
/// </summary>

bool methodN(int p)
{
    if (p < 100 && p>1000)
    {
        cout << "Not a valid number";
        exit(0);
    }

    string s = to_string(p);
    return s.find('7');
}

/// <summary>
/// з) x е равно на max {a, b, c}
/// </summary>
bool methodZ(int a, int b, int c, int x)
{
    int maxNumber = max(a, b,c);
    return maxNumber == x;
}

/// <summary>
/// и) x е различно от max {a, b, c}
/// </summary>
bool methodI(int a, int b, int c, int x)
{
    int maxNumber = max(a, b,c);
    return maxNumber != x;
}

/// <summary>
/// о) цифрите на трицифреното число m са различни
/// </summary>
bool methodO(int m)
{
    int a = m / 100;
    int b = (m / 10) % 10;
    int c = m % 10;

    return (a != b && a != c && b != c);
}

/// <summary>
/// п) поне две от цифрите на трицифреното число m са различни
/// </summary>
bool methodH(int m)
{
    int a = m / 100;
    int b = (m / 10) % 10;
    int c = m % 10;

    return (a != b || a != c || b != c);
}

/// <summary>
/// т) естественото число x, за което се знае, че е по-малко от 23, е просто
/// </summary>
bool methodT(int x)
{
    int arr[9] = { 1, 2, 3, 5, 7 ,11, 13, 17, 19, };

    for (int i = 0; i < 8; i++)
    {
        if (arr[i] == x) {
            return true;
        }
    }
    return false;


}

int main()
{
    return 0;
}
