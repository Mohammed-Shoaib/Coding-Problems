// Problem Code: HS08TEST

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int X;
	float Y;
	cin >> X >> Y;
	if( (Y - X - 0.5 >= 0) && !(X % 5) )
		printf("%0.2f", Y - X - 0.5);
	else
		printf("%0.2f", Y);
	return 0;
}