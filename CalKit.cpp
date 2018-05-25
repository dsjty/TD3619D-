#include "stdafx.h"
#include "CalKit.h"

CalKit::CalKit()
{	
	CalKitList[0] = L"TD1033E";
	CalKitList[1] = L"TD1033D";
	CalKitList[2] = L"TD1052D";
	CalKitList[3] = L"TD1032F";
	CalKitList[4] = L"TD1032B/E";
	CalKitList[5] = L"TD1036B/E";
	CalKitList[6] = L"TD1039B";
	CalKitList[7] = L"TD1038A/F/M";
	CalKitList[8] = L"User";
	CalKitList[9] = L"User";

	NewCalKitList[0] = L"TD1033E";
	NewCalKitList[1] = L"TD1033D";
	NewCalKitList[2] = L"TD1052D";
	NewCalKitList[3] = L"TD1032F";
	NewCalKitList[4] = L"TD1032B/E";
	NewCalKitList[5] = L"TD1036B/E";
	NewCalKitList[6] = L"TD1039B";
	NewCalKitList[7] = L"TD1038A/F/M";
	NewCalKitList[8] = L"User";
	NewCalKitList[9] = L"User";

	OldCalKitList[0] = L"85033E";
	OldCalKitList[1] = L"85033D";
	OldCalKitList[2] = L"85052D";
	OldCalKitList[3] = L"85032F";
	OldCalKitList[4] = L"85032B/E";
	OldCalKitList[5] = L"85036B/E";
	OldCalKitList[6] = L"85039B";
	OldCalKitList[7] = L"85038A/F/M";
	OldCalKitList[8] = L"User";
	OldCalKitList[9] = L"User";
}

CalKit::~CalKit()
{
}

CALKITOBJ CalKit::GetCalKitName(int id)
{
	//要不然这里就做一个用处 就是hook住0x519D60  外面也不做处理!直接读取类元素;
	return stCalKitObj;
}

bool CalKit::SetCalKitName(LPCSTR name, int id)
{
	WCHAR pBuffer[100] = { 0 };
	MultiByteToWideChar(CP_ACP, 0, name, -1, pBuffer, sizeof(WCHAR) * 100);
	for (int i = 0; i < 10; i++)
	{
		if (0 == wcscmp(pBuffer, OldCalKitList[i].c_str()))
		{
			wcscpy_s(pBuffer, NewCalKitList[i].c_str());
			break;
		}
	}
	CalKitList[id] = pBuffer;
	return true;
}

CalKit cCalkit;


//************************************
// 函数名:    GetCalKitName
// Access:    public 
// 返回值类型:   NAKED CALKITOBJ
// 说明: hook校准件循环信息以更新新UI校准件名信息
//************************************
NAKED CALKITOBJ GetCalKitName()
{
	DWORD CalName;
	int id;

	__asm push ebp
	__asm mov ebp,esp
	__asm sub esp,0x20
	__asm push eax
	__asm push ecx
	__asm push edx
	__asm push ebx
	__asm push esp
	__asm push ebp

	__asm mov CalName, eax
	__asm mov id,esi
	cCalkit.SetCalKitName((LPCSTR)((PCALKITOBJ)CalName)->dwObjNameAdd, id);

	__asm pop ebp
	__asm pop esp
	__asm pop ebx
	__asm pop edx
	__asm pop ecx
	__asm pop eax

	__asm add esp,0x20
	__asm pop ebp

	__asm mov eax, [eax + 4]
	__asm retn 0x8
}

