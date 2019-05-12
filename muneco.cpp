//
//  muneco.cpp
//  OpenGL
//
//  Created by Fermin Osorio on 5/11/19.
//  Copyright © 2019 Fermin Osorio. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

int x=1;
void Mostrar(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

   //Cabeza
    glPushMatrix();
        
        glTranslatef(0.0,3,-9);
        glColor3f(1.0f, 0.88f, 0.58f); // crema
        glutSolidSphere(1,50,50);
    glPopMatrix();
    
    //cuerpo
    glPushMatrix();    
        glTranslatef(0.0,0.2,-9);
        glColor3f(0.0469,0.67,0.5038); //verde-acua
        glutSolidCube(3);
    glPopMatrix();

    //brazo der
    glPushMatrix();     
        glTranslatef(2.0,0.3,-9);
        glColor3f(0.0392,0.49,0.3698); //verde-acua-oscuro
        glRotatef(40, 0.0, 2.0, 2.0);
        glScalef(0.2f,1.0f,0.2f);
        glutSolidCube(3);
    glPopMatrix();

    //brazo izq
    glPushMatrix();     
        glTranslatef(-2.0,0.3,-9);
        glColor3f(0.0392,0.49,0.3698); //verde-acua-oscuro
        glRotatef(40, 0.0, -2.0, -2.0);
        glScalef(0.2f,1.0f,0.2f);
        glutSolidCube(3);
    glPopMatrix();

    //correa
    glPushMatrix();    
        glTranslatef(0.0,-1.4,-9);
        glScalef(1.0f,0.30f,0.6f);
        glColor3f(0.49,0.3548,0.0392); //chocolate
        glutSolidCube(3);
    glPopMatrix();

    //hebilla-correa
    glPushMatrix();    
        glTranslatef(0.0,-1.4,-9);
        glScalef(0.30f,0.30f,0.9f);
        glColor3f(0.74,0.699,0.24); //dorado
        glutSolidCube(3);
    glPopMatrix();

    //pierna izq
    glPushMatrix();
        glTranslatef(-1.0,-3.4,-9);
         glScalef(0.35f,1.0f,0.6f);
         glColor3f(0.0392,0.227,0.49); //azul-marino
        glutSolidCube(3);
    glPopMatrix();

     //pierna der
    glPushMatrix();
        glTranslatef(1.0,-3.4,-9);
        glScalef(0.35f,1.0f,0.6f);
        glColor3f(0.0392,0.227,0.49); //azul-marino
        glutSolidCube(3);
    glPopMatrix();

    //pie der
    glPushMatrix();
        glColor3f(0.74,0.699,0.24); //dorado
        glTranslatef(1.0,-4.7,-9);
        glScalef(0.37f,0.1f,0.8f);
        glutSolidCube(3);
    glPopMatrix();

        //pie izq
    glPushMatrix();
        glColor3f(0.74,0.699,0.24); //dorado
        glTranslatef(-1.0,-4.7,-9);
        glScalef(0.37f,0.1f,0.8f);
        glutSolidCube(3);
    glPopMatrix();
    
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
    glutCreateWindow("Muñeco");
    iniciar();
    glutDisplayFunc(Mostrar);
    glutMainLoop();
    return 0;
}


