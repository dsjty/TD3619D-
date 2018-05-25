#include "stdafx.h"

extern CALDLG_CTXT dcCal_1;

static void UpdateButtonState(HWND hClient);

/*
static void TestSelected_21(HWND hClient)
{
if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL13_P21_O)) == BST_UNCHECKED)
{
EnableWindow(GetDlgItem(hClient, IDC_CAL13_P21_OK), FALSE);
return;
}

if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL13_P21_S)) == BST_UNCHECKED)
{
EnableWindow(GetDlgItem(hClient, IDC_CAL13_P21_OK), FALSE);
return;
}

if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL13_P21_L)) == BST_UNCHECKED)
{
EnableWindow(GetDlgItem(hClient, IDC_CAL13_P21_OK), FALSE);
return;
}

if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL13_P21_T)) == BST_UNCHECKED)
{
EnableWindow(GetDlgItem(hClient, IDC_CAL13_P21_OK), FALSE);
return;
}

EnableWindow(GetDlgItem(hClient, IDC_CAL13_P21_OK), TRUE);
}

static void TestSelected_12(HWND hClient)
{
if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL13_P12_O)) == BST_UNCHECKED)
{
EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_OK), FALSE);
return;
}

if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL13_P12_S)) == BST_UNCHECKED)
{
EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_OK), FALSE);
return;
}

if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL13_P12_L)) == BST_UNCHECKED)
{
EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_OK), FALSE);
return;
}

if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL13_P12_T)) == BST_UNCHECKED)
{
EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_OK), FALSE);
return;
}

EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_OK), TRUE);
}

static void UnSelected(HWND hClient)
{
EnableWindow(GetDlgItem(hClient, IDC_CAL13_P21_OK), FALSE);
EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_OK), FALSE);


Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_O), BST_UNCHECKED);
Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_S), BST_UNCHECKED);
Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_L), BST_UNCHECKED);
Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_T), BST_UNCHECKED);
Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_I), BST_UNCHECKED);
Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P12_O), BST_UNCHECKED);
Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P12_S), BST_UNCHECKED);
Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P12_L), BST_UNCHECKED);
Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P12_T), BST_UNCHECKED);
Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P12_I), BST_UNCHECKED);
}
*/

INT_PTR WINAPI fndeCal_1_3(PCALDLG_CTXT lpDlgCtxt, DWORD dwCode, WPARAM wParam, LPARAM lParam, LPARAM lParam2)
{
	if (lpDlgCtxt == NULL) return -1;

	INT_PTR lResult = 0;

	switch (dwCode)
	{
	case DEC_ENTER:

		OrigSoftMenu_Enter(CA_CALCAL);
		OrigSoftMenu_UpdateItems(CA_CALCAL);

		OrigSoftMenu_Enter(CA_CC_ER);
		OrigSoftMenu_UpdateItems(CA_CC_ER);


		EnableWindow(GetDlgItem((HWND)lParam2, IDC_CAL13_P21_OK), FALSE);
		EnableWindow(GetDlgItem((HWND)lParam2, IDC_CAL13_P12_OK), FALSE);


		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL13_GB_P21),
			GetStringByIndex(L"Port 2-1 (S21 S11)\0端口2-1 (S21 S11)\0端口2-1 (S21 S11)\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL13_GB_P12),
			GetStringByIndex(L"Port 1-2 (S12 S22)\0端口1-2 (S12 S22)\0端口1-2 (S12 S22)\0\0", nLangId));



		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL13_P21_O),
			GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL13_P21_S),
			GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL13_P21_L),
			GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL13_P21_T),
			GetStringByIndex(L"Thru\0短接\0短接\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL13_P21_I),
			GetStringByIndex(L"Isolation (Optional)\0隔离 (可选)\0隔離 (可選)\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL13_P12_O),
			GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL13_P12_S),
			GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL13_P12_L),
			GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL13_P12_T),
			GetStringByIndex(L"Thru\0短接\0短接\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL13_P12_I),
			GetStringByIndex(L"Isolation (Optional)\0隔离 (可选)\0隔離 (可選)\0\0", nLangId));


		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL13_P21_OK),
			GetStringByIndex(L"Done\0完成\0完成\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL13_P12_OK),
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

	GetButtonStateIndex((const char *)0x00B78CA0, NULL, &nIndex, 0x00010000);

	switch (nPort)
	{
	case 21:
		if (nIndex != 0)
		{
			OrigSoftMenu_ItemClicked2(CA_CC_ER, TA_CC_ER, 0);
		}
		break;
	case 12:
		if (nIndex != 1)
		{
			OrigSoftMenu_ItemClicked2(CA_CC_ER, TA_CC_ER, 0);
		}
		break;
	}
}

static void UpdateButtonState(HWND hClient)
{
	BOOL blTmp = FALSE;

	OrigSoftMenu_UpdateItems(CA_CC_ER);
	OrigSoftMenu_GetItemState(CA_CC_ER, 0, &blTmp, NULL, NULL);

	if (blTmp)
	{
		EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_O), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_S), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_L), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_T), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_I), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_OK), TRUE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL13_GB_P12), TRUE);

		ChangeCurPortNumber(21);

		OrigSoftMenu_GetItemState(CA_CC_ER, 1, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_O), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_O), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_ER, 2, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_S), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_S), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_ER, 3, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_L), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_L), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_ER, 4, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_T), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_T), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_ER, 5, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_I), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_I), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_ER, 6, &blTmp, NULL, NULL);

		EnableWindow(GetDlgItem(hClient, IDC_CAL13_P21_OK), blTmp);

		ChangeCurPortNumber(12);

		OrigSoftMenu_GetItemState(CA_CC_ER, 1, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P12_O), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P12_O), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_ER, 2, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P12_S), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P12_S), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_ER, 3, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P12_L), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P12_L), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_ER, 4, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P12_T), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P12_T), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_ER, 5, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P12_I), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P12_I), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_ER, 6, &blTmp, NULL, NULL);

		EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_OK), blTmp);
	}
	else
	{
		EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_O), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_S), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_L), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_T), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_I), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL13_P12_OK), FALSE);
		EnableWindow(GetDlgItem(hClient, IDC_CAL13_GB_P12), FALSE);

		OrigSoftMenu_GetItemState(CA_CC_ER, 1, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_O), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_O), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_ER, 2, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_S), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_S), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_ER, 3, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_L), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_L), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_ER, 4, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_T), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_T), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_ER, 5, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_I), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL13_P21_I), BST_UNCHECKED);

		OrigSoftMenu_GetItemState(CA_CC_ER, 6, &blTmp, NULL, NULL);

		EnableWindow(GetDlgItem(hClient, IDC_CAL13_P21_OK), blTmp);
	}
}


INT_PTR CALLBACK fndpCal_1_3(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
		return TRUE;
		/*
	case WM_PAINT:
	{
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
	}
	return 0;*/

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
				case IDC_CAL13_P21_O:

					ChangeCurPortNumber(21);
					OrigSoftMenu_ItemClicked2(CA_CC_ER, TA_CC_ER, 1);
					//TestSelected_21(hDlg);
					break;

				case IDC_CAL13_P21_S:

					ChangeCurPortNumber(21);
					OrigSoftMenu_ItemClicked2(CA_CC_ER, TA_CC_ER, 2);
					//TestSelected_21(hDlg);
					break;

				case IDC_CAL13_P21_L:

					ChangeCurPortNumber(21);
					OrigSoftMenu_ItemClicked2(CA_CC_ER, TA_CC_ER, 3);
					//TestSelected_21(hDlg);
					break;

				case IDC_CAL13_P21_T:

					ChangeCurPortNumber(21);
					OrigSoftMenu_ItemClicked2(CA_CC_ER, TA_CC_ER, 4);
					//TestSelected_21(hDlg);
					break;

				case IDC_CAL13_P21_I:

					ChangeCurPortNumber(21);
					OrigSoftMenu_ItemClicked2(CA_CC_ER, TA_CC_ER, 5);
					break;

				case IDC_CAL13_P12_O:

					ChangeCurPortNumber(12);
					OrigSoftMenu_ItemClicked2(CA_CC_ER, TA_CC_ER, 1);
					//TestSelected_12(hDlg);
					break;

				case IDC_CAL13_P12_S:

					ChangeCurPortNumber(12);
					OrigSoftMenu_ItemClicked2(CA_CC_ER, TA_CC_ER, 2);
					//TestSelected_12(hDlg);
					break;

				case IDC_CAL13_P12_L:

					ChangeCurPortNumber(12);
					OrigSoftMenu_ItemClicked2(CA_CC_ER, TA_CC_ER, 3);
					//TestSelected_12(hDlg);
					break;

				case IDC_CAL13_P12_T:

					ChangeCurPortNumber(12);
					OrigSoftMenu_ItemClicked2(CA_CC_ER, TA_CC_ER, 4);
					//TestSelected_12(hDlg);
					break;

				case IDC_CAL13_P12_I:

					ChangeCurPortNumber(12);
					OrigSoftMenu_ItemClicked2(CA_CC_ER, TA_CC_ER, 5);
					break;

				case IDC_CAL13_P21_OK:

					ChangeCurPortNumber(21);
					OrigSoftMenu_ItemClicked2(CA_CC_ER, TA_CC_ER, 6);
					//DestroyDialog_Cal(0);
					break;

				case IDC_CAL13_P12_OK:

					ChangeCurPortNumber(12);
					OrigSoftMenu_ItemClicked2(CA_CC_ER, TA_CC_ER, 6);
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


CALDLG_CTXT dcCal_1_3 =
{
	NULL,
	IDD_CAL_1_3,
	DFL_CMD_PREV | DFL_LBL_INFO1,
	&fndeCal_1_3,
	&fndpCal_1_3,
	NULL,
	NULL,
	NULL,
	L"Manual Calibration\0手动校准\0手動校準\0\0",
	L"Enhanced Response\0增强型响应\0增強型響應\0\0",
	L"\0\0",
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	RESERVE_DWORD4,
	RESERVE_DWORD4
};