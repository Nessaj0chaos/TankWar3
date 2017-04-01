#pragma once
#include "stdafx.h"
//#include "Draw.h"
//#include "Data.h"
//#include "Bullet.h"
enum Direct
{
	UP = 0, DOWN, LEFT, RIGHT
};

class BaseTank
{
public:
	BaseTank();
	BaseTank(int _id, int _nx,
		int _ny, int _life,
		int _nSpeed, int _fire,
		bool _nlive, int _dir) :
		nID(_id), nX(_nx), nY(_ny),
		nLife(_life), 
		nFire(_fire), isLive(_nlive),
		nDir(_dir) {

	}
	~BaseTank();
	void Move(int dir);
	void AutoMove();
	void Draw();
	void setLive(bool live);
	void Fire();
	bool Death();
	void clear();
	int getX();
	int getY();
	int getDir();
	int getID();
	void setX(int x);
	void setID(int _id);
	void setY(int y);
	void setDir(int up);
	void setTime(clock_t time);
	bool isTank();
	bool TankThrough();
private:
	int nID;
	int nX;
	int nY;
	int nLife;
	clock_t Tstartime;
	clock_t Firetime;
	clock_t Dirtime;
	int nFire;
	bool isLive;
	int nDir;
};