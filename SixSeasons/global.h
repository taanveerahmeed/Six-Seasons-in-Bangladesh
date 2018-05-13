//flags
int nightFlag = 0 ;
int summerFlag = 0;
int rainyFlag = 0;
int autumnFlag = 0;
int ltautmnFlag = 0;
int winterFlag = 0;
int springFlag = 0;


//color variables
float lotasColor[2][3] = {
	{ 81,23,110 },
	{ 255,229,97 }
};

float grassColor[1][3] = { { 86,110,48 } };

float houseColor[9][3] = {
	{ 157, 82, 24 }, // if c == 1 roof shade
	{ 125, 61, 17 }, // if c== 2 roof shade
	{ 122, 56, 8 }, // if c == 1 roof top first
	{ 119, 41, 18 },// if c == 2 roof top first 
	{ 135, 80, 60 }, // body left door
	{ 203, 188, 207 }, // body left
	{ 135, 80, 60 }, // house body right window
	{ 154, 121, 128 }, // house body right
	{ 89, 61, 14 } // roof top right side

};

//flower color
float flowerColor[4][3] = {
	{ 255,205,2 },
	{ 202,33,18 },
	{ 229,105,37 },
};

//forest
float forestColor[3][3] = {
	{ 67 , 159 , 26 }, // first
	{ 36, 109, 2 }, // second
	{ 28, 95, 0 } // third
};

float fieldColor[1][3] = { { 196,128,47 } };
float fieldColorLight[1][3] = { { 229,190,58 } };


float trainHeadColor[5][3] = {
	{ 0, 255, 0 }, // door
	{ 0, 255, 0 }, //window
	{ 125,16,22 }, //main box of train
	{ 0, 0, 0 }, // joining
	{ 255, 0, 0 } // train head color
};

float boatColor[8][3] = {
	{ 81,34,40 }, // boitha
	{ 220, 220, 220 }, //sail
	{ 81,34,40 },//bar
	{ 81,34,40 }, // top bar
	{ 98,94,90  }, //boat
	{ 0, 0, 0 }, //boat man
	{ 255,114,84}, // ellipse
	{ 134,67,48 }
};

float birdColor[1][3] = { { 0,0,0 }, };

float cloudColor[1][3] = { { 239,246,230 }, };

float treeColor[2][3] = { { 35,88,11 },{ 50,63,7 }, };
float treeColorLight[2][3] = { { 33,109,4 },{ 50,63,7 }, };

//forest
float greassDark[1][3] = { { 95, 113, 8 }, };
float greassLight[1][3] = { { 126,145,1 }, };

//function to change element color
void ChangeColor(float changedElement[10][3] = NULL, float color[10][3] = NULL, int colorNum = 0)
{
	for (int i = 0; i < colorNum; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			changedElement[i][j] = color[i][j];
		}
	}
}

void resetDefalutColor ()
{
	float temphouseColor[9][3] = {
	{ 157, 82, 24 }, // if c == 1 roof shade
	{ 125, 61, 17 }, // if c== 2 roof shade
	{ 122, 56, 8 }, // if c == 1 roof top first
	{ 119, 41, 18 },// if c == 2 roof top first 
	{ 135, 80, 60 }, // body left door
	{ 203, 188, 207 }, // body left
	{ 135, 80, 60 }, // house body right window
	{ 154, 121, 128 }, // house body right
	{ 89, 61, 14 } // roof top right side

	};

	ChangeColor (houseColor,temphouseColor,9);

	float templotasColor[2][3] = {
	{ 81,23,110 },
	{ 255,229,97 }
	};

	ChangeColor (lotasColor,templotasColor,2);

	float tempgrassColor[1][3] = { { 86,110,48 } };

	ChangeColor (grassColor,tempgrassColor,1);

	//flower color
	float tempflowerColor[4][3] = {
		{ 255,205,2 },
		{ 202,33,18 },
		{ 229,105,37 },
	};

	ChangeColor (flowerColor,tempflowerColor,4);

	//forest
	float tempforestColor[3][3] = {
		{ 67 , 159 , 26 }, // first
		{ 36, 109, 2 }, // second
		{ 28, 95, 0 } // third
	};

	ChangeColor (forestColor,tempforestColor,3);

	float tempfieldColor[1][3] = { { 196,128,47 } };
	ChangeColor (fieldColor,tempfieldColor,1);

	float tempfieldColorLight[1][3] = { { 229,190,58 } };
	ChangeColor (fieldColorLight,tempfieldColorLight,1);

	float temptrainHeadColor[5][3] = {
		{ 0, 255, 0 }, // door
		{ 0, 255, 0 }, //window
		{ 125,16,22 }, //main box of train
		{ 0, 0, 0 }, // joining
		{ 255, 0, 0 } // train head color
	};
	ChangeColor (trainHeadColor,temptrainHeadColor,5);

	float tempboatColor[8][3] = {
		{ 81,34,40 }, // boitha
		{ 220, 220, 220 }, //sail
		{ 81,34,40 },//bar
		{ 81,34,40 }, // top bar
		{ 98,94,90 }, //boat
		{ 0, 0, 0 }, //boat man
		{ 255,114,84 }, // ellipse
		{ 134,67,48 }
	};
	ChangeColor (boatColor,tempboatColor,8);

	//float birdColor[1][3] = { { 0,0,0 }, };

	float tempcloudColor[1][3] = { { 239,246,230 }, };
	ChangeColor (cloudColor,tempcloudColor,1);

	float temptreeColor[2][3] = { { 35,88,11 },{ 50,63,7 }, };
	ChangeColor (treeColor,temptreeColor,2);

	float temptreeColorLight[2][3] = { { 33,109,4 },{ 50,63,7 }, };
	ChangeColor (treeColorLight,temptreeColorLight,2);

	//forest
	float tempgreassDark[1][3] = { { 95, 113, 8 }, };
	ChangeColor (greassDark,tempgreassDark,1);

	float tempgreassLight[1][3] = { { 126,145,1 }, };
	ChangeColor (greassLight,tempgreassLight,1);


}

void resetFlag ()
{
	 nightFlag = 0 ;
	 summerFlag = 0;
	 rainyFlag = 0;
	 autumnFlag = 0;
	 ltautmnFlag = 0;
	 winterFlag = 0;
	 springFlag = 0;
}
