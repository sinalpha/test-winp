#include <windows.h>
#include <vector>
#include <utility>

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
	HBRUSH OldBrush;

	OldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));
	Rectangle(hdc, left, top, right, bottom);
	SelectObject(hdc, OldBrush);
}

void DrawFreeLine(HDC& hdc, const std::vector<std::pair<int, int>> footPrints) {
	
	for (int i = 0; i < footPrints.size() - 1; ++i) {
		const int stX{ footPrints[i].first };
		const int stY{ footPrints[i].second };
		const int edX{ footPrints[i + 1].first };
		const int edY{ footPrints[i + 1].second };

		MoveToEx(hdc, stX, stY, NULL);
		LineTo(hdc, edX, edY);
	}
	
}

void DrawCircle(HDC& hdc, int left, int top, int right, int bottom) {
	HBRUSH OldBrush;

	OldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));
	Ellipse(hdc, left, top, right, bottom);
	SelectObject(hdc, OldBrush);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	static int sx, sy, oldx, oldy;
	static BOOL bNowDraw{ FALSE };
	static int mod{ 0 };
	static std::vector<std::pair<int, int>> footPrints;
	HDC hdc;


	switch (iMessage) {
	case WM_LBUTTONDOWN:
		sx = LOWORD(lParam);
		sy = HIWORD(lParam);
		oldx = sx;
		oldy = sy;
		footPrints.push_back(std::make_pair(sx, sy));
		bNowDraw = TRUE;
		return 0;

	case WM_MOUSEMOVE:
		if (bNowDraw) {
			hdc = GetDC(hWnd);
			SetROP2(hdc, R2_NOT);
			switch (mod) {
			case 0: 
				DrawFreeLine(hdc, footPrints);
				footPrints.push_back(std::make_pair(LOWORD(lParam), HIWORD(lParam)));
				DrawFreeLine(hdc, footPrints);
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
			DrawFreeLine(hdc, footPrints);
			footPrints.clear();
			footPrints.resize(0);
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

