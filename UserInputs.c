#include <stdio.h>
#include <string.h>

int main() {

	int age = 0;
	float gpa = 0.0f;
	char grade = '\0';
	char name[30] = "";

	printf("Enter your age: ");
	scanf("%d", &age);

	printf("Enter your GPA: ");
	scanf("%f", &gpa);

	printf("Enter your grade: ");
	scanf(" %c", &grade);

	getchar();
	printf("Enter your full name: ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';
	// printf("Size of variable 'name': %d\n", sizeof(name));

	printf("%s\n", name);
	printf("%d\n", age);
	printf("%.2f\n", gpa);
	printf("%c\n", grade);

	return 0;
}