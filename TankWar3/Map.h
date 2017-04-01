#pragma once
#include <stdlib.h>
#include "Draw.h"
#include "Data.h"
#include <vector>
using namespace std;
class Map
{
public:
	typedef struct MAPCELLINFO {
		int nX;
		int nY;
		int nBlock;
		int nValue;
}MapCellInfo;
	void LoadMap(int id);
	static void loadWelMap();
	void printMap();
	static void destroyWall(int x,int y);
	void GetAllFormatFiles(string path, vector<string>& files, string format);
};
