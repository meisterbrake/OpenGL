//
//  segundo.cpp
//  OpenGL
//
//  Created by Fermin Osorio on 4/15/19.
//  Copyright © 2019 Fermin Osorio. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

int x=1;
void Mostrar(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f(-0.25, 0.25, -0.25);
    glVertex3f(-0.25, -0.25, 0.25);
    glVertex3f(0.25, -0.25, 0.25);
    glVertex3f(0.25, 0.25, -0.25);
    glEnd();

    
    glPopMatrix();
    glFlush();
    
}

void iniciar(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor4f(0.0, 1.0, 1.0, 1.0);
    gluPerspective(60.0, 1.0, 1.0, 100.0);
    glTranslatef(0.0, 0.0, -2.0);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    //gluOrtho2D(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH|GL_DEPTH_BUFFER_BIT);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Perspectiva");
    iniciar();
    glutDisplayFunc(Mostrar);
    glutMainLoop();
    return 0;
}


