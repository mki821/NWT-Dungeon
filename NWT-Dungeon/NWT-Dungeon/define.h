﻿#pragma once

#include <Windows.h>
#include <vector>
#include <fcntl.h>
#include<iostream>

using namespace std;

static wstring MainTitle[8] =
{
	{L"███▄▄▄▄    ▄█     █▄      ███          ████████▄  ███    █▄  ███▄▄▄▄      ▄██████▄     ▄████████  ▄██████▄  ███▄▄▄▄	 "},
	{L"███▀▀▀██▄ ███     ███ ▀█████████▄      ███   ▀███ ███    ███ ███▀▀▀██▄   ███    ███   ███    ███ ███    ███ ███▀▀▀██▄ "},
	{L"███   ███ ███     ███    ▀███▀▀██      ███    ███ ███    ███ ███   ███   ███    █▀    ███    █▀  ███    ███ ███   ███ "},
	{L"███   ███ ███     ███     ███   ▀      ███    ███ ███    ███ ███   ███  ▄███         ▄███▄▄▄     ███    ███ ███   ███ "},
	{L"███   ███ ███     ███     ███          ███    ███ ███    ███ ███   ███ ▀▀███ ████▄  ▀▀███▀▀▀     ███    ███ ███   ███ "},
	{L"███   ███ ███     ███     ███          ███    ███ ███    ███ ███   ███   ███    ███   ███    █▄  ███    ███ ███   ███ "},
	{L"███   ███ ███ ▄█▄ ███     ███          ███   ▄███ ███    ███ ███   ███   ███    ███   ███    ███ ███    ███ ███   ███ "},
	{L" ▀█   █▀   ▀███▀███▀     ▄████▀        ████████▀  ████████▀   ▀█   █▀    ████████▀    ██████████  ▀██████▀   ▀█   █▀  "}
};

static std::wstring MEN[11] = {
	{L"____"},
	{L" \\   \\"},
	{L" _\\___\\_"},
	{L"  / \" _)"},
	{L"  ((\\__ - _\\"},
	{L"   / \\\\"},
	{L"  / __|  /\\\\"},
	{L" UUU  /  /"},
	{L"   | /, _/"},
	{L"   |/|\\ | __"},
	{L"   / __\\____\\"}
};

static std::wstring TrashMobVisual[10] =
{
	{L"      ██            "},
	{L"       ███          "},
	{L"   ███████████      "},
	{L" ████████████████   "},
	{L" ██████████████████ "},
	{L"████  ████  ████████"},
	{L"████  ████  ████████"},
	{L"████████████████████"},
	{L" ██████████████████ "},
	{L"   ██████████████   "}
};

static std::wstring BEAR[14] = {
	{L"     ,-._____,-.     "},
	{L"    (_c       c_)    "},
	{L"     /  e-o-e  \\    "},
	{L"    (  (._|_,)  )    "},
	{L"     >._`---'_,<     "},
	{L"   ,'/  `---'  \\`.	"},
	{L" ,' /           \\ `."},
	{L"(  (             )  )"},
	{L" `-'\\           /`-'"},
	{L"    |`-._____.-'|    "},
	{L"    |     Y     |    "},
	{L"    /     |     \\   "},
	{L"   (      |      )   "},
	{L"    `-----^-----'    "}
};

static std::wstring CAT[14] = {
	{L" ▄▄             "},
	{L"█▀▀█     ▄   ▄  "},
	{L"█▄ █     █▄ ▄█  "},
	{L"▀▀ ██   ██████▄ "},
	{L"   █▀   ██▄█▄██ "},
	{L"   █    ██▀████ "},
	{L"  █▀ ▄▄  ██▄▄█  "},
	{L"  █▄███▄ ███▀   "},
	{L"   █████▄██     "},
	{L"    ██████      "},
	{L"  ▄█████████▄   "},
	{L" ██  █▀▀██ ▀█▄  "},
	{L"     █  ▀█  ▀█  "},
	{L"     ▀   ▀      "}
};