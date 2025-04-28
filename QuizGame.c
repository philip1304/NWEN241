#include <stdio.h>
#include <ctype.h>

int main() {

	// Quiz Game

	char questions[4][100] = {"What is the largest planet in the solar system?", 
							  "What is the hottest planet in the solar system?", 
							  "What planet has the most moons in the solar system?",
							  "Is the Earth flat?"};

	char options[][100]   = {" A. Jupiter\n B. Saturn\n C. Uranus\n D. Neptune", 
							 " A. Mercury\n B. Venus\n C. Earth\n D. Mars",
							 " A. Earth\n B. Mars\n C. Jupiter\n D. Saturn",
							 " A. Yes\n B. No\n C. Maybe \n Sometimes"};

	char answerKey[] = {'A', 'B', 'D', 'B'};

	int questionCount = sizeof(questions) / sizeof(questions[0]);

	char guess = '\0';
	int score = 0;

	printf("*** QUIZ GAME ***");

	for (int i = 0; i < questionCount; i++) {
		printf("\n%s\n", questions[i]);
		printf("%s\n", options[i]);
		printf("Enter your answer: ");
		scanf(" %c", &guess);

		guess = toupper(guess);

		if (guess == answerKey[i]) {
			printf("Correct!\n");
			score++;
		}
		else {
			printf("Wrong!\n");
		}
	}

	printf("Your final score is %d out of %d points!", score, questionCount);

	return 0;
}
