#include <stdio.h>

typedef int Number;
typedef char String[50];
typedef char Initials[3];

int main() {
	
	// typedef = reserved keyword that gives an exissting datatype a "nickname"
	//			 typedef existing_type new_name;

	int x = 3;
	int y = 4;
	int z = x + y;

	printf("%d\n", z);

	String name = "Philip Chang";

	printf("%s\n", name);

	Initials user1 = "PC";

	printf("%s\n", user1);

	return 0;
}
