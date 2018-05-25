#include "stdafx.h"

#define PRIV_M_NORMAL         0
#define PRIV_M_INVERT         1

#define PRIV_I_DT1            0
#define PRIV_I_DT2            1
#define PRIV_I_DT3            2
#define PRIV_I_DT4            3
#define PRIV_I_MT1            4
#define PRIV_I_MT2            5
#define PRIV_I_MT3            6
#define PRIV_I_MT4            7
#define PRIV_I_GM             8
#define PRIV_I_GS             9
#define PRIV_I_LF             10
#define PRIV_I_LL             11
#define PRIV_I_BG             12

#define PFLG_I_DT1            0x00000001
#define PFLG_I_DT2            0x00000002
#define PFLG_I_DT3            0x00000004
#define PFLG_I_DT4            0x00000008
#define PFLG_I_MT1            0x00000010
#define PFLG_I_MT2            0x00000020
#define PFLG_I_MT3            0x00000040
#define PFLG_I_MT4            0x00000080
#define PFLG_I_GM             0x00000100
#define PFLG_I_GS             0x00000200
#define PFLG_I_LF             0x00000400
#define PFLG_I_LL             0x00000800
#define PFLG_I_BG             0x00001000


static int nMode, nChange;
static void *lpThis_Mode[2] = { NULL, NULL };
static void *lpThis_Mode_RC[2] = { NULL, NULL };
static void *lpThis_R = NULL, *lpThis_G = NULL, *lpThis_B = NULL;

void UpdateColorValue(HWND hDlg);

INT_PTR WINAPI fndeColor(PDLG_CTXT lpDlgCtxt, DWORD dwCode, WPARAM wParam, LPARAM lParam, LPARAM lParam2)
{
	if (lpDlgCtxt == NULL) return -1;

	INT_PTR lResult = 0;

	switch (dwCode)
	{
	case DEC_ENTER:
	{
		OrigSoftMenu_Enter(CA_CLR);
		OrigSoftMenu_UpdateItems(CA_CLR);

		UpdateColorValue((HWND)lParam2);
	}
	break;

	case DEC_CMD_CLOSE:
		lResult = TRUE;
		break;
	}

	return lResult;
}

void UpdateColorValue(HWND hDlg)
{
	int nR, nG, nB;

	if (nMode < 0 || nMode > 1) return;

	OrigSoftMenu_ItemClicked2(CA_CLR, TA_CLR, nMode);

	if (lpThis_Mode[nMode] == NULL)
	{
		lpThis_Mode[nMode] = GetSubMenuPointer(CA_CLR, nMode);

		//OrigSoftMenu_Enter(lpThis_Mode[nMode]);
		OrigSoftMenu_UpdateItems(lpThis_Mode[nMode]);
	}

	//OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, 0);
	//OrigSoftMenu_Enter(CA_CLR_XX_RGB);

	OrigSoftMenu_UpdateItems(CA_CLR_XX_RGB);

	if (lpThis_R == NULL) 
		lpThis_R = GetSubMenuPointer(CA_CLR_XX_RGB, 0);
	if (lpThis_G == NULL) 
		lpThis_G = GetSubMenuPointer(CA_CLR_XX_RGB, 1);
	if (lpThis_B == NULL) 
		lpThis_B = GetSubMenuPointer(CA_CLR_XX_RGB, 2);

	if (lpThis_Mode[nMode] == NULL || lpThis_R == NULL ||
		lpThis_G == NULL || lpThis_B == NULL)
		return;

	OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_DT1);
	nR = GetSubMenuSelected(lpThis_R);
	nG = GetSubMenuSelected(lpThis_G);
	nB = GetSubMenuSelected(lpThis_B);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT1_R), nR);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT1_G), nG);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT1_B), nB);


	OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_DT2);
	nR = GetSubMenuSelected(lpThis_R);
	nG = GetSubMenuSelected(lpThis_G);
	nB = GetSubMenuSelected(lpThis_B);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT2_R), nR);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT2_G), nG);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT2_B), nB);


	OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_DT3);
	nR = GetSubMenuSelected(lpThis_R);
	nG = GetSubMenuSelected(lpThis_G);
	nB = GetSubMenuSelected(lpThis_B);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT3_R), nR);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT3_G), nG);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT3_B), nB);


	OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_DT4);
	nR = GetSubMenuSelected(lpThis_R);
	nG = GetSubMenuSelected(lpThis_G);
	nB = GetSubMenuSelected(lpThis_B);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT4_R), nR);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT4_G), nG);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT4_B), nB);


	OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_MT1);
	nR = GetSubMenuSelected(lpThis_R);
	nG = GetSubMenuSelected(lpThis_G);
	nB = GetSubMenuSelected(lpThis_B);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT1_R), nR);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT1_G), nG);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT1_B), nB);


	OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_MT2);
	nR = GetSubMenuSelected(lpThis_R);
	nG = GetSubMenuSelected(lpThis_G);
	nB = GetSubMenuSelected(lpThis_B);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT2_R), nR);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT2_G), nG);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT2_B), nB);


	OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_MT3);
	nR = GetSubMenuSelected(lpThis_R);
	nG = GetSubMenuSelected(lpThis_G);
	nB = GetSubMenuSelected(lpThis_B);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT3_R), nR);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT3_G), nG);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT3_B), nB);


	OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_MT4);
	nR = GetSubMenuSelected(lpThis_R);
	nG = GetSubMenuSelected(lpThis_G);
	nB = GetSubMenuSelected(lpThis_B);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT4_R), nR);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT4_G), nG);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT4_B), nB);


	OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_GM);
	nR = GetSubMenuSelected(lpThis_R);
	nG = GetSubMenuSelected(lpThis_G);
	nB = GetSubMenuSelected(lpThis_B);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_GM_R), nR);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_GM_G), nG);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_GM_B), nB);


	OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_GS);
	nR = GetSubMenuSelected(lpThis_R);
	nG = GetSubMenuSelected(lpThis_G);
	nB = GetSubMenuSelected(lpThis_B);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_GS_R), nR);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_GS_G), nG);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_GS_B), nB);


	OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_LF);
	nR = GetSubMenuSelected(lpThis_R);
	nG = GetSubMenuSelected(lpThis_G);
	nB = GetSubMenuSelected(lpThis_B);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_LF_R), nR);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_LF_G), nG);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_LF_B), nB);


	OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_LL);
	nR = GetSubMenuSelected(lpThis_R);
	nG = GetSubMenuSelected(lpThis_G);
	nB = GetSubMenuSelected(lpThis_B);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_LL_R), nR);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_LL_G), nG);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_LL_B), nB);


	OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_BG);
	nR = GetSubMenuSelected(lpThis_R);
	nG = GetSubMenuSelected(lpThis_G);
	nB = GetSubMenuSelected(lpThis_B);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_BG_R), nR);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_BG_G), nG);
	ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_BG_B), nB);
}

void SaveColorValue(HWND hDlg)
{
	int nR, nG, nB;

	if (nMode < 0 || nMode > 1) return;

	OrigSoftMenu_ItemClicked2(CA_CLR, TA_CLR, nMode);

	if (lpThis_Mode[nMode] == NULL)
	{
		lpThis_Mode[nMode] = GetSubMenuPointer(CA_CLR, nMode);

		OrigSoftMenu_UpdateItems(lpThis_Mode[nMode]);
	}

	OrigSoftMenu_UpdateItems(CA_CLR_XX_RGB);

	if (lpThis_R == NULL) lpThis_R = GetSubMenuPointer(CA_CLR_XX_RGB, 0);
	if (lpThis_G == NULL) lpThis_G = GetSubMenuPointer(CA_CLR_XX_RGB, 1);
	if (lpThis_B == NULL) lpThis_B = GetSubMenuPointer(CA_CLR_XX_RGB, 2);

	if (lpThis_Mode[nMode] == NULL || lpThis_R == NULL ||
		lpThis_G == NULL || lpThis_B == NULL)
		return;

	if (CHK_FLAGS(nChange, PFLG_I_DT1))
	{
		nR = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT1_R));
		nG = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT1_G));
		nB = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT1_B));

		OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_DT1);


		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 0);
		OrigSoftMenu_ItemClicked2(lpThis_R, TA_CLR_XX_RGB_X, nR);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 1);
		OrigSoftMenu_ItemClicked2(lpThis_G, TA_CLR_XX_RGB_X, nG);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 2);
		OrigSoftMenu_ItemClicked2(lpThis_B, TA_CLR_XX_RGB_X, nB);
	}

	if (CHK_FLAGS(nChange, PFLG_I_DT2))
	{
		nR = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT2_R));
		nG = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT2_G));
		nB = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT2_B));

		OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_DT2);


		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 0);
		OrigSoftMenu_ItemClicked2(lpThis_R, TA_CLR_XX_RGB_X, nR);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 1);
		OrigSoftMenu_ItemClicked2(lpThis_G, TA_CLR_XX_RGB_X, nG);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 2);
		OrigSoftMenu_ItemClicked2(lpThis_B, TA_CLR_XX_RGB_X, nB);
	}

	if (CHK_FLAGS(nChange, PFLG_I_DT3))
	{
		nR = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT3_R));
		nG = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT3_G));
		nB = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT3_B));

		OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_DT3);


		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 0);
		OrigSoftMenu_ItemClicked2(lpThis_R, TA_CLR_XX_RGB_X, nR);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 1);
		OrigSoftMenu_ItemClicked2(lpThis_G, TA_CLR_XX_RGB_X, nG);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 2);
		OrigSoftMenu_ItemClicked2(lpThis_B, TA_CLR_XX_RGB_X, nB);
	}

	if (CHK_FLAGS(nChange, PFLG_I_DT4))
	{
		nR = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT4_R));
		nG = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT4_G));
		nB = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_DT4_B));

		OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_DT4);


		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 0);
		OrigSoftMenu_ItemClicked2(lpThis_R, TA_CLR_XX_RGB_X, nR);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 1);
		OrigSoftMenu_ItemClicked2(lpThis_G, TA_CLR_XX_RGB_X, nG);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 2);
		OrigSoftMenu_ItemClicked2(lpThis_B, TA_CLR_XX_RGB_X, nB);
	}

	if (CHK_FLAGS(nChange, PFLG_I_MT1))
	{
		nR = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT1_R));
		nG = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT1_G));
		nB = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT1_B));

		OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_MT1);


		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 0);
		OrigSoftMenu_ItemClicked2(lpThis_R, TA_CLR_XX_RGB_X, nR);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 1);
		OrigSoftMenu_ItemClicked2(lpThis_G, TA_CLR_XX_RGB_X, nG);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 2);
		OrigSoftMenu_ItemClicked2(lpThis_B, TA_CLR_XX_RGB_X, nB);
	}

	if (CHK_FLAGS(nChange, PFLG_I_MT2))
	{
		nR = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT2_R));
		nG = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT2_G));
		nB = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT2_B));

		OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_MT2);


		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 0);
		OrigSoftMenu_ItemClicked2(lpThis_R, TA_CLR_XX_RGB_X, nR);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 1);
		OrigSoftMenu_ItemClicked2(lpThis_G, TA_CLR_XX_RGB_X, nG);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 2);
		OrigSoftMenu_ItemClicked2(lpThis_B, TA_CLR_XX_RGB_X, nB);
	}

	if (CHK_FLAGS(nChange, PFLG_I_MT3))
	{
		nR = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT3_R));
		nG = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT3_G));
		nB = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT3_B));

		OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_MT3);


		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 0);
		OrigSoftMenu_ItemClicked2(lpThis_R, TA_CLR_XX_RGB_X, nR);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 1);
		OrigSoftMenu_ItemClicked2(lpThis_G, TA_CLR_XX_RGB_X, nG);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 2);
		OrigSoftMenu_ItemClicked2(lpThis_B, TA_CLR_XX_RGB_X, nB);
	}

	if (CHK_FLAGS(nChange, PFLG_I_MT4))
	{
		nR = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT4_R));
		nG = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT4_G));
		nB = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_MT4_B));

		OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_MT4);


		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 0);
		OrigSoftMenu_ItemClicked2(lpThis_R, TA_CLR_XX_RGB_X, nR);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 1);
		OrigSoftMenu_ItemClicked2(lpThis_G, TA_CLR_XX_RGB_X, nG);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 2);
		OrigSoftMenu_ItemClicked2(lpThis_B, TA_CLR_XX_RGB_X, nB);
	}

	if (CHK_FLAGS(nChange, PFLG_I_GM))
	{
		nR = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_GM_R));
		nG = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_GM_G));
		nB = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_GM_B));

		OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_GM);


		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 0);
		OrigSoftMenu_ItemClicked2(lpThis_R, TA_CLR_XX_RGB_X, nR);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 1);
		OrigSoftMenu_ItemClicked2(lpThis_G, TA_CLR_XX_RGB_X, nG);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 2);
		OrigSoftMenu_ItemClicked2(lpThis_B, TA_CLR_XX_RGB_X, nB);
	}

	if (CHK_FLAGS(nChange, PFLG_I_GS))
	{
		nR = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_GS_R));
		nG = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_GS_G));
		nB = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_GS_B));

		OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_GS);


		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 0);
		OrigSoftMenu_ItemClicked2(lpThis_R, TA_CLR_XX_RGB_X, nR);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 1);
		OrigSoftMenu_ItemClicked2(lpThis_G, TA_CLR_XX_RGB_X, nG);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 2);
		OrigSoftMenu_ItemClicked2(lpThis_B, TA_CLR_XX_RGB_X, nB);
	}

	if (CHK_FLAGS(nChange, PFLG_I_LF))
	{
		nR = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_LF_R));
		nG = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_LF_G));
		nB = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_LF_B));

		OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_LF);


		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 0);
		OrigSoftMenu_ItemClicked2(lpThis_R, TA_CLR_XX_RGB_X, nR);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 1);
		OrigSoftMenu_ItemClicked2(lpThis_G, TA_CLR_XX_RGB_X, nG);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 2);
		OrigSoftMenu_ItemClicked2(lpThis_B, TA_CLR_XX_RGB_X, nB);
	}

	if (CHK_FLAGS(nChange, PFLG_I_LL))
	{
		nR = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_LL_R));
		nG = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_LL_G));
		nB = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_LL_B));

		OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_LL);


		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 0);
		OrigSoftMenu_ItemClicked2(lpThis_R, TA_CLR_XX_RGB_X, nR);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 1);
		OrigSoftMenu_ItemClicked2(lpThis_G, TA_CLR_XX_RGB_X, nG);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 2);
		OrigSoftMenu_ItemClicked2(lpThis_B, TA_CLR_XX_RGB_X, nB);
	}

	if (CHK_FLAGS(nChange, PFLG_I_BG))
	{
		nR = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_BG_R));
		nG = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_BG_G));
		nB = ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_CLR_CB_BG_B));

		OrigSoftMenu_ItemClicked2(lpThis_Mode[nMode], TA_CLR_XX, PRIV_I_BG);


		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 0);
		OrigSoftMenu_ItemClicked2(lpThis_R, TA_CLR_XX_RGB_X, nR);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 1);
		OrigSoftMenu_ItemClicked2(lpThis_G, TA_CLR_XX_RGB_X, nG);

		OrigSoftMenu_ItemClicked2(CA_CLR_XX_RGB, TA_CLR_XX_RGB, 2);
		OrigSoftMenu_ItemClicked2(lpThis_B, TA_CLR_XX_RGB_X, nB);
	}
}

INT_PTR CALLBACK fndpColor(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:

		nMode = 0;
		nChange = 0;
		Button_SetCheck(GetDlgItem(hDlg, IDC_CLR_CMD_NORMAL), BST_CHECKED);

		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_MODE),
			GetStringByIndex(L"Mode:\0模式:\0模式:\0\0", nLangId));

		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_CMD_NORMAL),
			GetStringByIndex(L"Normal\0正常\0正常\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_CMD_INVERT),
			GetStringByIndex(L"Invert\0反转\0反轉\0\0", nLangId));

		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_CMD_DEFCLR),
			GetStringByIndex(L"Reset Color\0默认颜色\0默認顏色\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDOK),
			GetStringByIndex(L"Done\0完成\0完成\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDCANCEL),
			GetStringByIndex(L"Cancel\0取消\0取消\0\0", nLangId));

		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_GB_DT1),
			GetStringByIndex(L"Data Trace 1\0数据曲线1\0數據曲線1\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_GB_DT2),
			GetStringByIndex(L"Data Trace 2\0数据曲线2\0數據曲線2\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_GB_DT3),
			GetStringByIndex(L"Data Trace 3\0数据曲线3\0數據曲線3\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_GB_DT4),
			GetStringByIndex(L"Data Trace 4\0数据曲线4\0數據曲線4\0\0", nLangId));

		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_GB_MT1),
			GetStringByIndex(L"Mem Trace 1\0存储曲线1\0存儲曲線1\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_GB_MT2),
			GetStringByIndex(L"Mem Trace 2\0存储曲线2\0存儲曲線2\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_GB_MT3),
			GetStringByIndex(L"Mem Trace 3\0存储曲线3\0存儲曲線3\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_GB_MT4),
			GetStringByIndex(L"Mem Trace 4\0存储曲线4\0存儲曲線4\0\0", nLangId));

		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_GB_GM),
			GetStringByIndex(L"Graticule Main\0主网格\0主網格\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_GB_GS),
			GetStringByIndex(L"Graticule Sub\0子网格\0子網格\0\0", nLangId));

		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_GB_LF),
			GetStringByIndex(L"Limit Fail\0极限测试失败\0極限測試失敗\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_GB_LL),
			GetStringByIndex(L"Limit Line\0极限线标\0極限線標\0\0", nLangId));

		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_GB_BG),
			GetStringByIndex(L"Background\0背景\0背景\0\0", nLangId));

		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_R),
			GetStringByIndex(L"Red\0红\0紅\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_R2),
			GetStringByIndex(L"Red\0红\0紅\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_R3),
			GetStringByIndex(L"Red\0红\0紅\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_R4),
			GetStringByIndex(L"Red\0红\0紅\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_R5),
			GetStringByIndex(L"Red\0红\0紅\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_R6),
			GetStringByIndex(L"Red\0红\0紅\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_R7),
			GetStringByIndex(L"Red\0红\0紅\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_R8),
			GetStringByIndex(L"Red\0红\0紅\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_R9),
			GetStringByIndex(L"Red\0红\0紅\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_R10),
			GetStringByIndex(L"Red\0红\0紅\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_R11),
			GetStringByIndex(L"Red\0红\0紅\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_R12),
			GetStringByIndex(L"Red\0红\0紅\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_R13),
			GetStringByIndex(L"Red\0红\0紅\0\0", nLangId));

		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_G),
			GetStringByIndex(L"Green\0绿\0綠\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_G2),
			GetStringByIndex(L"Green\0绿\0綠\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_G3),
			GetStringByIndex(L"Green\0绿\0綠\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_G4),
			GetStringByIndex(L"Green\0绿\0綠\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_G5),
			GetStringByIndex(L"Green\0绿\0綠\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_G6),
			GetStringByIndex(L"Green\0绿\0綠\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_G7),
			GetStringByIndex(L"Green\0绿\0綠\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_G8),
			GetStringByIndex(L"Green\0绿\0綠\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_G9),
			GetStringByIndex(L"Green\0绿\0綠\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_G10),
			GetStringByIndex(L"Green\0绿\0綠\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_G11),
			GetStringByIndex(L"Green\0绿\0綠\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_G12),
			GetStringByIndex(L"Green\0绿\0綠\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_G13),
			GetStringByIndex(L"Green\0绿\0綠\0\0", nLangId));

		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_B),
			GetStringByIndex(L"Blue\0蓝\0藍\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_B2),
			GetStringByIndex(L"Blue\0蓝\0藍\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_B3),
			GetStringByIndex(L"Blue\0蓝\0藍\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_B4),
			GetStringByIndex(L"Blue\0蓝\0藍\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_B5),
			GetStringByIndex(L"Blue\0蓝\0藍\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_B6),
			GetStringByIndex(L"Blue\0蓝\0藍\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_B7),
			GetStringByIndex(L"Blue\0蓝\0藍\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_B8),
			GetStringByIndex(L"Blue\0蓝\0藍\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_B9),
			GetStringByIndex(L"Blue\0蓝\0藍\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_B10),
			GetStringByIndex(L"Blue\0蓝\0藍\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_B11),
			GetStringByIndex(L"Blue\0蓝\0藍\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_B12),
			GetStringByIndex(L"Blue\0蓝\0藍\0\0", nLangId));
		SetWindowTextW(GetDlgItem(hDlg, IDC_CLR_LBL_B13),
			GetStringByIndex(L"Blue\0蓝\0藍\0\0", nLangId));


		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_R), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_R), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_R), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_R), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_R), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_R), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_G), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_G), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_G), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_G), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_G), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_G), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_B), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_B), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_B), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_B), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_B), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT1_B), 5, L"5");


		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_R), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_R), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_R), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_R), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_R), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_R), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_G), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_G), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_G), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_G), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_G), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_G), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_B), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_B), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_B), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_B), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_B), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT2_B), 5, L"5");


		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_R), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_R), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_R), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_R), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_R), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_R), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_G), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_G), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_G), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_G), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_G), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_G), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_B), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_B), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_B), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_B), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_B), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT3_B), 5, L"5");


		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_R), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_R), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_R), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_R), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_R), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_R), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_G), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_G), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_G), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_G), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_G), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_G), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_B), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_B), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_B), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_B), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_B), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_DT4_B), 5, L"5");


		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_R), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_R), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_R), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_R), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_R), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_R), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_G), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_G), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_G), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_G), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_G), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_G), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_B), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_B), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_B), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_B), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_B), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT1_B), 5, L"5");


		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_R), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_R), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_R), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_R), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_R), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_R), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_G), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_G), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_G), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_G), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_G), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_G), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_B), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_B), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_B), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_B), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_B), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT2_B), 5, L"5");


		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_R), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_R), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_R), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_R), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_R), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_R), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_G), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_G), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_G), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_G), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_G), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_G), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_B), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_B), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_B), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_B), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_B), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT3_B), 5, L"5");


		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_R), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_R), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_R), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_R), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_R), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_R), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_G), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_G), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_G), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_G), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_G), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_G), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_B), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_B), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_B), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_B), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_B), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_MT4_B), 5, L"5");


		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_R), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_R), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_R), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_R), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_R), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_R), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_G), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_G), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_G), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_G), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_G), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_G), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_B), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_B), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_B), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_B), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_B), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GM_B), 5, L"5");


		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_R), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_R), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_R), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_R), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_R), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_R), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_G), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_G), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_G), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_G), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_G), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_G), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_B), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_B), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_B), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_B), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_B), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_GS_B), 5, L"5");


		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_R), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_R), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_R), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_R), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_R), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_R), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_G), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_G), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_G), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_G), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_G), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_G), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_B), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_B), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_B), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_B), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_B), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LF_B), 5, L"5");


		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_R), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_R), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_R), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_R), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_R), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_R), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_G), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_G), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_G), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_G), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_G), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_G), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_B), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_B), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_B), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_B), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_B), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_LL_B), 5, L"5");


		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_R), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_R), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_R), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_R), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_R), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_R), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_G), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_G), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_G), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_G), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_G), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_G), 5, L"5");

		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_B), 0, L"0");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_B), 1, L"1");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_B), 2, L"2");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_B), 3, L"3");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_B), 4, L"4");
		ComboBox_InsertStringW(GetDlgItem(hDlg, IDC_CLR_CB_BG_B), 5, L"5");





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
				case IDC_CLR_CMD_NORMAL:
					if (nChange)
					{
						SaveColorValue(hDlg);
						nChange = 0;
					}

					nMode = 0;
					UpdateColorValue(hDlg);
					break;

				case IDC_CLR_CMD_INVERT:
					if (nChange)
					{
						SaveColorValue(hDlg);
						nChange = 0;
					}

					nMode = 1;
					UpdateColorValue(hDlg);
					break;

				case IDC_CLR_CMD_DEFCLR:
				{
					OrigSoftMenu_ItemClicked2(CA_CLR, TA_CLR, nMode);

					if (lpThis_Mode_RC[nMode] == NULL)
					{
						if (lpThis_Mode[nMode] == NULL)
						{
							lpThis_Mode[nMode] = GetSubMenuPointer(CA_CLR, nMode);

							OrigSoftMenu_UpdateItems(lpThis_Mode[nMode]);
						}

						if (lpThis_Mode[nMode] == NULL)break;

						lpThis_Mode_RC[nMode] = GetSubMenuPointer(lpThis_Mode[nMode], 13);
						if (lpThis_Mode_RC[nMode] == NULL)break;
					}

					OrigSoftMenu_ItemClicked2(lpThis_Mode_RC[nMode], TA_CLR_XX_RC, 0);
					UpdateColorValue(hDlg);
				}
				break;

				case IDOK:
					if (nChange)
					{
						SaveColorValue(hDlg);
						nChange = 0;
					}
					DestroyDialog_Def(0);
					break;

				case IDCANCEL:
					DestroyDialog_Def(0);
					break;
				}
				break;
			}
			else if (wNc == CBN_SELCHANGE)
			{
				switch (wId)
				{
				case IDC_CLR_CB_DT1_R:
				case IDC_CLR_CB_DT1_G:
				case IDC_CLR_CB_DT1_B:
					SET_FLAGS(nChange, PFLG_I_DT1);
					break;

				case IDC_CLR_CB_DT2_R:
				case IDC_CLR_CB_DT2_G:
				case IDC_CLR_CB_DT2_B:
					SET_FLAGS(nChange, PFLG_I_DT2);
					break;

				case IDC_CLR_CB_DT3_R:
				case IDC_CLR_CB_DT3_G:
				case IDC_CLR_CB_DT3_B:
					SET_FLAGS(nChange, PFLG_I_DT3);
					break;

				case IDC_CLR_CB_DT4_R:
				case IDC_CLR_CB_DT4_G:
				case IDC_CLR_CB_DT4_B:
					SET_FLAGS(nChange, PFLG_I_DT4);
					break;

				case IDC_CLR_CB_MT1_R:
				case IDC_CLR_CB_MT1_G:
				case IDC_CLR_CB_MT1_B:
					SET_FLAGS(nChange, PFLG_I_MT1);
					break;

				case IDC_CLR_CB_MT2_R:
				case IDC_CLR_CB_MT2_G:
				case IDC_CLR_CB_MT2_B:
					SET_FLAGS(nChange, PFLG_I_MT2);
					break;

				case IDC_CLR_CB_MT3_R:
				case IDC_CLR_CB_MT3_G:
				case IDC_CLR_CB_MT3_B:
					SET_FLAGS(nChange, PFLG_I_MT3);
					break;

				case IDC_CLR_CB_MT4_R:
				case IDC_CLR_CB_MT4_G:
				case IDC_CLR_CB_MT4_B:
					SET_FLAGS(nChange, PFLG_I_MT4);
					break;

				case IDC_CLR_CB_GM_R:
				case IDC_CLR_CB_GM_G:
				case IDC_CLR_CB_GM_B:
					SET_FLAGS(nChange, PFLG_I_GM);
					break;

				case IDC_CLR_CB_GS_R:
				case IDC_CLR_CB_GS_G:
				case IDC_CLR_CB_GS_B:
					SET_FLAGS(nChange, PFLG_I_GS);
					break;

				case IDC_CLR_CB_LF_R:
				case IDC_CLR_CB_LF_G:
				case IDC_CLR_CB_LF_B:
					SET_FLAGS(nChange, PFLG_I_LF);
					break;

				case IDC_CLR_CB_LL_R:
				case IDC_CLR_CB_LL_G:
				case IDC_CLR_CB_LL_B:
					SET_FLAGS(nChange, PFLG_I_LL);
					break;

				case IDC_CLR_CB_BG_R:
				case IDC_CLR_CB_BG_G:
				case IDC_CLR_CB_BG_B:
					SET_FLAGS(nChange, PFLG_I_BG);
					break;
				}
				break;
			}
		}
	}
	break;

	case WM_CLOSE:
		DestroyDialog_Def(0);
		break;
	}

	return FALSE;
}


DLG_CTXT dcColorWizard
{
	NULL,
	IDD_COLOR,
	0,
	&fndeColor,
	&fndpColor,
	RESERVE_DWORD4
};