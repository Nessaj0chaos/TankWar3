#include "stdafx.h"
#include "BaseTank.h"
extern int g_Map[MAP_WIDTH][MAP_HIGH];
BaseTank::BaseTank()
{
}

BaseTank::~BaseTank()
{
}

/**********************************************************************************************//**
 * \fn	void BaseTank::Move(int dir)
 *
 * \brief	Tank Moves.
 *
 * \author	Alex F
 * \date	2017/3/28
 *
 * \param	dir	The dir.
 **************************************************************************************************/

void BaseTank::Move(int dir)
{
	clear();
	if (nDir != dir)
	{
		nDir = dir;
	}
	else if(TankThrough()){
		if (nDir == UP) {
			nX -= 1;
		}
		else if (nDir == DOWN) {
			nX += 1;
		}
		else if (nDir == LEFT) {
			nY -= 1;
		}
		else if (nDir == RIGHT)
		{
			nY += 1;
		}
	}
	Draw();
}

/**********************************************************************************************//**
 * \fn	void BaseTank::AutoMove()
 *
 * \brief	Automatic move.
 *
 * \author	Alex F
 * \date	2017/3/29
 **************************************************************************************************/

void BaseTank::AutoMove()
{
	clock_t time1, time2, time3;
	time1 = clock();
	time2 = clock();
	time3 = clock();
	if (time1 - Firetime > 1200) {
		Fire();
		Firetime= time1;
	}
	if (time2 - Tstartime > 500) {
		Move(nDir);
		Tstartime = time2;
	}
	if (time3 - Dirtime > 3000) {
		nDir = (int)rand() % 4;
		Dirtime = time3;
	}
}

/**********************************************************************************************//**
 * \fn	void BaseTank::Draw()
 *
 * \brief	Draws this object.
 *
 * \author	Alex F
 * \date	2017/3/28
 **************************************************************************************************/

void BaseTank::Draw()
{
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			g_Map[nX + i][nY + j] = nID;
		}
	}
	if (nDir == UP) {
		Draw::WriteChar(nX, nY, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX - 1, nY, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX, nY - 1, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX, nY + 1, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX + 1, nY - 1, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX + 1, nY + 1, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	else if (nDir == DOWN) {
		Draw::WriteChar(nX, nY, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX + 1, nY, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX, nY - 1, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX, nY + 1, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX - 1, nY - 1, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX - 1, nY + 1, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	else if (nDir == LEFT) {
		Draw::WriteChar(nX, nY, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX, nY - 1, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX - 1, nY, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX - 1, nY + 1, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX + 1, nY, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX + 1, nY + 1, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		//printf("%d,%d", nX, nY);
	}
	else if (nDir == RIGHT) {
		Draw::WriteChar(nX, nY, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX, nY + 1, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX - 1, nY, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX + 1, nY, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX + 1, nY - 1, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		Draw::WriteChar(nX - 1, nY - 1, "¡ö", FOREGROUND_RED | FOREGROUND_INTENSITY);
		/*Draw::WriteChar(nX, nY, "  ¡ö¡ö", FOREGROUND_BLUE);
		Draw::WriteChar(nX - 1, nY, "¡ö¡ö  ", FOREGROUND_BLUE);
		Draw::WriteChar(nX + 1, nY, "¡ö¡ö  ", FOREGROUND_BLUE);*/
	}
}

/**********************************************************************************************//**
 * \fn	void BaseTank::setLive(bool live)
 *
 * \brief	Sets a live.
 *
 * \author	Alex F
 * \date	2017/3/29
 *
 * \param	live	True to live.
 **************************************************************************************************/

void BaseTank::setLive(bool live)
{
	isLive = live;
}

/**********************************************************************************************//**
 * \fn	void BaseTank::Fire()
 *
 * \brief	Fires this object.
 *
 * \author	Alex F
 * \date	2017/3/31
 **************************************************************************************************/

void BaseTank::Fire()
{
	
	clock_t Firetime = clock();
	switch (nDir) {
	case UP:
		if (g_Map[nX - 2][nY] <= 2 || g_Map[nX-2][nY]>=90) {
			bullet.setDir(nDir);
			bullet.setID(nID);
			bullet.setXY(nX, nY);
			bullet.setFire(Firetime);
			bullet.setLive(true);
			listBullet.push_back(bullet);
		}
		else {
			return;
		}
		break;
	case DOWN:
		if (g_Map[nX + 2][nY] <= 2 || g_Map[nX + 2][nY] >= 90) {
			bullet.setDir(nDir);
			bullet.setID(nID);
			bullet.setXY(nX, nY);
			bullet.setFire(Firetime);
			bullet.setLive(true);
			listBullet.push_back(bullet);
		}
		else {
			return;
		}
		break;
	case LEFT:
		if (g_Map[nX][nY - 2] <= 2 || g_Map[nX][nY - 2] >= 90) {
			bullet.setDir(nDir);
			bullet.setID(nID);
			bullet.setXY(nX, nY);
			bullet.setFire(Firetime);
			bullet.setLive(true);
			listBullet.push_back(bullet);
		}
		else {
			return;
		}
		break;
	case RIGHT:
		if (g_Map[nX][nY + 2] <= 2 || g_Map[nX][nY + 2] >= 90) {
			bullet.setDir(nDir);
			bullet.setID(nID);
			bullet.setXY(nX, nY);
			bullet.setFire(Firetime);
			bullet.setLive(true);
			listBullet.push_back(bullet);
		}
		else {
			return;
		}
		break;
	}
	//bullet.Move();
}

/**********************************************************************************************//**
 * \fn	bool BaseTank::Death()
 *
 * \brief	Deaths this object.
 *
 * \author	Alex F
 * \date	2017/3/29
 *
 * \return	True if it succeeds, false if it fails.
 **************************************************************************************************/

bool BaseTank::Death()
{
	return isLive;
}

/**********************************************************************************************//**
 * \fn	void BaseTank::clear()
 *
 * \brief	Clears this object to its blank/initial state.
 *
 * \author	Alex F
 * \date	2017/3/28
 **************************************************************************************************/

void BaseTank::clear()
{
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			g_Map[nX + i][nY + j] = 0;
		}
	}
	Draw::WriteChar(nX - 1, nY - 1, "  ", FOREGROUND_INTENSITY);
	Draw::WriteChar(nX - 1, nY + 1, "  ", FOREGROUND_INTENSITY);
	Draw::WriteChar(nX, nY, "  ", FOREGROUND_INTENSITY);
	Draw::WriteChar(nX - 1, nY, "  ", FOREGROUND_INTENSITY);
	Draw::WriteChar(nX, nY - 1, "  ", FOREGROUND_INTENSITY);
	Draw::WriteChar(nX, nY + 1, "  ", FOREGROUND_INTENSITY);
	Draw::WriteChar(nX + 1, nY - 1, "  ", FOREGROUND_INTENSITY);
	Draw::WriteChar(nX + 1, nY + 1, "  ", FOREGROUND_INTENSITY);
	Draw::WriteChar(nX + 1, nY, "  ", FOREGROUND_INTENSITY);
}

int BaseTank::getX()
{
	return nX;
}

int BaseTank::getY()
{
	return nY;
}

int BaseTank::getDir()
{
	return nDir;
}

int BaseTank::getID()
{
	return nID;
}

void BaseTank::setX(int x)
{
	nX = x;
}

void BaseTank::setID(int _id)
{
	nID = _id;
}

void BaseTank::setY(int y)
{
	nY = y;
}

void BaseTank::setDir(int up)
{
	nDir = up;
}

void BaseTank::setTime(clock_t time)
{
	Tstartime = time;
}

bool BaseTank::isTank()
{
	return false;
}

/**********************************************************************************************//**
 * \fn	bool BaseTank::TankThrough()
 *
 * \brief	Determines if we can tank through.
 *
 * \author	Alex F
 * \date	2017/3/29
 *
 * \return	True if it succeeds, false if it fails.
 **************************************************************************************************/

bool BaseTank::TankThrough()
{
	if (nX > 2 || nX < 37 || nY>2 || nY < 37) {
		if (nDir == UP) {
			if (g_Map[nX - 2][nY] > 0 || g_Map[nX - 2][nY - 1] > 0 || g_Map[nX - 2][nY + 1] > 0)
				return false;
		}
		if (nDir == DOWN) {
			if (g_Map[nX + 2][nY] > 0 || g_Map[nX + 2][nY - 1]>0 ||g_Map[nX + 2][nY + 1]>0)
				return false;
		}
		if (nDir == LEFT) {
			if (g_Map[nX][nY - 2] > 0 || g_Map[nX + 1][nY - 2] > 0 || g_Map[nX - 1][nY - 2] > 0)
				return false;
		}
		if (nDir == RIGHT) {
			if (g_Map[nX][nY + 2] > 0 || g_Map[nX + 1][nY + 2] > 0 || g_Map[nX - 1][nY + 2] > 0)
				return false;
		}
	}
}


