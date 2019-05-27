//
//  rebote.cpp
//  OpenGL
//
//  Created by Fermin Osorio on 5/27/19.
//  Copyright © 2019 Fermin Osorio. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

GLfloat x1 = 0.0f;
GLfloat y1 = 0.0f;
GLfloat rsize = 25;

GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;

GLfloat windowWidth;
GLfloat windowHeight;

void dibujarescena(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.75,0.0975,0.0975);
    glRectf(x1, y1, x1 + rsize, y1 - rsize);
    glutSwapBuffers();
}

void cronometro(int valor){
    if(x1 > windowWidth-rsize || x1 < -windowWidth) //error aqui salia y1 en vez de x1
        xstep = -xstep; //error aqui, vuevle a la direccion contraria cuando toca la parte izq o der
    if(y1 > windowHeight || y1 < -windowHeight + rsize)
        ystep = -ystep;
        
    x1 += xstep;
    y1 += ystep;

    if(x1 > (windowWidth - rsize + xstep))
        x1 = windowWidth-rsize-1;
    else if(x1 < -(windowWidth + xstep))
        x1 = - windowWidth - 1;

    if(y1 > (windowHeight + ystep))
        y1 = windowHeight - 1;
    else if(y1 < -(windowHeight - rsize + ystep))
        y1 = -windowHeight + rsize - 1;

    glutPostRedisplay();
    glutTimerFunc(33, cronometro, 1);
}

void Azul(void){

    glClearColor(0.0106f, 0.279f, 0.53f, 1.0f);
}

void escalado (GLsizei w, GLsizei h){
    GLfloat aspectRatio;
     if(h==0)
        h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (GLfloat)w/(GLfloat)h;

    if(w<=h){
        windowWidth = 100;
        windowHeight = 100 / aspectRatio;
        glOrtho(-windowWidth, windowWidth, -100.0, 100.0, 1.0, -1.0);
    }else{
        windowWidth = 100 * aspectRatio;
        windowHeight = 100;
        glOrtho(-windowWidth, windowWidth, -100.0, 100.0, 1.0, -1.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Rebotar");
    glutDisplayFunc(dibujarescena);
    glutReshapeFunc(escalado);
    glutTimerFunc(33, cronometro, 1);
    Azul();
    glutMainLoop();
    return 0;
}
