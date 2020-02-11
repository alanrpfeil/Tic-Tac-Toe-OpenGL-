#ifndef Ai_h
#define Ai_h

#include <cstdlib>
#include <time.h>
#include "Rect.h"

int getRandomNumber() {
	srand(time(NULL));
	int randNum = (rand() % 9);
	return randNum;
}

void AIplay() {
	bool hasPlayed = 0;

	while (hasPlayed == 0) {
		if ((getRandomNumber() == 0) && (zone[0][0].isused == 0)) {
			XorO(-0.66, 0.66);
			zone[0][0].isused = 1;
			zone[0][0].occupied = 'o';
			hasPlayed = 1;
			break;
		}
		if ((getRandomNumber() == 1) && (zone[1][0].isused == 0)) {
			XorO(0.00, 0.66);
			zone[1][0].isused = 1;
			zone[1][0].occupied = 'o';
			hasPlayed = 1;
			break;
		}
		if ((getRandomNumber() == 2) && (zone[2][0].isused == 0)) {
			XorO(0.66, 0.66);
			zone[2][0].isused = 1;
			zone[2][0].occupied = 'o';
			hasPlayed = 1;
			break;
		}
		if ((getRandomNumber() == 3) && (zone[0][1].isused == 0)) {
			XorO(-0.66, 0.00);
			zone[0][1].isused = 1;
			zone[0][1].occupied = 'o';
			hasPlayed = 1;
			break;
		}
		if ((getRandomNumber() == 4) && (zone[1][1].isused == 0)) {
			XorO(0.00, 0.00);
			zone[1][1].isused = 1;
			zone[1][1].occupied = 'o';
			hasPlayed = 1;
			break;
		}
		if ((getRandomNumber() == 5) && (zone[2][1].isused == 0)) {
			XorO(0.66, 0.00);
			zone[2][1].isused = 1;
			zone[2][1].occupied = 'o';
			hasPlayed = 1;
			break;
		}
		if ((getRandomNumber() == 6) && (zone[0][2].isused == 0)) {
			XorO(-0.66, -0.66);
			zone[0][2].isused = 1;
			zone[0][2].occupied = 'o';
			hasPlayed = 1;
			break;
		}
		if ((getRandomNumber() == 7) && (zone[1][2].isused == 0)) {
			XorO(0.00, -0.66);
			zone[1][2].isused = 1;
			zone[1][2].occupied = 'o';
			hasPlayed = 1;
			break;
		}
		if ((getRandomNumber() == 8) && (zone[2][2].isused == 0)) {
			XorO(0.66, -0.66);
			zone[2][2].isused = 1;
			zone[2][2].occupied = 'o';
			hasPlayed = 1;
			break;
		}
	}
}
#endif