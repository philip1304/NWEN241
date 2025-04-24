#include <stdio.h>
#include <stdlib.h>

int main(int arg, char *arga[]) {
	int sum = 0;

	for (int i = 1; i < arg; i++) {
		int num;

		if (sscanf(arga[i], "%d", &num) == 1) {
			sum += num;
		}
	}
	printf("%d\n", sum);

	return 0;
}
