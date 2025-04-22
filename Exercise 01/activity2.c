#include <stdio.h>

int main(void) {
	char input[50];

	printf("Enter a string without whitespaces: ");
	scanf("%s", input);
	printf("%s", input);

	return 0;
}