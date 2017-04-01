#include "stdafx.h"
#include "Draw.h"

/**********************************************************************************************//**
 * \fn	void Draw::WriteChar(int High, int Wide, char * pszChar, WORD wArr)
 *
 * \brief	Writes a character.
 *
 * \author	Alex F
 * \date	2017/3/31
 *
 * \param 		  	High   	The high.
 * \param 		  	Wide   	The wide.
 * \param [in,out]	pszChar	If non-null, the character.
 * \param 		  	wArr   	The array.
 **************************************************************************************************/

void Draw::WriteChar(int High, int Wide, char * pszChar, WORD wArr)
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	COORD loc;
	loc.X = Wide * 2;
	loc.Y = High;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wArr);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
	printf(pszChar);
}

/**********************************************************************************************//**
 * \fn	bool Draw::SetWindowsSize(char * pszWindowTitle, int nX, int nY)
 *
 * \brief	Sets windows size.
 *
 * \author	Alex F
 * \date	2017/3/31
 *
 * \param [in,out]	pszWindowTitle	If non-null, the window title.
 * \param 		  	nX			  	The n x coordinate.
 * \param 		  	nY			  	The n y coordinate.
 *
 * \return	True if it succeeds, false if it fails.
 **************************************************************************************************/

bool Draw::SetWindowsSize(char * pszWindowTitle, int nX, int nY)
{//���ÿ���̨����
	SetConsoleTitleA(pszWindowTitle);
	HANDLE hStdIn, hStdOut;
	hStdIn = GetStdHandle(STD_INPUT_HANDLE);
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//��ȡ������̨���ڴ�С
	COORD pos = GetLargestConsoleWindowSize(hStdOut);
	COORD BuffSize = { pos.X + 1,pos.Y + 1 };
	//���ÿ���̨����ȥ��С
	if (!SetConsoleScreenBufferSize(hStdOut, BuffSize)) {
		//���û�����ʧ��
		printf("buffer err(%d,%d)%d\n", BuffSize.X, BuffSize.Y, GetLastError());
		return false;
	}
	SMALL_RECT srctWindow = { 0,0,nX,nY };
	if (!SetConsoleWindowInfo(hStdOut, true, &srctWindow)) {
		//���ÿ���̨���ڴ�С
		printf("size err%d\n", GetLastError);
		return false;
	}
	COORD Buffer = { nX + 1,nY + 1 };
	//���ÿ���̨��������С
	if (!SetConsoleScreenBufferSize(hStdOut, Buffer)) {
		//���ÿ���̨���ڻ�����ʧ��
		printf("buffer err (%d,%d)\n", BuffSize.X, BuffSize.Y, GetLastError());
		return false;
	}
	return true;
}
