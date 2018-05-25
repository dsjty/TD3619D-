#pragma once

#ifndef _INC_WINDOWS
#include <Windows.h>
#endif

//菜单按钮宽度和高度;
#define BtnWidth_W	10
#define BtnHeith_H  24

#define BtnHeith_H2  40
#define BtnHeith_Root	34


//画笔句柄
extern HPEN hPen_Gray;

//画刷句柄
extern HBRUSH hPatternBrush_LtBlue;
extern HBRUSH hBrush_Light;
extern HBRUSH hBrush_LightGreen;
extern HBRUSH hBrush_Dark, hCalDlg_bk;

//新UI默认字体
extern HFONT hFont_cfg1, hFont_cfg2;      //字体配置1

//设置输入框类型的定义
#define ITID_UNKNOWN                    0       //未知, 交由原程序处理
#define ITID_GMK                        1       //响应GMk
#define ITID_NUM                        2       //响应num
#define ITID_TEXT                       3       //输入框是文本输入框 (交由原程序处理)
#define ITID_PW_GMK                     4       //浮动输入框的GMk

//曲线配置位图在原程序的资源Id
#define IDB_BMP_X1                      156
#define IDB_BMP_X2_1                    163
#define IDB_BMP_X2_2                    158
#define IDB_BMP_X2_3                    162
#define IDB_BMP_X2_4                    157
#define IDB_BMP_X3_1                    168
#define IDB_BMP_X3_2                    159
#define IDB_BMP_X3_3                    175
#define IDB_BMP_X3_4                    176
#define IDB_BMP_X3_5                    173
#define IDB_BMP_X3_6                    164
#define IDB_BMP_X4_1                    171
#define IDB_BMP_X4_2                    160
#define IDB_BMP_X4_3                    166


#define GET_BYTE_0(n)           ((BYTE)(((DWORD_PTR)(n)) & 0xff))
#define GET_BYTE_1(n)           ((BYTE)((((DWORD_PTR)(n)) >> 8) & 0xff))
#define GET_BYTE_2(n)           ((BYTE)((((DWORD_PTR)(n)) >> 16) & 0xff))
#define GET_BYTE_3(n)           ((BYTE)((((DWORD_PTR)(n)) >> 24) & 0xff))


#define CHK_FLAGS(v, f)         (((v) & (f)) == (f))
#define CHK_NOFLAGS(v, f)       (((v) & (f)) != (f))
#define CHK_EMPTY(v, f)         (((v) & (f)) == 0)
#define CHK_NONEMPTY(v, f)      (((v) & (f)) != 0)
#define SET_FLAGS(v, f)         ((v) |= (f))
#define NOT_FLAGS(v, f)         ((v) &= ~(f))

#define INC_SUBTEXT             L"%s\r\n%s"
#define INVALID_INDEX           (DWORD)-1


#define ComboBox_AddStringW(hwndCtl, lpsz)  \
((int)(DWORD)::SendMessageW((hwndCtl), CB_ADDSTRING, 0L, (LPARAM)(LPCWSTR)(lpsz)))

#define ComboBox_InsertStringW(hwndCtl, index, lpsz)  \
((int)(DWORD)::SendMessageW((hwndCtl), CB_INSERTSTRING, (WPARAM)(int)(index), (LPARAM)(LPCWSTR)(lpsz)))

#define ComboBox_DeleteAll(hwnd)  \
	while ((int)SNDMSG((HWND)(hwnd), CB_DELETESTRING , 0, 0) > 0) {} 


extern DWORD dwBaseAdd;

#define BASE										dwBaseAdd

#define TA_ROOT										(void *)(BASE+0xD7CD4C)
#define CA_ROOT										(void *)(BASE+0x163AC88)

//Preset
#define TA_PRESET									(void *)(BASE+0xD820F4)
#define CA_PRESET									(void *)(BASE+0x163CA68)


//Analysis
#define TA_ANALYSIS									(void *)(BASE+0xD74D44)
#define CA_ANALYSIS									(void *)(BASE+0x1636DC0)

//Analysis::Fixtre SiMulator
#define TA_ANALY_FIXSIM								(void)(BASE+0xD74D74)
#define CA_ANALY_FIXSIM								(void)(BASE+0x16366E0)

//Analysis::Fixtre SiMulator::Topology
#define TA_ANALY_FIXSIM_TOPO						(void)(BASE+0xD74EE0)
#define CA_ANALY_FIXSIM_TOPO						(void)(BASE+0x1636488)

//Analysis::Fixtre SiMulator::Topology::Device
#define TA_ANALY_FIXSIM_TOPO_DEV					(void)(BASE+0xD7507C)
#define CA_ANALY_FIXSIM_TOPO_DEV					(void)(BASE+0x1636420)

//Analysis::Fixtre SiMulator::Topology::Port1
#define TA_ANALY_FIXSIM_TOPO_P1						(void)(BASE+0xD75004)
#define CA_ANALY_FIXSIM_TOPO_p1						(void)(BASE+0x16363C0)

//Analysis::Fixtre SiMulator::Topology::Port2
#define TA_ANALY_FIXSIM_TOPO_P2						(void)(BASE+0xD74F8C)
#define CA_ANALY_FIXSIM_TOPO_p2						(void)(BASE+0x1636300)

//Analysis::Fixtre SiMulator::Topology::Port3
#define TA_ANALY_FIXSIM_TOPO_P3						(void)(BASE+0xD74FC8)	 
#define CA_ANALY_FIXSIM_TOPO_p3							//未找到，需要4端口仪器配合

//Analysis::Fixtre SiMulator::Port Matching
#define TA_ANALY_FIXSIM_PMATCH						(void)(BASE+0xD74DA4)
#define CA_ANALY_FIXSIM_PMATCH						(void)(BASE+0x1636120)

//Analysis::Fixtre SiMulator::Port Matching::Select Port
#define TA_ANALY_FIXSIM_SELPORT						(void)(BASE+0xD74DD4)
#define CA_ANALY_FIXSIM_SELPORT						(void)(BASE+0x16360C0)

//Analysis::Fixtre SiMulator::Port Matching::Select Circuit
#define TA_ANALY_FIXSIM_SELCIR						(void)(BASE+0xD769E0)
#define CA_ANALY_FIXSIM_SELCIR						(void)(BASE+0x1637000)

//Analysis::Fixtre SiMulator::Port ZConversion
#define TA_ANALY_FIXSIM_PZCON						(void)(BASE+0xD750BC)
#define CA_ANALY_FIXSIM_PZCON						(void)(BASE+0x16364F0)

//Analysis::Fixtre SiMulator::De-Embedding
#define TA_ANALY_FIXSIM_DeEMBED						(void)(BASE+0xD74E14)
#define CA_ANALY_FIXSIM_DeEMBED						(void)(BASE+0x1636180)

//Analysis::Fixtre SiMulator::De-Embedding::SelectPort
#define TA_ANALY_FIXSIM_DeEMBED_SELPORT				(void)(BASE+0xD74DD4)
#define CA_ANALY_FIXSIM_DeEMBED_SELPORT				(void)(BASE+0x16360C0)

//Analysis::Fixtre SiMulator::De-Embedding::SelectType
#define TA_ANALY_FIXSIM_DeEMBED_SELTYPE				(void)(BASE+0xD76AAC)
#define CA_ANALY_FIXSIM_DeEMBED_SELTYPE				(void)(BASE+0x1637110)

//Analysis::Fixtre SiMulator::Diff Matching
#define TA_ANALY_FIXSIM_DIFFMAT						(void)(BASE+0xD750EC)
#define CA_ANALY_FIXSIM_DIFFMAT						(void)(BASE+0x16365B0)

//Analysis::Fixtre SiMulator::Diff Matching::Select Bal Port
#define TA_ANALY_FIXSIM_DIFFMAT_SBP					(void)(BASE+0xD7511C)
#define CA_ANALY_FIXSIM_DIFFMAT_SBP					(void)(BASE+0x1636550)

//Analysis::Fixtre SiMulator::Diff Matching::Select Circuit
#define TA_ANALY_FIXSIM_DIFFMAT_SC					(void)(BASE+0xD76A3C)
#define CA_ANALY_FIXSIM_DIFFMAT_SC					(void)(BASE+0x1637088)

//Analysis::Fixtre SiMulator::Diff ZConversion
#define TA_ANALY_FIXSIM_DIFFZCON					(void)(BASE+0xD7515C)
#define CA_ANALY_FIXSIM_DIFFZCON					(void)(BASE+0x1636610)

//Analysis::Fixtre SiMulator::Cmn ZConversion
#define TA_ANALY_FIXSIM_CMNZCON						(void)(BASE+0xD7519C)
#define CA_ANALY_FIXSIM_CMNZCON						(void)(BASE+0x1636678)

//Analysis::Fixtre SiMulator::De-Embedding SnP
#define TA_ANALY_FIXSIM_DeEmSNP						(void)(BASE+0xD74E44)
#define CA_ANALY_FIXSIM_DeEmSNP						(void)(BASE+0x1636240)

//Analysis::Fixtre SiMulator::De-Embedding SnP::Topology
#define TA_ANALY_FIXSIM_DeEmSNP_TOPG				(void)(BASE+0xD74E74)
#define CA_ANALY_FIXSIM_DeEmSNP_TOPG				(void)(BASE+0x16361E0)

//Analysis::Fixtre SiMulator::De-Embedding SnP::Topology::Select Topology
#define TA_ANALY_FIXSIM_DeEmSNP_TOPG_SELTOP			(void)(BASE+0xD76B10)
#define CA_ANALY_FIXSIM_DeEmSNP_TOPG_SELTOP			(void)(BASE+0x1637198)

//Analysis::Fixtre SiMulator::De-Embedding SnP::Topology::Ports
#define TA_ANALY_FIXSIM_DeEmSNP_TOPG_PORTS			(void)(BASE+0xD757E4)
#define CA_ANALY_FIXSIM_DeEmSNP_TOPG_PORTS 			(void)(BASE+0x1636E20)

//Analysis::Fixtre SiMulator::De-Embedding SnP::Topology::Type(nwk1)
#define TA_ANALY_FIXSIM_DeEmSNP_TOPG_TYPE1			(void)(BASE+0xD76B68)
#define CA_ANALY_FIXSIM_DeEmSNP_TOPG_TYPE1 			(void)(BASE+0x1637218)

//Analysis::Fixtre SiMulator::De-Embedding SnP::Topology::Type(nwk2)
#define TA_ANALY_FIXSIM_DeEmSNP_TOPG_TYPE2			(void)(BASE+0xD76BD0)
#define CA_ANALY_FIXSIM_DeEmSNP_TOPG_TYPE2 			(void)(BASE+0x1637288)

//Analysis::Fixtre SiMulator::De-Embedding SnP::Topology::Type(nwk3)
#define TA_ANALY_FIXSIM_DeEmSNP_TOPG_TYPE3			(void)(BASE+0xD76C38)
#define CA_ANALY_FIXSIM_DeEmSNP_TOPG_TYPE3 			(void)(BASE+0x16372F8)

//Analysis::Fixtre SiMulator::De-Embedding SnP::Topology::Type(nwk4)
#define TA_ANALY_FIXSIM_DeEmSNP_TOPG_TYPE4			(void)(BASE+0xD76CA0)
#define CA_ANALY_FIXSIM_DeEmSNP_TOPG_TYPE4 			(void)(BASE+0x1637368)

//Analysis::Gating
#define TA_ANALY_GATING								(void)(BASE+0xD751E0)
#define CA_ANALY_GATING 							(void)(BASE+0x16367A0)

//Analysis::Gating::Shape
#define TA_ANALY_GATING_SHAPE						(void)(BASE+0xD76D40)
#define CA_ANALY_GATING_SHAPE 						(void)(BASE+0x16373D8)

//Analysis::Transform
#define TA_ANALY_TRANSFORM							(void)(BASE+0xD75218)
#define CA_ANALY_TRANSFORM 							(void)(BASE+0x1636808)

//Analysis::Transform::Type
#define TA_ANALY_TRANSFORM_TYPE						(void)(BASE+0xD76DB8)
#define CA_ANALY_TRANSFORM_TYPE	 					(void)(BASE+0x1637458)

//Analysis::Transform::Windows
#define TA_ANALY_TRANSFORM_WINDOWS					(void)(BASE+0xD75248)
#define CA_ANALY_TRANSFORM_WINDOWS	 				(void)(BASE+0x1636740)

//Analysis::Conversion
#define TA_ANALY_CONVER								(void)(BASE+0xD755BC)
#define CA_ANALY_CONVER				 				(void)(BASE+0x1636740)

//Analysis::Conversion::Function
#define TA_ANALY_CONVER_FUN							(void)(BASE+0xD755EC)
#define CA_ANALY_CONVER_FUN				 			(void)(BASE+0x1636D00)

//Analysis::Limit Test
#define TA_LIMITTEST								(void *)(BASE+0xD7528C)
#define CA_LIMITTEST								(void *)(BASE+0x1636990)

//Analysis::Limit Test::Edit Limit Line
#define TA_LT_ELL									(void *)(BASE+0xD75300)
#define CA_LT_ELL									(void *)(BASE+0x1636930)

//Analysis::Limit Test::Edit Limit Line::Clear Limit Table
#define TA_LT_ELL_CLT								(void *)(BASE+0xD75330)
#define CA_LT_ELL_CLT								(void *)(BASE+0x1636868)

//Analysis::Limit Test::Limit Line Offsets
#define TA_LT_LLO									(void *)(BASE+0xD752BC)
#define CA_LT_LLO									(void *)(BASE+0x16368D0)

//Analysis::Ripple Limit
#define TA_RIPPLELIMIT								(void *)(BASE+0xD75394)
#define CA_RIPPLELIMIT								(void *)(BASE+0x1636B78)

//Analysis::Ripple Limit::Ripple Value
#define TA_RL_RV									(void *)(BASE+0xD75454)
#define CA_RL_RV									(void *)(BASE+0x1636AB8)

//Analysis::Ripple Limit::Ripple Band
#define TA_RL_RBW									(void *)(BASE+0xD754A8)
#define CA_RL_RBW									(void *)(BASE+0x1636B18)

//Analysis::Ripple Limit::Edit Ripple Limit					 
#define TA_RL_ERL									(void *)(BASE+0xD753C4)
#define CA_RL_ERL									(void *)(BASE+0x1636A58)

//Analysis::Ripple Limit::Clear Ripple Limit Table			 
#define TA_RL_ERL_CRLT								(void *)(BASE+0xD753F4)
#define CA_RL_ERL_CRLT								(void *)(BASE+0x16369F0)

//Analysis::Bandwidth Limit									 
#define TA_BWLIMIT									(void *)(BASE+0xD75D84)
#define CA_BWLIMIT									(void *)(BASE+0x1636E80)

//Analysis::Point Limit										 
#define TA_POINTLIMIT								(void *)(BASE+0xD754F4)
#define CA_POINTLIMIT								(void *)(BASE+0x1636CA0)

//Analysis::Point Limit::Edit Point Limit					 
#define TA_POINTLIMIT_EPL							(void *)(BASE+0xD75524)
#define CA_POINTLIMIT_EPL							(void *)(BASE+0x1636C40)

//Analysis::Point Limit::Clear Point Limit Table			 
#define TA_POINTLIMIT_CPLT							(void *)(BASE+0xD75554)
#define CA_POINTLIMIT_CPLT							(void *)(BASE+0x1636BD8)



////Fault Location
#define CA_FAULTLOC							(void *)0x00A097C4
#define TA_FAULTLOC							(void *)0x00BC84E0

//Fault Location :: Type
#define CA_FL_TYPE							(void *)0x00A09824
#define TA_FL_TYPE							(void *)0x00BC8400

//Fault Location :: Unit
#define CA_FL_UNIT							(void *)0x00A09854
#define TA_FL_UNIT							(void *)0x00BC83A0

//Fault Location :: Window
#define CA_FL_WIND							(void *)0x00A097F4
#define TA_FL_WIND							(void *)0x00BC8480

//SRL
#define CA_SRL								(void *)0x00A098AC
#define TA_SRL								(void *)0x00BC8540

//FSRL :: Port X Connector
#define CA_SRL_PXC							(void *)0x00A098DC

//Conversion
#define CA_CONV								(void *)0x00A09BA4
#define TA_CONV								(void *)0x00BC85A0

//Conversion :: Function
#define CA_CONV_FN							(void *)0x00A09BD4
#define TA_CONV_FN							(void *)0x00BC8080


//Display
#define CA_DISPLAY									(void *)(BASE+0x16397D8)
#define TA_DISPLAY									(void *)(BASE+0xD798B4)

//Display :: Diaplay
#define CA_DISPLAY_DP								(void *)(BASE+0x16396B8)
#define TA_DISPLAY_DP								(void *)(BASE+0xD79924 )

//Display :: Data Math
#define CA_DISPLAY_DM								(void *)(BASE+0x1639718	)
#define TA_DISPLAY_DM								(void *)(BASE+0xD79974	)

//Display ::Alloc Channels
//#define FAI_TRACESCFG								  (void *)0x00536BE0
#define FA_TRACESCFG								(void *)(BASE+0x0040C460)       //retn
#define CA_ALLOCTRACES								(void *)(BASE+0x1639838)      //0x00536F80
#define TA_ALLOCTRACES								(void *)(BASE+0xD79C88)

//Display ::Num of Traces
#define FA_TRACESNUM								(void *)(BASE+0x0040C460)        //retn
#define CA_TRACESNUM								(void *)(BASE+0x1639658)        //0x00538C50
#define TA_TRACESNUM								(void *)(BASE+0xD798E4)

//Display ::Alloc Channels
#define CA_ALLOCCHAN								(void *)(BASE+0x16398A8)
#define TA_ALLOCCHAN								(void *)(BASE+0xD79D18)

//Display ::Data Hold
#define CA_DISPLAY_DH								(void *)(BASE+0x1639778)
#define TA_DISPLAY_DH								(void *)(BASE+0xD799E0)



//Trigger 
#define CA_TRIGGER									(void *)(BASE+0x163D298)
#define TA_TRIGGER									(void *)(BASE+0xD834C4)

//Trigger :: Trigger Source
#define CA_TRIGGER_TS								(void *)(BASE+0x163D238)
#define TA_TRIGGER_TS								(void *)(BASE+0xD834F4)


extern DWORD dwBaseAdd;

#define BASE										dwBaseAdd

#define TA_ROOT										(void *)(BASE+0xD7CD4C)
#define CA_ROOT										(void *)(BASE+0x163AC88)

//Preset
#define TA_PRESET									(void *)(BASE+0xD820F4)
#define CA_PRESET									(void *)(BASE+0x163CA68)


//Analysis
#define TA_ANALYSIS									(void *)(BASE+0xD74D44)
#define CA_ANALYSIS									(void *)(BASE+0x1636DC0)

//Analysis::Fixtre SiMulator
#define TA_ANALY_FIXSIM								(void)(BASE+0xD74D74)
#define CA_ANALY_FIXSIM								(void)(BASE+0x16366E0)

//Analysis::Fixtre SiMulator::Topology
#define TA_ANALY_FIXSIM_TOPO						(void)(BASE+0xD74EE0)
#define CA_ANALY_FIXSIM_TOPO						(void)(BASE+0x1636488)

//Analysis::Fixtre SiMulator::Topology::Device
#define TA_ANALY_FIXSIM_TOPO_DEV					(void)(BASE+0xD7507C)
#define CA_ANALY_FIXSIM_TOPO_DEV					(void)(BASE+0x1636420)

//Analysis::Fixtre SiMulator::Topology::Port1
#define TA_ANALY_FIXSIM_TOPO_P1						(void)(BASE+0xD75004)
#define CA_ANALY_FIXSIM_TOPO_p1						(void)(BASE+0x16363C0)

//Analysis::Fixtre SiMulator::Topology::Port2
#define TA_ANALY_FIXSIM_TOPO_P2						(void)(BASE+0xD74F8C)
#define CA_ANALY_FIXSIM_TOPO_p2						(void)(BASE+0x1636300)

//Analysis::Fixtre SiMulator::Topology::Port3
#define TA_ANALY_FIXSIM_TOPO_P3						(void)(BASE+0xD74FC8)	 
#define CA_ANALY_FIXSIM_TOPO_p3							//未找到，需要4端口仪器配合

//Analysis::Fixtre SiMulator::Port Matching
#define TA_ANALY_FIXSIM_PMATCH						(void)(BASE+0xD74DA4)
#define CA_ANALY_FIXSIM_PMATCH						(void)(BASE+0x1636120)

//Analysis::Fixtre SiMulator::Port Matching::Select Port
#define TA_ANALY_FIXSIM_SELPORT						(void)(BASE+0xD74DD4)
#define CA_ANALY_FIXSIM_SELPORT						(void)(BASE+0x16360C0)

//Analysis::Fixtre SiMulator::Port Matching::Select Circuit
#define TA_ANALY_FIXSIM_SELCIR						(void)(BASE+0xD769E0)
#define CA_ANALY_FIXSIM_SELCIR						(void)(BASE+0x1637000)

//Analysis::Fixtre SiMulator::Port ZConversion
#define TA_ANALY_FIXSIM_PZCON						(void)(BASE+0xD750BC)
#define CA_ANALY_FIXSIM_PZCON						(void)(BASE+0x16364F0)

//Analysis::Fixtre SiMulator::De-Embedding
#define TA_ANALY_FIXSIM_DeEMBED						(void)(BASE+0xD74E14)
#define CA_ANALY_FIXSIM_DeEMBED						(void)(BASE+0x1636180)

//Analysis::Fixtre SiMulator::De-Embedding::SelectPort
#define TA_ANALY_FIXSIM_DeEMBED_SELPORT				(void)(BASE+0xD74DD4)
#define CA_ANALY_FIXSIM_DeEMBED_SELPORT				(void)(BASE+0x16360C0)

//Analysis::Fixtre SiMulator::De-Embedding::SelectType
#define TA_ANALY_FIXSIM_DeEMBED_SELTYPE				(void)(BASE+0xD76AAC)
#define CA_ANALY_FIXSIM_DeEMBED_SELTYPE				(void)(BASE+0x1637110)

//Analysis::Fixtre SiMulator::Diff Matching
#define TA_ANALY_FIXSIM_DIFFMAT						(void)(BASE+0xD750EC)
#define CA_ANALY_FIXSIM_DIFFMAT						(void)(BASE+0x16365B0)

//Analysis::Fixtre SiMulator::Diff Matching::Select Bal Port
#define TA_ANALY_FIXSIM_DIFFMAT_SBP					(void)(BASE+0xD7511C)
#define CA_ANALY_FIXSIM_DIFFMAT_SBP					(void)(BASE+0x1636550)

//Analysis::Fixtre SiMulator::Diff Matching::Select Circuit
#define TA_ANALY_FIXSIM_DIFFMAT_SC					(void)(BASE+0xD76A3C)
#define CA_ANALY_FIXSIM_DIFFMAT_SC					(void)(BASE+0x1637088)

//Analysis::Fixtre SiMulator::Diff ZConversion
#define TA_ANALY_FIXSIM_DIFFZCON					(void)(BASE+0xD7515C)
#define CA_ANALY_FIXSIM_DIFFZCON					(void)(BASE+0x1636610)

//Analysis::Fixtre SiMulator::Cmn ZConversion
#define TA_ANALY_FIXSIM_CMNZCON						(void)(BASE+0xD7519C)
#define CA_ANALY_FIXSIM_CMNZCON						(void)(BASE+0x1636678)

//Analysis::Fixtre SiMulator::De-Embedding SnP
#define TA_ANALY_FIXSIM_DeEmSNP						(void)(BASE+0xD74E44)
#define CA_ANALY_FIXSIM_DeEmSNP						(void)(BASE+0x1636240)

//Analysis::Fixtre SiMulator::De-Embedding SnP::Topology
#define TA_ANALY_FIXSIM_DeEmSNP_TOPG				(void)(BASE+0xD74E74)
#define CA_ANALY_FIXSIM_DeEmSNP_TOPG				(void)(BASE+0x16361E0)

//Analysis::Fixtre SiMulator::De-Embedding SnP::Topology::Select Topology
#define TA_ANALY_FIXSIM_DeEmSNP_TOPG_SELTOP			(void)(BASE+0xD76B10)
#define CA_ANALY_FIXSIM_DeEmSNP_TOPG_SELTOP			(void)(BASE+0x1637198)

//Analysis::Fixtre SiMulator::De-Embedding SnP::Topology::Ports
#define TA_ANALY_FIXSIM_DeEmSNP_TOPG_PORTS			(void)(BASE+0xD757E4)
#define CA_ANALY_FIXSIM_DeEmSNP_TOPG_PORTS 			(void)(BASE+0x1636E20)

//Analysis::Fixtre SiMulator::De-Embedding SnP::Topology::Type(nwk1)
#define TA_ANALY_FIXSIM_DeEmSNP_TOPG_TYPE1			(void)(BASE+0xD76B68)
#define CA_ANALY_FIXSIM_DeEmSNP_TOPG_TYPE1 			(void)(BASE+0x1637218)

//Analysis::Fixtre SiMulator::De-Embedding SnP::Topology::Type(nwk2)
#define TA_ANALY_FIXSIM_DeEmSNP_TOPG_TYPE2			(void)(BASE+0xD76BD0)
#define CA_ANALY_FIXSIM_DeEmSNP_TOPG_TYPE2 			(void)(BASE+0x1637288)

//Analysis::Fixtre SiMulator::De-Embedding SnP::Topology::Type(nwk3)
#define TA_ANALY_FIXSIM_DeEmSNP_TOPG_TYPE3			(void)(BASE+0xD76C38)
#define CA_ANALY_FIXSIM_DeEmSNP_TOPG_TYPE3 			(void)(BASE+0x16372F8)

//Analysis::Fixtre SiMulator::De-Embedding SnP::Topology::Type(nwk4)
#define TA_ANALY_FIXSIM_DeEmSNP_TOPG_TYPE4			(void)(BASE+0xD76CA0)
#define CA_ANALY_FIXSIM_DeEmSNP_TOPG_TYPE4 			(void)(BASE+0x1637368)

//Analysis::Gating
#define TA_ANALY_GATING								(void)(BASE+0xD751E0)
#define CA_ANALY_GATING 							(void)(BASE+0x16367A0)

//Analysis::Gating::Shape
#define TA_ANALY_GATING_SHAPE						(void)(BASE+0xD76D40)
#define CA_ANALY_GATING_SHAPE 						(void)(BASE+0x16373D8)

//Analysis::Transform
#define TA_ANALY_TRANSFORM							(void)(BASE+0xD75218)
#define CA_ANALY_TRANSFORM 							(void)(BASE+0x1636808)

//Analysis::Transform::Type
#define TA_ANALY_TRANSFORM_TYPE						(void)(BASE+0xD76DB8)
#define CA_ANALY_TRANSFORM_TYPE	 					(void)(BASE+0x1637458)

//Analysis::Transform::Windows
#define TA_ANALY_TRANSFORM_WINDOWS					(void)(BASE+0xD75248)
#define CA_ANALY_TRANSFORM_WINDOWS	 				(void)(BASE+0x1636740)

//Analysis::Conversion
#define TA_ANALY_CONVER								(void)(BASE+0xD755BC)
#define CA_ANALY_CONVER				 				(void)(BASE+0x1636740)

//Analysis::Conversion::Function
#define TA_ANALY_CONVER_FUN							(void)(BASE+0xD755EC)
#define CA_ANALY_CONVER_FUN				 			(void)(BASE+0x1636D00)

//Analysis::Limit Test
#define TA_LIMITTEST								(void *)(BASE+0xD7528C)
#define CA_LIMITTEST								(void *)(BASE+0x1636990)

//Analysis::Limit Test::Edit Limit Line
#define TA_LT_ELL									(void *)(BASE+0xD75300)
#define CA_LT_ELL									(void *)(BASE+0x1636930)

//Analysis::Limit Test::Edit Limit Line::Clear Limit Table
#define TA_LT_ELL_CLT								(void *)(BASE+0xD75330)
#define CA_LT_ELL_CLT								(void *)(BASE+0x1636868)

//Analysis::Limit Test::Limit Line Offsets
#define TA_LT_LLO									(void *)(BASE+0xD752BC)
#define CA_LT_LLO									(void *)(BASE+0x16368D0)

//Analysis::Ripple Limit
#define TA_RIPPLELIMIT								(void *)(BASE+0xD75394)
#define CA_RIPPLELIMIT								(void *)(BASE+0x1636B78)

//Analysis::Ripple Limit::Ripple Value
#define TA_RL_RV									(void *)(BASE+0xD75454)
#define CA_RL_RV									(void *)(BASE+0x1636AB8)

//Analysis::Ripple Limit::Ripple Band
#define TA_RL_RBW									(void *)(BASE+0xD754A8)
#define CA_RL_RBW									(void *)(BASE+0x1636B18)

//Analysis::Ripple Limit::Edit Ripple Limit					 
#define TA_RL_ERL									(void *)(BASE+0xD753C4)
#define CA_RL_ERL									(void *)(BASE+0x1636A58)

//Analysis::Ripple Limit::Clear Ripple Limit Table			 
#define TA_RL_ERL_CRLT								(void *)(BASE+0xD753F4)
#define CA_RL_ERL_CRLT								(void *)(BASE+0x16369F0)

//Analysis::Bandwidth Limit									 
#define TA_BWLIMIT									(void *)(BASE+0xD75D84)
#define CA_BWLIMIT									(void *)(BASE+0x1636E80)

//Analysis::Point Limit										 
#define TA_POINTLIMIT								(void *)(BASE+0xD754F4)
#define CA_POINTLIMIT								(void *)(BASE+0x1636CA0)

//Analysis::Point Limit::Edit Point Limit					 
#define TA_POINTLIMIT_EPL							(void *)(BASE+0xD75524)
#define CA_POINTLIMIT_EPL							(void *)(BASE+0x1636C40)

//Analysis::Point Limit::Clear Point Limit Table			 
#define TA_POINTLIMIT_CPLT							(void *)(BASE+0xD75554)
#define CA_POINTLIMIT_CPLT							(void *)(BASE+0x1636BD8)



////Fault Location
#define CA_FAULTLOC							(void *)0x00A097C4
#define TA_FAULTLOC							(void *)0x00BC84E0

//Fault Location :: Type
#define CA_FL_TYPE							(void *)0x00A09824
#define TA_FL_TYPE							(void *)0x00BC8400

//Fault Location :: Unit
#define CA_FL_UNIT							(void *)0x00A09854
#define TA_FL_UNIT							(void *)0x00BC83A0

//Fault Location :: Window
#define CA_FL_WIND							(void *)0x00A097F4
#define TA_FL_WIND							(void *)0x00BC8480

//SRL
#define CA_SRL								(void *)0x00A098AC
#define TA_SRL								(void *)0x00BC8540

//FSRL :: Port X Connector
#define CA_SRL_PXC							(void *)0x00A098DC

//Conversion
#define CA_CONV								(void *)0x00A09BA4
#define TA_CONV								(void *)0x00BC85A0

//Conversion :: Function
#define CA_CONV_FN							(void *)0x00A09BD4
#define TA_CONV_FN							(void *)0x00BC8080


//Display
#define CA_DISPLAY									(void *)(BASE+0x16397D8)
#define TA_DISPLAY									(void *)(BASE+0xD798B4)

//Display :: Diaplay
#define CA_DISPLAY_DP								(void *)(BASE+0x16396B8)
#define TA_DISPLAY_DP								(void *)(BASE+0xD79924 )

//Display :: Data Math
#define CA_DISPLAY_DM								(void *)(BASE+0x1639718	)
#define TA_DISPLAY_DM								(void *)(BASE+0xD79974	)

//Display ::Alloc Channels
//#define FAI_TRACESCFG								  (void *)0x00536BE0
#define FA_TRACESCFG								(void *)(BASE+0x0040C460)       //retn
#define CA_ALLOCTRACES								(void *)(BASE+0x1639838)      //0x00536F80
#define TA_ALLOCTRACES								(void *)(BASE+0xD79C88)

//Display ::Num of Traces
#define FA_TRACESNUM								(void *)(BASE+0x0040C460)        //retn
#define CA_TRACESNUM								(void *)(BASE+0x1639658)        //0x00538C50
#define TA_TRACESNUM								(void *)(BASE+0xD798E4)

//Display ::Alloc Channels
#define CA_ALLOCCHAN								(void *)(BASE+0x16398A8)
#define TA_ALLOCCHAN								(void *)(BASE+0xD79D18)

//Display ::Data Hold
#define CA_DISPLAY_DH								(void *)(BASE+0x1639778)
#define TA_DISPLAY_DH								(void *)(BASE+0xD799E0)



//Trigger 
#define CA_TRIGGER									(void *)(BASE+0x163D298)
#define TA_TRIGGER									(void *)(BASE+0xD834C4)

//Trigger :: Trigger Source
#define CA_TRIGGER_TS								(void *)(BASE+0x163D238)
#define TA_TRIGGER_TS								(void *)(BASE+0xD834F4)




