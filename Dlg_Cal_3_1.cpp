#include "stdafx.h"

#define PRIV_CMDTEXT            (const char *)0x00B63F5C

void *lpThis_P12 = NULL;
void *lpThis_P34 = NULL;
void *lpThis_P56 = NULL;
void *lpThis_P78 = NULL;
void *lpThis_P9A = NULL;
void *lpThis_PBC = NULL;

extern CALDLG_CTXT dcCal_3;

static void UnSelected(HWND hClient)
{
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P1), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P1), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P1), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P2), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P2), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P2), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P12), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_P12), BST_UNCHECKED);

	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P3), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P3), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P3), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P4), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P4), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P4), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P34), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_P34), BST_UNCHECKED);

	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P5), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P5), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P5), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P6), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P6), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P6), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P56), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_P56), BST_UNCHECKED);

	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P7), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P7), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P7), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P8), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P8), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P8), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P78), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_P78), BST_UNCHECKED);

	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P9), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P9), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P9), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_PA), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_PA), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_PA), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P9A), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_P9A), BST_UNCHECKED);

	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_PB), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_PB), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_PB), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_PC), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_PC), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_PC), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_PBC), BST_UNCHECKED);
	Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_PBC), BST_UNCHECKED);
}

static inline int TestCalData(int nIndex)
{
	LPSTR lpItemText = GetSubMenuItemText(CA_CTC, nIndex);
	char *lpRStr;

	if (lpItemText == NULL)
		return 0;

	lpRStr = strrchr(lpItemText, '*');

	if (lpRStr == NULL)
		return 0;

	if (lpRStr[1] == 0)
		return 1;

	return 0;
}

static void UpdateGroupBoxTitle(HWND hClient)
{
	OrigSoftMenu_UpdateItems(CA_CTC);

	if (TestCalData(0))
	{
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL31_GB_P12), GetStringByIndex(L"Port 1-2*\0端口1-2*\0端口1-2*\0\0", nLangId));
	}
	else
	{
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL31_GB_P12), GetStringByIndex(L"Port 1-2\0端口1-2\0端口1-2\0\0", nLangId));
	}

	if (TestCalData(1))
	{
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL31_GB_P34), GetStringByIndex(L"Port 3-4*\0端口3-4*\0端口3-4*\0\0", nLangId));
	}
	else
	{
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL31_GB_P34), GetStringByIndex(L"Port 3-4\0端口3-4\0端口3-4\0\0", nLangId));
	}

	if (TestCalData(2))
	{
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL31_GB_P56), GetStringByIndex(L"Port 5-6*\0端口5-6*\0端口5-6*\0\0", nLangId));
	}
	else
	{
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL31_GB_P56), GetStringByIndex(L"Port 5-6\0端口5-6\0端口5-6\0\0", nLangId));
	}

	if (TestCalData(3))
	{
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL31_GB_P78), GetStringByIndex(L"Port 7-8*\0端口7-8*\0端口7-8*\0\0", nLangId));
	}
	else
	{
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL31_GB_P78), GetStringByIndex(L"Port 7-8\0端口7-8\0端口7-8\0\0", nLangId));
	}

	if (TestCalData(4))
	{
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL31_GB_P9A), GetStringByIndex(L"Port 9-10*\0端口9-10*\0端口9-10*\0\0", nLangId));
	}
	else
	{
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL31_GB_P9A), GetStringByIndex(L"Port 9-10\0端口9-10\0端口9-10\0\0", nLangId));
	}

	if (TestCalData(5))
	{
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL31_GB_PBC), GetStringByIndex(L"Port 11-12*\0端口11-12*\0端口11-12*\0\0", nLangId));
	}
	else
	{
		SetWindowTextW(GetDlgItem(hClient, IDC_CAL31_GB_PBC), GetStringByIndex(L"Port 11-12\0端口11-12\0端口11-12\0\0", nLangId));
	}

}

static void UpdateRadioButton(HWND hClient)
{
	BOOL blTmp = FALSE;

	OrigSoftMenu_GetItemState(lpThis_P12, 0, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P1), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P1), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P12, 1, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P1), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P1), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P12, 2, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P1), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P1), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P12, 3, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P2), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P2), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P12, 4, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P2), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P2), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P12, 5, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P2), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P2), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P12, 6, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P12), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P12), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P12, 7, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_P12), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_P12), BST_UNCHECKED);



	OrigSoftMenu_GetItemState(lpThis_P34, 0, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P3), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P3), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P34, 1, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P3), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P3), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P34, 2, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P3), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P3), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P34, 3, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P4), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P4), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P34, 4, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P4), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P4), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P34, 5, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P4), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P4), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P34, 6, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P34), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P34), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P34, 7, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_P34), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_P34), BST_UNCHECKED);



	OrigSoftMenu_GetItemState(lpThis_P56, 0, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P5), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P5), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P56, 1, NULL, &blTmp, NULL);
	if (blTmp & 0xFF) Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P5), BST_CHECKED);
	else Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P5), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P56, 2, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P5), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P5), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P56, 3, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P6), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P6), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P56, 4, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P6), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P6), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P56, 5, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P6), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P6), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P56, 6, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P56), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P56), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P56, 7, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_P56), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_P56), BST_UNCHECKED);




	OrigSoftMenu_GetItemState(lpThis_P78, 0, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P7), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P7), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P78, 1, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P7), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P7), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P78, 2, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P7), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P7), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P78, 3, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P8), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P8), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P78, 4, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P8), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P8), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P78, 5, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P8), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P8), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P78, 6, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P78), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P78), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P78, 7, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_P78), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_P78), BST_UNCHECKED);



	OrigSoftMenu_GetItemState(lpThis_P9A, 0, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P9), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P9), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P9A, 1, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P9), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P9), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P9A, 2, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P9), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P9), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P9A, 3, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_PA), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_PA), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P9A, 4, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_PA), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_PA), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P9A, 5, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_PA), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_PA), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P9A, 6, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P9A), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P9A), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_P9A, 7, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_P9A), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_P9A), BST_UNCHECKED);



	OrigSoftMenu_GetItemState(lpThis_PBC, 0, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_PB), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_PB), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_PBC, 1, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_PB), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_PB), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_PBC, 2, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_PB), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_PB), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_PBC, 3, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_PC), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_PC), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_PBC, 4, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_PC), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_PC), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_PBC, 5, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_PC), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_PC), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_PBC, 6, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_PBC), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_PBC), BST_UNCHECKED);

	OrigSoftMenu_GetItemState(lpThis_PBC, 7, NULL, &blTmp, NULL);
	if (blTmp & 0xFF)
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_PBC), BST_CHECKED);
	else
		Button_SetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_I_PBC), BST_UNCHECKED);
}

static void UpdateECalButton(HWND hClient)
{
	BOOL blTmp = FALSE;

	OrigSoftMenu_GetItemState(lpThis_P12, 8, &blTmp, NULL, NULL);
	EnableWindow(GetDlgItem(hClient, IDC_CAL31_CMD_E_P12), blTmp & 0xFF);

	OrigSoftMenu_GetItemState(lpThis_P34, 8, &blTmp, NULL, NULL);
	EnableWindow(GetDlgItem(hClient, IDC_CAL31_CMD_E_P34), blTmp & 0xFF);

	OrigSoftMenu_GetItemState(lpThis_P56, 8, &blTmp, NULL, NULL);
	EnableWindow(GetDlgItem(hClient, IDC_CAL31_CMD_E_P56), blTmp & 0xFF);

	OrigSoftMenu_GetItemState(lpThis_P78, 8, &blTmp, NULL, NULL);
	EnableWindow(GetDlgItem(hClient, IDC_CAL31_CMD_E_P78), blTmp & 0xFF);

	OrigSoftMenu_GetItemState(lpThis_P9A, 8, &blTmp, NULL, NULL);
	EnableWindow(GetDlgItem(hClient, IDC_CAL31_CMD_E_P9A), blTmp & 0xFF);

	OrigSoftMenu_GetItemState(lpThis_PBC, 8, &blTmp, NULL, NULL);
	EnableWindow(GetDlgItem(hClient, IDC_CAL31_CMD_E_PBC), blTmp & 0xFF);
}


static void UpdateDoneButton(HWND hClient)
{
	if ((Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P1)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P1)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P1)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P2)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P2)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P2)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P12)) != BST_UNCHECKED))
	{
		EnableButton_Cal(DEC_CMD_OK, TRUE);
		return;
	}

	if ((Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P3)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P3)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P3)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P4)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P4)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P4)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P34)) != BST_UNCHECKED))
	{
		EnableButton_Cal(DEC_CMD_OK, TRUE);
		return;
	}

	if ((Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P5)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P5)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P5)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P6)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P6)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P6)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P56)) != BST_UNCHECKED))
	{
		EnableButton_Cal(DEC_CMD_OK, TRUE);
		return;
	}

	if ((Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P7)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P7)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P7)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P8)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P8)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P8)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P78)) != BST_UNCHECKED))
	{
		EnableButton_Cal(DEC_CMD_OK, TRUE);
		return;
	}

	if ((Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_P9)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_P9)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_P9)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_PA)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_PA)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_PA)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_P9A)) != BST_UNCHECKED))
	{
		EnableButton_Cal(DEC_CMD_OK, TRUE);
		return;
	}

	if ((Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_PB)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_PB)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_PB)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_O_PC)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_S_PC)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_L_PC)) != BST_UNCHECKED) &&
		(Button_GetCheck(GetDlgItem(hClient, IDC_CAL31_CMD_T_PBC)) != BST_UNCHECKED))
	{
		EnableButton_Cal(DEC_CMD_OK, TRUE);
		return;
	}

	EnableButton_Cal(DEC_CMD_OK, FALSE);
}

INT_PTR WINAPI fndeCal_3_1(PCALDLG_CTXT lpDlgCtxt, DWORD dwCode, WPARAM wParam, LPARAM lParam, LPARAM lParam2)
{
	if (lpDlgCtxt == NULL)
		return -1;

	INT_PTR lResult = 0;

	switch (dwCode)
	{
	case DEC_ENTER:

		lpThis_P12 = GetSubMenuPointer(CA_CTC, 0);
		if (lpThis_P12)
		{
			OrigSoftMenu_Enter(lpThis_P12);
			OrigSoftMenu_UpdateItems(lpThis_P12);
		}

		lpThis_P34 = GetSubMenuPointer(CA_CTC, 1);
		if (lpThis_P34)
		{
			OrigSoftMenu_Enter(lpThis_P34);
			OrigSoftMenu_UpdateItems(lpThis_P34);
		}

		lpThis_P56 = GetSubMenuPointer(CA_CTC, 2);
		if (lpThis_P56)
		{
			OrigSoftMenu_Enter(lpThis_P56);
			OrigSoftMenu_UpdateItems(lpThis_P56);
		}

		lpThis_P78 = GetSubMenuPointer(CA_CTC, 3);
		if (lpThis_P78)
		{
			OrigSoftMenu_Enter(lpThis_P78);
			OrigSoftMenu_UpdateItems(lpThis_P78);
		}

		lpThis_P9A = GetSubMenuPointer(CA_CTC, 4);
		if (lpThis_P9A)
		{
			OrigSoftMenu_Enter(lpThis_P9A);
			OrigSoftMenu_UpdateItems(lpThis_P9A);
		}

		lpThis_PBC = GetSubMenuPointer(CA_CTC, 5);
		if (lpThis_PBC)
		{
			OrigSoftMenu_Enter(lpThis_PBC);
			OrigSoftMenu_UpdateItems(lpThis_PBC);
		}

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_GB_P12), GetStringByIndex(L"Port 1-2\0端口1-2\0端口1-2\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_P1), GetStringByIndex(L"Port 1\0端口1\0端口1\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_P2), GetStringByIndex(L"Port 2\0端口2\0端口2\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_P12), GetStringByIndex(L"Port 1-2\0端口1-2\0端口1-2\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_O_P1), GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_S_P1), GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_L_P1), GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_O_P2), GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_S_P2), GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_L_P2), GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_T_P12), GetStringByIndex(L"Thru\0短接\0短接\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_I_P12), GetStringByIndex(L"Isol(Optional)\0隔离(可选)\0隔離(可選)\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_E_P12), GetStringByIndex(L"ECal\0电子校准\0電子校準\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_GB_P34), GetStringByIndex(L"Port 3-4\0端口3-4\0端口3-4\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_P3), GetStringByIndex(L"Port 3\0端口3\0端口3\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_P4), GetStringByIndex(L"Port 4\0端口4\0端口4\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_P34), GetStringByIndex(L"Port 3-4\0端口3-4\0端口3-4\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_O_P3), GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_S_P3), GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_L_P3), GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_O_P4), GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_S_P4), GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_L_P4), GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_T_P34), GetStringByIndex(L"Thru\0短接\0短接\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_I_P34), GetStringByIndex(L"Isol(Optional)\0隔离(可选)\0隔離(可選)\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_E_P34), GetStringByIndex(L"ECal\0电子校准\0電子校準\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_GB_P56), GetStringByIndex(L"Port 5-6\0端口5-6\0端口5-6\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_P5), GetStringByIndex(L"Port 5\0端口5\0端口5\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_P6), GetStringByIndex(L"Port 6\0端口6\0端口6\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_P56), GetStringByIndex(L"Port 5-6\0端口5-6\0端口5-6\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_O_P5), GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_S_P5), GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_L_P5), GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_O_P6), GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_S_P6), GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_L_P6), GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_T_P56), GetStringByIndex(L"Thru\0短接\0短接\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_I_P56), GetStringByIndex(L"Isol(Optional)\0隔离(可选)\0隔離(可選)\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_E_P56), GetStringByIndex(L"ECal\0电子校准\0電子校準\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_GB_P78), GetStringByIndex(L"Port 7-8\0端口7-8\0端口7-8\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_P7), GetStringByIndex(L"Port 7\0端口7\0端口7\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_P8), GetStringByIndex(L"Port 8\0端口8\0端口8\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_P78), GetStringByIndex(L"Port 7-8\0端口7-8\0端口7-8\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_O_P7), GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_S_P7), GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_L_P7), GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_O_P8), GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_S_P8), GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_L_P8), GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_T_P78), GetStringByIndex(L"Thru\0短接\0短接\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_I_P78), GetStringByIndex(L"Isol(Optional)\0隔离(可选)\0隔離(可選)\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_E_P78), GetStringByIndex(L"ECal\0电子校准\0電子校準\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_GB_P9A), GetStringByIndex(L"Port 9-10\0端口9-10\0端口9-10\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_P9), GetStringByIndex(L"Port 9\0端口9\0端口9\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_PA), GetStringByIndex(L"Port 10\0端口10\0端口10\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_P9A), GetStringByIndex(L"Port 9-10\0端口9-10\0端口9-10\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_O_P9), GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_S_P9), GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_L_P9), GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_O_PA), GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_S_PA), GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_L_PA), GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_T_P9A), GetStringByIndex(L"Thru\0短接\0短接\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_I_P9A), GetStringByIndex(L"Isol(Optional)\0隔离(可选)\0隔離(可選)\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_E_P9A), GetStringByIndex(L"ECal\0电子校准\0電子校準\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_GB_PBC), GetStringByIndex(L"Port 11-12\0端口11-12\0端口11-12\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_PB), GetStringByIndex(L"Port 11\0端口11\0端口11\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_PC), GetStringByIndex(L"Port 12\0端口12\0端口12\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_PBC), GetStringByIndex(L"Port 11-12\0端口11-12\0端口11-12\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_O_PB), GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_S_PB), GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_L_PB), GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_O_PC), GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_S_PC), GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_L_PC), GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_T_PBC), GetStringByIndex(L"Thru\0短接\0短接\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_I_PBC), GetStringByIndex(L"Isol(Optional)\0隔离(可选)\0隔離(可選)\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL31_CMD_E_PBC), GetStringByIndex(L"ECal\0电子校准\0電子校準\0\0", nLangId));

		UpdateGroupBoxTitle((HWND)lParam2);
		UpdateRadioButton((HWND)lParam2);
		UpdateECalButton((HWND)lParam2);
		UpdateDoneButton((HWND)lParam2);

		break;

	case DEC_CMD_PREV:
		UpdateDialog_Cal(&dcCal_3, 0);
		break;


	case DEC_CMD_OK:
		OrigSoftMenu_ItemClicked2(CA_CTC, TA_CTC, 8);
		break;

	case DEC_CMD_CANCEL:
	{
		LPCWSTR lpText = GetStringByIndex(L"Whether to cancel the calibration data?\0是否取消校准数据?\0是否取消校準數據?\0\0", nLangId);
		LPCWSTR lpTitle = GetStringByIndex(L"Confirm the cancellation\0确认取消操作\0確認取消操作\0\0", nLangId);

		if (DialogMsgBox_Cal(lpText, lpTitle, MB_YESNO) == IDYES)
		{
			OrigSoftMenu_Enter(CA_CTCC);
			OrigSoftMenu_UpdateItems(CA_CTCC);

			OrigSoftMenu_ItemClicked2(CA_CTCC, TA_CTCC, 0);

			UnSelected(lpDlgCtxt->hwClient);
		}
	}
	break;

	case DEC_CMD_CLOSE:
		lResult = TRUE;
		break;
	}

	return lResult;
}

INT_PTR CALLBACK fndpCal_3_1(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
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
				case IDC_CAL31_CMD_O_P1:
					if (lpThis_P12 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P12, TA_CTC_PXX, 0);
					break;

				case IDC_CAL31_CMD_S_P1:
					if (lpThis_P12 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P12, TA_CTC_PXX, 1);
					break;

				case IDC_CAL31_CMD_L_P1:
					if (lpThis_P12 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P12, TA_CTC_PXX, 2);
					break;

				case IDC_CAL31_CMD_O_P2:
					if (lpThis_P12 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P12, TA_CTC_PXX, 3);
					break;

				case IDC_CAL31_CMD_S_P2:
					if (lpThis_P12 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P12, TA_CTC_PXX, 4);
					break;

				case IDC_CAL31_CMD_L_P2:
					if (lpThis_P12 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P12, TA_CTC_PXX, 5);
					break;

				case IDC_CAL31_CMD_T_P12:
					if (lpThis_P12 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P12, TA_CTC_PXX, 6);
					break;

				case IDC_CAL31_CMD_I_P12:
					if (lpThis_P12 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P12, TA_CTC_PXX, 7);
					break;

				case IDC_CAL31_CMD_E_P12:
					if (lpThis_P12 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P12, TA_CTC_PXX, 8);
					break;

				case IDC_CAL31_CMD_O_P3:
					if (lpThis_P34 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P34, TA_CTC_PXX, 0);
					break;

				case IDC_CAL31_CMD_S_P3:
					if (lpThis_P34 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P34, TA_CTC_PXX, 1);
					break;

				case IDC_CAL31_CMD_L_P3:
					if (lpThis_P34 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P34, TA_CTC_PXX, 2);
					break;

				case IDC_CAL31_CMD_O_P4:
					if (lpThis_P34 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P34, TA_CTC_PXX, 3);
					break;

				case IDC_CAL31_CMD_S_P4:
					if (lpThis_P34 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P34, TA_CTC_PXX, 4);
					break;

				case IDC_CAL31_CMD_L_P4:
					if (lpThis_P34 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P34, TA_CTC_PXX, 5);
					break;

				case IDC_CAL31_CMD_T_P34:
					if (lpThis_P34 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P34, TA_CTC_PXX, 6);
					break;

				case IDC_CAL31_CMD_I_P34:
					if (lpThis_P34 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P34, TA_CTC_PXX, 7);
					break;

				case IDC_CAL31_CMD_E_P34:
					if (lpThis_P34 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P34, TA_CTC_PXX, 8);
					break;

				case IDC_CAL31_CMD_O_P5:
					if (lpThis_P56 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P56, TA_CTC_PXX, 0);
					break;

				case IDC_CAL31_CMD_S_P5:
					if (lpThis_P56 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P56, TA_CTC_PXX, 1);
					break;

				case IDC_CAL31_CMD_L_P5:
					if (lpThis_P56 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P56, TA_CTC_PXX, 2);
					break;

				case IDC_CAL31_CMD_O_P6:
					if (lpThis_P56 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P56, TA_CTC_PXX, 3);
					break;

				case IDC_CAL31_CMD_S_P6:
					if (lpThis_P56 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P56, TA_CTC_PXX, 4);
					break;

				case IDC_CAL31_CMD_L_P6:
					if (lpThis_P56 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P56, TA_CTC_PXX, 5);
					break;

				case IDC_CAL31_CMD_T_P56:
					if (lpThis_P56 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P56, TA_CTC_PXX, 6);
					break;

				case IDC_CAL31_CMD_I_P56:
					if (lpThis_P56 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P56, TA_CTC_PXX, 7);
					break;

				case IDC_CAL31_CMD_E_P56:
					if (lpThis_P56 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P56, TA_CTC_PXX, 8);
					break;

				case IDC_CAL31_CMD_O_P7:
					if (lpThis_P78 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P78, TA_CTC_PXX, 0);
					break;

				case IDC_CAL31_CMD_S_P7:
					if (lpThis_P78 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P78, TA_CTC_PXX, 1);
					break;

				case IDC_CAL31_CMD_L_P7:
					if (lpThis_P78 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P78, TA_CTC_PXX, 2);
					break;

				case IDC_CAL31_CMD_O_P8:
					if (lpThis_P78 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P78, TA_CTC_PXX, 3);
					break;

				case IDC_CAL31_CMD_S_P8:
					if (lpThis_P78 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P78, TA_CTC_PXX, 4);
					break;

				case IDC_CAL31_CMD_L_P8:
					if (lpThis_P78 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P78, TA_CTC_PXX, 5);
					break;

				case IDC_CAL31_CMD_T_P78:
					if (lpThis_P78 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P78, TA_CTC_PXX, 6);
					break;

				case IDC_CAL31_CMD_I_P78:
					if (lpThis_P78 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P78, TA_CTC_PXX, 7);
					break;

				case IDC_CAL31_CMD_E_P78:
					if (lpThis_P78 == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P78, TA_CTC_PXX, 8);
					break;

				case IDC_CAL31_CMD_O_P9:
					if (lpThis_P9A == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P9A, TA_CTC_PXX, 0);
					break;

				case IDC_CAL31_CMD_S_P9:
					if (lpThis_P9A == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P9A, TA_CTC_PXX, 1);
					break;

				case IDC_CAL31_CMD_L_P9:
					if (lpThis_P9A == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P9A, TA_CTC_PXX, 2);
					break;

				case IDC_CAL31_CMD_O_PA:
					if (lpThis_P9A == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P9A, TA_CTC_PXX, 3);
					break;

				case IDC_CAL31_CMD_S_PA:
					if (lpThis_P9A == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P9A, TA_CTC_PXX, 4);
					break;

				case IDC_CAL31_CMD_L_PA:
					if (lpThis_P9A == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P9A, TA_CTC_PXX, 5);
					break;

				case IDC_CAL31_CMD_T_P9A:
					if (lpThis_P9A == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P9A, TA_CTC_PXX, 6);
					break;

				case IDC_CAL31_CMD_I_P9A:
					if (lpThis_P9A == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P9A, TA_CTC_PXX, 7);
					break;

				case IDC_CAL31_CMD_E_P9A:
					if (lpThis_P9A == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_P9A, TA_CTC_PXX, 8);
					break;

				case IDC_CAL31_CMD_O_PB:
					if (lpThis_PBC == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_PBC, TA_CTC_PXX, 0);
					break;

				case IDC_CAL31_CMD_S_PB:
					if (lpThis_PBC == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_PBC, TA_CTC_PXX, 1);
					break;

				case IDC_CAL31_CMD_L_PB:
					if (lpThis_PBC == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_PBC, TA_CTC_PXX, 2);
					break;

				case IDC_CAL31_CMD_O_PC:
					if (lpThis_PBC == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_PBC, TA_CTC_PXX, 3);
					break;

				case IDC_CAL31_CMD_S_PC:
					if (lpThis_PBC == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_PBC, TA_CTC_PXX, 4);
					break;

				case IDC_CAL31_CMD_L_PC:
					if (lpThis_PBC == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_PBC, TA_CTC_PXX, 5);
					break;

				case IDC_CAL31_CMD_T_PBC:
					if (lpThis_PBC == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_PBC, TA_CTC_PXX, 6);
					break;

				case IDC_CAL31_CMD_I_PBC:
					if (lpThis_PBC == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_PBC, TA_CTC_PXX, 7);
					break;

				case IDC_CAL31_CMD_E_PBC:
					if (lpThis_PBC == NULL)
						break;
					OrigSoftMenu_ItemClicked2(lpThis_PBC, TA_CTC_PXX, 8);
					break;
				}

				UpdateDoneButton(hDlg);
			}
		}
	}
	break;
	}

	return FALSE;
}

CALDLG_CTXT dcCal_3_1 =
{
	NULL,
	IDD_CAL_3_1,
	DFL_CMD_PREV | DFL_CMD_OK | DFL_LBL_INFO1,
	&fndeCal_3_1,
	&fndpCal_3_1,
	NULL,
	NULL,
	NULL,
	L"Test Set Cal\0测试装置校准\0測試裝置校準\0\0",
	NULL,
	L"\0\0",
	L"标有#的部分为可选部分\0\0",
	NULL,
	NULL,
	L"Done\0完成\0完成\0\0",
	L"Cancel\0取消\0取消\0\0",
	RESERVE_DWORD4,
	RESERVE_DWORD4
};