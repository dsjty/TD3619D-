#include "stdafx.h"

extern WORD wWidth_MainWnd, wHeight_MainWnd;

const LPCWSTR wcsListTristate2[] =
{
	L"Off\0关闭\0關閉\0\0",
	L"Absolute\0绝对\0絕對\0\0",
	L"Margin\0相对\0相對\0\0"
};

const LPCWSTR wcsList12[] =
{
	L"1\0\0",
	L"2\0\0",
	L"3\0\0",
	L"4\0\0",
	L"5\0\0",
	L"6\0\0",
	L"7\0\0",
	L"8\0\0",
	L"9\0\0",
	L"10\0\0",
	L"11\0\0",
	L"12\0\0"
};

const LPCWSTR wcsListFLType[] =
{
	L"Bandpass\0带通\0帶通\0\0",
	L"Lowpass Step\0低通阶跃\0低通階躍\0\0",
	L"Lowpass Imp\0低通脉冲\0低通脈衝\0\0"
};

const LPCWSTR wcsListFLUnit[] =
{
	L"Seconds\0秒\0秒\0\0",
	L"Meters\0米\0米\0\0",
	L"Feet\0英尺\0英呎\0\0"
};

const LPCWSTR wcsListFLWindow[] =
{
	L"Maximum\0最大\0最大0\0",
	L"Normal\0正常\0正常\0\0",
	L"Minimum\0最小\0最小\0\0"
};

const LPCWSTR wcsListFLRefType[] =
{
	L"One Way\0\0",
	L"Round Trip\0\0"
};

const LPCWSTR wcsListPR[] =
{
	L"Z:Reflection\0Z:反射\0Z:反射\0\0",
	L"Z:Transmission\0Z:传输\0Z:傳輸\0\0",
	L"Y:Reflection\0Y:反射\0Z:反射\0\0",
	L"Y:Transmission\0Y:传输\0Y:傳輸\0\0",
	L"1 / S\0\0"
};


int WINAPI fnItemClicked_OpenELL(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
// 	if (wParam == IC_CLICKED_LAST)
// 	{
// 		OrigSoftMenu_Enter(CA_ANALYSIS);
// 		OrigSoftMenu_Enter(CA_LIMITTEST);
// 
// 		OrigSoftMenu_Enter(lpSubItem->lpThis);
// 		OrigSoftMenu_UpdateItems(lpSubItem->lpThis);
// 
// 		PSTMSG(hwMainWnd, WM_SIZE, SIZE_RESTORED, MAKELPARAM(wWidth_MainWnd, wHeight_MainWnd));
// 		Toolbar_Redraw();
// 	}

	return 0;
}

int WINAPI fnItemClicked_CloseELL(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
// 	if (wParam == IC_CLICKED_LAST)
// 	{
// 		OrigSoftMenu_Leave(lpSubItem->lpThis);
// 
// 		PSTMSG(hwMainWnd, WM_SIZE, SIZE_RESTORED, MAKELPARAM(wWidth_MainWnd, wHeight_MainWnd));
// 		Toolbar_Redraw();
// 	}

	return 0;
}

int WINAPI fnItemClicked_OpenERL(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
// 	if (wParam == IC_CLICKED_LAST)
// 	{
// 		OrigSoftMenu_Enter(CA_ANALYSIS);
// 
// 		OrigSoftMenu_Enter(CA_RIPPLELIMIT);
// 
// 		OrigSoftMenu_Enter(lpSubItem->lpThis);
// 		OrigSoftMenu_UpdateItems(lpSubItem->lpThis);
// 
// 		PSTMSG(hwMainWnd, WM_SIZE, SIZE_RESTORED, MAKELPARAM(wWidth_MainWnd, wHeight_MainWnd));
// 		Toolbar_Redraw();
// 	}

	return 0;
}

int WINAPI fnItemClicked_CloseERL(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
// 	if (wParam == IC_CLICKED_LAST)
// 	{
// 		OrigSoftMenu_Leave(lpSubItem->lpThis);
// 
// 		PSTMSG(hwMainWnd, WM_SIZE, SIZE_RESTORED, MAKELPARAM(wWidth_MainWnd, wHeight_MainWnd));
// 		Toolbar_Redraw();
// 	}
	return 0;
}

int WINAPI fnUpdateData_Type(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem);
int WINAPI fnUpdateData_Unit(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem);

int WINAPI fnUpdateData_RefType(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	int nIndex = 0;
	LPCWSTR *lppWStr = (LPCWSTR *)lpSubItem->lpParams;
	LPCWSTR lpText = NULL;

	if (lpSubItem->lpOpt[2] == NULL) return -1;

	GetButtonStateIndex((char *)lpSubItem->lpOpt[2], lpSubItem->lpOpt[3], &nIndex, (int)lpSubItem->lpOpt[0]);

	if ((*lppWStr) && ((DWORD)nIndex < lpSubItem->dwNumberOfParams))
	{
		lpText = GetStringByIndex(lppWStr[nIndex], nLangId);
	}
	else
		lpText = L"!ERROR!";

	if (lpSubItem->lpOpt[4])
		SetWindowTextW((HWND)lpSubItem->lpOpt[4], lpText);

	return 0;
}

int WINAPI fnItemClicked_RefType(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	if (wParam == IC_CLICKED_LAST)
	{
		fnUpdateData_RefType(0, 0, 0, lpSubItem);
	}

	return 0;
}

int WINAPI fnUpdateData_P1C_Len(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	if (CHK_NOFLAGS(lpSubItem->dwFlags, SIF_NOT_ENTER))
		OrigSoftMenu_Enter(CA_SRL);

	OrigSoftMenu_ItemClicked2(CA_SRL, TA_SRL, 1);

	return 0;
}

int WINAPI fnUpdateIndex_P2C_Len(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	DWORD *dwIndex = (DWORD *)0x00BB8C90;

	if (CHK_NOFLAGS(lpSubItem->dwFlags, SIF_NOT_ENTER))
		OrigSoftMenu_Enter(CA_SRL);

	OrigSoftMenu_ItemClicked2(CA_SRL, TA_SRL, 2);

	return 0;
}

//极限测试子条目
SOFT_SUB_ITEM subitemLimitTest[] =
{
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		0,
		L"Limit Test\0极限测试\0極限測試\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00010000, 0, (void *)0x00B779B4, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_LIMITTEST,
		CA_LIMITTEST,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 1090, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		1,
		L"Limit Line\0极限线标\0極限線標\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00050400, 0, (void *)0x00B77A20, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_LIMITTEST,
		CA_LIMITTEST,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		2,
		L"Clip Lines\0间隔线\0間隔線\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00090800, 0, (void *)0x00B779EC, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_LIMITTEST,
		CA_LIMITTEST,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		5,
		L"Fail Sign\0失败标志\0失敗標誌\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x000D0C00, 0, (void *)0x00B6076C, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_LIMITTEST,
		CA_LIMITTEST,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		0,
		SIA_FULLLINE,
		SIS_Delimiter,
		0,
		NULL,
		NULL,
		40,
		20,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_FN_CLICKED,
		SIA_FULLLINE,
		SIS_ButtonEx,
		3,
		L"Open Edit Limit Line\0打开编辑极限线标\0打開編輯極限線標\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		{ 0, &fnItemClicked_OpenELL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_LT_ELL,
		CA_LT_ELL,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_FN_CLICKED | SIF_FN_SETFOCUS,
		SIA_FULLLINE,
		SIS_ButtonEx,
		3,
		L"Close Edit Limit Line\0关闭编辑极限线标\0關閉編輯極限線標\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		{ 0, &fnItemClicked_CloseELL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_LT_ELL,
		CA_LT_ELL,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		0,
		L"Delete\0删除\0刪除\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_LT_ELL,
		CA_LT_ELL,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		1,
		L"Add\0增加\0增加\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_LT_ELL,
		CA_LT_ELL,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		0,
		L"Clear Limit Table\0清除极限表格\0清除極限表格\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_LT_ELL_CLT,
		CA_LT_ELL_CLT,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		3,
		L"Export to CSV file\0导出到CSV文件\0導出到CSV文件\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_LT_ELL,
		CA_LT_ELL,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		4,
		L"Import from CSV file\0从CSV文件导入\0從CSV文件導入\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_LT_ELL,
		CA_LT_ELL,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		0,
		SIA_FULLLINE,
		SIS_Delimiter,
		0,
		NULL,
		NULL,
		40,
		20,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE,
		SIS_InputButtonEx,
		0,
		L"Stimulus Offset\0激励偏移\0激勵偏移\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BB8AB8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_LT_LLO,
		CA_LT_LLO,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE,
		SIS_InputButtonEx,
		1,
		L"Amplitude Offset\0幅度偏移\0幅度偏移\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BB8AE8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_LT_LLO,
		CA_LT_LLO,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		2,
		L"Marker -> Amplitude Offset\0频标 -> 幅度偏移\0頻標 -> 幅度偏移\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_LT_LLO,
		CA_LT_LLO,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
};


//波动极限子条目
SOFT_SUB_ITEM subitemRippleLimit[] =
{
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		0,
		L"Ripple Limit Test\0波动极限测试\0波動極限測試\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00010000, 0, (void *)0x00B77C5C, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_RIPPLELIMIT,
		CA_RIPPLELIMIT,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 1091, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		1,
		L"Ripple Limit\0波动极限\0波動極限\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00050400, 0, (void *)0x00B77C8C, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_RIPPLELIMIT,
		CA_RIPPLELIMIT,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		5,
		L"Fail Sign\0失败标志\0失敗標誌\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00090800, 0, (void *)0x00B6076C, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_RIPPLELIMIT,
		CA_RIPPLELIMIT,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_FN_SELECTED | SIF_FN_UPDATEDATA,
		SIA_FULLLINE,
		SIS_ComboButtonEx,
		2,
		L"Ripple Value\0波动值\0波動值\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ (void *)0x00080700, 0, (void *)0x00B77DBC, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, &fnItemSelected_Default, &fnUpdateData_Default, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_RL_RV,
		CA_RL_RV,
		sizeof(wcsListTristate2) / sizeof(LPCWSTR),
		wcsListTristate2,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_FN_SELECTED | SIF_FN_UPDATEDATA,
		SIA_FULLLINE,
		SIS_ComboButtonEx,
		3,
		L"Ripple Band\0波动带宽\0波動帶寬\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ (void *)0x00010000, 0, (void *)0x00B77CC8, (void *)0x0B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, &fnItemSelected_Default, &fnUpdateData_DEC_Default, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_RL_RBW,
		CA_RL_RBW,
		sizeof(wcsList12) / sizeof(LPCWSTR),
		wcsList12,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		0,
		SIA_FULLLINE,
		SIS_Delimiter,
		0,
		NULL,
		NULL,
		40,
		20,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_FN_CLICKED,
		SIA_FULLLINE,
		SIS_ButtonEx,
		4,
		L"Open Edit Ripple Limit\0打开编辑波动极限\0打開編輯波動極限\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		{ 0, &fnItemClicked_OpenERL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_RL_ERL,
		CA_RL_ERL,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_FN_CLICKED| SIF_FN_SETFOCUS,
		SIA_FULLLINE,
		SIS_ButtonEx,
		4,
		L"Close Edit Ripple Limit\0关闭编辑波动极限\0關閉編輯波動極限\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		{ 0, &fnItemClicked_CloseERL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_RL_ERL,
		CA_RL_ERL,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		0,
		L"Delete\0删除\0刪除\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_RL_ERL,
		CA_RL_ERL,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		1,
		L"Add\0增加\0增加\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_RL_ERL,
		CA_RL_ERL,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		0,
		L"Clear Ripple Limit Table\0清除波动极限表格\0清除波動極限表格\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_RL_ERL_CRLT,
		CA_RL_ERL_CRLT,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		3,
		L"Export to CSV file\0导出到CSV文件\0導出到CSV文件\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_RL_ERL,
		CA_RL_ERL,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		4,
		L"Import from CSV file\0从CSV文件导入\0從CSV文件導入\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_RL_ERL,
		CA_RL_ERL,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
};


//带宽极限子条目
SOFT_SUB_ITEM subitemBandwidthLimit[] =
{
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		0,
		L"BW Test\0带宽测试\0帶寬測試\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00020100, 0, (void *)0x00B77EF8, (void *)0x06, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_BWLIMIT,
		CA_BWLIMIT,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 1092, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		1,
		L"BW Display\0带宽显示\0帶寬顯示\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00060500, 0, (void *)0x00B77F94, (void *)0x06, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_BWLIMIT,
		CA_BWLIMIT,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		2,
		L"BW Marker\0带宽标志\0帶寬標誌\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x000A0900, 0, (void *)0x00B77F60, (void *)0x06, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_BWLIMIT,
		CA_BWLIMIT,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		6,
		L"Fail Sign\0失败标志\0失敗標誌\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x000E0D00, 0, (void *)0x00B6076C, (void *)0x06, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_BWLIMIT,
		CA_BWLIMIT,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE | SIA_INPUT_TIME,
		SIS_InputButtonEx,
		3,
		L"N dB Points\0N dB点\0N dB點\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BB8A90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_BWLIMIT,
		CA_BWLIMIT,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE,
		SIS_InputButtonEx,
		4,
		L"Min Bandwidth\0最小带宽\0最小帶寬\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BC8708, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_BWLIMIT,
		CA_BWLIMIT,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE,
		SIS_InputButtonEx,
		5,
		L"Max Bandwidth\0最大带宽\0最大帶寬\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BC8758, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_BWLIMIT,
		CA_BWLIMIT,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
};


//故障定位子条目
SOFT_SUB_ITEM subitemFaultLocation[] =
{
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		0,
		L"Fault Location\0故障定位\0故障定位\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00030200, 0, (void *)0x00B5BFA0, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_FAULTLOC,
		CA_FAULTLOC,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE,
		SIS_InputButtonEx,
		1,
		L"Start\0起始\0起始\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BB8C18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_FAULTLOC,
		CA_FAULTLOC,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE,
		SIS_InputButtonEx,
		2,
		L"Stop\0终止\0終止\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BB8BC8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_FAULTLOC,
		CA_FAULTLOC,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE,
		SIS_InputButtonEx,
		3,
		L"Center\0中心频率\0中心頻率\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BB8B78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_FAULTLOC,
		CA_FAULTLOC,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE,
		SIS_InputButtonEx,
		4,
		L"Span\0带宽\0帶寬\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BB8B28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_FAULTLOC,
		CA_FAULTLOC,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		5,
		L"Set Freq Low Pass\0设置频率低通\0設置頻率低通\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_FAULTLOC,
		CA_FAULTLOC,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_FN_SELECTED | SIF_FN_UPDATEDATA,
		SIA_FULLLINE,
		SIS_ComboButtonEx,
		6,
		L"Type\0类型\0類型\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ (void *)0x00030200, 0, (void *)0x00B7780C, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, &fnItemSelected_Default, &fnUpdateData_Type, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_FL_TYPE,
		CA_FL_TYPE,
		sizeof(wcsListFLType) / sizeof(LPCWSTR),
		wcsListFLType,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE | SIA_INPUT_TIME,
		SIS_InputButtonEx,
		9,
		L"Cable Loss\0电缆损耗\0電纜損耗\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BB8B10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_FAULTLOC,
		CA_FAULTLOC,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_FN_SELECTED | SIF_FN_UPDATEDATA,
		SIA_FULLLINE,
		SIS_ComboButtonEx,
		10,
		L"Unit\0单位\0單位\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ (void *)0x00161500, 0, (void *)0x00B772AC, (void *)0x91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, &fnItemSelected_Default, &fnUpdateData_Unit, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_FL_UNIT,
		CA_FL_UNIT,
		sizeof(wcsListFLUnit) / sizeof(LPCWSTR),
		wcsListFLUnit,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_FN_SELECTED | SIF_FN_UPDATEDATA,
		SIA_FULLLINE,
		SIS_ComboButtonEx,
		10,
		L"Window\0窗口\0窗口\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ (void *)0x00080700, 0, (void *)0x00B77774, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, &fnItemSelected_Default, &fnUpdateData_Default, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_FL_WIND,
		CA_FL_WIND,
		sizeof(wcsListFLWindow) / sizeof(LPCWSTR),
		wcsListFLWindow,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE,
		SIS_InputButtonEx,
		3,
		L"Impulse Width\0Impulse Width\0Impulse Width\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BB8D00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_FL_WIND,
		CA_FL_WIND,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE,
		SIS_InputButtonEx,
		4,
		L"Kalser Beta\0Kalser Beta\0Kalser Beta\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BB8CE8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_FL_WIND,
		CA_FL_WIND,
		0,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK | SIF_FN_CLICKED | SIF_FN_UPDATEDATA,
		SIA_FULLLINE | SIA_EXLBL | SIA_UPDATEITEM,
		SIS_ButtonEx,
		8,
		L"Reflection Type\0反射类型\0反射類型\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ (void *)0x00111000, 0, (void *)0x00B5BAE4, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, &fnItemClicked_RefType, 0, &fnUpdateData_RefType, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_FAULTLOC,
		CA_FAULTLOC,
		sizeof(wcsListFLRefType) / sizeof(LPCWSTR),
		wcsListFLRefType,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
};

int WINAPI fnUpdateData_Type(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	if (lpSubItem && lpSubItem->lpThis)
	{
		int nIndex = 0;
		nIndex = GetSubMenuSelected(lpSubItem->lpThis);
		ComboBox_SetCurSel((HWND)lpSubItem->lpOpt[4], nIndex);

		if (nIndex == 1)
			subitemFaultLocation[10].szItemText = L"Step Rise\0Step Rise\0Step Rise\0\0";
		else
			subitemFaultLocation[10].szItemText = L"Impulse Width\0Impulse Width\0Impulse Width\0\0";


		if (subitemFaultLocation[10]._hWnd)
		{
			SetWindowTextW(subitemFaultLocation[10]._hWnd, GetStringByIndex(subitemFaultLocation[10].szItemText, nLangId));
			InvalidateRect(subitemFaultLocation[10]._hWnd, NULL, TRUE);
			UpdateWindow(subitemFaultLocation[10]._hWnd);
		}
	}

	return 0;
}

int WINAPI fnUpdateData_Unit(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	if (lpSubItem && lpSubItem->lpThis)
	{
		int nIndex = 0;
		nIndex = GetSubMenuSelected(lpSubItem->lpThis);

		if (nIndex == 0)
		{
			SET_FLAGS(subitemFaultLocation[1].dwAttributes, SIA_INPUT_TIME);
			SET_FLAGS(subitemFaultLocation[2].dwAttributes, SIA_INPUT_TIME);
			SET_FLAGS(subitemFaultLocation[3].dwAttributes, SIA_INPUT_TIME);
			SET_FLAGS(subitemFaultLocation[4].dwAttributes, SIA_INPUT_TIME);
		}
		else
		{
			NOT_FLAGS(subitemFaultLocation[1].dwAttributes, SIA_INPUT_TIME);
			NOT_FLAGS(subitemFaultLocation[2].dwAttributes, SIA_INPUT_TIME);
			NOT_FLAGS(subitemFaultLocation[3].dwAttributes, SIA_INPUT_TIME);
			NOT_FLAGS(subitemFaultLocation[4].dwAttributes, SIA_INPUT_TIME);
		}

		ComboBox_SetCurSel((HWND)lpSubItem->lpOpt[4], nIndex);
	}

	return 0;
}

//转换子条目
SOFT_SUB_ITEM subitemConversion[] =
{
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		0,
		L"Conversion\0转换\0轉換\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00010000, 0, (void *)0x00B77FF0, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_CONV,
		CA_CONV,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_FN_SELECTED | SIF_FN_UPDATEDATA,
		SIA_FULLLINE,
		SIS_ComboButtonEx,
		1,
		L"Function\0功能\0功能\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ (void *)0x000C0B00, 0, (void *)0x00B7804C, (void *)0x14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, &fnItemSelected_Default, &fnUpdateData_Default, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_CONV_FN,
		CA_CONV_FN,
		sizeof(wcsListPR) / sizeof(LPCWSTR),
		wcsListPR,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
};

int WINAPI fnTagPageEnter_LimitTest(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage)
{
	OrigSoftMenu_UpdateItems(CA_ANALYSIS);
	OrigSoftMenu_UpdateItems(CA_LIMITTEST);

	OrigSoftMenu_UpdateItems(CA_LT_LLO);
	OrigSoftMenu_Enter(CA_LT_LLO);
	return 0;
}

int WINAPI fnTagPageLeave_LimitTest(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage)
{
	OrigSoftMenu_Leave(CA_LT_ELL);
	return 0;
}

int WINAPI fnTagPageEnter_RippleLimit(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage)
{
	OrigSoftMenu_UpdateItems(CA_ANALYSIS);
	OrigSoftMenu_UpdateItems(CA_RIPPLELIMIT);

	return 0;
}


int WINAPI fnTagPageLeave_RippleLimit(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage)
{
	OrigSoftMenu_Leave(CA_RL_ERL);
	return 0;
}

int WINAPI fnTagPageEnter_BWLimit(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage)
{
	OrigSoftMenu_UpdateItems(CA_ANALYSIS);
	OrigSoftMenu_UpdateItems(CA_BWLIMIT);

	return 0;
}

int WINAPI fnTagPageEnter_FaultLoc(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage)
{
	OrigSoftMenu_UpdateItems(CA_ANALYSIS);
	OrigSoftMenu_UpdateItems(CA_FAULTLOC);

	return 0;
}

int WINAPI fnTagPageEnter_Conversion(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage)
{
	OrigSoftMenu_UpdateItems(CA_ANALYSIS);
	OrigSoftMenu_UpdateItems(CA_CONV);

	return 0;
}


//分析子菜单
SOFT_TAG_PAGE submenuAnalysis[] =
{
	{
		TPF_FN_ENTER /* | TPF_FN_LEAVE */,
		0,
		L"Limit Test\0极限测试\0極限測試\0\0",
		NULL,
		sizeof(subitemLimitTest) / sizeof(SOFT_SUB_ITEM),
		subitemLimitTest,
		RESERVE_DWORD4,
		&fnTagPageEnter_LimitTest,
		&fnTagPageLeave_LimitTest,
		0,
		{ L"::/Measurement/Data_Analysis/Limit_Test.htm", (void*)1090, 0, 0 }
	}
	,
	{
		TPF_FN_ENTER | TPF_FN_LEAVE,
		0,
		L"Ripple Limit\0波动极限\0波動極限\0\0",
		NULL,
		sizeof(subitemRippleLimit) / sizeof(SOFT_SUB_ITEM),
		subitemRippleLimit,
		RESERVE_DWORD4,
		&fnTagPageEnter_RippleLimit,
		&fnTagPageLeave_RippleLimit,
		0,
		{ L"::/Measurement/Data_Analysis/Ripple_Test.htm", (void*)1091, 0, 0 }
	}
	,
	{
		TPF_FN_ENTER,
		0,
		L"Bandwidth Limit\0带宽极限\0帶寬極限\0\0",
		NULL,
		sizeof(subitemBandwidthLimit) / sizeof(SOFT_SUB_ITEM),
		subitemBandwidthLimit,
		RESERVE_DWORD4,
		&fnTagPageEnter_BWLimit,
		NULL,
		0,
		{ L"::/Measurement/Data_Analysis/Bandwidth_Test.htm", (void*)1092, 0, 0 }
	}
	,
	{
		TPF_FN_ENTER,
		0,
		L"Fault Location\0故障定位\0故障定位\0\0",
		NULL,
		sizeof(subitemFaultLocation) / sizeof(SOFT_SUB_ITEM),
		subitemFaultLocation,
		RESERVE_DWORD4,
		&fnTagPageEnter_FaultLoc,
		NULL,
		0,
		{ 0, 0, 0, 0 }
	}
	,
	{
		TPF_FN_ENTER,
		0,
		L"Conversion\0转换\0轉換\0\0",
		NULL,
		sizeof(subitemConversion) / sizeof(SOFT_SUB_ITEM),
		subitemConversion,
		RESERVE_DWORD4,
		&fnTagPageEnter_Conversion,
		NULL,
		0,
		{ 0, L"::/Measurement/Data_Analysis/Performing_Parameter_Conversion_of_Measurement_Results.htm", 0, 0 }
	}
};

//分析主菜单
SOFT_MENU menuAnalysis =
{
	0,
	0,
	L"Analysis\0分析\0分析\0\0",
	NULL,
	sizeof(submenuAnalysis) / sizeof(SOFT_TAG_PAGE),
	submenuAnalysis,
	NULL,
	NULL,
	0,
	{ 0, 0, 0, 0 }
};

