#include <iostream>
using namespace std;

void fun(double a)
{
	cout << "a : " << a << endl;
}

int main(void)
{
	int a = 10.5;	
	fun(a);
	return 0;
}
