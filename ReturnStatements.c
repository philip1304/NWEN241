#include <stdio.h>
#include <stdbool.h>

double square(double num) {
	return num * num;
}

double cube(double num) {
	return num * num * num;
}

bool ageCheck(int age) {
	if (age >= 18) {
		return true;
	}
	else {
		return false;
	}
}

int getMax(int x, int y) {
	if (x >= y) {
		return x;
	}
	else {
		return y;
	}
}

int main() {

	// return = returns a value back to where you call a function.

	double x = square(2);
	double y = square(3);
	double z = square(4);

	printf("%lf\n", x);
	printf("%lf\n", y);
	printf("%lf\n", z);

	x = cube(2);
	y = cube(3);
	z = cube(4);

	printf("%lf\n", x);
	printf("%lf\n", y);
	printf("%lf\n", z);	

	int age = 0;

	printf("Enter your age: ");
	scanf("%d", age);

	if (ageCheck(age)) {
		printf("You may sign up!\n");
	}
	else {
		printf("You must be 18 or older to sign up!\n");
	}

	int max = getMax(2, 3);

	printf("%d", max);

	return 0;
}
