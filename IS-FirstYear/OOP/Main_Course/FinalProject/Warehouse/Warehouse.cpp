#include <iostream>
#include "View.h"

int main()
{
	View view =  View();
	while (true)
	{
		if (view.menu() == false)
		{
			break;
		}
	}
}