#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Timer");


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
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	//윈도우 크기 설정은 스킵한다.
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}


void CALLBACK Draw(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
	
	static TCHAR str[128]{ TEXT("Hello!") };
	static bool flag{ true };
	static int y{ 100 };
	HDC hdc;
	
	hdc = GetDC(hWnd);
	y--;
	TextOut(hdc, 10, y, str, lstrlen(str));
	if (y <= 10) {
		KillTimer(hWnd, 1);
		SetTimer(hWnd, 1, 1000, NULL);
		y = 100;
		lstrcpy(str, (flag = !flag) ? TEXT("Hello!") : TEXT("World!"));
	}


	ReleaseDC(hWnd, hdc);
	
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	
	
	switch (iMessage) {
	case WM_CREATE:
		SetTimer(hWnd, 1, 1000, NULL);
		SendMessage(hWnd, WM_TIMER, 1, 0);
		return 0;

	case WM_TIMER:
		InvalidateRect(hWnd, NULL, TRUE);
		KillTimer(hWnd, 1);
		SetTimer(hWnd, 1, 10, Draw);
		return 0;

	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}