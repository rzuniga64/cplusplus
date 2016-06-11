#include "Graphics.h"
#include "Ball.h"

Ball ball(50, WINDOW_WIDTH, WINDOW_HEIGHT, RED);

void drawScene(void) {
    clearWindow(); 

    ball.draw();
    glutSwapBuffers();
}

void animate() {
    ball.update();
    glutPostRedisplay();
}

void handleKey(unsigned char key, int x, int y) {
    switch(key) {
        case 'q':
            exit(0);
            break;
    }
}


int main(int argc, char **argv) {
    graphicsSetup(argc, argv);
    glutDisplayFunc(drawScene);
    glutIdleFunc(animate);
    glutKeyboardFunc(handleKey);
    glutMainLoop();
    glutSwapBuffers();
}

