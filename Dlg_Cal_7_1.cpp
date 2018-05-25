#include "stdafx.h"

extern CALDLG_CTXT dcCal_7;

void UpdateComboBox_STD(HWND hCtl);

void *lpThis_SCLS_O = NULL;
void *lpThis_SCLS_O_P1 = NULL;
void *lpThis_SCLS_O_P2 = NULL;
void *lpThis_SCLS_S = NULL;
void *lpThis_SCLS_S_P1 = NULL;
void *lpThis_SCLS_S_P2 = NULL;
void *lpThis_SCLS_L = NULL;
void *lpThis_SCLS_L_P1 = NULL;
void *lpThis_SCLS_L_P2 = NULL;
void *lpThis_SCLS_T_P12 = NULL;

static void UpdateComboBoxSel(HWND hClient)
{
  int nIndex;

  OrigSoftMenu_UpdateItems(lpThis_SCLS_O);

  if (lpThis_SCLS_O_P1)
  {
    OrigSoftMenu_UpdateItems(lpThis_SCLS_O_P1);
    nIndex = GetSubMenuSelected_Radio(lpThis_SCLS_O_P1);

    ComboBox_SetCurSel(GetDlgItem(hClient, IDC_CAL71_CB_OP1), nIndex);
  }

  if (lpThis_SCLS_O_P2)
  {
    OrigSoftMenu_UpdateItems(lpThis_SCLS_O_P2);
    nIndex = GetSubMenuSelected_Radio(lpThis_SCLS_O_P2);

    ComboBox_SetCurSel(GetDlgItem(hClient, IDC_CAL71_CB_OP2), nIndex);
  }

  OrigSoftMenu_UpdateItems(lpThis_SCLS_S);

  if (lpThis_SCLS_S_P1)
  {
    OrigSoftMenu_UpdateItems(lpThis_SCLS_S_P1);
    nIndex = GetSubMenuSelected_Radio(lpThis_SCLS_S_P1);

    ComboBox_SetCurSel(GetDlgItem(hClient, IDC_CAL71_CB_SP1), nIndex);
  }

  if (lpThis_SCLS_S_P2)
  {
    OrigSoftMenu_UpdateItems(lpThis_SCLS_S_P2);
    nIndex = GetSubMenuSelected_Radio(lpThis_SCLS_S_P2);

    ComboBox_SetCurSel(GetDlgItem(hClient, IDC_CAL71_CB_SP2), nIndex);
  }

  OrigSoftMenu_UpdateItems(lpThis_SCLS_L);

  if (lpThis_SCLS_L_P1)
  {
    OrigSoftMenu_UpdateItems(lpThis_SCLS_L_P1);
    nIndex = GetSubMenuSelected_Radio(lpThis_SCLS_L_P1);

    ComboBox_SetCurSel(GetDlgItem(hClient, IDC_CAL71_CB_LP1), nIndex);
  }

  if (lpThis_SCLS_L_P2)
  {
    OrigSoftMenu_UpdateItems(lpThis_SCLS_L_P2);
    nIndex = GetSubMenuSelected_Radio(lpThis_SCLS_L_P2);

    ComboBox_SetCurSel(GetDlgItem(hClient, IDC_CAL71_CB_LP2), nIndex);
  }


  if (lpThis_SCLS_T_P12)
  {
    OrigSoftMenu_UpdateItems(lpThis_SCLS_T_P12);
    nIndex = GetSubMenuSelected_Radio(lpThis_SCLS_T_P12);

    ComboBox_SetCurSel(GetDlgItem(hClient, IDC_CAL71_CB_P12), nIndex);
  }
}

INT_PTR WINAPI fndeCal_7_1(PCALDLG_CTXT lpDlgCtxt, DWORD dwCode, WPARAM wParam, LPARAM lParam, LPARAM lParam2)
{
  if (lpDlgCtxt == NULL) return -1;

  INT_PTR lResult = 0;

  switch (dwCode)
  {
    case DEC_ENTER:
    {
      int nIndex = 0;

      OrigSoftMenu_Enter(CA_MCK);
      OrigSoftMenu_UpdateItems(CA_MCK);
      OrigSoftMenu_ItemClicked2(CA_MCK, TA_MCK, 1);

      OrigSoftMenu_Enter(CA_MCK_SCLS);
      OrigSoftMenu_UpdateItems(CA_MCK_SCLS);

      OrigSoftMenu_Enter(CA_MCK_SCLS_T);
      OrigSoftMenu_UpdateItems(CA_MCK_SCLS_T);

      lpThis_SCLS_O = GetSubMenuPointer(CA_MCK_SCLS, 0);
      if (lpThis_SCLS_O)
      {
        OrigSoftMenu_Enter(lpThis_SCLS_O);
        OrigSoftMenu_UpdateItems(lpThis_SCLS_O);

        lpThis_SCLS_O_P1 = GetSubMenuPointer(lpThis_SCLS_O, 1);
        if (lpThis_SCLS_O_P1)
        {
          OrigSoftMenu_Enter(lpThis_SCLS_O_P1);
          OrigSoftMenu_UpdateItems(lpThis_SCLS_O_P1);
        }

        lpThis_SCLS_O_P2 = GetSubMenuPointer(lpThis_SCLS_O, 2);
        if (lpThis_SCLS_O_P2)
        {
          OrigSoftMenu_Enter(lpThis_SCLS_O_P2);
          OrigSoftMenu_UpdateItems(lpThis_SCLS_O_P2);
        }
      }

      lpThis_SCLS_S = GetSubMenuPointer(CA_MCK_SCLS, 1);
      if (lpThis_SCLS_S)
      {
        OrigSoftMenu_Enter(lpThis_SCLS_S);
        OrigSoftMenu_UpdateItems(lpThis_SCLS_S);

        lpThis_SCLS_S_P1 = GetSubMenuPointer(lpThis_SCLS_S, 1);
        if (lpThis_SCLS_S_P1)
        {
          OrigSoftMenu_Enter(lpThis_SCLS_S_P1);
          OrigSoftMenu_UpdateItems(lpThis_SCLS_S_P1);
        }

        lpThis_SCLS_S_P2 = GetSubMenuPointer(lpThis_SCLS_S, 2);
        if (lpThis_SCLS_S_P2)
        {
          OrigSoftMenu_Enter(lpThis_SCLS_S_P2);
          OrigSoftMenu_UpdateItems(lpThis_SCLS_S_P2);
        }
      }

      lpThis_SCLS_L = GetSubMenuPointer(CA_MCK_SCLS, 2);
      if (lpThis_SCLS_L)
      {
        OrigSoftMenu_Enter(lpThis_SCLS_L);
        OrigSoftMenu_UpdateItems(lpThis_SCLS_L);

        lpThis_SCLS_L_P1 = GetSubMenuPointer(lpThis_SCLS_L, 1);
        if (lpThis_SCLS_L_P1)
        {
          OrigSoftMenu_Enter(lpThis_SCLS_L_P1);
          OrigSoftMenu_UpdateItems(lpThis_SCLS_L_P1);
        }

        lpThis_SCLS_L_P2 = GetSubMenuPointer(lpThis_SCLS_L, 2);
        if (lpThis_SCLS_L_P2)
        {
          OrigSoftMenu_Enter(lpThis_SCLS_L_P2);
          OrigSoftMenu_UpdateItems(lpThis_SCLS_L_P2);
        }
      }

      lpThis_SCLS_T_P12 = GetSubMenuPointer(CA_MCK_SCLS_T, 0);
      if (lpThis_SCLS_T_P12)
      {
        OrigSoftMenu_Enter(lpThis_SCLS_T_P12);
        OrigSoftMenu_UpdateItems(lpThis_SCLS_T_P12);
      }

      SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL71_GB_O),
        GetStringByIndex(L"Open\0开路器\0開路器\0\0", nLangId));
      SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL71_GB_S),
        GetStringByIndex(L"Short\0短路器\0短路器\0\0", nLangId));
      SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL71_GB_L),
        GetStringByIndex(L"Load\0负载\0負載\0\0", nLangId));
      SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL71_GB_T),
        GetStringByIndex(L"Thru\0短接\0短接\0\0", nLangId));

      SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL71_LBL_OA),
        GetStringByIndex(L"Set All\0全部设置\0全部設置\0\0", nLangId));
      SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL71_LBL_SA),
        GetStringByIndex(L"Set All\0全部设置\0全部設置\0\0", nLangId));
      SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL71_LBL_LA),
        GetStringByIndex(L"Set All\0全部设置\0全部設置\0\0", nLangId));

      SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL71_LBL_OP1),
        GetStringByIndex(L"Port 1\0端口1\0端口1\0\0", nLangId));
      SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL71_LBL_SP1),
        GetStringByIndex(L"Port 1\0端口1\0端口1\0\0", nLangId));
      SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL71_LBL_LP1),
        GetStringByIndex(L"Port 1\0端口1\0端口1\0\0", nLangId));

      SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL71_LBL_OP2),
        GetStringByIndex(L"Port 2\0端口2\0端口2\0\0", nLangId));
      SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL71_LBL_SP2),
        GetStringByIndex(L"Port 2\0端口2\0端口2\0\0", nLangId));
      SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL71_LBL_LP2),
        GetStringByIndex(L"Port 2\0端口2\0端口2\0\0", nLangId));

      SetWindowTextW(GetDlgItem((HWND)lParam2, IDC_CAL71_LBL_P12),
        GetStringByIndex(L"Port 1-2\0端口1-2\0端口1-2\0\0", nLangId));

      UpdateComboBox_STD(GetDlgItem((HWND)lParam2, IDC_CAL71_CB_OA));
      UpdateComboBox_STD(GetDlgItem((HWND)lParam2, IDC_CAL71_CB_OP1));
      UpdateComboBox_STD(GetDlgItem((HWND)lParam2, IDC_CAL71_CB_OP2));
      UpdateComboBox_STD(GetDlgItem((HWND)lParam2, IDC_CAL71_CB_SA));
      UpdateComboBox_STD(GetDlgItem((HWND)lParam2, IDC_CAL71_CB_SP1));
      UpdateComboBox_STD(GetDlgItem((HWND)lParam2, IDC_CAL71_CB_SP2));
      UpdateComboBox_STD(GetDlgItem((HWND)lParam2, IDC_CAL71_CB_LA));
      UpdateComboBox_STD(GetDlgItem((HWND)lParam2, IDC_CAL71_CB_LP1));
      UpdateComboBox_STD(GetDlgItem((HWND)lParam2, IDC_CAL71_CB_LP2));
      UpdateComboBox_STD(GetDlgItem((HWND)lParam2, IDC_CAL71_CB_P12));

      UpdateComboBoxSel((HWND)lParam2);
    }
    break;

    case DEC_CMD_PREV:
    UpdateDialog_Cal(&dcCal_7, 0);
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

INT_PTR CALLBACK fndpCal_7_1(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
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
        /*
        if (wNc == BN_CLICKED)
        {
          switch (wId)
          {
            case IDC_CAL2_CMD_RT_S21:
            OrigSoftMenu_ItemClicked2(CA_ECAL_RT, TA_ECAL_RT, 0);
            break;
          }
          break;
        }
        */

        if (wNc == CBN_SELCHANGE)
        {
          switch (wId)
          {
            case IDC_CAL71_CB_OA:
            {
              if (lpThis_SCLS_O)
              {
                OrigSoftMenu_ItemClicked2(CA_MCK_SCLS, TA_MCK_SCLS, 0);

                OrigSoftMenu_Enter(lpThis_SCLS_O);
                OrigSoftMenu_UpdateItems(lpThis_SCLS_O);
                OrigSoftMenu_ItemClicked2(lpThis_SCLS_O, TA_MCK_SCLS_X, 0);

                OrigSoftMenu_Enter(CA_SCLS_X_SA);
                OrigSoftMenu_UpdateItems(CA_SCLS_X_SA);
                OrigSoftMenu_ItemClicked2(CA_SCLS_X_SA, TA_SCLS_X_SA, ComboBox_GetCurSel((HWND)lParam));

                UpdateComboBoxSel(hDlg);
              }
            }
            break;

            case IDC_CAL71_CB_OP1:
            {
              if (lpThis_SCLS_O_P1)
              {
                OrigSoftMenu_ItemClicked2(CA_MCK_SCLS, TA_MCK_SCLS, 0);

                OrigSoftMenu_Enter(lpThis_SCLS_O);
                OrigSoftMenu_UpdateItems(lpThis_SCLS_O);
                OrigSoftMenu_ItemClicked2(lpThis_SCLS_O, TA_MCK_SCLS_X, 1);

                OrigSoftMenu_Enter(lpThis_SCLS_O_P1);
                OrigSoftMenu_UpdateItems(lpThis_SCLS_O_P1);
                OrigSoftMenu_ItemClicked2(lpThis_SCLS_O_P1, TA_SCLS_X_XX, ComboBox_GetCurSel((HWND)lParam));
              }
            }
            break;

            case IDC_CAL71_CB_OP2:
            {
              if (lpThis_SCLS_O_P2)
              {
                OrigSoftMenu_ItemClicked2(CA_MCK_SCLS, TA_MCK_SCLS, 0);

                OrigSoftMenu_Enter(lpThis_SCLS_O);
                OrigSoftMenu_UpdateItems(lpThis_SCLS_O);
                OrigSoftMenu_ItemClicked2(lpThis_SCLS_O, TA_MCK_SCLS_X, 2);

                OrigSoftMenu_Enter(lpThis_SCLS_O_P2);
                OrigSoftMenu_UpdateItems(lpThis_SCLS_O_P2);
                OrigSoftMenu_ItemClicked2(lpThis_SCLS_O_P2, TA_SCLS_X_XX, ComboBox_GetCurSel((HWND)lParam));
              }
            }
            break;

            case IDC_CAL71_CB_SA:
            {
              if (lpThis_SCLS_S)
              {
                OrigSoftMenu_ItemClicked2(CA_MCK_SCLS, TA_MCK_SCLS, 1);

                OrigSoftMenu_Enter(lpThis_SCLS_S);
                OrigSoftMenu_UpdateItems(lpThis_SCLS_S);
                OrigSoftMenu_ItemClicked2(lpThis_SCLS_S, TA_MCK_SCLS_X, 0);

                OrigSoftMenu_Enter(CA_SCLS_X_SA);
                OrigSoftMenu_UpdateItems(CA_SCLS_X_SA);
                OrigSoftMenu_ItemClicked2(CA_SCLS_X_SA, TA_SCLS_X_SA, ComboBox_GetCurSel((HWND)lParam));

                UpdateComboBoxSel(hDlg);
              }
            }
            break;

            case IDC_CAL71_CB_SP1:
            {
              if (lpThis_SCLS_S_P1)
              {
                OrigSoftMenu_ItemClicked2(CA_MCK_SCLS, TA_MCK_SCLS, 1);

                OrigSoftMenu_Enter(lpThis_SCLS_S);
                OrigSoftMenu_UpdateItems(lpThis_SCLS_S);
                OrigSoftMenu_ItemClicked2(lpThis_SCLS_S, TA_MCK_SCLS_X, 1);

                OrigSoftMenu_Enter(lpThis_SCLS_S_P1);
                OrigSoftMenu_UpdateItems(lpThis_SCLS_S_P1);
                OrigSoftMenu_ItemClicked2(lpThis_SCLS_S_P1, TA_SCLS_X_XX, ComboBox_GetCurSel((HWND)lParam));
              }
            }
            break;

            case IDC_CAL71_CB_SP2:
            {
              if (lpThis_SCLS_S_P2)
              {
                OrigSoftMenu_ItemClicked2(CA_MCK_SCLS, TA_MCK_SCLS, 1);

                OrigSoftMenu_Enter(lpThis_SCLS_S);
                OrigSoftMenu_UpdateItems(lpThis_SCLS_S);
                OrigSoftMenu_ItemClicked2(lpThis_SCLS_S, TA_MCK_SCLS_X, 2);

                OrigSoftMenu_Enter(lpThis_SCLS_S_P2);
                OrigSoftMenu_UpdateItems(lpThis_SCLS_S_P2);
                OrigSoftMenu_ItemClicked2(lpThis_SCLS_S_P2, TA_SCLS_X_XX, ComboBox_GetCurSel((HWND)lParam));
              }
            }
            break;

            case IDC_CAL71_CB_LA:
            {
              if (lpThis_SCLS_L)
              {
                OrigSoftMenu_ItemClicked2(CA_MCK_SCLS, TA_MCK_SCLS, 2);

                OrigSoftMenu_Enter(lpThis_SCLS_L);
                OrigSoftMenu_UpdateItems(lpThis_SCLS_L);
                OrigSoftMenu_ItemClicked2(lpThis_SCLS_L, TA_MCK_SCLS_X, 0);

                OrigSoftMenu_Enter(CA_SCLS_X_SA);
                OrigSoftMenu_UpdateItems(CA_SCLS_X_SA);
                OrigSoftMenu_ItemClicked2(CA_SCLS_X_SA, TA_SCLS_X_SA, ComboBox_GetCurSel((HWND)lParam));

                UpdateComboBoxSel(hDlg);
              }
            }
            break;

            case IDC_CAL71_CB_LP1:
            {
              if (lpThis_SCLS_L_P1)
              {
                OrigSoftMenu_ItemClicked2(CA_MCK_SCLS, TA_MCK_SCLS, 2);

                OrigSoftMenu_Enter(lpThis_SCLS_L);
                OrigSoftMenu_UpdateItems(lpThis_SCLS_L);
                OrigSoftMenu_ItemClicked2(lpThis_SCLS_L, TA_MCK_SCLS_X, 1);

                OrigSoftMenu_Enter(lpThis_SCLS_L_P1);
                OrigSoftMenu_UpdateItems(lpThis_SCLS_L_P1);
                OrigSoftMenu_ItemClicked2(lpThis_SCLS_L_P1, TA_SCLS_X_XX, ComboBox_GetCurSel((HWND)lParam));
              }
            }
            break;

            case IDC_CAL71_CB_LP2:
            {
              if (lpThis_SCLS_L_P2)
              {
                OrigSoftMenu_ItemClicked2(CA_MCK_SCLS, TA_MCK_SCLS, 2);

                OrigSoftMenu_Enter(lpThis_SCLS_L);
                OrigSoftMenu_UpdateItems(lpThis_SCLS_L);
                OrigSoftMenu_ItemClicked2(lpThis_SCLS_L, TA_MCK_SCLS_X, 2);

                OrigSoftMenu_Enter(lpThis_SCLS_L_P2);
                OrigSoftMenu_UpdateItems(lpThis_SCLS_L_P2);
                OrigSoftMenu_ItemClicked2(lpThis_SCLS_L_P2, TA_SCLS_X_XX, ComboBox_GetCurSel((HWND)lParam));
              }
            }
            break;

            case IDC_CAL71_CB_P12:
            {
              if (lpThis_SCLS_T_P12)
              {
                OrigSoftMenu_ItemClicked2(lpThis_SCLS_T_P12, TA_SCLS_T_P12, ComboBox_GetCurSel((HWND)lParam));
              }
            }
            break;
          }
        }
      }
    }
    break;

  }

  return FALSE;
}

CALDLG_CTXT dcCal_7_1 =
{
  NULL,
  IDD_CAL_7_1,
  DFL_CMD_PREV | DFL_LBL_INFO1,
  &fndeCal_7_1,
  &fndpCal_7_1,
  NULL,
  NULL,
  NULL,
  L"Modify Cal Kit\0更换校准件\0更換校準件\0\0",
  L"Specify CLSs\0指定标准类别\0指定標準類別\0\0",
  L"\0\0",
  NULL,
  NULL,
  NULL,
  NULL,
  L"Exit\0退出\0退出\0\0",
  RESERVE_DWORD4,
  RESERVE_DWORD4
};