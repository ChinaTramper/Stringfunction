
#include "strfunc.h"

UINT8 str_len(UINT8 *str)
{
	return strlen((const char *)str);
}

/*
����:
	ʵ���ַ������ƣ���Խ��
���:
	dstStr:Ŀ���ַ���
	resStr:Դ�ַ��� 
	dstLen:Ŀ���ַ������� sizeof��õĳ���
	cpyLen:���Ƴ��� strlen��õĳ���
����ֵ:
	TRUE:�ɹ�
	FALSE:ʧ��
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
����:
	ʵ���ڴ濽������Խ�磬������memset
���:
	dstStr:Ŀ�ĵ�ַ
	resStr:Դ��ַ
	dstLen:Ŀ�ĵ�ַ���� sizeof()��õĳ���
	cpyLen:���Ƴ��� sizeof()��õĳ���
����ֵ:
	TRUE:�ɹ�
	FALSE:ʧ��
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
����:
	ʵ���ַ���׷�ӣ���Խ��
���:
	dstStr:Ŀ���ַ���
	resStr:Դ�ַ��� 
	dstLen:Ŀ���ַ������� sizeof()��õĳ���
	cpyLen:׷�ӳ��� strlen()��õĳ���
����ֵ:
	TRUE:�ɹ�
	FALSE:ʧ��
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
����:
	�����ַ�����ߵ�һ��ΪresChar�ַ���λ��
���:
	dstStr:Ŀ���ַ���
	resChar:Ŀ���ַ�
����ֵ:
	Ŀ���ַ������ַ�����,�������ڷ���0xffff
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
����:
	�����ַ�����ߵ�һ����ΪresChar�ַ���λ��
���:
	dstStr:Ŀ���ַ���
	resChar:Ŀ���ַ�
����ֵ:
	Ŀ���ַ������ַ���һ����ΪresChar������
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
����:
	�����ַ����ұߵ�һ��ΪresChar�ַ���λ��
���:
	dstStr:Ŀ���ַ���
	resStr:Ŀ���ַ�
����ֵ:
	Ŀ���ַ������ַ�����,�������ڷ���0xffff
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
����:
	�����ַ����ұߵ�һ����ΪresChar�ַ���λ��
���:
	dstStr:Ŀ���ַ���
	resStr:Ŀ���ַ�
����ֵ:
	Ŀ���ַ������ַ�����,�������ڷ���0xffff
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
����:
	����ַ����Ҳ�ո�
���:
	dstStr:Ŀ���ַ���
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
����:
	����ַ������ո�
���:
	dstStr:Ŀ���ַ���
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
����:
	����ַ�������ո�
���:
	dstStr:Ŀ���ַ���
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
����:
	�ַ����Ƚ�
���:
	dstStr:Ŀ���ַ���
	resStr:Դ�ַ��� 
	cmptype:�Ƿ��Сд����
����ֵ:
	TURE:���
	FALSE:�����
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







