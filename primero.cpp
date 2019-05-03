//
//  primero.cpp
//  OpenGL
//
//  Created by Fermin Osorio on 4/15/19.
//  Copyright © 2019 Fermin Osorio. All rights reserved.
//


#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

int x=1;
void Display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    for(int i=0; i<4; i++){
        glTranslatef(i*(-0.5), 0, 0);
        glScalef(x, x, 1);
        x=x*1.5;
        glRotatef(i*180, 0, 0, 1);
        glTranslatef(i*50, 0, 0);
        glRecti(0, 0, 60, 40);
        
    }
    glPopMatrix();
    glFlush();
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glViewport(0, 0, 300, 200);
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
    
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(300, 200);
    glutCreateWindow("Fermin Osorio");
    init();
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
