#pragma once
#include "Define.h"	

void FullScreen();
void GotoXY(int x, int y);
BOOL GotoPos(int x, int y);				
COORD CursorPosition();		
void CursorVisible(bool visible, DWORD size);						
void SetColor(int textColor = 15, int bgColor = 0);
int GetColor();
void LockResize();
COORD GetConsoleResolution();		
void SetFontSize(UINT weight, UINT fontX, UINT fontY);				
enum class Color {
	Black, Blue, Green, Skyblue,
	Red, Violet, Yellow, LightGray,
	Gray, LightBlue, LightGreen, Mint,
	LightRed, LightViolet, LightYellow, White, End
};
using std::cout;
using std::wcout;
using std::endl;	