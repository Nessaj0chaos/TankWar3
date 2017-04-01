#pragma once
#include "Draw.h"
#include "Data.h"

class EditMap
{
public:
	static void PriEditMap();
	VOID MouseEventProc(MOUSE_EVENT_RECORD mer);
	int MessageLoop();
	void SaveMap();
};