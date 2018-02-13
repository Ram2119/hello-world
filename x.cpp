#include <iostream>
using namespace std;


class A
{
	public:
		A(int x) {
			this->x = x;
		}	
		int x;
};

class B : public A
{
	public:
		B(int a) : A(a)
		{
			this->x = a-2;
		}
		void printX()
		{
			cout << "x : " << x << endl;
			cout << "A::x : " << A::x << endl;
		}
		
	private:	
		int x;
};

int main(void)
{
	B obj(20);

	obj.printX();
	return 0;
}
