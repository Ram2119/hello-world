#include <stdio.h>
#define BYTE	8

void show_bits(int n)
{
	int i = 0;	
	for (i = BYTE * sizeof(int); i > 0; i--) {
		if (!(i%8))
			printf("  ");
		printf("%d", (n & (1<<(i-1))) ? 1 : 0);
	}
	printf("\n");
}

int swap_bits(int n, int d, int s)
{
	//return (((((1<<s)&n) << d) | (((unsigned)n&(1<<d))>>s)) | (n & (~((1<<s) | (1<<d)))));
	return ((n>>s & 1) ^ (n>>d & 1)) ? (n ^ (1<<s | 1<<d)) : n;	
}


int set_bits(int n, int s, int d)
{

//	return (n | (~(~0 << abs(d-s)) << s));

	return ( n | ((~0 << s) & (~(~0 << d+1))));
}


int rotateBits(unsigned n, int p, int isLeft)
{
	if (isLeft)
		return ((n << p) | (n >> 32-p));
	else
		return ((n >> p) | (n << 32-p));
}


int complement(unsigned n, unsigned s, unsigned d)
{
//	return  (n ^ ((~(~0 << (abs(d-s-1)))) << (s<d? s : d)));

/*	printf("@@# %d\n", d+1);
	show_bits(((~(~0 << (d+1))) >> s) << s);	

	return (n ^ (((~(~0 << (d+1))) >> s) << s));	
*/
	return n^(~((~0)<<(s-d+1))<<d);
	
}



int main(void)
{
	int n = 2147483647;
		
	show_bits(n);

	int res;
//	res = swap_bits(n, 0, 5);
//	show_bits(res);

//	res = set_bits(n, 7, 11);
//	show_bits(res);


//	res = rotateBits(n, 3, 0);
//	show_bits(res);

	res = complement(n, 1, 31);
	show_bits(res);

	return 0;
}
