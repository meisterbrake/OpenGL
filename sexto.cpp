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
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    
    glBegin(GL_QUADS);
        glColor4f(0.0, 1.0, 1.0, 1.0);
        //primer vertice superior izq
        glVertex3f(-0.25, 0.25, -0.25);
        //segundo vertice inferior izq
        glVertex3f(-0.25, -0.25, 0.25);
        //tercer vertice inferior der
        glVertex3f(0.25, -0.25, 0.25);
        //cuarto vertice superior der
        glVertex3f(0.25, 0.25, -0.25);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1,0,0);
        //primer vertice superior
        glVertex3f(0.0,0.30,0);
        //segundo vertice inferior izq
        glVertex3f(-0.30,-0.30,0);
        //tercer vertice interior der
        glVertex3f(0.3,-0.30,0);
    glEnd();
    
    glFlush();
    
}

void iniciar(){
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluPerspective(60.0, 1.0, 1.0, 100.0);
    glTranslatef(0.0, 0.0, -2.0);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Perspectiva");
    iniciar();
    glutDisplayFunc(Mostrar);
    glutMainLoop();
    return 0;
}


