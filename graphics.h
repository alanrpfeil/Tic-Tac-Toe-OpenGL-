#ifndef graphics_h
#define graphics_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif
#include <cmath>

void drawGrid() {	//3x3 Grid
	glColor3f(0.5, 0.5, 0.5);
	glLineWidth(2.0);

	glBegin(GL_LINES);
	glVertex2d(-0.33, 1.00);
	glVertex2d(-0.33, -1.00);
	glEnd();

	glBegin(GL_LINES);
	glVertex2d(0.33, 1.00);
	glVertex2d(0.33, -1.00);
	glEnd();

	glBegin(GL_LINES);
	glVertex2d(-1.00, 0.33);
	glVertex2d(1.00, 0.33);
	glEnd();

	glBegin(GL_LINES);
	glVertex2d(-1.00, -0.33);
	glVertex2d(1.00, -0.33);
	glEnd();

}

void drawX(double xorigin, double yorigin) {
	glColor3f(0.2,0.5,0.5);
	glLineWidth(7.0);

	glBegin(GL_LINES);
	glVertex2d((xorigin - 0.29),(yorigin + 0.29)); //top-left vertex
	glVertex2d((xorigin + 0.29),(yorigin - 0.29)); //bottom-right vertex
	glEnd();

	glBegin(GL_LINES);
	glVertex2d((xorigin + 0.29),(yorigin + 0.29)); //top-right vertex
	glVertex2d((xorigin - 0.29),(yorigin - 0.29)); //bottom-left vertex
	glEnd();
}

void drawO(double xorigin, double yorigin) {
	glColor3f(0.5, 0.2, 0.2);
	double const pi = 3.1415926;
	double r = 0.29, dtheta = 0.0;

	glBegin(GL_POLYGON);
	for (int i = 0; i <= 25; i++) {
		glVertex2d((xorigin + r*cos(dtheta)), (yorigin + r*sin(dtheta)));
		dtheta += ((2 * pi) / 25);
	}
	glEnd();

	dtheta = 0;
	r = 0.26;
	glBegin(GL_POLYGON);
	glColor3d(0.0, 0.0, 0.0);	//A disk; not a plate. Masking a black circle over colored circle for ring effect
	for (int i = 0; i <= 25; i++) {
		glVertex3d((xorigin + r * cos(dtheta)), (yorigin + r * sin(dtheta)), -1);
		dtheta += ((2 * pi) / 25);
	}
	glEnd();
}

void winnerPlayerX() {
	glColor3f(0.2, 0.5, 0.5);
	glLineWidth(8);
	glBegin(GL_LINES);

	glVertex2d(-0.60, 0.10);
	glVertex2d(-0.60, 0.30);
	glVertex2d(-0.60, 0.30);
	glVertex2d(-0.50, 0.30);
	glVertex2d(-0.50, 0.30);		//P
	glVertex2d(-0.50, 0.20);
	glVertex2d(-0.50, 0.20);
	glVertex2d(-0.60, 0.20);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(-0.40, 0.30);
	glVertex2d(-0.40, 0.10);		//L
	glVertex2d(-0.40, 0.10);
	glVertex2d(-0.30, 0.10);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(-0.20, 0.10);
	glVertex2d(-0.20, 0.30);
	glVertex2d(-0.20, 0.30);
	glVertex2d(-0.10, 0.30);
	glVertex2d(-0.10, 0.30);		//A
	glVertex2d(-0.10, 0.10);
	glVertex2d(-0.10, 0.10);
	glVertex2d(-0.10, 0.20);
	glVertex2d(-0.10, 0.20);
	glVertex2d(-0.20, 0.20);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(0.05, 0.10);
	glVertex2d(0.05, 0.20);
	glVertex2d(0.05, 0.20);
	glVertex2d(0.00, 0.30);
	glVertex2d(0.00, 0.30);			//Y
	glVertex2d(0.05, 0.20);
	glVertex2d(0.05, 0.20);
	glVertex2d(0.10, 0.30);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(0.20, 0.10);
	glVertex2d(0.30, 0.10);
	glVertex2d(0.30, 0.10);
	glVertex2d(0.20, 0.10);
	glVertex2d(0.20, 0.10);
	glVertex2d(0.20, 0.20);
	glVertex2d(0.20, 0.20);			//E
	glVertex2d(0.30, 0.20);
	glVertex2d(0.30, 0.20);
	glVertex2d(0.20, 0.20);
	glVertex2d(0.20, 0.20);
	glVertex2d(0.20, 0.30);
	glVertex2d(0.20, 0.30);
	glVertex2d(0.30, 0.30);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(0.40, 0.10);
	glVertex2d(0.40, 0.30);
	glVertex2d(0.40, 0.30);
	glVertex2d(0.50, 0.30);
	glVertex2d(0.50, 0.30);			//R
	glVertex2d(0.50, 0.20);
	glVertex2d(0.50, 0.20);
	glVertex2d(0.40, 0.20);
	glVertex2d(0.40, 0.20);
	glVertex2d(0.50, 0.10);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(0.05, 0.05);
	glVertex2d(-0.05, -0.15);

	glEnd();
									//X
	glBegin(GL_LINES);

	glVertex2d(-0.05, 0.05); 
	glVertex2d(0.05, -0.15);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(-0.30, -0.20);
	glVertex2d(-0.275, -0.40);
	glVertex2d(-0.275, -0.40);
	glVertex2d(-0.25, -0.20);
	glVertex2d(-0.25, -0.20);		//W
	glVertex2d(-0.225, -0.40);
	glVertex2d(-0.225, -0.40);
	glVertex2d(-0.20, -0.20);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(-0.10, -0.40);
	glVertex2d(-0.10, -0.20);
	glVertex2d(-0.10, -0.20);
	glVertex2d(0.00, -0.20);
	glVertex2d(0.00, -0.20);		//O
	glVertex2d(0.00, -0.40);
	glVertex2d(0.00, -0.40);
	glVertex2d(-0.10, -0.40);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(0.10, -0.40);
	glVertex2d(0.10, -0.20);
	glVertex2d(0.10, -0.20);
	glVertex2d(0.20, -0.40);		//N
	glVertex2d(0.20, -0.40);
	glVertex2d(0.20, -0.20);

	glEnd();
}

void winnerPlayerO() {

	glColor3f(0.5, 0.2, 0.2);
	glLineWidth(8);
	glBegin(GL_LINES);

	glVertex2d(-0.60, 0.10);
	glVertex2d(-0.60, 0.30);
	glVertex2d(-0.60, 0.30);
	glVertex2d(-0.50, 0.30);
	glVertex2d(-0.50, 0.30);		//P
	glVertex2d(-0.50, 0.20);
	glVertex2d(-0.50, 0.20);
	glVertex2d(-0.60, 0.20);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(-0.40, 0.30);
	glVertex2d(-0.40, 0.10);		//L
	glVertex2d(-0.40, 0.10);
	glVertex2d(-0.30, 0.10);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(-0.20, 0.10);
	glVertex2d(-0.20, 0.30);
	glVertex2d(-0.20, 0.30);
	glVertex2d(-0.10, 0.30);
	glVertex2d(-0.10, 0.30);		//A
	glVertex2d(-0.10, 0.10);
	glVertex2d(-0.10, 0.10);
	glVertex2d(-0.10, 0.20);
	glVertex2d(-0.10, 0.20);
	glVertex2d(-0.20, 0.20);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(0.05, 0.10);
	glVertex2d(0.05, 0.20);
	glVertex2d(0.05, 0.20);
	glVertex2d(0.00, 0.30);
	glVertex2d(0.00, 0.30);			//Y
	glVertex2d(0.05, 0.20);
	glVertex2d(0.05, 0.20);
	glVertex2d(0.10, 0.30);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(0.20, 0.10);
	glVertex2d(0.30, 0.10);
	glVertex2d(0.30, 0.10);
	glVertex2d(0.20, 0.10);
	glVertex2d(0.20, 0.10);
	glVertex2d(0.20, 0.20);
	glVertex2d(0.20, 0.20);			//E
	glVertex2d(0.30, 0.20);
	glVertex2d(0.30, 0.20);
	glVertex2d(0.20, 0.20);
	glVertex2d(0.20, 0.20);
	glVertex2d(0.20, 0.30);
	glVertex2d(0.20, 0.30);
	glVertex2d(0.30, 0.30);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(0.40, 0.10);
	glVertex2d(0.40, 0.30);
	glVertex2d(0.40, 0.30);
	glVertex2d(0.50, 0.30);
	glVertex2d(0.50, 0.30);			//R
	glVertex2d(0.50, 0.20);
	glVertex2d(0.50, 0.20);
	glVertex2d(0.40, 0.20);
	glVertex2d(0.40, 0.20);
	glVertex2d(0.50, 0.10);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(-0.05, -0.15);
	glVertex2d(-0.05, 0.05);
	glVertex2d(-0.05, 0.05);
	glVertex2d(0.05, 0.05);
	glVertex2d(0.05, 0.05);		//O
	glVertex2d(0.05, -0.15);
	glVertex2d(0.05, -0.15);
	glVertex2d(-0.05, -0.15);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(-0.30, -0.20);
	glVertex2d(-0.275, -0.40);
	glVertex2d(-0.275, -0.40);
	glVertex2d(-0.25, -0.20);
	glVertex2d(-0.25, -0.20);		//W
	glVertex2d(-0.225, -0.40);
	glVertex2d(-0.225, -0.40);
	glVertex2d(-0.20, -0.20);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(-0.10, -0.40);
	glVertex2d(-0.10, -0.20);
	glVertex2d(-0.10, -0.20);
	glVertex2d(0.00, -0.20);
	glVertex2d(0.00, -0.20);		//O
	glVertex2d(0.00, -0.40);
	glVertex2d(0.00, -0.40);
	glVertex2d(-0.10, -0.40);

	glEnd();

	glBegin(GL_LINES);

	glVertex2d(0.10, -0.40);
	glVertex2d(0.10, -0.20);
	glVertex2d(0.10, -0.20);
	glVertex2d(0.20, -0.40);		//N
	glVertex2d(0.20, -0.40);
	glVertex2d(0.20, -0.20);

	glEnd();
	
}

#endif
