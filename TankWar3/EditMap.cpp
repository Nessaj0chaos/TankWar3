#include "stdafx.h"
#include "EditMap.h"
/** \brief	The pmap[ map high][pmap width] */
int g_Pmap[MAP_HIGH][PMAP_WIDTH];
int tmp = 0;		//临时变量

/**********************************************************************************************//**
 * \fn	void EditMap::PriEditMap()
 *
 * \brief	Pri edit map.
 *
 * \author	Alex F
 * \date	2017/3/31
 **************************************************************************************************/

void EditMap::PriEditMap()
{
	//打印边界
	for (int i = 0; i < MAP_HIGH; i++) {
		for (int j = 0; j < PMAP_WIDTH; j++) {
			if (i == 0 || j == 0 || i == 39 || j == 39 || j == 59 || i == 13 && j > 39) {
				g_Pmap[i][j] = 4;
			}
		}
	}
	g_Pmap[5][45] = WALL_A1;
	g_Pmap[7][45] = WALL_A2;
	g_Pmap[9][45] = TANK_B;
	g_Pmap[17][45] = 12;
	g_Pmap[19][45] = 13;
	g_Pmap[37][19] = 8;
	g_Pmap[38][19] = 8;
	g_Pmap[38][20] = 8;
	g_Pmap[37][20] = 8;
	Draw::WriteChar(21, 45, "提示：", COLOR_PURPLE_FOR);
	Draw::WriteChar(23, 47, "左侧为地图编辑区，", COLOR_PURPLE_FOR);
	Draw::WriteChar(25, 47, "鼠标单击选中的图形，", COLOR_PURPLE_FOR);
	Draw::WriteChar(27, 47, "然后在编辑区对地图", COLOR_PURPLE_FOR);
	Draw::WriteChar(29, 47, "进行编辑", COLOR_PURPLE_FOR);
	Draw::WriteChar(5, 47, "土墙可摧毁", COLOR_PURPLE_FOR);
	Draw::WriteChar(7, 47, "残墙可摧毁", COLOR_PURPLE_FOR);
	Draw::WriteChar(9, 47, "不可摧毁", COLOR_PURPLE_FOR);
	for (int i = 0; i < MAP_HIGH; i++) {
		for (int j = 0; j < PMAP_WIDTH; j++)
		{
			if (g_Pmap[i][j] == 2) {
				Draw::WriteChar(i, j, WALL_A1_PC, COLOR_RED_FOR);
			}
			if (g_Pmap[i][j] == 4) {
				Draw::WriteChar(i, j, WALL_B_PC, COLOR_WHITE_FOR);
			}
			if (g_Pmap[i][j] == WALL_A2) {
				Draw::WriteChar(i, j, WALL_A2_PC, COLOR_BLUE_FOR);
			}
			if (g_Pmap[i][j] == 8) {
				Draw::WriteChar(i, j, WALL_F_PC, COLOR_BLUE_FOR);
			}
			if (g_Pmap[i][j] == TANK_B) {
				Draw::WriteChar(i, j, TANK_BODY, COLOR_PURPLE_FOR);
			}
			if (g_Pmap[i][j] == 12) {
				Draw::WriteChar(i, j, "按F2保存地图......", COLOR_PURPLE_FOR);
			}
			if (g_Pmap[i][j] == 13) {
				Draw::WriteChar(i, j, "按ESC退出编辑.....", COLOR_PURPLE_FOR);
			}
		}
	}
}

/**********************************************************************************************//**
 * \fn	VOID EditMap::MouseEventProc(MOUSE_EVENT_RECORD mer)
 *
 * \brief	Mouse event proc.
 *
 * \author	Alex F
 * \date	2017/3/31
 *
 * \param	mer	The mer.
 *
 * \return	A VOID.
 **************************************************************************************************/

VOID EditMap::MouseEventProc(MOUSE_EVENT_RECORD mer)
{
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			int x = mer.dwMousePosition.X;
			int y = mer.dwMousePosition.Y;
			if (x==90&&y==5) {
				tmp = g_Pmap[y][x/2];
			}
			else if (x==90 && y==7) {
				tmp = g_Pmap[y][x/2];
			}
			else if (x == 90 && y==9) {
				tmp = g_Pmap[y][x/2];
			}
			if (x > 1 && x < 77 && y>1 && y < 39 ) {
				if (y < 4 || y>35) {
					return;
				}
				g_Pmap[y][x / 2] = tmp;
				if (tmp == TANK_B) {
					Draw::WriteChar(y, x / 2, TANK_BODY, COLOR_PURPLE_FOR);
				}
				else if (tmp == WALL_A1) {
					Draw::WriteChar(y, x / 2, WALL_A1_PC, COLOR_RED_FOR);
				}
				else if (tmp == WALL_A2) {
					Draw::WriteChar(y, x / 2, WALL_A2_PC, COLOR_WHITE_FOR);
				}
			}
		}
		char szBuf[100] = { 0 };
		sprintf_s(szBuf, sizeof(szBuf), "x=%2d,y=%2d ", mer.dwMousePosition.Y, mer.dwMousePosition.X / 2);
		SetConsoleTitleA(szBuf);
		Draw::WriteChar(38, 54, szBuf, COLOR_RED_FOR);
}

/**********************************************************************************************//**
 * \fn	int EditMap::MessageLoop()
 *
 * \brief	Message loop.
 *
 * \author	Alex F
 * \date	2017/3/31
 *
 * \return	An int.
 **************************************************************************************************/

int EditMap::MessageLoop()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stdRecord = { 0 };
	DWORD dwRead;
	DWORD dwRead1;
	GetConsoleMode(hStdin, &dwRead1);
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (true)
	{
		ReadConsoleInput(hStdin, &stdRecord, 1, &dwRead);

		if (stdRecord.EventType == MOUSE_EVENT) {
			MouseEventProc(stdRecord.Event.MouseEvent);
		}
		if (KEYDOWN(VK_F2)) {

			SetConsoleMode(hStdin, dwRead1);
			
			SaveMap();
			MessageBox(NULL, L"保存成功...", L"文件保存", MB_OK);
			for (int i = 0; i < MAP_HIGH; i++) {
				for (int j = 0; j < PMAP_WIDTH; j++) {
					if (i > 0 || j > 0 || i < 39 || j < 39) {
						g_Pmap[i][j] = 0;
						Draw::WriteChar(i, j, "  ", 0);
					}
				}
			}
			system("cls");
			return 0;
		}
		else if (KEYDOWN(VK_ESCAPE)) {
		//	system("cls");
			HANDLE stdOut =GetStdHandle(STD_OUTPUT_HANDLE);
			DWORD dwRead2;
			FillConsoleOutputCharacter(stdOut,' ' , 6500, { 0,0 }, &dwRead2);
			for (int i = 0; i < MAP_HIGH; i++) {
				for (int j = 0; j < PMAP_WIDTH; j++) {
					if (i > 0 || j > 0 || i < 39 || j < 39) {
						g_Pmap[i][j] = 0;
						Draw::WriteChar(i, j, "  ", 0);
					}
				}
			}
			return 0;
		}
	}
}

/**********************************************************************************************//**
 * \fn	void EditMap::SaveMap()
 *
 * \brief	Saves the map.
 *
 * \author	Alex F
 * \date	2017/3/31
 **************************************************************************************************/

void EditMap::SaveMap()
{

	string n;
	std::cout << "请输入文件的编号（为数字）：";
	std::cin >> n;
	string str = "map" + n + "\.map";
	ofstream fout(str, ios_base::out);
	if (!fout) {
		std::cerr << "Error opening " << str << "for writing." << std::endl;
	}
	for (int i = 0; i < MAP_WIDTH; i++) {
		fout.write(reinterpret_cast<char*>(&g_Pmap[i]), sizeof(int)*MAP_WIDTH);
	}
	fout.close();
}