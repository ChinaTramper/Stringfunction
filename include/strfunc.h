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
extern UINT8 str_cmp(const char* const dstStr,const char* const resStr,e_CmpType cmptype);
extern UINT16 str_ischar_left(const char* const dstStr,char resChar);
extern UINT16 str_isnotchar_left(const char* const dstStr,char resChar);
extern UINT16 str_ischar_right(const char* const dstStr,char resChar);
extern UINT16 str_isnotchar_right(const char* const dstStr,char resChar);
extern void str_trim_right(char* const dstStr);
extern void str_trim_left(char* const dstStr);
extern void str_trim(char* const dstStr);
extern UINT8 mem_cpy(unsigned char *dstMem,const char *resMem,UINT32 dstLen,UINT32 cpyLen);
#define str_isletter(c) ((((c) >= ('a'))&&((c) <= ('z'))) || (((c) >= ('A'))&&((c) <= ('Z'))))
#define str_isupper(c) (((c) >= ('A'))&&((c) <= ('Z')))
#define str_islower(c) (((c) >= ('a'))&&((c) <= ('z')))
#define str_isnumber(c) (((c) >= ('0'))&&((c) <= ('9')))
extern UINT8 str_atoi(const char* const dstStr,long *pRetVal);
extern UINT8 str_itoa(long SwchVal,char* const dstStr,UINT16 strsize);