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

//project functions
#include "init.h";

//dispay the component on display
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(translate_x, translate_y, translate_z);

	if (winterFlag == 1)
	{
		walkingMan(-4 + (x * .041), -14 + (y * .039), 2 - (.0005*x));
		walkingMan(-6 + (x * .035), -16 + (y * .033), 2.5 - (.0007*x));
	}
	if (rainyFlag == 1) 
	{
		Rain (-rx,-ry);
		Thunder (20,20,.8*rx);
		Thunder (-15 ,20,.8*rx);
	}

	/////////////////LAND CODE START/////////////////////

	//star
	if (nightFlag == 1 && summerFlag == 1) {
		multiStar();
	}

	//boat
	if (nightFlag != 1 && winterFlag != 1) boat(bx + 20, by - 20, 1.1, boatColor);
	else if (nightFlag == 1 && winterFlag != 1) boat(15, -20, 1.1, boatColor);

	//lotas
	if (nightFlag != 1 && winterFlag != 1)
	{
		lotas(85 + x*.05, -55, .5, lotasColor);
		if (rainyFlag == 1 )
		{
			lotas(85 + x*.05, -55, .3, lotasColor);
			lotas(235 + x*.05, -8, .2, lotasColor);
		}
	}
		

	//extra leave
	if (winterFlag != 1)
	{
		leaf(65 + x*.05, -55, .5);

		leaf(84 + x*.05, -53.5, .5);

		leaf(72 + x*.05, -45, .5);

		if (rainyFlag == 1)
		{
			leaf(65 + x*.05, -55, .3);

			leaf(84 + x*.05, -53.5, .3);

			leaf(72 + x*.05, -45, .3);

		}
	}
	

	//firefly
	if (nightFlag == 1 && rainyFlag != 1) {
		if (x % 10 == 0) {
			fireFly(x*.05, y*.004);
		}
	}

	//stone

	//left side
	grass(-17, -36.5, 1, grassColor);
	grass(-20, -52, .7, grassColor);
	grass(-19, -51, .7, grassColor);

	if (nightFlag != 1) rgb(39, 43, 29);
	else rgb(51, 31, 5);
	ellipse(-12, -35.3, 2, 3, 220); 
	ellipse(-12, -35.3, 4, 2, 220);

	grass(-3, -21, .6, grassColor);
	grass(0, -21, .6, grassColor);

	if (nightFlag != 1) rgb(39, 43, 29);
	else rgb(51, 31, 5);
	ellipse(0, -12, 1.3, 2.3, 220);
	ellipse(0, -12, 3.3, 1.3, 220);

	grass(-5, -18.5, .6, grassColor);


	//right side
	grass(40, -3, .7, grassColor);
	grass(42, -3, .7, grassColor);
	grass(39, -5, .7, grassColor);

	if (nightFlag != 1) rgb(39, 43, 29);
	else rgb(51, 31, 5);
	ellipse(7, -25, 1, 2, 220); 
	ellipse(7, -25, 3, 1, 220);

	ellipse(30, -1.6, 1, 2, 220); 
	ellipse(30, -1.6, 3, 1, 220);
	
	grass(45,  -1.6, .7,  grassColor );

	//above near to the train
	if (nightFlag != 1) rgb(39, 43, 29);
	else rgb(51, 31, 5);
	ellipse(55, 3, .7, 1.7, 220); 
	ellipse(55, 3, 2.7, .7, 220);

	ellipse(59, 3, 1.5, 2.5, 220);
	ellipse(59, 3, 3.5, 1.5, 220);

	grass(80, 4, .7, grassColor);
	grass(78, 4, .7, grassColor);
	grass(75, 3.5, .7, grassColor);

	grass(75, 4, .7, grassColor);
	grass(73, 4, .7, grassColor);
	grass(70, 3.5, .7, grassColor);


	//cow
	if (nightFlag != 1 && rainyFlag != 1)
	{
		rgb(0, 0, 0);
		cow(2, 2, y);
	}
	

	//powal

	
	if (nightFlag != 1 && autumnFlag != 1) rgb(248, 227, 134);
	else rgb(158, 108, 27);
	if (autumnFlag == 1) rgb(1, 53, 9);

	ellipse(-19, -22, 8, 18, 180);
	ellipse(-25, -23, 4, 1, 180);
	ellipse(-20, -22, 4, 1, 180);

	ellipse(-33, -25, 4, 1, 180);
	


	//chari
	rgb(0, 0, 0);
	ellipse(-25, -23, 3.5, -2, 180);


	//----
	rgb(0, 0, 0);

	glBegin(GL_POLYGON);

	glVertex2f(-19.5,-21.5);
	glVertex2f(-19, -21.5);
	glVertex2f(-19, 1);
	glVertex2f(-19.5, 1);

	glEnd();


	//Human Thrashing
	if (ltautmnFlag == 1 && nightFlag != 1) {
		humanThrashing(-25, -17, .5, x);
		float powalColor[1][3] = { { 221,238,97 } };
		grass(-17, -6, 1, fieldColor);
	}
	
	//grass bottom / front of house
	grass(-19, -10, .5, grassColor);
	//grass(-10, -10, .7, grassColor);


	grass(-58, -30, .7, grassColor);
	grass(-60, -30, .7, grassColor);

	grass(-58, -52, .7, grassColor);
	grass(-60, -52, .7, grassColor);
	grass(-62, -52, .7, grassColor);
	grass(-62, -50, .7, grassColor);
	grass(-64, -52, .7, grassColor);
	grass(-66, -52, .7, grassColor);
	grass(-68, -52, .7, grassColor);
	grass(-70, -52, .7, grassColor);
	grass(-62, -50, .7, grassColor);
	grass(-72, -52, .7, grassColor);
	grass(-74, -52, .7, grassColor);
	grass(-76, -52, .7, grassColor);
	grass(-80, -52, .7, grassColor);
	grass(-84, -52, .7, grassColor);
	grass(-84, -50, .7, grassColor);
	grass(-86, -52, .7, grassColor);

	if (winterFlag != 1)
	{
		flower(-54, -30, 1, flowerColor);
		flower(-56, -31, 1, flowerColor);

		if (springFlag == 1)
		{
			flower(-50, -30, 1, flowerColor);
			flower(-52, -31, 1, flowerColor);

			flower(5, -32, 1, flowerColor);
			flower(7, -33, 1, flowerColor);
			flower(6, -30, 1, flowerColor);

		}
	}

	
	//house
	houseBig(-25, -10, 2, 1, houseColor);

	grass(-74, -28, .7, grassColor);
	grass(-76, -28, .7, grassColor);

	houseBig(-40, -12, 1.5, 2, houseColor);
	houseBig(-22, -9, 2, 2, houseColor);
	houseBig(-15, -5, 1, 1, houseColor);
	houseBig(-20, -2, 1, 1, houseColor);


	forest(forestColor);
	
	//fild and farmer
	if (nightFlag != 1 && summerFlag != 1 && winterFlag != 1)
	{
		farmer(-25 - x * .02);
		farmer(-28 - x * .02, 4.5);
		farmer(-35 + x * .02, 2);

		if (ltautmnFlag == 1 || autumnFlag == 1)
		{
			farmer(-22 - x * .02, 2.5);
			farmer(-22 - x * .02, -1.5);
			farmer(-37 + x * .02, 1.5);
		}
	}
	

	field(-12, fieldColor);
	field(-10, fieldColorLight);
	field(-8, fieldColor);
	field(-6, fieldColorLight);
	field(-4, fieldColor);
	field(-2, fieldColorLight);
	field(1, fieldColor);
	field(3, fieldColorLight);
	field(5, fieldColor);

	//kashfool
	if (autumnFlag == 1)
	{

		katkin(78, 36, .5);
		katkin(77, 36.5, .5);
		katkin(76, 36.32, .5);

		katkin(80, 36, .5);
		katkin(81, 36.5, .5);
		katkin(82, 36.32, .5);

	}

	// train
	TrainHead (x -70,6.8,.8,trainHeadColor);
	trainCompartment (x -78.4,6.8,.8, trainHeadColor);
	trainCompartment (x -86.8,6.8,.8, trainHeadColor);
	trainCompartment (x -95.2,6.8,.8, trainHeadColor);
	trainCompartment (x -103.6,6.8,.8, trainHeadColor);
	trainCompartment(x - 112, 6.8, .8, trainHeadColor);
	trainCompartment(x - 120.4, 6.8, .8, trainHeadColor);
	trainCompartment(x - 128.8, 6.8, .8, trainHeadColor);

	//ghat
	Ghatla();


	riverShed(20 + x*.05,-20,1, boatColor);
	riverShed(18 + x*.05, -20.5, 1, boatColor);
	riverShed(17.5 + x*.05, -21, 1, boatColor);
	riverShed(16 + x*.05, -21.5, 1, boatColor);

	riverShed(30 + x*.05, -15, 1, boatColor);
	riverShed(28 + x*.05, -15.5, 1, boatColor);
	riverShed(27.5 + x*.05, -16, 1, boatColor);
	riverShed(26 + x*.05, -16.5, 1, boatColor);

	riverShed(40 + x*.05, -5, 1, boatColor);
	riverShed(38 + x*.05, -5, 1, boatColor);
	riverShed(37.5 + x*.05, -6, 1, boatColor);
	riverShed(36 + x*.05, -6.5, 1, boatColor);

	riverShed(40 + x*.05, -30, 1, boatColor);
	riverShed(38 + x*.05, -30, 1, boatColor);
	riverShed(37.5 + x*.05, -31, 1, boatColor);
	riverShed(36 + x*.05, -31.5, 1, boatColor);


	//road & river
	if (nightFlag != 1) rgb(88, 182, 220);  // river
	else rgb(0, 100, 101);

	if (summerFlag == 1 || winterFlag == 1 ) ellipse(55, -39, 41, 42, 360);
	else if (rainyFlag == 1) ellipse(55, -39, 60, 42, 360);
	else ellipse(55, -39, 47, 42, 360);

	if (nightFlag != 1) rgb(66, 64, 43);
	else rgb(16, 38, 11);
	ellipse(50, -39, 45, 42, 360);

	if (nightFlag != 1 ) rgb(128, 108, 71);
	else rgb(33, 54, 9);
	ellipse(50, -38, 65, 43, 360);


	//child
	if (nightFlag != 1 && rainyFlag !=1) Children(-43, -27.8, 1, x);
	
	
	//land background
	if (nightFlag != 1) rgb(215, 175, 111);
	else rgb(89, 104, 67);
	box(0, -25);

	//////////////LAND CODE END///////////////////

	//////////////SKY CODE START///////////////////

	//birds
	if (nightFlag != 1)
	{
		bird(-28 + x*.1, 11 + y*.01, 2.2, birdColor);
		bird(-28.5 + x*.1, 12 + y*.01, 2.2, birdColor);
		bird(-29 + x*.1, 13 + y*.01, 2.2, birdColor);
		bird(-27 + x*.1, 12 + y*.01, 2.2, birdColor);

		if (springFlag == 1)
		{
			bird(-20 + x*.1, 7 + y*.01, 2.2, birdColor);
			bird(-20.5 + x*.1, 8 + y*.01, 2.2, birdColor);
			bird(-21 + x*.1, 9 + y*.01, 2.2, birdColor);
			bird(-19 + x*.1, 8 + y*.01, 2.2, birdColor);
			bird(-17 + x*.1, 7 + y*.01, 2.2, birdColor);
			bird(-18.5 + x*.1, 8 + y*.01, 2.2, birdColor);
			bird(-16 + x*.1, 9 + y*.01, 2.2, birdColor);
			bird(-15 + x*.1, 8 + y*.01, 2.2, birdColor);
			bird(10 + x*.1, 7 + y*.01, 2.2, birdColor);
			bird(10.5 + x*.1, 8 + y*.01, 2.2, birdColor);
			bird(11 + x*.1, 9 + y*.01, 2.2, birdColor);
			bird(9 + x*.1, 8 + y*.01, 2.2, birdColor);
			bird(-2 + x*.1, 7 + y*.01, 2.2, birdColor);
			bird(-2.5 + x*.1, 8 + y*.01, 2.2, birdColor);
			bird(2.1 + x*.1, 9 + y*.01, 2.2, birdColor);
			bird(1.9 + x*.1, 8 + y*.01, 2.2, birdColor);
		}
	}
	


	//cloud
	if (summerFlag == 1 )
	{
		cloud(-2,0,-2, cloudColor);
		cloud(10, -6, -3, cloudColor);
		cloud(-30, -1, -.8, cloudColor);
		cloud(-60, -1, 0, cloudColor);
		cloud(30, -1, -.8, cloudColor);
	}

	else if (rainyFlag == 1 )
	{
		cloud(-2 + x*.1,0, 2, cloudColor);
		cloud(10 + x*.1, -6, 1, cloudColor);
		cloud(-30 + x*.1, -1, 3.2, cloudColor);
		cloud(-60 + x*.1, -1, 4, cloudColor);
		cloud(30 + x*.1, -1, 1.2, cloudColor);
	}

	else 
	{
	
		cloud(-2 + x*.1,0,0, cloudColor);
		cloud(10 + x*.1, -6, -1, cloudColor);
		cloud(-30 + x*.1, -1, 1.2, cloudColor);
		cloud(-60 + x*.1, -1, 2, cloudColor);
		cloud(30 + x*.1, -1, 1.2, cloudColor);
	}
	

	

	//forest tree
	
	treeSmall(5, 9, 1, treeColor, x);
	treeSmall(6, 11, 1, treeColorLight, x);

	treeSmall(-16, 9, 1, treeColorLight, x);
	treeSmall(-35, 9, 1, treeColorLight, x);

	treeSmall(-52, 9, 1, treeColor, x);
	treeSmall(-55, 11, 1, treeColorLight, x);

	treeSmall(30, 9, 1, treeColor, x);
	treeSmall(55, 11, 1, treeColorLight, x);

	
	
	//forest style 2
	if (nightFlag != 1)rgb(146, 161, 0);
	else rgb(76, 103, 105);
	ellipse(2, 5, 3, 2, 180);
	ellipse(10, 5, 3, 2, 180);
	ellipse(20, 5, 3, 3, 180);
	ellipse(30, 5, 4, 2, 180);
	ellipse(40, 5, 5, 3, 180);
	ellipse(50, 5, 3, 2, 180);
	ellipse(-10, 5, 4, 2, 180);
	ellipse(-20, 5, 3, 3, 180);
	ellipse(-30, 5, 4, 2, 180);
	ellipse(-40, 5, 6, 3, 180);
	ellipse(-50, 6, 3, 2, 180);


	grass(0 , 5, 1, greassDark);
	grass(3, 5, 1, greassDark);
	grass(6, 2, 2, greassLight);
	grass(9, 5, 1, greassDark);
	grass(12, 5, 1, greassDark);
	grass(15, 2.5, 2, greassLight);
	grass(18, 2.5, 2, greassDark);
	grass(21, 2.5, 2, greassLight);
	grass(24, 5, 1, greassDark);
	grass(27, 5, 1, greassDark);
	grass(30, 1, 3, greassLight);
	grass(33, 3, 2, greassDark);
	grass(36, 3, 2, greassDark);
	grass(39, 5, 1, greassDark);
	grass(42, 5, 1, greassDark);
	grass(45, 3, 2, greassLight);
	grass(48, 3, 2, greassDark);
	grass(51, 5, 1, greassDark);
	grass(54, 1, 3, greassLight);
	grass(57, 5, 1, greassDark);

	grass(-3, 5, 1, greassDark);
	grass(-6, 2, 2, greassLight);
	grass(-9, 5, 1, greassDark);
	grass(-12, 5, 1, greassDark);
	grass(-15, 2, 2, greassLight);
	grass(-18, 5, 1, greassDark);
	grass(-21, 2, 2, greassLight);
	grass(-24, 5, 1, greassDark);
	grass(-27, 5, 1, greassDark);
	grass(-30, 1, 3, greassLight);
	grass(-33, 5, 1, greassDark);
	grass(-36, 2, 2, greassDark);
	grass(-39, 5, 1, greassDark);
	grass(-42, 5, 1, greassDark);
	grass(-45, 2, 2, greassLight);
	grass(-48, 5, 1, greassDark);
	grass(-51, 5, 1, greassDark);
	grass(-54, 1, 3, greassLight);
	grass(-57, 5, 1, greassDark);
	

	//sun
	
	if (nightFlag != 1 && rainyFlag != 1)
	{
		if (summerFlag == 1) rgb(249,94,12);  //summer sun
		else if (springFlag == 1)rgb(242, 220 -(x*.3) , 65 - (x*.5));  //spring sun
		
		else rgb(240, 220 - (x*.3), 65 - (x*.5));
		
		if (winterFlag != 1 && springFlag != 1) circle(sx + 55, sy + 32, 8 + (x*.01));
		if (springFlag == 1) circle(sx + -1, sy + 32, 4 + (x*.01));
	}

	else if (rainyFlag != 1)
	{
		 rgb(255, 255, 255);
		 circle(52 +x*.01,  30, 5);
	}

	//rainbow
	if (rainyFlag == 1 && nightFlag != 1) rainbow(10, 30);

	//sky background
	if (nightFlag != 1) glColor3f(0.0, 1.0, 1.0);
	
	else rgb(29, 29, 29); //summer
	if (summerFlag == 1 && nightFlag != 1) rgb(252,178,17);
	if (winterFlag == 1 && nightFlag != 1) rgb(160, 168, 191);
	if (springFlag == 1 && nightFlag != 1) rgb(12, 116, 231);

	else if ((rainyFlag == 1 && nightFlag != 1)) rgb(99,133,142);
	box(0, 10 );
	//////////////SKY CODE END///////////////////

	glutSwapBuffers();

}

