// CPP program to illustrate the number of
// ways to represent N as sum of 1, 3 and 4.
#include <bits/stdc++.h>
using namespace std;
 
// function to count the number of
// ways to represent n as sum of 1, 3 and 4
int countWays(int n)
{
	int DP[n + 1];
			 
	// base cases
	DP[0] = DP[1] = DP[2] = 1;
	DP[3] = 2;
					 
	// iterate for all values from 4 to n
	for (int i = 4; i <= n; i++) 
		DP[i] = DP[i - 1] + DP[i - 3] + DP[i - 4];
						     
	return DP[n];
}
 
// driver code
int main()
{
	int n = 10;
	cout << countWays(n) << endl;
	
	return 0;
}

