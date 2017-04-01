// TankWar3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;


int main()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	Welcome obj1;
	/*EditMap m;
	m.PriEditMap();*/
	//vector<BaseTank> enTank;
	//vector<Bullet> enBullet;
	//BaseTank playerTank[2];
	//vector<Bullet>	playerBullet;
	//vector<BaseTank>::iterator it;
	srand((unsigned)time(NULL));
	//Map obj2;
	//obj2.printMap();
	//Control m;
	////m.myTank();
	//playerTank[0].setX(37);
	//playerTank[0].setY(13);
	//playerTank[0].setDir(UP);
	//playerTank[0].setLive(true);
	//playerTank[0].setID(0);
	//playerTank[0].setTime(clock());
	//playerTank[0].Draw();
	
	while (true)
	{
		obj1.Print();
		obj1.getKeyDown();
	}
	
    return 0;
}

