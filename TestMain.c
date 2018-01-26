#include "typedef.h"
#include "strfunc.h"
#include <stdlib.h>

#define Str_Len 16
#define PRINT_TEST(FuncStr,SouStr) {\
	printf("Test %s function!:\r\n",FuncStr);\
	printf("Sou String is:\t\t%s\r\n",SouStr);}	
#define PRINT_RESULT(i,DestStr) {printf("Des len %2d String is:\t%s\r\n",i,DestStr);}
#define PRINT_LEN(DestStr,len,exp,ret) {printf("Str:%s len %2d  %s ret %2d\r\n",DestStr,len,exp,ret);}
#define PRINT_NEXTLINE() {printf("\r\n");}
#define PRINT_NOCHAR(c) {printf("%c not exit!\r\n",c);}
#define PRINT_CHAR(char,c,i) {printf("char %c result is %c index is %d!\r\n",char,c,i);}


int main(int argc, char *argv[])
{
	UINT8 bType = 13;
	int i;
	long value;
	char sou_str[Str_Len] = "Hi,I'm Chinese!";
	char sou_str_trim[Str_Len+4] = "  Hi,I'm Chinese!  ";
	char sou_str_sentive[Str_Len] = "HI,I'M CHINESE!";
	char dst_str[2*Str_Len] = {0};
	UINT16 Index;

	if(1 < argc)
		bType = atoi(argv[1]);

	PRINT_NEXTLINE();
	switch(bType)
	{
		case 0:
			PRINT_TEST("str_cpy",sou_str);
			for(i=0;i<2*Str_Len;i+=4)
			{
				memset(dst_str,0,sizeof(dst_str));
				str_cpy(dst_str,sou_str,i,strlen(sou_str));
				PRINT_RESULT(i,dst_str);
			}
			PRINT_NEXTLINE();
			break;
		case 1:
			PRINT_TEST("mem_cpy",sou_str);
			for(i=0;i<2*Str_Len;i+=4)
			{
				memset(dst_str,0,sizeof(dst_str));
				mem_cpy(dst_str,sou_str,i,sizeof(sou_str));
				PRINT_RESULT(i,dst_str);
			}
			PRINT_NEXTLINE();
			break;
		case 2:
			PRINT_TEST("str_cat",sou_str);
			memset(dst_str,0,sizeof(dst_str));
			for(i=0;i<2*Str_Len;i+=4)
			{
				str_cat(dst_str,sou_str,sizeof(dst_str),i);
				PRINT_RESULT(i,dst_str);
			}
			PRINT_NEXTLINE();
			break;
		case 3:
			PRINT_TEST("str_ischar_left",sou_str);
			memset(dst_str,0,sizeof(dst_str));
			for(i='A';i<'z';i++)
			{
				Index = str_ischar_left(sou_str,(char)i);
				if(FULL_UINT16 == Index)
					{PRINT_NOCHAR((char) i);}
				else
					PRINT_CHAR(i,sou_str[Index],Index);
			}
			PRINT_NEXTLINE();
			break;
		case 4:
			PRINT_TEST("str_isnotchar_left",sou_str);
			memset(dst_str,0,sizeof(dst_str));
			for(i='A';i<'z';i++)
			{
				Index = str_isnotchar_left(sou_str,(char)i);
				if(FULL_UINT16 == Index)
					{PRINT_NOCHAR((char) i);}
				else
					PRINT_CHAR(i,sou_str[Index],Index);
			}
			PRINT_NEXTLINE();
			break;
		case 5:
			PRINT_TEST("str_ischar_right",sou_str);
			memset(dst_str,0,sizeof(dst_str));
			for(i='A';i<'z';i++)
			{
				Index = str_ischar_right(sou_str,(char)i);
				if(FULL_UINT16 == Index)
					{PRINT_NOCHAR((char) i);}
				else
					PRINT_CHAR(i,sou_str[Index],Index);
			}
			PRINT_NEXTLINE();
			break;
		case 6:
			PRINT_TEST("str_isnotchar_right",sou_str);
			memset(dst_str,0,sizeof(dst_str));
			for(i='A';i<'z';i++)
			{
				Index = str_isnotchar_right(sou_str,(char)i);
				if(FULL_UINT16 == Index)
					{PRINT_NOCHAR((char) i);}
				else
					PRINT_CHAR(i,sou_str[Index],Index);
			}
			PRINT_NEXTLINE();
			break;
		case 7:
			PRINT_TEST("str_trim_right",sou_str_trim);
			memset(dst_str,0,sizeof(dst_str));
			PRINT_RESULT(strlen(sou_str_trim),sou_str_trim);	
			str_trim_right(sou_str_trim);
			PRINT_RESULT(strlen(sou_str_trim),sou_str_trim);	
			PRINT_NEXTLINE();
			break;
		case 8:
			PRINT_TEST("str_trim_left",sou_str_trim);
			memset(dst_str,0,sizeof(dst_str));
			PRINT_RESULT(strlen(sou_str_trim),sou_str_trim);	
			str_trim_left(sou_str_trim);
			PRINT_RESULT(strlen(sou_str_trim),sou_str_trim);	
			PRINT_NEXTLINE();
			break;
		case 9:
			PRINT_TEST("str_trim",sou_str_trim);
			memset(dst_str,0,sizeof(dst_str));
			PRINT_RESULT(strlen(sou_str_trim),sou_str_trim);	
			str_trim(sou_str_trim);
			PRINT_RESULT(strlen(sou_str_trim),sou_str_trim);	
			PRINT_NEXTLINE();
			break;
		case 10:
			PRINT_TEST("str_cmp",sou_str);
			PRINT_LEN(sou_str_sentive,strlen(sou_str_sentive)
				,"case-insensit",str_cmp(sou_str,sou_str_sentive,case_insensit));
			PRINT_LEN(sou_str_sentive,strlen(sou_str_sentive)
				,"case-sensit",str_cmp(sou_str,sou_str_sentive,case_sensit));
			break;
		case 11:
			PRINT_TEST("str_atoi",sou_str);
			i = str_atoi("12030",&value);
			PRINT_LEN("12030",value,"case-insensit",i);
			i = str_atoi("-12030",&value);
			PRINT_LEN("-12030",value,"case-insensit",i);
			i = str_atoi("-123*",&value);
			PRINT_LEN("-123*",value,"case-insensit",i);
			i = str_atoi("0123",&value);
			PRINT_LEN("0123",value,"case-insensit",i);
			i = str_atoi("-0123",&value);
			PRINT_LEN("-0123",value,"case-insensit",i);
			break;
		case 12:
			PRINT_TEST("str_itoa",sou_str);
			i = str_itoa(123,sou_str,Str_Len);
			PRINT_LEN("123",value,sou_str,i);
			memset(dst_str,0,sizeof(dst_str));
			i = str_itoa(-123,sou_str,Str_Len);
			PRINT_LEN("-123",value,sou_str,i);
			memset(dst_str,0,sizeof(dst_str));
			i = str_itoa(123,sou_str,Str_Len);
			PRINT_LEN("123",value,sou_str,i);
			memset(dst_str,0,sizeof(dst_str));
			i = str_itoa(-123,sou_str,Str_Len);
			PRINT_LEN("-123",value,sou_str,i);
			memset(dst_str,0,sizeof(dst_str));
			i = str_itoa(123456789123456,sou_str,Str_Len);
			PRINT_LEN("123456789123456",value,sou_str,i);
			memset(dst_str,0,sizeof(dst_str));
			i = str_itoa(-12345678912345,sou_str,Str_Len);
			PRINT_LEN("-12345678912345",value,sou_str,i);
			memset(dst_str,0,sizeof(dst_str));
			i = str_itoa(1234567891234567,sou_str,Str_Len);
			PRINT_LEN("1234567891234567",value,sou_str,i);
			memset(dst_str,0,sizeof(dst_str));
			i = str_itoa(-123456789123456,sou_str,Str_Len);
			PRINT_LEN("-123456789123456",value,sou_str,i);
			break;
		case 13:
			str_upper(sou_str);
			PRINT_RESULT(0,sou_str);
			str_lower(sou_str);
			PRINT_RESULT(0,sou_str);
			break;
	}

	
	return 0;
}

