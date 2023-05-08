#ifndef __BRIGHTNESS_H__
#define __BRIGHTNESS_H__

#include "structs.h"

void makeFov (Player *user, int cols, int rows, Tile** map);


int getDistance (Position origion, Position target);

bool InMap(int y, int x, int cols, int rows);

bool lineOfSight (Position origin, Position target, Tile** map);

void clearFov (Player * user, int cols, int rows, Tile** map);

#endif