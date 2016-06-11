#include "Graphics.h"
#define _USE_MATH_DEFINES
#include <math.h>

GLfloat ballRadius = 60.0f;			// Radius of the bouncing ball
GLfloat ballX = WINDOW_WIDTH/2.0;   // Ball's center (x, y) position
GLfloat ballY = WINDOW_HEIGHT/2.0;
GLfloat ballXMax, ballXMin, ballYMax, ballYMin; // Ball's center (x, y) bounds
GLfloat xSpeed = 5.0f;				// Ball's speed in x and y directions
GLfloat ySpeed = 2.5f;
int refreshMillis = 30;				// Refresh period in milliseconds

// Projection clipping area
GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;

/* Initialize OpenGL Graphics */
void initGL() {
	glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
}

/* Callback handler for window re-paint event */
void display() {
	glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer
	glMatrixMode(GL_MODELVIEW);    // To operate on the model-view matrix
	glLoadIdentity();              // Reset model-view matrix

	glTranslatef(ballX, ballY, 0.0f);  // Translate to (xPos, yPos)
	// Use triangular segments to form a circle
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f);  // Blue
	glVertex2f(0.0f, 0.0f);       // Center of circle
	int numSegments = 100;
	GLfloat angle;
	for (int i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
		angle = i * 2.0f * M_PI / numSegments;  // 360 deg for all segments
		glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
	}
	glEnd();

	glutSwapBuffers();  // Swap front and back buffers (of double buffered mode)

	// Animation Control - compute the location for the next refresh
	ballX += xSpeed;
	ballY += ySpeed;
	// Check if the ball exceeds the edges
	if (ballX > ballXMax) {
		ballX = ballXMax;
		xSpeed = -xSpeed;
	}
	else if (ballX < ballXMin) {
		ballX = ballXMin;
		xSpeed = -xSpeed;
	}
	if (ballY > ballYMax) {
		ballY = ballYMax;
		ySpeed = -ySpeed;
	}
	else if (ballY < ballYMin) {
		ballY = ballYMin;
		ySpeed = -ySpeed;
	}
}

/* Call back when the windows is re-sized */
void reshape(GLsizei width, GLsizei height) {
	// Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping area to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset the projection matrix
	if (width >= height) {
		clipAreaXLeft = 0.0;
		clipAreaXRight = WINDOW_WIDTH * aspect;
		clipAreaYBottom = 0;
		clipAreaYTop = WINDOW_HEIGHT;
	}
	else {
		clipAreaXLeft = 0.0;
		clipAreaXRight = WINDOW_WIDTH;
		clipAreaYBottom = 0.0;
		clipAreaYTop = WINDOW_HEIGHT / aspect;
	}
	gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop);
	ballXMin = clipAreaXLeft + ballRadius;
	ballXMax = clipAreaXRight - ballRadius;
	ballYMin = clipAreaYBottom + ballRadius;
	ballYMax = clipAreaYTop - ballRadius;
}

/* Called back when the timer expired */
void Timer(int value) {
	glutPostRedisplay();    // Post a paint request to activate display()
	glutTimerFunc(refreshMillis, Timer, 0); // subsequent timer call at milliseconds
}

void drawScene(void) {
	// always clear the window before drawing
    clearWindow(); 

	display();
	
	// don't remove this line, or your drawing won't appear
    glutSwapBuffers();
}

/* handleKey function
   Determines how particular keystrokes should be
   handled by the program.  Right now 'q' quits the 
   program, and all other keystrokes do nothing.
   There is no need to change this function. 
   */
void handleKey(unsigned char key, int x, int y) {
    switch(key) {
        case 'q':
            exit(0);
            break;
    }
}

/* Main function.  Initializes everything.
   You shouldn't need to modify this function
   at all.  Rather, you should modify the drawScene function to
   draw your picture.  It is automatically called when the 
   window is drawn on the screen because of the initialization
   below. */
int main(int argc, char **argv) {
    graphicsSetup(argc, argv);
    glutDisplayFunc(drawScene);
	glutReshapeFunc(reshape);     // Register callback handler for window re-shape
	glutTimerFunc(0, Timer, 0);   // First timer call immediately
	initGL();                     // Our own OpenGL initialization
    glutKeyboardFunc(handleKey);
    glutMainLoop();
}
