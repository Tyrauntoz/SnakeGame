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

char food[4][4] = {
	{0, 1, 1, 0},
	{1, 0, 0, 1},
	{1, 0, 0, 1},
	{0, 1, 1, 0}
};



#endif /* GRAPHICS_H_ */