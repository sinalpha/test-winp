//#include <windows.h>
//#include <random>
//
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE g_hInst;
//LPCTSTR lpszClass = TEXT("Timer");
//
//std::uniform_int_distribution<int> uid1{ 0, 499 };
//std::uniform_int_distribution<int> uid2{ 0, 399 };
//std::uniform_int_distribution<int> colUid{ 0, 255 };
//std::default_random_engine dre;
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
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
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
//	int i;
//
//	switch (iMessage) {
//	case WM_CREATE:
//		SetTimer(hWnd, 1, 50, NULL);
//		return 0;
//
//
//	case WM_TIMER:
//		hdc = GetDC(hWnd);
//		//무한 루프로 설정하면은 안된다!
//		for (i = 0; i < 1000; ++i)
//			SetPixel(hdc, uid1(dre), uid2(dre), RGB(colUid(dre), colUid(dre), colUid(dre)));
//
//		ReleaseDC(hWnd, hdc);
//		return 0;
//
//
//	case WM_LBUTTONDOWN:
//		hdc = GetDC(hWnd);
//		Ellipse(hdc, LOWORD(lParam) - 10, HIWORD(lParam) - 10, LOWORD(lParam) + 10, HIWORD(lParam) + 10);
//		ReleaseDC(hWnd, hdc);
//		return 0;
//
//
//	case WM_DESTROY:
//		KillTimer(hWnd, 1);
//		PostQuitMessage(0);
//		return 0;
//
//
//	}
//	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
//}