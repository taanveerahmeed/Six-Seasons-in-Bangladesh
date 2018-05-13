/*------------------------------------------------------------*
* @package Six Seasons in Bangladesh						  *
* @version 1.0.0                                              *
* @author Rhythm Shahriar                                     *
* @author Tanvir Ahmed                                        *
* @author H.M. Maruf                                          *
*-------------------------------------------------------------*/

/*--------------------------------------------------------------
|	Six Seasons in Bangladesh is an OpenGL computer graphics   |
|	project using the GLUT library. It's an animation project  |
|	where all the seasons in Bangladesh are arranged as an     |
|	animation video with some keyboard and mouse event.        |
---------------------------------------------------------------*/

//project major libraries
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#include "global.h"
#include "movement.h"
#include "elements.h"
#include "keyevents.h"


float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -30.0;


//iniatilize the component
void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_SMOOTH); // Enable Smooth Shading
	glClearDepth(1.0f);		// DepthBuffer Setup
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing


}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0f, (GLfloat)w / (GLfloat)h, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}




