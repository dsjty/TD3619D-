#include "stdafx.h"

extern SOFT_SUB_ITEM subitemChannelsConfig[14];
extern SOFT_SUB_ITEM subitemTracesConfig[15];

int WINAPI fnTagPageEnter_ChannelsConfig(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage);
int WINAPI fnTagPageEnter_TracesConfig(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage);

const LPCWSTR wcsListDisplay[] =
{
	L"Data\0数据\0數據\0\0",
	L"Memory\0存储器\0存儲器\0\0",
	L"Data & Memory\0数据 & 存储器\0數據 & 存儲器\0\0",
	L"OFF\0关闭\0關閉\0\0"
};

const LPCWSTR wcsListDataMath[] =
{
	L"OFF\0关闭\0關閉\0\0",
	L"Data / Mem\0数据 / 存储器\0數據 / 存儲器\0\0",
	L"Data * Mem\0数据 * 存储器\0數據 * 存儲器\0\0",
	L"Data - Mem\0数据 - 存储器\0數據 - 存儲器\0\0",
	L"Data + Mem\0数据 + 存储器\0數據 + 存儲器\0\0"
};

const LPCWSTR wcsListGL[] =
{
	L"Auto\0自动\0自動\0\0",
	L"Relative\0相对\0相對\0\0"
};

int WINAPI fnUpdateData_DM(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	int nIndex = 0;

	if (lpSubItem->lpOpt[2] == NULL) return -1;

	GetButtonStateIndex((char *)lpSubItem->lpOpt[2], lpSubItem->lpOpt[3], &nIndex, (int)lpSubItem->lpOpt[0]);

	switch (nIndex)
	{
	case 1:
		nIndex = 3;
		break;
	case 2:
		nIndex = 1;
		break;
	case 3:
		nIndex = 4;
		break;
	case 4:
		nIndex = 2;
		break;
	}

	ComboBox_SetCurSel((HWND)lpSubItem->lpOpt[4], nIndex);

	return 0;
}

int WINAPI fnUpdateData_GL(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	int nIndex = 0;
	LPCWSTR lpText = NULL;

	if (lpSubItem->lpOpt[2] == NULL)
		return -1;

	GetButtonStateIndex((char *)lpSubItem->lpOpt[2], lpSubItem->lpOpt[3], &nIndex, (int)lpSubItem->lpOpt[0]);

	__try
	{
		LPCWSTR *lppWStr = (LPCWSTR *)lpSubItem->lpParams;
		
		if ((lppWStr) && ((DWORD)nIndex < lpSubItem->dwNumberOfParams))
		{
			lpText = GetStringByIndex(lppWStr[nIndex], nLangId);
		}
		else
			lpText = L"!ERROR!";
	}
	__except (1)
	{
		wstring *lppWStr = (wstring *)lpSubItem->lpParams;

		if ((lppWStr) && ((DWORD)nIndex < lpSubItem->dwNumberOfParams))
		{
			lpText = GetStringByIndex(lppWStr[nIndex].c_str(), nLangId);
		}
		else
			lpText = L"!ERROR!";
	}
	if (lpSubItem->lpOpt[4])
		SetWindowTextW((HWND)lpSubItem->lpOpt[4], lpText);

	return 0;
}

int WINAPI fnItemClicked_GL(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	if (wParam == IC_CLICKED_LAST)
	{
		fnUpdateData_GL(0, 0, 0, lpSubItem);
	}

	return 0;
}


//存储子条目
static SOFT_SUB_ITEM subitemDisplay[] =
{
	{
		SIF_FN_SELECTED | SIF_FN_UPDATEDATA,
		SIA_FULLLINE,
		SIS_ComboButtonEx,
		0,
		L"Display\0显示\0顯示\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		RESERVE_DWORD16,
		{ 0, 0, &fnItemSelected_Default, &fnUpdateData_GetSub_Default, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_DISPLAY_DP,
		CA_DISPLAY_DP,
		sizeof(wcsListDisplay) / sizeof(LPCWSTR),
		wcsListDisplay,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		4,
		L"Data -> Mem\0数据 -> 存储器\0數據 -> 存儲器\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_DISPLAY,
		CA_DISPLAY,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_FN_SELECTED | SIF_FN_UPDATEDATA,
		SIA_FULLLINE,
		SIS_ComboButtonEx,
		0,
		L"Data Math\0数据计算\0數據計算\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ (void *)0x000D0C00, 0, (void *)0x00D6440C, (void *)0x3C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, &fnItemSelected_Default, &fnUpdateData_GetSub_Default, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_DISPLAY_DM,
		CA_DISPLAY_DM,
		sizeof(wcsListDataMath) / sizeof(LPCWSTR),
		wcsListDataMath,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE | SIA_INPUT_TEXT,
		SIS_InputButtonEx,
		9,
		L"Edit Title Lable\0编辑标题标签\0編輯標題標簽\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x010B4818, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_DISPLAY,
		CA_DISPLAY,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		10,
		L"Title Lable\0标题标签\0標題標簽\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00060500, 0, (void *)0x00D64D38, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_DISPLAY,
		CA_DISPLAY,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		11,
		L"Graticule Lable\0网格标签\0網格標簽\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x000A0900, 0, (void *)0x00D64F00, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_DISPLAY,
		CA_DISPLAY,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		12,
		L"Invert Color\0反转颜色\0反轉顏色\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00131200, 0, (void *)0x00D64F8C, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_DISPLAY,
		CA_DISPLAY,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		13,
		L"Frequency\0频率\0頻率\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00232200, 0, (void *)0x00D64B58, (void *)0xA4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_DISPLAY,
		CA_DISPLAY,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		14,
		L"Update\0更新数据\0更新數據\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00252400, 0, (void *)0x00D64F6C, (void *)0xC3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_DISPLAY,
		CA_DISPLAY,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
};

static int WINAPI fnTagPageEnter_Display(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage)
{
	OrigSoftMenu_Enter(CA_DISPLAY);
	OrigSoftMenu_UpdateItems(CA_DISPLAY);

	return 0;
}

//显示子菜单
SOFT_TAG_PAGE submenuDisplay[] =
{
	{
		TPF_FN_ENTER,
		0,
		L"Display\0显示\0顯示\0\0",
		NULL,
		sizeof(subitemDisplay) / sizeof(SOFT_SUB_ITEM),
		subitemDisplay,
		RESERVE_DWORD4,
		&fnTagPageEnter_Display,
		NULL,
		0,
		{ L"::/Measurement/Setting_Measurement_Conditions/setting_window_displays.htm", (void*)1010, 0, 0 }
	}
	,
	{
		TPF_FN_ENTER,
		0,
		L"Allocate Channels\0分配通道\0分配通道\0\0",
		NULL,
		sizeof(subitemChannelsConfig) / sizeof(SOFT_SUB_ITEM),
		subitemChannelsConfig,
		RESERVE_DWORD4,
		&fnTagPageEnter_ChannelsConfig,
		NULL,
		0,
		{ L"::/Measurement/Setting_Measurement_Conditions/Setting_Channels_and_Traces.htm#Setting_channel_display__layout_of_channel_windows_", (void*)1010, 0, 0 }
	}
	,
	{
		TPF_FN_ENTER,
		0,
		L"Allocate Traces\0分配曲线\0分配曲線\0\0",
		NULL,
		sizeof(subitemTracesConfig) / sizeof(SOFT_SUB_ITEM),
		subitemTracesConfig,
		RESERVE_DWORD4,
		&fnTagPageEnter_TracesConfig,
		NULL,
		0,
		{ L"::/Measurement/Setting_Measurement_Conditions/Setting_Channels_and_Traces.htm#Setting_trace_display", (void*)1010, 0, 0 }
	}
};

//显示主菜单
SOFT_MENU menuDisplay =
{
	0,
	0,
	L"Display\0显示\0顯示\0\0",
	NULL,
	sizeof(submenuDisplay) / sizeof(SOFT_TAG_PAGE),
	submenuDisplay,
	NULL,
	NULL,
	0,
	RESERVE_DWORD4
};
