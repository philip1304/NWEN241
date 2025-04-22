#include <stdio.h>

int main(void) {
	char input[50];

	printf("Enter a string: ");
	scanf("%[^\n]", input);
	printf("%s", input);

	return 0;
}