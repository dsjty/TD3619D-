#include "stdafx.h"

/*
本文件包含来自于E5062.exe中函数调用的逆向结果及再工程函数
*/

//E5062主窗口宽和高
WORD wWidth_MainWnd = 0, wHeight_MainWnd = 0;

//软菜单窗口句柄
HWND hwSoftMenu = NULL;
//软菜单条目区域窗口句柄
HWND hwSoftItem = NULL;

//E5070主窗口句柄
HWND hwMainWnd = NULL;

void UpdateSize_UI();

void *GetSubMenuPointer(void *lpThis, int nIndex)
{
	void *lpResult = NULL;
	void *lpVar1, *lpVar2;
	int nMaxItem;

	if (lpThis == NULL) 
		return lpResult;

	lpVar1 = GetOffsetPointer(lpThis, 0x24);

	if (lpVar1)
	{
		lpVar2 = GetOffsetPointer(lpThis, 0x28);
		nMaxItem = ((int)lpVar2 - (int)lpVar1) >> 2; // ((int)lpVar2 - (int)lpVar1) ÷ 4
	}
	else
		nMaxItem = 0;

	if (nIndex < nMaxItem)
		lpResult = GetOffsetPointer(lpVar1, nIndex * 4);

	return lpResult;
}

bool GetButtonCheckState(void * lpBtnState, int nIndex)
{
	typedef void * (__thiscall * fn_priFn1)(void * lpBtnState, int nVar);
	typedef void * (__thiscall * fn_priFn2)(void * lpVar1, int nVar);

	void *lpTmp, *lpTmp2, *lpTmp3;
	fn_priFn1 priFn1;
	fn_priFn2 priFn2;
	bool *lpBool;

	lpTmp = *(void **)lpBtnState;
	priFn1 = (fn_priFn1)(*(void **)((int)lpTmp + 4));

	lpTmp2 = priFn1(lpBtnState, -1);
	lpTmp = *(void **)lpTmp2;
	priFn2 = (fn_priFn2)(*(void **)((int)lpTmp + 0x14));

	lpTmp2 = priFn2(lpTmp2, -1);
	lpTmp2 = *(void **)((int)lpTmp2 + 0x8);
	lpTmp3 = *(void **)((int)lpTmp2 + 0x8);
	lpBool = (bool *)((int)lpTmp3 + (nIndex * 16) + 0x08);

	return *lpBool;
}

NAKED int WINAPI DirectCall(void *lpThis, void *lpFunction)
{
	__asm mov ecx, dword ptr[esp + 0x04]
		__asm call dword ptr[esp + 0x08]
		__asm retn 0x08
}

NAKED int WINAPI DirectCall_2(void *lpThis, void *lpFunction, int nIndex)
{
	__asm push ebp
	__asm mov ecx, dword ptr[esp + 0x08]
		__asm mov eax, dword ptr[esp + 0x0C]
		__asm mov ebp, dword ptr[esp + 0x10]
		__asm push ebp
	__asm call eax
	__asm pop ebp
	__asm retn 0x0C
}

void WINAPI _CWnd__OnSize_main(CWnd *lpThis, UINT nType, int cx, int cy)
{
	if (nType != SIZE_MINIMIZED)
	{
		UpdateSize_UI();
	}
}

LPCSTR GetStringByIndexA(LPCSTR lpStr, int nIndex)
{
	if (lpStr == NULL || nIndex <= 0)
		return lpStr;

	LPCSTR lpRetStr = lpStr;
	size_t nLen;

	while (nIndex)
	{
		nLen = strlen(lpRetStr) + 1;
		lpRetStr = (LPCSTR)((size_t)lpRetStr + nLen * sizeof(CHAR));

		if (*lpRetStr == 0)
			return lpStr;

		nIndex--;
	}

	return lpRetStr;
}

//************************************
// 函数名:    GetStringByIndex
// FullName:  GetStringByIndex
// Access:    public 
// 返回值类型:   LPCWSTR
// 参数: LPCWSTR lpWStr	语言文字
// 参数: int nIndex  语言序号
// 说明: 根据nIndex选择按钮语言文字,返回相关语种语言;
//************************************
LPCWSTR GetStringByIndex(LPCWSTR lpWStr, int nIndex)
{
	if (lpWStr == NULL || nIndex <= 0)
		return lpWStr;

	LPCWSTR lpRetWStr = lpWStr;
	size_t nLen;

	while (nIndex)
	{
		nLen = wcslen(lpRetWStr) + 1;
		lpRetWStr = (LPCWSTR)((size_t)lpRetWStr + nLen * sizeof(WCHAR));

		if (*lpRetWStr == 0)
			return lpWStr;

		nIndex--;
	}

	return lpRetWStr;
}

LPCWSTR GetStringByIndex(LPCWSTR lpWStr, int nIndex, int lParam)
{
	return lpWStr;
}

int GetButtonStateIndex(const char *lpszCmd, void *lpUnk, int *lpIndex, int nVars)
{
	if (!lpszCmd || !lpIndex)
		return -1;

	typedef void *(__cdecl *fn_00023650)(void *lpOutput, PBAS_STR pbsInput, int nNum);
	typedef void *(__cdecl *fn_00A33D80)(PBAS_STR pbsVar, void *lpMemAddr2);
	typedef void *(__thiscall *fn_00484060)(void *lpMemAddr);

	fn_00023650 fn00023650 = (fn_00023650)(BASE + 0x23650);
	fn_00A33D80 fn00A33D80 = (fn_00A33D80)(BASE + 0xA33D80);

	void *lpAlloc, *lpTmp;
	int nLen = strlen(lpszCmd);
	BAS_STR bsVar;
	BYTE btUnkObj[96];

	if (nLen == 0)
		return -2;

	lpAlloc = malloc(nLen + 0xF);

	bsVar.lpszText = (char *)lpAlloc;
	bsVar.lpUnkObj1 = lpUnk;
	bsVar.lpUnkObj2 = 0;
	bsVar.lpUnkObj3 = 0;
	bsVar.dwStringLen = nLen;
	bsVar.dwBufferMaxLen = nLen + 0xf;

	if (bsVar.lpszText == NULL)
		return -3;

	bsVar.lpszText[0] = GET_BYTE_0(nVars);
	bsVar.lpszText++;
	strcpy_s(bsVar.lpszText, bsVar.dwBufferMaxLen, lpszCmd);

	*(int *)&btUnkObj[0] = 0;
	*(int *)&btUnkObj[0x58] = GET_BYTE_1(nVars);

	lpTmp = fn00023650(btUnkObj, &bsVar, 0);

	lpTmp = fn00A33D80((PBAS_STR)((int)lpTmp + 0x24), GetOffsetPointer(lpTmp, 0x20));
	*lpIndex = *(int *)((int)lpTmp + 0x1C);

	free(lpAlloc);
	return 0;
}

int GetCommandVariant_Dbl(const char *lpszCmd, void *lpVTable, void *lpVTable2, void *lpUnk, double *lpDbl)
{
	typedef void *(__cdecl *fn_00404D20)(void *lpOutput, PBAS_STR pbsInput, int nNum);
	typedef void *(__cdecl *fn_00404BD0)(void *lpInput);
	typedef void *(__thiscall *fn_0040E390)(void *lpThis, void *lpVar);
	typedef int(__thiscall *fn_004076C0)(void *lpThis);
	typedef int(__thiscall *fn_004100B0)(void *lpThis, double *lpDbl);
	typedef int(__thiscall *fn_00404760)(void *lpMemAddr); //VarClr

	typedef struct _X20_S
	{
		BYTE            btThis[16];
		VARIANTARG      pvarg;
	} X20_S;

	fn_00404D20 fn00404D20 = (fn_00404D20)0x00404D20;
	fn_00404BD0 fn00404BD0 = (fn_00404BD0)0x00404BD0;
	fn_0040E390 fn0040E390 = (fn_0040E390)0x0040E390;
	fn_004076C0 fn004076C0 = (fn_004076C0)0x004076C0;
	fn_004100B0 fn004100B0 = (fn_004100B0)0x004100B0;
	fn_00404760 fn00404760 = (fn_00404760)0x00404760;

	double dblTmp;
	void *lpAlloc, *lpTmp, *lpTmp2;
	int *lpRet;
	HRESULT hResult;
	int nLen = strlen(lpszCmd);

	BAS_STR bsVar;
	X20_S x20;

	BYTE btVarObj[180];

	lpAlloc = malloc(nLen + 32);

	bsVar.lpUnkObj1 = lpUnk;
	bsVar.lpszText = (char *)lpAlloc;
	bsVar.dwStringLen = nLen;
	bsVar.dwBufferMaxLen = nLen + 31;

	if (bsVar.lpszText == NULL)
		return -1;

	bsVar.lpszText[0] = 0;
	bsVar.lpszText++;
	strcpy_s(bsVar.lpszText, bsVar.dwBufferMaxLen, lpszCmd);

	memset(&x20, 0, sizeof(x20));
	memset(btVarObj, 0, sizeof(btVarObj));

	*(void **)btVarObj = lpVTable;
	lpTmp = fn00404D20(btVarObj, &bsVar, 0);
	lpTmp = lpRet = (int *)fn00404BD0(lpTmp);

	if (!lpRet[12])
	{
		//Exception
		free(lpAlloc);
		return -2;
	}

	lpTmp2 = (void *)lpRet[4];

	fn0040E390(x20.btThis, lpTmp2);
	fn004076C0(&lpRet[1]);
	fn004100B0(x20.btThis, &dblTmp);
	if (lpDbl) *lpDbl = dblTmp;

	hResult = VariantClear(&x20.pvarg);

	if (hResult < 0)
	{
		//Exception
		free(lpAlloc);
		return 1;
	}

	*(void **)btVarObj = lpVTable2;
	fn00404760(btVarObj);

	free(lpAlloc);
	return 0;
}

int FmtValueToString(void *lpInput, char *lpszBuffer, DWORD dwMaxLen, double *lpDblOut)
{
	if (!lpInput || !lpszBuffer || !dwMaxLen) 
		return -1;

	fn_GetDouble fnGetDbl = GetAddr_GetDbl(lpInput);
	fn_FmtToString fnFmtStr = GetAddr_FmtStr(lpInput);
	BAS_STR bsVar = { 0, 0, 0, 0 };
	PBAS_STR lpbs = &bsVar;
	int nRet = -2;

	if (lpDblOut)
	{
		*lpDblOut = fnGetDbl(lpInput);
		lpbs = fnFmtStr((void *)(((DWORD)lpInput) + 4), lpbs, *lpDblOut);
	}
	else
		lpbs = fnFmtStr((void *)(((DWORD)lpInput) + 4), lpbs, fnGetDbl(lpInput));

	if (lpbs && (lpbs->lpszText))
	{
		char *lpText = lpbs->lpszText;

		nRet = strcpy_s(lpszBuffer, dwMaxLen, lpText);

		lpText--;

		if ((*lpText != 0) && (*lpText != -1))
			lpText[0]--;
		else if (fnFree)
			fnFree(lpText);
		else
			free(lpText);
	}

	return nRet;
}

int FmtValueToStringEx(void *lpInput, char *lpszBuffer, DWORD dwMaxLen, double lpDblIn)
{
	if (!lpInput || !lpszBuffer || !dwMaxLen) 
		return -1;

	fn_FmtToString fnFmtStr = GetAddr_FmtStr(lpInput);
	BAS_STR bsVar = { 0, 0, 0, 0 };
	PBAS_STR lpbs = &bsVar;
	int nRet = -2;

	lpbs = fnFmtStr((void *)(((DWORD)lpInput) + 4), lpbs, lpDblIn);

	if (lpbs && (lpbs->lpszText))
	{
		char *lpText = lpbs->lpszText;

		nRet = strcpy_s(lpszBuffer, dwMaxLen, lpText);

		lpText--;

		if ((*lpText != 0) && (*lpText != -1))
			lpText[0]--;
		else if (fnFree)
			fnFree(lpText);
		else
			free(lpText);
	}

	return nRet;
}

int FmtValueToStringExW(void *lpInput, LPWSTR lpszBuffer, DWORD dwMaxLen, double lpDblIn)
{
	if (!lpInput || !lpszBuffer || !dwMaxLen) 
		return -1;

	fn_FmtToString fnFmtStr = GetAddr_FmtStr(lpInput);
	BAS_STR bsVar = { 0, 0, 0, 0 };
	PBAS_STR lpbs = &bsVar;
	int nRet = -2;

	lpbs = fnFmtStr((void *)(((DWORD)lpInput) + 4), lpbs, lpDblIn);

	if (lpbs && (lpbs->lpszText))
	{
		char *lpText = lpbs->lpszText;

		nRet = MultiByteToWideChar(1253, 0, lpText, -1, lpszBuffer, dwMaxLen);

		lpText--;

		if ((*lpText != 0) && (*lpText != -1))
			lpText[0]--;
		else if (fnFree)
			fnFree(lpText);
		else
			free(lpText);
	}

	return nRet;
}

BOOL ScanfStringToValue(void *lpInput, LPCSTR lpszText, double *lpDbl)
{
	if (!lpInput || !lpszText)
		return FALSE;

	fn_SetDouble fnSetDbl = GetAddr_SetDbl(lpInput);
	fn_ScanfToDouble fnScfDbl = GetAddr_ScfDbl(lpInput);
	BAS_STR bsVar = { NULL, NULL, 0,0, MAX_PATH - 1 };
	BOOL blRet = FALSE;
	char szText[MAX_PATH];

	szText[0] = 0;
	szText[1] = 0;
	bsVar.lpszText = &(szText[1]);

	strcpy_s(bsVar.lpszText, bsVar.dwBufferMaxLen, lpszText);
	bsVar.dwStringLen = strlen(bsVar.lpszText);

	if (lpDbl)
	{
		*lpDbl = fnScfDbl(lpInput, &bsVar);
		blRet = fnSetDbl(lpInput, *lpDbl);
	}
	else
	{
		blRet = fnSetDbl(lpInput, fnScfDbl(lpInput, &bsVar));
	}

	return blRet;
}

BOOL ScanfStringToValueW(void *lpInput, LPCWSTR lpWcsText, double *lpDbl)
{
	if (!lpInput || !lpWcsText)
		return FALSE;

	fn_SetDouble fnSetDbl = GetAddr_SetDbl(lpInput);
	fn_ScanfToDouble fnScfDbl = GetAddr_ScfDbl(lpInput);
	BAS_STR bsVar = { NULL, NULL, 0, 0, MAX_PATH - 1 };
	BOOL blRet = FALSE;
	char szText[MAX_PATH];

	szText[0] = 0;
	szText[1] = 0;
	bsVar.lpszText = &(szText[1]);

	WideCharToMultiByte(1253, 0, lpWcsText, -1, bsVar.lpszText, bsVar.dwBufferMaxLen, NULL, NULL);
	bsVar.dwStringLen = strlen(bsVar.lpszText);

	if (lpDbl)
	{
		*lpDbl = fnScfDbl(lpInput, &bsVar);
		blRet = fnSetDbl(lpInput, *lpDbl);
	}
	else
	{
		blRet = fnSetDbl(lpInput, fnScfDbl(lpInput, &bsVar));
	}

	return blRet;
}

BOOL ScanfStringToValueEx(void *lpInput, LPCSTR lpText, double *lpDbl)
{
	if (!lpInput || !lpText || !lpDbl)
		return FALSE;

	fn_ScanfToDouble fnScfDbl = GetAddr_ScfDbl(lpInput);
	BAS_STR bsVar = { NULL, NULL, 0, 0, MAX_PATH - 1 };
	char szText[MAX_PATH];

	szText[0] = 0;
	szText[1] = 0;
	bsVar.lpszText = &(szText[1]);

	strcpy_s(bsVar.lpszText, bsVar.dwBufferMaxLen, lpText);
	bsVar.dwStringLen = strlen(bsVar.lpszText);

	*lpDbl = fnScfDbl(lpInput, &bsVar);

	return TRUE;
}

BOOL ScanfStringToValueExW(void *lpInput, LPCWSTR lpWcsText, double *lpDbl)
{
	if (!lpInput || !lpWcsText || !lpDbl) 
		return FALSE;

	fn_ScanfToDouble fnScfDbl = GetAddr_ScfDbl(lpInput);
	BAS_STR bsVar = { NULL, NULL, 0, 0, MAX_PATH - 1 };
	char szText[MAX_PATH];

	szText[0] = 0;
	szText[1] = 0;
	bsVar.lpszText = &(szText[1]);

	WideCharToMultiByte(1253, 0, lpWcsText, -1, bsVar.lpszText, bsVar.dwBufferMaxLen, NULL, NULL);
	bsVar.dwStringLen = strlen(bsVar.lpszText);

	*lpDbl = fnScfDbl(lpInput, &bsVar);

	return TRUE;
}

BOOL SetInputStringObjectW(void *lpInObj, LPCWSTR lpWcsText)
{
	if (lpInObj == NULL || lpWcsText == NULL)
		return FALSE;

	typedef BOOL(__thiscall *func_SetInStrObj)(void *lpThis_lpInStrObj, PBAS_STR lpBasStr);

	func_SetInStrObj fnSISO = (func_SetInStrObj)*(DWORD *)(*((DWORD *)lpInObj) + 0x04);
	BAS_STR bsVar = { NULL, NULL, 0, 0, MAX_PATH - 1 };
	char szText[MAX_PATH];

	szText[0] = 0;
	szText[1] = 0;
	bsVar.lpszText = &szText[1];

	WideCharToMultiByte(CP_ACP, 0, lpWcsText, -1, bsVar.lpszText, bsVar.dwBufferMaxLen, NULL, NULL);
	bsVar.dwStringLen = strlen(bsVar.lpszText);

	return fnSISO(lpInObj, &bsVar);
}

BOOL GetInputStringObjectW(void *lpInObj, LPWSTR lpWcsText, DWORD dwMaxLen, int *lpLimit)
{
	if (lpInObj == NULL)
		return FALSE;

	if (lpLimit)
	{
		typedef int(__thiscall *func_GetInStrObjLimit)(void *lpThis_lpInStrObj);
		func_GetInStrObjLimit fnGISOL = (func_GetInStrObjLimit)*(DWORD *)(*((DWORD *)lpInObj) + 0x0C);

		*lpLimit = fnGISOL(lpInObj);
	}

	if (lpWcsText == NULL || dwMaxLen == 0)
		return FALSE;

	typedef PBAS_STR(__thiscall *func_GetInStrObj)(void *lpThis_lpInStrObj, PBAS_STR lpBasStr);

	func_GetInStrObj fnGISO = (func_GetInStrObj)*(DWORD *)(*((DWORD *)lpInObj) + 0x08);
	BAS_STR bsVar = { NULL, NULL, 0, 0 };
	PBAS_STR lpbs = &bsVar;

	lpWcsText[0] = 0;

	lpbs = fnGISO(lpInObj, lpbs);

	if (lpbs && (lpbs->lpszText))
	{
		char *lpText = lpbs->lpszText;

		MultiByteToWideChar(1253, 0, lpText, -1, lpWcsText, dwMaxLen);

		lpText--;

		if ((*lpText != 0) && (*lpText != -1))
			lpText[0]--;
		else if (fnFree)
			fnFree(lpText);
		else
			free(lpText);

		return TRUE;
	}

	return FALSE;
}

BOOL SetInputBtnStateIndex(void *lpBtnState, int nIndex)
{
	if (!lpBtnState) 
		return FALSE;

	typedef void *(__thiscall *fn_priCall1)(void *lpThis, int nVar);

	void *lpVar1, *lpVar2, *lpVar3;
	fn_priCall1 fnCall1;

	lpVar1 = *(void **)lpBtnState;
	fnCall1 = (fn_priCall1)GetOffsetPointer(lpVar1, 0x04);

	lpVar1 = fnCall1(lpBtnState, -1);

	lpVar2 = *(void **)lpVar1;
	fnCall1 = (fn_priCall1)GetOffsetPointer(lpVar2, 0x14);

	lpVar2 = fnCall1(lpVar1, -1);

	lpVar3 = GetOffsetPointer(lpVar2, 0x08);
	lpVar1 = *(void **)lpVar3;
	fnCall1 = (fn_priCall1)GetOffsetPointer(lpVar1, 0x24);

	fnCall1(lpVar3, nIndex);

	return TRUE;
}

BOOL GetMarkerStateIndex(void *lpBtnState, int *lpIndex, bool *lpBool, bool *lpBool2)
{
	if (!lpBtnState || !lpIndex) 
		return FALSE;

	typedef void *(__thiscall *fn_priCall1)(void *lpThis, int nVar);
	typedef int(__thiscall *fn_priCall2)(void *lpThis);

	void *lpVar1, *lpVar2, *lpVar3;
	fn_priCall1 fnCall1;
	fn_priCall2 fnCall2;
	int nRet;

	lpVar1 = *(void **)lpBtnState;
	fnCall1 = (fn_priCall1)GetOffsetPointer(lpVar1, 0x04);

	lpVar1 = fnCall1(lpBtnState, -1);

	lpVar2 = *(void **)lpVar1;
	fnCall1 = (fn_priCall1)GetOffsetPointer(lpVar2, 0x14);

	lpVar2 = fnCall1(lpVar1, -1);

	lpVar3 = GetOffsetPointer(lpVar2, 0x08);
	lpVar1 = *(void **)lpVar3;
	fnCall2 = (fn_priCall2)GetOffsetPointer(lpVar1, 0x14);

	nRet = fnCall2(lpVar3);

	*lpIndex = nRet;

	if (lpBool)
	{
		fnCall1 = (fn_priCall1)GetOffsetPointer(lpVar1, 0x0C);
		lpVar2 = fnCall1(lpVar3, nRet);

		*lpBool = (bool)GET_BYTE_0(lpVar2);
	}

	if (lpBool2)
	{
		int nVar = (int)GetOffsetPointer(lpVar3, 0x1C);

		fnCall1 = (fn_priCall1)GetOffsetPointer(lpVar1, 0x08);
		lpVar2 = fnCall1(lpVar3, nVar);

		*lpBool2 = (bool)GET_BYTE_0(lpVar2);
	}

	return TRUE;
}

int GetSubMenuSelected(void *lpThis)
{
	if (lpThis == NULL)
		return -1;

	typedef void * (__thiscall *func_InitVar)(void *lpThis);
	typedef int(__thiscall * fnGetButtonState)(void *lpThis, int nIndex, DWORD dwState[4]);

	void *lpStatic = *(void **)lpThis;
	func_InitVar fnInitVar = (func_InitVar)(BASE + 0xA0C1D0);
	fnGetButtonState fnGetItemState = (fnGetButtonState)GetOffsetPointer(lpStatic, 0x10);
	DWORD nInVar[4];

	int nMax = (int)GetOffsetPointer(lpThis, 0x04);
	int nRet = -1;

	fnInitVar(nInVar);

	for (int nIndex = 0; nIndex < nMax; nIndex++)
	{
		fnGetItemState(lpThis, nIndex, nInVar);

		if (nInVar[1])
		{
			nRet = nIndex;
			break;
		}
	}

	return nRet;
}

int GetSubMenuSelected_Radio(void *lpThis)
{
	if (lpThis == NULL) 
		return -1;

	BOOL blTmp = FALSE;
	int nMax = (int)GetOffsetPointer(lpThis, 0x04);

	for (int nIndex = 0; nIndex < nMax; nIndex++)
	{
		OrigSoftMenu_GetItemState(lpThis, nIndex, NULL, NULL, &blTmp);

		if (blTmp) 
			return nIndex;
	}

	return -1;
}

int GetSubMenuItemCount(void *lpThis)
{
	if (lpThis == NULL) 
		return 0;

	return (int)GetOffsetPointer(lpThis, 0x04);
}

LPSTR GetSubMenuItemText(void *lpThis, int nIndex)
{
	LPSTR *lpList = (LPSTR *)GetOffsetPointer(lpThis, 0x14);
	int nMax = GetSubMenuItemCount(lpThis);

	if (nIndex >= nMax || nIndex < 0) 
		return NULL;

	if (lpList == NULL) 
		return NULL;

	return (LPSTR)lpList[nIndex];
}

BOOL InputFineTune(void *lpInput, double *lpDblOut, double dblCurrent, int iDelta)
{
	if (!lpInput || !lpDblOut)
		return FALSE;

	fn_FineTune fnFineTune = GetAddr_FineTune(lpInput);
	int nDelta = iDelta, nNumber;

	if (!fnFineTune)
		return FALSE;

	if (nDelta < 0)
		nDelta = -nDelta;

	if (nDelta == 1)
		nNumber = 0;
	else if (nDelta == 5)
		nNumber = 1;
	else
		nNumber = 2;

	*lpDblOut = fnFineTune((void *)(((DWORD)lpInput) + 4), dblCurrent, ((iDelta < 0) ? false : true), nNumber);

	return TRUE;
}

BOOL InputFineTune2(void *lpInput, double *lpDblOut, double dblCurrent, int iDelta)
{
	if (!lpInput || !lpDblOut) 
		return FALSE;

	fn_FineTune2 fnFineTune2 = GetAddr_FineTune2(lpInput);

	if (!fnFineTune2) 
		return FALSE;

	*lpDblOut = fnFineTune2((void *)(((DWORD)lpInput) + 4), dblCurrent, ((iDelta < 0) ? false : true));

	return TRUE;
}

int TrimLeft(char *s, int nMax)
{
	if (!s) 
		return -1;
	char *p = s;
	while (*p && ((' ' == *p) || ('\t' == *p)))
		p++;

	if (*p)
		strcpy_s(s, nMax, p);
	else
		*s = 0;

	return 0;
}

int BreakString(char *s, int nMax)
{
	if (!s) 
		return -1;

	int nIndex = 0;

	while ((nIndex < nMax) && (s[nIndex] != 0))
	{
		if (s[nIndex] == ' ' || s[nIndex] == '\t')
		{
			s[nIndex] = 0;
			break;
		}
		nIndex++;
	}

	return nIndex;
}

int MakeUnitStringW(void *lpInput, LPWSTR lpWText, int nMax, LPCSTR lpUnitChar)
{
	double dblTmp;
	char szText[MAX_PATH];

	if (!lpInput || !lpWText) 
		return -1;

	WideCharToMultiByte(1253, 0, lpWText, -1, szText, MAX_PATH, NULL, NULL);
	TrimLeft(szText, MAX_PATH);
	BreakString(szText, MAX_PATH);
	strcat_s(szText, MAX_PATH, lpUnitChar);
	ScanfStringToValueEx(lpInput, szText, &dblTmp);
	FmtValueToStringExW(lpInput, lpWText, nMax, dblTmp);
	return 0;
}

void PSTMSG_432_2()
{
	PostMessageA(hwMainWnd, 0x0432, 0x02, 0);
}

void PSTMSG_432_E()
{
	PostMessageA(hwMainWnd, 0x0432, 0x0E, 0);
}