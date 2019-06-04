//
//  rompecabeza.cpp
//  OpenGL
//
//  Created by Fermin Osorio on 6/3/19.
//  Copyright © 2019 Fermin Osorio. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

float tamano = 0.25;
float posInicial[2] = {0.50, 0.50};
float pos[7][3] = {
      {posInicial[0], posInicial[1], 0.0},
      {posInicial[0]-(tamano*4), posInicial[1], 0.0},
      {posInicial[0]-(tamano*4), posInicial[1]-(tamano*3), 0.0},
      {posInicial[0]-(tamano*6), posInicial[1]-(tamano*6), 0.0},
      {posInicial[0]-(tamano*4), posInicial[1]-(tamano*9), 0.0},
      {posInicial[0], posInicial[1]-(tamano*13), 0.0},
      {posInicial[0]-(tamano*6), posInicial[1]-(tamano*15), 0.0},

};
float var[2] = {pos[0][0],pos[0][1]} ;
typedef enum {op1, op2, op3, op4, op5, op6, op7} opcionesMenu;
int item = 0;

void Mostrar(){
    glClear(GL_COLOR_BUFFER_BIT);

    //cuadro - rojo
    glPushMatrix();
        //traslacion
        glTranslatef(pos[0][0], pos[0][1], pos[0][2]);

        glBegin(GL_POLYGON);
        //color
        glColor3f(0.92, 0.0276, 0.0276); 
            glVertex3f(-1*tamano, tamano, 0.0); //izquieda arriba
            glVertex3f(-1*tamano, -1*tamano, 0.0); //izquierda abajo
            glVertex3f(tamano, -1*tamano, 0.0); //derecha abajo
            glVertex3f(tamano, tamano, 0.0);  //derecha arriba
        glEnd();
    glPopMatrix();

    //cuadro - rosado
    glPushMatrix();
        //traslacion
        glTranslatef(pos[1][0], pos[1][1], pos[1][2]);

        glBegin(GL_POLYGON);
        //color
        glColor3f(0.91, 0.0455, 0.8956); 
            glVertex3f(-1*tamano, tamano, 0.0); //izquieda arriba
            glVertex3f(-1*tamano, -1*tamano, 0.0); //izquierda abajo
            glVertex3f(tamano, -1*tamano, 0.0); //derecha abajo
            glVertex3f(tamano, tamano, 0.0);  //derecha arriba
        glEnd();
    glPopMatrix();

    //rectangulo - azul
    glPushMatrix();
        //traslacion
        glTranslatef(pos[2][0], pos[2][1], pos[2][2]);

        glBegin(GL_POLYGON);
        //color
        glColor3f(0.037, 0.2831, 0.74); 
            glVertex3f(-1*tamano, tamano, 0.0); //izquieda arriba
            glVertex3f(-1*tamano, -1*tamano, 0.0); //izquierda abajo
            glVertex3f(tamano*3, -1*tamano, 0.0); //derecha abajo
            glVertex3f(tamano*3, tamano, 0.0);  //derecha arriba
        glEnd();
    glPopMatrix();

    //rectangulo - naranja
    glPushMatrix();
        //traslacion
        glTranslatef(pos[3][0], pos[3][1], pos[3][2]);

        glBegin(GL_POLYGON);
        //color
        glColor3f(0.86, 0.3429, 0.1548); 
            glVertex3f(-1*tamano, tamano, 0.0); //izquieda arriba
            glVertex3f(-1*tamano, -1*tamano, 0.0); //izquierda abajo
            glVertex3f(tamano*7, -1*tamano, 0.0); //derecha abajo
            glVertex3f(tamano*7, tamano, 0.0);  //derecha arriba
        glEnd();
    glPopMatrix();

    //rectangulo - morado
    glPushMatrix();
        //traslacion
        glTranslatef(pos[4][0], pos[4][1], pos[4][2]);

        glBegin(GL_POLYGON);
        //color
        glColor3f(0.4699, 0.0897, 0.69); 
            glVertex3f(-1*tamano, tamano, 0.0); //izquieda arriba
            glVertex3f(-1*tamano, -1*tamano*1.5, 0.0); //izquierda abajo
            glVertex3f(tamano*3, -1*tamano*1.5, 0.0); //derecha abajo
            glVertex3f(tamano*3, tamano, 0.0);  //derecha arriba
        glEnd();
    glPopMatrix();

    //poligono - gris
    glPushMatrix();
        //traslacion
        glTranslatef(pos[5][0], pos[5][1], pos[5][2]);

        glBegin(GL_POLYGON);
        //color
        glColor3f(0.82, 0.82, 0.82); 
            glVertex3f(-1*tamano, -1*tamano*1.5, 0.0); //izquieda arriba
            glVertex3f(-1*tamano*3, -1*tamano*1.5, 0.0); //izquierda abajo
            glVertex3f(-1*tamano*3, -1*tamano*2, 0.0); //izquierda abajo
            glVertex3f(tamano, -1*tamano*2, 0.0); //derecha abajo
            glVertex3f(tamano, tamano, 0.0); //derecha abajo
            glVertex3f(-1*tamano, tamano, 0.0); //derecha abajo
        glEnd();
    glPopMatrix();

    //poligono - amarillo/verdoso
    glPushMatrix();
        //traslacion
        glTranslatef(pos[6][0], pos[6][1], pos[6][2]);

        glBegin(GL_POLYGON);
        //color
        glColor3f(0.94, 1, 0.1); 
            glVertex3f(tamano, -1*tamano*1.5, 0.0); //izquieda arriba
            glVertex3f(tamano*3, -1*tamano*1.5, 0.0); //izquierda abajo
            glVertex3f(tamano*3, -1*tamano*2, 0.0); //izquierda abajo
            glVertex3f(-1*tamano, -1*tamano*2, 0.0); //derecha abajo
            glVertex3f(-1*tamano, tamano, 0.0); //derecha abajo
            glVertex3f(tamano, tamano, 0.0); //derecha abajo
        glEnd();
    glPopMatrix();

    


    glFlush();
    
}

void onMenu(int opcion){
    switch(opcion){
        case op1:
            var[0] = pos[0][0];
            var[1] = pos[0][1];
            item=0;
        break;
        case op2:
            var[0] = pos[1][0];
            var[1] = pos[1][1];
            item=1;
        break;
        case op3:
            var[0] = pos[2][0];
            var[1] = pos[2][1];
            item=2;
        break;
        case op4:
            var[0] = pos[3][0];
            var[1] = pos[3][1];
            item=3;
        break;
        case op5:
            var[0] = pos[4][0];
            var[1] = pos[4][1];
            item=4;
        break;
        case op6:
            var[0] = pos[5][0];
            var[1] = pos[5][1];
            item=5;
        break;
        case op7:
            var[0] = pos[6][0];
            var[1] = pos[6][1];
            item=6;
        break;
        
        default:
        break;

    }
    glutPostRedisplay();
}

void keyboard(unsigned char button, int x, int y){
    switch (button) {
        case 'a': 
            var[0] -= tamano;
            pos[item][0] = var[0];
        break;
            
        case 'd':
            var[0] += tamano;
            pos[item][0] = var[0];
        break;

        case 's':
            var[1] -= tamano;
            pos[item][1] = var[1];
        break;
        case 'w':
            var[1] += tamano;
            pos[item][1] = var[1];
        break;
            
        default:
            break;
    }
      glutPostRedisplay();
}

void creacionMenu(void){

    int menuPrincipal;

    menuPrincipal = glutCreateMenu(onMenu);
    glutAddMenuEntry("Rojo", op1);
    glutAddMenuEntry("Rosado", op2);
    glutAddMenuEntry("Azul", op3);
    glutAddMenuEntry("Naranja", op4);
    glutAddMenuEntry("Morado", op5);
    glutAddMenuEntry("Gris", op6);
    glutAddMenuEntry("Amarillo", op7);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void iniciar(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glViewport(0, 0, 150, 100);
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800, 1000);
    //glutInitWindowPosition(0, 0);
    glutCreateWindow("Puzzle");
    iniciar();
    glutDisplayFunc(Mostrar);
    creacionMenu(); 
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}



