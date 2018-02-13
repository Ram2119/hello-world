// C++ program to print largest contiguous array sum
#include <iostream>
#include <climits>
using namespace std;

int maxSubArraySum(int a[], int size)
{

	int maxEndingHere = 0;
	int maxSoFar = 0;
	int start = 0;
	int end = 0;

	int i = 0;
	for (; i < size; i++) {
		maxEndingHere = maxEndingHere + a[i];
		if (maxEndingHere < 0) {
			maxEndingHere = 0;
			start = i+1;
		}
		else if (maxEndingHere > maxSoFar) {
			maxSoFar = maxEndingHere;
			end = i;
		}
	}

	while (start <= end) {
		cout << a[start] << "  ";
		start++;
	}	
	cout << endl;

	return maxSoFar;
}

/*Driver program to test maxSubArraySum*/
int main()
{
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum << endl;
	return 0;
}
