#include <stdio.h>
	// C Practice Project

int main(void) {
	double num1, num2, result;
	char operator;
	
	// User input
	printf("Enter calculation (e.g., 5 + 3): ");
	scanf("%lf %c %lf", &num1, &operator, &num2);

	// Calculation
	switch (operator) {
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		if (num2 == 0) {
			printf("Error: Cannot divide by 0!\n");
			return 1;
		}
		result = num1 / num2;
		break;
	default:
		printf("Invalid operator.\n");
		return 1;
	}

	// Print result
	printf("Result: %.2lf\n", result);
}
