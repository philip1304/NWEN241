#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
	
	// if statement = Do some code if a condition is true.
	//				  If the condition is false, don't do it.

	int age = 0;

	printf("Enter your age: ");
	scanf("%d", &age);
	getchar();

	if (age >= 65) {
		printf("You are a senior!\n");
	}
	else if (age >= 18) {
		printf("You are an adult!\n");
	}
	else if (age < 0) {
		printf("You haven't been born yet!\n");
	}
	else if (age == 0) {
		printf("You are a newborn!\n");
	}
	else {
		printf("You are a child!\n");
	}


	bool isStudent = true;

	if (isStudent) {
		printf("You are a student!\n");
	}
	else {
		printf("You are NOT a student!\n");
	}


	char name[50] = "";

	printf("Enter your name: ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';

	if (strlen(name) == 0) {
		printf("You have not entered a name!\n");
	}
	else {
		printf("Hello %s\n", name);
	}

	return 0;
}
