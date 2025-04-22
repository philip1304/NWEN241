#include <stdio.h>

int main(void) {
	float ctemp;
	float ftemp;

	printf("Enter temperature: ");
	scanf("%f", &ctemp);
	ftemp = ctemp * (9.0 / 5.0) + 32;

	printf("%.2f", ftemp);
	return 0;
}