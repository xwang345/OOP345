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


#include <vector>

int solution(std::vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	unsigned int i = 0, k = 0, index = 0;
	long int sum1 = 0, sum2 = 0;
	int size = sizeof(long long);
	for (i = 1; i<A.size() - 1; i++){
		sum1 = sum2 = 0;
		for (k = 0; k<i; k++){
			sum1 += A[k];
		}

		for (k = i + 1; k<A.size(); k++){
			sum2 += A[k];
		}

		if (sum1 == sum2){
			index = i;
		}
	}
	return index;
}





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


	std::vector<int> A;
	A.push_back(-1);
	A.push_back(3);
	A.push_back(-4);
	A.push_back(5);
	A.push_back(1);
	A.push_back(-6);
	A.push_back(2);
	A.push_back(1);
	int ans = solution(A);




}