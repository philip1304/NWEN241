#include <stdio.h>

int SUM(int a, int b) {
	return a + b;
}


int main(void) {
	int a, b, s;
	scanf("%d %d", &a, &b);
	s = SUM(a, b);
	printf("%d", s);

	return 0;
}