
#if 0
#include <bits/stdc++.h>
using namespace std;
 
// Returns the missing number. Size of arr2[]
// is n-1.
int missingNumber(int arr1[], int arr2[], int n)
{
	// missing number 'mnum'
	int mnum = 0;
			 
	// 1st array is of size 'n'
	for (int i=0; i<n; i++)
		mnum = mnum ^ arr1[i];
				 
	// 2nd array is of size 'n-1'
	for (int i=0; i<n-1; i++)
		mnum = mnum ^ arr2[i];
					 
	// required missing number
	return mnum;
}
 
// Driver program to test above
int main()
{
	int arr1[] = {4, 8, 1, 3, 7};
	int arr2[] = {7, 4, 3, 1};
	
	int n = sizeof(arr1) / sizeof(arr1[0]);
	cout << "Missing number = "
		 << missingNumber(arr1, arr2, n)
		 << endl;

	return 0;
}
#endif


// C++ program to find all pair in both arrays
// whose sum is equal to given value x
#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;
 
// Function to find all pairs in both arrays
// whose sum is equal to given value x
void findPairs(int arr1[], int arr2[], int n, int m, int x)
{
	// Insert all elements of first array in a hash
	unordered_set<int> s;
	for (int i=0; i<n; i++)
		s.insert(arr1[i]);
				 
	// Subtract sum from second array elements one
	// by one and check it's present in array first
	// or not
	for (int j=0; j<m; j++)
		if (s.find(x - arr2[j]) != s.end())
			cout << x-arr2[j] << " "
				 << arr2[j] << endl;
}
 
// Driver code
int main()
{
	int arr1[] = {1, 0, -4, 7, 6, 4};
	int arr2[] = {0 ,2, 4, -3, 2, 1};
	int x = 8;
	
	int n = sizeof(arr1)/sizeof(int);
	int m = sizeof(arr2)/sizeof(int);
	
	findPairs(arr1, arr2, n, m, x);
	
	return 0;
}
