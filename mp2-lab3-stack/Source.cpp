#include <iostream>
#include "TCalculator.h"

using namespace std;
int main() {
	try {
		TCalculator c;
		string expr;
		cin >> expr;
		c.Setexpr(expr);
		c.ToPostfix();
		cout << c.GetPostfix() << endl;
		cout << c.calc();
	}
	catch (const char *s) {
		cout << s;
	}
	system("pause");
	return 0;
}