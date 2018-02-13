#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Sum {
public:
	Sum() {
		sum = 0;
	}
	void showTotal() {
		cout << "sum : " << sum << endl;	
	}
	void operator()(int n) {
		sum += n;
		cout << "sum : " << sum << endl;
	}

private:		
	int sum;
};


int main(void)
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);

	std::for_each(a.begin(), a.end(), Sum());


	return 0;
}
