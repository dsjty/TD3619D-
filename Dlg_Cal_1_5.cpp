#include "stdafx.h"

void *lpThis_2PortCal = NULL;
void *lpThis_2PC_R = NULL;
void *lpThis_2PC_T = NULL;
void *lpThis_2PC_I = NULL;
BYTE btLastState = 0;

extern CALDLG_CTXT dcCal_1;

static void UpdateButtonState(HWND hClient);

/*
void TestSelected(HWND hClient)
{
if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P1_O)) == BST_UNCHECKED)
{
EnableButton_Cal(DEC_CMD_OK, FALSE);
return;
}

if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P2_O)) == BST_UNCHECKED)
{
EnableButton_Cal(DEC_CMD_OK, FALSE);
return;
}

if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P1_S)) == BST_UNCHECKED)
{
EnableButton_Cal(DEC_CMD_OK, FALSE);
return;
}

if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P2_S)) == BST_UNCHECKED)
{
EnableButton_Cal(DEC_CMD_OK, FALSE);
return;
}

if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P1_L)) == BST_UNCHECKED)
{
EnableButton_Cal(DEC_CMD_OK, FALSE);
return;
}

if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P2_L)) == BST_UNCHECKED)
{
EnableButton_Cal(DEC_CMD_OK, FALSE);
return;
}

if (Button_GetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P12_T)) == BST_UNCHECKED)
{
EnableButton_Cal(DEC_CMD_OK, FALSE);
return;
}

EnableButton_Cal(DEC_CMD_OK, TRUE);
return;
}

static void UnSelected(HWND hClient)
{
EnableButton_Cal(DEC_CMD_OK, FALSE);

Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P1_O), BST_UNCHECKED);

Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P2_O), BST_UNCHECKED);

Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P1_S), BST_UNCHECKED);

Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P2_S), BST_UNCHECKED);

Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P1_L), BST_UNCHECKED);

Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P2_L), BST_UNCHECKED);

Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P12_T), BST_UNCHECKED);

Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P12_I), BST_UNCHECKED);
}
*/

INT_PTR WINAPI fndeCal_1_5(PCALDLG_CTXT lpDlgCtxt, DWORD dwCode, WPARAM wParam, LPARAM lParam, LPARAM lParam2)
{
	if (lpDlgCtxt == NULL) return -1;

	INT_PTR lResult = 0;

	switch (dwCode)
	{
	case DEC_ENTER:

		OrigSoftMenu_Enter(CA_CALCAL);
		OrigSoftMenu_UpdateItems(CA_CALCAL);

		lpThis_2PortCal = GetSubMenuPointer(CA_CALCAL, 5);

		if (lpThis_2PortCal)
		{
			OrigSoftMenu_Enter(lpThis_2PortCal);
			OrigSoftMenu_UpdateItems(lpThis_2PortCal);

			lpThis_2PC_R = GetSubMenuPointer(lpThis_2PortCal, 0);
			if (lpThis_2PC_R)
			{
				OrigSoftMenu_Enter(lpThis_2PC_R);
				OrigSoftMenu_UpdateItems(lpThis_2PC_R);
			}

			lpThis_2PC_T = GetSubMenuPointer(lpThis_2PortCal, 1);
			if (lpThis_2PC_T)
			{
				OrigSoftMenu_Enter(lpThis_2PC_T);
				OrigSoftMenu_UpdateItems(lpThis_2PC_T);
			}

			lpThis_2PC_I = GetSubMenuPointer(lpThis_2PortCal, 2);
			if (lpThis_2PC_I)
			{
				OrigSoftMenu_Enter(lpThis_2PC_I);
				OrigSoftMenu_UpdateItems(lpThis_2PC_I);
			}
		}


		EnableButton_Cal(DEC_CMD_OK, FALSE);

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL15_GB_P1),
			GetStringByIndex(L"Port1 Reflection\0端口1反射\0端口1反射\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL15_GB_P2),
			GetStringByIndex(L"Port2 Reflection\0端口2反射\0端口2反射\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL15_GB_P12),
			GetStringByIndex(L"Port 1-2\0端口1-2\0端口1-2\0\0", nLangId));



		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL15_CMD_P1_O),
			GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL15_CMD_P2_O),
			GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL15_CMD_P1_S),
			GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL15_CMD_P2_S),
			GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL15_CMD_P1_L),
			GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL15_CMD_P2_L),
			GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));



		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL15_CMD_P12_T),
			GetStringByIndex(L"Thru\0短接\0短接\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL15_CMD_P12_I),
			GetStringByIndex(L"Isolation (Optional)\0隔离 (可选)\0隔離 (可選)\0\0", nLangId));

		UpdateButtonState((HWND)lParam2);
		SetTimer((HWND)lParam2, 1, 50, NULL);
		break;

	case DEC_CMD_PREV:
		KillTimer(lpDlgCtxt->hwClient, 1);
		UpdateDialog_Cal(&dcCal_1, 0);
		break;

	case DEC_CMD_OK:
	{
		if (lpThis_2PortCal == NULL)
		{
			lpThis_2PortCal = GetSubMenuPointer(CA_CALCAL, 5);

			if (lpThis_2PortCal)
			{
				OrigSoftMenu_Enter(lpThis_2PortCal);
				OrigSoftMenu_UpdateItems(lpThis_2PortCal);
			}
			else
				break;
		}

		OrigSoftMenu_ItemClicked2(lpThis_2PortCal, TA_CC_2PC, 3);
		//DestroyDialog_Cal(0);
	}
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

inline void GetSubMenuPtr_R()
{
	if (lpThis_2PortCal)
	{
		lpThis_2PC_R = GetSubMenuPointer(lpThis_2PortCal, 0);
	}
	else
	{
		lpThis_2PortCal = GetSubMenuPointer(CA_CALCAL, 5);

		if (lpThis_2PortCal)
		{
			OrigSoftMenu_Enter(lpThis_2PortCal);
			OrigSoftMenu_UpdateItems(lpThis_2PortCal);
			lpThis_2PC_R = GetSubMenuPointer(lpThis_2PortCal, 0);
		}
	}
}

inline void GetSubMenuPtr_T()
{
	if (lpThis_2PortCal)
	{
		lpThis_2PC_T = GetSubMenuPointer(lpThis_2PortCal, 1);
	}
	else
	{
		lpThis_2PortCal = GetSubMenuPointer(CA_CALCAL, 5);

		if (lpThis_2PortCal)
		{
			OrigSoftMenu_Enter(lpThis_2PortCal);
			OrigSoftMenu_UpdateItems(lpThis_2PortCal);
			lpThis_2PC_T = GetSubMenuPointer(lpThis_2PortCal, 1);
		}
	}
}

inline void GetSubMenuPtr_I()
{
	if (lpThis_2PortCal)
	{
		lpThis_2PC_I = GetSubMenuPointer(lpThis_2PortCal, 2);
	}
	else
	{
		lpThis_2PortCal = GetSubMenuPointer(CA_CALCAL, 5);

		if (lpThis_2PortCal)
		{
			OrigSoftMenu_Enter(lpThis_2PortCal);
			OrigSoftMenu_UpdateItems(lpThis_2PortCal);
			lpThis_2PC_I = GetSubMenuPointer(lpThis_2PortCal, 2);
		}
	}
}

static void UpdateButtonState(HWND hClient)
{
	BOOL blTmp = FALSE;

	if (lpThis_2PortCal)
	{
		OrigSoftMenu_UpdateItems(lpThis_2PortCal);

		OrigSoftMenu_GetItemState(lpThis_2PortCal, 3, &blTmp, NULL, NULL);
		EnableButton_Cal(DEC_CMD_OK, blTmp);
	}

	if (lpThis_2PC_R)
	{
		OrigSoftMenu_UpdateItems(lpThis_2PC_R);

		OrigSoftMenu_GetItemState(lpThis_2PC_R, 0, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P1_O), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P1_O), BST_UNCHECKED);


		OrigSoftMenu_GetItemState(lpThis_2PC_R, 1, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P1_S), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P1_S), BST_UNCHECKED);


		OrigSoftMenu_GetItemState(lpThis_2PC_R, 2, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P1_L), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P1_L), BST_UNCHECKED);


		OrigSoftMenu_GetItemState(lpThis_2PC_R, 3, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P2_O), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P2_O), BST_UNCHECKED);


		OrigSoftMenu_GetItemState(lpThis_2PC_R, 4, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P2_S), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P2_S), BST_UNCHECKED);


		OrigSoftMenu_GetItemState(lpThis_2PC_R, 5, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P2_L), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P2_L), BST_UNCHECKED);
	}

	if (lpThis_2PC_T)
	{
		OrigSoftMenu_UpdateItems(lpThis_2PC_T);

		OrigSoftMenu_GetItemState(lpThis_2PC_T, 0, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P12_T), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P12_T), BST_UNCHECKED);
	}

	if (lpThis_2PC_I)
	{
		OrigSoftMenu_UpdateItems(lpThis_2PC_I);

		OrigSoftMenu_GetItemState(lpThis_2PC_I, 0, NULL, &blTmp, NULL);

		if (blTmp)
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P12_I), BST_CHECKED);
		else
			Button_SetCheck(GetDlgItem(hClient, IDC_CAL15_CMD_P12_I), BST_UNCHECKED);
	}
}



INT_PTR CALLBACK fndpCal_1_5(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_PAINT:
	/*{
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
	}*/
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
				case IDC_CAL15_CMD_P1_O:

					if (lpThis_2PC_R == NULL)
					{
						GetSubMenuPtr_R();

						if (lpThis_2PC_R == NULL)
						{
							Button_SetCheck((HWND)lParam, BST_UNCHECKED);
							return TRUE;
						}
						else
						{
							OrigSoftMenu_Enter(lpThis_2PC_R);
							OrigSoftMenu_UpdateItems(lpThis_2PC_R);
						}
					}

					OrigSoftMenu_ItemClicked2(lpThis_2PC_R, TA_CC_2PC_R, 0);
					//TestSelected(hDlg);
					break;

				case IDC_CAL15_CMD_P1_S:

					if (lpThis_2PC_R == NULL)
					{
						GetSubMenuPtr_R();

						if (lpThis_2PC_R == NULL)
						{
							Button_SetCheck((HWND)lParam, BST_UNCHECKED);
							return TRUE;
						}
						else
						{
							OrigSoftMenu_Enter(lpThis_2PC_R);
							OrigSoftMenu_UpdateItems(lpThis_2PC_R);
						}
					}

					OrigSoftMenu_ItemClicked2(lpThis_2PC_R, TA_CC_2PC_R, 1);
					//TestSelected(hDlg);
					break;

				case IDC_CAL15_CMD_P1_L:

					if (lpThis_2PC_R == NULL)
					{
						GetSubMenuPtr_R();

						if (lpThis_2PC_R == NULL)
						{
							Button_SetCheck((HWND)lParam, BST_UNCHECKED);
							return TRUE;
						}
						else
						{
							OrigSoftMenu_Enter(lpThis_2PC_R);
							OrigSoftMenu_UpdateItems(lpThis_2PC_R);
						}
					}

					OrigSoftMenu_ItemClicked2(lpThis_2PC_R, TA_CC_2PC_R, 2);
					//TestSelected(hDlg);
					break;

				case IDC_CAL15_CMD_P2_O:

					if (lpThis_2PC_R == NULL)
					{
						GetSubMenuPtr_R();

						if (lpThis_2PC_R == NULL)
						{
							Button_SetCheck((HWND)lParam, BST_UNCHECKED);
							return TRUE;
						}
						else
						{
							OrigSoftMenu_Enter(lpThis_2PC_R);
							OrigSoftMenu_UpdateItems(lpThis_2PC_R);
						}
					}

					OrigSoftMenu_ItemClicked2(lpThis_2PC_R, TA_CC_2PC_R, 3);
					//TestSelected(hDlg);
					break;

				case IDC_CAL15_CMD_P2_S:

					if (lpThis_2PC_R == NULL)
					{
						GetSubMenuPtr_R();

						if (lpThis_2PC_R == NULL)
						{
							Button_SetCheck((HWND)lParam, BST_UNCHECKED);
							return TRUE;
						}
						else
						{
							OrigSoftMenu_Enter(lpThis_2PC_R);
							OrigSoftMenu_UpdateItems(lpThis_2PC_R);
						}
					}

					OrigSoftMenu_ItemClicked2(lpThis_2PC_R, TA_CC_2PC_R, 4);
					//TestSelected(hDlg);
					break;

				case IDC_CAL15_CMD_P2_L:

					if (lpThis_2PC_R == NULL)
					{
						GetSubMenuPtr_R();

						if (lpThis_2PC_R == NULL)
						{
							Button_SetCheck((HWND)lParam, BST_UNCHECKED);
							return TRUE;
						}
						else
						{
							OrigSoftMenu_Enter(lpThis_2PC_R);
							OrigSoftMenu_UpdateItems(lpThis_2PC_R);
						}
					}

					OrigSoftMenu_ItemClicked2(lpThis_2PC_R, TA_CC_2PC_R, 5);
					//TestSelected(hDlg);
					break;

				case IDC_CAL15_CMD_P12_T:

					if (lpThis_2PC_T == NULL)
					{
						GetSubMenuPtr_T();

						if (lpThis_2PC_T == NULL)
						{
							Button_SetCheck((HWND)lParam, BST_UNCHECKED);
							return TRUE;
						}
						else
						{
							OrigSoftMenu_Enter(lpThis_2PC_T);
							OrigSoftMenu_UpdateItems(lpThis_2PC_T);
						}
					}

					OrigSoftMenu_ItemClicked2(lpThis_2PC_T, TA_CC_2PC_T, 0);
					//TestSelected(hDlg);
					break;

				case IDC_CAL15_CMD_P12_I:

					if (lpThis_2PC_I == NULL)
					{
						GetSubMenuPtr_I();

						if (lpThis_2PC_I == NULL)
						{
							Button_SetCheck((HWND)lParam, BST_UNCHECKED);
							return TRUE;
						}
						else
						{
							OrigSoftMenu_Enter(lpThis_2PC_I);
							OrigSoftMenu_UpdateItems(lpThis_2PC_I);
						}
					}

					OrigSoftMenu_ItemClicked2(lpThis_2PC_I, TA_CC_2PC_I, 0);
					//TestSelected(hDlg);
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


CALDLG_CTXT dcCal_1_5 =
{
	NULL,
	IDD_CAL_1_5,
	DFL_CMD_PREV | DFL_CMD_OK | DFL_LBL_INFO1,
	&fndeCal_1_5,
	&fndpCal_1_5,
	NULL,
	NULL,
	NULL,
	L"Manual Calibration\0手动校准\0手動校準\0\0",
	L"2 Port Cal\0\x32端口校准\0\x32端口校準\0\0",
	L"\0\0",
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	RESERVE_DWORD4,
	RESERVE_DWORD4
};