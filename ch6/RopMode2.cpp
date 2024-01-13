#include <windows.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Menu");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		0, 0, 1000, 1000,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	HACCEL hAccel;
	hAccel = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCELERATOR1));
	while (GetMessage(&Message, NULL, 0, 0)) {
		if (!TranslateAccelerator(hWnd, hAccel, &Message))
		{
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
	}
	return (int)Message.wParam;
}

void DrawLine(HDC& hdc, int sx, int sy, int oldx, int oldy) {
	MoveToEx(hdc, sx, sy, NULL);
	LineTo(hdc, oldx, oldy);
}

void DrawRectangle(HDC& hdc, int left, int top, int right, int bottom) {
	Rectangle(hdc, left, top, right, bottom);
}

void DrawFreeLine(HDC& hdc, int x, int y, int oldx, int oldy, LPARAM& lParam) {
	MoveToEx(hdc, x, y, NULL);
	x = LOWORD(lParam);
	y = HIWORD(lParam);
	LineTo(hdc, x, y);
}

void DrawCircle(HDC& hdc, int left, int top, int right, int bottom) {
	Ellipse(hdc, left, top, right, bottom);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	static int sx, sy, oldx, oldy;
	static BOOL bNowDraw{ FALSE };
	static int mod{ 0 };
	HDC hdc;



	switch (iMessage) {
	case WM_LBUTTONDOWN:
		sx = LOWORD(lParam);
		sy = HIWORD(lParam);
		oldx = sx;
		oldy = sy;
		bNowDraw = TRUE;
		return 0;

	case WM_MOUSEMOVE:
		if (bNowDraw) {
			hdc = GetDC(hWnd);
			SetROP2(hdc, R2_NOT);
			switch (mod) {
			case 0: 

				break;
			case 1: 
				DrawLine(hdc, sx, sy, oldx, oldy);
				oldx = LOWORD(lParam);
				oldy = HIWORD(lParam);
				DrawLine(hdc, sx, sy, oldx, oldy);
				break;
			case 2: 
				DrawCircle(hdc, sx, sy, oldx, oldy);
				oldx = LOWORD(lParam);
				oldy = HIWORD(lParam);
				DrawCircle(hdc, sx, sy, oldx, oldy);
				break;
			case 3: 
				DrawRectangle(hdc, sx, sy, oldx, oldy);
				oldx = LOWORD(lParam);
				oldy = HIWORD(lParam);
				DrawRectangle(hdc, sx, sy, oldx, oldy);
				break;
			}
			ReleaseDC(hWnd, hdc);
		}
		return 0;

	case WM_LBUTTONUP:
		bNowDraw = FALSE;
		hdc = GetDC(hWnd);
		switch (mod) {
		case 0: 
			//DrawFreeLine(hdc, sx, sy, lParam);
			break;

		case 1:
			DrawLine(hdc, sx, sy, oldx, oldy);
			break;

		case 2:
			DrawCircle(hdc, sx, sy, oldx, oldy);
			break;

		case 3: 
			DrawRectangle(hdc, sx, sy, oldx, oldy);
			break;
		}
		ReleaseDC(hWnd, hdc);;
		return 0;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_40004:
			MessageBox(hWnd, TEXT("자유"), TEXT("Demo"), MB_OK);
			mod = 0;
			break;

		case ID_40005:
			MessageBox(hWnd, TEXT("선"), TEXT("Demo"), MB_OK);
			mod = 1;
			break;

		case ID_40006:
			MessageBox(hWnd, TEXT("원"), TEXT("Demo"), MB_OK);
			mod = 2;
			break;

		case ID_40007:
			MessageBox(hWnd, TEXT("사각형"), TEXT("Demo"), MB_OK);
			mod = 3;
			break;
		}
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

