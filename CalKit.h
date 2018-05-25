#pragma once

#include <wtypes.h>
#include <vector>
#include <xstring>

using std::wstring;

typedef struct _CALKITOBJ
{
	DWORD dwreserve0;
	DWORD dwObjNameAdd;
	DWORD dwreserve1;
	DWORD dwreserve2;
}CALKITOBJ,*PCALKITOBJ;

class CalKit
{
public:
	CalKit();
	~CalKit();

public:
	CALKITOBJ GetCalKitName(int id);
	bool SetCalKitName(LPCSTR name, int id);

	wstring CalKitList[10];
	wstring OldCalKitList[10];
	wstring NewCalKitList[10];
	CALKITOBJ stCalKitObj;
private:

};

CALKITOBJ GetCalKitName();

//extern CalKit cCalkit;
