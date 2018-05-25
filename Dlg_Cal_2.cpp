#include "stdafx.h"

INT_PTR WINAPI fndeCal_2(PCALDLG_CTXT lpDlgCtxt, DWORD dwCode, WPARAM wParam, LPARAM lParam, LPARAM lParam2)
{
	if (lpDlgCtxt == NULL) return -1;

	INT_PTR lResult = 0;

	switch (dwCode)
	{
	case DEC_ENTER:
	{
		int nOnOff = 0;

		OrigSoftMenu_Enter(CA_ECAL);
		OrigSoftMenu_UpdateItems(CA_ECAL);

		OrigSoftMenu_Enter(CA_ECAL_RT);
		OrigSoftMenu_UpdateItems(CA_ECAL_RT);

		OrigSoftMenu_Enter(CA_ECAL_ER);
		OrigSoftMenu_UpdateItems(CA_ECAL_ER);

		OrigSoftMenu_Enter(CA_ECAL_1PC);
		OrigSoftMenu_UpdateItems(CA_ECAL_1PC);

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL2_GB_RT), GetStringByIndex(L"Response (Thru)\0响应短接\0響應短接\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL2_GB_ER), GetStringByIndex(L"Enhanced Response\0增强型响应\0增強型響應\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL2_GB_1PC), GetStringByIndex(L"1-Port Cal\0\x31端口校准\0\x31端口校準\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL2_GB_2PC), GetStringByIndex(L"2-Port Cal\0\x32端口校准\0\x32端口校準\0\0", nLangId));

		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL2_CMD_CI), GetStringByIndex(L"Isolation\0校准隔离\0校準隔離\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL2_CMD_P1), GetStringByIndex(L"Port 1\0端口1\0端口1\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL2_CMD_P2), GetStringByIndex(L"Port 2\0端口2\0端口2\0\0", nLangId));
		SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL2_CMD_2PC), GetStringByIndex(L"2-Port Cal\0\x32端口校准\0\x32端口校準\0\0", nLangId));


		GetButtonStateIndex((const char *)0x00B62BB4, NULL, &nOnOff, 0x000F0E00);

		if (GET_BYTE_0(nOnOff) != 0)
		{
			Button_SetCheck(GetDlgItem((HWND)lParam2, IDC_CAL2_CMD_CI), BST_CHECKED);
		}
		else
		{
			Button_SetCheck(GetDlgItem((HWND)lParam2, IDC_CAL2_CMD_CI), BST_UNCHECKED);
		}
	}
	break;

	case DEC_CMD_OK:
		if (Button_GetCheck(GetDlgItem((HWND)lParam2, IDC_CAL2_CMD_CI)) == BST_UNCHECKED)
		{
			int nOnOff = 0;

			GetButtonStateIndex((const char *)0x00B62BB4, NULL, &nOnOff, 0x000F0E00);

			if (GET_BYTE_0(nOnOff) != 0)
			{
				OrigSoftMenu_ItemClicked2(CA_ECAL, TA_ECAL, 4);
			}
		}
		else
		{
			int nOnOff = 0;

			GetButtonStateIndex((const char *)0x00B62BB4, NULL, &nOnOff, 0x000F0E00);

			if (GET_BYTE_0(nOnOff) == 0)
			{
				OrigSoftMenu_ItemClicked2(CA_ECAL, TA_ECAL, 4);
			}
		}
		break;

	case DEC_CMD_CANCEL:
		lResult = TRUE;
		break;

	case DEC_CMD_CLOSE:
		lResult = TRUE;
		break;
	}

	return lResult;
}

INT_PTR CALLBACK fndpCal_2(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
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
				case IDC_CAL2_CMD_CI:
					if (Button_GetCheck((HWND)lParam) == BST_UNCHECKED)
					{
						int nOnOff = 0;

						GetButtonStateIndex((const char *)0x00B62BB4, NULL, &nOnOff, 0x000F0E00);

						if (GET_BYTE_0(nOnOff) != 0)
						{
							OrigSoftMenu_ItemClicked2(CA_ECAL, TA_ECAL, 4);
						}
					}
					else
					{
						int nOnOff = 0;

						GetButtonStateIndex((const char *)0x00B62BB4, NULL, &nOnOff, 0x000F0E00);

						if (GET_BYTE_0(nOnOff) == 0)
						{
							OrigSoftMenu_ItemClicked2(CA_ECAL, TA_ECAL, 4);
						}
					}
					break;

				case IDC_CAL2_CMD_RT_S21:
					OrigSoftMenu_ItemClicked2(CA_ECAL_RT, TA_ECAL_RT, 0);
					break;

				case IDC_CAL2_CMD_RT_S12:
					OrigSoftMenu_ItemClicked2(CA_ECAL_RT, TA_ECAL_RT, 1);
					break;

				case IDC_CAL2_CMD_ER_S21:
					OrigSoftMenu_ItemClicked2(CA_ECAL_ER, TA_ECAL_ER, 0);
					break;

				case IDC_CAL2_CMD_ER_S12:
					OrigSoftMenu_ItemClicked2(CA_ECAL_ER, TA_ECAL_ER, 1);
					break;

				case IDC_CAL2_CMD_P1:
					OrigSoftMenu_ItemClicked2(CA_ECAL_1PC, TA_ECAL_1PC, 0);
					break;

				case IDC_CAL2_CMD_P2:
					OrigSoftMenu_ItemClicked2(CA_ECAL_1PC, TA_ECAL_1PC, 1);
					break;

				case IDC_CAL2_CMD_2PC:
					OrigSoftMenu_ItemClicked2(CA_ECAL, TA_ECAL, 3);
					break;
				}
			}
		}
	}
	break;

	}

	return FALSE;
}

CALDLG_CTXT dcCal_2 =
{
	NULL,
	IDD_CAL_2,
	DFL_CMD_OK | DFL_LBL_INFO1,
	&fndeCal_2,
	&fndpCal_2,
	NULL,
	NULL,
	NULL,
	L"ECal\0电子校准\0電子校準\0\0",
	NULL,
	L"\0\0",
	NULL,
	NULL,
	NULL,
	L"Done\0完成\0完成\0\0",
	L"Exit\0退出\0退出\0\0",
	RESERVE_DWORD4,
	RESERVE_DWORD4
};