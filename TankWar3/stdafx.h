// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>


// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include <time.h>
#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "BaseTank.h"
#include "Bullet.h"
#include "Control.h"
#include "Data.h"
#include "Draw.h"
#include "EditMap.h"
#include "Map.h"
#include "Welcome.h"
#include <Windows.h>
#include <list>
#include <vector>
using namespace std;




extern vector<BaseTank> enTank;
extern vector<BaseTank> myTank;
extern vector<Bullet> listBullet;
extern vector<Bullet>	playerBullet;
extern vector<string>	filename;
extern int g_Map[MAP_WIDTH][MAP_HIGH];
extern Bullet bullet;