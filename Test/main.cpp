#include <iostream>
#include <string>

class A {
	int a;
public:
	A(int aa) : a(aa) {}
	void display(const char* str) const {
		std::cout << str << ' ' << a << std::endl;
	}
};

void print(const A& a) { a.display("lvalue "); }
void print(A&& a)      { a.display("rvalue "); }



#include "testcode.h"
#include "testArray.h"
using namespace std;
int main() {
	//A a(10);
	//print(a);
	//print(A(20));


	//double a = 1.9;
	//double b = 3.3;
	//int c = 2;
	//int d = 7;

	string str1 = "abc";
	string str2 = "def";

	cout << str1 << str2 << endl;
	swapTest(str1, str2);
	cout << str1 << str2 << endl;
	

	//cout << c << d << endl;
	//swapTest(c, d);
	//cout << c << d << endl;


	//double k = maximumTest(a, b);
	//int j = maximumTest(c, d);
	//char* res = maximumTest(str1, str2);


	//cout << k << j << res << endl;


	cout << "templete Class Test" << endl;

	//testArray<> a, b;

	//for (int i = 0; i < 5; i++)
	//	a[i] = i*i;

	//b = a;
	//for (int i = 0; i < 5; i++)
	//	cout << b[i] << ' ';

	//cout << endl;

	

	testArray<> s, t;
	testArray<double> u,c;
	testArray<int, 40> v;
	testArray<int, 50> z;


	std::cout << testArray<>::cnt() << std::endl;
	std::cout << testArray<double>::cnt() << std::endl;
	std::cout << testArray<int, 40>::cnt() << std::endl;


}