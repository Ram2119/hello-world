#include<iostream>
#include <stdio.h>

using namespace std;

/* such a function will not be safe if x is non static variable of it */
int &fun()
{
	static int x; 
	return x;
}    

int main()
{
	fun() = 10;

	/* this line prints 10 on screen */
	cout << fun() << endl;

	getchar();
	return 0;
}
