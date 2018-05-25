#include "stdafx.h"

/*
本文件包含来自于E5062.exe中函数调用的逆向结果及再工程函数
*/


int OrigSoftMenu_Enter(void *lpThis)
{
	if (lpThis == NULL) 
		return -1;

	void *lpVTable = *(void **)lpThis;

	if (lpVTable == NULL) 
		return -2;

	return DirectCall(lpThis, GetOffsetPointer(lpVTable, 0x18));
}

int OrigSoftMenu_Leave(void *lpThis)
{
	if (lpThis == NULL) 
		return -1;

	void *lpVTable = *(void **)lpThis;

	if (lpVTable == NULL) 
		return -2;

	return DirectCall(lpThis, GetOffsetPointer(lpVTable, 0x1C));
}

void OrigSoftMenu_ClearItems(void *lpThis)
{
	if (lpThis)
	{
		typedef void(__thiscall * fnClearItem)(void *lpThis);

		fnClearItem fnCI = (fnClearItem)0x00926430;

		fnCI(lpThis);
	}

	return;
}

int OrigSoftMenu_UpdateItems(void *lpThis)
{
	if (lpThis == NULL) 
		return -1;

	typedef void(__thiscall * fnClearItem)(void *lpThis);

	fnClearItem fnCI = (fnClearItem)0x00926430;
	void *lpVTable = *(void **)lpThis;

	fnCI(lpThis);

	if (lpVTable == NULL) 
		return -2;

	return DirectCall(lpThis, GetOffsetPointer(lpVTable, 0x08));   //刷新菜单控件
}

int OrigSoftMenu_ItemClicked(void *lpThis, int nItemIndex)
{
	if (lpThis == NULL) 
		return -1;

	void *lpVTable = *(void **)lpThis;

	if (lpVTable == NULL) 
		return -2;

	return DirectCall_2(lpThis, GetOffsetPointer(lpVTable, 0x0C), nItemIndex);
}

int OrigSoftMenu_ItemClicked2(void *lpThis, void *lpOptVTable, int nItemIndex)
{
	if (lpThis == NULL) 
		return -1;

	void *lpVTable = *(void **)lpThis;

	if (lpVTable == NULL)
	{
		lpVTable = lpOptVTable;

		if (lpVTable == NULL) 
			return -2;
	}

	return DirectCall_2(lpThis, GetOffsetPointer(lpVTable, 0x0C), nItemIndex);
}

int OrigSoftMenu_GetItemState(void *lpThis, int nIndex, LPBOOL lpblEnable, LPBOOL lpblCheck, LPBOOL lpblRadio)
{
	typedef int(__thiscall * fnGetButtonState)(void *lpThis, int nIndex, DWORD dwState[4]);

	if (lpThis == NULL) 
		return -1;

	void *lpVTable = *(void **)lpThis;

	if (lpVTable == NULL) 
		return -2;

	fnGetButtonState fnGBS = (fnGetButtonState)GetOffsetPointer(lpVTable, 0x10);

	int nRet;

	DWORD dwData[4] = { 0x00A78624, 1, 0, 0 };
	DWORD dwSafe[4];

	dwSafe;

	//刷新菜单控件
	OrigSoftMenu_UpdateItems(lpThis);  

	nRet = fnGBS(lpThis, nIndex, dwData);

	if (lpblEnable) 
		*lpblEnable = dwData[1];
	if (lpblCheck) 
		*lpblCheck = dwData[2];
	if (lpblRadio) 
		*lpblRadio = dwData[3];

	return nRet;
}