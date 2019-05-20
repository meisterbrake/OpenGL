//
//  parcial.cpp - Practica
//  OpenGL
//
//  Created by Fermin Osorio on 5/20/19.
//  Copyright © 2019 Fermin Osorio. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
static float angulo = 0;

//colores de cono 1
static float r1 = 0.1422;
static float g1 = 0.6281;
static float b1 = 0.79;

//colores de esfera
static float r2 = 0.91;
static float g2 = 0.324;
static float b2 = 0.0728;

//colores de cono 2
static float r3 = 0.0861;
static float g3 = 0.69;
static float b3 = 0.0759;

void GoMenu(int value);

void init()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING); //sombras
    glEnable(GL_LIGHT0); //luz
    glEnable(GL_COLOR_MATERIAL);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    
    gluPerspective(60.0,1.0,1.0,100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //se mueve hacia atras un poco
    glTranslatef( 0, 0, -28 );

    //cono azul
    glPushMatrix();
        glTranslatef(-10,0,0);
        glRotatef(angulo, 2, 3, 5);
        glColor3f(r1, g1, b1);
        glutSolidCone(4,5,7,7);
    glPopMatrix();

    //esfera wire rojo
    glPushMatrix();
        glTranslatef(0,0,0);
        glRotatef(angulo, -2, -3, -5);
        glColor3f(r2, g2, b2);
        glutWireSphere(4,50,50);
    glPopMatrix();

    //cono verde
    glPushMatrix();
        glTranslatef(10,0,0);
        glRotatef(angulo, 2, 3, 5);
        glColor3f(r3, g3, b3);
        glutSolidCone(4,5,7,7);
    glPopMatrix();

    glutSwapBuffers();
}



void idle()
{
    angulo += 0.9f; //velocidad
    glutPostRedisplay();
}

void mouse(unsigned char button, int x, int y){
    switch (button) {
        case 'r':
           
                glutIdleFunc(idle);
            break;
            
        case 's':
          
                glutIdleFunc(0);
            break;
        default:
            break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Practica de Parcial 1 - Fermin Osorio");
    
    //menu
    int sub1=glutCreateMenu(GoMenu);
    glutAddMenuEntry("Cono Morado",1);
    glutAddMenuEntry("Esfera Roja",2); 
    glutAddMenuEntry("Cono Verde",3);
    glutCreateMenu(GoMenu);
    glutAddSubMenu("Colors",sub1);
    
    
    glutAddMenuEntry("Fondo Amarillo",4);
    glutAddMenuEntry("Fondo Negro",5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutDisplayFunc(display);
    //glutIdleFunc(idle);
    glutKeyboardFunc(mouse);
    
    init();
    glutMainLoop();
    return 0;
}

void GoMenu(int value){
    switch(value){
        case 1: 
            r1 = 0.3937;
            g1 = 0.3225;
            b1 = 0.75;
            
        break;

        case 2:
            r2 = 0.73;
            g2 = 0.0438;
            b2 = 0.0438;
        break;
        
        case 3:
            r3 = 0.93;
            g3 = 0.9162;
            b3 = 0.1023;
        break;
        
        case 4:
            glClearColor(0.92, 0.91, 0.322,1.0);
        break;

         case 5:
            glClearColor(0.0, 0.0, 0.0,1.0);
        break;
    }
    glutPostRedisplay();
}