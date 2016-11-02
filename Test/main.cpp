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




double foo(int a, double b)
{
	for (int i = 0; i < a; i++){
		b += b;
	}
	return b;
}

class O
{
public:
	double operator()(int x, double y) { 
		while (x > 0){
			y -= 1.0;
			x--;
		}
		return y;
	}
};

template<typename T>
void call(int x, double y, T&func)
{
	std::cout << func(x, y) << std::endl;
}



int foo()
{
	static int x = 10;
	{
		int x = 5;
		x += x;
	}
	return x;
}


class Bob{
	int t;
public:
	Bob() { t = 0; }
	Bob(int p) { t = p; }
	bool operator > (int p) {
		return t > p;
	}
};


template<typename T>
void callMe(T& pCall){
	static int x = 8;
	x++;
	if (pCall > x){
		cout << x << endl;
	}
}



using namespace std;
int main() {


	Bob a, b;
	int i = 10;
	callMe(a);
	callMe(i);
	callMe(b);





	//std::vector<int> a = { 1, 2, 3, 4 };
	//std::vector<int> b;
	//std::vector<int> c;

	//std::cout << "vector a" << a.size() << endl;
	//b = a;
	//std::cout << "vector a_copy---" << a.size() << endl;
	//c = std::move(a);
	//std::cout << "vector a_move---" << a.size() << endl;


	//std::vector<const int*> pInt;

	//int tmp = 1;
	//const int& tt = tmp;
	//std::cout << "tt  " << tt << endl;
	//std::cout << "tt1  " << &tt << endl;
	//int i = tt;
	//std::cout << "i  " << i << endl;
	//std::cout << "i&  " << &i << endl;

	//int* pp = new int;
	//pp = &i;
	//std::cout << "pp  " << pp << endl;
	//std::cout << "pp*  " << *pp << endl;


	//pInt.push_back(pp);
	//std::cout << "vec  " << *pInt[0] << endl;
	
//	delete pp;

	//O o;
	//auto l = [] (int x, double y) { return x - y; };

	//call(3, 5.0, foo);
	//call(5, 3.0, o);
	//call(3, 2.0, l);


	//A a(10);
	//print(a);
	//print(A(20));


	//double a = 1.9;
	//double b = 3.3;
	//int c = 2;
	//int d = 7;

	//string str1 = "abc";
	//string str2 = "def";

	//cout << str1 << str2 << endl;
	//swapTest(str1, str2);
	//cout << str1 << str2 << endl;
	

	//cout << c << d << endl;
	//swapTest(c, d);
	//cout << c << d << endl;


	//double k = maximumTest(a, b);
	//int j = maximumTest(c, d);
	//char* res = maximumTest(str1, str2);


	//cout << k << j << res << endl;


//	cout << "templete Class Test" << endl;

	//testArray<> a, b;

	//for (int i = 0; i < 5; i++)
	//	a[i] = i*i;

	//b = a;
	//for (int i = 0; i < 5; i++)
	//	cout << b[i] << ' ';

	//cout << endl;

	

	//testArray<> s, t;
	//testArray<double> u,c;
	//testArray<int, 40> v;
	//testArray<int, 50> z;


	//std::cout << testArray<>::cnt() << std::endl;
	//std::cout << testArray<double>::cnt() << std::endl;
	//std::cout << testArray<int, 40>::cnt() << std::endl;


	//std::vector<int> A;
	//A.push_back(-1);
	//A.push_back(3);
	//A.push_back(-4);
	//A.push_back(5);
	//A.push_back(1);
	//A.push_back(-6);
	//A.push_back(2);
	//A.push_back(1);
	//int ans = solution(A);


	int a1 = 3;
	int a2 = 3;
	int a3 = 3;
	int a4 = 3;

	if ((a1 == a2) && (a2 == a3) && (a3 == a4)){
		std::cout << "Match" << endl;
	}
	else{
		std::cout << "Not Match" << endl;
	}



}