#include <iostream>
#include <string>
#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int CreateWindows()
{
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };
    
    HINSTANCE hInstance = nullptr;

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND handle = CreateWindowEx(
        NULL,
        CLASS_NAME,
        L"Learn to Program Windows",
        WS_OVERLAPPEDWINDOW,

        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL, 
        NULL,
        hInstance,
        NULL
    );

    if (handle == NULL)
        return 0;

    ShowWindow(handle, SW_SHOWDEFAULT);
}

int main()
{
    CreateWindows();
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}