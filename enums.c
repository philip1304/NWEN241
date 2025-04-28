#include <stdio.h>

typedef enum {
	SUNDAY = 1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY // values start at 0, increment by one.
} Day;

typedef enum {
	SUCCESS, FAILURE, PENDING
} Status;

void connectStatus(Status status);

int main() {
	
	// enum = A user-defined data type that consists
	//		  of a set of named integer constants.
	//		  Benefit: Replaces numbers with readable names.

    // SUNDAY  = 0;
    // MONDAY  = 1;
    // TUESDAY = 2;

	Day today = SATURDAY;

	if (today == SUNDAY || today == SATURDAY) {
		printf("It's the weekend!\n");
	}
	else {
		printf("It's a weekday...\n");
	}

	printf("%d\n", today);

	Status status = SUCCESS;

	connectStatus(status);

    return 0;
}

void connectStatus(Status status) {

	switch (status) {
		case SUCCESS:
			printf("Connection was successful!\n");
			break;
		case FAILURE:
			printf("Connection failed.\n");
			break;
		case PENDING:
			printf("Connection in progress.\n");
			break;
		default:
			printf("Status unknown.\n");
			break;
	}
}
