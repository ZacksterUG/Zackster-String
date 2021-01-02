#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include "ZackString.h"
using namespace std;
//using namespace ZacksterString;
int main()
{
	ZacksterString::str a, b, c;
	ZacksterString::str k("Hello world!");
	a = "Hello";
	b = " world";
	a += b;
	c = a + "!!!";
	c[5] = 'R';
	cout << c.line() << endl;
	cout << k.line() << endl;
	return 0;
}