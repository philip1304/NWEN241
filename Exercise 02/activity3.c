#include <stdio.h>

// Define structure record
struct Record {
	char name[40];
	int age;
	float height;
};

// Implement print_record_ptr() function
void print_record_ptr(struct Record *rec) {
	printf("Name  : %s\n",   rec -> name);
	printf("Age   : %d\n",   rec -> age);
	printf("Height: %.2f\n", rec -> height);
}

int main(void) {
	struct Record rec;

	scanf("%s %d %f", rec.name, &rec.age, &rec.height);
	print_record_ptr(&rec);

	return 0;
}
