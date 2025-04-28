#include <stdio.h>

int main() {
	
	// Calculator Program

	char operator = '\0';
	double num1 = 0.0;
	double num2 = 0.0;
	double result = 0.0;

	printf("Enter the first number: ");
	scanf("%lf", &num1);

	printf("Enter the operator (+ - * /): ");
	scanf(" %c", &operator); 	// clear \n from input buffer

	printf("Enter the second number: ");
	scanf("%lf", &num2);

	switch(operator) {
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
			printf("You cannot divide by 0!\n");
		}
		else {
			result = num1 / num2;
		}
		break;
	default:
		printf("Invalid operator!\n");
	}

	printf("Result: %.4lf\n", result);

	return 0;
}