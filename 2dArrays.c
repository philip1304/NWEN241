#include <stdio.h>

int main() {
	
	// 2D Array = An array where each element is an array.
	//			  array[][] = {{}, {}, {}};

	int numbers[][3] = {{1, 2, 3}, 
					    {4, 5, 6}, 
					    {7, 8, 9},
						{3, 6, 9}};

	for (int i = 0; i < 4; i++) {       // rows
		for (int j = 0; j < 3; j++) {   // columns
			printf("%d ", numbers[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	char numpad[][3] = {{'1', '2', '3'}, 
						{'4', '5', '6'}, 
						{'7', '8', '9'}, 
						{'*', '0', '#'}};

	for (int i = 0; i < 4; i++) {       // rows
		for (int j = 0; j < 3; j++) {   // columns
			printf("%c ", numpad[i][j]);
		}
		printf("\n");
	}

	return 0;
}
