#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	
	// while loop = Continue some code WHILE the condition remains true.
	//				Condition must be true for us to enter the while loop.

	int number = 0;

	while (number <= 0) {
		printf("Enter a number greater than 0: ");
		scanf("%d", &number);
		getchar();
		printf("You saved me!\n");
	}

	char name[50] = "";

	printf("Enter your name: ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';

	while (strlen(name) == 0) {
		printf("Name cannot be empty! Please enter your name: ");
		fgets(name, sizeof(name), stdin);
		name[strlen(name) - 1] = '\0';
	}

	printf("Thank you for saving me %s!", name);

	bool isRunning = true;
	char response = '\0';

	while (isRunning) {
		printf("You are playing a game!\n");
		printf("Would you like to continue? (Y = yes, N = no): ");
		scanf(" %c", &response);

		if (response == 'N' || response == 'n') {
			isRunning = false;
		}
	}

	printf("You escaped!");

	return 0;
}
