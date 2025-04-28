#include <stdio.h>

int main() {
	
	// array = A fixed-size collection of elements of the same data type.
	// 		   Similar to a variable, but it holds more than 1 value.

	int numbers[] = {10, 20, 30, 40, 50};
	char grades[] = {'A', 'B', 'C', 'D', 'F'};
	char name[] = "Philip Chang";

	for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
		printf("%d ", numbers[i]);
	}

	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("%c ", grades[i]);
	}

	printf("\n");

	for (int i = 0; i < 12; i++) {
		printf("%c", name[i]);
	}

	return 0;
}
