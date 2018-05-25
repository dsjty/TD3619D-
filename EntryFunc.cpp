#include "stdafx.h"

BOOL WINAPI _CWnd__Create(CWnd *lpThis, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext);

void WINAPI _CWnd__OnSize_main(CWnd *lpThis, UINT nType, int cx, int cy);


NAKED int ef_CWnd__Create()
{
	__asm pop eax
	__asm push ecx
	__asm push eax
	__asm jmp _CWnd__Create
	__asm int 3
	__asm int 3
	__asm int 3
	__asm int 3
}

//0x0008AE219
NAKED void ef_CWnd__OnSize_main()
{
	__asm mov esp, ebp
	__asm pop ebp			//__asm add esp, 0x10
	__asm pop eax
	__asm push ecx
	__asm push eax
	__asm jmp _CWnd__OnSize_main
	__asm int 3
}