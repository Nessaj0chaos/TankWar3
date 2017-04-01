#pragma once
#include "stdafx.h"

class Welcome
{

	
public:
	static int nX ;
	static int nY ;


	/*Welcome(int x, int y):nX(x),nY(y){}*/
	Welcome();
	~Welcome();
	void Print();
	void getKeyDown();
	void Pointer();
	void ClearPointer();
	void SetGameNum();
	void setXY(int x, int y);
	void SetGameState(int x);
};