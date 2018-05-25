#include "stdafx.h"

int WINAPI fnhk_DrawTextA(HDC hdc, LPCSTR lpchText, int cchText, LPRECT lprc, UINT format);
//HGDIOBJ WINAPI fnhk_SelectObject(HDC hdc, HGDIOBJ h);

//0x00BB7C74 hFont

static HFONT hFont_DrawRect = NULL; //绘图区域字体
static HFONT hFont_Backup = NULL;
static void *lpfnDrawTextA = &fnhk_DrawTextA;
//static void *lpfnSelectObject = &fnhk_SelectObject;

#define _LT_  LocaleText

LOCALE_TEXT LocaleText[] =
{
	{
		(void *)0x008C8FCA,
		NULL,
		"Tr\0曲线\0曲線\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x00904216,
		NULL,
		"/ Ref \0/ 基准 \0/ 基準 \0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x0090A754,
		NULL,
		"Scale \0分辨率 \0分辨率 \0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x0090A796,
		NULL,
		"Scale \0分辨率 \0分辨率 \0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004E47ED,
		NULL,
		"Log Mag\0对数\0對數\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004E48BB,
		NULL,
		"Phase\0相位\0相位\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004E4984,
		NULL,
		"Delay\0延迟\0延遲\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004E4A4F,
		NULL,
		"Smith (Lin/Phase)\0史密斯圆图 (线性/相位)\0史密斯圓圖 (線性/相位)\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004E4B1B,
		NULL,
		"Smith (Log/Phase)\0史密斯圆图 (对数/相位)\0史密斯圓圖 (對數/相位)\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004E4BE6,
		NULL,
		"Smith (Re/Im)\0史密斯圆图 (实部/虚部)\0史密斯圓圖 (實部/虛部)\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004E4CB1,
		NULL,
		"Smith (R+jX)\0史密斯圆图 (R+jX)\0史密斯圓圖 (R+jX)\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004E4D7C,
		NULL,
		"Smith (G+jB)\0史密斯圆图 (G+jB)\0史密斯圓圖 (G+jB)\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004E4E48,
		NULL,
		"Polar (Lin/Phase)\0极坐标 (线性/相位)\0極坐標 (線性/相位)\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004E4F14,
		NULL,
		"Polar (Log/Phase)\0极坐标 (对数/相位)\0極坐標 (對數/相位)\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004E4FDF,
		NULL,
		"Polar (Re/Im)\0极坐标 (实部/虚部)\0極坐標 (實部/虛部)\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004E50A9,
		NULL,
		"Lin Mag\0线性\0線性\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004E523B,
		NULL,
		"Real\0实部\0實部\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004E5304,
		NULL,
		"Imag\0虚部\0虛部\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004E550F,
		NULL,
		"Ex Phase\0扩展相位\0擴展相位\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004E572C,
		NULL,
		"Pos Phase\0正相位\0正相位\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x0090C053,
		NULL,
		"Meas\0测量\0测量\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008D2B80,
		NULL,
		"ExtRef\0外基准\0外基准\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008D2B90,
		NULL,
		"ExtRef\0外基准\0外基准\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008D2DAA,
		NULL,
		"Stop\0停止\0停止\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008D2DBA,
		NULL,
		"Stop\0停止\0停止\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008D2AE7,
		NULL,
		"Svc\0服务\0服务\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008D2AF7,
		NULL,
		"Svc\0服务\0服务\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008C4AA8,
		NULL,
		"Start \0起始 \0起始 \0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008C4AB8,
		NULL,
		"Start \0起始 \0起始 \0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008C4B5B,
		NULL,
		"Stop \0终止 \0终止 \0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008C4B6B,
		NULL,
		"Stop \0终止 \0终止 \0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008c59df,
		NULL,
		"Off\0关闭\0關閉\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008E4275,
		NULL,
		"Loading ...\0载入中 ...\0载入中 ...\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008E4287,
		NULL,
		"Loading ...\0载入中 ...\0载入中 ...\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008E48EF,
		NULL,
		"Rev.\0版本: \0版本: \0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008E3FD7,
		NULL,
		"Build: \0构建: \0构建: \0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008E4B38,
		NULL,
		"Option: %s\0选件: %s\0选件: %s\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008E470A,
		NULL,
		"Portions (C)Copyright 1996, Microsoft Corporation. All rights reserved.\0版权所有 (C)Copyright 1996\0版权所有 (C)Copyright 1996\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008E4BAF,
		NULL,
		"Portions (C)Copyright 1996, Microsoft Corporation. All rights reserved.\0版权所有 (C)Copyright 1996\0版权所有 (C)Copyright 1996\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x0057F63F,
		NULL,
		"Copyright (C) 2002-2006 Tianda Technologies\0版权所有 (C)Copyright 2002-2016\0版权所有 (C)Copyright 2002-2016\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x008E4B8B,
		NULL,
		"Copyright (C) 2002-2006 Tianda Technologies\0版权所有 (C)Copyright 2002-2016\0版权所有 (C)Copyright 2002-2016\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x00402ABA,
		NULL,
		"Initializing Main Window ...\0初始化主窗口 ...\0初始化主窗口 ...\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x0040286C,
		NULL,
		"Simulator Mode\0模拟器模式\0模拟器模式\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x004027DC,
		NULL,
		"Will Exit in Five Seconds\0将在5秒后退出\0将在5秒后退出\0\0",
		NULL,
		{ 0 }
	}
	,
	{
		(void *)0x00402705,
		NULL,
		"Will Shut Down in Five Seconds\0将在5秒后关机\0将在5秒后关机\0\0",
		NULL,
		{ 0 }
	}
};


int WINAPI fnhk_DrawTextA(HDC hdc, LPCSTR lpchText, int cchText, LPRECT lprc, UINT format)
{
	HGDIOBJ hGdiObjFont = GetCurrentObject(hdc, OBJ_FONT);
	int nRet;

	SelectObject(hdc, hFont_DrawRect);
	nRet = DrawTextA(hdc, lpchText, cchText, lprc, format);
	SelectObject(hdc, hGdiObjFont);

	return nRet;
}

//°编码替换
int __cdecl fnhk_StdOperatorPlus(PBAS_STR lpBStrOut, PBAS_STR lpBStr1, PBAS_STR lpBStr2)
{
	typedef int(__cdecl *fn_StdOperatorPlus)(PBAS_STR lpBStrOut, PBAS_STR lpBStr1, PBAS_STR lpBStr2);

	fn_StdOperatorPlus fnSOP = (fn_StdOperatorPlus)0x009565B6;
	int nRet, nMode = 0;

	if ((lpBStr2->dwStringLen == 1) && (*lpBStr2->lpszText == '\xB0'))
	{
		nMode = 1;

		strcpy_s(lpBStr2->lpszText, lpBStr2->dwBufferMaxLen, "°");
		lpBStr2->dwStringLen = strlen(lpBStr2->lpszText);
	}

	nRet = fnSOP(lpBStrOut, lpBStr1, lpBStr2);

	switch (nMode)
	{
	case 1:
		strcpy_s(lpBStr2->lpszText, lpBStr2->dwBufferMaxLen, "\xB0\x00");
		lpBStr2->dwStringLen = strlen(lpBStr2->lpszText);
		break;
	}

	return nRet;
}

//拦截E506X Network
PBAS_STR __stdcall fn_008BF860(PBAS_STR lpBStr)
{
	if (lpBStr && lpBStr->lpszText)
	{
		strcpy_s(lpBStr->lpszText, lpBStr->dwBufferMaxLen, "矢量网络分析仪");
		lpBStr->dwStringLen = strlen(lpBStr->lpszText);
	}

	return lpBStr;
}

NAKED PBAS_STR fnhk_008BF860(PBAS_STR lpBStr)
{
	__asm push eax
	__asm call fn_008BF860
	__asm retn 0x04
}

inline int GetMaxLocaleText()
{
	return sizeof(_LT_) / sizeof(LOCALE_TEXT);
}

void UpdateCurrentLocale()
{
	int nMax = GetMaxLocaleText();
	LPCSTR lpcText;

	for (int nIndex = 0; nIndex < nMax; nIndex++)
	{
		lpcText = GetStringByIndexA(_LT_[nIndex].lpLocaleText, nLangId);

		if (lpcText)
		{
			int nLen = strlen(lpcText);

			if (nLen >= 48)
			{
				if (_LT_[nIndex].lpszCurText)
					free(_LT_[nIndex].lpszCurText);

				_LT_[nIndex].lpszCurText = (char *)malloc(nLen + 1);

				if (_LT_[nIndex].lpszCurText == NULL)
					continue;

				strcpy_s(_LT_[nIndex].lpszCurText, nLen + 1, lpcText);
			}
			else
				strcpy_s(_LT_[nIndex].szCurText, 48, lpcText);
		}
	}
}

static void SetTextHook()
{
	int nMax = GetMaxLocaleText();

	//更新当前语言翻译
	UpdateCurrentLocale();

	for (int nIndex = 0; nIndex < nMax; nIndex++)
	{
		if (_LT_[nIndex].lpOrigAddr == NULL)
		{
			if (_LT_[nIndex].lpszCurText)
				SetPointer((int *)_LT_[nIndex].lpHookAddr, (int *)&(_LT_[nIndex].lpOrigAddr), (int)_LT_[nIndex].lpszCurText);
			else
				SetPointer((int *)_LT_[nIndex].lpHookAddr, (int *)&(_LT_[nIndex].lpOrigAddr), (int)_LT_[nIndex].szCurText);
		}
	}
}

//************************************
// 函数名:    SetFuncHook
// Access:    public static 
// 返回值类型:   void
// 说明: 设置函数hook
//************************************
static void SetFuncHook()
{
	int nTmp;

	SetPointer((int *)0x009056C6, NULL, (int)&lpfnDrawTextA);
	SetPointer((int *)0x00905732, NULL, (int)&lpfnDrawTextA);
	SetPointer((int *)0x009058AB, NULL, (int)&lpfnDrawTextA);
	SetPointer((int *)0x008D39F9, NULL, (int)&lpfnDrawTextA);
	SetPointer((int *)0x008AD51A, NULL, (int)&lpfnDrawTextA);
	SetPointer((int *)0x008E4847, NULL, (int)&lpfnDrawTextA);
	SetPointer((int *)0x008E4968, NULL, (int)&lpfnDrawTextA);
	SetPointer((int *)0x008E4ABF, NULL, (int)&lpfnDrawTextA);
	SetPointer((int *)0x008ACF93, NULL, (int)&lpfnDrawTextA);
	
	WriteMemory((void *)0x008E4B1E, "\xFF\xB4\x24\xB8\x00\x00\x00\xA1\x98\x2F\xA0\x00\xFF\xD0\x8B\xFF\x90", 17);
	SetPointer((int *)(0x008E4B1E + 8), NULL, (int)&lpfnDrawTextA);
		
	WriteMemory((void *)0x008E4B61, "\xFF\xB4\x24\xB8\x00\x00\x00\xA1\x98\x2F\xA0\x00\xFF\xD0\x8B\xFF\x90", 17);
	SetPointer((int *)(0x008E4B61 + 8), NULL, (int)&lpfnDrawTextA);
		
	WriteMemory((void *)0x008E4C17, "\xFF\xB4\x24\xB8\x00\x00\x00\xA1\x98\x2F\xA0\x00\xFF\xD0\x8B\xFF\x90", 17);
	SetPointer((int *)(0x008E4C17 + 8), NULL, (int)&lpfnDrawTextA);
	
	SetOffsetHook((int *)0x00904211, &nTmp, (int)&fnhk_StdOperatorPlus);
	SetOffsetHook((int *)0x00904254, &nTmp, (int)&fnhk_StdOperatorPlus);

	nTmp = 0xE9;
	WriteMemory((void *)0x008BF91E, &nTmp, 1);
	SetOffsetHook((int *)0x008BF91F, &nTmp, (int)&fnhk_008BF860);
}


int InitLocaleHook()
{
#define FONT_SIZE           12
	LOGFONTW logfont;
	int nTmp;

	//创建字体
	logfont.lfHeight = FONT_SIZE;
	logfont.lfWidth = 0;
	logfont.lfEscapement = 0;
	logfont.lfOrientation = 0;
	logfont.lfWeight = FW_NORMAL;
	logfont.lfItalic = 0;
	logfont.lfUnderline = 0;
	logfont.lfStrikeOut = 0;
	//logfont.lfCharSet = DEFAULT_CHARSET;
	logfont.lfCharSet = GB2312_CHARSET;
	logfont.lfOutPrecision = OUT_DEFAULT_PRECIS;
	logfont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	logfont.lfQuality = CLEARTYPE_NATURAL_QUALITY;
	//logfont.lfQuality = DEFAULT_QUALITY;
	logfont.lfPitchAndFamily = FF_DONTCARE | DEFAULT_PITCH;
	wcscpy_s(logfont.lfFaceName, LF_FACESIZE, L"Simsun");

	hFont_DrawRect = CreateFontIndirectW(&logfont);

	if (hFont_DrawRect == NULL) return -1;

	nTmp = FONT_SIZE;
	WriteMemory((void *)0x004A784C, &nTmp, sizeof(BYTE));

	nTmp = FONT_SIZE;
	WriteMemory((void *)0x004A7923, &nTmp, sizeof(BYTE));

	nTmp = 0x12 - FONT_SIZE;
	WriteMemory((void *)0x008D3AFB, &nTmp, sizeof(BYTE));


	//hook 相关地址
	SetTextHook();
	SetFuncHook();
	return 0;
#undef FONT_SIZE
}

#undef _LT_