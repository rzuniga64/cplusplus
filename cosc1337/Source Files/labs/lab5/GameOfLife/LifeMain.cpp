#include "Graphics.h"
#include "LifeGrid.h"
#include <iostream>

LifeGrid grid(WINDOW_WIDTH, WINDOW_HEIGHT);

void drawScene(void) {
    clearWindow();
    grid.draw();
    glutSwapBuffers();
}

void animate() {
    grid.update();
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

