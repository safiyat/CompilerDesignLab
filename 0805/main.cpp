#include <iostream>
#include <string>
#include "regexp.h"

using namespace std;

int main()
{
	regexp a("a+b");
	cout << a.text() << endl;
	cout << "Hello World!" << endl;
	return 0;
}

