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

   //Cabeza
    glPushMatrix();
        
        glTranslatef(0.0,3,-9);
        glColor3f(1,5,0);
        glutSolidSphere(1,50,50);
    glPopMatrix();
    
    //cuerpo
    glPushMatrix();    
        glTranslatef(0.0,0.2,-9);
        glColor3f(2,0,0);
        glutSolidCube(3);
    glPopMatrix();

    //brazo der
    glPushMatrix();     
        glTranslatef(2.2,0.0,-9);
        glColor3f(2,0,0);
        
        glScalef(0.2f,1.0f,1.0f);
        glutSolidCube(3);
    glPopMatrix();

    //pierna izq
    glPushMatrix();
       
        glTranslatef(-1.2,-2.8,-9);
         glScalef(0.2f,1.0f,1.0f);
         glColor3f(0,3,0);
        glutSolidCube(3);
    glPopMatrix();

     //pierna der
    glPushMatrix();
        glColor3f(0,3,0);
        glTranslatef(1.2,-2.8,-9);
        glScalef(0.2f,1.0f,1.0f);
        glutSolidCube(3);
    glPopMatrix();

    //pie der
    glPushMatrix();
        glColor3f(1,5,0);
        glTranslatef(1.2,-4.5,-9);
        glScalef(0.2f,0.3f,1.0f);
        glutSolidCube(3);
    glPopMatrix();

        //pie izq
    glPushMatrix();
        glColor3f(1,5,0);
        glTranslatef(-1.2,-4.5,-9);
        glScalef(0.2f,0.3f,1.0f);
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
    glutCreateWindow("Muneco");
    iniciar();
    glutDisplayFunc(Mostrar);
    glutMainLoop();
    return 0;
}


