//#include <iostream>

template <typename T=int, int size=50> class testArray
{
	T a[50];
	int n;
	T dummy;
	static int count;
public:
	testArray() : n(0), dummy(0) { count++;  }
	T& operator[] (int i){
		return i > n - 1 && i < 50 ? a[i] : dummy;
	}

	static int cnt() { return count; }

	~testArray()
	{
		count--;
	//	std::cout << "destuction : " << count << endl;
	}
};

template <typename T = int, int size = 50> int testArray<T, size>::count = 0;;


template <typename T> struct S
{
	static double something_relevant;
};

template <typename T>
double S<T>::something_relevant = 1.5;