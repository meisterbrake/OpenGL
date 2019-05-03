//
//  tercero.cpp
//  OpenGL
//
//  Created by Fermin Osorio on 4/15/19.
//  Copyright © 2019 Fermin Osorio. All rights reserved.
//


#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

void myInit(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(7);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glVertex2i(200, 250);
    glVertex2i(300, 130);
    glVertex2i(400, 330);
    glEnd();
    glFlush();
}

int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Configuracion del entorno OPENGL");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}

