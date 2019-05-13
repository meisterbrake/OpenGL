//
//  luces.cpp
//  OpenGL
//
//  Created by Fermin Osorio on 5/13/19.
//  Copyright © 2019 Fermin Osorio. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

GLfloat mat_color [] = {0.0,1.0,1.0,1.0}; //color ambiental y difuso del material
GLfloat light_color [] = {1.0,1.0,1.0,1.0}; //color difuso y especular de la luz
GLfloat light_ambient [] = {0.0,0.0,0.0,1.0}; //color ambiental de la luz 
GLfloat normal [] = {0.0,1.0,0.0,0.0}; //valor para las normales - van hacia arriba
GLfloat light_dir [] = {0.0,1.0,0.0,0.0}; //valor de la direccion de la luz


void Mostrar(){
    glBegin(GL_QUADS);

        glNormal3f(1.0,0.0,0.0);
        glVertex3f(-1.0,0.0,-1.0);

        glNormal3fv(normal);
        glVertex3f(-1.0,0.0,1.0);

        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(1.0,0.0,1.0);

        glNormal3fv(normal);
        glVertex3f(1.0,0.0,-1.0);

    glEnd();
    glTranslatef(0.0, 0.0, -2.0);
    glFlush();


}
void iniciar(){
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0,1.0,1.0);

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);
    //activacion de luces y sus caracteristicas
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_color);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light_color);
    glEnable(GL_LIGHT0);

    //seleccion de material
    glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,mat_color);

    //definicion de perspectiva
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(60.0,1.0,1.0,100.0);
    
    //posicionamiento del observador
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(-0.3,-0.6,-4.0);

    //definir direccion de la luz
    glLightfv(GL_LIGHT0,GL_POSITION,light_dir);
    
}

int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(20,20);
    glutCreateWindow("Ejemplo Guia - Luces y Materiales");
    iniciar();
    glutDisplayFunc(Mostrar);
    glutMainLoop();
    return 0;
}



