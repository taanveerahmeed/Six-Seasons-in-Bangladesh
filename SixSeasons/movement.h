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

int x = 0;
float y = 0;
float bx = 0;
float by = 0;
float sx = 0;
float sy = 0;
float rx = 0;
float ry = 0;


//reset
void reset() {
	x = 0;
	y = 0;
	sx = sy = 0;
	
}

//update operations
void moveHouse(int value) {
	x++;
	y++;
	//sx--;
	//sy--;
	bx = x * .21;
	by = y * .05;
	sx = sx - x * .0006;
	sy = sx - y * .008;
	rx++;
	ry++;

	
	if (x == 400) {
		reset();
		
	}

	else if (x % 5 == 0)
	{
		rx = ry = 0;
	}

	glutPostRedisplay();
	glutTimerFunc(100, moveHouse, 0);
}




void movement() {
	glutTimerFunc(100, moveHouse, 0);
	
}