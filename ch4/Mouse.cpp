//#include <windows.h>
//
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE g_hInst;
//LPCTSTR lpszClass = TEXT("Move");
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
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hInstance = hInstance;
//	WndClass.lpfnWndProc = WndProc;
//	WndClass.lpszClassName = lpszClass;
//	WndClass.lpszMenuName = NULL;
//	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
//	RegisterClass(&WndClass);
//
//	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
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
//	static int x;
//	static int y;
//	static bool isMoving{ false };
//
//	switch (iMessage) {
//	case WM_LBUTTONDOWN:
//		x = LOWORD(lParam);
//		y = HIWORD(lParam);
//		isMoving = true;
//		return 0;
//	
//	case WM_LBUTTONUP:
//		isMoving = false;
//		return 0;
//	
//	case WM_MOUSEMOVE:
//		if (true == isMoving) {
//			hdc = GetDC(hWnd);
//			MoveToEx(hdc, x, y, NULL);
//			x = LOWORD(lParam);
//			y = HIWORD(lParam);
//			LineTo(hdc, x, y);
//			ReleaseDC(hWnd, hdc);
//		}
//		return 0;
//
//	case WM_LBUTTONDBLCLK:
//		InvalidateRect(hWnd, NULL, TRUE);
//		return 0;
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;		
//	}
//	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
//}