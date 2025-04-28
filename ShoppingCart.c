#include <stdio.h>
#include <string.h>

int main() {
	
	// Shopping Cart Program

	char item[50] = "";
	float price = 0.0f;
	int quantity = 0;
	char currency = '$';
	float total = 0.0f;

	printf("What item would you like to purchase?: ");
	fgets(item, sizeof(item), stdin);
	item[strlen(item) - 1] = '\0';

	printf("What is the price for each item?: ");
	scanf("%f", &price);

	printf("How many would you like to purchase?: ");
	scanf("%d", &quantity);

	total = price * quantity;

	printf("\nYou have purchased %d %s/s.\n", quantity, item);
	printf("The total cost is: %c%.2f\n", currency, total);

	return 0;
}
