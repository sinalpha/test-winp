#include <windows.h>

class Window
{
public:
	void Init(LONG, LONG, HINSTANCE&, LPCWSTR);
	void Cleanup();

private:
	HWND window;
};

LRESULT WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);
void Create(LONG , LONG , HINSTANCE& , HWND& , LPCWSTR );
