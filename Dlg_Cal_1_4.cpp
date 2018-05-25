#include "stdafx.h"

extern CALDLG_CTXT dcCal_1;

static void UpdateButtonState(HWND hClient);

/*
static void TestSelected_1(HWND hClient)
{
if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL14_P1_O)) == BST_UNCHECKED)
{
EnableWindow(GetDlgItem(hClient, IDC_CAL14_P1_OK), FALSE);
return;
}

if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL14_P1_S)) == BST_UNCHECKED)
{
EnableWindow(GetDlgItem(hClient, IDC_CAL14_P1_OK), FALSE);
return;
}

if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL14_P1_L)) == BST_UNCHECKED)
{
EnableWindow(GetDlgItem(hClient, IDC_CAL14_P1_OK), FALSE);
return;
}

EnableWindow(GetDlgItem(hClient, IDC_CAL14_P1_OK), TRUE);
}


static void TestSelected_2(HWND hClient)
{
if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL14_P2_O)) == BST_UNCHECKED)
{
EnableWindow(GetDlgItem(hClient, IDC_CAL14_P2_OK), FALSE);
return;
}

if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL14_P2_S)) == BST_UNCHECKED)
{
EnableWindow(GetDlgItem(hClient, IDC_CAL14_P2_OK), FALSE);
return;
}

if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL14_P2_L)) == BST_UNCHECKED)
{
EnableWindow(GetDlgItem(hClient, IDC_CAL14_P2_OK), FALSE);
return;
}

EnableWindow(GetDlgItem(hClient, IDC_CAL14_P2_OK), TRUE);
}


static void UnSelected(HWND hClient)
{
EnableWindow(GetDlgItem(hClient, IDC_CAL14_P1_OK), FALSE);
EnableWindow(GetDlgItem(hClient, IDC_CAL14_P2_OK), FALSE);

Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P1_O), BST_UNCHECKED);
Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P1_S), BST_UNCHECKED);
Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P1_L), BST_UNCHECKED);
Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P2_O), BST_UNCHECKED);
Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P2_S), BST_UNCHECKED);
Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P2_L), BST_UNCHECKED);
}
*/

INT_PTR WINAPI fndeCal_1_4(PCALDLG_CTXT lpDlgCtxt, DWORD dwCode, WPARAM wParam, LPARAM lParam, LPARAM lParam2)
{
	if (lpDlgCtxt == NULL) return -1;

	INT_PTR lResult = 0;

	switch (dwCode)
	{
	case DEC_ENTER:

		OrigSoftMenu_Enter(CA_CALCAL);
		OrigSoftMenu_UpdateItems(CA_CALCAL);

		OrigSoftMenu_Enter(CA_CC_1PC);
		OrigSoftMenu_UpdateItems(CA_CC_1PC);


		EnableWindow(GetDlgItem((HWND)lParam2, IDC_CAL14_P1_OK), FALSE);
		EnableWindow(GetDlgItem((HWND)lParam2, IDC_CAL14_P2_OK), FALSE);


		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL14_GB_P1),
			GetStringByIndex(L"Port 1\0端口1\0端1\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL14_GB_P2),
			GetStringByIndex(L"Port 2\0端口2 \0端口2\0\0", nLangId));


		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL14_P1_O),
			GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL14_P1_S),
			GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL14_P1_L),
			GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL14_P2_O),
			GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL14_P2_S),
			GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL14_P2_L),
			GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));


		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL14_P1_OK),
			GetStringByIndex(L"Done\0完成\0完成\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL14_P2_OK),
			GetStringByIndex(L"Done\0完成\0完成\0\0", nLangId));

		UpdateButtonState((HWND)lParam2);
		SetTimer((HWND)lParam2, 1, 50, NULL);
		break;

	case DEC_CMD_PREV:
		KillTimer(lpDlgCtxt->hwClient, 1);
		UpdateDialog_Cal(&dcCal_1, 0);
		break;

	case DEC_CMD_CANCEL:
	{
		LPCWSTR lpText = GetStringByIndex(L"Whether to cancel the calibration data?\0是否取消校准数据?\0是否取消校準數據?\0\0", nLangId);
		LPCWSTR lpTitle = GetStringByIndex(L"Confirm the cancellation\0确认取消操作\0確認取消操作\0\0", nLangId);

		if (DialogMsgBox_Cal(lpText, lpTitle, MB_YESNO) == IDYES)
		{
			OrigSoftMenu_Enter(CA_CC_XX_C);
			OrigSoftMenu_UpdateItems(CA_CC_XX_C);

			OrigSoftMenu_ItemClicked2(CA_CC_XX_C, TA_CC_XX_C, 0);

			//UnSelected(lpDlgCtxt->hwClient);
			UpdateButtonState(lpDlgCtxt->hwClient);
		}
	}

	break;

	case DEC_CMD_CLOSE:
		KillTimer(lpDlgCtxt->hwClient, 1);
		lResult = TRUE;
		break;
	}

	return lResult;
}

static void ChangeCurPortNumber(int nPort)
{
	int nIndex = 0;

	GetButtonStateIndex((const char *)0x00B78C0C, NULL, &nIndex, 0x00);

	switch (nPort)
	{
	case 1:
		if (nIndex != 0)
		{
			OrigSoftMenu_ItemClicked2(CA_CC_1PC, TA_CC_1PC, 0);
		}
		break;
	case 2:
		if (nIndex != 1)
		{
			OrigSoftMenu_ItemClicked2(CA_CC_1PC, TA_CC_1PC, 0);
		}
		break;
	}
}

static void UpdateButtonState(HWND hClient)
{
	BOOL blTmp = FALSE;

	OrigSoftMenu_UpdateItems(CA_CC_1PC);
	OrigSoftMenu_GetItemState(CA_CC_1PC, 0, &blTmp, NULL, NULL);

	if (blTmp)
	{
		EnableWindow(GetDlgItem(hClient, IDC_CAL14_P2_O), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL14_P2_S), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL14_P2_L), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL14_P2_OK), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL14_GB_P2), TRUE);

		ChangeCurPortNumber(1);

		OrigSoftMenu_GetItemState(CA_CC_1PC, 1, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P1_O), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P1_O), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_1PC, 2, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P1_S), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P1_S), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_1PC, 3, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P1_L), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P1_L), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_1PC, 4, &blTmp, NULL, NULL);

		EnableWindow(GetDlgItem(hClient, IDC_CAL14_P1_OK), blTmp);

		ChangeCurPortNumber(2);

		OrigSoftMenu_GetItemState(CA_CC_1PC, 1, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P2_O), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P2_O), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_1PC, 2, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P2_S), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P2_S), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_1PC, 3, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P2_L), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P2_L), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_1PC, 4, &blTmp, NULL, NULL);

		EnableWindow(GetDlgItem(hClient, IDC_CAL14_P2_OK), blTmp);
	}
	else
	{
		EnableWindow(GetDlgItem(hClient, IDC_CAL14_P2_O), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL14_P2_S), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL14_P2_L), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL14_P2_OK), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL14_GB_P2), FALSE);

		OrigSoftMenu_GetItemState(CA_CC_1PC, 1, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P1_O), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P1_O), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_1PC, 2, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P1_S), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P1_S), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_1PC, 3, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P1_L), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL14_P1_L), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_1PC, 4, &blTmp, NULL, NULL);

		EnableWindow(GetDlgItem(hClient, IDC_CAL14_P1_OK), blTmp);
	}
}

INT_PTR CALLBACK fndpCal_1_4(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_PAINT:
	{/*
		PAINTSTRUCT ps;
		HDC hDC = BeginPaint(hDlg, &ps), hCDC;
		BOOL blCDC = TRUE;
		HBITMAP hBM;
		RECT rect;
		int cx, cy;

		if (hDC == NULL)
			break;

		GetClientRect(hDlg, &rect);
		cx = rect.right - rect.left;
		cy = rect.bottom - rect.top;

		//尝试使用双缓冲
		hCDC = CreateCompatibleDC(hDC);

		//判断双缓冲
		if (hCDC == NULL)
		{
			hCDC = hDC;
			blCDC = FALSE;
		}
		else if (hBM = CreateCompatibleBitmap(hDC, cx, cy))
		{
			SelectObject(hCDC, hBM);
			DeleteObject(hBM);
		}
		else
		{
			DeleteDC(hCDC);
			hCDC = hDC;
			blCDC = FALSE;
		}
		SelectObject(hCDC, hCalDlg_bk);
		Rectangle(hCDC, rect.left, rect.top, rect.right, rect.bottom);

		if (blCDC)
		{
			BitBlt(hDC, rect.left, rect.top, cx, cy, hCDC, rect.left, rect.top, SRCCOPY);
			DeleteDC(hCDC);
		}

		EndPaint(hDlg, &ps);
		*/
	}
	return 0;
	case WM_TIMER:
		if (wParam == 1)
		{
			UpdateButtonState(hDlg);
			return 0;
		}
		break;

	case WM_COMMAND:
	{
		WORD wId = LOWORD(wParam), wNc = HIWORD(wParam);

		if (lParam)
		{
			if (wNc == BN_CLICKED)
			{
				switch (wId)
				{
				case IDC_CAL14_P1_O:

					ChangeCurPortNumber(1);
					OrigSoftMenu_ItemClicked2(CA_CC_1PC, TA_CC_1PC, 1);
					//TestSelected_1(hDlg);
					break;

				case IDC_CAL14_P1_S:

					ChangeCurPortNumber(1);
					OrigSoftMenu_ItemClicked2(CA_CC_1PC, TA_CC_1PC, 2);
					//TestSelected_1(hDlg);
					break;

				case IDC_CAL14_P1_L:

					ChangeCurPortNumber(1);
					OrigSoftMenu_ItemClicked2(CA_CC_1PC, TA_CC_1PC, 3);
					//TestSelected_1(hDlg);
					break;

				case IDC_CAL14_P2_O:

					ChangeCurPortNumber(2);
					OrigSoftMenu_ItemClicked2(CA_CC_1PC, TA_CC_1PC, 1);
					//TestSelected_2(hDlg);
					break;

				case IDC_CAL14_P2_S:

					ChangeCurPortNumber(2);
					OrigSoftMenu_ItemClicked2(CA_CC_1PC, TA_CC_1PC, 2);
					//TestSelected_2(hDlg);
					break;

				case IDC_CAL14_P2_L:

					ChangeCurPortNumber(2);
					OrigSoftMenu_ItemClicked2(CA_CC_1PC, TA_CC_1PC, 3);
					//TestSelected_2(hDlg);
					break;

				case IDC_CAL14_P1_OK:

					ChangeCurPortNumber(1);
					OrigSoftMenu_ItemClicked2(CA_CC_1PC, TA_CC_1PC, 4);
					//DestroyDialog_Cal(0);
					break;

				case IDC_CAL14_P2_OK:

					ChangeCurPortNumber(2);
					OrigSoftMenu_ItemClicked2(CA_CC_1PC, TA_CC_1PC, 4);
					//DestroyDialog_Cal(0);
					break;
				}

				UpdateButtonState(hDlg);
			}
		}
	}
	break;
	}

	return FALSE;
}


CALDLG_CTXT dcCal_1_4 =
{
	NULL,
	IDD_CAL_1_4,
	DFL_CMD_PREV | DFL_LBL_INFO1,
	&fndeCal_1_4,
	&fndpCal_1_4,
	NULL,
	NULL,
	NULL,
	L"Manual Calibration\0手动校准\0手動校準\0\0",
	L"1 Port Cal\0\x31端口校准\0\x31端口校準\0\0",
	L"\0\0",
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	RESERVE_DWORD4,
	RESERVE_DWORD4
};