#include "stdafx.h"

extern CALDLG_CTXT dcCal_7_1;

extern CalKit cCalkit;


static int nLastIdx = -1;
static WNDPROC wpfn_InputEdit = NULL;

void SetInputType(int nNewType);
static LRESULT CALLBACK wp_InputEdit(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static void *lpThis_STD[21] =
{
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

void UpdateComboBox_STD(HWND hCtl)
{
	typedef void *(__cdecl *func_0051F4B0)(int nIndex);

	ComboBox_DeleteAll(hCtl);
	OrigSoftMenu_UpdateItems(CA_MCK_DSTD);

	func_0051F4B0 fn0051F4B0 = (func_0051F4B0)0x0051F4B0;
	void *lpRes;
	char *lpLabel;
	int nIndex = 0;
	WCHAR wcsText[MAX_PATH];

	do
	{
		lpRes = fn0051F4B0(nIndex);

		if ((lpRes) && (lpLabel = (char *)GetOffsetPointer(lpRes, 0x0C)))
		{
			MultiByteToWideChar(1253, 0, lpLabel, -1, wcsText, MAX_PATH);
		}
		else
		{
			swprintf_s(wcsText, MAX_PATH, L"[%d:Invalid]", nIndex);
		}

		ComboBox_InsertStringW(hCtl, nIndex, wcsText);
		nIndex++;
	} while (nIndex < 0x15);

}

static void UpdateTypeState_STD(HWND hClient, int nIndex)
{
	switch (nIndex)
	{
	case 0:
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C0), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C1), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C2), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C3), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L0), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L1), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L2), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L3), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_OD), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_OZ), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_OL), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_AI), FALSE);
		break;

	case 1:
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C0), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C1), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C2), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C3), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L0), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L1), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L2), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L3), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_OD), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_OZ), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_OL), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_AI), FALSE);
		break;

	case 2:
	case 3:
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C0), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C1), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C2), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C3), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L0), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L1), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L2), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L3), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_OD), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_OZ), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_OL), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_AI), FALSE);
		break;

	case 4:
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C0), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C1), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C2), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C3), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L0), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L1), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L2), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L3), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_OD), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_OZ), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_OL), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_AI), TRUE);
		break;

	default:
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C0), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C1), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C2), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_C3), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L0), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L1), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L2), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_L3), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_OD), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_OZ), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_OL), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL7_EDIT_AI), FALSE);
		break;
	}
}

static void UpdateType_STD(HWND hClient, int nIndex)
{
	if ((nIndex >= 0) && (nIndex < 0x15) && (lpThis_STD[nIndex]))
	{
		OrigSoftMenu_UpdateItems(lpThis_STD[nIndex]);

		void *lpThis2 = GetSubMenuPointer(lpThis_STD[nIndex], 1);

		if (lpThis2 == NULL) return;

		OrigSoftMenu_UpdateItems(lpThis2);

		int nTmp = GetSubMenuSelected_Radio(lpThis2);
		ComboBox_SetCurSel(GetDlgItem(hClient, IDC_CAL7_CB_STDTYPE), nTmp);

		UpdateTypeState_STD(hClient, nTmp);
	}
}

static void UpdateValue_STD(HWND hClient, int nIndex)
{
	int nTmp = 0;
	char szTmp[MAX_PATH];
	WCHAR wcsTmp[MAX_PATH];

	GetInputStringObjectW((void *)0x00BB8FD8, wcsTmp, MAX_PATH, &nTmp);
	SendDlgItemMessage(hClient, IDC_CAL7_EDIT_KIT, EM_LIMITTEXT, nTmp, NULL);

	//85038A/F/M    85039B   85036B/E   85032B/E   85032F   85052D   85033D   85033E
	if (0 == wcscmp(wcsTmp, cCalkit.OldCalKitList[7].c_str()))
		wcscpy_s(wcsTmp, cCalkit.CalKitList[7].c_str());
	else if (0 == wcscmp(wcsTmp, cCalkit.OldCalKitList[6].c_str()))
		wcscpy_s(wcsTmp, cCalkit.CalKitList[6].c_str());
	else if (0 == wcscmp(wcsTmp, cCalkit.OldCalKitList[5].c_str()))
		wcscpy_s(wcsTmp, cCalkit.CalKitList[5].c_str());
	else if (0 == wcscmp(wcsTmp, cCalkit.OldCalKitList[4].c_str()))
		wcscpy_s(wcsTmp, cCalkit.CalKitList[4].c_str());
	else if (0 == wcscmp(wcsTmp, cCalkit.OldCalKitList[3].c_str()))
		wcscpy_s(wcsTmp, cCalkit.CalKitList[3].c_str());
	else if (0 == wcscmp(wcsTmp, cCalkit.OldCalKitList[2].c_str()))
		wcscpy_s(wcsTmp, cCalkit.CalKitList[2].c_str());
	else if (0 == wcscmp(wcsTmp, cCalkit.OldCalKitList[1].c_str()))
		wcscpy_s(wcsTmp, cCalkit.CalKitList[1].c_str());
	else if (0 == wcscmp(wcsTmp, cCalkit.OldCalKitList[0].c_str()))
		wcscpy_s(wcsTmp, cCalkit.CalKitList[0].c_str());

	SetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_KIT), wcsTmp);

	if ((nIndex >= 0) && (nIndex < 0x15) && (lpThis_STD[nIndex]))
	{
		OrigSoftMenu_ItemClicked2(CA_MCK_DSTD, TA_MCK_DSTD, nIndex);
		OrigSoftMenu_Enter(lpThis_STD[nIndex]);
		OrigSoftMenu_UpdateItems(lpThis_STD[nIndex]);

		UpdateType_STD(hClient, nIndex);

		OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 0);
		GetInputStringObjectW((void *)0x00BB8FD4, wcsTmp, MAX_PATH, &nTmp);
		SendDlgItemMessage(hClient, IDC_CAL7_EDIT_STDLBL, EM_LIMITTEXT, nTmp, NULL);
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_STDLBL), wcsTmp);

		OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 2);
		FmtValueToString((void *)0x00BB8DF0, szTmp, MAX_PATH, NULL);
		MultiByteToWideChar(1253, 0, szTmp, -1, wcsTmp, MAX_PATH);
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_C0), wcsTmp);

		OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 3);
		FmtValueToString((void *)0x00BB8DF0, szTmp, MAX_PATH, NULL);
		MultiByteToWideChar(1253, 0, szTmp, -1, wcsTmp, MAX_PATH);
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_C1), wcsTmp);

		OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 4);
		FmtValueToString((void *)0x00BB8DF0, szTmp, MAX_PATH, NULL);
		MultiByteToWideChar(1253, 0, szTmp, -1, wcsTmp, MAX_PATH);
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_C2), wcsTmp);

		OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 5);
		FmtValueToString((void *)0x00BB8DF0, szTmp, MAX_PATH, NULL);
		MultiByteToWideChar(1253, 0, szTmp, -1, wcsTmp, MAX_PATH);
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_C3), wcsTmp);

		OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 6);
		FmtValueToString((void *)0x00BB8DF0, szTmp, MAX_PATH, NULL);
		MultiByteToWideChar(1253, 0, szTmp, -1, wcsTmp, MAX_PATH);
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_L0), wcsTmp);

		OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 7);
		FmtValueToString((void *)0x00BB8DF0, szTmp, MAX_PATH, NULL);
		MultiByteToWideChar(1253, 0, szTmp, -1, wcsTmp, MAX_PATH);
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_L1), wcsTmp);

		OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 8);
		FmtValueToString((void *)0x00BB8DF0, szTmp, MAX_PATH, NULL);
		MultiByteToWideChar(1253, 0, szTmp, -1, wcsTmp, MAX_PATH);
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_L2), wcsTmp);

		OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 9);
		FmtValueToString((void *)0x00BB8DF0, szTmp, MAX_PATH, NULL);
		MultiByteToWideChar(1253, 0, szTmp, -1, wcsTmp, MAX_PATH);
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_L3), wcsTmp);

		OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 10);
		FmtValueToString((void *)0x00BB8DF0, szTmp, MAX_PATH, NULL);
		MultiByteToWideChar(1253, 0, szTmp, -1, wcsTmp, MAX_PATH);
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_OD), wcsTmp);

		OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 11);
		FmtValueToString((void *)0x00BB8DF0, szTmp, MAX_PATH, NULL);
		MultiByteToWideChar(1253, 0, szTmp, -1, wcsTmp, MAX_PATH);
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_OZ), wcsTmp);

		OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 12);
		FmtValueToString((void *)0x00BB8DF0, szTmp, MAX_PATH, NULL);
		MultiByteToWideChar(1253, 0, szTmp, -1, wcsTmp, MAX_PATH);
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_OL), wcsTmp);

		OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 13);
		FmtValueToString((void *)0x00BB8DF0, szTmp, MAX_PATH, NULL);
		MultiByteToWideChar(1253, 0, szTmp, -1, wcsTmp, MAX_PATH);
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_AI), wcsTmp);
	}
}


LPCWSTR DeleteStar(LPWSTR wcsStr)
{
	wstring wsStr = wcsStr;
	int iCount = 0;

	iCount = wsStr.rfind(L" *");
	if (iCount != wstring::npos)
		wsStr.erase(wsStr.begin() + iCount, wsStr.begin() + iCount + 2);
	
	wcscpy_s(wcsStr,MAX_PATH, wsStr.c_str());
	return 00;
}

static void SaveValue_STD(HWND hClient, int nIndex)
{
#define PRIV_C0         0x00000001
#define PRIV_C1         0x00000002
#define PRIV_C2         0x00000004
#define PRIV_C3         0x00000008
#define PRIV_CX         0x0000000F
#define PRIV_L0         0x00000010
#define PRIV_L1         0x00000020
#define PRIV_L2         0x00000040
#define PRIV_L3         0x00000080
#define PRIV_LX         0x000000F0
#define PRIV_OD         0x00000100
#define PRIV_OZ         0x00000200
#define PRIV_OL         0x00000400
#define PRIV_OX         0x00000700
#define PRIV_AI         0x00000800


	int nTmp;
	WCHAR wcsTmp[MAX_PATH];

	GetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_KIT), wcsTmp, MAX_PATH);

	DeleteStar(wcsTmp);

	if (wcslen(wcsTmp)) 
		SetInputStringObjectW((void *)0x00BB8FD8, wcsTmp);

	if ((nIndex >= 0) && (nIndex < 0x15) && (lpThis_STD[nIndex]))
	{
		DWORD dwFlags;

		OrigSoftMenu_ItemClicked2(CA_MCK_DSTD, TA_MCK_DSTD, nIndex);
		OrigSoftMenu_Enter(lpThis_STD[nIndex]);
		OrigSoftMenu_UpdateItems(lpThis_STD[nIndex]);

		OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 0);
		GetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_STDLBL), wcsTmp, MAX_PATH);
		if (wcslen(wcsTmp)) 
			SetInputStringObjectW((void *)0x00BB8FD4, wcsTmp);

		nTmp = ComboBox_GetCurSel(GetDlgItem(hClient, IDC_CAL7_CB_STDTYPE));

		if ((nTmp >= 0) && (nTmp < 6))
		{
			OrigSoftMenu_Enter(CA_MCK_DSTD_TYPE);
			OrigSoftMenu_UpdateItems(CA_MCK_DSTD_TYPE);
			OrigSoftMenu_ItemClicked2(CA_MCK_DSTD_TYPE, TA_MCK_DSTD_TYPE, nTmp);
		}

		switch (nTmp)
		{
		case 0:
			dwFlags = PRIV_CX | PRIV_OX;
			break;

		case 1:
			dwFlags = PRIV_LX | PRIV_OX;
			break;

		case 2:
		case 3:
			dwFlags = PRIV_OX;
			break;

		case 4:
			dwFlags = PRIV_OX | PRIV_AI;
			break;

		default:
			dwFlags = 0;
			break;
		}

		if (CHK_FLAGS(dwFlags, PRIV_C0))
		{
			GetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_C0), wcsTmp, MAX_PATH);
			OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 2);
			ScanfStringToValueW((void *)0x00BB8DF0, wcsTmp, NULL);
		}

		if (CHK_FLAGS(dwFlags, PRIV_C1))
		{
			GetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_C1), wcsTmp, MAX_PATH);
			OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 3);
			ScanfStringToValueW((void *)0x00BB8DF0, wcsTmp, NULL);
		}

		if (CHK_FLAGS(dwFlags, PRIV_C2))
		{
			GetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_C2), wcsTmp, MAX_PATH);
			OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 4);
			ScanfStringToValueW((void *)0x00BB8DF0, wcsTmp, NULL);
		}

		if (CHK_FLAGS(dwFlags, PRIV_C3))
		{
			GetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_C3), wcsTmp, MAX_PATH);
			OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 5);
			ScanfStringToValueW((void *)0x00BB8DF0, wcsTmp, NULL);
		}

		if (CHK_FLAGS(dwFlags, PRIV_L0))
		{
			GetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_L0), wcsTmp, MAX_PATH);
			OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 6);
			ScanfStringToValueW((void *)0x00BB8DF0, wcsTmp, NULL);
		}

		if (CHK_FLAGS(dwFlags, PRIV_L1))
		{
			GetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_L1), wcsTmp, MAX_PATH);
			OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 7);
			ScanfStringToValueW((void *)0x00BB8DF0, wcsTmp, NULL);
		}

		if (CHK_FLAGS(dwFlags, PRIV_L2))
		{
			GetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_L2), wcsTmp, MAX_PATH);
			OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 8);
			ScanfStringToValueW((void *)0x00BB8DF0, wcsTmp, NULL);
		}

		if (CHK_FLAGS(dwFlags, PRIV_L3))
		{
			GetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_L3), wcsTmp, MAX_PATH);
			OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 9);
			ScanfStringToValueW((void *)0x00BB8DF0, wcsTmp, NULL);
		}

		if (CHK_FLAGS(dwFlags, PRIV_OD))
		{
			GetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_OD), wcsTmp, MAX_PATH);
			OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 10);
			ScanfStringToValueW((void *)0x00BB8DF0, wcsTmp, NULL);
		}

		if (CHK_FLAGS(dwFlags, PRIV_OZ))
		{
			GetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_OZ), wcsTmp, MAX_PATH);
			OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 11);
			ScanfStringToValueW((void *)0x00BB8DF0, wcsTmp, NULL);
		}

		if (CHK_FLAGS(dwFlags, PRIV_OL))
		{
			GetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_OL), wcsTmp, MAX_PATH);
			OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 12);
			ScanfStringToValueW((void *)0x00BB8DF0, wcsTmp, NULL);
		}

		if (CHK_FLAGS(dwFlags, PRIV_AI))
		{
			GetWindowTextW(GetDlgItem(hClient, IDC_CAL7_EDIT_AI), wcsTmp, MAX_PATH);
			OrigSoftMenu_ItemClicked2(lpThis_STD[nIndex], TA_MCK_DSTD_XX, 13);
			ScanfStringToValueW((void *)0x00BB8DF0, wcsTmp, NULL);
		}
	}

#undef PRIV_C0
#undef PRIV_C1
#undef PRIV_C2
#undef PRIV_C3
#undef PRIV_L0
#undef PRIV_L1
#undef PRIV_L2
#undef PRIV_L3
#undef PRIV_OD
#undef PRIV_OZ
#undef PRIV_OL
#undef PRIV_AI
}

INT_PTR WINAPI fndeCal_7(PCALDLG_CTXT lpDlgCtxt, DWORD dwCode, WPARAM wParam, LPARAM lParam, LPARAM lParam2)
{
	if (lpDlgCtxt == NULL) return -1;

	INT_PTR lResult = 0;

	switch (dwCode)
	{
	case DEC_ENTER:
	{
		OrigSoftMenu_Enter(CA_MCK);
		OrigSoftMenu_UpdateItems(CA_MCK);

		OrigSoftMenu_Enter(CA_MCK_DSTD);
		OrigSoftMenu_UpdateItems(CA_MCK_DSTD);

		OrigSoftMenu_Enter(CA_MCK_RCK);
		OrigSoftMenu_UpdateItems(CA_MCK_RCK);

		nLastIdx = -1;

		for (int nIndex = 0; nIndex < 21; nIndex++)
		{
			lpThis_STD[nIndex] = GetSubMenuPointer(CA_MCK_DSTD, nIndex);

			if (lpThis_STD[nIndex])
			{
				OrigSoftMenu_Enter(lpThis_STD[nIndex]);
				OrigSoftMenu_UpdateItems(lpThis_STD[nIndex]);
				OrigSoftMenu_Leave(lpThis_STD[nIndex]);
			}
		}

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL7_LBL_KIT),
			GetStringByIndex(L"Label Kit\0校准件命名\0校準件命名\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL7_CMD_RCK),
			GetStringByIndex(L"Restore Cal Kit\0恢复默认校准件\0恢復默認校準件\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL7_LBL_DEFSTD),
			GetStringByIndex(L"Define STDs\0定义标准\0定義標準\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL7_LBL_STDLBL),
			GetStringByIndex(L"STD Label\0标准命名\0標準命名\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL7_LBL_STDTYPE),
			GetStringByIndex(L"STD Type\0标准类型\0標準類型\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL7_LBL_OD),
			GetStringByIndex(L"Offset Delay\0延迟偏移\0延遲偏移\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL7_LBL_OZ),
			GetStringByIndex(L"Offset Z0\0阻抗偏移\0阻抗偏移\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL7_LBL_OL),
			GetStringByIndex(L"Offset Loss\0损耗偏移\0損耗偏移\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL7_LBL_AI),
			GetStringByIndex(L"Arb. Impedance\0绝对阻抗\0絕對阻抗\0\0", nLangId));


		ComboBox_InsertStringW(GetDlgItem((HWND)lParam2, IDC_CAL7_CB_STDTYPE), 0,
			GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));
		ComboBox_InsertStringW(GetDlgItem((HWND)lParam2, IDC_CAL7_CB_STDTYPE), 1,
			GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));
		ComboBox_InsertStringW(GetDlgItem((HWND)lParam2, IDC_CAL7_CB_STDTYPE), 2,
			GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));
		ComboBox_InsertStringW(GetDlgItem((HWND)lParam2, IDC_CAL7_CB_STDTYPE), 3,
			GetStringByIndex(L"Delay/Thru\0延迟/短接\0延遲/短接\0\0", nLangId));
		ComboBox_InsertStringW(GetDlgItem((HWND)lParam2, IDC_CAL7_CB_STDTYPE), 4,
			GetStringByIndex(L"Arbitrary\0任意阻抗\0任意阻抗\0\0", nLangId));
		ComboBox_InsertStringW(GetDlgItem((HWND)lParam2, IDC_CAL7_CB_STDTYPE), 5,
			GetStringByIndex(L"None\0无\0無\0\0", nLangId));

		UpdateComboBox_STD(GetDlgItem((HWND)lParam2, IDC_CAL7_CB_DEFSTD));
		UpdateValue_STD((HWND)lParam2, -1);
	}
	break;

	case DEC_CMD_NEXT:
		SaveValue_STD(lpDlgCtxt->hwClient, nLastIdx);
		OrigSoftMenu_Leave(CA_MCK_RCK);
		OrigSoftMenu_Leave(CA_MCK_DSTD);
		OrigSoftMenu_Leave(CA_MCK);
		UpdateDialog_Cal(&dcCal_7_1, 0);
		break;

	case DEC_CMD_CANCEL:
		lResult = TRUE;
		OrigSoftMenu_Leave(CA_MCK_RCK);
		OrigSoftMenu_Leave(CA_MCK_DSTD);
		OrigSoftMenu_Leave(CA_MCK);
		break;

	case DEC_CMD_CLOSE:
		lResult = TRUE;
		OrigSoftMenu_Leave(CA_MCK_RCK);
		OrigSoftMenu_Leave(CA_MCK_DSTD);
		OrigSoftMenu_Leave(CA_MCK);
		break;
	}

	return lResult;
}

INT_PTR CALLBACK fndpCal_7(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
		wpfn_InputEdit = (WNDPROC)SetWindowLong(GetDlgItem(hDlg, IDC_CAL7_EDIT_C0), GWL_WNDPROC, (LONG)&wp_InputEdit);
		SetWindowLong(GetDlgItem(hDlg, IDC_CAL7_EDIT_C1), GWL_WNDPROC, (LONG)&wp_InputEdit);
		SetWindowLong(GetDlgItem(hDlg, IDC_CAL7_EDIT_C2), GWL_WNDPROC, (LONG)&wp_InputEdit);
		SetWindowLong(GetDlgItem(hDlg, IDC_CAL7_EDIT_C3), GWL_WNDPROC, (LONG)&wp_InputEdit);
		SetWindowLong(GetDlgItem(hDlg, IDC_CAL7_EDIT_L0), GWL_WNDPROC, (LONG)&wp_InputEdit);
		SetWindowLong(GetDlgItem(hDlg, IDC_CAL7_EDIT_L1), GWL_WNDPROC, (LONG)&wp_InputEdit);
		SetWindowLong(GetDlgItem(hDlg, IDC_CAL7_EDIT_L2), GWL_WNDPROC, (LONG)&wp_InputEdit);
		SetWindowLong(GetDlgItem(hDlg, IDC_CAL7_EDIT_L3), GWL_WNDPROC, (LONG)&wp_InputEdit);
		SetWindowLong(GetDlgItem(hDlg, IDC_CAL7_EDIT_OD), GWL_WNDPROC, (LONG)&wp_InputEdit);
		SetWindowLong(GetDlgItem(hDlg, IDC_CAL7_EDIT_OZ), GWL_WNDPROC, (LONG)&wp_InputEdit);
		SetWindowLong(GetDlgItem(hDlg, IDC_CAL7_EDIT_AI), GWL_WNDPROC, (LONG)&wp_InputEdit);
		return TRUE;
	case WM_COMMAND:
	{
		WORD wId = LOWORD(wParam), wNc = HIWORD(wParam);

		if (lParam)
		{
			if (wNc == BN_CLICKED)
			{
				switch (wId)
				{
				case IDC_CAL7_CMD_RCK:
				{
					if (MessageBoxW(hDlg, L"是否恢复默认校准设置?", L"提示", MB_YESNO) == IDYES)
					{
						HWND hCtl = GetDlgItem(hDlg, IDC_CAL7_CB_DEFSTD);
						int nCurIndex = ComboBox_GetCurSel(hCtl);

						OrigSoftMenu_ItemClicked2(CA_MCK_RCK, TA_MCK_RCK, 0);
						UpdateComboBox_STD(hCtl);
						ComboBox_SetCurSel(hCtl, nCurIndex);
						UpdateValue_STD(hDlg, nCurIndex);
					}
				}
				break;
				}
				break;
			}

			if (wNc == CBN_SELCHANGE)
			{
				switch (wId)
				{
				case IDC_CAL7_CB_DEFSTD:
				{
					SaveValue_STD(hDlg, nLastIdx);
					nLastIdx = ComboBox_GetCurSel((HWND)lParam);
					UpdateValue_STD(hDlg, nLastIdx);
				}
				break;

				case IDC_CAL7_CB_STDTYPE:
				{
					UpdateTypeState_STD(hDlg, ComboBox_GetCurSel((HWND)lParam));
				}
				break;
				}
			}
		}
	}
	break;
	case WM_DESTROY:
		TagPage_RefreshItems(TRUE);
		break;
	}

	return FALSE;
}

LRESULT CALLBACK wp_InputEdit(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT lResult = 0;

	switch (msg)
	{
	case WM_CHAR:
	{
		int nIndex = 0;

		switch (GetWindowLong(hWnd, GWL_ID))
		{
		case IDC_CAL7_EDIT_C0:
			nIndex = 2;
			break;

		case IDC_CAL7_EDIT_C1:
			nIndex = 3;
			break;

		case IDC_CAL7_EDIT_C2:
			nIndex = 4;
			break;

		case IDC_CAL7_EDIT_C3:
			nIndex = 5;
			break;

		case IDC_CAL7_EDIT_L0:
			nIndex = 6;
			break;

		case IDC_CAL7_EDIT_L1:
			nIndex = 7;
			break;

		case IDC_CAL7_EDIT_L2:
			nIndex = 8;
			break;

		case IDC_CAL7_EDIT_L3:
			nIndex = 9;
			break;

		case IDC_CAL7_EDIT_OD:
			nIndex = 10;
			break;

		case IDC_CAL7_EDIT_OZ:
			nIndex = 11;
			break;

		case IDC_CAL7_EDIT_AI:
			nIndex = 13;
			break;

		default:
			if (wpfn_InputEdit)
				lResult = CallWindowProc(wpfn_InputEdit, hWnd, msg, wParam, lParam);
			else
				lResult = DefWindowProc(hWnd, msg, wParam, lParam);
			break;
		}

		if (lpThis_STD[nLastIdx] == NULL)
		{
			if (wpfn_InputEdit)
				lResult = CallWindowProc(wpfn_InputEdit, hWnd, msg, wParam, lParam);
			else
				lResult = DefWindowProc(hWnd, msg, wParam, lParam);
			break;
		}

		OrigSoftMenu_ItemClicked2(CA_MCK_DSTD, TA_MCK_DSTD, nLastIdx);
		OrigSoftMenu_UpdateItems(lpThis_STD[nLastIdx]);
		OrigSoftMenu_ItemClicked2(lpThis_STD[nLastIdx], TA_MCK_DSTD_XX, nIndex);

		switch (wParam)
		{
		case 'n':
		{
			WCHAR wcsText[MAX_PATH];

			GetWindowTextW(hWnd, wcsText, MAX_PATH);
			MakeUnitStringW((void *)0x00BB8DF0, wcsText, MAX_PATH, "n");
			SetWindowTextW(hWnd, wcsText);
		}
		break;

		case 'u':
		{
			WCHAR wcsText[MAX_PATH];

			GetWindowTextW(hWnd, wcsText, MAX_PATH);
			MakeUnitStringW((void *)0x00BB8DF0, wcsText, MAX_PATH, "\xEC\0");   //μ
			SetWindowTextW(hWnd, wcsText);
		}
		break;

		case 'm':
		{
			WCHAR wcsText[MAX_PATH];

			GetWindowTextW(hWnd, wcsText, MAX_PATH);
			MakeUnitStringW((void *)0x00BB8DF0, wcsText, MAX_PATH, "m");
			SetWindowTextW(hWnd, wcsText);
		}
		break;

		default:
		{
			if (((wParam >= 'A') && (wParam <= 'Z')) || ((wParam >= 'a') && (wParam <= 'z')))
				break;

			if (wpfn_InputEdit)
				lResult = CallWindowProc(wpfn_InputEdit, hWnd, msg, wParam, lParam);
			else
				lResult = DefWindowProc(hWnd, msg, wParam, lParam);
		}
		break;
		}

	}
	break;

	case WM_SETFOCUS:
		if (wpfn_InputEdit)
			lResult = CallWindowProc(wpfn_InputEdit, hWnd, msg, wParam, lParam);
		else
			lResult = DefWindowProc(hWnd, msg, wParam, lParam);

		SetInputType(ITID_NUM);
		break;

	case WM_KILLFOCUS:
		if (wpfn_InputEdit)
			lResult = CallWindowProc(wpfn_InputEdit, hWnd, msg, wParam, lParam);
		else
			lResult = DefWindowProc(hWnd, msg, wParam, lParam);

		SetInputType(ITID_UNKNOWN);
		break;

	default:
		if (wpfn_InputEdit)
			lResult = CallWindowProc(wpfn_InputEdit, hWnd, msg, wParam, lParam);
		else
			lResult = DefWindowProc(hWnd, msg, wParam, lParam);
		break;
	}

	return lResult;
}


CALDLG_CTXT dcCal_7 =
{
	NULL,
	IDD_CAL_7,
	DFL_CMD_NEXT | DFL_LBL_INFO1,
	&fndeCal_7,
	&fndpCal_7,
	NULL,
	NULL,
	NULL,
	L"Modify Cal Kit\0更换校准件\0更換校準件\0\0",
	L"Define STDs\0定义标准\0定義標準\0\0",
	L"\0\0",
	NULL,
	NULL,
	NULL,
	NULL,
	L"Exit\0退出\0退出\0\0",
	RESERVE_DWORD4,
	RESERVE_DWORD4
};