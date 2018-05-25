// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"

#ifdef _X86_
extern "C" { int _afxForceUSRDLL; }
#else
extern "C" { int __afxForceUSRDLL; }
#endif 

//模块句柄
HMODULE hMainMod = NULL;
HMODULE hMod = NULL;

BOOL APIENTRY DM_ProcessAttach(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved);

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		MessageBox(0, "TEST 1", 0, 0);
		DM_ProcessAttach(hModule, ul_reason_for_call, lpReserved);
		break;
	}

	case DLL_PROCESS_DETACH:
	{
		break;
	}
	}
	return TRUE;
}


__declspec(dllexport) void backfun()
{

}
