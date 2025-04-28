#include <stdio.h>

int main() {
	
	// Format specifier = Special tokens that begin with a % symbol,
	//					  followed by a character that specifies the data type
	// 					  and optional modifiers (width, precision, flags).
	//					  They control how data is displayed or interpreted.

	int age = 26;
	float price = 19.99;
	double pi = 3.1415926535;
	char currency = '$';
	char name[] = "Philip Chang";

	printf("\nMy age is %d.\n", age);
	printf("The price of my balm cleanser is %.2f.\n", price);
	printf("The value of pi is %lf.\n", pi);
	printf("The currency is NZD%c.\n", currency);
	printf("My name is %s.\n", name);


	// width

	int num1 = 1;
	int num2 = 10;
	int num3 = 100;
	int num4 = -1000;

	printf("\n%-4d\n", num1);  // - left-justifies the number
	printf("%04d\n", num2);    // prints 0s before the number
	printf("%+4d\n", num3);    // displays if number is positive
	printf("%4d\n", num4);


	// precision

	float price1 = 19.99;
	float price2 = 1.50;
	float price3 = -100.00;
	float price4 = 30.779;

	printf("\n%.2f\n", price1);  // rounds to 2dp
	printf("%.2f\n", price2);
	printf("%.1f\n", price3);    // rounds to 1dp
	printf("%.2f\n", price4);

	printf("\n");
	printf("%+7.2f\n", price1);
	printf("%+7.2f\n", price2);
	printf("%+7.2f\n", price3);

	return 0;
}