//
//  rebote.cpp
//  OpenGL
//
//  Created by Fermin Osorio on 5/27/19.
//  Copyright © 2019 Fermin Osorio. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
GLfloat size = 3;

//definicion del modelo de una luz
GLfloat light_Ambient [4] = {0.4, 0.4, 0.4, 1.0};
GLfloat light_Diffuse [4] = {0.7, 0.7, 0.7, 1.0};
GLfloat light_Position [4] = {20.0, 15.0, 10.0, 1.0};
GLfloat light_const [4] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_lin [4] = {0.00, 0.0, 0.0, 1.0};
GLfloat light_qua [4] = {0.001, 0.0, 0.0, 1.0};

//definicion de las caracteristicas opticas del material: coeficientes de reflexion
GLfloat material [4] = {1.0, 0.2, 0.2, 1.0};
GLfloat RedMaterial [4] = {1.0, 0.0, 0.0, 1.0};
GLfloat GreenMaterial [4] = {0.0, 1.0, 0.0, 1.0};
GLfloat BlueMaterial [4] = {0.0, 0.0, 1.0, 1.0};
GLfloat WhiteMaterial [4] = {1.0, 1.0, 1.0, 1.0};

/*los valores de los materiales se van a sumar para tener una
totalidad que antes se multiplico a la luz
ambiente + difuso + especular */

GLUquadricObj *quadobj;
void luces(void){

    //cargando las ecuaciones de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_Ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_Diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_Position);

    glLightfv(GL_LIGHT0, GL_LINEAR_ATTENUATION, light_lin);
    glLightfv(GL_LIGHT0, GL_CONSTANT_ATTENUATION, light_const);
    glLightfv(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, light_qua);
}

void EjesReferencia(){

    glLineWidth(size);
    glBegin(GL_LINES);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, RedMaterial);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(20.0, 0.0, 0.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, GreenMaterial); 
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 20.0, 0.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, WhiteMaterial); 
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 20.0);
    glEnd();
}

void cilindro(){

    quadobj = gluNewQuadric();
    gluQuadricDrawStyle(quadobj, GLU_FILL);
    
    gluQuadricNormals(quadobj, GLU_SMOOTH);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(-90, 1.0, 0.0, 0.0);
    gluCylinder(quadobj,
                2, //Gldouble baseRadius,
                2, //Gldouble topRadius,
                3, // Gldouble height, 
                15, //Glint slices, 
                15); //Glint stacks );
    
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-7.0, 0.0, -27.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    gluCylinder(quadobj, 
                2, //Gldouble baseRadius,
                2, //Gldouble topRadius,
                3, //Gldouble height, 
                15, //GLint slices, 
                15); //Glint stacks);
    
    glPopMatrix();

    gluDeleteQuadric(quadobj);
}

void RenderScene(void){
    
    //Borrar frame buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    //preparar la luz
    luces();

    //prepara ejes de referencia
    EjesReferencia();

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, material);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glShadeModel(GL_FLAT);

    //prepaar un cilindro
    cilindro();

    //render de las primitivas
    glFlush();

}

int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); //note que se asigno GLUT_DEPTH itilizar uffer de profundidad
    glutInitWindowSize(800,600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("utilizando camara con opengl");
    glutDisplayFunc(RenderScene);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    //habilitando el buffer de profundidad
    glEnable(GL_DEPTH_TEST);
    //cte GL_DEPTH_TEST HABILITADO

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(15, 800/600, .1, 1000);
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

    glTranslatef(4,3,-0.5);

    glutMainLoop();
    return 0;
}



