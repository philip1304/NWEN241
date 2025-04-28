#include <stdio.h>

void birthday(int* age);

int main() {
	
	// pointer = A variable that stores the memory address of another variable.
	// 			 Benefit: They help avoid wasting memory by allowing you to pass
	//			 the address of a large data structure instead of copying the entire data.

	int age = 26;
	int *pAge = &age;  // int* pAge = &age;

	printf("%p\n", &age);
	printf("%p\n", pAge);

	birthday(pAge);

	printf("You are %d years old!", age);

	return 0;
}

void birthday(int* age) {
	(*age)++;
}
