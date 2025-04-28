#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	// Number Guessing Game

	srand(time(NULL));

	int guess = 0;
	int tries = 0;
	int min = 1;
	int max = 100;
	int answer = rand() % (max - min + 1) + min;

	printf("%d", answer);

	printf("*** NUMBER GUESSING GAME ***\n");

	do {
		printf("Guess a number between %d - %d!", min, max);
		scanf("%d", &guess);
		tries++;

		if (guess < answer) {
			printf("Too low!\n");
		}
		else if (guess > answer) {
			printf("Too high!\n");
		}

	} while (guess != answer);

	printf("The answer is %d!\n", answer);
	printf("It took you %d tries.\n", tries);

	return 0;
}
