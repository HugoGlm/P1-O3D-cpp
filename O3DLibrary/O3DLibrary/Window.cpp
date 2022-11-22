#include "Window.h"
#include "WindowMenu.h"

#pragma region constructor
Core::Window::Window(const PrimitiveType::FString& _name, const int _width, const int _height)
{
	name = _name;
	width = _width;
	height = _height;

	const LPCWSTR _className = L"Default Window";
	HINSTANCE _instance = HINSTANCE();
	WNDCLASS _wndClass = {};
	_wndClass.lpszClassName = _className;
	_wndClass.hInstance = _instance;
	//TODO Window Proc
	_wndClass.lpfnWndProc = WindowProc_Internal;
	_wndClass.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	_wndClass.hCursor = LoadCursor(_instance, IDC_HAND);
	RegisterClass(&_wndClass);

	windowInstance = CreateWindowEx(0, _className, _name.ToWString().c_str(),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZE, CW_USEDEFAULT, CW_USEDEFAULT,
		width, height, nullptr, nullptr, _instance, this);
	CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"CLICK !", WS_CHILD | WS_VISIBLE | WS_BORDER, 
		100, 20, 140, 20, windowInstance, NULL, NULL, NULL);
}
Core::Window::~Window()
{
	for (std::pair<const char*, WindowMenu*> _p : menus)
		delete _p.second;
	menus.clear();
	delete windowInstance;
}
#pragma endregion

#pragma region methods
LRESULT __stdcall Core::Window::windowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rc;
	POINT draw[5] = { 125, 25, 150, 25, 150, 50, 150, 25, 125, 25 };

	if (_hWindow == nullptr)
		return 0;
	switch (_msg)
	{
	case WM_PAINT:
		hdc = BeginPaint(_hWindow, &ps);
		GetClientRect(_hWindow, &rc);
		SetMapMode(hdc, MM_ANISOTROPIC);
		SetWindowExtEx(hdc, 100, 100, NULL);
		SetViewportExtEx(hdc, rc.right, rc.bottom, NULL);
		Polyline(hdc, draw, 5);
		EndPaint(_hWindow, &ps);
		return 0;
		break;
	case WM_CREATE:
		AddMenu(_hWindow);
		break;
	case WM_DESTROY:
	{
		Close();
		break;
	}
	default:
		return DefWindowProcW(_hWindow, _msg, _wp, _lp);
	}
}
LRESULT __stdcall Core::Window::WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	if (_msg == WM_NCCREATE)
	{
		SetWindowLongPtr(_hWindow, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(reinterpret_cast<CREATESTRUCT*>(_lp)->lpCreateParams));
		return true;
	}
	return reinterpret_cast<Window*>(GetWindowLongPtr(_hWindow, GWLP_USERDATA))->windowProc(_hWindow, _msg, _wp, _lp);
}
void Core::Window::Update()
{
	MSG _msg = {};
	while (isOpen)
	{
		while (PeekMessage(&_msg, windowInstance, 0, 0, PM_REMOVE));
		{
			if (!TranslateAccelerator(_msg.hwnd, nullptr, &_msg))
			{
				TranslateMessage(&_msg);
				DispatchMessage(&_msg);
			}
		}
	}
}
void Core::Window::AddMenu(HWND _hwnd)
{
	const WindowMenu* _menu = CreateWindowMenu("");
	WindowMenu* _fileMenu = CreateWindowMenu("File");
	WindowMenu* _newMenu = CreateWindowMenu("New");
	WindowMenu* _editMenu = CreateWindowMenu("Edit");
	_editMenu->CreateButtonMenu("Copy");
	_newMenu->CreateButtonMenu("Project");
	_fileMenu->CreatePopupMenu(_newMenu);
	_fileMenu->CreateButtonMenu("Close");
	_menu->CreatePopupMenu(_fileMenu);
	_menu->CreatePopupMenu(_editMenu);
	SetMenu(_hwnd, *_menu);
}
Core::WindowMenu* Core::Window::CreateWindowMenu(const char* _name)
{
	WindowMenu* _menu = new WindowMenu(this, _name);
	menus.insert(std::pair<const char*, WindowMenu*>(_name, _menu));
	return _menu;
}
int Core::Window::MenuCount() const
{
	return menus.size();
}
void Core::Window::RegisterMenu(WindowMenu* _menu)
{
	menus.insert(std::pair<const char*, WindowMenu*>(_menu->Name(), _menu));
}
void Core::Window::Open()
{
	if (windowInstance == nullptr)
		return;
	isOpen = true;
	ShowWindow(windowInstance, SW_SHOWDEFAULT);
	UpdateWindow(windowInstance);
	Update();
}
void Core::Window::Close()
{
	CloseWindow(windowInstance);
	isOpen = false;
}
#pragma endregion


