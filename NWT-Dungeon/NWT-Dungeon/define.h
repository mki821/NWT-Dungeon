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
	{L"  / \" _\)"},
	{L"  ((\\__ - _\\"},
	{L"   / \\\\"},
	{L"  / __|  /\\\\"},
	{L" UUU  /  /"},
	{L"   | /, _/"},
	{L"   |/|\\ | __"},
	{L"   / __\\____\\"}
};

static wstring TrashMobVisual[10] =
{
	{L"       ██              "},
	{L"	     ████			 "},
	{L"	  ████████████		 "},
	{L"  ████████████████	 "},
	{L"  ██████████████████	 "},
	{L" ████  ████  ████████ "},
	{L" ████  ████  ████████ "},
	{L" ████████████████████ "},
	{L"  ██████████████████	 "},
	{L"	   ██████████████	 "}
};