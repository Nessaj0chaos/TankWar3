#include "stdafx.h"
#include "Control.h"
extern int iBorn[3][2] = { { 2,2 },{ 2,19 },{ 2.37 } };
extern INT	MAX_ENEMY = 18;		//�о�����
extern INT	MAX_ENEMY_NOW = 3;  //��ǰ�о�����
extern INT CUR_ENEMY_NOW = 0;	//����о�̹�˺���������
extern INT g_GameState;			//��Ϸ״̬
static int initID = 98;			//���ɵ�̹�˵�IDֵ
static int nSocre1 = 0;			//���1 �ĵ÷�
static int nSocre2 = 0;			//���2 �ĵ÷�
int size = filename.size();
char ch1[10];
char ch2[10];
char cht[10];
/**********************************************************************************************//**
 * \fn	void Control::getScreen()
 *
 * \brief	��ʼ��Ϸʱ�ĺ���
 *
 * \author	Alex F
 * \date	2017/3/31
 **************************************************************************************************/

void Control::getScreen()
{
	if (g_GameState == 0) {				//��g_GameState=0ʱ �ǵ������
		initMyTank();
		myTank[0].Draw();
	}
	if (g_GameState == 1)				//��g_GameState=1ʱ ��˫�����
	{
		initMyTank();
		myTank[0].Draw();
		FriendTank();
		myTank[1].Draw();
	}
	Map map;
	map.LoadMap(fileNum);
	PrintHelp();
	while (true)
	{
		if (g_GameState == 0) {					//������Ϸʱ�Ĳ���
			if (myTank[0].Death() == true) {
				if (KEYDOWN(VK_UP)) {
					myTank[0].Move(UP);
				}
				else if (KEYDOWN(VK_DOWN)) {
					myTank[0].Move(DOWN);
				}
				else if (KEYDOWN(VK_LEFT)) {
					myTank[0].Move(LEFT);
				}
				else if (KEYDOWN(VK_RIGHT)) {
					myTank[0].Move(RIGHT);
				}
				else if (KEYDOWN(VK_SPACE)) {
					myTank[0].Fire();
				}
			}
			itoa(nSocre1, ch1, 10);
			itoa(MAX_ENEMY, cht, 10);
			Draw::WriteChar( 5, MAP_HIGH+5, "��ҵ÷֣�", COLOR_PURPLE_FOR);
			Draw::WriteChar(5, MAP_HIGH+10, ch1, COLOR_PURPLE_FOR);
			Draw::WriteChar(7, MAP_HIGH + 5, "ʣ��̹�ˣ�", COLOR_PURPLE_FOR);
			Draw::WriteChar(7, MAP_HIGH + 10, cht, COLOR_PURPLE_FOR);
		}
		if (g_GameState == 1) {					//˫����Ϸʱ�Ĳ���
			if (myTank[0].Death() == true) {
				if (KEYDOWN(VK_UP)) {
					myTank[0].Move(UP);
				}
				else if (KEYDOWN(VK_DOWN)) {
					myTank[0].Move(DOWN);
				}
				else if (KEYDOWN(VK_LEFT)) {
					myTank[0].Move(LEFT);
				}
				else if (KEYDOWN(VK_RIGHT)) {
					myTank[0].Move(RIGHT);
				}
				else if (KEYDOWN(VK_SPACE)) {
					myTank[0].Fire();
				}
			}
			if (myTank[1].Death() == true) {
				if (KEYDOWN('W') || KEYDOWN('w')) {
					myTank[1].Move(UP);
				}
				else if (KEYDOWN('S') || KEYDOWN('s')) {
					myTank[1].Move(DOWN);
				}
				else if (KEYDOWN('A') || KEYDOWN('a')) {
					myTank[1].Move(LEFT);
				}
				else if (KEYDOWN('D') || KEYDOWN('d')) {
					myTank[1].Move(RIGHT);
				}
				else if (KEYDOWN(VK_F2)) {
					myTank[1].Fire();
				}
			}
			itoa(nSocre1, ch1, 10);
			itoa(nSocre2, ch2, 10);
			itoa(MAX_ENEMY, cht, 10);
			Draw::WriteChar(5, MAP_HIGH + 5, "���1�÷֣�", COLOR_PURPLE_FOR);
			Draw::WriteChar(5, MAP_HIGH + 11, ch1, COLOR_PURPLE_FOR);
			Draw::WriteChar(6, MAP_HIGH + 5, "���2�÷֣�", COLOR_PURPLE_FOR);
			Draw::WriteChar(6, MAP_HIGH + 11, ch2, COLOR_PURPLE_FOR);
			Draw::WriteChar(7, MAP_HIGH + 5, "ʣ��̹�ˣ�", COLOR_PURPLE_FOR);
			Draw::WriteChar(7, MAP_HIGH + 11, cht, COLOR_PURPLE_FOR);
		}
		
		if (g_GameState == 0) {							//ʧ�ܺ��ʼ����������Ϸ
			if (!myTank[0].Death()) {
				myTank.clear();
				listBullet.clear();
				enTank.clear();
				filename.clear();
				Welcome  obj;
				obj.setXY(23, 15);
				g_GameState = 0;
				MAX_ENEMY = 18; //�о�����
				MAX_ENEMY_NOW = 3;
				CUR_ENEMY_NOW = 0;
				fileNum = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][2 + j] = 0;
					}
				}
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][19 + j] = 0;
					}
				}
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][37 + j] = 0;
					}
				}
				nSocre1 = 0;
				nSocre2 = 0;
				MessageBox(NULL, L"�����ˣ������������˵���you loser...", L"Tips", MB_OK);
				HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
				DWORD dwRead2;
				FillConsoleOutputCharacter(stdOut, ' ', 6500, { 0,0 }, &dwRead2);
				return;
			}
		}
		if (g_GameState == 1) {							//ʧ�ܺ��ʼ����˫����Ϸ
			if (!myTank[0].Death()&&!myTank[1].Death()) {
				myTank.clear();
				listBullet.clear();
				enTank.clear();
				filename.clear();
				Welcome  obj;
				obj.setXY(23, 15);
				g_GameState = 0;
				MAX_ENEMY = 18; //�о�����
				MAX_ENEMY_NOW = 3;
				CUR_ENEMY_NOW = 0;
				fileNum = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][2 + j] = 0;
					}
				}
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][19 + j] = 0;
					}
				}
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][37 + j] = 0;
					}
				}
				MessageBox(NULL, L"�������ˣ������������˵���you loser...", L"Tips", MB_OK);
				HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
				DWORD dwRead2;
				FillConsoleOutputCharacter(stdOut, ' ', 6500, { 0,0 }, &dwRead2);
				return;
			}
		}
		
		if (MAX_ENEMY == 0) {							//����������Ϊ��ʱ��Ϸ���������ʤ��
			if (MessageBox(NULL, L"��ϲ�㣨���ǣ�Ӯ�ˣ��Ƿ���� \
				��һ��...��Ϊ�˳�����ʼ����\
				", L"Next Level", MB_OKCANCEL) == IDOK) {
				fileNum = +1;
				myTank.clear();
				listBullet.clear();
				enTank.clear();
				MAX_ENEMY = 18; //�о�����
				MAX_ENEMY_NOW = 3;
				CUR_ENEMY_NOW = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][2 + j] = 0;
					}
				}
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][19 + j] = 0;
					}
				}
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][37 + j] = 0;
					}
				}
				HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
				DWORD dwRead2;
				FillConsoleOutputCharacter(stdOut, ' ', 6500, { 0,0 }, &dwRead2);
				getScreen();
			}
			else {
				myTank.clear();
				listBullet.clear();
				enTank.clear();
				filename.clear();
				MAX_ENEMY = 18; //�о�����
				MAX_ENEMY_NOW = 3;
				CUR_ENEMY_NOW = 0;
				fileNum = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][2 + j] = 0;
					}
				}
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][19 + j] = 0;
					}
				}
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][37 + j] = 0;
					}
				}
				MessageBox(NULL, L"�������ˣ������������˵���you loser...", L"Tips", MB_OK);
				HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
				DWORD dwRead2;
				FillConsoleOutputCharacter(stdOut, ' ', 6500, { 0,0 }, &dwRead2);
				return;
			}
		}
		if(KEYDOWN('P')||KEYDOWN('p')){					//��Ϸ��ͣ
			if (MessageBox(NULL, L"��ͣ", L"stop", MB_OK)) {

			}
		}
		if (KEYDOWN(VK_ESCAPE)) {						//�˳���Ϸ��
			if (MessageBox(NULL, L"�Ƿ��˳���ǰ��Ϸ��", L"return", MB_OKCANCEL) == IDOK) {
				myTank.clear();
				listBullet.clear();
				enTank.clear();
				filename.clear();
				Welcome  obj;
				obj.setXY(23, 15);
				g_GameState = 0;
				MAX_ENEMY = 18; //�о�����
				MAX_ENEMY_NOW = 3;
				CUR_ENEMY_NOW = 0;
				fileNum = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][2 + j] = 0;
					}
				}
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][19 + j] = 0;
					}
				}
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][37 + j] = 0;
					}
				}
				HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
				DWORD dwRead2;
				FillConsoleOutputCharacter(stdOut, ' ', 6500, { 0,0 }, &dwRead2);
				return;
			}
		}
		enBorn();										//�ڹ̶��ĳ����ص����ɵз�̹��
		for (int it = 0; it < enTank.size(); it++) {	//�����з�̹��������ʹ�з�̹���ƶ���ͬʱ�����ӵ�
			enTank[it].AutoMove();
		}

		for (int i = 0; i < listBullet.size(); i++)     //�����ӵ���������������ж�
		{
			if (listBullet[i].islive()) {
				if (!BulletHitWall(listBullet[i])||!BulletHitTank(listBullet[i]))
					listBullet[i].Move();
			}
			else
				listBullet.erase(listBullet.begin() + i);
		}
		if (g_Map[38][19] == 0 || g_Map[37][19] == 0 ||		//�ж��ϼ��ǲ��Ǳ�����
			g_Map[37][20] == 0 || g_Map[38][20] == 0)
		{
			if (g_GameState == 0) {
				myTank.clear();
				listBullet.clear();
				enTank.clear();
				filename.clear();
				MAX_ENEMY = 18; //�о�����
				MAX_ENEMY_NOW = 3;
				CUR_ENEMY_NOW = 0;
				fileNum = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][2 + j] = 0;
					}
				}
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][19 + j] = 0;
					}
				}
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][37 + j] = 0;
					}
				}
				MessageBox(NULL, L"�����ˣ������������˵���you loser...", L"Tips", MB_OK);
				HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
				DWORD dwRead2;
				FillConsoleOutputCharacter(stdOut, ' ', 6500, { 0,0 }, &dwRead2);
				return;
			}
			if (g_GameState == 1) {
				myTank.clear();
				listBullet.clear();
				enTank.clear();
				filename.clear();
				MAX_ENEMY = 18; //�о�����
				MAX_ENEMY_NOW = 3;
				CUR_ENEMY_NOW = 0;
				fileNum = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][2 + j] = 0;
					}
				}
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][19 + j] = 0;
					}
				}
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						g_Map[2 + i][37 + j] = 0;
					}
				}
				MessageBox(NULL, L"�������ˣ������������˵���you loser...", L"Tips", MB_OK);
				HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
				DWORD dwRead2;
				FillConsoleOutputCharacter(stdOut, ' ', 6500, { 0,0 }, &dwRead2);
				return;
			}
		}
		if (KEYDOWN(VK_F12)) {								//��F12�򿪰����Ի���
			MessageBox(NULL, L"\
��Ϸ�������1��UP��DOWN��LEFT��RIGHT�������ڵ��ǿո��\n\
���2��W��S��A��D�������ڵ���F2.\n\
��P����ͣ��Ϸ\
", L"Help", MB_OK);
		}
	}
}

/**********************************************************************************************//**
 * \fn	bool Control::isTank(int *x,int *y)
 *
 * \brief	Query if 'x' is tank.
 *
 * \author	Alex F
 * \date	2017/3/29
 *
 * \param [in,out]	x	If non-null, the x coordinate.
 * \param [in,out]	y	If non-null, the y coordinate.
 *
 * \return	True if tank, false if not.
 **************************************************************************************************/

bool Control::isTank(int x,int y)
{
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (g_Map[x + 1][y + j] != 0) {
				return true;
			}
		}
	}
	return false;
}

/**********************************************************************************************//**
 * \fn	void Control::initEnTank(int x,int y,int dir,bool live,int id)
 *
 * \brief	Initializes the en tank.
 *
 * \author	Alex F
 * \date	2017/3/29
 *
 * \param	x   	The x coordinate.
 * \param	y   	The y coordinate.
 * \param	dir 	The dir.
 * \param	live	True to live.
 * \param	id  	The identifier.
 **************************************************************************************************/

void Control::initEnTank(int x,int y,int dir,bool live)
{
	tank.setX(x);
	tank.setY(y);
	tank.setDir(dir);
	tank.setLive(live);
	tank.setID(initID);
	tank.setTime(clock());
	tank.Draw();
	enTank.push_back(tank);
	initID += 1;
}

/**********************************************************************************************//**
 * \fn	void Control::enBorn()
 *
 * \brief	���ɵо�̹��	
 *
 * \author	Alex F
 * \date	2017/3/31
 **************************************************************************************************/

void Control::enBorn()
{
	if (MAX_ENEMY > 0) {
		if (CUR_ENEMY_NOW < 3) {
			if (!isTank(2, 2)) {
				initEnTank(2, 2, DOWN, true);
				CUR_ENEMY_NOW++;
			}
			else if (!isTank(2, 19)) {
				initEnTank(2, 19, DOWN, true);
				CUR_ENEMY_NOW++;
				return;
			}
			else if (!isTank(2, 37)) {
				initEnTank(2, 37, DOWN, true);
				CUR_ENEMY_NOW++;
			}

		}
	}
}
/**********************************************************************************************//**
 * \fn	void Control::BulletHitWall(Bullet & bullet)
 *
 * \brief	Bullet hit wall.
 *
 * \author	Alex F
 * \date	2017/3/29
 *
 * \param [in,out]	bullet	The bullet.
 **************************************************************************************************/

bool Control::BulletHitWall(Bullet &bullet)
{
	int x = bullet.getX();
	int y = bullet.getY();

	int dir = bullet.getDir();
	if (dir == UP)
	{
		if (x > 1) {
			if (g_Map[x][y] == 2 || g_Map[x][y] == 1) {
				//bullet.Bclear();
				g_Map[x][y]--;
				if (g_Map[x][y - 1] == 2 || g_Map[x][y - 1] == 1){
					g_Map[x][y - 1]--;
					Map::destroyWall(x, y-1);
				}
				if (g_Map[x][y + 1] == 2 || g_Map[x][y + 1] == 1) {
					g_Map[x][y + 1]--;
					Map::destroyWall(x, y+1);
				}
				bullet.setLive(false);
				Map::destroyWall(x, y);
				return true;
			}
			else if (g_Map[x][y] == 8) {
				g_Map[x][y]=0;
				bullet.setLive(false);
				Map::destroyWall(x, y);
				return true;
			}
			else if (g_Map[x][y] > 0 ) {
				//bullet.Bclear();
				bullet.setLive(false);
				Map::destroyWall(x, y);
				return true;
			}
			/*else {
				bullet.setLive(false);
				return false;
			}*/
		}
		else {
			bullet.Bclear();
			bullet.setLive(false);
			return false;
		}
	}
	else if (dir == DOWN) {
		if (x < 38) {
			if (g_Map[x][y] == 2 || g_Map[x][y] == 1) {
			//	bullet.Bclear();
				if (g_Map[x][y - 1] == 2 || g_Map[x][y-1] == 1) {
					g_Map[x][y-1]--;
					Map::destroyWall(x, y-1);
				}
				if (g_Map[x][y + 1] == 2 || g_Map[x][y + 1] == 1) {
					g_Map[x][y + 1] --;
					Map::destroyWall(x, y+1);
				}
				g_Map[x][y]--;
				bullet.setLive(false);
				Map::destroyWall(x, y);
				return true;
			}
			else if (g_Map[x][y] == 8) {
				g_Map[x][y] = 0;
				bullet.setLive(false);
				Map::destroyWall(x, y);
				return true;
			}
			else if (g_Map[x][y] > 0 ) {
			//	bullet.Bclear();
				bullet.setLive(false);
				Map::destroyWall(x, y);
				return true;
			}
			/*else {
				bullet.Bclear();
				bullet.setLive(false);
				return false;
			}*/
		}
		else {
			bullet.Bclear();
			bullet.setLive(false);
			return false;
		}
	}
	else if (dir == LEFT) {
		if (y > 1) {
			if (g_Map[x][y] == 2 || g_Map[x][y] == 1) {
			//	bullet.Bclear();
				if (g_Map[x - 1][y] == 2 || g_Map[x - 1][y] == 1) {
					g_Map[x-1][y]--;
					Map::destroyWall(x-1, y);
				}
				if (g_Map[x + 1][y] == 2 || g_Map[x + 1][y] == 1) {
					g_Map[x + 1][y]--;
					Map::destroyWall(x+1, y);
				}
				g_Map[x][y]--;
				bullet.setLive(false);
				Map::destroyWall(x, y);
				return true;
			}
			else if (g_Map[x][y] == 8) {
				g_Map[x][y] = 0;
				bullet.setLive(false);
				Map::destroyWall(x, y);
				return true;
			}
			else if (g_Map[x][y] > 0) {
			//	bullet.Bclear();
				bullet.setLive(false);
				Map::destroyWall(x, y);
				return true;
			}
			/*else {
				bullet.setLive(false);
				return false;
			}*/
		}
		else {
			bullet.Bclear();
			bullet.setLive(false);
			return false;
		}
	}
	else if (dir == RIGHT) {
		if (y < 38) {
			if (g_Map[x][y] == 2 || g_Map[x][y] == 1) {
				if (g_Map[x - 1][y] == 2 || g_Map[x - 1][y] == 1) {
					g_Map[x - 1][y]--;
					Map::destroyWall(x - 1, y);
				}
				if (g_Map[x + 1][y] == 2 || g_Map[x + 1][y] == 1) {
					g_Map[x + 1][y]--;
					Map::destroyWall(x + 1, y);
				}
				g_Map[x][y]--;
				bullet.setLive(false);
				Map::destroyWall(x, y);
				return true;
			}
			else if (g_Map[x][y] == 8) {
				g_Map[x][y] = 0;
				bullet.setLive(false);
				Map::destroyWall(x, y);
				return true;
			}
			else if (g_Map[x][y] > 0) {
		//		bullet.Bclear();
				bullet.setLive(false);
				Map::destroyWall(x, y);
				return true;
			}
			/*else {
				bullet.setLive(false);
				return false;
			}*/
		}
		else {
			bullet.Bclear();
			bullet.setLive(false);
			return false;
		}
	}
	return false;
}

/**********************************************************************************************//**
 * \fn	bool Control::BulletHitTank(Bullet & bullet, BaseTank& tank)
 *
 * \brief	Bullet hit tank.
 *
 * \author	Alex F
 * \date	2017/3/29
 *
 * \param [in,out]	bullet	The bullet.
 * \param [in,out]	tank  	The tank.
 *
 * \return	True if it succeeds, false if it fails.
 **************************************************************************************************/

bool Control::BulletHitTank(Bullet &bullet)
{
	int x = bullet.getX();
	int y = bullet.getY();
	int id = bullet.getID();
	if (id >= 98) {
		if (g_Map[x][y] == 96 || g_Map[x][y] == 97) {
			int tmp = g_Map[x][y];
			for (int i = 0; i < myTank.size(); i++) {
				if (tmp == myTank[i].getID()) {
					myTank[i].clear();
					bullet.Bclear();
					bullet.setLive(false);
					myTank[i].setLive(false);
					return true;
				}
			}
		}
	}
	if (id == 96) {
		if (g_Map[x][y] >= 98) {
			int tmp = g_Map[x][y];
			for (int i = 0; i < enTank.size(); i++) {
				if (tmp == enTank[i].getID()) {
					enTank[i].clear();
					enTank[i].setLive(false);
					bullet.Bclear();
					bullet.setLive(false);
					enTank.erase(enTank.begin() + i);
					CUR_ENEMY_NOW--;
					MAX_ENEMY--;
					nSocre1++;
					return true;
				}
			}
		}
	}
	if (id == 97) {
		if (g_Map[x][y] >= 98) {
			int tmp = g_Map[x][y];
			for (int i = 0; i < enTank.size(); i++) {
				if (tmp == enTank[i].getID()) {
					enTank[i].clear();
					enTank[i].setLive(false);
					bullet.Bclear();
					bullet.setLive(false);
					enTank.erase(enTank.begin() + i);
					CUR_ENEMY_NOW--;
					MAX_ENEMY--;
					nSocre2++;
					return true;
				}
			}
		}
	}
}

/**********************************************************************************************//**
 * \fn	void Control::initMyTank()
 *
 * \brief	Initializes my tank.
 *
 * \author	Alex F
 * \date	2017/3/31
 **************************************************************************************************/

void Control::initMyTank()
{
	BaseTank m;
	m.setDir(UP);
	m.setID(96);
	m.setLive(true);
	m.setX(37);
	m.setY(15);
	myTank.push_back(m);
}

/**********************************************************************************************//**
 * \fn	void Control::FriendTank()
 *
 * \brief	Friend tank.
 *
 * \author	Alex F
 * \date	2017/3/31
 **************************************************************************************************/

void Control::FriendTank()
{
	BaseTank n;
	n.setDir(UP);
	n.setID(97);
	n.setLive(true);
	n.setX(37);
	n.setY(24);
	myTank.push_back(n);
}

/**********************************************************************************************//**
 * \fn	void Control::setFileNum(int num)
 *
 * \brief	Sets file number.
 *
 * \author	Alex F
 * \date	2017/3/31
 *
 * \param	num	Number of.
 **************************************************************************************************/

void Control::setFileNum(int num)
{
	fileNum = num;
}

/**********************************************************************************************//**
 * \fn	void Control::PrintHelp()
 *
 * \brief	Print help.
 *
 * \author	Alex F
 * \date	2017/3/31
 **************************************************************************************************/

void Control::PrintHelp()
{
	for (int i = 39; i < 60; i++) {
		Draw::WriteChar(15, i,WALL_B_PC , COLOR_WHITE_FOR);
	}
	Draw::WriteChar(17,MAP_HIGH+5 ,"��F12�鿴����" , COLOR_WHITE_FOR);
	Draw::WriteChar(19, MAP_HIGH + 5, "��ESC�˳���ǰ��Ϸ", COLOR_WHITE_FOR);
}
