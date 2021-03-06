#include <iostream>
using namespace std;

int main()
{

	int a, b;
	cin >> a >> b;
	int result = a * b;
	cout << result<<endl;
	cout << result % 10 << endl;;

	if ((result % 10 )/2 ==0)
	{
		cout << true << endl;;
	}
	else{
		cout << false << endl;;
	}
	
}
