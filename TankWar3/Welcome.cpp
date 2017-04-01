#include "stdafx.h"
#include "Welcome.h"
INT g_GameState;
INT g_Selected;


Welcome::Welcome()
{
}

Welcome::~Welcome()
{
}
int Welcome::nX = 23;
int Welcome::nY = 15;
/**********************************************************************************************//**
 * \fn	void Welcome::Print()
 *
 * \brief	Prints this object.
 *
 * \author	Alex F
 * \date	2017/3/31
 **************************************************************************************************/

void Welcome::Print()
{
	Map::loadWelMap();
	Draw::WriteChar(23, 16, "  单人游戏", COLOR_WHITE_FOR);
	Draw::WriteChar(25, 16, "  双人游戏", COLOR_WHITE_FOR);
	Draw::WriteChar(27, 16, "  地图选择", COLOR_WHITE_FOR);
	Draw::WriteChar(29, 16, "  编辑地图", COLOR_WHITE_FOR);
	Draw::WriteChar(31, 16, "  退出游戏", COLOR_WHITE_FOR);
}

/**********************************************************************************************//**
 * \fn	void Welcome::getKeyDown()
 *
 * \brief	Gets key down.
 *
 * \author	Alex F
 * \date	2017/3/31
 **************************************************************************************************/

void Welcome::getKeyDown()
{
	Pointer();
	//system("cls");
	if (KEYDOWN(VK_UP)) {
		if (g_GameState > 0) {
			ClearPointer();
			nX-=2;
			Pointer();
			g_GameState--;
		}
	}
	else if (KEYDOWN(VK_DOWN)) {
		if (g_GameState < 4) {
			ClearPointer();
			nX+=2;
			Pointer();
			g_GameState++;
		}
	}
	else if (KEYDOWN(VK_RETURN)) {
		if (g_GameState == 0) {
			system("cls");
			Control play1;
			play1.getScreen();
		}
		if (g_GameState == 1) {
			system("cls");
			Control play2;
			play2.getScreen();
		}
		if (g_GameState == 2) {
			system("cls");
			SetGameNum();
		}
		if (g_GameState == 3) {
			system("cls");
			EditMap obj;
			obj.PriEditMap();
			obj.MessageLoop();
		}
		if (g_GameState == 4) {
			exit(0);
		}
	}
}

void Welcome::Pointer()
{
	Draw::WriteChar(nX, nY, "■", COLOR_RED_FOR);
}

void Welcome::ClearPointer()
{
	Draw::WriteChar(nX, nY, "  ", COLOR_WHITE_FOR);
}

/**********************************************************************************************//**
 * \fn	void Welcome::SetGameNum()
 *
 * \brief	Sets game number.
 *
 * \author	Alex F
 * \date	2017/3/31
 **************************************************************************************************/

void Welcome::SetGameNum()
{
	getchar();
	Map obj;
	obj.GetAllFormatFiles(".\\",filename,".map");
	int size = filename.size();
LOOP:	
	string str = "当前地图数量：" + to_string(size) + "请输入你要选择的关数：";
	char *ch = (char*)str.c_str();
	Draw::WriteChar(20, 8, ch, COLOR_WHITE_FOR);
	int n;
	scanf_s("%d", &n);
	if (n > filename.size()) {
		goto LOOP;
	}
	Control obj2;
LOOP2:	
	Draw::WriteChar(21, 8, "请输入玩家人数（0代表一个玩家，1代表两个玩家)：", COLOR_WHITE_FOR);
	int nNum;
	scanf_s("%d", &nNum);
	if (nNum != 0 && nNum != 1) {
		goto LOOP2;
	}
	g_GameState = nNum;
	system("cls");
	obj2.setFileNum(n);
	obj2.getScreen();
	filename.clear();

}

void Welcome::setXY(int x, int y) {
	nX = x;
	nY = y;
}