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

typedef PhysVector Coords;

typedef PhysVector Velocity;

class Planet {
    public:
        float mass;
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

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; i <solarsystem.size(); i++){ //dibuja un punto como planeta
        Planet &planet = solarsystem[i];
        glBegin(GL_POLYGON);
        for(float arc = 0; arc < 2*pi; arc+=0.5){
            glVertex2f(cos(arc) + planet.loc.x, sin(arc) + planet.loc.y);
        }

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

void newPlanet(float m){
    Planet planet;
    planet.loc.x = mouse_x_pos;
    planet.loc.y = mouse_y_pos;
    planet.v = stopped;
    planet.mass = m;
    solarsystem.push_back(planet);
}

void physicsLoop(int val){
    display();

    if(left_click){
        newPlanet(50.0f);
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

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Sistema Solar");
    glOrtho(0, 320.0, 240.0, 0, 0, 1);
    glutDisplayFunc(display);
    glutMouseFunc(mouseHandler);
    glutMotionFunc(mouseMotionHandler);

    physicsLoop(0);

    glutMainLoop();
    return 0;
}

