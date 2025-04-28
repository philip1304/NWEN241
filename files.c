#include <stdio.h>

int main() {
	
	// Write a File

	FILE *pFile = fopen("C:\\Users\\philip\\OneDrive\\output.txt", "w");

	char text[] = "I don't like to study!";

	if (pFile == NULL) {
		printf("Error opening file.\n");
		return 1;
	}

	fprintf(pFile, "%s", text);

	printf("File was written to successfully.");

	fclose(pFile);

	return 0;
}
