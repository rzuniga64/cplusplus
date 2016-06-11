#include "Graphics.h"
#include "Ball.h"
#include <ctime>
#include <vector>


vector<Ball *> ballVector;

void drawScene(void) {
    clearWindow(); 

	for (size_t i = 0; i < ballVector.size(); i++)
		ballVector[i]->draw();
    glutSwapBuffers();
}

void animate() {
	static GraphicsTimer timer;
	int ms = timer.deltaT();
	for (size_t i = 0; i < ballVector.size(); i++)
		ballVector[i]->update(ms);
    glutPostRedisplay();
}

void handleKey(unsigned char key, int x, int y) {
    switch(key) {
        case 'q':
			for (size_t i = 0; i < ballVector.size(); i++)
				delete ballVector[i];
			ballVector.clear();
            exit(0);
            break;
		case 'b':
			ballVector.push_back(new Ball(WINDOW_WIDTH, WINDOW_HEIGHT));
			break;
		case 'd':
			for (size_t i = 0; i < ballVector.size(); i++)
				delete ballVector[i];
			ballVector.clear();
    }
}


int main(int argc, char **argv) {
    srand(time(0));
    graphicsSetup(argc, argv);
    glutDisplayFunc(drawScene);
    glutIdleFunc(animate);
    glutKeyboardFunc(handleKey);
    glutMainLoop();
    glutSwapBuffers();
}

