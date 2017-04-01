#pragma once
#include "stdafx.h"

using namespace std;

class Control
{
	int fileNum = 0;
public:
	BaseTank tank;
	Bullet bullet;
	void getScreen();
	bool isTank(int x, int y);
	void initEnTank(int x, int y, int dir, bool live);
	void enBorn();
	static bool BulletHitWall(Bullet& bullet);
	bool BulletHitTank(Bullet &bullet);
	void initMyTank();
	void FriendTank();
	void setFileNum(int num);
	void PrintHelp();
};