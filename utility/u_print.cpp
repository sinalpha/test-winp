#include "include/u_print.h"

void MyTextOut(HDC hdc, int x, int y, LPCTSTR Text) {

	TextOut(hdc, x, y, Text, lstrlen(Text));

}

void u_wsprintf(TCHAR* str, int score) {

	wsprintf(str, TEXT("���� ������ %d���Դϴ�."), score);

}