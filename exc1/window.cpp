#include "window.h"

void Window::Init(LONG width, LONG height, HINSTANCE& instance, LPCWSTR title)
{
	// Create a new window
	Create(width, height, instance, window, title);
}
void Window::Cleanup()
{
	DestroyWindow(window);
}

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    switch (msg) {
 
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }

    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}
void Create(LONG width, LONG height, HINSTANCE& instance, HWND& window, LPCWSTR title)
{
	// Register the window class
	WNDCLASSEX wc{ sizeof(WNDCLASSEX),
	             CS_CLASSDC,
	             WndProc,
	             0L,
	             0L,
	             GetModuleHandle(NULL),
	             NULL,
	             NULL,
	             NULL,
	             NULL,
	             title, 
	             NULL };

	RegisterClassEx(&wc);
	

	// Get the desktop resolution
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	int x = (desktop.right - width) / 2;

	// Create the window
	RECT rc = { 0, 0, width, height };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	window = CreateWindow(wc.lpszClassName, title, WS_OVERLAPPEDWINDOW, x, 0, (rc.right - rc.left), (rc.bottom - rc.top), NULL, NULL, instance, NULL);;

	// Show the window
	ShowWindow(window, SW_SHOWDEFAULT);
	UpdateWindow(window);

	// Delete unnesessary data;
	UnregisterClass(wc.lpszClassName, wc.hInstance);

}

