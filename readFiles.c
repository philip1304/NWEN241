#include <stdio.h>

int main() {
	
	// Read a File

	FILE *pFile = fopen("C:\\Users\\philip\\OneDrive\\output.txt", "r");

	char buffer[1024] = {0};

	if (pFile == NULL) {
		printf("Unable to open file.");
		return 1;
	}

	while (fgets(buffer, sizeof(buffer), pFile) != NULL) {
		printf("%s\n", buffer);
	}

	fclose(pFile);

	return 0;
}
