#include <windows.h>
#include "console.h"

void FullScreen() {
	//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	//::SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}

void GotoXY(int x, int y) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cur = { x, y };

	SetConsoleCursorPosition(hOut, cur);
}

BOOL GotoPos(int x, int y) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔창 핸들
	COORD cur = { x * 2, y }; //커서관련 구조체

	return SetConsoleCursorPosition(hOut, cur);
}

COORD CursorPosition() {
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buf);
	return buf.dwCursorPosition;
}

void CursorVisible(bool visible, DWORD size) {
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.bVisible = visible; //on, off
	curInfo.dwSize = size; //커서굵기

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void SetColor(int textColor, int bgColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | textColor);
}

int GetColor() {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

	int color = info.wAttributes & 0xf;

	return color;
}

void LockResize() {
	HWND console = GetConsoleWindow();

	if (console != nullptr) {
		LONG style = GetWindowLong(console, GWL_STYLE);
		style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX;

		SetWindowLong(console, GWL_STYLE, style);
	}
}

COORD GetConsoleResolution()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

	short width = info.srWindow.Right - info.srWindow.Left + 1;
	short height = info.srWindow.Bottom - info.srWindow.Top + 1;

	return COORD{ width, height };
}

void SetFontSize(UINT weight, UINT fontX, UINT fontY) {
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	GetCurrentConsoleFontEx(hOut, false, &font);
	font.FontWeight = weight;
	font.dwFontSize.X = fontX;
	font.dwFontSize.Y = fontY;

	SetCurrentConsoleFontEx(hOut, false, &font);
}
