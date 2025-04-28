#include <stdio.h>

int main() {
	
	// arithmetic operators = + - * / % ++ --

	int x = 2;
	int y = 3;
	int z = 0;

	

	// z = x + y;
	// z = x - y;
	// z = x * y;
	z = x / y;

	printf("%d\n", z);


	float a = 2.0;
	float b = 3.0;
	float c = 0.0;

	c = a / b;

	printf("%f\n", c);


	int m = 10;
	int n = 3;
	int o = 0;

	o = m % n;
	printf("%d\n", o);

	m++;
	printf("%d\n", m);

	m--;
	printf("%d\n", m);

	n+=2;
	printf("%d\n", n);

	n-=2;
	printf("%d\n", n);

	n*=2;
	printf("%d\n", n);

	n/=3;
	printf("%d\n", n);

	return 0;
}
