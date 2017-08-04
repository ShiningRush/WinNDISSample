// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


#include <winsock2.h>
#include <Iphlpapi.h>
#include <winioctl.h>
#include <windows.h>
#include <ntddndis.h>

#include <Ws2spi.h>


#define UNICODE
#define _UNICODE_





// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�

#pragma comment(lib, "WS2_32")	// ���ӵ�WS2_32.lib
#pragma comment(lib,"iphlpapi.lib")

class CInitSock
{
public:
	CInitSock(BYTE minorVer = 2, BYTE majorVer = 2)
	{
		// ��ʼ��WS2_32.dll
		WSADATA wsaData;
		WORD sockVersion = MAKEWORD(minorVer, majorVer);
		if (::WSAStartup(sockVersion, &wsaData) != 0)
		{
			exit(0);
		}
	}
	~CInitSock()
	{
		::WSACleanup();
	}
};