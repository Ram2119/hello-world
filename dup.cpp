#include <iostream>
using namespace std;


bool findDup(int a[], int size, int k)
{
	for (int i = 0; i < size; i++) {
		for(int j = i+1; j <= i+k; j++) {
			if (a[i] == a[j])
				return true;	
		}
	}
	
	return false;
}

int main(void)
{
	int a[] = {1, 2, 1, 3, 2, 4, 3};
	int size = sizeof(a) / sizeof(a[0]);
	int k;

	cout << "Enter dist k" << endl;
	cin >> k; 

	bool ret = findDup(a, size, k);
	if (ret)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;

	return 0;
}

