#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	// C Practice Project

// Functions
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return a / b; }

int main(void) {
	char input[100];
	double num1, num2, result;
	char operator;
	
	printf("\n~~~ Phlop's Calculator in C! ~~~\n");
	printf("\nEnter 'q' to quit the program.\n");

	while (1) {
		printf("\nEnter calculation (e.g., 1 + 1): ");
		fgets(input, sizeof(input), stdin);

		input[strcspn(input, "\n")] = 0;

		if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0) {
			printf("Exiting calculator...\n");
			break;
		}

		if (sscanf(input, "%lf %c %lf", &num1, &operator, &num2) != 3) {
			printf("Invalid input. Format must be: number operator number.\n");
			continue;
		}


		switch (operator) {
		case '+':
			result = add(num1, num2);
			break;
		case '-':
			result = subtract(num1, num2);
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			if (num2 == 0) {
				printf("Error: Cannot divide by 0!\n");
				continue;
			}
			result = divide(num1, num2);
			break;
		default:
			printf("Invalid operator.\n");
			continue;
		}

		printf("Result: %.10lf\n", result);
	}

	return 0;
}
