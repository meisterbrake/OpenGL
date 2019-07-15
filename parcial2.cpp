//
//  parcial2.cpp
//  OpenGL
//
//  Created by Fermin Osorio on 7/15/19.
//  Copyright © 2019 Fermin Osorio. All rights reserved.
//


#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
GLfloat size = 3;

//definicion del modelo de una luz

//GLfloat light_color1 [] = {0.95,0.152,0.9367,1.0}; //color difuso y especular de la luz
//GLfloat light_color2 [] = {0.20,0.14,0.66,1.0}; //color difuso y especular de la luz
//GLfloat light_color [] = {0.3799,0.0385,0.77,1.0}; //color difuso y especular de la luz
//GLfloat light_ambient [] = {0.0,0.0,0.0,1.0}; //color ambiental de la luz 
//GLfloat light_dir [] = {0.0,1.0,0.0,0.0}; //valor de la direccion de la luz

//definicion del modelo de una luz
GLfloat light_Ambient [4] = {0.3799, 0.0385, 0.77,1.0};
GLfloat light_Diffuse [4] = {0.7, 0.7, 0.7, 1.0};
GLfloat light_Position [4] = {20.0, 15.0, 10.0, 1.0};
GLfloat light_const [4] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_lin [4] = {0.00, 0.0, 0.0, 1.0};
GLfloat light_qua [4] = {0.001, 0.0, 0.0, 1.0};


GLfloat light_Ambient1 [4] = {1.0, 0.069, 0.02, 1.0};
GLfloat light_Diffuse1 [4] = {0.7, 0.7, 0.7, 1.0};
GLfloat light_Position1 [4] = {20.0, 15.0, 10.0, 1.0};
GLfloat light_const1 [4] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_lin1 [4] = {0.00, 0.0, 0.0, 1.0};
GLfloat light_qua1 [4] = {0.001, 0.0, 0.0, 1.0};





//Menu
int iFondo = 0;
int iDibujo = 3;
float r,r1,g,g1,b,b1,angulo=1.0;
typedef enum {FONDO1, FONDO2, FONDO3, DIBUJO1, DIBUJO2, DIBUJO3, ROTADER, ROTAIZQ}
opcionesMenu;

void idle()
{
    angulo += 0.9f; //velocidad
    glutPostRedisplay();
}

void idle2()
{
    angulo -= 0.9f; //velocidad
    glutPostRedisplay();
}


void onMenu(int opcion){
    switch(opcion){
        case FONDO1:
           r1=0.2;
           g1=0.2;
           b1=0.2;
            break;
        case FONDO2:
            r1=0.0806;
            g1=0.2334;
            b1=0.62;
            break;
        case FONDO3:
            r1=0.0088;
            g1=0.44;
            b1=0.3538;
            break;
        case DIBUJO1:
            iDibujo = 3;
            r=0.3799;
            g=0.0385;
            b=0.77;
            glEnable(GL_LIGHT0);
            glDisable(GL_LIGHT1);
            glDisable(GL_LIGHT2);
            break;
        case DIBUJO2:
            iDibujo = 4;
            r=1.0;
            g=0.069;
            b=0.02;
            glEnable(GL_LIGHT1);
            glDisable(GL_LIGHT0);
            glDisable(GL_LIGHT2);
            break;
        case ROTADER:
            glutIdleFunc(idle);
            //glRotatef(45, 0, 1,0);
            break;

        case ROTAIZQ:
            glutIdleFunc(idle2);
            //glRotatef(45, 0, -1,0);
            break;

    }
    glutPostRedisplay();
}

void creacionMenu(void){
    int menuFondo, menuDibujo, menuPrincipal, menuRotacion;

    menuFondo = glutCreateMenu(onMenu);
    glutAddMenuEntry("Negro", FONDO1);
    glutAddMenuEntry("Azul oscuro", FONDO2);
    glutAddMenuEntry("Verde oscuro", FONDO3);
    

    menuDibujo = glutCreateMenu(onMenu);
    glutAddMenuEntry("Morado", DIBUJO1);
    glutAddMenuEntry("Rosado", DIBUJO2);
    //glutAddMenuEntry("Azul claro", DIBUJO3);

    menuRotacion = glutCreateMenu(onMenu);
    glutAddMenuEntry("Derecha 45", ROTADER);
    glutAddMenuEntry("Izquierda 45", ROTAIZQ);
    

    menuPrincipal = glutCreateMenu(onMenu);
    glutAddSubMenu("Color de fondo", menuFondo);
    glutAddSubMenu("Color de dibujo", menuDibujo);
    glutAddSubMenu("Rotacion", menuRotacion);

    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


GLUquadricObj *quadobj;
void luces(void){

    //cargando las ecuaciones de luz

    //cargando las ecuaciones de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_Ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_Diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_Position);

    glLightfv(GL_LIGHT0, GL_LINEAR_ATTENUATION, light_lin);
    glLightfv(GL_LIGHT0, GL_CONSTANT_ATTENUATION, light_const);
    glLightfv(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, light_qua);

    //glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_Ambient1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_Diffuse1);
    glLightfv(GL_LIGHT1, GL_POSITION, light_Position1);

    glLightfv(GL_LIGHT1, GL_LINEAR_ATTENUATION, light_lin1);
    glLightfv(GL_LIGHT1, GL_CONSTANT_ATTENUATION, light_const1);
    glLightfv(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, light_qua1);


}

void conos(){

     glClearColor(r1, g1, b1, 1.0f);

    quadobj = gluNewQuadric();
    gluQuadricDrawStyle(quadobj, GLU_FILL);
    
    gluQuadricNormals(quadobj, GLU_SMOOTH);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-4.0, -5.0, 0.0);
    //glRotatef(angulo, 0.0, 0.0, 1.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(2,5,7,3);
    glColor3f(r,g,b);
    
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-8.0, -5.0, -15.0);
    //glRotatef(angulo, 0.0, 0.0, 1.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(2,5,7,3);
    glColor3f(r,g,b);
    
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-9.0, -4.0, -25.0);
    //glRotatef(angulo, 0.0, 0.0, 1.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(2,5,7,3);
    glColor3f(r,g,b);
    glPopMatrix();

    gluDeleteQuadric(quadobj);
}

void RenderScene(void){
    
    //Borrar frame buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    //preparar la luz
    luces();

    //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, material);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glShadeModel(GL_FLAT);

    //preparar los conos
    conos();

    //render de las primitivas
    glFlush();

}

int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); //note que se asigno GLUT_DEPTH itilizar uffer de profundidad
    glutInitWindowSize(800,600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Semestral");
    glutDisplayFunc(RenderScene);

    //habilitando el buffer de profundidad
    glEnable(GL_DEPTH_TEST);
    //cte GL_DEPTH_TEST HABILITADO

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(20, 800/600, .1, 1000);
    //fov:angulo de apertura de la camara=> 15 grados
    //relacion de aspecto 3:4, 16:9 =>800/600
    //plano de visita cercano mayor de 0 => .1
    //plano de visita lejano => 1000

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(20, 10, 45, 4, 2, -5, 0, 1, 0);

    //camara tiene un ojo, posicion de lente y giro
    // ejex, ejey, ejez: especifica la posicion de la lente de la camara u ojo
    // centerx, centery, centerz: especifica la posicion del punto al que se mira
    //upx, upy, upz: especifica el vector de orientacion de la camara
    creacionMenu(); 
    glTranslatef(4,3,-0.5);

    glutMainLoop();
    return 0;
}



