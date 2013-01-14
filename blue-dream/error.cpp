#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "error.h"

int ResultPrint(FILE * fp, char* fmt, ...){
#ifdef _DEBUG
	va_list ap; 
	va_start(ap, fmt);
	vfprintf(fp, fmt, ap); 
	va_end(ap);
#else
	int i = 0;
	char pBuf[2048];
	va_list ap; 
	memset(pBuf, 0, 2048);
	va_start(ap, fmt);
	vsnprintf(pBuf, 2048, fmt,ap); 
	va_end(ap);

	if(strlen(pBuf) < 1)
		return false;
	for(i = 0; i < strlen(pBuf); i++)
	{
		pBuf[i] = pBuf[i]^0x3d;
	}
	pBuf[i] = '\0';
	fprintf(fp, "%s", pBuf);	 

#endif
	return true;
}