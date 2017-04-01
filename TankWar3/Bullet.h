#pragma once
#include "stdafx.h"
class Bullet
{
public:
	Bullet();
	Bullet(int _id, int _nx,
		int _ny, int _dir,
		clock_t _time, bool _live) :
		nID(_id), nX(_nx), nY(_ny),
		nDir(_dir), Firetime(_time),
		isLive(_live) {};
	~Bullet();
	int getID();
	int getX();
	int getY();
	int getDir();
	clock_t getTime();
	void setID(int _id);
	void setTime(clock_t time);
	void setXY(int x,int y);
	void setDir(int dir);
	void setLive(bool live);
	void setFire(clock_t _time);
	void BDraw();
	void Bclear();
	bool BulletThrough();
	bool islive();
	void Move();
private:
	int nID;
	int nX;
	int nY;
	int nDir;
	clock_t Firetime;
	clock_t Curtime = 0;
	bool isLive;

};