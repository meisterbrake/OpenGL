//
//  fisica.cpp
//  OpenGL
//
//  Created by Fermin Osorio on 6/10/19.
//  Copyright © 2019 Fermin Osorio. All rights reserved.
//


#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <iostream>
#include <cmath>
#include <vector>

const double pi = 3.141593;

typedef struct PhysVector{
    float x;
    float y;
};

float masa = 1.0;
float radius = 8.0;
float r,g,b, vx,vy;

typedef PhysVector Coords;

typedef PhysVector Velocity;
typedef enum {MASA50, MASA20, MASA10, TEST, ROJO, VERDE, AMARILLO, AZUL, V1, V05, V02};

class Planet {
    public:
        float mass;
        float radius;
        float r;
        float g;
        float b;
        Coords loc;
        Velocity v;
};

const Coords origin = {0,0};
const Coords stopped = {0,0};

void physicsLoop(int);
void display(void);
void mouseHandler(int, int, int, int);
void mouseMotionHandler(int, int);
void newPlanet(float);

int mouse_x_pos, mouse_y_pos;

bool left_click = false;

std::vector<Planet> solarsystem;

void onMenu(int opcion){
    switch(opcion){
        case MASA50:
            masa = 50.0;
            radius = masa / 10;
            break;
        case MASA20:
            masa = 20.0;
            radius = masa / 10;
            break;
        case MASA10:
            masa = 10.0;
            radius = masa / 10;
            break;
       
        case V1:
            vx = 0.01;
            vy = 0.01;
            break;
        case V05:
            vx = 0.05;
            vy = 0.05;
            break;
        case V02:
            vx = 0.02;
            vy = 0.02;
            break;

        case ROJO:
            r = 0.92;
            g = 0.0276;
            b = 0.0276; 
            break;
        
        case VERDE:
            r = 0.2024;
            g = 0.92;
            b = 0.4536;
            break;
        
        case AMARILLO:
            r = 0.94;
            g = 1.0;
            b = 0.1; 
            break;
        
        case AZUL:
            r = 0.037;
            g = 0.2831;
            b =  0.74; 
            break;


    }
    glutPostRedisplay();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; i <solarsystem.size(); i++){ //dibuja un punto como planeta
        Planet &planet = solarsystem[i];
       
        glPushMatrix();
        glBegin(GL_TRIANGLE_FAN);
        
        /*for(float arc = 0; arc < 2*pi; arc+=0.5){
             glColor3f(0.2024, 0.92, 0.4536); 
             
            glVertex2f(cos(arc) + planet.loc.x, sin(arc) + planet.loc.y);
        }*/

        GLfloat twicePi = 2.0f * pi;
	
		for(int i = 0; i <= 100;i++) { 
            glColor3f(planet.r, planet.g, planet.b); 
			glVertex2f(
			    planet.loc.x + (planet.radius * cos(i *  twicePi / 100)), 
			    planet.loc.y + (planet.radius * sin(i * twicePi / 100))
			);
		}
	
        glPopMatrix();
        glEnd();
        
    }

    glFlush();
    glutSwapBuffers();
}

void mouseHandler(int button, int state, int x, int y){
    mouseMotionHandler(x, y);

    if(state == GLUT_DOWN){
        if(button == GLUT_LEFT_BUTTON){
            left_click = true;
            return;
        }
    }
}

void mouseMotionHandler(int x, int y){
    mouse_x_pos = x;
    mouse_y_pos = y;
}

void newPlanet(float masa, float radio, float r, float g, float b){
    Planet planet;
    planet.loc.x = mouse_x_pos;
    planet.loc.y = mouse_y_pos;
    planet.v.x = vx;
    planet.v.y = vy; 
    planet.mass = masa;
    planet.radius = radio;
    planet.r = r;
    planet.g = g;
    planet.b = b;
    solarsystem.push_back(planet);
}

void physicsLoop(int val){
    display();

    if(left_click){
        newPlanet(masa, radius, r, g, b);
        
        left_click = false;
    }

    for(int i = 0; i < solarsystem.size(); i++){
        Planet &planet = solarsystem[i];
        for(int j = 0; j < solarsystem.size(); j++){
            if(i == j){
                continue;
            }
            const Planet &other_planet = solarsystem[j];

            float dist = sqrt((other_planet.loc.x - planet.loc.x) * (other_planet.loc.x - planet.loc.x) 
            + (other_planet.loc.y - planet.loc.y) * (other_planet.loc.y - planet.loc.y));

            if(dist < 3){
                planet.v.x = ((planet.v.x * planet.mass + other_planet.v.x * other_planet.mass) / 
                (planet.mass +other_planet.mass)); //colision inelastica

                planet.v.y = ((planet.v.y * planet.mass + other_planet.v.y * other_planet.mass) / 
                (planet.mass + other_planet.mass));

                planet.mass +=other_planet.mass;
                planet.radius +=other_planet.radius; //tamaño del radio
                solarsystem.erase(solarsystem.begin()+j); //borra el planeta que colisiona

            }else{
                //adciona el componente de aceleracion en funcion de la gravedad por coordenada
                planet.v.x += 0.001*(other_planet.mass / dist * (other_planet.loc.x - planet.loc.x));
                planet.v.y += 0.001*(other_planet.mass / dist * (other_planet.loc.y - planet.loc.y));
            }
        }
        planet.loc.x += planet.v.x; //incrementar posicion
        planet.loc.y += planet.v.y;
    }
    
    glutTimerFunc(1, physicsLoop, 0);
}



void creacionMenu(void){
    int menuMasa, menuVelocidad, menuPrincipal, menuColor;

    menuMasa = glutCreateMenu(onMenu);
    glutAddMenuEntry("50", MASA50);
    glutAddMenuEntry("20", MASA20);
    glutAddMenuEntry("10", MASA10);

    menuVelocidad = glutCreateMenu(onMenu);
    glutAddMenuEntry("Velocidad 1", V1);
    glutAddMenuEntry("Velocidad 0.5", V05);
    glutAddMenuEntry("Velocidad 0.2", V02);
    
    menuColor = glutCreateMenu(onMenu);
    glutAddMenuEntry("Verde", VERDE);
    glutAddMenuEntry("Azul", AZUL);
    glutAddMenuEntry("Rojo", ROJO);
    glutAddMenuEntry("Amarillo", AMARILLO);
    
    menuPrincipal = glutCreateMenu(onMenu);
    glutAddSubMenu("Masa", menuMasa);
    glutAddSubMenu("Color", menuColor);
    glutAddSubMenu("Velocidad", menuVelocidad);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Sistema Solar");
    glOrtho(0, 320.0, 240.0, 0, 0, 1);
    glutDisplayFunc(display);
    glutMouseFunc(mouseHandler);
    glutMotionFunc(mouseMotionHandler);

    physicsLoop(0);
    creacionMenu(); 
    glutMainLoop();
    return 0;
}

