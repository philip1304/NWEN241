#include <stdio.h>
#include <stdbool.h>

int main() {
	// Variables: Reusable containers for values.
	//            Behaves as if it were the value it contains.

	// int    =   whole numbers (4 bytes in modern systems)
	// float  ==  single-precision decimal number (4 bytes)
	// double ==  double-precision decimal number (8 bytes)
	// char   =   single character (1 byte)
	// char[] =   array of characters (size varies)
	// bool   =   true or false (1 byte, requires <stdbool.h>)


	// int
	int age = 25;
	int year = 2025;
	int quantity = 1;

	printf("\nYou are %d years old.\n", age);
	printf("The year is %d.\n", year);
	printf(
		"You have ordered %d balm cleanser.\n", quantity);

	// float
	float gpa = 3.7;
	float price = 19.99;
	float temperature = 19.1;

	printf("\nYour GPA is currently %.1f.\n", gpa);
	printf("The price of your chosen cleanser is NZD$%.2f.\n", price);
	printf("The temperature is %f°C.\n", temperature);


	// double
	double pi = 3.14159265358979;
	double e = 2.7182818284590;

	printf("\nThe value of pi is %lf.\n", pi);
	printf("The value of e is %.15lf.\n", e);


	// char
	char grade = 'A';
	char symbol = '!';
	char currency = '$';

	printf("\nYour grade is %c.\n", grade);
	printf("You've been spotted%c\n", symbol);
	printf("The currency is NZD%c.\n", currency);


	// char[]
	char name[] = "Philip";
	char food[] = "Nasi Lemak";
	char email[] = "philip.chang1304@gmail.com";

	printf("\nHello %s.\n", name);
	printf("Your favourite Malaysian food is %s.\n", food);
	printf("Your email is %s.\n", email);


	// bool
	bool isOnline = true;
	bool isStudent = true;
	bool forSale = false;

	printf("\n%d\n", isOnline);
	printf("%d\n", isStudent);
	printf("%d\n", forSale);

	if(isOnline) {
		printf("You are ONLINE.\n");
	}
	else {
		printf("You are OFFLINE.\n");
	}

	if(isStudent) {
		printf("You are a STUDENT.\n");
	}
	else {
		printf("You are NOT a STUDENT.\n");
	}

	if(forSale) {
		printf("That item is for sale.\n");
	}
	else {
		printf("That item is NOT for sale.\n");
	}



	// Homework
	int realAge = 26;
	float height = 171.2;
	double weight = 63.26;
	char initial = 'P';
	char fullName[] = "Philip Chang";
	bool isSingle = true;

	printf("\nI am %d years old.\n", realAge);
	printf("I am %.1fcm tall.\n", height);
	printf("I am %.2lfkg heavy.\n", weight);
	printf("My initial is %c.\n", initial);
	printf("My full name is %s.\n", fullName);

	if(isSingle) {
		printf("I am single.\n");
	}
	else {
		printf("I am in a relationship.\n");
	}

	return 0;
}