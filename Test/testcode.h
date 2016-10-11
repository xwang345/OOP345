

template<typename T>
void swapTest(T&a, T&b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

template<typename T>
T maximumTest(T a, T b)
{
	return a > b ? a : b;
}

//template<>
//char* maximumTest<char*>(char*a, char* b)
//{
//	return std::strcmp(a, b) > 0 ? a : b;
//}