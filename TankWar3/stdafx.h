// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>


// TODO: 在此处引用程序需要的其他头文件
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