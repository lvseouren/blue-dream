// blue-dream.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "error.h"

#include "data_store.h"




int _tmain(int argc, _TCHAR* argv[])
{
	int count = 10000;
	ResultPrint(stdout, "this is a test command.\n");
	init_sqlite3_();

	while(count--){}
//	Sleep(200000);
	return 0;
}

