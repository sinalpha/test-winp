//#include <windows.h>
//
//#include "../utility/include/myPrint.h"
//
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE g_hInst;
//LPCTSTR lpszClass = TEXT("TextOut");
//
//int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
//	, LPSTR lpszCmdParam, int nCmdShow)
//{
//	HWND hWnd;
//	MSG Message;
//	WNDCLASS WndClass;
//	g_hInst = hInstance;
//
//	WndClass.cbClsExtra = 0;
//	WndClass.cbWndExtra = 0;
//	WndClass.hbrBackground = CreateHatchBrush(HS_DIAGCROSS, RGB(0, 0, 255));
//	WndClass.hCursor = LoadCursor(NULL, IDC_WAIT);
//	WndClass.hIcon = LoadIcon(NULL, IDI_QUESTION);
//	WndClass.hInstance = hInstance;
//	WndClass.lpfnWndProc = WndProc;
//	WndClass.lpszClassName = lpszClass;
//	WndClass.lpszMenuName = NULL;
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	RegisterClass(&WndClass);
//
//	hWnd = CreateWindow(lpszClass, TEXT("My First Program"), WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL,
//		0, 0, 1000, 1000,
//		NULL, (HMENU)NULL, hInstance, NULL);
//	ShowWindow(hWnd, nCmdShow);
//
//	while (GetMessage(&Message, NULL, 0, 0)) {
//		TranslateMessage(&Message);
//		DispatchMessage(&Message);
//	}
//	return (int)Message.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//	const TCHAR *str = TEXT("Hello");
//
//	switch (iMessage) {
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		SetTextAlign(hdc, TA_UPDATECP);
//		TextOut(hdc, 200, 60, TEXT("Beautiful Korea"), 15);
//		TextOut(hdc, 200, 80, TEXT("is My"), 5);
//		TextOut(hdc, 200, 100, TEXT("Lovely Home Country"), 19);
//		
//		TCHAR str[100];
//		my::myWsprintf(str, 100);
//		TextOut(hdc, 10, 10, str, lstrlen(str));
//		
//		EndPaint(hWnd, &ps);
//		return 0;
//	}
//
//	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
//}
//
