#include <stdio.h>
#include <stdarg.h>

int sum(int arg_cnt, ...)
{
	va_list list;

	int x = 0;
	va_start(list, arg_cnt);

	while (arg_cnt > 0) { 
		x += va_arg(list, int);
		arg_cnt--;
	}	
	va_end(list);	
	return x;
}

int main(void)
{
	int cnt = 5;	

	printf("res : %d\n", sum(cnt, 3, 5, 2, 5, 5));

	return 0;
}
