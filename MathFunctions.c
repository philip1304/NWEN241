#include <stdio.h>
#include <math.h>

int main() {

	int x = 2;

	// x = sqrt(x);
	// x = pow(x, 4);

	printf("%d\n", x);


	float y = 3.14;

	// y = round(y);
	// y = ceil(y);
	// y = floor(y);

	printf("%f\n", y);


	float z = 45;

	// z = abs(z);
	// z = log(z);
	// z = sin(z);
	// z = cos(z);
	z = tan(z);

	printf("%f\n", z);

	return 0;
}