#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//#include <X11/Xlib.h>
//#define RAND_MAX 5
//unsigned int sleep(unsigned int seconds);

float x0=-1.0, y0=60.0;
float x1=5.0,y1=60.0;
float x2=1.0,y2=60.0;
float x3=-1.0,y3=60.0;
float x4=-1.0,y4=60.0;
int r;


int cont=0;
int limit=0;
float x5=25.0,y5=60.0;
float x6=25.0,y6=60.0;


typedef enum {FIGURA0,FIGURA1,FIGURA2,FIGURA3,FIGURA4,FIGURA5,FIGURA6}
opcionesMenu;

int figura=0;
int order[7]; 
void generateRandomOrder(){
  for(int i=0;i<=0;i++){
    order[i]=rand()%6;

  }
}
void init(void){
   glClearColor(0.0,0.0,0.0,0.0);
   //glShadeModel(GL_ROUND_NV);

}
void mover(){
  
      if(y3>=-5){
        figura=3;
        y3-=0.2;
        if(y3<-5){
          cont++;
        }
      }
      if(cont==1 && y6>-5){
        y6-=0.2;
        figura=6;
        if(y6<-5){
          cont++;
        }
      }
      if(cont==2 && y2>-5){
        y2-=0.2;
        figura=2;
        if(y2<-5){
          cont++;
        }
      }
      if(cont==4 && y5>5){
        y5-=0.2;
        figura=5;
        if(y5<5){
          cont++;
        }
      }
      if(cont==5 && y0>5){
        y0-=0.2;
        figura=0;
        if(y0<5){
          cont++;
        }
      }
      if(cont==6 && y4>5){
        y4-=0.2;
        figura=4;
        if(y4<5){
          cont++;
        }
      }
      if(cont==3 && y1>1){
        y1-=0.2;
        figura=1;
        if(y1<1){
          cont++;
        }
      }

 glutPostRedisplay();
        //sleep(1);
}
void display(){
    
    
    

    glClear(GL_COLOR_BUFFER_BIT);
    
    //figura0
    
    //glutPostRedisplay();
    glPushMatrix();
    glColor3f(0.92, 0.0276, 0.0276); 
    glTranslatef(x0,y0,1.0);
    glRectf(-2.0,-2.0,2.0,2.0);
    glPopMatrix();
   // glutSwapBuffers();
      
   


    //figura1
    glPushMatrix();
    glColor3f(0.91, 0.0455, 0.8956); 
    glTranslatef(x1,y1,1.0);
    glRectf(-8.0,-2.0,8.0,2.0);
    glPopMatrix();
    

    //figura2  
    glPushMatrix();
    glColor3f(0.037, 0.2831, 0.74); 
    glTranslatef(x2,y2,1.0);
    glRectf(-4.0,-4.0,4.0,4.0);
    glPopMatrix();
    

    //figura3
    glPushMatrix();
    glColor3f(0.86, 0.3429, 0.1548); 
    glTranslatef(x3,y3,1.0);
    glRectf(-2.0,-4.0,2.0,4.0);
    glPopMatrix();
    

    glPushMatrix();
    glTranslatef(x3+2,y3-6,1.0);
    glRectf(-4.0,-2.0,4.0,2.0);
    glPopMatrix();
    


    //figura4
    glPushMatrix();
    glColor3f(0.4699, 0.0897, 0.69); 
    glTranslatef(x4,y4,1.0);
    glRectf(-2.0,-2.0,2.0,2.0);
    glPopMatrix();

    //figura5
    glPushMatrix();
    glColor3f(0.82, 0.82, 0.82); 
    glTranslatef(x5,y5,1.0);
    glRectf(-4.0,-2.0,4.0,2.0);
    glPopMatrix();


    //figura6
    glPushMatrix();
    glColor3f(0.94, 1, 0.1);
    glTranslatef(x6,y6,1.0);
    glRectf(-2.0,-4.0,2.0,4.0);
    glPopMatrix();
    

    glPushMatrix();
    glTranslatef(x6-2,y6-6,1.0);
    glRectf(-4.0,-2.0,4.0,2.0);
    glPopMatrix();


glutSwapBuffers();




       
    

    
}


void reshape(int w, int h){
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0,50.0,-50.0,50.0,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    
}
void keyboard(unsigned char button,int x,int y){
    switch (button)
    {
        case 'w':
           
           switch (figura)
           {
              case 0:
                y0++;
            
                //printf("%f",y0);
                break;
             
              case 1:
                y1++;
                break;
             
              case 2:
                y2++;
                break;
            
              case 3:
                y3++;
                break;
            
              case 4:
                y4++;
                break;
           
              case 5:
                y5++;
                break;
              
              case 6:
                y6++;
                break;
              default:
              break;
           }
              
            
            break;
         case 's':
           switch (figura)
           {
              case 0:
                y0--;
                break;
             
              case 1:
                y1--;
                break;
             
              case 2:
                y2--;
                break;
            
              case 3:
                y3--;
                break;
            
              case 4:
                y4--;
                break;
           
              case 5:
                y5--;
                break;
              
              case 6:
                y6--;
                break;
              
              default:
              break;
           }  
            
            break;
         case 'a':
           switch (figura)
           {
              case 0:
                x0--;
                break;
             
              case 1:
                x1--;
                break;
             
              case 2:
                x2--;
                break;
            
              case 3:
                x3--;
                break;
            
              case 4:
                x4--;
                break;
           
              case 5:
                x5--;
                break;
              
              case 6:
                x6--;
                break;
              
              default:
              break;
           }
              
            
            break;

         case 'd':
           switch (figura)
           {
              case 0:
                x0++;
                break;
             
              case 1:
                x1++;
                break;
             
              case 2:
                x2++;
                break;
            
              case 3:
                x3++;
                break;
            
              case 4:
                x4++;
                break;
           
              case 5:
                x5++;
                break;

              case 6:
                x6++;
                break;
              
              default:
              break;
           }
              
            
            break;
        
        case 'q':

         glutIdleFunc(mover);
          break;
          

        
        default:
            break;
    }

     glutPostRedisplay();
}

void onMenu(int opcion){
    switch(opcion){
        case FIGURA0:
            figura=0;
            break;
        case FIGURA1: 
            figura=1;
            break;
        case FIGURA2: 
            figura=2;
            break;
        case FIGURA3:
            figura=3;
            break;
        case FIGURA4:
            figura=4;
            break;
        case FIGURA5:
            figura=5;
            break;

        case FIGURA6:
            figura=6;
            break;

        default:
            break;
    }

    glutPostRedisplay();
}


void creacionMenu(void){
    int selecFic,menuPrincipal;

    selecFic = glutCreateMenu(onMenu);
    glutAddMenuEntry("Figura roja",FIGURA0);
    glutAddMenuEntry("Figura verde",FIGURA1);
    glutAddMenuEntry("Figura azul",FIGURA2);
    glutAddMenuEntry("Figura amarilla",FIGURA3);
    glutAddMenuEntry("Figura blanca",FIGURA4);
    glutAddMenuEntry("Figura morada",FIGURA5);
    glutAddMenuEntry("Figura celeste",FIGURA6);
    menuPrincipal=glutCreateMenu(onMenu);
    glutAddSubMenu("Seleccion de Figura", selecFic);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

}

int main(int argc, char* argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    srand(time(0)); 
    creacionMenu();
    glutMainLoop();
    
    return 0;
}


