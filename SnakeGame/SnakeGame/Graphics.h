#ifndef GRAPHICS_H_
#define GRAPHICS_H_

char headNorth[4][4] = {
	{0, 1, 1, 0},
	{0, 1, 1, 0},
	{1, 1, 1, 1},
	{1, 1, 1, 1}
};

char headSouth[4][4] = {
	{1, 1, 1, 1},
	{1, 1, 1, 1},
	{0, 1, 1, 0},
	{0, 1, 1, 0}
};

char headEast[4][4] = {
	{1, 1, 0, 0},
	{1, 1, 1, 1},
	{1, 1, 1, 1},
	{1, 1, 0, 0}
};

char headWest[4][4] = {
	{0, 0, 1, 1},
	{1, 1, 1, 1},
	{1, 1, 1, 1},
	{0, 0, 1, 1}
};

char blank[4][4] = {
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0}
};

char fill[4][4] = {
	{0, 1, 1, 0},
	{1, 1, 1, 1},
	{1, 1, 1, 1},
	{0, 1, 1, 0}
};

char fill2[4][4] = {
	{1, 1, 1, 1},
	{1, 1, 1, 1},
	{1, 1, 1, 1},
	{1, 1, 1, 1}
};

char food[4][4] = {
	{0, 1, 1, 0},
	{1, 0, 0, 1},
	{1, 0, 0, 1},
	{0, 1, 1, 0}
};

char gameOver[16][16] = {
	{0, 0, 0, 245, 245, 245, 245, 245, 0, 0, 0, 0, 0, 0, 245, 0},
	{0, 0, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 245, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 245, 245, 245, 0, 0, 0},
	{0, 0, 0, 0, 245, 245, 245, 0, 0, 0, 0, 0, 0, 245, 0, 0},
	{0, 0, 0, 245, 0, 0, 0, 245, 0, 0, 0, 0, 0, 0, 245, 0},
	{0, 0, 0, 245, 0, 0, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 245, 245, 245, 0, 0, 0, 0, 245, 245, 245, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 245, 0, 0, 0, 245, 0},
	{0, 0, 0, 245, 0, 245, 245, 0, 0, 0, 245, 0, 0, 0, 245, 0},
	{0, 0, 0, 245, 0, 245, 0, 245, 0, 0, 0, 245, 245, 245, 0, 0},
	{0, 0, 0, 0, 245, 0, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 245, 245, 245, 245, 0},
	{0, 0, 0, 245, 245, 245, 245, 245, 0, 0, 245, 0, 0, 0, 0, 0},
	{0, 0, 0, 245, 0, 245, 0, 245, 0, 0, 245, 0, 0, 0, 0, 0},
	{0, 0, 0, 245, 0, 0, 0, 245, 0, 0, 0, 245, 245, 245, 245, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

char score[9][40] = {
	{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0}
};

char high[9][32] ={
	{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}
};

char zero[9][8]= {
	{0, 0, 1, 1, 1, 1, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 0, 1, 1, 0},
	{0, 1, 1, 0, 0, 1, 1, 0},
	{0, 1, 1, 0, 0, 1, 1, 0},
	{0, 1, 1, 0, 0, 1, 1, 0},
	{0, 1, 1, 0, 0, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 1, 1, 1, 1, 0, 0}
};

char one[9][8]= {
	{0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0}
};

char two[9][8]= {
	{0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 1, 1, 1, 1, 0, 0},
	{0, 0, 1, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 1, 0, 0},
	{0, 0, 1, 1, 1, 1, 0, 0}
};

char three[9][8]= {
	{0, 0, 1, 1, 1, 0, 0, 0},
	{0, 0, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 1, 1, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 0}
};

char four[9][8]= {
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 1, 1, 1, 1, 1, 0, 0},
	{0, 1, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0}
};

char five[9][8]= {
	{0, 0, 0, 1, 1, 1, 1, 0},
	{0, 0, 1, 1, 1, 1, 1, 0},
	{0, 0, 1, 1, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 1, 1, 0},
	{0, 0, 1, 1, 1, 1, 1, 0},
	{0, 0, 1, 1, 1, 1, 0, 0}
};

char six[9][8]= {
	{0, 0, 1, 1, 1, 1, 0, 0},
	{0, 1, 1, 1, 1, 1, 0, 0},
	{0, 1, 1, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 0, 1, 1, 0},
	{0, 1, 1, 0, 0, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 1, 1, 1, 1, 0, 0}
};

char seven[9][8]= {
	{0, 0, 1, 1, 1, 1, 0, 0},
	{0, 0, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0},
	{0, 0, 1, 1, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0, 0, 0}
};

char eight[9][8]= {
	{0, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 0, 1, 1, 0},
	{0, 1, 1, 0, 0, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 0, 1, 1, 0},
	{0, 1, 1, 0, 0, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 0}
};

char nine[9][8]= {
	{0, 0, 1, 1, 1, 1, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 0, 1, 1, 0},
	{0, 1, 1, 0, 0, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 1, 1, 1, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 1, 1, 1, 1, 1, 0},
	{0, 0, 1, 1, 1, 1, 1, 0}
};

char empty[9][8]= {
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0}
};
#endif /* GRAPHICS_H_ */