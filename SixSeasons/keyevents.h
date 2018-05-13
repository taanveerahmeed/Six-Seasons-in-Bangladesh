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

int hideHouse = 0;

void keyboard(unsigned char key, int x, int y) {
	reset ();
	switch (key) {
		
	case 27: // “esc” on keyboard
		exit(0);
		break;

	case 'a': // “a” on keyboard
		hideHouse++;
		glutPostRedisplay();
		break;

	case 'n': // “n” on keyboard
		
		{
			//resetFlag ();
			nightFlag = 1;

			float tempcloudColor[1][3] = { { 48, 48, 48 } };
			//cloudColor = tempcloudColor;
			ChangeColor(cloudColor, tempcloudColor, 1);

			float temptreeColor[2][3] = { { 42, 79, 73 },{ 13, 22, 25 }, };
			ChangeColor(treeColor, temptreeColor, 2);
			ChangeColor(treeColorLight, temptreeColor, 2);
			
			float tempforestColor[4][3] = { { 77, 107, 108 } };
			ChangeColor(greassDark, tempforestColor, 1);
			ChangeColor(greassLight, tempforestColor, 1);

			float tempgrassColor[1][3] = { { 28, 47, 0 } };
			ChangeColor(grassColor, tempgrassColor, 1);

			float forestColorbhndhouse[3][3] = {
				{ 33, 40, 10 }, // first
				{ 33, 40, 10 }, // second
				{ 33, 40, 10 } // third
			};

			//rgb(33, 40, 10)
			ChangeColor(forestColor, forestColorbhndhouse, 3);

			float tempfieldColor[1][3] = { { 0,84,16 } };
			float tempfieldColorLight[1][3] = { { 60,60,26 } };
			ChangeColor(fieldColor, tempfieldColor, 1);
			ChangeColor(fieldColorLight, tempfieldColorLight, 1);

			float temphouseColor[9][3] = {
			{ 70,14,8 }, // if c == 1 roof shade
			{ 69,13,7 }, // if c== 2 roof shade
			{ 82,13,0 }, // if c == 1 roof top first
			{ 82,13,0 },// if c == 2 roof top first 
			{ 78,16,7 }, // body left door
			{ 173,69,1 }, // body left
			{ 84,12,9 }, // house body right window
			{ 197,75,0 }, // house body right
			{ 92,23,5 } // roof top right side

			};

			ChangeColor(houseColor, temphouseColor, 9);

			float tempboatColor[8][3] = {
			{ 255, 0, 255 }, // boitha
			{ 0, 0, 255 }, //sail
			{ 255, 0, 0 },//bar
			{ 255, 0, 0 }, // top bar
			{ 48,48,48 }, //boat
			{ 0, 0, 255 }, //boat man
			{ 56,18,0 }, // ellipse
			{ 56,18,0 }
			};

			ChangeColor(boatColor, tempboatColor, 8);
			
			float tempTrainHeadColor[5][3] = {
				{ 255, 255, 255 }, // door
				{ 255, 255, 255 }, //window
				{ 2,32,82 }, //main box of train
				{ 0, 0, 0 }, // joining
				{ 255, 0, 0 } // train head color
			};

			ChangeColor(trainHeadColor, tempTrainHeadColor, 5);

			glutPostRedisplay();
			break;
		}

	case 'd': // “d” on keyboard

	{
		
		resetDefalutColor();
		if (rainyFlag == 1)
		{
			float tempcloudColor[1][3] = { { 133,139,153 }, };
			ChangeColor(cloudColor, tempcloudColor, 1);
		}

		if (autumnFlag == 1)
		{
			float tempfieldColor[1][3] = { { 0,84,16 } };
			float tempfieldColorLight[1][3] = { { 60,60,26 } };
			ChangeColor(fieldColor, tempfieldColor, 1);
			ChangeColor(fieldColorLight, tempfieldColorLight, 1);
		}
		nightFlag = 0;
		glutPostRedisplay();
		break;
	}

	case '1': // “1” on keyboard           //summer 

	{
		resetFlag ();
		resetDefalutColor ();
		summerFlag = 1;
		glutPostRedisplay();
		break;
	}

	case '2': // “2” on keyboard          //rainy

	{
		resetFlag ();
		resetDefalutColor ();
		rainyFlag = 1;
		float tempcloudColor[1][3] = { { 133,139,153 }, };
		ChangeColor(cloudColor, tempcloudColor, 1);
		glutPostRedisplay();
		break;
	}

	case '3': // “3” on keyboard        //autumn

	{
		resetFlag ();
		resetDefalutColor ();
		autumnFlag = 1;
		float tempfieldColor[1][3] = { { 0,84,16 } };
		float tempfieldColorLight[1][3] = { { 60,60,26 } };
		ChangeColor(fieldColor, tempfieldColor, 1);
		ChangeColor(fieldColorLight, tempfieldColorLight, 1);
		glutPostRedisplay();
		break;
	}


	case '4': // “4” on keyboard        //late autumn

	{
		resetFlag();
		resetDefalutColor();
		ltautmnFlag = 1;
		glutPostRedisplay();
		break;
	}

	case '5': // “5” on keyboard        //winter

	{
		resetFlag();
		resetDefalutColor();
		winterFlag = 1;
		float tempfieldColor[1][3] = { { 79, 72, 47 } };
		float tempfieldColorLight[1][3] = { { 110,98,74 } };
		ChangeColor(fieldColor, tempfieldColor, 1);
		ChangeColor(fieldColorLight, tempfieldColorLight, 1);
		glutPostRedisplay();
		break;
	}

	case '6': // “5” on keyboard        //spring

	{
		resetFlag();
		resetDefalutColor();
		springFlag = 1;
		glutPostRedisplay();
		break;
	}
	default: 
		break;
	}

}