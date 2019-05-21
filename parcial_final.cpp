//
//  UNIVERSIDAD TECNOLOGICA DE PANAMA
//  FACULTAD DE INGENIERIA DE SISTEMAS COMPUTACIONALES
//
//  Created by Fermin Osorio & Jahiro Hernández on 5/21/19.
//  Copyright © 2019. All rights reserved.
//


#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

int iFondo = 0;
int iDibujo = 3;
GLfloat light_color1 [] = {0.12,0.50,0.26,1.0}; //color difuso y especular de la luz
GLfloat light_color2 [] = {0.20,0.14,0.66,1.0}; //color difuso y especular de la luz
GLfloat light_color [] = {1.0,1.0,1.0,1.0}; //color difuso y especular de la luz
GLfloat light_ambient [] = {0.0,0.0,0.0,1.0}; //color ambiental de la luz 
GLfloat light_dir [] = {0.0,1.0,0.0,0.0}; //valor de la direccion de la luz


typedef enum {FONDO1, FONDO2, FONDO3, DIBUJO1, DIBUJO2, DIBUJO3, ROTADER, ROTAIZQ}
opcionesMenu;

void onMenu(int opcion){
    switch(opcion){
        case FONDO1:
            iFondo = 0;
            break;
        case FONDO2:
            iFondo = 1;
            break;
        case FONDO3:
            iFondo = 2;
            break;
        case DIBUJO1:
            iDibujo = 3;
            glEnable(GL_LIGHT0);
            glDisable(GL_LIGHT1);
            glDisable(GL_LIGHT2);
            break;
        case DIBUJO2:
            iDibujo = 4;
            glEnable(GL_LIGHT1);
            glDisable(GL_LIGHT0);
            glDisable(GL_LIGHT2);
            break;
        case DIBUJO3:
            iDibujo = 5;
            glEnable(GL_LIGHT2);
            glDisable(GL_LIGHT0);
            glDisable(GL_LIGHT1);
            
            break;
        case ROTADER:
             glRotatef(45, 0, 1,0);
             break;
        case ROTAIZQ:
             glRotatef(45, 0, -1,0);
             break;

    }
    glutPostRedisplay();
}

void creacionMenu(void){
    int menuFondo, menuDibujo, menuPrincipal, menuRotacion;

    menuFondo = glutCreateMenu(onMenu);
    glutAddMenuEntry("Negro", FONDO1);
    glutAddMenuEntry("Verde oscuro", FONDO2);
    glutAddMenuEntry("Azul oscuro", FONDO3);

    menuDibujo = glutCreateMenu(onMenu);
    glutAddMenuEntry("Blanco", DIBUJO1);
    glutAddMenuEntry("Verde claro", DIBUJO2);
    glutAddMenuEntry("Azul claro", DIBUJO3);

    menuRotacion = glutCreateMenu(onMenu);
    glutAddMenuEntry("Derecha 45", ROTADER);
    glutAddMenuEntry("Izquierda 45", ROTAIZQ);

    menuPrincipal = glutCreateMenu(onMenu);
    glutAddSubMenu("Color de fondo", menuFondo);
    glutAddSubMenu("Color de dibujo", menuDibujo);
    glutAddSubMenu("Rotacion", menuRotacion);

    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void initgl(){

    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);
    //activacion de luces y sus caracteristicas
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_color);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light_color);
    glEnable(GL_LIGHT0);
    
    glLightfv(GL_LIGHT1,GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,light_color1);
    glLightfv(GL_LIGHT1,GL_SPECULAR,light_color1);
    //glEnable(GL_LIGHT1);

    glLightfv(GL_LIGHT2,GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT2,GL_DIFFUSE,light_color2);
    glLightfv(GL_LIGHT2,GL_SPECULAR,light_color2);
    //glEnable(GL_LIGHT2);

    //definir direccion de la luz
    glLightfv(GL_LIGHT0,GL_POSITION,light_dir);
    glLightfv(GL_LIGHT1,GL_POSITION,light_dir);
    glLightfv(GL_LIGHT2,GL_POSITION,light_dir);
    
}
void display(void){
    float colores[6][3] = {
        { 0.00f, 0.00f, 0.00f}, //0 - negro
        { 0.06f, 0.25f, 0.13f}, //1 - verde oscuro
        { 0.10f, 0.07f, 0.33f}, //2 - azul oscuro
        { 1.00f, 1.00f, 1.00f}, //3 - blanco
        { 0.12f, 0.50f, 0.26f}, //4 - verde claro
        { 0.20f, 0.14f, 0.66f}, //5 - azul claro
    
    };
    
    glClearColor(colores[iFondo][0], colores[iFondo][1], colores [iFondo][2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(colores[iDibujo][0], colores[iDibujo][1], colores [iDibujo][2]);
    glutSolidTeapot(0.5); //objeto solido
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Parcial 1");
    initgl();
    glutDisplayFunc(display);

    creacionMenu(); 
    
    glutMainLoop();
}