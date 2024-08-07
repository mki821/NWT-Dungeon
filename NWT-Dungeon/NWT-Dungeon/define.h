﻿#pragma once

#include <Windows.h>
#include <vector>
#include <fcntl.h>
#include<iostream>
#include<ctime>

using std::string;
using std::wstring;
using std::vector;

static wstring MainTitle[3][8] = {
	{
		{L"███▄▄▄▄    ▄█     █▄      ███          ████████▄  ███    █▄  ███▄▄▄▄      ▄██████▄     ▄████████  ▄██████▄  ███▄▄▄▄	"},
		{L"███▀▀▀██▄ ███     ███ ▀█████████▄      ███   ▀███ ███    ███ ███▀▀▀██▄   ███    ███   ███    ███ ███    ███ ███▀▀▀██▄"},
		{L"███   ███ ███     ███    ▀███▀▀██      ███    ███ ███    ███ ███   ███   ███    █▀    ███    █▀  ███    ███ ███   ███"},
		{L"███   ███ ███     ███     ███   ▀      ███    ███ ███    ███ ███   ███  ▄███         ▄███▄▄▄     ███    ███ ███   ███"},
		{L"███   ███ ███     ███     ███          ███    ███ ███    ███ ███   ███ ▀▀███ ████▄  ▀▀███▀▀▀     ███    ███ ███   ███"},
		{L"███   ███ ███     ███     ███          ███    ███ ███    ███ ███   ███   ███    ███   ███    █▄  ███    ███ ███   ███"},
		{L"███   ███ ███ ▄█▄ ███     ███          ███   ▄███ ███    ███ ███   ███   ███    ███   ███    ███ ███    ███ ███   ███"},
		{L" ▀█   █▀   ▀███▀███▀     ▄████▀        ████████▀  ████████▀   ▀█   █▀    ████████▀    ██████████  ▀██████▀   ▀█   █▀ "}
	},
	{
		{L"   ▄██████▄    ▄▄▄▄███▄▄▄▄      ▄████████    ▄████████       ▄████████  ▄█          ▄████████    ▄████████    ▄████████"},
		{L"  ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███   ███    ███      ███    ███ ███         ███    ███   ███    ███   ███    ███"},
		{L"  ███    █▀  ███   ███   ███   ███    ███   ███    █▀       ███    █▀  ███         ███    █▀    ███    ███   ███    ███"},
		{L" ▄███        ███   ███   ███   ███    ███  ▄███▄▄▄          ███        ███        ▄███▄▄▄       ███    ███  ▄███▄▄▄▄██▀"},
		{L"▀▀███ ████▄  ███   ███   ███ ▀███████████ ▀▀███▀▀▀          ███        ███       ▀▀███▀▀▀     ▀███████████ ▀▀███▀▀▀▀▀  "},
		{L"  ███    ███ ███   ███   ███   ███    ███   ███    █▄       ███    █▄  ███         ███    █▄    ███    ███ ▀███████████"},
		{L"  ███    ███ ███   ███   ███   ███    ███   ███    ███      ███    ███ ███▌    ▄   ███    ███   ███    ███   ███    ███"},
		{L"  ████████▀   ▀█   ███   █▀    ███    █▀    ██████████      ████████▀  █████▄▄██   ██████████   ███    █▀    ███    ███"}
	},
	{
		{L"   ▄██████▄    ▄▄▄▄███▄▄▄▄      ▄████████    ▄████████       ▄██████▄   ▄█    █▄     ▄████████    ▄████████"},
		{L"  ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███   ███    ███      ███    ███ ███    ███   ███    ███   ███    ███"},
		{L"  ███    █▀  ███   ███   ███   ███    ███   ███    █▀       ███    ███ ███    ███   ███    █▀    ███    ███"},
		{L" ▄███        ███   ███   ███   ███    ███  ▄███▄▄▄          ███    ███ ███    ███  ▄███▄▄▄      ▄███▄▄▄▄██▀"},
		{L"▀▀███ ████▄  ███   ███   ███ ▀███████████ ▀▀███▀▀▀          ███    ███ ███    ███ ▀▀███▀▀▀     ▀▀███▀▀▀▀▀  "},
		{L"  ███    ███ ███   ███   ███   ███    ███   ███    █▄       ███    ███ ███    ███   ███    █▄  ▀███████████"},
		{L"  ███    ███ ███   ███   ███   ███    ███   ███    ███      ███    ███ ███    ███   ███    ███   ███    ███"},
		{L"  ████████▀   ▀█   ███   █▀    ███    █▀    ██████████       ▀██████▀   ▀██████▀    ██████████   ███    ███"},
	}
};

static wstring MEN[11] = {
	{L"____               "},
	{L" \\   \\           "},
	{L" _\\___\\_         "},
	{L"  / \" _)          "},
	{L"  ((\\__ - _\\     "},
	{L"   / \\\\          "},
	{L"  / __|  /\\\\     "},
	{L" UUU  /  /         "},
	{L"   | /, _/         "},
	{L"   |/|\\ | __      "},
	{L"   / __\\____\\    "}
}; 

static vector<wstring> MEN_ATTACK[11] = {
	{
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
	},
	{
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
	},
	{
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
	},
	{
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
	},
	{
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
	}
};

static std::wstring TrashMobVisual[3][10] = {
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
	},
	{
		{L"  █  ║   █          "},
		{L" ██ ███  ██         "},
		{L"███ ╬█╬ ████        "},
		{L"████╦█╦█████        "},
		{L"████████████        "},
		{L"██  █ █   ██        "},
		{L" █        █         "},
		{L"                    "},
		{L"                    "},
		{L"                    "}
	},
	{
		{L" ██   ███  ███      "},
		{L"██████████████      "},
		{L" █████ █ █████      "},
		{L"  ████ █ ████       "},
		{L"   █████████        "},
		{L"   ███   ███        "},
		{L"  ████   ██         "},
		{L"  █████████         "},
		{L" ██████ ████        "},
		{L"  ███    ████       "}
	}
};

static std::wstring BossSword[15] =
{
	{L"      ▄██▄      "},
	{L"     █╬╬╬╬█     "},
	{L"     █╬╬╬╬█     "},
	{L"     █╬╬╬╬█     "},
	{L"     █╬╬╬╬█     "},
	{L"     █╬╬╬╬█     "},
	{L"     █╬╬╬╬█     "},
	{L"     █╬╬╬╬█     "},
	{L"     █╬╬╬╬█     "},
	{L" █   █╬╬╬╬█   █ "},
	{L"█╬████╬╬╬╬████╬█"},
	{L" █   ▀█▄▄█▀   █ "},
	{L"       ██       "},
	{L"       ██       "},
	{L"       ╩╩       "}
};

static wstring BEAR[16] = {
	{L"                     "},
	{L"                     "},
	{L"     ,-._____,-.     "},
	{L"    (_c       c_)    "},
	{L"     /  e-o-e  \\     "},
	{L"    (  (._|_,)  )    "},
	{L"     >._`---'_,<     "},
	{L"   ,'/  `---'  \\`.   "},
	{L" ,' /           \\ `.   "},
	{L"(  (             ) ) "},
	{L" `-'\\           /`-'   "},
	{L"    |`-._____.-'|     "},
	{L"    |     Y     |    "},
	{L"    /     |     \\    "},
	{L"   (      |      )   "},
	{L"    `-----^-----'    "}
};

static vector<wstring> BEAR_ATTACK[5] = {
	{
		{L"                     "},
		{L"                     "},
		{L"     ,-._____,-.     "},
		{L"    (_c       c_)    "},
		{L"     /  e-o-e  \\     "},
		{L"    (  (._|_,)  )    "},
		{L"     >._`---'_,<     "},
		{L"   ,'/  `---'  \\`.   "},
		{L" ,' /           \\ `. "},
		{L"(  (             ) )"},
		{L" `-'\\           /`-' "},
		{L"    |`-._____.-'|    "},
		{L"    |     Y     |    "},
		{L"    /     |     \\    "},
		{L"   (      |      )   "},
		{L"    `-----^-----'    "}
	},
	{
		{L"                     "},
		{L"     ,-._____,-.     "},
		{L"    (_c       c_)    "},
		{L"     /  e-o-e  \\     "},
		{L"    (  (._|_,)  )    "},
		{L"     >._`---'_,<     "},
		{L"   ,'/  `---'  \\`.   "},
		{L" ,' /           \\ `. "},
		{L"(  (             ) )"},
		{L" `-'\\           /`-' "},
		{L"    |`-._____.-'|    "},
		{L"    |     Y     |    "},
		{L"    /     |     \\    "},
		{L"   (      |      )   "},
		{L"    `-----^-----'    "},
		{L"                     "}
	},
	{
		{L"     ,-._____,-.     "},
		{L"    (_c       c_)    "},
		{L"     /  e-o-e  \\     "},
		{L"    (  (._|_,)  )    "},
		{L"     >._`---'_,<     "},
		{L"   ,'/  `---'  \\`.   "},
		{L" ,' /           \\ `. "},
		{L"(  (             ) )"},
		{L" `-'\\           /`-' "},
		{L"    |`-._____.-'|    "},
		{L"    |     Y     |    "},
		{L"    /     |     \\    "},
		{L"   (      |      )   "},
		{L"    `-----^-----'    "},
		{L"                     "},
		{L"                     "}
	},
	{
		{L"                     "},
		{L"     ,-._____,-.     "},
		{L"    (_c       c_)    "},
		{L"     /  e-o-e  \\     "},
		{L"    (  (._|_,)  )    "},
		{L"     >._`---'_,<     "},
		{L"   ,'/  `---'  \\`.   "},
		{L" ,' /           \\ `. "},
		{L"(  (             ) )"},
		{L" `-'\\           /`-' "},
		{L"    |`-._____.-'|    "},
		{L"    |     Y     |    "},
		{L"    /     |     \\    "},
		{L"   (      |      )   "},
		{L"    `-----^-----'    "},
		{L"                     "}
	},
	{
		{L"                     "},
		{L"                     "},
		{L"     ,-._____,-.     "},
		{L"    (_c       c_)    "},
		{L"     /  e-o-e  \\     "},
		{L"    (  (._|_,)  )    "},
		{L"     >._`---'_,<     "},
		{L"   ,'/  `---'  \\`.   "},
		{L" ,' /           \\ `.  "},
		{L"(  (             ) )"},
		{L" `-'\\           /`-'  "},
		{L"    |`-._____.-'|    "},
		{L"    |     Y     |    "},
		{L"    /     |     \\    "},
		{L"   (      |      )   "},
		{L"    `-----^-----' "}
	}
};

static wstring CAT[14] = {
	{L"    ▄▄                "},
	{L"   █▀▀█     ▄   ▄     "},
	{L"   █▄ █     █▄ ▄█     "},
	{L"   ▀▀ ██   ██████▄    "},
	{L"      █▀   ██▄█▄██    "},
	{L"      █    ██▀████    "},
	{L"     █▀ ▄▄  ██▄▄█     "},
	{L"     █▄███▄ ███▀      "},
	{L"      █████▄██        "},
	{L"       ██████         "},
	{L"     ▄█████████▄      "},
	{L"    ██  █▀▀██ ▀█▄     "},
	{L"        █  ▀█  ▀█     "},
	{L"        ▀   ▀         "}
};

static vector<wstring> CAT_ATTACK[5] = {
	{
		{L"    ▄▄                "},
		{L"   █▀▀█     ▄   ▄     "},
		{L"   █▄ █     █▄ ▄█     "},
		{L"   ▀▀ ██   ██████▄    "},
		{L"      █▀   ██▄█▄██    "},
		{L"      █    ██▀████    "},
		{L"     █▀ ▄▄  ██▄▄█     "},
		{L"     █▄███▄ ███▀      "},
		{L"      █████▄██        "},
		{L"       ██████         "},
		{L"     ▄█████████▄      "},
		{L"    ██  █▀▀██ ▀█▄     "},
		{L"        █  ▀█  ▀█     "},
		{L"        ▀   ▀         "}
	},		   			      
	{		   			      
		{L"    ▄▄                "},
		{L"   █▀▀█     ▄   ▄     "},
		{L"   █▄ █     █▄ ▄█     "},
		{L"   ▀▀ ██   ██████▄    "},
		{L"      █▀   ██▄█▄██    "},
		{L"      █    ██▀████    "},
		{L"     █▀ ▄▄  ██▄▄█     "},
		{L"     █▄███▄ ███▀      "},
		{L"      █████▄██        "},
		{L"       ██████         "},
		{L"     ▄█████████▄▄     "},
		{L"    ██  █▀▀██  ▀█     "},
		{L"        █  ▀█     "   },
		{L"        ▀   ▀         "}
	},		   			      
	{		   			      
		{L"    ▄▄                "},
		{L"   █▀▀█     ▄   ▄     "},
		{L"   █▄ █     █▄ ▄█     "},
		{L"   ▀▀ ██   ██████▄    "},
		{L"      █▀   ██▄█▄██    "},
		{L"      █    ██▀████    "},
		{L"     █▀ ▄▄  ██▄▄█     "},
		{L"     █▄███▄ ███▀      "},
		{L"      █████▄██        "},
		{L"       ██████  ▄█     "},
		{L"     ▄████████▄██     "},
		{L"    ██  █▀▀██  ▀      "},
		{L"        █  ▀█         "},
		{L"        ▀   ▀         "}
	},		   			      
	{		   			      
		{L"    ▄▄                "},
		{L"   █▀▀█     ▄   ▄     "},
		{L"   █▄ █     █▄ ▄█     "},
		{L"   ▀▀ ██   ██████▄    "},
		{L"      █▀   ██▄█▄██    "},
		{L"      █    ██▀████    "},
		{L"     █▀ ▄▄  ██▄▄█     "},
		{L"     █▄███▄ ███▀      "},
		{L"      █████▄██        "},
		{L"       ██████         "},
		{L"     ▄█████████▄▄     "},
		{L"    ██  █▀▀██  ▀█     "},
		{L"        █  ▀█         "},
		{L"        ▀   ▀         "}
	},		   			      
	{		   			      
		{L"    ▄▄                "},
		{L"   █▀▀█     ▄   ▄     "},
		{L"   █▄ █     █▄ ▄█     "},
		{L"   ▀▀ ██   ██████▄    "},
		{L"      █▀   ██▄█▄██    "},
		{L"      █    ██▀████    "},
		{L"     █▀ ▄▄  ██▄▄█     "},
		{L"     █▄███▄ ███▀      "},
		{L"      █████▄██        "},
		{L"       ██████         "},
		{L"     ▄█████████▄      "},
		{L"    ██  █▀▀██ ▀█▄     "},
		{L"        █  ▀█  ▀█     "},
		{L"        ▀   ▀         "}
	}
};

static string STAGE[8] = {
	{"  /$$$$$$  /$$$$$$$$ /$$$$$$   /$$$$$$  /$$$$$$$$         "},
	{" /$$__  $$|__  $$__//$$__  $$ /$$__  $$| $$_____/         "}, 
	{"| $$  \\__/   | $$  | $$  \\ $$| $$  \\__/| $$       /$$  "},
	{"|  $$$$$$    | $$  | $$$$$$$$| $$ /$$$$| $$$$$   |__/     "},
	{" \\____  $$   | $$  | $$__  $$| $$|_  $$| $$__/           "},
	{" /$$  \\ $$   | $$  | $$  | $$| $$  \\ $$| $$       /$$   "},
	{"|  $$$$$$/   | $$  | $$  | $$|  $$$$$$/| $$$$$$$$|__/     "},
	{" \\______/    |__/  |__/  |__/ \\______/ |________/       "}
};

static string NUM[10][8] = {
	{
		{"  /$$$$$$ "},
		{" /$$$_  $$"},
		{"| $$$$\\ $$"},
		{"| $$ $$ $$"},
		{"| $$\\ $$$$"},
		{"| $$ \\ $$$"},
		{"|  $$$$$$/"},
		{" \\______/ "}
	},
	{
		{"    /$$  "},
		{"  /$$$$  "},
		{" |_  $$  "},
		{"   | $$  "},
		{"   | $$  "},
		{"   | $$  "},
		{"  /$$$$$$"},
		{" |______/"}
	},
	{
		{"  /$$$$$$ "},
		{" /$$__  $$"},
		{"|__/  \\ $$"},
		{"  /$$$$$$/"},
		{" /$$____/ "},
		{"| $$      "},
		{"| $$$$$$$$"},
		{"|________/"}
	},
	{
		{"  /$$$$$$ "},
		{" /$$__  $$"},
		{"|__/  \\ $$"},
		{"   /$$$$$/"},
		{"  |___  $$"},
		{" /$$  \\ $$"},
		{"|  $$$$$$/"},
		{" \\______/ "}
	},
	{
		{" /$$   /$$"},
		{"| $$  | $$"},
		{"| $$  | $$"},
		{"| $$$$$$$$"},
		{"|_____  $$"},
		{"      | $$"},
		{"      | $$"},
		{"      |__/"}
	},
	{
		{" /$$$$$$$ "},
		{"| $$____/ "},
		{"| $$      "},
		{"| $$$$$$$ "},
		{"|_____  $$"},
		{" /$$  \\ $$"},
		{"|  $$$$$$/"},
		{" \\______/ "}
	},
	{
		{"  /$$$$$$ "},
		{" /$$__  $$"},
		{"| $$  \\__/"},
		{"| $$$$$$$ "},
		{"| $$__  $$"},
		{"| $$  \\ $$"},
		{"|  $$$$$$/"},
		{" \\______/ "}
	},
	{
		{" /$$$$$$$$"},
		{"|_____ $$/"},
		{"     /$$/ "},
		{"    /$$/  "},
		{"   /$$/   "},
		{"  /$$/    "},
		{" /$$/     "},
		{"|__/      "}
	},
	{
		{"  /$$$$$$ "},
		{" /$$__  $$"},
		{"| $$  \\ $$"},
		{"|  $$$$$$/"},
		{" >$$__  $$"},
		{"| $$  \\ $$"},
		{"|  $$$$$$/"},
		{" \\______/ "}
	},
	{
		{"  /$$$$$$ "},
		{" /$$__  $$"},
		{"| $$  \\ $$"},
		{"|  $$$$$$$"},
		{" \\____  $$"},
		{" /$$  \\ $$"},
		{"|  $$$$$$/"},
		{" \\______/ "}
	}                                   
};
