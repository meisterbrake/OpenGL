//
//  quinto.cpp
//  OpenGL
//
//  Created by Fermin Osorio on 4/15/19.
//  Copyright © 2019 Fermin Osorio. All rights reserved.
//


 #define GL_SILENCE_DEPRECATION
 #include <GLUT/GLUT.h>


 void init(void){
 glClearColor(0.0, 0.0, 0.0, 0.0);
 glClear(GL_COLOR_BUFFER_BIT);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 }
 
 void myDisplay(void){
     glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
     glMatrixMode(GL_MODELVIEW);
     glBegin(GL_TRIANGLES);
     glColor3f(1.0, 0.0, 0.0);
     glVertex3f(0.0, 0.8,0.0 );
     glColor3f(0.0, 1.0, 0.0);
     glVertex3f(-0.6, -0.2, 0.0);
     glColor3f(0.0, 0.0, 1.0);
     glVertex3f(0.6, -0.2, 0.0);
 glEnd();
 glFlush();
 }
 
 int main(int argc, char * argv[]){
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(640, 480);
 glutInitWindowPosition(100, 150);
 glutCreateWindow("Configuracion del entorno OPENGL");
 glutDisplayFunc(myDisplay);
 init();
 glutMainLoop();
 }


