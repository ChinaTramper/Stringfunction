#ifndef _STRFUNC_H_
	#define _STRFUNC_H_ 
#endif 

#include "typedef.h"
#include <stdio.h>
#include <string.h>

typedef enum CmpType
{
	case_insensit = 0,
	case_sensit
}e_CmpType;


extern UINT8 str_cpy(char *dstStr,const char *resStr,UINT32 dstLen,UINT32 cpyLen);
extern UINT8 str_cat(char *dstStr,const char *resStr,UINT32 dstLen,UINT32 cpyLen);
extern UINT16 str_ischar_left(const char* const dstStr,char resChar);
extern UINT16 str_isnotchar_left(const char* const dstStr,char resChar);
extern UINT16 str_ischar_right(const char* const dstStr,char resChar);
extern UINT16 str_isnotchar_right(const char* const dstStr,char resChar);
extern void str_trim_right(char* const dstStr);
extern void str_trim_left(char* const dstStr);
extern void str_trim(char* const dstStr);
extern UINT8 mem_cpy(unsigned char *dstMem,const char *resMem,UINT32 dstLen,UINT32 cpyLen);
extern UINT8 str_cmp(const char* const dstStr,const char* const resStr,e_CmpType cmptype);

