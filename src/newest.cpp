//#include <windows.h>
//
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//
//int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//    LPSTR lpszCmdParam, int nCmdShow)
//{
//	
//    const int width = 1280, height = 960;
//	
//    WNDCLASSEX wc = { sizeof(WNDCLASSEX),
//                 CS_CLASSDC,
//                 WndProc,
//                 0L,
//                 0L,
//                 GetModuleHandle(NULL),
//                 NULL,
//                 NULL,
//                 NULL,
//                 NULL,
//                 L"newest", 
//                 NULL };
//
//	RegisterClassEx(&wc);
//
//    RECT wr = { 0, 0, width, height };
//    AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);
//
//    HWND hwnd = CreateWindow(wc.lpszClassName, L"newest",
//        WS_OVERLAPPEDWINDOW,
//        100, 
//        100, 
//        wr.right - wr.left, 
//        wr.bottom - wr.top, 
//        NULL, NULL, wc.hInstance, NULL);
//    
//    ShowWindow(hwnd, SW_SHOWDEFAULT);
//    UpdateWindow(hwnd);
//
//    MSG msg = {};
//    while (WM_QUIT != msg.message) {
//        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
//            TranslateMessage(&msg);
//            DispatchMessage(&msg);
//        }
//    }
//
//    DestroyWindow(hwnd);
//    UnregisterClass(wc.lpszClassName, wc.hInstance);
//
//    return 0;
//}
//
//LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
//
//    switch (msg) {
// 
//    case WM_DESTROY:
//        ::PostQuitMessage(0);
//        return 0;
//    }
//
//    return ::DefWindowProc(hWnd, msg, wParam, lParam);
//}
