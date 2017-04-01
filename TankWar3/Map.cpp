#include "stdafx.h"
#include "Map.h"
int g_Map[MAP_WIDTH][MAP_HIGH] = { \
{ WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0, WALL_A1, WALL_A1, WALL_A1, WALL_A1, WALL_A1,       0,       0,       0,       0, WALL_A1, WALL_A1, WALL_A1,       0,       0,       0,       0,       0, WALL_A1, WALL_A1,       0,       0, WALL_A1,       0,       0,       0,       0, WALL_A1,       0,       0, WALL_A1,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0, WALL_A1, WALL_A1, WALL_A1, WALL_A1, WALL_A1,       0,       0,       0,       0, WALL_A1, WALL_A1, WALL_A1,       0,       0,       0,       0,       0, WALL_A1, WALL_A1,       0,       0, WALL_A1,       0,       0,       0,       0, WALL_A1,       0,       0, WALL_A1,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0, WALL_A1,       0,       0,       0,       0, WALL_A1, WALL_A1,       0,       0, WALL_A1,       0,       0,       0,       0, WALL_A1,       0, WALL_A1, WALL_A1,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0, WALL_A1,       0,       0,       0,       0, WALL_A1, WALL_A1, WALL_A1,       0, WALL_A1,       0,       0,       0,       0, WALL_A1,       0, WALL_A1,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0, WALL_A1,       0,       0,       0,       0, WALL_A1,       0, WALL_A1,       0, WALL_A1,       0,       0,       0,       0, WALL_A1,       0, WALL_A1,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0, WALL_A1,       0,       0,       0,       0, WALL_A1,       0, WALL_A1,       0, WALL_A1,       0,       0,       0,       0, WALL_A1, WALL_A1,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0,       0,       0, WALL_A1, WALL_A1, WALL_A1, WALL_A1, WALL_A1,       0,       0,       0,       0, WALL_A1,       0, WALL_A1,       0, WALL_A1,       0,       0,       0,       0, WALL_A1, WALL_A1,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0,       0,       0, WALL_A1, WALL_A1, WALL_A1, WALL_A1, WALL_A1,       0,       0,       0,       0, WALL_A1,       0,       0, WALL_A1, WALL_A1,       0,       0,       0,       0, WALL_A1, WALL_A1, WALL_A1,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0, WALL_A1,       0,       0,       0,       0, WALL_A1,       0,       0, WALL_A1, WALL_A1,       0,       0,       0,       0, WALL_A1,       0, WALL_A1,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0, WALL_A1,       0,       0,       0,       0, WALL_A1,       0,       0, WALL_A1, WALL_A1,       0,       0,       0,       0, WALL_A1,       0, WALL_A1, WALL_A1,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0, WALL_A1,       0,       0,       0,       0, WALL_A1,       0,       0, WALL_A1, WALL_A1,       0,       0,       0,       0, WALL_A1,       0,       0, WALL_A1,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0,       0,       0, WALL_A1,       0,       0,       0, WALL_A1,       0,       0,       0,       0, WALL_A1,       0,       0,       0, WALL_A1,       0,       0,       0,       0, WALL_A1,       0,       0, WALL_A1,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,  WALL_C,  WALL_C,  WALL_C,  WALL_D,  WALL_D,  WALL_D,  WALL_E,  WALL_E,  WALL_E,  WALL_F,  WALL_F,  WALL_F,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,  WALL_C,  WALL_C,  WALL_C,  WALL_D,  WALL_D,  WALL_D,  WALL_E,  WALL_E,  WALL_E,  WALL_F,  WALL_F,  WALL_F,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,  WALL_C,  WALL_C,  WALL_C,  WALL_D,  WALL_D,  WALL_D,  WALL_E,  WALL_E,  WALL_E,  WALL_F,  WALL_F,  WALL_F,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,  WALL_C,  WALL_C,  WALL_C,  WALL_D,  WALL_D,  WALL_D,  WALL_E,  WALL_E,  WALL_E,  WALL_F,  WALL_F,  WALL_F,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,  WALL_C,  WALL_C,  WALL_C,  WALL_D,  WALL_D,  WALL_D,  WALL_E,  WALL_E,  WALL_E,  WALL_F,  WALL_F,  WALL_F,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,  WALL_C,  WALL_C,  WALL_C,  WALL_D,  WALL_D,  WALL_D,  WALL_E,  WALL_E,  WALL_E,  WALL_F,  WALL_F,  WALL_F,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0,       0, WALL_B}, \
{ WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B,  WALL_B, WALL_B} };

int g_Tmap[MAP_WIDTH][MAP_HIGH];		//临时地图数组

/**********************************************************************************************//**
 * \fn	void Map::LoadMap(int id)
 *
 * \brief	Loads a map.
 *
 * \author	Alex F
 * \date	2017/3/31
 *
 * \param	id	The identifier.
 **************************************************************************************************/

void Map::LoadMap(int id)
{
	string filePath = ".\\";
	string format = ".map";
	GetAllFormatFiles(filePath, filename, format);
	ifstream fin(filename[id], ios_base::in);
	if (!fin) {
		cerr << " open false" << endl;
	}
	fin.read(reinterpret_cast<char*>(&g_Map), sizeof(int)*MAP_WIDTH*MAP_HIGH);
	printMap();
	fin.close();
}
int g_Wmap[MAP_WIDTH][MAP_HIGH];	//临时数组

/**********************************************************************************************//**
 * \fn	void Map::loadWelMap()
 *
 * \brief	Loads wel map.
 *
 * \author	Alex F
 * \date	2017/3/31
 **************************************************************************************************/

void Map::loadWelMap()
{
	ifstream fin("mapwelcome.map", ios_base::in);
	if (!fin) {
		cerr << " open false" << endl;
	}
	fin.read(reinterpret_cast<char*>(&g_Wmap), sizeof(int)*MAP_WIDTH*MAP_HIGH);
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HIGH; j++)
		{
			if (g_Wmap[i][j] == 0xA) {
				Draw::WriteChar(i,j,TANK_BODY,COLOR_RED_FOR);
			}
		}
	}
	fin.close();
}

/**********************************************************************************************//**
 * \fn	void Map::printMap()
 *
 * \brief	Print map.
 *
 * \author	Alex F
 * \date	2017/3/31
 **************************************************************************************************/

void Map::printMap()
{
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HIGH; j++)
		{
			if (g_Map[i][j] == 1) {
				Draw::WriteChar(i, j, WALL_A2_PC, COLOR_WHITE_FOR);
			}
			if (g_Map[i][j] == 2) {
				Draw::WriteChar(i, j, WALL_A1_PC, COLOR_RED_FOR);
			}
			if (g_Map[i][j] == 4) {
				Draw::WriteChar(i, j, WALL_B_PC, COLOR_WHITE_FOR);
			}
			if (g_Map[i][j] == 8) {
				Draw::WriteChar(i, j, WALL_F_PC, COLOR_BLUE_FOR);
			}
			if (g_Map[i][j] == 0xA) {
				Draw::WriteChar(i, j, TANK_BODY, COLOR_RED_FOR);
			}
		}
	}
}

/**********************************************************************************************//**
 * \fn	void Map::destroyWall(int x, int y)
 *
 * \brief	Destroys the wall.
 *
 * \author	Alex F
 * \date	2017/3/31
 *
 * \param	x	The x coordinate.
 * \param	y	The y coordinate.
 **************************************************************************************************/

void Map::destroyWall(int x, int y)
{
	if (g_Map[x][y] == 1) {
		Draw::WriteChar(x, y, WALL_A2_PC, COLOR_WHITE_FOR);
	}
	else if (g_Map[x][y] == 0) {
		Draw::WriteChar(x, y, "  ", COLOR_WHITE_FOR);
	}
	else if (g_Map[x][y] == 4) {
		Draw::WriteChar(x, y, WALL_B_PC, COLOR_WHITE_FOR);
	}
	else if (g_Map[x][y] == 5) {
		Draw::WriteChar(x, y, WALL_C_PC, COLOR_BLUE_FOR);
	}
	else if (g_Map[x][y] == 6) {
		Draw::WriteChar(x, y, WALL_D_PC, COLOR_BLUE_FOR);
	}
	else if (g_Map[x][y] == 7) {
		Draw::WriteChar(x, y, WALL_E_PC, COLOR_BLUE_FOR);
	}
	else if (g_Map[x][y] == 8) {
		Draw::WriteChar(x, y, WALL_F_PC, COLOR_BLUE_FOR);
	}
}

void Map::GetAllFormatFiles(string path, vector<string>& files, string format)
{
	//文件句柄    
	long   hFile = 0;
	//文件信息    
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*" + format).c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					//files.push_back(p.assign(path).append("\\").append(fileinfo.name) );  
					GetAllFormatFiles(p.assign(path).append("\\").append(fileinfo.name), files, format);
				}
			}
			else
			{
				files.push_back(p.assign(fileinfo.name));  //将文件路径保存，也可以只保存文件名:    p.assign(path).append("\\").append(fileinfo.name)  
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

