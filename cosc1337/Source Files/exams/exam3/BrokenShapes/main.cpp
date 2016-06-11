#include "Graphics.h"
#include "Shapes.h"
#include <ctime>
#include <vector>

vector<Shape> shapes;

void drawScene(void) {
    clearWindow();
    
    for (size_t i=0; i<shapes.size(); i++)
        shapes[i].draw();

    glFlush();
}

void animate() {
    for (size_t i=0; i<shapes.size(); i++)
        shapes[i].update();
    
    glutPostRedisplay();
}

void handleKey(unsigned char key, int x, int y) {
    Shape * s;
    switch(key) {
        case 'c':
            shapes.push_back(Circle(WINDOW_WIDTH, WINDOW_HEIGHT));
            break;
        case 'b':
            shapes.push_back(Box(WINDOW_WIDTH, WINDOW_HEIGHT));
            break;
        case 't':
            shapes.push_back(Triangle(WINDOW_WIDTH, WINDOW_HEIGHT));
            break;
        case 'q':
            exit(0);
            break;
    }
}

int main(int argc, char **argv) {
    graphicsSetup(argc, argv);
    srand(time(0));
    glutDisplayFunc(drawScene);
    glutIdleFunc(animate);
    glutKeyboardFunc(handleKey);
    glutMainLoop();
    glutSwapBuffers();
}

