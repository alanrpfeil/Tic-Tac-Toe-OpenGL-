#include "graphics.h"
#include "Rect.h"
#include "App.h"
#include <cstdlib>
#include <time.h>

using namespace std;

// Store the width and height of the window
int width = 640, height = 640;
void(*XorO)(double, double) = drawX; //setting up function pointer to alternate between X's and O's
bool switchXorO = 0;				 //switches between function pointers ^
Rect zone[3][3];					 //setting up trigger rectangular zones within 3x3 grid
int counter = 1;					 //keeps track when we need to start computing for a winner; starts at 1 for 1st turn
char playerWon = 'n';
bool useAI = 0;
bool hasPlayed = 0;
int randNum;

int getRandomNumber() {
	srand(time(NULL));
	int randNum = (rand() % 9);
	return randNum;
}

App::App(const char* label, int x, int y, int w, int h) : GlutApp(label, x, y, w, h) {
	mx = 0.0;
	my = 0.0;
	zone[0][0].x = -1.0; zone[0][0].y = 1.00; zone[0][0].w = 0.66; zone[0][0].h = 0.66;
	zone[1][0].x = -0.33; zone[1][0].y = 1.00; zone[1][0].w = 0.66; zone[1][0].h = 0.66;
	zone[2][0].x = 0.33; zone[2][0].y = 1.00; zone[2][0].w = 0.66; zone[2][0].h = 0.66;
	zone[0][1].x = -1.0; zone[0][1].y = 0.33; zone[0][1].w = 0.66; zone[0][1].h = 0.66;
	zone[1][1].x = -0.33; zone[1][1].y = 0.33; zone[1][1].w = 0.66; zone[1][1].h = 0.66;
	zone[2][1].x = 0.33; zone[2][1].y = 0.33; zone[2][1].w = 0.66; zone[2][1].h = 0.66;
	zone[0][2].x = -1.0; zone[0][2].y = -0.33; zone[0][2].w = 0.66; zone[0][2].h = 0.66;
	zone[1][2].x = -0.33; zone[1][2].y = -0.33; zone[1][2].w = 0.66; zone[1][2].h = 0.66;
	zone[2][2].x = 0.33; zone[2][2].y = -0.33; zone[2][2].w = 0.66; zone[2][2].h = 0.66;
}

//-------------------------------------------------------
// A function to draw the scene
//-------------------------------------------------------
void App::draw() {
	
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color to black
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (counter == 1) {
		cout << "Type '0' for singleplayer mode or type '1' for 2-player mode: " << endl;
		cin >> useAI;
	}

	drawGrid();

	if (switchXorO == 0) {
		XorO = drawX;
	}
	else {
		XorO = drawO;
	}
	
	if (useAI == 1 && counter >= 3 && counter <= 10 && playerWon == 'n') {
		hasPlayed = 0;

		while (hasPlayed == 0) {
			randNum = getRandomNumber();

			if ((randNum == 0) && (zone[0][0].isused == 0)) {
				zone[0][0].isused = 1;
				zone[0][0].occupied = 'o';
				hasPlayed = 1;
				break;
			}
			else if ((randNum == 1) && (zone[1][0].isused == 0)) {
				zone[1][0].isused = 1;
				zone[1][0].occupied = 'o';
				hasPlayed = 1;
				break;
			}
			else if ((randNum == 2) && (zone[2][0].isused == 0)) {
				zone[2][0].isused = 1;
				zone[2][0].occupied = 'o';
				hasPlayed = 1;
				break;
			}
			else if ((randNum == 3) && (zone[0][1].isused == 0)) {
				zone[0][1].isused = 1;
				zone[0][1].occupied = 'o';
				hasPlayed = 1;
				break;
			}
			else if ((randNum == 4) && (zone[1][1].isused == 0)) {
				zone[1][1].isused = 1;
				zone[1][1].occupied = 'o';
				hasPlayed = 1;
				break;
			}
			else if ((randNum == 5) && (zone[2][1].isused == 0)) {
				zone[2][1].isused = 1;
				zone[2][1].occupied = 'o';
				hasPlayed = 1;
				break;
			}
			else if ((randNum == 6) && (zone[0][2].isused == 0)) {
				drawO(-0.66, -0.66);
				zone[0][2].isused = 1;
				zone[0][2].occupied = 'o';
				hasPlayed = 1;
				break;
			}
			else if ((randNum == 7) && (zone[1][2].isused == 0)) {
				zone[1][2].isused = 1;
				zone[1][2].occupied = 'o';
				hasPlayed = 1;
				break;
			}
			else if ((randNum == 8) && (zone[2][2].isused == 0)) {
				zone[2][2].isused = 1;
				zone[2][2].occupied = 'o';
				hasPlayed = 1;
				break;
			}
		}
	}

		if (zone[0][0].getused() == 1 && playerWon == 'n') {
			if (zone[0][0].occupied == 'x') { drawX(-0.66, 0.66); }
			else { drawO(-0.66, 0.66); }
		}
		if (zone[1][0].getused() == 1) {
			if (zone[1][0].occupied == 'x') { drawX(0.00, 0.66); }
			else { drawO(0.00, 0.66); }
		}
		if (zone[2][0].getused() == 1) {
			if (zone[2][0].occupied == 'x') { drawX(0.66, 0.66); }
			else { drawO(0.66, 0.66); }
		}
		if (zone[0][1].getused() == 1) {
			if (zone[0][1].occupied == 'x') { drawX(-0.66, 0.00); }
			else { drawO(-0.66, 0.00); }
		}
		if (zone[1][1].getused() == 1) {
			if (zone[1][1].occupied == 'x') { drawX(0.00, 0.00); }
			else { drawO(0.00, 0.00); }
		}
		if (zone[2][1].getused() == 1) {
			if (zone[2][1].occupied == 'x') { drawX(0.66, 0.00); }
			else { drawO(0.66, 0.00); }
		}
		if (zone[0][2].getused() == 1) {
			if (zone[0][2].occupied == 'x') { drawX(-0.66, -0.66); }
			else { drawO(-0.66, -0.66); }
		}
		if (zone[1][2].getused() == 1) {
			if (zone[1][2].occupied == 'x') { drawX(0.00, -0.66); }
			else { drawO(0.00, -0.66); }
		}
		if (zone[2][2].getused() == 1) {
			if (zone[2][2].occupied == 'x') { drawX(0.66, -0.66); }
			else { drawO(0.66, -0.66); }
		}

		if (useAI == 1 || counter == 1) {
			counter++;
		}

		if (counter >= 5) {
			for (int i = 0; i <= 2; i++) {
				if ((zone[i][0].occupied == zone[i][1].occupied && (zone[i][0].occupied == zone[i][2].occupied)) && (zone[i][0].occupied != ' ')) { playerWon = zone[i][0].occupied; break; }
				if ((zone[0][i].occupied == zone[1][i].occupied && (zone[0][i].occupied == zone[2][i].occupied)) && (zone[0][i].occupied != ' ')) { playerWon = zone[0][i].occupied; break; }
				if ((zone[0][0].occupied == zone[1][1].occupied && (zone[0][0].occupied == zone[2][2].occupied)) && (zone[1][1].occupied != ' ')) { playerWon = zone[1][1].occupied; break; }
				if ((zone[0][2].occupied == zone[1][1].occupied && (zone[0][2].occupied == zone[2][0].occupied)) && (zone[1][1].occupied != ' ')) { playerWon = zone[1][1].occupied; break; }
			}
		}

		if (playerWon == 'x') {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// Set background color to black
			glClearColor(0.0, 0.0, 0.0, 1.0);

			winnerPlayerX();
		}
		else if (playerWon == 'o') {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// Set background color to black
			glClearColor(0.0, 0.0, 0.0, 1.0);

			winnerPlayerO();
		}

		if (playerWon == 'n') {
			glutSwapBuffers();
		}
}

/* FUNCTIONS */

void App::mouseDown(float x, float y) {
	// Update app state
	mx = x;
	my = y;

	if (zone[0][0].contains(mx, my) && (zone[0][0].isused == 0)) { zone[0][0].isused = 1; XorO(-0.66, 0.66); if (XorO == drawX) { zone[0][0].occupied = 'x'; } else { zone[0][0].occupied = 'o'; } } //top row, leftmost
	if (zone[1][0].contains(mx, my) && (zone[1][0].isused == 0)) { zone[1][0].isused = 1; XorO(0.00, 0.66); if (XorO == drawX) { zone[1][0].occupied = 'x'; } else { zone[1][0].occupied = 'o'; } } //top row, middle
	if (zone[2][0].contains(mx, my) && (zone[2][0].isused == 0)) { zone[2][0].isused = 1; XorO(0.66, 0.66); if (XorO == drawX) { zone[2][0].occupied = 'x'; } else { zone[2][0].occupied = 'o'; } } //top row, rightmost
	if (zone[0][1].contains(mx, my) && (zone[0][1].isused == 0)) { zone[0][1].isused = 1; XorO(-0.66, 0.00); if (XorO == drawX) { zone[0][1].occupied = 'x'; } else { zone[0][1].occupied = 'o'; } } //mid row, leftmost
	if (zone[1][1].contains(mx, my) && (zone[1][1].isused == 0)) { zone[1][1].isused = 1; XorO(0.00, 0.00); if (XorO == drawX) { zone[1][1].occupied = 'x'; } else { zone[1][1].occupied = 'o'; } } //mid row, middle
	if (zone[2][1].contains(mx, my) && (zone[2][1].isused == 0)) { zone[2][1].isused = 1; XorO(0.66, 0.00); if (XorO == drawX) { zone[2][1].occupied = 'x'; } else { zone[2][1].occupied = 'o'; } } //mid row, rightmost
	if (zone[0][2].contains(mx, my) && (zone[0][2].isused == 0)) { zone[0][2].isused = 1; XorO(-0.66, -0.66); if (XorO == drawX) { zone[0][2].occupied = 'x'; } else { zone[0][2].occupied = 'o'; } } //bottom row, leftmost
	if (zone[1][2].contains(mx, my) && (zone[1][2].isused == 0)) { zone[1][2].isused = 1; XorO(0.00, -0.66); if (XorO == drawX) { zone[1][2].occupied = 'x'; } else { zone[1][2].occupied = 'o'; } } //bottom row, middle
	if (zone[2][2].contains(mx, my) && (zone[2][2].isused == 0)) { zone[2][2].isused = 1; XorO(0.66, -0.66); if (XorO == drawX) { zone[2][2].occupied = 'x'; } else { zone[2][2].occupied = 'o'; } } //bottom row, rightmost
	
	glutSwapBuffers();

	if (counter >= 5) {
		for (int i = 0; i <= 2; i++) {
			if ((zone[i][0].occupied == zone[i][1].occupied && (zone[i][0].occupied == zone[i][2].occupied)) && (zone[i][0].occupied != ' ')) { playerWon = zone[i][0].occupied; break; }
			if ((zone[0][i].occupied == zone[1][i].occupied && (zone[0][i].occupied == zone[2][i].occupied)) && (zone[0][i].occupied != ' ')) { playerWon = zone[0][i].occupied; break; }
			if ((zone[0][0].occupied == zone[1][1].occupied && (zone[0][0].occupied == zone[2][2].occupied)) && (zone[1][1].occupied != ' ')) { playerWon = zone[1][1].occupied; break; }
			if ((zone[0][2].occupied == zone[1][1].occupied && (zone[0][2].occupied == zone[2][0].occupied)) && (zone[1][1].occupied != ' ')) { playerWon = zone[1][1].occupied; break; }
		}
	}

	if (playerWon == 'x') {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Set background color to black
		glClearColor(0.0, 0.0, 0.0, 1.0);

		winnerPlayerX();
	}
	else if (playerWon == 'o') {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Set background color to black
		glClearColor(0.0, 0.0, 0.0, 1.0);

		winnerPlayerO();
	}

	if (useAI == 0) {
		switchXorO = !(switchXorO);
		// Redraw the scene
	}
	glutSwapBuffers();
	counter++;
}

void App::mouseDrag(float x, float y) {
	// Update app state
	mx = x;
	my = y;

}

void App::keyPress(unsigned char key) {
	if (key == 27) {
		// Exit the app when Esc key is pressed
		exit(0);
	}
}
