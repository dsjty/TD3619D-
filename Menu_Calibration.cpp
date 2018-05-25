#include "stdafx.h"

extern CALDLG_CTXT dcCal_1;
extern CALDLG_CTXT dcCal_2;
extern CALDLG_CTXT dcCal_3;
extern CALDLG_CTXT dcCal_7;

extern CalKit cCalkit;

//校准子条目
SOFT_SUB_ITEM subitemCalibration[] =
{
	{
		SIF_ORIGCLICK,
		SIA_FULLLINE | SIA_GETBTNSTATE | SIA_UPDATEITEM,
		SIS_CheckButtonEx,
		0,
		L"Correction\0校正\0校正\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00020100, 0, (void *)0x00B6466C, (void *)0x77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_CALIBRAT,
		CA_CALIBRAT,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_CALWND,
		SIA_FULLLINE,
		SIS_ButtonEx,
		1,
		L"Calibration\0校准\0校準\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		NULL,
		&dcCal_1,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_CALWND,
		SIA_FULLLINE,
		SIS_ButtonEx,
		3,
		L"Test Set Cal\0测试装置校准\0測試裝置校準\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		NULL,
		&dcCal_3,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_CALWND,
		SIA_FULLLINE,
		SIS_ButtonEx,
		2,
		L"ECal\0电子校准\0電子校準\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		NULL,
		&dcCal_2,
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
		0,
		L"Clear All\0全部清除\0全部清除\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_CALIBRAT_CA,
		CA_CALIBRAT_CA,
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
		5,
		L"Property\0校准信息显示\0校準信息顯示\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00060500, 0, (void *)0x00B64650, (void *)0x77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_CALIBRAT,
		CA_CALIBRAT,
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
		6,
		L"Cal Kit\0校准件\0校準件\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ (void *)0x00010000, 0, (void *)0x00B629D4, (void *)0x06, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, &fnItemSelected_Default, &fnUpdateData_DEC_Default, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		INVALID_INDEX,
		NULL,
		NULL,
		TA_CALIBRAT_CK,
		CA_CALIBRAT_CK,
		(DWORD)10,
		(void *)cCalkit.CalKitList,
		RESERVE_DWORD4,
		{0,0,0,1}
	}
	,
	{
		SIF_CALWND,
		SIA_FULLLINE,
		SIS_ButtonEx,
		7,
		L"Modify Cal Kit\0更换校准件\0更換校準件\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		RESERVE_DWORD16,
		RESERVE_DWORD16,
		0,
		NULL,
		NULL,
		NULL,
		&dcCal_7,
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
		0,
		L"Port Extensions\0端口扩展\0端口擴展\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H,
		NULL,
		{ (void *)0x00010000, 0, (void *)0x00B63770, (void *)0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_CALIBRAT_PE,
		CA_CALIBRAT_PE,
		NULL,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
	,
	{
		SIF_ORIGCLICK | SIF_NOREPLY,
		SIA_FULLLINE | SIA_INPUT_TIME,
		SIS_InputButtonEx,
		1,
		L"Extension Port 1\0扩展端口1\0擴展端口1\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BB8D70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_CALIBRAT_PE,
		CA_CALIBRAT_PE,
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
		2,
		L"Extension Port 2\0扩展端口2\0擴展端口2\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BB8D98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_CALIBRAT_PE,
		CA_CALIBRAT_PE,
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
		L"Velocity Factor\0速度系数\0速度系數\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BB8DE0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_CALIBRAT,
		CA_CALIBRAT,
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
		10,
		L"Set Z0\0设置阻抗\0設置阻抗\0\0",
		NULL,
		BtnWidth_W,
		BtnHeith_H2,
		NULL,
		{ 0, (void *)0x00BB8DD0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		RESERVE_DWORD16,
		INVALID_INDEX,
		NULL,
		NULL,
		TA_CALIBRAT,
		CA_CALIBRAT,
		0,
		NULL,
		RESERVE_DWORD4,
		RESERVE_DWORD4
	}
};

int WINAPI fnTagPageEnter_Calibration(DWORD dwFlags, WPARAM wParam, LPARAM lParam, struct _SOFT_TAG_PAGE *lpTagPage)
{
	BOOL blTmp = FALSE;
	OrigSoftMenu_UpdateItems(CA_CALIBRAT);


	OrigSoftMenu_GetItemState(CA_CAL_TSC, 1, &blTmp, NULL, NULL);

	if (blTmp & 0xFF)
		NOT_FLAGS(subitemCalibration[2].dwAttributes, SIAE_DISABLED);
		//SET_FLAGS(subitemCalibration[2].dwAttributes, SIAE_DISABLED);
	else
		SET_FLAGS(subitemCalibration[2].dwAttributes, SIAE_DISABLED);

	return 0;
}


//校准子菜单
SOFT_TAG_PAGE submenuCalibration[] =
{
	{
		TPF_FN_ENTER /* | SSF_FN_LEAVE */,
		0,
		L"Calibration\0校准\0校準\0\0",
		NULL,
		sizeof(subitemCalibration) / sizeof(SOFT_SUB_ITEM),
		subitemCalibration,
		RESERVE_DWORD4,
		&fnTagPageEnter_Calibration,
		NULL,
		0,
		{ L"::/Measurement/Calibration/Calibration.htm", (void*)1031, 0, 0 }
	}
};

//校准主菜单
SOFT_MENU menuCalibration =
{
	0,
	0,
	L"Calibration\0校准\0校準\0\0",
	NULL,
	sizeof(submenuCalibration) / sizeof(SOFT_TAG_PAGE),
	submenuCalibration,
	NULL,
	NULL,
	0,
	RESERVE_DWORD4
};

