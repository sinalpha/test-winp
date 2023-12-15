#include "include/myPrint.h"


void my::myTextOut(HDC hdc, int x, int y, LPCTSTR Text) {

	TextOut(hdc, x, y, Text, lstrlen(Text));

}

void my::myWsprintf(TCHAR * str, int score) {

	wsprintf(str, TEXT("현재 점수는 %d점입니다."), score);

}

void my::drawLine(HDC hdc, int x1, int y1, int x2, int y2) {

	MoveToEx(hdc, x1, x2, NULL);
	LineTo(hdc, x2, y2);

}

void my::drawCircle(HDC hdc, int x, int y, int r) {

	Ellipse(hdc, x + r, y + r, x + r, y + r);
}

void my::drawEllipse(HDC hdc, int x, int y, int r) {

	Ellipse(hdc, x - r, y - r, x + r, y + r);

}
