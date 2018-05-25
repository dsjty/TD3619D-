﻿#include "stdafx.h"

//窗口hook句柄
HHOOK hhkcwrp_MainWnd = NULL;
HHOOK hhkcwp_MainWnd = NULL;

extern HWND hwSoftItem;
extern WORD wWidth_MainWnd, wHeight_MainWnd;

void wndhk_SoftItem_FineTune(LPCWPRETSTRUCT lpCWPR, LPNMUPDOWN lpNMUD, PSOFT_SUB_ITEM lpSubItem, DWORD dwFlags)
{
	if (!lpSubItem) 
		return;
	if (!lpSubItem->lpOpt[1]) 
		return;

	double dblOutput;
	fn_GetDouble fnGetDbl = GetAddr_GetDbl(lpSubItem->lpOpt[1]);
	char szText[MAX_PATH];
	WCHAR wcsText[MAX_PATH];

	if (lpSubItem->lpOpt[2])
		SetInputBtnStateIndex(lpSubItem->lpOpt[2], (int)lpSubItem->lpOpt[3]);

	if (CHK_FLAGS(dwFlags, 0x01))
	{
		if (InputFineTune2(lpSubItem->lpOpt[1], &dblOutput, fnGetDbl(lpSubItem->lpOpt[1]), -(lpNMUD->iDelta)))
		{
			FmtValueToStringEx(lpSubItem->lpOpt[1], szText, MAX_PATH, dblOutput);

			MultiByteToWideChar(1253, 0, szText, -1, wcsText, MAX_PATH);

			SetWindowTextW((HWND)lpSubItem->lpOpt[4], wcsText);
		}
	}
	else
	{
		if (InputFineTune(lpSubItem->lpOpt[1], &dblOutput, fnGetDbl(lpSubItem->lpOpt[1]), -(lpNMUD->iDelta)))
		{
			FmtValueToStringEx(lpSubItem->lpOpt[1], szText, MAX_PATH, dblOutput);
			MultiByteToWideChar(1253, 0, szText, -1, wcsText, MAX_PATH);

			SetWindowTextW((HWND)lpSubItem->lpOpt[4], wcsText);
		}
	}

	if (CHK_FLAGS(lpSubItem->dwAttributes, SIA_PSTMSG_432_2))
		PSTMSG_432_2();
}

void wndhk_SoftItem_OnCommand(LPCWPRETSTRUCT lpCWPR, PSOFT_SUB_ITEM lpSubItem)
{
	WORD wNc = HIWORD(lpCWPR->wParam), wId = LOWORD(lpCWPR->wParam);

	switch (lpSubItem->dwStyle)
	{
	case SIS_ComboButtonEx:
	case SIS_ComboRadioButtonEx:
		if ((wNc == CBN_SELENDOK) && CHK_FLAGS(lpSubItem->dwFlags, SIF_FN_SELECTED) && (lpSubItem->lpEvent[FNID_SELECTED]))
		{
			func_ItemEvent_Selected fnSelected = (func_ItemEvent_Selected)lpSubItem->lpEvent[FNID_SELECTED];
			fnSelected(0, 0, 0, lpSubItem, ComboBox_GetCurSel((HWND)lpSubItem->lpOpt[4]));
			UpdateCurrentItemsAndData();
		}
		break;
	}
}

void wndhk_SoftItem_OnNotify(LPCWPRETSTRUCT lpCWPR, PSOFT_SUB_ITEM lpSubItem)
{
	LPNMHDR lpNMHDR = (LPNMHDR)lpCWPR->lParam;

	switch (GetWindowLong(lpNMHDR->hwndFrom, GWL_USERDATA))
	{
	case SIA_FINETUNE://旋钮
	{
		SoftItem_Finetune(lpSubItem, -(((LPNMUPDOWN)lpCWPR->lParam)->iDelta), 1);
	}
	break;
	case SIA_FINETUNE2:
	{
		SoftItem_Finetune2(lpSubItem, -(((LPNMUPDOWN)lpCWPR->lParam)->iDelta));
	}
	break;
	default:
		break;
	}
}

void wndhk_OnCommand(LPCWPRETSTRUCT lpCWPR)
{
	HWND hParentWnd = GetParent(lpCWPR->hwnd);

	if (hParentWnd == hwSoftItem)
	{
		PSOFT_SUB_ITEM lpSubItem = (PSOFT_SUB_ITEM)GetWindowLong(lpCWPR->hwnd, GWL_USERDATA);
		PSOFT_SUB_ITEM lpSubItem2 = GetSoftItemByIndex(GetWindowLong(lpCWPR->hwnd, GWL_ID) - 1000);

		if (lpSubItem != lpSubItem2)
			lpSubItem = NULL;

		if (lpSubItem) 
			wndhk_SoftItem_OnCommand(lpCWPR, lpSubItem);
	}
}

void wndhk_OnNotify(LPCWPRETSTRUCT lpCWPR)
{
	HWND hParentWnd = GetParent(lpCWPR->hwnd);

	if (hParentWnd == hwSoftItem)
	{
		PSOFT_SUB_ITEM lpSubItem = (PSOFT_SUB_ITEM)GetWindowLong(lpCWPR->hwnd, GWL_USERDATA);
		PSOFT_SUB_ITEM lpSubItem2 = GetSoftItemByIndex(GetWindowLong(lpCWPR->hwnd, GWL_ID) - 1000);

		if (lpSubItem != lpSubItem2)
			lpSubItem = NULL;

		if (lpSubItem)
			wndhk_SoftItem_OnNotify(lpCWPR, lpSubItem);
	}
}

//CallWndProc Hook
LRESULT CALLBACK cwphk_MainWnd(int nCode, WPARAM wParam, LPARAM lParam)
{
#define _LPCWPS_           ((LPCWPSTRUCT)lParam)
	if ((_LPCWPS_->message == WM_SIZE) && (_LPCWPS_->hwnd == hwMainWnd))
	{
		wWidth_MainWnd = LOWORD(_LPCWPS_->lParam);
		wHeight_MainWnd = HIWORD(_LPCWPS_->lParam);
	}
	return CallNextHookEx(hhkcwp_MainWnd, nCode, wParam, lParam);
#undef _LPCWPS_
}

//CallWndRetProc Hook
LRESULT CALLBACK cwrphk_MainWnd(int nCode, WPARAM wParam, LPARAM lParam)
{
	LPCWPRETSTRUCT lpCWPR = (LPCWPRETSTRUCT)lParam;

	switch (lpCWPR->message)
	{
	case WM_COMMAND:
		wndhk_OnCommand(lpCWPR);
		break;

	case WM_NOTIFY:
		wndhk_OnNotify(lpCWPR);
		break;

	case WM_ACTIVATE:
	{
		if ((lpCWPR->hwnd == hwMainWnd))
			SetFocus(hwSoftMenu);
	}
	break;

	case WM_SETFOCUS:
	{
		HWND hP1 = GetParent(lpCWPR->hwnd);
		DWORD dwId;

		if (hP1 == hwSoftItem)
		{
			dwId = GetWindowLong(lpCWPR->hwnd, GWL_ID);

			if ((dwId >= 1000) && (dwId <= 65535))
			{
				SoftItem_SetFocusValue(dwId - 1000, 0x00);
				SoftItem_InvalidLastFocus();
			}

			InvalidateRect(lpCWPR->hwnd, NULL, TRUE);
			UpdateWindow(lpCWPR->hwnd);
		}
		else if (GetParent(hP1) == hwSoftItem)
		{
			dwId = GetWindowLong(hP1, GWL_ID);

			if ((dwId >= 1000) && (dwId <= 65535))
			{
				SoftItem_SetFocusValue(dwId - 1000, 0x01);
				SoftItem_InvalidLastFocus();
			}

			InvalidateRect(hP1, NULL, TRUE);
			UpdateWindow(hP1);
		}
// 		else if (hP1 == hwToolbar)
// 		{
// 			SetFocus(hwSoftMenu);
// 		}
	}
	break;
	}
	return CallNextHookEx(hhkcwrp_MainWnd, nCode, wParam, lParam);
}

