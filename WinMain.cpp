#include <Windows.h>
//#include "WindowsMessageMap.h"
#include <sstream>
#define UNICODE
#define _UNICODE

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{
	//static WindowsMessageMap mm;
	//std::string str = mm(msg, lParam, wParam).c_str();
	// Initializing an object of wstring
	//std::wstring temp = std::wstring(str.begin(), str.end());
	// Applying c_str() method on temp
	//LPCWSTR wideString = temp.c_str();
	//OutputDebugString(wideString);
	
	switch (msg)
	{
		case WM_CLOSE:
			PostQuitMessage(1300135);
			break;

		case WM_KEYDOWN:
			if (wParam == 'F') {
				SetWindowText(hWnd, "I don't show up ever, Something is wrong.");
			}
			break;
		case WM_KEYUP:
			if (wParam == 'F') {
				SetWindowText(hWnd, "Stop Pressing F");
			}
			break;
		case WM_CHAR:
		{
			static std::string title;
			title.push_back((char)wParam);
			SetWindowText(hWnd, title.c_str());
		}
		break;
		case WM_LBUTTONDOWN:
		{
			POINTS pt = MAKEPOINTS(lParam);
			std::ostringstream oss;
			oss << "Horizontalla de la : " << pt.x << ", sohite Vertical moshikashite : " << pt.y;
			SetWindowText(hWnd, oss.str().c_str());
		}
	}

	
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	const auto pClassName = "WindowsMyLover";
	// register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);
	// create window instance
	HWND hWnd = CreateWindowEx(
		0, pClassName,
		"Welcome to Depression",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr
	);
	// show the damn window
	ShowWindow(hWnd, SW_SHOW);
	//while (true);
	//return 0;

	//message 
	MSG msg;
	BOOL gresult;

	while ( (gresult = GetMessage(&msg, nullptr, 0, 0)) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gresult == -1) {
		return -1;
	}
	else {
		return msg.wParam;
	}
	return 0;
}