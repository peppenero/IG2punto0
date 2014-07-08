#include <iostream>
#include <glm.h>
#include <GL/glut.h>
#include <fstream>
#include "Camera.h"
#include "LettoreMatrice.h"
#include <cmath>
#include <string>
#include <istream>

using namespace std;
//Lights settings
GLfloat light_ambient[]= { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat light_diffuse[]= { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat light_specular[]= { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat light_position[]= { 100.0f, 0.0f, -10.0f, 1.0f };

//Materials settings
GLfloat mat_ambient[]= { 0.5f, 0.5f, 0.0f, 0.0f };
GLfloat mat_diffuse[]= { 0.5f, 0.5f, 0.0f, 0.0f };
GLfloat mat_specular[]= { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat mat_shininess[]= { 1.0f };

float fraction=0.3, xrot = 0, yrot = 0;
float lastx,lasty;

Camera camera;

GLMmodel* gun;




void init(void)
{
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);
	/*glEnable(GL_LIGHTING);
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glLightfv (GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv (GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, light_specular);
	glLightfv (GL_LIGHT1, GL_POSITION, light_position);
    glEnable (GL_LIGHT1);*/

	    //Materials initialization and activation
	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_specular);
	glMaterialfv (GL_FRONT, GL_POSITION, mat_shininess);
	glShadeModel (GL_SMOOTH);
	camera.setPosition(89.55,100.0,100.0,100.0);
}

void display(void)
{

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear (GL_COLOR_BUFFER_BIT);
	gluLookAt(camera.getXpos(), camera.getYpos(), camera.getZpos(), camera.getXpos()+camera.getDirectionX(),camera.getYpos()+camera.getDirectionY(), 		camera.getZpos()+camera.getDirectionZ(),0.0,1.0,0.0);
	
	char** matrice;
	LettoreMatrice l;
	matrice=l.leggiMatrice();
	for(int i=0;i<l.getRiga();i++){
		glPushMatrix();
		for(int j=0;j<l.getColonna();j++)
		{
			switch(matrice[i][j])
			{
			case '0':
				glTranslatef(5,0,0);
				break;
			case '1':
				glutWireCube(5);
				glTranslatef(5,0,0);
				break;
			default :
				break;
			}
			
		}
		glPopMatrix();
		glTranslatef(0.0,0.0,5.0);
		
	}
      
	
	
	glutSwapBuffers();
}
void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0f,500.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char c,int x,int y){
	switch(c){
	case'w':
		{
		camera.setXpos(camera.getXpos()+(camera.getDirectionX()*fraction));	//cout<<"\nxpos"<<camera.getXpos()<<" XDIR "<<camera.getDirectionX();
		//camera.setYpos(camera.getYpos()+(camera.getDirectionY()*fraction));	cout<<" ypos"<<camera.getAngleY();
		camera.setZpos(camera.getZpos()+(camera.getDirectionZ()*fraction));	//cout<<" zpos"<<camera.getZpos();		
		glutPostRedisplay();}
		break;
	case's':
		camera.setXpos(camera.getXpos()-(camera.getDirectionX()*fraction));
		//camera.setYpos(camera.getYpos()-(camera.getDirectionY()*fraction));
		camera.setZpos(camera.getZpos()-(camera.getDirectionZ()*fraction));
		glutPostRedisplay();
		break;
	case'a':
		camera.setXpos(camera.getXpos()+(camera.getDirectionZ()*fraction));
		camera.setZpos(camera.getZpos()-(camera.getDirectionX()*fraction));
		glutPostRedisplay();
		break;
	case'd':
		camera.setXpos(camera.getXpos()-(camera.getDirectionZ()*fraction));
		camera.setZpos(camera.getZpos()+(camera.getDirectionX()*fraction));
		glutPostRedisplay();
		break;
	}

}

void mouse(int x,int y)
{

	if((y-lasty)>0)
	 {
		camera.setAngleX(camera.getAngleX()-0.05);
		camera.setDirectionY(sin(camera.getAngleX()));
		//camera.setDirectionZ(-cos(camera.getAngleX()));
		glutPostRedisplay();
	 }

	if((y-lasty)<0)
	 {
		camera.setAngleX(camera.getAngleX()+0.05);
		camera.setDirectionY(sin(camera.getAngleX()));
		//camera.setDirectionZ(-cos(camera.getAngleX()));
		glutPostRedisplay();
		
	 }
	if((x-lastx)>0)
	{	
		camera.setAngleY(camera.getAngleY()+0.05);
		camera.setDirectionX(sin(camera.getAngleY()));
		camera.setDirectionZ(-cos(camera.getAngleY()));
		glutPostRedisplay();
	}

	if((x-lastx)<0)
	{
		camera.setAngleY(camera.getAngleY()-0.05);
		camera.setDirectionX(sin(camera.getAngleY()));
		camera.setDirectionZ(-cos(camera.getAngleY()));
		glutPostRedisplay();
		
	}

	lastx=x;
	lasty=y;
		
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (800, 800);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init();
	glutFullScreen();
	glutDisplayFunc(display);	
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutPassiveMotionFunc(mouse);
	glutSetCursor(GLUT_CURSOR_NONE);
	glutMainLoop();
	return 0;
}
