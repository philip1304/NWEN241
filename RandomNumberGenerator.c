#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	// Pseudo-random = Appear random but are determined by a
	//				   mathematical formula that uses a seed value
	//				   to generate a predictable sequence of numbers.
	//				   Advanced: Mersenne Twister or /dev/random

	srand(time(NULL));

	int min = 50;
	int max = 100;
	
	int randomNum = (rand() % (max - min + 1)) + min;

	printf("%d", randomNum);

	return 0;
}
