#pragma once

#include <windows.h>

namespace my {

	void myTextOut(HDC, int, int, LPCTSTR);
	void myWsprintf(TCHAR*, int);
	void drawLine(HDC hdc, int x1, int y1, int x2, int y2);
	void drawCircle(HDC hdc, int x, int y, int r);
	void drawEllipse(HDC hdc, int x, int y, int r);
}
