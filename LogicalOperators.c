#include <stdio.h>
#include <stdbool.h>

int main() {

	int temp = 15;

	if (temp <= 0 || temp >= 30) {
		printf("The temperature is BAD!\n");
	}
	else {
		printf("The temperature is GOOD!\n");
	}

	bool isSunny = true;

	if (!isSunny) {
		printf("It is NOT sunny!\n");
	}
	else {
		printf("It is sunny!\n");
	}

	return 0;
}
