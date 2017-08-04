// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
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





// TODO: 在此处引用程序需要的其他头文件

#pragma comment(lib, "WS2_32")	// 链接到WS2_32.lib
#pragma comment(lib,"iphlpapi.lib")

class CInitSock
{
public:
	CInitSock(BYTE minorVer = 2, BYTE majorVer = 2)
	{
		// 初始化WS2_32.dll
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