
#include "strfunc.h"

UINT8 str_len(UINT8 *str)
{
	return strlen((const char *)str);
}

/*
功能:
	实现字符串复制，防越界
入参:
	dstStr:目的字符串
	resStr:源字符串 
	dstLen:目的字符串长度 sizeof获得的长度
	cpyLen:复制长度 strlen获得的长度
返回值:
	TRUE:成功
	FALSE:失败
*/
UINT8 str_cpy(char *dstStr,const char *resStr,UINT32 dstLen,UINT32 cpyLen)
{
	UINT32 CpyLen,ResRealLen;
	
	if(NULL == dstStr || NULL == resStr)
		return FALSE;
	if(2 > dstLen)
		return TRUE;
	
	ResRealLen = strlen(resStr);
	CpyLen = (ResRealLen > cpyLen) ? cpyLen : ResRealLen;
	if(CpyLen > (dstLen - 1))
		CpyLen = dstLen - 1;
	
	memcpy(dstStr,resStr,CpyLen);
	dstStr[CpyLen] = 0;
	return TRUE;
}

/*
功能:
	实现内存拷贝，防越界，不负责memset
入参:
	dstStr:目的地址
	resStr:源地址
	dstLen:目的地址长度 sizeof()获得的长度
	cpyLen:复制长度 sizeof()获得的长度
返回值:
	TRUE:成功
	FALSE:失败
*/

UINT8 mem_cpy(UINT8 *dstMem,const char *resMem,UINT32 dstLen,UINT32 cpyLen)
{
	UINT32 CpyLen;
	
	if(NULL == dstMem || NULL == resMem || dstLen < cpyLen)
		return FALSE;
	
	CpyLen = (dstLen > cpyLen) ? cpyLen : dstLen;
	
	memcpy(dstMem,resMem,CpyLen);
	return TRUE;
}


/*
功能:
	实现字符串追加，防越界
入参:
	dstStr:目的字符串
	resStr:源字符串 
	dstLen:目的字符串长度 sizeof()获得的长度
	cpyLen:追加长度 strlen()获得的长度
返回值:
	TRUE:成功
	FALSE:失败
*/
UINT8 str_cat(char *dstStr,const char *resStr,UINT32 dstLen,UINT32 cpyLen)
{
	UINT32 CatLen,DstRealLen,ResRealLen;
	
	if(NULL == dstStr || NULL == resStr)
		return FALSE;

	DstRealLen = strlen(dstStr);
	if(DstRealLen >= dstLen - 1)
		return TRUE;
	
	ResRealLen = (strlen(resStr) > cpyLen) ? cpyLen : strlen(resStr);
	CatLen = ((dstLen - DstRealLen-1) > ResRealLen) ? 
		ResRealLen : (dstLen - DstRealLen-1);

	
	memcpy(dstStr+DstRealLen,resStr,CatLen);
	dstStr[DstRealLen+CatLen] = '\0';
	return TRUE;
}


/*
功能:
	查找字符串左边第一个为resChar字符的位置
入参:
	dstStr:目的字符串
	resChar:目的字符
返回值:
	目的字符距首字符长度,若不存在返回0xffff
*/
UINT16 str_ischar_left(const char* const dstStr,char resChar)
{
	UINT16 i;
	
	if(NULL == dstStr)
		return FULL_UINT16;

	for(i=0;i<strlen(dstStr);i++)
	{
		if(resChar == dstStr[i])
		{
			return i;
		}
	}

	return FULL_UINT16;
}


/*
功能:
	查找字符串左边第一个不为resChar字符的位置
入参:
	dstStr:目的字符串
	resChar:目的字符
返回值:
	目的字符距首字符第一个不为resChar的索引
*/
UINT16 str_isnotchar_left(const char* const dstStr,char resChar)
{
	UINT16 i;
	
	if(NULL == dstStr)
		return FULL_UINT16;

	for(i=0;i<strlen(dstStr);i++)
	{
		if(resChar != dstStr[i])
		{
			return i;
		}
	}

	return FULL_UINT16;
}


/*
功能:
	查找字符串右边第一个为resChar字符的位置
入参:
	dstStr:目的字符串
	resStr:目的字符
返回值:
	目的字符距首字符长度,若不存在返回0xffff
*/
UINT16 str_ischar_right(const char* const dstStr,char resChar)
{
	UINT16 StrLen;
	
	if(NULL == dstStr)
		return FULL_UINT16;

	StrLen = strlen(dstStr);
	if(1 > StrLen)
		return FULL_UINT16;

	do
	{
		StrLen--;
		if(resChar == dstStr[StrLen])
		{
			return StrLen;
		}

	}while(StrLen);
	return FULL_UINT16;
}


/*
功能:
	查找字符串右边第一个不为resChar字符的位置
入参:
	dstStr:目的字符串
	resStr:目的字符
返回值:
	目的字符距首字符长度,若不存在返回0xffff
*/
UINT16 str_isnotchar_right(const char* const dstStr,char resChar)
{
	UINT16 StrLen;
	
	if(NULL == dstStr)
		return FULL_UINT16;

	StrLen = strlen(dstStr);
	if(1 > StrLen)
		return FULL_UINT16;

	do
	{
		StrLen--;
		if(resChar != dstStr[StrLen])
		{
			return StrLen;
		}

	}while(StrLen);
	return FULL_UINT16;
}


/*
功能:
	清除字符串右侧空格
入参:
	dstStr:目的字符串
*/
void str_trim_right(char* const dstStr)
{
	UINT16 StrLen;
	
	if(NULL == dstStr)
		return;

	StrLen = strlen(dstStr);
	if(1 > StrLen)
		return;
	
	do 
	{
		StrLen--;
		if(' ' == dstStr[StrLen])
			dstStr[StrLen] = 0;
		else
			return;
	}while(StrLen);
	return;
}


/*
功能:
	清除字符串左侧空格
入参:
	dstStr:目的字符串
*/
void str_trim_left(char* const dstStr)
{
	UINT16 i,StrLen;
	
	if(NULL == dstStr)
		return;

	StrLen = strlen(dstStr);
	for(i=0;i<StrLen;i++)
	{
		if(' ' != dstStr[i])
			break;
	}

	if(0 == i)
		return;
	memmove(dstStr,dstStr+i,StrLen-i);
	dstStr[StrLen-i] = 0;

	return;
}


/*
功能:
	清除字符串两侧空格
入参:
	dstStr:目的字符串
*/
void str_trim(char* const dstStr)
{	
	if(NULL == dstStr)
		return;

	str_trim_right(dstStr);
	str_trim_left(dstStr);

	return;
}

/*
功能:
	字符串比较
入参:
	dstStr:目的字符串
	resStr:源字符串 
	cmptype:是否大小写敏感
返回值:
	TURE:相等
	FALSE:不相等
*/
UINT8 str_cmp(const char* const dstStr,const char* const resStr,e_CmpType cmptype)
{	
	if(NULL == dstStr || NULL == resStr)
		return;

	switch(cmptype)
	{
		case case_insensit:
			return (0 == strcasecmp(dstStr,resStr));
		case case_sensit:
			return (0 == strcmp(dstStr,resStr));
	}

	return (0 == strcmp(dstStr,resStr));
}







