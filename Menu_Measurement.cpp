#include "stdafx.h"


extern SOFT_MENU menuSimth;
extern SOFT_MENU menuPolar;


const LPCWSTR wcsListSimth[] =
{
	L"Lin / Phase\0线性 / 相位\0線性 / 相位\0\0",
	L"Log / Phase\0对数 / 相位\0對數 / 相位\0\0",
	L"Real / Imag\0实部 / 虚部\0實部 / 虛部\0\0",
	L"R + jX\0R + jX\0R + jX\0\0",
	L"G + jB\0G + jB\0G + jB\0\0"
};

const LPCWSTR wcsListPolar[] =
{
	L"Lin / Phase\0线性 / 相位\0線性 / 相位\0\0",
	L"Log / Phase\0对数 / 相位\0對數 / 相位\0\0",
	L"Real / Imag\0实部 / 虚部\0實部 / 虛部\0\0"
};

const LPCWSTR wcsListTrackMode[] =
{
	L"Off\0关闭\0關閉\0\0",
	L"Track Peak\0跟踪峰值\0跟蹤峰值\0\0",
	L"Track Freq\0跟踪频率\0跟蹤頻率\0\0"
};

int WINAPI fnUpdateData_SParam(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem);
int WINAPI fnUpdateData_Format(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem);
int WINAPI fnUpdateData_TrackMode(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem);


//S参数子条目
SOFT_SUB_ITEM subitemSParam[] =
{
	{
		SIF_ORIGCLICK | SIF_FN_UPDATEDATA,
		SIA_FULLLINE | SIA_GROUP | SIA_GETBTNSTATE,
		SIS_RadioButtonEx,
		0,
		L"S11\0S11\0S11\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00020100, 0, (void *)0x00B56D74, (void *)0x02, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, &fnUpdateData_SParam, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		0,
		NULL,
		NULL,
		TA_SPARAM,
		CA_SPARAM,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_RadioButtonEx,
		1,
		L"S21\0S21\0S21\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_SPARAM,
		CA_SPARAM,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_RadioButtonEx,
		2,
		L"S12\0S12\0S12\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_SPARAM,
		CA_SPARAM,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_RadioButtonEx,
		3,
		L"S22\0S22\0S22\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_SPARAM,
		CA_SPARAM,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
};

//格式子条目
SOFT_SUB_ITEM subitemFormat[] =
{
	{
		SIF_ORIGCLICK | SIF_FN_UPDATEDATA,
		SIA_FULLLINE | SIA_GROUP | SIA_GETBTNSTATE,
		SIS_RadioButtonEx,
		0,
		L"Log Mag\0对数\0對數\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00020100, 0, (void *)0x00B77458, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, &fnUpdateData_Format, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		0,
		NULL,
		NULL,
		TA_FORMAT,
		CA_FORMAT,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_RadioButtonEx,
		1,
		L"Phase\0相位\0相位\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_FORMAT,
		CA_FORMAT,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_RadioButtonEx,
		2,
		L"Group Delay\0群延迟\0群延遲\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_FORMAT,
		CA_FORMAT,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_FN_SELECTED,
		SIA_FULLLINE,
		SIS_ComboRadioButtonEx,
		3,
		L"Smith\0史密斯圆图\0史密斯圓圖\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		RESERVE_DWORD16,
		{ 0, 0, &fnItemSelected_Default, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		0,
		NULL,
		NULL,
		TA_SIMTH,
		CA_SIMTH,
		sizeof(wcsListSimth) / sizeof(LPCWSTR),
		wcsListSimth,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_FN_SELECTED,
		SIA_FULLLINE,
		SIS_ComboRadioButtonEx,
		4,
		L"Polar\0极坐标\0極坐標\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		RESERVE_DWORD16,
		{ 0, 0, &fnItemSelected_Default, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		0,
		NULL,
		NULL,
		TA_POLAR,
		CA_POLAR,
		sizeof(wcsListPolar) / sizeof(LPCWSTR),
		wcsListPolar,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_RadioButtonEx,
		5,
		L"Lin Mag\0线性\0線性\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_FORMAT,
		CA_FORMAT,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_RadioButtonEx,
		6,
		L"SWR\0SWR\0SWR\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_FORMAT,
		CA_FORMAT,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_RadioButtonEx,
		7,
		L"Real\0实部\0實部\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_FORMAT,
		CA_FORMAT,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_RadioButtonEx,
		8,
		L"Imaginary\0虚部\0虛部\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_FORMAT,
		CA_FORMAT,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_RadioButtonEx,
		9,
		L"Expand Phase\0扩展相位\0擴展相位\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_FORMAT,
		CA_FORMAT,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_RadioButtonEx,
		10,
		L"Positive Phase\0正相位\0正相位\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_FORMAT,
		CA_FORMAT,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
};

//标尺子条目
SOFT_SUB_ITEM subitemScale[] =
{
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE | SIA_INPUT_TIME,
		SIS_InputButtonEx,
		3,
		L"Scale/Div\0分辨率/格\0分辨率/格\0\0",
		NULL,
		BtnWidth_W,
		52,
		NULL,
		{ 0, (void *)0x00BB92A0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_SCALE,
		CA_SCALE,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE | SIA_UPDATEDATA,
		SIS_InputButtonEx,
		2,
		L"Divisions\0格数\0格數\0\0",
		NULL,
		BtnWidth_W,
		52,
		NULL,
		{ 0, (void *)0x00BB9280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_SCALE,
		CA_SCALE,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE,
		SIS_InputButtonEx,
		4,
		L"Reference Position\0基准位置\0基准位置\0\0",
		NULL,
		BtnWidth_W,
		52,
		NULL,
		{ 0, (void *)0x00BB9290, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_SCALE,
		CA_SCALE,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE | SIA_INPUT_TIME,
		SIS_InputButtonEx,
		5,
		L"Reference Value\0基准数值\0基准數值\0\0",
		NULL,
		BtnWidth_W,
		52,
		NULL,
		{ 0, (void *)0x00BB92C8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_SCALE,
		CA_SCALE,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		7,
		L"Marker -> Reference\0频标 -> 基准\0頻標 -> 基准\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_SCALE,
		CA_SCALE,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE | SIA_INPUT_TIME,
		SIS_InputButtonEx,
		8,
		L"Electrical Delay\0电子延迟\0電子延遲\0\0",
		NULL,
		BtnWidth_W,
		52,
		NULL,
		{ 0, (void *)0x00BB9260, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_SCALE,
		CA_SCALE,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE | SIA_INPUT_TIME,
		SIS_InputButtonEx,
		9,
		L"Phase Offset\0相位偏移\0相位偏移\0\0",
		NULL,
		BtnWidth_W,
		52,
		NULL,
		{ 0, (void *)0x00BB9250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_SCALE,
		CA_SCALE,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
};

//定标子条目
SOFT_SUB_ITEM subitemAutoScale[] =
{
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		0,
		L"Auto Scale\0自动定标\0自動定標\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_SCALE,
		CA_SCALE,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		1,
		L"Auto Scale All\0自动定标 (全部)\0自動定標 (全部)\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		TA_SCALE,
		CA_SCALE,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
};


int WINAPI fnTagPageEnter_Format(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage)
{
	OrigSoftMenu_UpdateItems(CA_FORMAT);
	return 0;
}

int WINAPI fnTagPageEnter_SParam(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage)
{
	BOOL blTmp = FALSE;

	OrigSoftMenu_GetItemState(CA_SPARAM, 2, &blTmp, NULL, NULL);

	if (blTmp & 0xFF)
		NOT_FLAGS(subitemSParam[2].dwAttributes, SIAE_DISABLED);
	else
		SET_FLAGS(subitemSParam[2].dwAttributes, SIAE_DISABLED);


	OrigSoftMenu_GetItemState(CA_SPARAM, 3, &blTmp, NULL, NULL);

	if (blTmp & 0xFF)
		NOT_FLAGS(subitemSParam[3].dwAttributes, SIAE_DISABLED);
	else
		SET_FLAGS(subitemSParam[3].dwAttributes, SIAE_DISABLED);

	return 0;
}



//测量子菜单
SOFT_TAG_PAGE submenuMeasurement[] =
{
	{
		TPF_FN_ENTER,
		0,
		L"S Parameter\0S参数\0S參數\0\0",
		NULL,
		sizeof(subitemSParam) / sizeof(SOFT_SUB_ITEM),
		subitemSParam,
		RESERVE_DWORD4,
		&fnTagPageEnter_SParam,
		NULL,
		0,
		{ L"::/Measurement/Setting_Measurement_Conditions/Selecting_Measurement_Parameters.htm#S_parameters", (void*)1027, 0, 0 }
	}
	,
	{
		TPF_FN_ENTER,
		0,
		L"Foramt\0格式\0格式\0\0",
		NULL,
		sizeof(subitemFormat) / sizeof(SOFT_SUB_ITEM),
		subitemFormat,
		RESERVE_DWORD4,
		&fnTagPageEnter_Format,
		NULL,
		0,
		{ L"::/Measurement/Setting_Measurement_Conditions/Selecting_a_Data_Format.htm", (void*)1028, 0, 0 }
	}
	,
	{
		0,
		0,
		L"Scale\0标尺\0標尺\0\0",
		NULL,
		sizeof(subitemScale) / sizeof(SOFT_SUB_ITEM),
		subitemScale,
		RESERVE_DWORD4,
		NULL,
		NULL,
		0,
		{ L"::/Measurement/Setting_Measurement_Conditions/Setting_the_Scales.htm", (void*)1029, 0, 0 }
	}
	,
	{
		0,
		0,
		L"Auto Scale\0定标\0定標\0\0",
		NULL,
		sizeof(subitemAutoScale) / sizeof(SOFT_SUB_ITEM),
		subitemAutoScale,
		RESERVE_DWORD4,
		NULL,
		NULL,
		0,
		{ L"::/Measurement/Setting_Measurement_Conditions/Setting_the_Scales.htm", (void*)1029, 0, 0 }
	}
};

//测量主菜单
SOFT_MENU menuMeasurement =
{
	0,
	0,
	L"Measurement\0测量\0測量\0\0",
	NULL,
	sizeof(submenuMeasurement) / sizeof(SOFT_TAG_PAGE),
	submenuMeasurement,
	NULL,
	NULL,
	0,
	RESERVE_DWORD4
};


int WINAPI fnUpdateData_SParam(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	int nIndex = 0;

	if (lpSubItem->lpOpt[2] == NULL) 
		return -1;

	GetButtonStateIndex((char *)lpSubItem->lpOpt[2], lpSubItem->lpOpt[3], &nIndex, (int)lpSubItem->lpOpt[0]);

	switch (nIndex)
	{
	case 1:
	case 2:
	case 3:
		SoftItem_ActivationItemByOffsetIndex(lpSubItem, nIndex);
		break;

	default:
		SoftItem_ActivationItemByOffsetIndex(lpSubItem, 0);
		break;
	}

	return 0;
}

int WINAPI fnUpdateData_Format(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	int nIndex = 0;

	if (lpSubItem->lpOpt[2] == NULL)
		return -1;

	GetButtonStateIndex((char *)lpSubItem->lpOpt[2], lpSubItem->lpOpt[3], &nIndex, (int)lpSubItem->lpOpt[0]);

	switch (nIndex)
	{
	case 1:
	case 2:
		SoftItem_ActivationItemByOffsetIndex(lpSubItem, nIndex);
		break;

	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
		SoftItem_ActivationItemByOffsetIndex(lpSubItem, nIndex - 6);
		break;

	case 3:
	case 4:
	case 5:
	case 6:
	case 7:

		if (3 < (sizeof(subitemFormat) / sizeof(SOFT_SUB_ITEM)))
		{
			if (subitemFormat[3].dwStyle == SIS_ComboButtonEx || subitemFormat[3].dwStyle == SIS_ComboRadioButtonEx)
				ComboBox_SetCurSel((HWND)subitemFormat[3].lpOpt[4], nIndex - 3);
			SoftItem_ActivationItemByOffsetIndex(lpSubItem, 3);
		}

		break;

	case 8:
	case 9:
	case 10:

		if (4 < (sizeof(subitemFormat) / sizeof(SOFT_SUB_ITEM)))
		{
			if (subitemFormat[4].dwStyle == SIS_ComboButtonEx || subitemFormat[4].dwStyle == SIS_ComboRadioButtonEx)
				ComboBox_SetCurSel((HWND)subitemFormat[4].lpOpt[4], nIndex - 8);
			SoftItem_ActivationItemByOffsetIndex(lpSubItem, 4);
		}

		break;

	default:
		SoftItem_ActivationItemByOffsetIndex(lpSubItem, 0);
		break;
	}

	return 0;
}


int WINAPI fnUpdateData_TrackMode(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	int nIndex = 0;

	if (lpSubItem->lpOpt[2] == NULL) 
		return -1;

	GetButtonStateIndex((char *)lpSubItem->lpOpt[2], lpSubItem->lpOpt[3], &nIndex, (int)lpSubItem->lpOpt[0]);
	ComboBox_SetCurSel((HWND)lpSubItem->lpOpt[4], nIndex);

	return 0;
}

