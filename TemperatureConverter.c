#include <stdio.h>

int main() {
	
	// Temperature Converter Program

	char choice = '\0';
	float celsius = 0.0f;
	float fahrenheit = 0.0f;

	printf("Temperature Converter Program\n");
	printf("C. Celsius to Fahrenheit\n");
	printf("F. Fahrenheit to Celsius\n");

	printf("Is the temp in Celsius (C) or Fahrenheit (F)?: ");
	scanf("%c", &choice);

	if (choice == 'C') {
		// Celsius to Fahrenheit
		printf("Enter the temperature in Celsius: ");
		scanf("%f", &celsius);
		fahrenheit = (celsius * 9/5) + 32;
		printf("%.1f Celsius is equal to %.1f Fahrenheit.\n", celsius, fahrenheit);
	}
	else if (choice == 'F') {
		// Fahrenheit to Celsius
		printf("Enter the temperature in Fahrenheit: ");
		scanf("%f", &fahrenheit);
		celsius = (fahrenheit - 32) * 5 / 9;
		printf("%.1f Fahrenheit is equal to %.1f Celsius.\n", fahrenheit, celsius);
	}
	else {
		printf("Invalid choice! Please enter C or F!\n");
	}

	return 0;
}