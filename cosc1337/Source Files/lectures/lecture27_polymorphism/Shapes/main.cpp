#include "Graphics.h"
#include "Shapes.h"
#include <ctime>
#include <vector>

vector<Shape*> shapes;

void drawScene(void) {
    clearWindow();
    
    for (size_t i=0; i<shapes.size(); i++)
        shapes[i]->draw();

    glFlush();
}

void animate(int) {
    for (size_t i=0; i<shapes.size(); i++)
        shapes[i]->update();
    
    glutPostRedisplay();
	glutTimerFunc(20, animate, 0);
}

void handleKey(unsigned char key, int x, int y) {
    switch(key) {
        case 'b':
            shapes.push_back(new Circle(WINDOW_WIDTH, WINDOW_HEIGHT));
            break;
        case 't':
            shapes.push_back(new Triangle(WINDOW_WIDTH, WINDOW_HEIGHT));
            break;
        case 'r':
            shapes.push_back(new Box(WINDOW_WIDTH, WINDOW_HEIGHT));
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
    glutTimerFunc(20, animate, 0);
    glutKeyboardFunc(handleKey);
    glutMainLoop();
    glutSwapBuffers();
}

