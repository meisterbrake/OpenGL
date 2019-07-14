//
//  fractales.cpp
//  lab2
//
//  Created by Fermin Osorio on 7/12/19.
//  Copyright © 2019 Fermin Osorio. All rights reserved.
//

#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <math.h>
#include <stdlib.h>

/*Establece el tamaño inicial de la ventana de visualización*/
GLsizei winWidth=600,winHeight=600;

/*Establece los límites de las coordenadas del plan complejo*/
GLfloat xComplexMin=-0.25, xComplexMax=1.25;
GLfloat yComplexMin=-0.75, yComplexMax=0.75;

struct complexNum{
    GLfloat x,y;
};

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glPointSize(2);
}

void plotPoint(complexNum z)
{
    glBegin(GL_POINTS);
    glVertex2f(z.x, z.y);
    glEnd();
}

void solveQuadraticEq(complexNum lambda, complexNum * z)
{
    GLfloat lambdaMagSq, discrMag;
    complexNum discr = {0.0, 0.0};
    static complexNum fourOverLambda = {0.0, 0.0};
    static GLboolean firstPoint = true;
    
    if (firstPoint)
    {
        /*calculo el número complejo 4 / lambda */
        lambdaMagSq = lambda.x * lambda.x + lambda.y * lambda.y;
        fourOverLambda.x = 4.0 * lambda.x / lambdaMagSq;
        fourOverLambda.y = -4.0 * lambda.y/lambdaMagSq;
        firstPoint=false;
    }
    
    discr.x= 1.0 - (z->x * fourOverLambda.x - z->y * fourOverLambda.y);
    discr.y= z->x * fourOverLambda.y + z->y * fourOverLambda.x;
    discrMag = sqrt(discr.x * discr.x + discr.y * discr.y);
    
    /*actualiza z, evitando la división con negativos*/
    
    if(discrMag + discr.x < 0)
    {
        z->x=0;
    }
    
    else
    {
        z->x = sqrt((discrMag+discr.x)/2.0);
    }
    
    if(discrMag - discr.x < 0)
    {
        z->y = 0;
    }
    
    else
    {
        z->y = 0.5 * sqrt((discrMag - discr.x)/2.0);
    }
    
    /*trabajo con la mitad de los puntos que emplean la raíz negativa en el cuadrante 3*/
    
    if(rand()< RAND_MAX / 2)
    {
        z->x = -z->x;
        z->y = -z->y;
    }
    
    /*aqui trabajamos con los puntos en el quadrante 2 ó 4 donde la parte imaginaria del discriminante es negativa y se invierte el signo de x*/
    
    if(discr.y < 0)
       {
           z->x = -z->x;
       }
       z->x = 0.5 * (1-z->x);
       }
       
       
       void selfSqTransf(complexNum lambda,complexNum z,GLint numPoints)
    {
        GLint k;
        for(k = 0; k < 10; k++)
        {
            solveQuadraticEq(lambda,&z);
        }
        for(k = 0; k < numPoints; k++)    {
            solveQuadraticEq(lambda,&z);
            plotPoint(z);}
    }
          void displayFcn(void)
            {
                GLint numPoints = 10000;
                complexNum lambda = {2.0, 1.0};
                complexNum z0 = {1.5, 0.4};
                
                glClear(GL_COLOR_BUFFER_BIT);
                glColor3f(1.0, 0.0, 1.0);
                
                selfSqTransf(lambda, z0, numPoints);
                glFlush();
                
            }
            
            void winReshapeFcn(GLint newWidth, GLint newHeight)
            {
                glViewport(0, 0, newHeight, newHeight);
                
                glMatrixMode(GL_PROJECTION);
                glLoadIdentity();
                
                gluOrtho2D(xComplexMin, xComplexMax, yComplexMin, yComplexMax);
                glClear(GL_COLOR_BUFFER_BIT);
            }
            
    int main(int argc,char* argv[])
        {
                glutInit(&argc,argv);
                glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                glutInitWindowPosition(50,50);
                glutInitWindowSize(winWidth,winHeight);
                glutCreateWindow("Fractales");
                
                init();
                glutDisplayFunc(displayFcn);
                glutReshapeFunc(winReshapeFcn);
                
                glutMainLoop();
        }
