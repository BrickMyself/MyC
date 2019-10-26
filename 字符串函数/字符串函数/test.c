#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
int my_strcmp( const char* str1,const char *str2)
{
     assert(str1&&str2);
	 while(*str1!='\0'&&*str2!='\0')
	 {
	 if(*str1>*str2)
	 {
		 return 1;
	 }
	 if(*str1<*str2)
	 {
		 return -1;
	 }
	 str1++;
	 str2++;
	 if('\0'==*str1&&*str2=='\0')
	 {
		 return 0;
	 }
	 }
}
int mian()
{
	char *str1="hello";
	char *str2="hi";
	int ret;
    ret=my_strcmp(str1,str2);
	printf("%d",ret);
	system("pause");
	return 0;
}