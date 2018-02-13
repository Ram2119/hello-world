#include <iostream>
#include <typeinfo> 
using namespace std;

template<typename T>
const T& getMax(const T& a, const T& b)
{
	cout << typeid(a).name() << endl;	
//	cout << type_name<decltype(a)>() << endl;	
	return (a > b ? a : b);
}


template<typename RT, typename T1, typename T2>
const RT max(const T1 a, const T2 b)
{
	cout << typeid(a).name() << endl;	
	cout << typeid(b).name() << endl;	
	return (a > b ? a : b);
}

template<typename T>
const T max(const T a, const T b, const int c)	//template overloading
{
	return (max(a,b), c);
}

template<typename T>
T shift(T a)
{
	return (a << 1);
}
template<>						//template specialization
double shift<double>(double a)
{
	cout << "operation can't be performed!" << endl;	
	return a;
}

int main(void)
{
	cout << getMax(10, 15) << endl;
	cout << getMax(15.6, 5.8) << endl;
	cout << getMax<double>(10, 15.8) << endl;


	cout << "max : " << ::max<double>(20, 25.8) << endl;
	cout << "max : " << ::max<double>(25.8, 20) << endl;

	cout << shift(2) << endl;
	cout << shift<double>(2.5) << endl;


	cout << "###max : " << ::max(25, 20, 30) << endl;

	return 0;
}
