#include <stdio.h>

void checkBalance(float balance);
float deposit();
float withdraw(float balance);

int main() {

	// Banking Program

	int choice = 0;
	float balance = 0.0f;

	printf("*** WELCOME TO PHLOP'S BANK ***\n");

	do {
		printf("\nSelect an option: \n");
		printf("1. Check Balance\n");
		printf("2. Deposit Money\n");
		printf("3. Withdraw Money\n");
		printf("4. Exit Program\n");

		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				checkBalance(balance);
				break;
			case 2:
				balance += deposit();
				break;
			case 3:
				balance -= withdraw(balance);
				break;
			case 4:
				printf("\n Thank you for using Phlop's Bank! Have a wonderful day!\n");
				break;
			default:
				printf("Invalid choice! Please select 1 - 4!\n");
		}

	} while (choice != 4);

	return 0;
}

void checkBalance(float balance) {
	printf("Your current balance is: $%.2f\n", balance);
}

float deposit() {
	float amount = 0.0f;

	printf("Enter amount to deposit: $");
	scanf("%f", &amount);

	if (amount < 0) {
		printf("Invalid amount!\n");
		return 0.0f;
	}
	else {
		printf("Successfully deposited $%.2f\n", amount);
		return amount;
	}
}

float withdraw(float balance) {
	float amount = 0.0f;

	printf("Enter amount to withdraw: $");
	scanf("%f", &amount);

	if (amount < 0) {
		printf("Invalid amount!\n");
		return 0.0f;
	}
	else if (amount > balance) {
		printf("Insufficient funds! Your balance is $%.2f\n", balance);
		return 0.0f;
	}
	else {
		printf("Successfully withdrew $%.2f\n", amount);
		return amount;
	}

	return 0.0f;
}
