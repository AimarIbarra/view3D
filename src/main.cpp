#include <windows.h>
#include <GL/glut.h>
// #include <iostream>

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2d(0.0f, -0.5f);
    glVertex2d(-0.5f, -0.0f);
    glVertex2d(0.5f, -0.0f);
    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    // Code from Sample Site

    glutInit(&argc, argv); // Initialize GLUT
    glutCreateWindow(
        "OpenGL Setup Test");     // Create a window with the given title
    glutInitWindowSize(320, 320); // Set the window's initial width & height
    glutInitWindowPosition(50,
                           50); // Position the window's initial top-left corner
    glutDisplayFunc(
        display);   // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
