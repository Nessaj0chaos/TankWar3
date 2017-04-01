#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

int Bullet::getID()
{
	return nID;
}

int Bullet::getX()
{
	return nX;
}

int Bullet::getY()
{
	return nY;
}

int Bullet::getDir()
{
	return nDir;
}

clock_t Bullet::getTime()
{
	return Firetime;
}

void Bullet::setID(int _id)
{
	nID = _id;
}

void Bullet::setTime(clock_t time)
{
	Firetime = time;
}

/**********************************************************************************************//**
 * \fn	void Bullet::setXY(int x,int y)
 *
 * \brief	Sets an xy.
 *
 * \author	Alex F
 * \date	2017/3/31
 *
 * \param	x	The x coordinate.
 * \param	y	The y coordinate.
 **************************************************************************************************/

void Bullet::setXY(int x,int y)
{
	if (nDir == UP) {
		nX = x - 2;
		nY = y;
	}
	else if (nDir == DOWN) {
		nX = x + 2;
		nY = y;
	}
	else if (nDir == LEFT) {
		nX = x;
		nY = y - 2;
	}
	else if (nDir == RIGHT) {
		nX = x;
		nY = y + 2;
	}
}

void Bullet::setDir(int dir)
{
	nDir = dir;
}

void Bullet::setLive(bool live)
{
	isLive = live;
}

void Bullet::setFire(clock_t _time)
{
	Firetime = _time;
}

/**********************************************************************************************//**
 * \fn	void Bullet::Move()
 *
 * \brief	Moves this object.
 *
 * \author	Alex F
 * \date	2017/3/31
 **************************************************************************************************/

void Bullet::Move()
{
	if (BulletThrough()) {
		if (clock() - Curtime < 100) {
			return;
		}
		Bclear();

		if (nDir == UP) {
			nX -= 1;
		}
		else if (nDir == DOWN) {
			nX += 1;
		}
		else if (nDir == LEFT) {
			nY -= 1;
		}
		else if (nDir == RIGHT) {
			nY += 1;
		}
		if (g_Map[nX][nY]==0) {
			BDraw();
		}
		Curtime = clock();
	}
}

void Bullet::BDraw()
{
	//g_Map[nX][nY] = nID;
	Draw::WriteChar(nX, nY, MISSILETYPE_1_PC, COLOR_YELLOW_FOR);
}

void Bullet::Bclear()
{
	//g_Map[nX][nY] = 0;
	Draw::WriteChar(nX, nY, "  ", COLOR_YELLOW_FOR);
}

/**********************************************************************************************//**
 * \fn	bool Bullet::BulletThrough()
 *
 * \brief	Determines if we can bullet through.
 *
 * \author	Alex F
 * \date	2017/3/31
 *
 * \return	True if it succeeds, false if it fails.
 **************************************************************************************************/

bool Bullet::BulletThrough()
{
	switch (nDir)
	{
	case UP:
		if (nX  > 1) {
			return true;
		}
		else
			return false;
		break;
	case DOWN:
		if (nX < 38) {
			return true;
		}
		else
			return false;
		break;
	case LEFT:
		if (nY - 1 > 0) {
			return true;
		}
		else
			return false;
		break;
	case RIGHT:
		if (nY + 1 < 39) {
			return true;
		}
		else
			return false;

		break;
	default:
		break;
	}
}

bool Bullet::islive()
{
	return isLive;
}
