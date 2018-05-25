#include "stdafx.h"

#define SERIAL_NUMBER	_T("SerialNum.dat")

extern DLG_CTXT dcColorWizard;

const char szMULTiport1[] = "SENSe*:MULTiport:PORT1:SELect";
const char szMULTiport2[] = "SENSe*:MULTiport:PORT2:SELect";

const LPCWSTR wcsListLanguage[] =
{
	L"English\0\0",
	L"简体中文\0\0",
	L"繁體中文\0\0"
};

const LPCWSTR wcsListMultiport[] =
{
	L"Port 1\0端口 1\0端口 1\0\0",
	L"Port 2\0端口 2\0端口 2\0\0",
	L"Port 3\0端口 3\0端口 3\0\0",
	L"Port 4\0端口 4\0端口 4\0\0",
	L"Port 5\0端口 5\0端口 5\0\0",
	L"Port 6\0端口 6\0端口 6\0\0",
	L"Port 7\0端口 7\0端口 7\0\0",
	L"Port 8\0端口 8\0端口 8\0\0",
	L"Port 9\0端口 9\0端口 9\0\0",
	L"Port 10\0端口 10\0端口 10\0\0",
	L"Port 11\0端口 11\0端口 11\0\0",
	L"Port 12\0端口 12\0端口 12\0\0"
};

const LPCWSTR wcsListPreset[] =
{
	L"Factory\0工厂\0工廠\0\0",
	L"User\0用户\0用戶\0\0"
};

const LPCWSTR wcsListWeb[] =
{
	L"ON\0开启\0開啟\0\0",
	L"OFF\0关闭\0關閉\0\0",
	L"-\0-\0-\0\0"
};

const LPCWSTR wcsListSecurityLv[] =
{
	L"None\0无\0無\0\0",
	L"Low\0低\0低\0\0",
	L"High\0高\0高\0\0"
};

const LPCWSTR wcsListMeasureSVC[] =
{
	L"OFF\0关\0關\0\0",
	L"T1\0T1\0T1\0\0",
	L"T2\0T2\0T2\0\0",
	L"R\0R\0R\0\0",
	L"R2\0R1\0R1\0\0",
	L"R2\0R2\0R2\0\0"
};

const LPCWSTR wcsListDummyDUT[] =
{
	L"User\0自定义\0自定義\0\0",
	L"Open\0开路器\0開路器\0\0",
	L"Short\0短路器\0短路器\0\0",
	L"Load\0负载\0負載\0\0",
	L"Thru\0短接\0短接\0\0",
	L"Ecal\0电子校准\0電子校準\0\0"
};

int WINAPI fnUpdateData_Web(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	int nIndex = 0;
	LPCWSTR *lppWStr = (LPCWSTR *)lpSubItem->lpParams;
	LPCWSTR lpText = NULL;
	bool bl1 = *(bool *)0x00BB9708, bl2 = *(bool *)0x00BB9709;

	if (bl1)
	{
		if (bl2)
			nIndex = 0;
		else
			nIndex = 1;
	}
	else
		nIndex = 2;

	if ((*lppWStr) && ((DWORD)nIndex < lpSubItem->dwNumberOfParams))
		lpText = GetStringByIndex(lppWStr[nIndex], nLangId);
	else
		lpText = L"!ERROR!";

	if (lpSubItem->lpOpt[4])
		SetWindowTextW((HWND)lpSubItem->lpOpt[4], lpText);

	return 0;
}

int WINAPI fnItemClicked_Web(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	if (wParam == IC_CLICKED_LAST)
	{
		fnUpdateData_Web(0, 0, 0, lpSubItem);
	}

	return 0;
}

int WINAPI fnItemSelected_Lang(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem, int nIndex)
{
	if (nIndex == -1)
		nIndex = 0;

	nLangId = nIndex;         //设置新语言Id
	//UpdateCurrentLocale();
	TagPage_RefreshItems(FALSE);   //刷新软菜单
	UpdateSoftMenu();
	return 0;
}

int WINAPI fnUpdateData_Lang(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	ComboBox_SetCurSel((HWND)lpSubItem->lpOpt[4], nLangId);
	return 0;
}

int WINAPI fnItemSelected_SysLang(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem, int nIndex)
{
	if (nIndex == -1)
		nIndex = 0;

	WCHAR wcsText[10];

	swprintf_s(wcsText, 10, L"%d", nIndex);
	WritePrivateProfileStringW(L"System", L"LangId", wcsText, L"NACore.ini");
	MessageBoxW(hwMainWnd, L"您当前要切换系统语言,此功能必须重启软件才能生效!", L"提示", MB_OK);
	return 0;
}

int WINAPI fnUpdateData_SysLang(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	int nSysLangId;

	nSysLangId = GetPrivateProfileIntW(L"System", L"LangId", 1, L"NACore.ini");

	ComboBox_SetCurSel((HWND)lpSubItem->lpOpt[4], nSysLangId);
	return 0;
}

//系统子条目
static SOFT_SUB_ITEM subitemSystem[] =
{
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		4,
		L"Dump Screen Image\0屏幕拷贝\0屏幕拷貝\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYSTEM,
		CA_SYSTEM,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
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
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		0,
		L"Print\0打印\0打印\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYSTEM,
		CA_SYSTEM,
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
		L"Abort Printing\0取消打印\0取消打印\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYSTEM,
		CA_SYSTEM,
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
		2,
		L"Printer Setup\0打印机设置\0打印機設置\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYSTEM,
		CA_SYSTEM,
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
		3,
		L"Invert Image\0反转颜色\0反轉顏色\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x000E0D00, 0, (void *)0x00B60A00, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYSTEM,
		CA_SYSTEM,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
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
		RESERVE_DWORD4
	}
	,
	{
		SIF_FN_SELECTED | SIF_FN_UPDATEDATA,
		SIA_FULLLINE,
		SIS_ComboButtonEx,
		0,
		L"System Language\0系统语言\0系統語言\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		RESERVE_DWORD16,
		{ 0, 0, &fnItemSelected_SysLang, &fnUpdateData_SysLang, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		NULL,
		NULL,
		sizeof(wcsListLanguage) / sizeof(LPCWSTR),
		wcsListLanguage,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_FN_SELECTED | SIF_FN_UPDATEDATA,
		SIA_FULLLINE,
		SIS_ComboButtonEx,
		0,
		L"Menu Language\0菜单语言\0菜單語言\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		RESERVE_DWORD16,
		{ 0, 0, &fnItemSelected_Lang, &fnUpdateData_Lang, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		NULL,
		NULL,
		sizeof(wcsListLanguage) / sizeof(LPCWSTR),
		wcsListLanguage,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		8,
		L"Firmware Revision\0硬件版本\0硬件版本\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYSTEM,
		CA_SYSTEM,
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
		10,
		L"Exit\0退出\0退出\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYSTEM,
		CA_SYSTEM,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
};

//多端口子条目
static SOFT_SUB_ITEM subitemMultiport[] =
{
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		0,
		L"Multiport Control\0多端口控制\0多端口控制\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00000000, 0, (void *)0x00B64B58, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MPS,
		CA_SYS_MPS,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_FN_SELECTED | SIF_NOT_ENTER | SIF_FN_UPDATEDATA,
		SIA_FULLLINE,
		SIS_ComboButtonEx,
		1,
		L"Reflection\0反射\0反射\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ (void *)0x00, 0, (void *)szMULTiport1, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, &fnItemSelected_Default, &fnUpdateData_DEC_Default, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MPS_XX,
		NULL,
		sizeof(wcsListMultiport) / sizeof(LPCWSTR),
		wcsListMultiport,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_FN_SELECTED | SIF_NOT_ENTER | SIF_FN_UPDATEDATA,
		SIA_FULLLINE,
		SIS_ComboButtonEx,
		2,
		L"Transmission\0传输\0傳輸\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ (void *)0x00, 0, (void *)szMULTiport2, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, &fnItemSelected_Default, &fnUpdateData_DEC_Default, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MPS_XX,
		NULL,
		sizeof(wcsListMultiport) / sizeof(LPCWSTR),
		wcsListMultiport,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		3,
		L"Property\0校准信息显示\0多端口控制\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00060500, 0, (void *)0x00B64B3C, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MPS,
		CA_SYS_MPS,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
};


int WINAPI fnUpdateData_SICL_LAN(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	const char *lpInfFile;
	UINT uVal;

	lpInfFile = (const char *)GetOffsetPointer((void *)0x00BB41B0, 0x94);

	uVal = GetPrivateProfileIntA("VXI11", "ENABLE", 0, lpInfFile);

	if (uVal != 0)
	{
		SET_FLAGS(lpSubItem->dwAttributes, SIAE_CHECKED);
		Button_SetCheck(lpSubItem->_hWnd, BST_CHECKED);
	}
	else
	{
		NOT_FLAGS(lpSubItem->dwAttributes, SIAE_CHECKED);
		Button_SetCheck(lpSubItem->_hWnd, BST_UNCHECKED);
	}

	return 0;
}

int WINAPI fnItemClicked_SICL_LAN(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	if (wParam == IC_CLICKED_LAST)
	{
		fnUpdateData_SICL_LAN(0, 0, 0, lpSubItem);
	}

	return 0;
}


//程控接口子条目
static SOFT_SUB_ITEM subitemGLSETUP[] =
{
	{
		0,
		SIA_FULLLINE,
		SIS_Delimiter,
		0,
		L"GPIB Setup\0GPIB 设置\0GPIB 設置\0\0",
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
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE,
		SIS_InputButtonEx,
		0,
		L"Talker/Listener Address\0讲/听 地址\0講/聽 地址\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BB96F0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_GPIB,
		CA_SYS_MISC_GPIB,
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
		L"System Controller Configuration\0系统控制器配置\0系統控制器配置\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_GPIB,
		CA_SYS_MISC_GPIB,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		0,
		SIA_FULLLINE,
		SIS_Delimiter,
		0,
		L"Network Setup\0网络设置\0網路配置\0\0",
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
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		0,
		L"Telnet Server\0Telnet 服务\0Telnet 服務\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00010000, 0, (void *)0x00B555E8, (void *)0x77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_NET,
		CA_SYS_MISC_NET,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK | SIF_FN_CLICKED | SIF_FN_UPDATEDATA,
		SIA_FULLLINE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		1,
		L"SICL-LAN Server\0SICL-LAN 服务\0SICL-LAN 服務\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		{ 0, &fnItemClicked_SICL_LAN, 0, &fnUpdateData_SICL_LAN, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_NET,
		CA_SYS_MISC_NET,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE,
		SIS_InputButtonEx,
		2,
		L"SICL-LAN Address\0SICL-LAN 地址\0SICL-LAN 地址\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BB96D0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_NET,
		CA_SYS_MISC_NET,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK | SIF_FN_CLICKED | SIF_FN_UPDATEDATA,
		SIA_FULLLINE | SIA_EXLBL | SIA_UPDATEITEM,
		SIS_ButtonEx,
		3,
		L"Web Server\0Web 服务器\0Web 服務器\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		RESERVE_DWORD16,
		{ 0, &fnItemClicked_Web, 0, &fnUpdateData_Web, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_NET,
		CA_SYS_MISC_NET,
		sizeof(wcsListWeb) / sizeof(LPCWSTR),
		wcsListWeb,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		4,
		L"VNC Server Config\0VNC 服务配置\0VNC 服務配置\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_NET,
		CA_SYS_MISC_NET,
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
		3,
		L"Network Identification\0网络识别\0網路識別\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_NET,
		CA_SYS_MISC_NET,
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
		4,
		L"Network Configuration\0网络配置\0網路配置\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_NET,
		CA_SYS_MISC_NET,
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
		5,
		L"LAN Dialog\0LAN 对话框\0LAN 對話框\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_NET,
		CA_SYS_MISC_NET,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
};

BOOL GetSerialNum(TCHAR* wcSerNum)
{

	CFile file;
	if (!file.Open(_T("D:\\Tianda\\SerialNum.dat"), CFile::modeRead | CFile::typeText))
		return false;

	file.SeekToBegin();
	file.Read(wcSerNum, sizeof(CHAR) * 20);
	file.Close();
	return TRUE;
}

int WINAPI fnItemClicked_Seir(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	TCHAR wcSerNum[21] = { 0 };
	if (lpSubItem->lpOpt[4])
	{
		if (GetSerialNum(wcSerNum))
			SetWindowText((HWND)lpSubItem->lpOpt[4], wcSerNum);
		else
			SetWindowTextW((HWND)lpSubItem->lpOpt[4], L"ERROR");
	}
	else
		SetWindowTextW((HWND)lpSubItem->lpOpt[4], L"ERROR!");
	return 0;
}

int WINAPI fnItemClicked_TestMenu(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	//继续找类地址.......
	return 0;
}

//服务菜单
static SOFT_SUB_ITEM subitemSrv[] =
{
	{
		SIF_NOREPLY | SIF_FN_UPDATEDATA,
		SIA_FULLLINE | SIA_EXLBL | SIA_UPDATEITEM | SIA_UNREAD,
		SIS_ButtonEx,
		0,
		L"Serial Number\0序列号\0序列號\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		RESERVE_DWORD16,
		{ 0, 0, 0, &fnItemClicked_Seir, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		0,
		0,
		0,
		0,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE ,
		SIS_ButtonEx,
		0,
		L"Power On Test\0电源测试\0電源測試\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00010000, 0, (void *)0x00B7CA78, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SRVMEU_TM,
		CA_SRVMEU_TM,
		NULL,
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
		L"Display\0显示测试\0顯示測試\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SRVMEU_TM,
		CA_SRVMEU_TM,
		NULL,
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
		L"Front Panel\0前面板测试\0前面板測試\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SRVMEU_TM,
		CA_SRVMEU_TM,
		NULL,
		NULL,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE ,
		SIS_ButtonEx,
		3,
		L"Adjust Touch Screen\0触摸屏调整\0觸摸屏調整\0\0",  
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SRVMEU_TM,
		CA_SRVMEU_TM,
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
		L"Security Level\0安全级别\0安全等級\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ (void *)0x00050400, 0, (void *)0x00B684D4, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, &fnItemSelected_Default, &fnUpdateData_Default, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SRVMEU_SL,
		CA_SRVMEU_SL,
		sizeof(wcsListSecurityLv) / sizeof(LPCWSTR),
		wcsListSecurityLv,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_FN_SELECTED | SIF_FN_UPDATEDATA,
		SIA_FULLLINE,
		SIS_ComboButtonEx,
		0,
		L"Measure(SVC)\0测量(SVC)\0測量(SVC)\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ (void *)0x00080700, 0, (void *)0x00B7B9D0, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, &fnItemSelected_Default, &fnUpdateData_Default, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SRVMEU_TM_SF_SVC,
		CA_SRVMEU_TM_SF_SVC,
		sizeof(wcsListMeasureSVC) / sizeof(LPCWSTR),
		wcsListMeasureSVC,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_FN_SELECTED | SIF_FN_UPDATEDATA,
		SIA_FULLLINE,
		SIS_ComboButtonEx,
		3,
		L"Dummy DUT\0Dummy DUT\0Dummy DUT\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ (void *)0x00090800, 0, (void *)0x00B6B860, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, &fnItemSelected_Default, &fnUpdateData_Default, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SRVMEU_TM_SF_DUT,
		CA_SRVMEU_TM_SF_DUT,
		sizeof(wcsListDummyDUT) / sizeof(LPCWSTR),
		wcsListDummyDUT,
		RESERVE_DWORD4,
		{ 0, 0, 0, 0 }
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		0,
		L"Freq Reference\0Freq Reference\0Freq Reference\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00010000, 0, (void *)0x00B7BF54, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SRVMEU_TM_SF_SysCal,
		CA_SRVMEU_TM_SF_SysCal,
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
		1,
		L"Synthe Gain\0Synthe Gain\0Synthe Gain\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00020100, 0, (void *)0x00B7BF28, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SRVMEU_TM_SF_SysCal,
		CA_SRVMEU_TM_SF_SysCal,
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
		2,
		L"Local Power\0Local Power\0Local Power\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00030200, 0, (void *)0x00B7BF00, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SRVMEU_TM_SF_SysCal,
		CA_SRVMEU_TM_SF_SysCal,
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
		3,
		L"Source Power\0Source Power\0Source Power\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00040300, 0, (void *)0x00B7BED8, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SRVMEU_TM_SF_SysCal,
		CA_SRVMEU_TM_SF_SysCal,
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
		4,
		L"IF Range\0IF Range\0IF Range\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00050400, 0, (void *)0x00B7BEB4, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SRVMEU_TM_SF_SysCal,
		CA_SRVMEU_TM_SF_SysCal,
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
		5,
		L"Port Char\0Port Char\0Port Char\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00060500, 0, (void *)0x00B7BE88, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SRVMEU_TM_SF_SysCal,
		CA_SRVMEU_TM_SF_SysCal,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}

};


int WINAPI fnUpdateData_PresetS(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	const char *lpInfFile;
	UINT uVal;

	lpInfFile = (const char *)GetOffsetPointer((void *)0x00BB41B0, 0x94);

	uVal = GetPrivateProfileIntA("PRESET", "USER", 0, lpInfFile);

	if (uVal != 0)
	{
		ComboBox_SetCurSel((HWND)lpSubItem->lpOpt[4], 1);
	}
	else
	{
		ComboBox_SetCurSel((HWND)lpSubItem->lpOpt[4], 0);
	}

	return 0;
}

int WINAPI fnItemSelected_PresetS(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem, int nIndex)
{
	if (nIndex == -1) nIndex = 0;

	if ((lpSubItem->lpThis) && (lpSubItem->lpVTable))
	{
		//if (CHK_NOFLAGS(lpSubItem->dwFlags, SIF_NOT_ENTER))
		//{
		//  OrigSoftMenu_Enter(lpSubItem->lpThis);
		//}

		OrigSoftMenu_ItemClicked2(lpSubItem->lpThis, lpSubItem->lpVTable, nIndex);
	}

	fnUpdateData_PresetS(0, 0, 0, lpSubItem);

	return 0;
}

int WINAPI fnUpdateData_PresetC(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	const char *lpInfFile;
	UINT uVal;

	lpInfFile = (const char *)GetOffsetPointer((void *)0x00BB41B0, 0x94);

	uVal = GetPrivateProfileIntA("PRESET", "CONFIRM", 1, lpInfFile);

	if (uVal != 0)
	{
		SET_FLAGS(lpSubItem->dwAttributes, SIAE_CHECKED);
		Button_SetCheck(lpSubItem->_hWnd, BST_CHECKED);
	}
	else
	{
		NOT_FLAGS(lpSubItem->dwAttributes, SIAE_CHECKED);
		Button_SetCheck(lpSubItem->_hWnd, BST_UNCHECKED);
	}

	UpdatePresetState();

	return 0;
}

int WINAPI fnItemClicked_PresetC(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_SUB_ITEM *lpSubItem)
{
	if (wParam == IC_CLICKED_LAST)
	{
		fnUpdateData_PresetC(0, 0, 0, lpSubItem);
	}

	return 0;
}

//杂项子条目
static SOFT_SUB_ITEM subitemMisc[] =
{
	{
		0,
		SIA_FULLLINE,
		SIS_Delimiter,
		0,
		L"Beeper\0蜂鸣器设置\0蜂鳴器設置\0\0",
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
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		0,
		L"Beep Complete\0完成时提示音\0完成時提示音\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00010000, 0, (void *)0x00B67C68, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_BEEP,
		CA_SYS_MISC_BEEP,
		NULL,
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
		L"Test Beep Complete\0测试完成时提示音\0測試完成時提示音\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_BEEP,
		CA_SYS_MISC_BEEP,
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
		2,
		L"Beep Warning\0蜂鸣器报警\0蜂鳴器報警\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00090800, 0, (void *)0x00B67E0C, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_BEEP,
		CA_SYS_MISC_BEEP,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		3,
		L"Test Beep Warning\0测试蜂鸣器报警\0測試蜂鳴器報警\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_BEEP,
		CA_SYS_MISC_BEEP,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		0,
		SIA_FULLLINE,
		SIS_Delimiter,
		0,
		L"Clock Setup\0时钟设置\0時鐘設置\0\0",
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
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		0,
		L"Set Date and Time\0设置日期和时间\0設置日期和時間\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_CLOCK,
		CA_SYS_MISC_CLOCK,
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
		1,
		L"Show Clock\0显示时钟\0顯示時鐘\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00020100, 0, (void *)0x00B6074C, (void *)0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_CLOCK,
		CA_SYS_MISC_CLOCK,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		0,
		SIA_FULLLINE,
		SIS_Delimiter,
		0,
		L"Lock Setup\0锁定设置\0鎖定設置\0\0",
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
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		0,
		L"Front Panel && Keyboard Lock\0前面板&&键盘锁定\0前面板&&鍵盤鎖定\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00010000, 0, (void *)0x00B6836C, (void *)0x38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_KL,
		CA_SYS_MISC_KL,
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
		1,
		L"Mouse Lock\0鼠标锁定\0鼠標鎖定\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00060500, 0, (void *)0x00B68380, (void *)0x38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_KL,
		CA_SYS_MISC_KL,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_DIALOG,
		SIA_FULLLINE,
		SIS_ButtonEx,
		0,
		L"Color Setup\0颜色配置\0颜色配置\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		NULL,
		&dcColorWizard,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		0,
		SIA_FULLLINE,
		SIS_Delimiter,
		0,
		L"Preset Setup\0复位设置\0復位設置\0\0",
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
		RESERVE_DWORD4
	}
	,
	{
		SIF_FN_SELECTED | SIF_FN_UPDATEDATA,
		SIA_FULLLINE,
		SIS_ComboButtonEx,
		0,
		L"State\0状态\0狀態\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		RESERVE_DWORD16,
		{ 0, 0, &fnItemSelected_PresetS, &fnUpdateData_PresetS, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC_PR_S,
		CA_SYS_MISC_PR_S,
		sizeof(wcsListPreset) / sizeof(LPCWSTR),
		wcsListPreset,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	/*
	,
	{
	SIF_ORIGCLICK | SIF_FN_CLICKED | SIF_FN_UPDATEDATA,
	SIA_FULLLINE | SIA_UPDATEITEM,
	SIS_CheckButtonEx,
	1,
	L"Confirm\0确认提示\0確認提示\0\0",
	NULL,
	BtnWidth_W,
	BtnHeith_H,
	NULL,
	RESERVE_DWORD16,
	{ 0, &fnItemClicked_PresetC, 0, &fnUpdateData_PresetC, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	INVALID_INDEX,
	NULL,
	NULL,
	TA_SYS_MISC_PR,
	CA_SYS_MISC_PR,
	NULL,
	NULL,
	RESERVE_DWORD4,
	RESERVE_DWORD4
	}
	*/
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
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE,
		SIS_ButtonEx,
		7,
		L"Control Panel\0控制面板\0控制面板\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_SYS_MISC,
		CA_SYS_MISC,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
};


static int WINAPI fnTagPageEnter_System(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage)
{
	OrigSoftMenu_Enter(CA_SYSTEM);
	OrigSoftMenu_UpdateItems(CA_SYSTEM);
	return 0;
}

static int WINAPI fnTagPageEnter_Multiport(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage)
{
	OrigSoftMenu_Enter(CA_SYSTEM);
	OrigSoftMenu_UpdateItems(CA_SYSTEM);
	OrigSoftMenu_Enter(CA_SYS_MPS);
	OrigSoftMenu_UpdateItems(CA_SYS_MPS);

	subitemMultiport[1].lpThis = GetSubMenuPointer(CA_SYS_MPS, 1);
	subitemMultiport[2].lpThis = GetSubMenuPointer(CA_SYS_MPS, 2);

	return 0;
}


static int WINAPI fnTagPageEnter_GLSETUP(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage)
{
	int nCount;

	OrigSoftMenu_Enter(CA_SYSTEM);
	OrigSoftMenu_UpdateItems(CA_SYSTEM);

	OrigSoftMenu_Enter(CA_SYS_MISC);
	OrigSoftMenu_UpdateItems(CA_SYS_MISC);

	OrigSoftMenu_Enter(CA_SYS_MISC_GPIB);
	OrigSoftMenu_UpdateItems(CA_SYS_MISC_GPIB);

	OrigSoftMenu_Enter(CA_SYS_MISC_NET);
	OrigSoftMenu_UpdateItems(CA_SYS_MISC_NET);

	nCount = GetSubMenuItemCount(CA_SYS_MISC_NET);

	switch (nCount)
	{
	case 6:   //无WEB VNC LAN
		lpTagPage->lpSubItem[9].dwFunctionId = 3;
		lpTagPage->lpSubItem[10].dwFunctionId = 4;
		lpTagPage->lpSubItem[11].dwFunctionId = 5;
		SET_FLAGS(lpTagPage->lpSubItem[7].dwAttributes, SIAE_DISABLED);
		SET_FLAGS(lpTagPage->lpSubItem[8].dwAttributes, SIAE_DISABLED);
		SET_FLAGS(lpTagPage->lpSubItem[11].dwAttributes, SIAE_DISABLED);
		break;

	case 7:   //无WEB VNC
		lpTagPage->lpSubItem[9].dwFunctionId = 3;
		lpTagPage->lpSubItem[10].dwFunctionId = 4;
		lpTagPage->lpSubItem[11].dwFunctionId = 5;
		SET_FLAGS(lpTagPage->lpSubItem[7].dwAttributes, SIAE_DISABLED);
		SET_FLAGS(lpTagPage->lpSubItem[8].dwAttributes, SIAE_DISABLED);
		NOT_FLAGS(lpTagPage->lpSubItem[11].dwAttributes, SIAE_DISABLED);
		break;

	case 8:   //无LAN
		lpTagPage->lpSubItem[9].dwFunctionId = 5;
		lpTagPage->lpSubItem[10].dwFunctionId = 6;
		lpTagPage->lpSubItem[11].dwFunctionId = 7;
		NOT_FLAGS(lpTagPage->lpSubItem[7].dwAttributes, SIAE_DISABLED);
		NOT_FLAGS(lpTagPage->lpSubItem[8].dwAttributes, SIAE_DISABLED);
		SET_FLAGS(lpTagPage->lpSubItem[11].dwAttributes, SIAE_DISABLED);
		break;

	case 9:   //全有
		lpTagPage->lpSubItem[9].dwFunctionId = 5;
		lpTagPage->lpSubItem[10].dwFunctionId = 6;
		lpTagPage->lpSubItem[11].dwFunctionId = 7;
		NOT_FLAGS(lpTagPage->lpSubItem[7].dwAttributes, SIAE_DISABLED);
		NOT_FLAGS(lpTagPage->lpSubItem[8].dwAttributes, SIAE_DISABLED);
		NOT_FLAGS(lpTagPage->lpSubItem[11].dwAttributes, SIAE_DISABLED);
		break;
	}

	return 0;
}

static int WINAPI fnTagPageEnter_SrvMeu(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage)
{
	OrigSoftMenu_Enter(CA_SRVMEU);
	OrigSoftMenu_UpdateItems(CA_SRVMEU);
	return 0;
}

static int WINAPI fnTagPageEnter_Misc(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage)
{
	OrigSoftMenu_Enter(CA_SYSTEM);
	OrigSoftMenu_UpdateItems(CA_SYSTEM);

	OrigSoftMenu_Enter(CA_SYS_MISC);
	OrigSoftMenu_UpdateItems(CA_SYS_MISC);

	OrigSoftMenu_Enter(CA_SYS_MISC_BEEP);
	OrigSoftMenu_UpdateItems(CA_SYS_MISC_BEEP);

	OrigSoftMenu_UpdateItems(CA_SYS_MISC_PR);
	OrigSoftMenu_UpdateItems(CA_SYS_MISC_PR_S);

	return 0;
}

//系统子菜单
SOFT_TAG_PAGE submenuSystem[] =
{
	{
		TPF_FN_ENTER,
		0,
		L"System\0系统\0系統\0\0",
		NULL,
		sizeof(subitemSystem) / sizeof(SOFT_SUB_ITEM),
		subitemSystem,
		RESERVE_DWORD4,
		&fnTagPageEnter_System,
		NULL,
		0,
		{ L"::/Setting_Control_Functions/Checking_the_product_information.htm", 0, 0, 0 }
	}
	,
	{
		TPF_FN_ENTER,
		0,
		L"Multiport\0多端口\0多端口\0\0",
		NULL,
		sizeof(subitemMultiport) / sizeof(SOFT_SUB_ITEM),
		subitemMultiport,
		RESERVE_DWORD4,
		&fnTagPageEnter_Multiport,
		NULL,
		0,
		{ L"::/Setting_Control_Functions/Initial_Source_Port_Control_function.htm", 0, 0, 0 }
	}
	,
	{
		TPF_FN_ENTER,
		0,
		L"GPIB && LAN Setup\0程控接口\0程控接口\0\0",
		NULL,
		sizeof(subitemGLSETUP) / sizeof(SOFT_SUB_ITEM),
		subitemGLSETUP,
		RESERVE_DWORD4,
		&fnTagPageEnter_GLSETUP,
		NULL,
		0,
		{ L"::/Setting_Control_Functions/Setting_the_GPIB.htm", 0, 0, 0 }
	}
	,
	{
		TPF_FN_ENTER,
		0,
		L"Service Menu\0服务菜单\0服務菜單\0\0",
		NULL,
		sizeof(subitemSrv) / sizeof(SOFT_SUB_ITEM),
		subitemSrv,
		RESERVE_DWORD4,
		&fnTagPageEnter_SrvMeu,
		NULL,
		0,
		{ L"::/Setting_Control_Functions/Setting_the_GPIB.htm", 0, 0, 0 }
	}
	,
	{
		TPF_FN_ENTER,
		0,
		L"Misc Setup\0杂项设置\0雜項設置\0\0",
		NULL,
		sizeof(subitemMisc) / sizeof(SOFT_SUB_ITEM),
		subitemMisc,
		RESERVE_DWORD4,
		&fnTagPageEnter_Misc,
		NULL,
		0,
		{ L"::/Setting_Control_Functions/Setting_the_Beeper_Built_in_Speaker.htm", 0, 0, 0 }
	}
};

//系统主菜单
SOFT_MENU menuSystem =
{
	0,
	0,
	L"System\0系统\0系統\0\0",
	NULL,
	sizeof(submenuSystem) / sizeof(SOFT_TAG_PAGE),
	submenuSystem,
	NULL,
	NULL,
	0,
	RESERVE_DWORD4
};
