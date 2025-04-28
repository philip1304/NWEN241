#include <stdio.h>
#include <string.h>

int main() {
	
	// Array of Strings

	char fruits[][10] = {"Durian", 
						 "Jackfruit", 
						 "Longan", 
						 "Rambutan"};
	
	int size = sizeof(fruits) / sizeof(fruits[0]);

	fruits[0][0] = 'n';
	fruits[0][5] = 'D';

	fruits[1][0] = 't';
	fruits[1][8] = 'J';

	fruits[2][0] = 'n';
	fruits[2][5] = 'L';

	fruits[3][0] = 'n';
	fruits[3][7] = 'R';

	for (int i = 0; i < size; i++) {
		printf("%s\n", fruits[i]);
	}


	char names[4][25] = {0};
	int rows = sizeof(names) / sizeof(names[0]);

	for (int i = 0; i < rows; i++) {
		printf("Enter a name: ");
		fgets(names[i], sizeof(names[i]), stdin);
		names[i][strlen(names[i]) - 1] = '\0';
	}

	for (int i = 0; i < rows; i++) {
		printf("%s\n", names[i]);
	}

	return 0;
}
