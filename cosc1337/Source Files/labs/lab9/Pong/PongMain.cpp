#include "Graphics.h"
#include "PongGame.h"
#include <vector>

PongGame * game;

void drawScene(void) {
    clearWindow();
    game->draw();
    glutSwapBuffers();
}

void animate(int) {
    game->update();
    glutPostRedisplay();
	glutTimerFunc(20, animate, 0);
}

void handleKeyDown(unsigned char key, int x, int y) {
    switch(key) {
        case 'q':
            exit(0);
            break;
        default:
            game->handleKeyDown(key);
            break;
    }
}

void handleKeyUp(unsigned char key, int x, int y) {
    game->handleKeyUp(key);
}

int main(int argc, char **argv) {
    graphicsSetup(argc, argv);
    srand(time(0));
    game = new PongGame(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutDisplayFunc(drawScene);
    glutTimerFunc(20, animate, 0);
    glutKeyboardFunc(handleKeyDown);
    glutKeyboardUpFunc(handleKeyUp);
    glutMainLoop();
    glutSwapBuffers();
}

