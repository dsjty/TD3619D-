﻿#pragma once

#ifndef _INC_WINDOWS
#include <Windows.h>
#endif

#ifndef _INC_WINDOWSX
#include <Windowsx.h>
#endif


inline BOOL WriteMemory(LPVOID lpAny, LPCVOID lpData, SIZE_T stCount)
{
	DWORD dwOldProtect;

	if (!VirtualProtect(lpAny, stCount, PAGE_EXECUTE_READWRITE, &dwOldProtect))
		return FALSE;

	memcpy_s(lpAny, stCount, lpData, stCount);

	return VirtualProtect(lpAny, stCount, dwOldProtect, &dwOldProtect);
}

//上层函数+基址
inline void *GetOffsetPointer(void *lpAny, int nOffset)
{
	return *(void **)((int)lpAny + nOffset);
}

//上层函数+基址
inline fn_SetDouble GetAddr_SetDbl(void *lpInput)
{
	return (fn_SetDouble)*(DWORD *)(*((DWORD *)lpInput) + 0x04);
}

//上层函数+基址
inline fn_GetDouble GetAddr_GetDbl(void *lpInput)
{
	return (fn_GetDouble)*(DWORD *)(*((DWORD *)lpInput) + 0x08);
}
//上层函数+基址
inline fn_ScanfToDouble GetAddr_ScfDbl(void *lpInput)
{
	return (fn_ScanfToDouble)*(DWORD *)(*((DWORD *)lpInput) + 0x0C);
}

//交由上层函数+基址
inline fn_FmtToString GetAddr_FmtStr(void *lpInput)
{
	return (fn_FmtToString)*(DWORD *)(((DWORD *)lpInput)[1] + 0x24);
}

//交由上层函数+基址
inline fn_FmtToStringAvg GetAddr_FmtStrA(void *lpInput)
{
	return (fn_FmtToStringAvg)*(DWORD *)(((DWORD *)lpInput)[1] + 0x24);
}

//上层函数+基址
inline fn_FineTune GetAddr_FineTune(void *lpInput)
{
	return (fn_FineTune)*(DWORD *)(((DWORD *)lpInput)[1] + 0x0C);
}
//上层函数+基址
inline fn_FineTune2 GetAddr_FineTune2(void *lpInput)
{
	return (fn_FineTune2)*(DWORD *)(((DWORD *)lpInput)[1] + 0x08);
}

inline BOOL HitRect(RECT rect, int x, int y)
{
	if (rect.right - rect.left == 0 || rect.bottom - rect.top == 0)
		return FALSE;

	if ((x >= rect.left) && (x < rect.right) && (y >= rect.top) && (y < rect.bottom))
		return TRUE;
	else
		return FALSE;
}

inline PSOFT_MENU GetCurrentSoftMenu()
{
	if (lpMenuStack[btMenuIndex] == NULL)
	{
		lpMenuStack[0] = &menuRoot;
		btMenuIndex = 0;
	}

	return lpMenuStack[btMenuIndex];
}

//更新控件
inline void UpdateCurrentItems()
{
	PSOFT_TAG_PAGE lpTagPage = SoftItem_GetCurrentTagPage();

	if (lpTagPage)
	{
		DWORD dwIndex;

		for (dwIndex = 0; dwIndex < lpTagPage->dwNumOfSubItems; dwIndex++)
		{
			if (lpTagPage->lpSubItem[dwIndex]._hWnd)
			{
				InvalidateRect(lpTagPage->lpSubItem[dwIndex]._hWnd, NULL, TRUE);
				UpdateWindow(lpTagPage->lpSubItem[dwIndex]._hWnd);
			}
		}
	}

	InvalidateRect(hwSoftItem, NULL, TRUE);

	UpdateWindow(hwSoftItem);
}

inline void UpdateDataByTagPage(PSOFT_TAG_PAGE lpTagPage)
{
	if (lpTagPage)
	{
		DWORD dwIndex;

		for (dwIndex = 0; dwIndex < lpTagPage->dwNumOfSubItems; dwIndex++)
		{
			if (CHK_FLAGS(lpTagPage->lpSubItem[dwIndex].dwFlags, SIF_FN_UPDATEDATA) && (lpTagPage->lpSubItem[dwIndex].lpEvent[FNID_UPDATE_DATA]))
			{
				func_ItemEvent_UpdateData fnUpdateData = (func_ItemEvent_UpdateData)lpTagPage->lpSubItem[dwIndex].lpEvent[FNID_UPDATE_DATA];
				fnUpdateData(0, 0, 0, &(lpTagPage->lpSubItem[dwIndex]));
			}
			else if ((lpTagPage->lpSubItem[dwIndex].dwStyle == SIS_InputButtonEx) && (lpTagPage->lpSubItem[dwIndex].lpOpt[1]))
			{
				PSOFT_SUB_ITEM lpSubItem = &(lpTagPage->lpSubItem[dwIndex]);
				WCHAR wcsText[MAX_PATH] = { 0 };

				wcsText[0] = 0;

				if (CHK_NOFLAGS(lpSubItem->dwFlags, SIF_NOREPLY) && lpSubItem->lpThis && lpSubItem->lpVTable)
				{
					OrigSoftMenu_ItemClicked2(lpSubItem->lpThis, lpSubItem->lpVTable, lpSubItem->dwFunctionId);
				}

				if (CHK_FLAGS(lpSubItem->dwAttributes, SIA_INPUT_TEXT))
				{
					GetInputStringObjectW(lpSubItem->lpOpt[1], wcsText, MAX_PATH, NULL);
				}
				else
				{
					char szText[MAX_PATH] = { 0 };
					szText[0] = 0;

					FmtValueToString(lpSubItem->lpOpt[1], szText, MAX_PATH, NULL);
					MultiByteToWideChar(CP_ACP, 0, szText, -1, wcsText, MAX_PATH);
				}

				SetWindowTextW((HWND)lpSubItem->lpOpt[4], wcsText);
			}
		}
	}
}

inline void UpdateCurrentData()
{
	PSOFT_TAG_PAGE lpTagPage = SoftItem_GetCurrentTagPage();

	if (lpTagPage)
	{
		DWORD dwIndex;

		for (dwIndex = 0; dwIndex < lpTagPage->dwNumOfSubItems; dwIndex++)
		{
			if (CHK_FLAGS(lpTagPage->lpSubItem[dwIndex].dwFlags, SIF_FN_UPDATEDATA) && (lpTagPage->lpSubItem[dwIndex].lpEvent[FNID_UPDATE_DATA]))
			{
				func_ItemEvent_UpdateData fnUpdateData = (func_ItemEvent_UpdateData)lpTagPage->lpSubItem[dwIndex].lpEvent[FNID_UPDATE_DATA];
				fnUpdateData(0, 0, 0, &(lpTagPage->lpSubItem[dwIndex]));
			}
		}
	}
}

//更新控件
inline void UpdateCurrentItemsAndData()
{
	PSOFT_TAG_PAGE lpTagPage = SoftItem_GetCurrentTagPage();

	if (lpTagPage)
	{
		DWORD dwIndex;

		for (dwIndex = 0; dwIndex < lpTagPage->dwNumOfSubItems; dwIndex++)
		{
			if (CHK_FLAGS(lpTagPage->lpSubItem[dwIndex].dwFlags, SIF_FN_UPDATEDATA) && (lpTagPage->lpSubItem[dwIndex].lpEvent[FNID_UPDATE_DATA]))
			{
				func_ItemEvent_UpdateData fnUpdateData = (func_ItemEvent_UpdateData)lpTagPage->lpSubItem[dwIndex].lpEvent[FNID_UPDATE_DATA];
				fnUpdateData(0, 0, 0, &(lpTagPage->lpSubItem[dwIndex]));
			}

			if ((lpTagPage->lpSubItem[dwIndex].dwStyle == SIS_InputButtonEx) && (lpTagPage->lpSubItem[dwIndex].lpOpt[1]) && (lpTagPage->lpSubItem[dwIndex].lpOpt[4]))
			{
				PSOFT_SUB_ITEM lpSubItem = &(lpTagPage->lpSubItem[dwIndex]);
				WCHAR wcsText[MAX_PATH] = { 0 };

				wcsText[0] = 0;

				if (CHK_NOFLAGS(lpSubItem->dwFlags, SIF_NOREPLY) && lpSubItem->lpThis && lpSubItem->lpVTable)
					OrigSoftMenu_ItemClicked2(lpSubItem->lpThis, lpSubItem->lpVTable, lpSubItem->dwFunctionId);


				if (CHK_FLAGS(lpSubItem->dwAttributes, SIA_INPUT_TEXT))
					GetInputStringObjectW(lpSubItem->lpOpt[1], wcsText, MAX_PATH, NULL);

				else
				{
					char szText[MAX_PATH] = { 0 };
					szText[0] = 0;

					FmtValueToString(lpSubItem->lpOpt[1], szText, MAX_PATH, NULL);
					MultiByteToWideChar(CP_ACP, 0, szText, -1, wcsText, MAX_PATH);
				}

				SetWindowTextW((HWND)lpSubItem->lpOpt[4], wcsText);
			}

			if (lpTagPage->lpSubItem[dwIndex].lpOpt[4])
			{
				InvalidateRect((HWND)lpTagPage->lpSubItem[dwIndex].lpOpt[4], NULL, TRUE);
				UpdateWindow((HWND)lpTagPage->lpSubItem[dwIndex].lpOpt[4]);
			}
			else if (lpTagPage->lpSubItem[dwIndex]._hWnd)
			{
				InvalidateRect((HWND)lpTagPage->lpSubItem[dwIndex]._hWnd, NULL, TRUE);
				UpdateWindow((HWND)lpTagPage->lpSubItem[dwIndex]._hWnd);
			}
		}
	}

	InvalidateRect(hwSoftItem, NULL, TRUE);
	UpdateWindow(hwSoftItem);
	PopWnd_UpdateInputBox();
}

//测试窗口句柄是不是当前子菜单下的SoftItem
inline DWORD TestHitItem(HWND hWnd_SoftItem)
{
	PSOFT_TAG_PAGE lpTagPage = SoftItem_GetCurrentTagPage();
	PSOFT_SUB_ITEM lpSubItem;
	DWORD dwIndex;

	for (dwIndex = 0; dwIndex < lpTagPage->dwNumOfSubItems; dwIndex++)
	{
		lpSubItem = &(lpTagPage->lpSubItem[dwIndex]);

		if (hWnd_SoftItem == lpSubItem->_hWnd)
			return dwIndex;
	}

	return INVALID_INDEX;
}

inline PSOFT_TAG_PAGE GetTagPageByIndex(DWORD dwIndex)
{
	if (lpMenuStack[btMenuIndex] == NULL)
	{
		lpMenuStack[0] = &menuRoot;
		btMenuIndex = 0;
	}

	if (lpMenuStack[btMenuIndex] == NULL) 
		return NULL;

	if (dwIndex >= lpMenuStack[btMenuIndex]->dwNumOfTagPages)
		return NULL;

	return &(lpMenuStack[btMenuIndex]->lpTagPage[dwIndex]);
}


inline LPCWSTR GetCurrentSoftMenuTitle()
{
	if (lpMenuStack[btMenuIndex] == NULL)
	{
		lpMenuStack[0] = &menuRoot;
		btMenuIndex = 0;
	}

	return (lpMenuStack[btMenuIndex]->szMenuTitle != NULL) ? lpMenuStack[btMenuIndex]->szMenuTitle : lpMenuStack[btMenuIndex]->lpszMenuTitle;
}

inline LPCWSTR GetCurrentSoftMenuTitleByIndex(int nIndex)
{
	if (lpMenuStack[btMenuIndex] == NULL)
	{
		lpMenuStack[0] = &menuRoot;
		btMenuIndex = 0;
	}

	if (lpMenuStack[btMenuIndex]->szMenuTitle != NULL)
		return lpMenuStack[btMenuIndex]->szMenuTitle;

	return GetStringByIndex(lpMenuStack[btMenuIndex]->lpszMenuTitle, nIndex);
}

inline DWORD GetCurrentSoftItemIndex(PSOFT_SUB_ITEM lpSubItem)
{
	PSOFT_TAG_PAGE lpTagPage = SoftItem_GetCurrentTagPage();

	if (lpTagPage && (((DWORD)lpSubItem - (DWORD)lpTagPage->lpSubItem) % sizeof(SOFT_SUB_ITEM) == 0))
	{
		DWORD dwOffset = (DWORD)lpSubItem - (DWORD)lpTagPage->lpSubItem;
		DWORD dwIndex = dwOffset / sizeof(SOFT_SUB_ITEM);

		if (dwIndex < lpTagPage->dwNumOfSubItems)
			return dwIndex;
	}

	return INVALID_INDEX;
}

inline DWORD GetIndexBySoftItem(PSOFT_TAG_PAGE lpTagPage, PSOFT_SUB_ITEM lpSubItem)
{
	if (lpTagPage && (((DWORD)lpSubItem - (DWORD)lpTagPage->lpSubItem) % sizeof(SOFT_SUB_ITEM) == 0))
	{
		DWORD dwOffset = (DWORD)lpSubItem - (DWORD)lpTagPage->lpSubItem;
		DWORD dwIndex = dwOffset / sizeof(SOFT_SUB_ITEM);

		if (dwIndex < lpTagPage->dwNumOfSubItems)
			return dwIndex;
	}

	return INVALID_INDEX;
}

inline PSOFT_SUB_ITEM GetSoftItemByIndex(int nIndex)
{
	PSOFT_TAG_PAGE lpTagPage = SoftItem_GetCurrentTagPage();

	if (lpTagPage == NULL) 
		return NULL;
	if ((DWORD)nIndex >= lpTagPage->dwNumOfSubItems) 
		return NULL;

	return &(lpTagPage->lpSubItem[nIndex]);
}

inline LPCWSTR GetSoftItemText(PSOFT_SUB_ITEM lpSubItem)
{
	if (lpSubItem == NULL) 
		return NULL;

	return (lpSubItem->szItemText != NULL) ? lpSubItem->szItemText : lpSubItem->lpszItemText;
}

inline LPCWSTR GetSoftItemTextByIndex(PSOFT_SUB_ITEM lpSubItem, int nIndex)
{
	if (lpSubItem == NULL) 
		return NULL;

	if (lpSubItem->szItemText != NULL)
		return lpSubItem->szItemText;

	return GetStringByIndex(lpSubItem->lpszItemText, nIndex);
}

inline PSOFT_SUB_ITEM GetGroupHeader(PSOFT_TAG_PAGE lpTagPage, PSOFT_SUB_ITEM lpSubItem)
{
	if (lpTagPage == NULL) 
		return NULL;
	if (lpSubItem == NULL) 
		return NULL;
	if (lpSubItem->dwAttributes & SIA_GROUP) 
		return NULL;
	if (lpSubItem->dwGroupIndex >= lpTagPage->dwNumOfSubItems) 
		return NULL;

	if (lpTagPage->lpSubItem[lpSubItem->dwGroupIndex].dwAttributes & SIA_GROUP)
		return &(lpTagPage->lpSubItem[lpSubItem->dwGroupIndex]);

	return NULL;
}

inline DWORD GetGroupOffsetIndex(PSOFT_TAG_PAGE lpTagPage, PSOFT_SUB_ITEM lpSubItem)
{
	if (lpTagPage == NULL) 
		return 0;
	if (lpSubItem == NULL) 
		return 0;
	if (lpSubItem->dwAttributes & SIA_GROUP) 
		return 0;
	if (lpSubItem->dwGroupIndex >= lpTagPage->dwNumOfSubItems) 
		return 0;
	if ((DWORD)lpSubItem > (DWORD)&(lpTagPage->lpSubItem[lpTagPage->dwNumOfSubItems - 1])) 
		return 0;

	DWORD dwOffset = (DWORD)lpSubItem - (DWORD)&(lpTagPage->lpSubItem[lpSubItem->dwGroupIndex]);
	return dwOffset / sizeof(SOFT_SUB_ITEM);
}

inline LPCWSTR GetActiveItemTextByTagPage(PSOFT_TAG_PAGE lpTagPage)
{
	if ((lpTagPage) && (lpTagPage->dwActiveIndex < lpTagPage->dwNumOfSubItems))
	{
		PSOFT_SUB_ITEM lpSubItem = &(lpTagPage->lpSubItem[lpTagPage->dwActiveIndex]);

		return GetSoftItemTextByIndex(lpSubItem, nLangId);
	}

	return NULL;
}

inline LPCWSTR GetActiveItemTextBySoftMenu(PSOFT_MENU lpSoftMenu)
{
	if ((lpSoftMenu) && (lpSoftMenu->dwActiveIndex < lpSoftMenu->dwNumOfTagPages))
	{
		PSOFT_TAG_PAGE lpTagPage = &(lpSoftMenu->lpTagPage[lpSoftMenu->dwActiveIndex]);

		if (lpTagPage->dwActiveIndex < lpTagPage->dwNumOfSubItems)
		{
			PSOFT_SUB_ITEM lpSubItem = &(lpTagPage->lpSubItem[lpTagPage->dwActiveIndex]);

			return GetSoftItemTextByIndex(lpSubItem, nLangId);
		}
	}

	return NULL;
}

//更新复选框按钮状态
inline void UpdateCheckBoxState(PSOFT_SUB_ITEM lpSubItem)
{
	if (CHK_FLAGS(lpSubItem->dwAttributes, SIA_GETCHKSTATE) && (lpSubItem->lpOpt[2]))
	{
		if (lpSubItem->lpOpt[12])
		{
			lpSubItem->lpOpt[2] = (void*)((DWORD)lpSubItem->lpOpt[2] - BASE);
			lpSubItem->lpOpt[12] = 0;
		}
		if (GetButtonCheckState(lpSubItem->lpOpt[2], (int)lpSubItem->lpOpt[3]))
		{
			SET_FLAGS(lpSubItem->dwAttributes, SIAE_CHECKED);
			Button_SetCheck(lpSubItem->_hWnd, BST_CHECKED);
		}
		else
		{
			NOT_FLAGS(lpSubItem->dwAttributes, SIAE_CHECKED);
			Button_SetCheck(lpSubItem->_hWnd, BST_UNCHECKED);
		}
	}
	else if (CHK_FLAGS(lpSubItem->dwAttributes, SIA_GETBTNSTATE) && (lpSubItem->lpOpt[2]))
	{
		int nOnOff = 0;

		if (lpSubItem->lpOpt[12])
		{
			lpSubItem->lpOpt[2] = (void*)((DWORD)lpSubItem->lpOpt[2] - BASE);
			lpSubItem->lpOpt[12] = 0;
		}
		GetButtonStateIndex((char *)lpSubItem->lpOpt[2], lpSubItem->lpOpt[3], &nOnOff, (int)lpSubItem->lpOpt[0]);

		if (GET_BYTE_0(nOnOff) != 0)
		{
			SET_FLAGS(lpSubItem->dwAttributes, SIAE_CHECKED);
			Button_SetCheck(lpSubItem->_hWnd, BST_CHECKED);
		}
		else
		{
			NOT_FLAGS(lpSubItem->dwAttributes, SIAE_CHECKED);
			Button_SetCheck(lpSubItem->_hWnd, BST_UNCHECKED);
		}
	}
}
