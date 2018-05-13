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

#include <math.h>

#define PI 3.1416
#define DEG2RAD 3.14159/180.0//degree to radiant

//this will convert the color to float value
void rgb(float r, float g, float b) {
	float color = 255;
	glColor3f(r / color, g / color, b / color);
}

//generate color
void etColor(float r, float g, float b) {
	rgb(r, g, b);
}


//circle
void circle(GLfloat x, GLfloat y, GLfloat radius) {//takes x and y axix(center) and radious
	int i;
	int triangleAmount = 20; //used to draw circle
		
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	//glColor3f(0.99, 0.72, 0.07);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle

	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}
	glEnd();
}

//house big
void houseBig(float x = 0, float y = 0, float sf = 1, int c = 1, float color[10][3] = NULL) {
	//roof shade
	if(c == 1)	etColor(color[0][0], color[0][1], color[0][2]);
	else etColor(color[1][0], color[1][1], color[1][2]);
		//rgb(125, 61, 17);

	glBegin(GL_POLYGON);

	glVertex2f((2 + x) * sf, (3 + y) * sf);
	glVertex2f((4 + x) * sf, (8 + y) * sf);
	glVertex2f((6 + x) * sf, (8 + y) * sf);
	glVertex2f((4 + x) * sf, (3 + y) * sf);

	glEnd();
	
	//roof top first
	if (c == 1) etColor(color[2][0], color[2][1], color[2][2]);
		//rgb(122, 56, 8);
	else etColor(color[3][0], color[3][1], color[3][2]);
		//rgb(119, 41, 18);

	glBegin(GL_POLYGON);

	glVertex2f((-1 + x) * sf,( 3 + y) * sf);
	glVertex2f((1 + x) * sf, (8 + y) * sf);
	glVertex2f((9 + x) * sf, (8 + y) * sf);
	glVertex2f((7 + x) * sf, (3 + y) * sf);

	glEnd();


	//body left door
	etColor(color[4][0], color[4][1], color[4][2]);
	//rgb(135, 80, 60);

	glBegin(GL_POLYGON);

	glVertex2f((2 + x) * sf, (0 + y) * sf);
	glVertex2f((2 + x) * sf, (2 + y) * sf);
	glVertex2f((3 + x) * sf, (2 + y) * sf);
	glVertex2f((3 + x) * sf, (0 + y) * sf);

	glEnd();


	//body left
	etColor(color[5][0], color[5][1], color[5][2]);
	//rgb(203, 188, 207);

	glBegin(GL_POLYGON);

	glVertex2f((7 + x) * sf, (3.5 + y) * sf);
	glVertex2f((7 + x) * sf, (0 + y) * sf);
	glVertex2f((0 + x) * sf, (0 + y) * sf);
	glVertex2f((0 + x) * sf, (3 + y) * sf);

	glEnd();

	//house body right window
	etColor(color[6][0], color[6][1], color[6][2]);
	//rgb(135, 80, 60);

	glBegin(GL_POLYGON);

	glVertex2f((8 + x) * sf, (3 + y) * sf);
	glVertex2f((9 + x) * sf, (3 + y) * sf);
	glVertex2f((9 + x) * sf, (2 + y) * sf);
	glVertex2f((8 + x) * sf, (2 + y) * sf);

	glEnd();


	//house body right
	etColor(color[7][0], color[7][1], color[7][2]);
	//rgb(154, 121, 128);

	glBegin(GL_POLYGON);

	glVertex2f((9 + x) * sf, (8 + y) * sf);
	glVertex2f((10 + x) * sf, (3 + y) * sf);
	glVertex2f((10 + x) * sf, (0 + y) * sf);
	glVertex2f((7 + x) * sf, (0 + y) * sf);
	glVertex2f((7 + x) * sf, (3.5 + y) * sf);

	glEnd();


	//roof top right side
	etColor(color[8][0], color[8][1], color[8][2]);
	//rgb(89, 61, 14);

	glBegin(GL_POLYGON);

	glVertex2f((9 + x) * sf, (8 + y) * sf);
	glVertex2f((11 + x) * sf, (3 + y) * sf);
	glVertex2f((10 + x) * sf, (3 + y) * sf);

	glEnd();
}

//tree
void treeSmall(float x = 0, float y = 0 ,float sf = 1, float color[10][3] = NULL, int movement = 1) {
	

	float move = 0;
	if (movement % 4 == 0) {
		move = .08;
	}

	//circle
	etColor(color[0][0], color[0][1], color[0][2]);
	//glColor3f(0, 1, 0);

	if (winterFlag != 1) 
	
	{
		if (rainyFlag == 1) {
			circle((0 + x + move) * sf, (5 + y + move) * sf, 2.5 * sf);
			circle((-2 + x + move) * sf, (3 + y + move) * sf, 2.5 * sf);
			circle((2 + x + move) * sf, (3 + y + move) * sf, 2.5 * sf);
		}
		else {
			circle((0 + x) * sf, (5 + y) * sf, 2.5 * sf);
			circle((-2 + x) * sf, (3 + y) * sf, 2.5 * sf);
			circle((2 + x) * sf, (3 + y) * sf, 2.5 * sf);
		}
	}
	

	//wood
	etColor(color[1][0], color[1][1], color[1][2]);
	//glColor3f(1, 0, 0);

	glBegin(GL_POLYGON);

	glVertex2f((.2 + x) * sf, (y + 2) * sf);
	glVertex2f((.2 + x) * sf, (y -6) * sf);
	glVertex2f((-.2 + x) * sf, (y -6) * sf);
	glVertex2f((-.2 + x) * sf, (y + 2) * sf);

	glEnd();

	/////
	//glColor3f(1, 0, 0);

	glBegin(GL_POLYGON);

	glVertex2f((-.2 + x) * sf, (y -1) * sf);
	glVertex2f((-.2 + x) * sf, (y -1.2) * sf);
	glVertex2f((-2 + x) * sf, (y + 0) * sf);

	glEnd();

	/////
	//glColor3f(1, 0, 0);

	glBegin(GL_POLYGON);

	glVertex2f((-.2 + x) * sf, (-2.5 + y) * sf);
	glVertex2f((-.2 + x) * sf, (-3 + y) * sf);
	glVertex2f((2 + x) * sf, (-1 + y) * sf);

	glEnd();
	
}

//grass
void grass(float x = 0, float y = 0 , float sf = 1, float color[10][3] = NULL) {
	//wood
	etColor(color[0][0], color[0][1], color[0][2]);
	//glColor3f(0, 1, 0);

	glBegin(GL_POLYGON);

	glVertex2f((0 + x) * sf, (0 + y) * sf);
	glVertex2f((1.1 + x) * sf, (2.8 + y) * sf);
	glVertex2f((.9 + x) * sf, (.1 + y) * sf);
	glVertex2f((2.5 + x) * sf, (4.9 + y) * sf);
	glVertex2f((2 + x) * sf, (2 + y) * sf);
	glVertex2f((1.8 + x) * sf, (2.4 + y) * sf);
	glVertex2f((1.2 + x) * sf, (.2 + y) * sf);
	glVertex2f((1.9 + x) * sf, (1.1 + y) * sf);
	glVertex2f((1.6 + x) * sf, (.2 + y) * sf);
	glVertex2f((1.1 + x) * sf, (.7 + y) * sf);
	glVertex2f((.2 + x) * sf, (0 + y) * sf);
	glVertex2f((3.1 + x) * sf, (3.1 + y) * sf);
	glVertex2f((2.5 + x) * sf, (0 + y) * sf);
	glVertex2f((3.1 + x) * sf, (1.8 + y) * sf);
	glVertex2f((2.9 + x) * sf, (0 + y) * sf);
	glVertex2f((3.1 + x) * sf, (0 + y) * sf);
	glVertex2f((4.5 + x) * sf, (1.2 + y) * sf);
	glVertex2f((3.5 + x) * sf, (0 + y) * sf);

	glEnd();
}

//ellipse
void ellipse(float x = 0, float y = 0, float radiusX = 0, float radiusY = 0, int circle = 0) {

	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i < circle; i++) { //for half elipse (360 for full elipse)
		float rad = i*DEG2RAD;
		glVertex2f(x + cos(rad)*radiusX, y + sin(rad)*radiusY);
	}

	glEnd();
}


//train compartment
void trainCompartment(float x = 0, float y = 0, float sf = 1, float color[10][3] = NULL) {
	
	//door
	etColor(color[0][0], color[0][1], color[0][2]);
	//glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f((6.8 + x) * sf, (y + .5) * sf);
	glVertex2f((7.5 + x) * sf, (y + .5) * sf);
	glVertex2f((7.5 + x) * sf, (y + 2) * sf);
	glVertex2f((6.8 + x) * sf, (y + 2) * sf);
	glEnd();


	//window
	int inc = 0;
	for (int i = 0; i<3; i++) {
		etColor(color[1][0], color[1][1], color[1][2]);
		//glColor3f(0.0, 1.0, 0.0);

		glBegin(GL_POLYGON);
		glVertex2f ((1 + inc + x) * sf, (y + 1) * sf);
		glVertex2f ((2 + inc + x) * sf, (y + 1) * sf);
		glVertex2f ((2 + inc + x) * sf, (y + 2) * sf);
		glVertex2f ((1 + inc + x) * sf, (y + 2) * sf);
		glEnd();
		inc += 2;//here only x increases
	}

	etColor(color[2][0], color[2][1], color[2][2]);
	//glColor3f(0.0, 0.0, 1.0);
	//main box of train
	glBegin(GL_POLYGON);
	glVertex2f ((0 + x) * sf, (y + 0) * sf);
	glVertex2f ((8 + x) * sf, (y + 0) * sf);
	glVertex2f ((8 + x) * sf, (y + 3) * sf);
	glVertex2f ((0 + x) * sf, (y + 3) * sf);
	glEnd();

	
	circle ((1.5 + x) * sf, (y -.2) * sf, .3 * sf); //first tire
	circle ((3 + x) * sf, (y -.2) * sf, .3 * sf); //second tire
	circle ((4.5 + x) * sf, (y -.2) * sf, .3 * sf); //third tire
	circle((6 + x) * sf, (y -.2) * sf, .3 * sf); //fourth tire

	//joining
	etColor(color[3][0], color[3][1], color[3][2]);
	//glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f ((8 + x) * sf, (y + .5) * sf);
	glVertex2f ((8.35 + x) * sf, (y + .5) * sf);
	glVertex2f ((8.35 + x) * sf, (y + 2.5) * sf);
	glVertex2f ((8 + x) * sf, (y + 2.5) * sf);
	glEnd();

	
}


// train head
void TrainHead(float x = 0, float y = 0, float sf = 1, float color[10][3] = NULL) {
	trainCompartment(x,y,sf,color);
	//head lower part
	etColor(color[4][0], color[4][1], color[4][2]);
	//glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	glVertex2f ((8 + x) * sf, (y + 0) * sf);
	glVertex2f ((10 + x) * sf, (y + 0) * sf);
	glVertex2f ((10 + x) * sf, (y + 1.5) * sf);
	glVertex2f ((8 + x) * sf, (y + 1.5) * sf);
	glEnd();


	//light
	if (nightFlag == 1)
	{
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON);
		glVertex2f ((10.1 + x) * sf, (y + .5) * sf);
		glVertex2f ((17 + x) * sf, (y - 0) * sf);
		glVertex2f ((17 + x) * sf, (y + 1.75) * sf);
		glVertex2f ((10.1 + x) * sf, (y + .75) * sf);
		glEnd();
	}
	


	//head upper part
	//glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f ((10 + x) * sf, (y + 1.5) * sf);
	glVertex2f ((8 + x) * sf, (y + 1.5) * sf);

	glVertex2f ((8 + x) * sf, (y + 3.0) * sf);
	glVertex2f ((9.5 + x) * sf, (y + 2.5) * sf);
	glEnd();

	//smoke hole
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f ((7.8 + x) * sf, (y + 3) * sf);
	glVertex2f ((8.5 + x) * sf, (y + 3) * sf);

	glVertex2f ((8.5 + x) * sf, (y + 3.5) * sf);
	glVertex2f ((7.8 + x) * sf, (y + 3.5) * sf);
	glEnd();


	//smoke
	glColor3f(1.0,1.0,1.0);
	circle ((8 + x) * sf, (y + 4) * sf, .3 * sf); 

	glColor3f(1.0,1.0,1.0);
	circle ((7 + x) * sf, (y + 4.5) * sf, .4* sf); 

	glColor3f(1.0,1.0,1.0);
	circle ((5.8 + x) * sf, (y + 4.7) * sf, .55 * sf);

	glColor3f(1.0,1.0,1.0);
	circle ((4.5 + x) * sf, (y + 5.1) * sf, .6 * sf); 



	//driver body
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f ((8.6 + x) * sf, (y + 1.5) * sf);
	glVertex2f ((9 + x) * sf, (y + 1.5) * sf);
	glVertex2f ((8.75 + x) * sf, (y + 2.3) * sf);
	glEnd();

	//driver head
	glBegin(GL_POINTS);
	glVertex2f ((8.75 + x) * sf, (y + 2.3) * sf);
	glEnd();
}



//flower 
void flower(float x = 0, float y = 0, float sf = 1, float color[10][3] = NULL) {
	
	//center
	etColor(color[0][0], color[0][1], color[0][2]);
	//glColor3f(0, 1, 0);
	circle((0 + x) * sf, (0 + y) * sf, .3 * sf);

	etColor(color[1][0], color[1][1], color[1][2]);
	//glColor3f(1, 0, 0);
	circle((0 + x) * sf, (.5 + y) * sf, 1 * sf);
	circle((-1 + x) * sf, (-.5 + y) * sf, 1 * sf);
	circle((1 + x) * sf, (-.5 + y) * sf, 1 * sf);

	//bar
	etColor(color[2][0], color[2][1], color[2][2]);
	//glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f((-.1 + x) * sf, (0 + y) * sf);
	glVertex2f((-.1 + x) * sf, (-5 + y) * sf);
	glVertex2f((.1 + x) * sf, (-5 + y) * sf);
	glVertex2f((.1 + x) * sf, (0 + y) * sf);

	glEnd();

}

//box
void box(float x = 0, float y = 0, float sf = 1) {
	glBegin(GL_POLYGON);
	glVertex2f((-70 + x) * sf, (-30 + y) * sf);
	glVertex2f((70 + x) * sf, (-30 + y) * sf);
	glVertex2f((70 + x) * sf, (30 + y) * sf);
	glVertex2f((-70 + x) * sf, (30 + y) * sf);

	glEnd();
}

//forest behind the houses
void forest (float color[10][3] = NULL)
{
	//rgb(67, 159, 26);
	etColor(color[0][0], color[0][1], color[0][2]);
	ellipse(-58, -3, 14, 12, 360);
	//rgb(36, 109, 2);
	etColor(color[1][0], color[1][1], color[1][2]);
	ellipse(-50, -1, 10, 8, 360);
	//rgb(28, 95, 0);
	etColor(color[2][0], color[2][1], color[2][2]);
	ellipse(-42, -1, 7, 6, 360);
}

//cloud
void cloud(float x = 0, float y = 0, float sf = 1, float color[10][3] = NULL) {
	etColor(color[0][0], color[0][1], color[0][2]);
	ellipse(2 + x, 30 + y, 5 + sf, 4 + sf, 360);
	ellipse(-2 + x, 30 + y, 5 + sf, 3 + sf, 360);
	ellipse(4 + x, 30 + y, 5 + sf, 3 + sf, 360);
}


//birds
void bird(float x = 0, float y = 0, float sf = 1, float color[10][3] = NULL) {
	etColor(color[0][0], color[0][1], color[0][2]);

	glBegin(GL_POLYGON);
	glVertex2f((2.8 + x) * sf, (y + 1.8) * sf);
	glVertex2f((2 + x) * sf, (y + 2.5) * sf);
	glVertex2f((2.5 + x) * sf, (y + 2.1) * sf);
	glVertex2f((2.7 + x) * sf, (y + 2.2) * sf);
	glEnd();
}


//field
void field(float y = 0, float color[10][3] = NULL) {
	grass(-80, y, .5, color);
	grass(-78, y, .5, color);
	grass(-76, y, .5, color);
	grass(-74, y, .5, color);
	grass(-72, y, .5, color);
	grass(-70, y, .5, color);
	grass(-68, y, .5, color);
	grass(-66, y, .5, color);
	grass(-64, y, .5, color);
	grass(-62, y, .5, color);
	grass(-60, y, .5, color);
	grass(-58, y, .5, color);
	grass(-56, y, .5, color);
	grass(-54, y, .5, color);
	grass(-52, y, .5, color);
	grass(-50, y, .5, color);
	grass(-48, y, .5, color);
	grass(-46, y, .5, color);
	grass(-44, y, .5, color);
	grass(-42, y, .5, color);
}


//cow
void cow(float x = 0, float y = 0, int movement = 1) {

	float move = 0;
	if (movement % 10 == 0) {
		move = .05;
	}
	ellipse(-30 + x, -23.3 + y + move, 1, 1.7, 360);

	//horn
	ellipse(-30.2 + x, -21.5 + y, .2, .3, 360);
	ellipse(-29.5 + x, -21.5 + y, .2, .3, 360);

	ellipse(-35 + x, -23 + y, 4, 2, 360);
	ellipse(-33 + x, -22.2 + y, 1, 1.7, 360);
	ellipse(-33.85 + x, -22.5 + y, 1, 1.7, 360);

	//neck
	glBegin(GL_POLYGON);

	glVertex2f(-32.2 + x, -24.5 + y);
	glVertex2f(-31 + x, -24.7 + y);
	glVertex2f(-30.2 + x, -24.4 + y);
	glVertex2f(-30.7 + x, -22 + y);
	glVertex2f(-31.7 + x, -22 + y);

	glEnd();

	//back
	glBegin(GL_POLYGON);

	glVertex2f(-39 + x, -23 + y);
	glVertex2f(-38.5 + x, -25 + y);
	glVertex2f(-38.3 + x, -26.5 + y);
	glVertex2f(-38 + x, -25.5 + y);
	glVertex2f(-36 + x, -23 + y);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex2f(-38 + x, -23 + y);
	glVertex2f(-37.5 + x, -25 + y);
	glVertex2f(-37.3 + x, -26.5 + y);
	glVertex2f(-37 + x, -25.5 + y);
	glVertex2f(-35 + x, -23 + y);

	glEnd();

	//front leg
	glBegin(GL_POLYGON);

	glVertex2f(-35 + x, -23 + y);
	glVertex2f(-34.5 + x, -25 + y);
	glVertex2f(-34.3 + x, -26.5 + y);
	glVertex2f(-34 + x, -25.5 + y);
	glVertex2f(-32 + x, -23 + y);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex2f(-34 + x, -23 + y);
	glVertex2f(-33.5 + x, -25 + y);
	glVertex2f(-33.3 + x, -26.5 + y);
	glVertex2f(-33 + x, -25.5 + y);
	glVertex2f(-31 + x, -23 + y);

	glEnd();

	//tail
	glBegin(GL_POLYGON);

	glVertex2f(-39 + x, -23.2 + y);
	glVertex2f(-39 + x, -24.5 + y);
	glVertex2f(-39.2 + x, -24.5 + y);
	glVertex2f(-39.2 + x, -23 + y);

	glEnd();

	ellipse(-39 + x, -24.5 + y, .2, .5, 360);
}

//lotas
void lotas(float x = 0, float y = 0, float sf = 1, float color[10][3] = NULL) {

	//etColor(color[1][0], color[1][1], color[1][2]);
	//ellipse(-42.5 + x, 28.5 + y, .5, .2 , 360);

	etColor(color[0][0], color[0][1], color[0][2]);

	glBegin(GL_POLYGON);

	glVertex2f((2.1 + x) * sf, (y + 1.1) * sf);
	glVertex2f((1.9 + x) * sf, (y + 2.1) * sf);
	glVertex2f((2.7 + x) * sf, (y + 3) * sf);
	glVertex2f((1.3 + x) * sf, (y + 3) * sf);


	glVertex2f((1.8 + x) * sf, (y + 4.5) * sf);
	glVertex2f((.3 + x) * sf, (y + 4) * sf);
	glVertex2f((0 + x) * sf, (y + 5.1) * sf);
	glVertex2f((-.7 + x) * sf, (y + 4) * sf);


	glVertex2f((-2 + x) * sf, (y + 4.5) * sf);
	glVertex2f((-1.7 + x) * sf, (y + 3) * sf);
	glVertex2f((-2.9 + x) * sf, (y + 2.8) * sf);
	glVertex2f((-2 + x) * sf, (y + 2) * sf);
	glVertex2f((-2.1 + x) * sf, (y + 1.1) * sf);

	glVertex2f((0 + x) * sf, (y + .2) * sf);

	glEnd();


	//flower bud
	rgb(68, 0, 103);
	ellipse((4.2 + x) * sf, (0 + y) * sf, .8 * sf, 1.4 * sf, 360);

	//bud stick
	rgb(68, 0, 103);
	glBegin(GL_POLYGON);
	glVertex2f((4 + x) * sf, (.1 + y) * sf);
	glVertex2f((4.4 + x) * sf, (.1 + y) * sf);
	glVertex2f((4.4 + x) * sf, (-3.9 + y) * sf);
	glVertex2f((4 + x) * sf, (-3.9 + y) * sf);
	glEnd();

	//flower stick
	rgb(68, 0, 103);
	glBegin(GL_POLYGON);
	glVertex2f((0 + x) * sf, (.1 + y) * sf);
	glVertex2f((0.6 + x) * sf, (.1 + y) * sf);
	glVertex2f((0.6 + x) * sf, (-3.9 + y) * sf);
	glVertex2f((0 + x) * sf, (-3.9 + y) * sf);
	glEnd();

}

//leaf

void leaf (float x = 0, float y = 0, float sf = 1, float color[10][3] = NULL) {

	//lotus leaf (erased part)
	if (nightFlag != 1) rgb(88, 182, 220);         //must be water color
	else rgb(0, 100, 101);
	
	glBegin(GL_POLYGON);
	glVertex2f((7 + x) * sf, (-4 + y) * sf);
	glVertex2f((7 + x) * sf, (-6 + y) * sf);
	glVertex2f((1 + x) * sf, (-5 + y) * sf);
	glEnd();

	//leaf
	if (nightFlag != 1)  rgb(100, 159, 26);
	else rgb(48, 48, 48);
	ellipse((-1 + x) * sf, (-5 + y) * sf, 7 * sf, 5.5 * sf, 360);
}

//river shed

void riverShed(float x = 0, float y = 0, float sf = 1, float color[10][3] = NULL) {

	if (nightFlag != 1) etColor(color[0][0], color[0][1], color[0][2]);
	else rgb(48, 48, 48);
	glPointSize(8);
	glBegin(GL_LINES);

	glVertex2f((2.1 + x) * sf, (y + 1.1) * sf);
	glVertex2f((11 + x) * sf, (y + 1.1) * sf);

	glEnd();
}

//boat
void boat(float x = 0, float y = 0, float sf = 1, float color[10][3] = NULL) {

	//boitha
	if (nightFlag != 1)

	{
		etColor(color[0][0], color[0][1], color[0][2]);
		//glColor3f(1, 0, 1);

		glBegin(GL_POLYGON);
		glVertex2f((.2 + x) * sf, (4 + y) * sf);
		glVertex2f((.4 + x) * sf, (4 + y) * sf);
		glVertex2f((-1 + x) * sf, (0 + y) * sf);
		glVertex2f((-1.2 + x) * sf, (0 + y) * sf);

		glEnd();

		//sail
		etColor(color[1][0], color[1][1], color[1][2]);
		//glColor3f(0, 0, 1);

		glBegin(GL_POLYGON);
		glVertex2f((1.5 + x) * sf, (12 + y) * sf);
		glVertex2f((5.5 + x) * sf, (12 + y) * sf);
		glVertex2f((7.5 + x) * sf, (9 + y) * sf);
		glVertex2f((7.8 + x) * sf, (7 + y) * sf);
		glVertex2f((8 + x) * sf, (4.5 + y) * sf);
		glVertex2f((2 + x) * sf, (4.5 + y) * sf);
		glVertex2f((2.8 + x) * sf, (7.5 + y) * sf);
		glVertex2f((2.8 + x) * sf, (9.1 + y) * sf);

		glEnd();

		//bar
		etColor(color[2][0], color[2][1], color[2][2]);
		//glColor3f(1, 0, 0);

		glBegin(GL_POLYGON);
		glVertex2f((4.5 + x) * sf, (3 + y) * sf);
		glVertex2f((4.5 + x) * sf, (13.5 + y) * sf);
		glVertex2f((5 + x) * sf, (13.5 + y) * sf);
		glVertex2f((5 + x) * sf, (3 + y) * sf);

		glEnd();

		///top bar
		etColor(color[3][0], color[3][1], color[3][2]);
		//glColor3f(1, 0, 0);

		glBegin(GL_LINES);
		glVertex2f((1.5 + x) * sf, (12 + y) * sf);
		glVertex2f((-2 + x) * sf, (3 + y) * sf);

		glVertex2f((8 + x) * sf, (4.5 + y) * sf);
		glVertex2f((7.7 + x) * sf, (2 + y) * sf);
		glEnd();

	}
	
	//boat
	etColor(color[4][0], color[4][1], color[4][2]);
	//glColor3f(0, 1, 0);

	glBegin(GL_POLYGON);

	glVertex2f((0 + x) * sf, (.5 + y) * sf);
	glVertex2f((-2 + x) * sf, (3 + y) * sf);
	glVertex2f((1 + x) * sf, (2 + y) * sf);
	glVertex2f((9 + x) * sf, (2 + y) * sf);
	glVertex2f((12 + x) * sf, (3 + y) * sf);
	glVertex2f((10 + x) * sf, (.5 + y) * sf);

	glEnd();

	if (nightFlag != 1)
	{
		//boat man
		etColor(color[5][0], color[5][1], color[5][2]);
		//glColor3f(0, 0, 1);
		circle((x - .5) * sf, (y + 3) * sf, .3 * sf);
		circle((x - .5) * sf, (y + 2.5) * sf, .5 * sf);

		
	}
	
	//ellipse
	etColor(color[6][0], color[6][1], color[6][2]);
	//glColor3f(0, 0, 1);
	ellipse((2.8 + x) * sf, (2 + y) * sf, 1 * sf, 1 * sf, 180);

	etColor(color[7][0], color[7][1], color[7][2]);
	//glColor3f(1,0, 0);
	ellipse((4.8 + x) * sf, (2 + y) * sf, 3 * sf, 2 * sf, 180);

	riverShed((-1.5 + x) * sf, (-1 + y) * sf, 1, color);
	riverShed((-2.5 + x) * sf, (-1.5 + y) * sf, 1, color);
	riverShed((-3.5 + x) * sf, (-2 + y) * sf, 1, color);
	riverShed((-1.5 + x) * sf, (-2.5 + y) * sf, 1, color);
}


void Children(float x = 0, float y = 0, float sf = 1, int movement= 0) {
	//circle(GLfloat x, GLfloat y, GLfloat radius);
	circle((0 + x) * sf, (y + 0) * sf, .8 * sf);

	//float x = 0, float y = 0, float radiusX = 0, float radiusY = 0, int circle = 0
	ellipse(0 + x, 0 + y, 0 + sf, 0 + sf, 360);


	float move = -0.05;
	if (movement % 5 == 0) {
		move = .05;
	}

	//first child
	rgb(0, 0, 0);
	circle(-43 + move, -24, 1);
	rgb(200, 200, 200);
	ellipse(-43, -25, 1, 1.5, 360);

	//second child
	rgb(0, 0, 0);
	circle(-40.5 + move, -27.5, 1);
	rgb(200, 200, 200);
	ellipse(-40.5, -28.5, 1, 1.5, 360);

	//third child
	rgb(0, 0, 0);
	circle(-43 + move, -30, 1);
	rgb(200, 200, 200);
	ellipse(-43, -31, 1, 1.5, 360);

	//fourth child
	rgb(0, 0, 0);
	circle(-45.5 + move, -27.5, 1);
	rgb(200, 200, 200);
	ellipse(-45.5, -28.5, 1, 1.5, 360);
}


void farmer (float x = 0, float y = 0, float sf = 1, float color[10][3] = NULL){
	//hat
	rgb(166, 112, 94);

	glBegin(GL_POLYGON);
	glVertex2f((0.4 + x) * sf, (y + 0) * sf);
	glVertex2f((1.6 + x) * sf, (y + 0) * sf);
	glVertex2f((1 + x) * sf, (y + .7) * sf);
	glEnd();

	ellipse(1 + x, - 0.3 + y, 1.1 * sf, .4 * sf, 360); 

	//body
	rgb(8, 8, 10);
	glBegin(GL_POLYGON);

	glVertex2f((0.6 + x) * sf, (y - .5) * sf);
	glVertex2f((.57 + x) * sf, (y - 1.4) * sf);
	glVertex2f((1.1 + x) * sf, (y - 2.1) * sf);
	glVertex2f((1.6 + x) * sf, (y -1.4) * sf);
	glVertex2f((1.6 + x) * sf, (y -.5) * sf);
	glEnd();
}

void Ghatla(float x = 0, float y = 0, float sf = 1, float color[10][3] = NULL)

{
	//khuti lower
	rgb(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f((14.2 + x) * sf, (y - 22) * sf);
	glVertex2f((13.6 + x) * sf, (y - 22) * sf);
	glVertex2f((13.6 + x) * sf, (y - 19.5) * sf);
	glVertex2f((14.2 + x) * sf, (y - 19.5) * sf);
	glEnd();


	//poita
	rgb(125, 61, 17);
	glBegin(GL_POLYGON);
	glVertex2f((11.15 + x) * sf, (y - 18) * sf);
	glVertex2f((15.1 + x) * sf, (y - 18) * sf);
	glVertex2f((14.1 + x) * sf, (y - 21) * sf);
	glVertex2f((9.35 + x) * sf, (y - 21) * sf);
	glEnd();


	//khuti upper
	rgb(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f((14.4 + x) * sf, (y - 19) * sf);
	glVertex2f((15 + x) * sf, (y - 19) * sf);
	glVertex2f((15 + x) * sf, (y - 17) * sf);
	glVertex2f((14.4 + x) * sf, (y - 17) * sf);
	glEnd();


}


//firefly
void fireFly (float x = 0, float y = 0, float sf = 1)

{
	rgb(255, 255, 0);
	glPointSize (2);
	glBegin(GL_POINTS);

	glVertex2f((10 + x) * sf, (y - 17) * sf);

	glVertex2f((5 + x) * sf, (y - 10) * sf);
	glVertex2f((-10 + x) * sf, (y - 15) * sf);
	glVertex2f((- 29 + x) * sf, (y - 5) * sf);
	glVertex2f((-20 + x) * sf, (y - 17) * sf);

	glVertex2f((-35 + x) * sf, (y + 2) * sf);
	glVertex2f((-30 + x) * sf, (y - 0) * sf);
	glVertex2f((- 25 + x) * sf, (y - 1) * sf);
	glVertex2f((-32 + x) * sf, (y + 1 ) * sf);

	glEnd();
}

void Rain (float x = 0, float y = 0, float sf = 1, float color[10][3] = NULL) {
	rgb (250,250,250);
	int cX=-55,cY=35;//corner x corner y
	for(int i=0;i<50;i++){
		for(int j = 0;j <50 ;j++){
			glBegin(GL_LINES);
			glVertex2f(( x +cX) * sf, (y +cY) * sf);
			glVertex2f(( x + (cX-2)) * sf, (y + (cY-2)) * sf);
			glEnd();
			cX =cX+5;
			glFlush();
		}
		cY = cY-5;
		cX=-55;
	}
}

void Thunder(float x = 0, float y = 0, float sf = 1){
	glColor3f(1.0,1.0,1.0);
		glBegin(GL_LINES);
		glVertex2f((2.8 + x) * sf, (y + 1) * sf);
		glVertex2f((7 + x) * sf, (y + 4.5) * sf);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f((.5 + x) * sf, (y + 1.5) * sf);
		glVertex2f((3.5 + x) * sf, (y + 1.5) * sf);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f((1 + x) * sf, (y + 0) * sf);
		glVertex2f((2.5 + x) * sf, (y + 1.5) * sf);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f((4.3 + x) * sf, (y + .3) * sf);
		glVertex2f((4.9 + x) * sf, (y + 2.9) * sf);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f((4.7 + x) * sf, (y + 1.6) * sf);
		glVertex2f((5.8 + x) * sf, (y + .2) * sf);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f((2.2 + x) * sf, (y + 4) * sf);
		glVertex2f((5.7 + x) * sf, (y + 3.6) * sf);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f((2.2 + x) * sf, (y + 2.7) * sf);
		glVertex2f((4.1 + x) * sf, (y + 3.9) * sf);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f((5.9 + x) * sf, (y + 2.5) * sf);
		glVertex2f((6.3 + x) * sf, (y + 4) * sf);
		glEnd();
}


void star(float x = 0, float y = 0, float sf = 1) {
	
	glBegin(GL_POLYGON);
	glVertex2f((0 + x) * sf, (.3 + y) * sf);
	glVertex2f((.3 + x) * sf, (-.3 + y) * sf);
	glVertex2f((-.3 + x) * sf, (.3 + y) * sf);
	glVertex2f((.3 + x) * sf, (.3 + y) * sf);
	glVertex2f((-.3 + x) * sf, (-.3 + y) * sf);

	glEnd();
}

//star package
void multiStar() {

	rgb(254, 254, 254);

	star(0, 15);
	star(10, 30);
	star(-10, 20);
	star(-20, 25);
	star(-30, 18);
	star(36, 15);
}


//rainbow
void rainbow(float x, float y) {
	//rainbow
	rgb(99, 133, 142); //must be sky color
	ellipse(-25 + x, -31 + y, 35, 15, 180);
	rgb(189, 49, 255);
	ellipse(-25 + x, -30 + y, 35, 15, 180);
	rgb(75, 0, 130);
	ellipse(-25 + x, -29 + y, 35, 15, 180);
	rgb(0, 0, 255);
	ellipse(-25 + x, -28 + y, 35, 15, 180);
	rgb(0, 128, 0);
	ellipse(-25 + x, -27 + y, 35, 15, 180);
	rgb(255, 255, 0);
	ellipse(-25 + x, -26 + y, 35, 15, 180);
	rgb(255, 99, 0);
	ellipse(-25 + x, -25 + y, 35, 15, 180);
	rgb(255, 0, 0);
	ellipse(-25 + x, -24 + y, 35, 15, 180);
}

//katkin flower
void katkin(float x, float y, float sf) {
	rgb(250, 250, 250);
	ellipse(-25 + x, -31 + y, (.5*sf) , (3*sf) , 360);
	rgb(254, 254, 254);
	ellipse(-25.5 + x, -31 + y, (.5*sf), (3 * sf), 360);
}

void walkingMan(float x = 0, float y = 0, float sf = 1, float color[10][3] = NULL)

{
	 rgb(6, 0, 0);
	circle((.5 + x) * sf, (y + .36) * sf, .36 * sf);
	//float x = 0, float y = 0, float radiusX = 0, float radiusY = 0, int circle = 0
	glBegin(GL_POLYGON);//Body
	glVertex2f((0 + x) * sf, (y + 0) * sf);
	glVertex2f((1 + x) * sf, (y + 0) * sf);
	glVertex2f((1 + x) * sf, (y - 1) * sf);
	glVertex2f((0 + x) * sf, (y - 1) * sf);

	glEnd();
	//leg
	//ellipse(0 + .2, 0 + 1.2, .1 + sf, .3 + sf, 360);

	//ellipse((.2 + x) * sf, (-1.2 + y) * sf, .1 * sf, .1 * sf, 360);
	//ellipse((.8 + x) * sf, (-1.2 + y) * sf, .1 * sf, .1 * sf, 360);
	ellipse((.3 + x) * sf, (-1.2 + y) * sf, .12 * sf, .3 * sf, 360);
	ellipse((.7 + x) * sf, (-1.2 + y) * sf, .12 * sf, .3 * sf, 360);

	glBegin(GL_POLYGON);//stick
	glVertex2f((-1.5 + x) * sf, (y - .5) * sf);
	glVertex2f((-1.5 + x) * sf, (y - .6) * sf);
	glVertex2f((2.5 + x) * sf, (y + .5) * sf);
	glVertex2f((2.5 + x) * sf, (y + .6) * sf);
	glEnd();

	//left hand
	glBegin(GL_POLYGON);//hands ist half
	glVertex2f((0 + x) * sf, (y + 0) * sf);
	glVertex2f((-.2 + x) * sf, (y - .5) * sf);
	glVertex2f((-.2 + x) * sf, (y - .6) * sf);
	glVertex2f((0 + x) * sf, (y - .2) * sf);

	glEnd();

	glBegin(GL_POLYGON);//hands 2nd half
	glVertex2f((-.2 + x) * sf, (y - .5) * sf);
	glVertex2f((-.2 + x) * sf, (y - .6) * sf);
	glVertex2f((-.6 + x) * sf, (y - .3) * sf);
	glVertex2f((-.5 + x) * sf, (y - .3) * sf);

	glEnd();

	//right hand

	glBegin(GL_POLYGON);//hands ist half
	glVertex2f((.8 + x) * sf, (y + 0) * sf);
	glVertex2f((1.2 + x) * sf, (y - .5) * sf);
	glVertex2f((1.2 + x) * sf, (y - .3) * sf);
	glVertex2f((.8 + x) * sf, (y + .1) * sf);
	glEnd();

	glBegin(GL_POLYGON);//hands 2nd half
	glVertex2f((1.2 + x) * sf, (y - .5) * sf);
	glVertex2f((1.2 + x) * sf, (y - .3) * sf);
	glVertex2f((1.6 + x) * sf, (y + .35) * sf);
	glVertex2f((1.5 + x) * sf, (y + .35) * sf);
	glEnd();

	//left pot
	ellipse((-1.3 + x) * sf, (-1.8 + y) * sf, .5 * sf, .3 * sf, 360);


	glBegin(GL_LINE_LOOP);//left rope from stick
						  //glVertex2f((-1.5 + x) * sf, (y - .5) * sf);
	glVertex2f((-1.3 + x) * sf, (y - .6) * sf);
	glVertex2f((-1.8 + x) * sf, (y - 1.8) * sf);
	glVertex2f((-.8 + x) * sf, (y - 1.8) * sf);
	glEnd();


	//left pot
	ellipse((2.3 + x) * sf, (-.85 + y) * sf, .5 * sf, .3 * sf, 360);


	glBegin(GL_LINE_LOOP);//right rope from the stick
	glVertex2f((2.3 + x) * sf, (y + .55) * sf);
	glVertex2f((1.8 + x) * sf, (y - .9) * sf);
	glVertex2f((2.8 + x) * sf, (y - .8) * sf);
	glEnd();




}



void humanThrashing(float x = 0, float y = 0, float sf = 1, int move = 0)

{
	float movement = 0;
	if (move % 10 == 0) movement++;
	else movement--;

	rgb(88, 40, 30);
	//waist to leg
	glBegin(GL_POLYGON);
	glVertex2f((0 + x) * sf, (y + 0) * sf);
	glVertex2f((2.2 + x) * sf, (y + 1.5) * sf);
	glVertex2f((2.2 + x) * sf, (y + 6.5) * sf);
	glVertex2f((0 + x) * sf, (y + 5) * sf);
	glEnd();

	//body
	rgb(151, 114, 155);
	glBegin(GL_POLYGON);
	glVertex2f((.2 + x) * sf, (y + 5.1 + movement*.05) * sf);
	glVertex2f((2 + x) * sf, (y + 6.3 + movement*.05) * sf);
	glVertex2f((-.9 + x) * sf, (y + 7.2 + movement*.05) * sf);
	glVertex2f((-2.6 + x) * sf, (y + 6.1 + movement*.05) * sf);
	glEnd();

	rgb(0, 0, 0);
	//head
	circle((-2.1 + x) * sf, (y + 7 + movement*.05) * sf, .6 * sf);

	//hand
	glBegin(GL_LINE_LOOP);
	glVertex2f((-2.4 + x) * sf, (y + 6 + movement*.05) * sf);
	glVertex2f((-2 + x) * sf, (y + 6 + movement*.05) * sf);
	glVertex2f((-2 + x) * sf, (y + 5.1 + movement*.05) * sf);
	glVertex2f((-2.7 + x) * sf, (y + 5) * sf);
	glVertex2f((-2.9 + x) * sf, (y + 5.5) * sf);
	glEnd();

	//leg left
	ellipse((.7 + x) * sf, (-.3 + y) * sf, .2 * sf, .85 * sf, 360);

	//leg right
	ellipse((1.7 + x) * sf, (.5 + y) * sf, .2 * sf, .85 * sf, 360);

}

