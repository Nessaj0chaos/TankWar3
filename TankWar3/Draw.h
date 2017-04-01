#pragma once
//´òÓ¡×Ö·û
#include<Windows.h>
#include<stdio.h>

class Draw
{
public:
	static void WriteChar(int High, int Wide, char* pszChar, WORD wArr);
	static bool SetWindowsSize(char* pszWindowTitle, int nX, int nY);
	int High, Wide, nX, nY;
	char* pszChar, *pszWindowTitle;
};