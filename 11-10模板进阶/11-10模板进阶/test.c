#include<iostream>
using namespace std;
int main()
{
    //s表示通过进制转换后M的N进制数
    string s = "";
    string tables = "0123456789ABCDEF";//从二进制到十六进制的数的集合
    //输入某个数M，和需要转换的进制N
    int M = 0;
    int N = 0;
    cin >> M >> N;
    if (M == 0)
    {
        s = "0";
    }
    while (M)
    {
        if (M < 0)
        {
            M = -M;
            cout << "-";
        }

        s = tables[M%N]+s;
        M /= N;
    }

    //注意：因为s是字符串，最好在输出的时候将该字符串以C风格显示出来即就是s.c_str(),某些编译器可以跑过，但有的编译器就必须加上
    cout << s.c_str() << endl;
    return 0;
}
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int a,b,c;
//	int A,B,C,D;
//	scanf("%d %d %d %d",&A,&B,&C,&D);
//    for(a=-30;a<=30;a++)
//	{
//		for(b=-30;b<=30;b++)
//		{
//			for(c=-30;c<=30;c++)
//			{
//				if((a-b)==A&&((b-c)==B)&&((a+b)==C)&&((b+c)==D))
//				{
//					printf("%d %d %d ",a,b,c);
//				}
//			}
//		}
//	} 
//    system("pause");
//    return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int n=100;
//	int i=2;
//	int flag=0;
//	for(n=100; n<=200; n++)
//	{
//		for(i=2; i<n; i++)
//		{
//			if(n%i==0)
//			{
//				flag=-1;
//				break;
//			}
//		}
//		if(flag==0)
//		{
//			printf("%d",n);
//		}
//	}
//
//system("pause");
//return 0;
//}


//#include <iostream>
//#include <string>
// 
//using namespace std;
// 
////将整句话进行倒置，标点符号不倒换
//void reverString(char *str,int len){           
//	int j=len;
//	int i=0;
//	while (i<j)
//	{
//		char tmp=str[i];
//		str[i]=str[j];
//		str[j]=tmp;
//		i++;
//		j--;
//	}
//}
// 
////按单词倒置
//void reverWord(char *str){
//	int i=0;
//	int begin=0;
//	int end=0;
//	while (str[i])
//	{
//		//通过空格判断单词，记录每个单词的开头和结尾的位置，再进行倒置
//		if (str[i]!=' ')
//		{
//			begin=i;
//			while (str[i]!=' '&&str[i])
//				i++;
//			i=i-1;	
//			end=i;			
//		}
//		while (begin<end)
//		{
//			char tmp=str[begin];
//			str[begin]=str[end];
//			str[end]=tmp;
//			begin++;
//			end--;
//		}
//		i++;
//	}	
//}
// 
//int main(){
//	char p[]="To be or not to be, just to find to try.";
//	int lenth=strlen(p)-1;
//
//	reverString(p,lenth);
//	reverWord(p);
//	cout << p << endl;
//    system("pause");
//	return 0;
//}
//
////#include<stdio.h>
////#include<string.h>
////#include<stdlib.h>
////void Reset(char *str,int len)
////{
////    char tmp;
////	int i=0;
////    for(i=0;i<len/2;i++)
////    {
////        tmp=str[i];
////        str[i]=str[len-1-i];
////        str[len-1-i]=str[i];
////    }
////    
////}
////int main()
////{
////    char str[100]="hello world";
////    int lenth=strlen(str);
////    int i=0;
////	Reset(str,lenth);
////	for(i=0; i<lenth-1; i++)
////	{
////		printf("%s",str[i]);
////	}
////    system("pause");
////    return 0;
////}
//
//
////#include<stdio.h>
////#include<stdlib.h>
////int main()
////{
////    int a,b;
////    int max,min;
////    scanf("%d %d",&a,&b);
////    max=a;
////    if(max<b)
////    {
////        max=b;
////        min=a;
////    }
////    else min=b;
////	if(max==0||min==0)
////    {
////		return 0;
////    }
////    if(max%min==0)
////    {
////        printf("%d",max);
////    }
////    else
////    {
////        printf("%d",max*min);
////    }
////    
////    system("pause");
////    return 0;
////}
//
//
//
////#include<iostream>
////using namespace std;
////class Persion
////{
////public:
////	void Print()
////	{
////		cout<< age <<endl;
////	}
////private:
////	int age;
////}
////class Student :public Persion
////{
////
////
////
////}
////#define N 100
////template<class T,size_t N>//通常情况下都是整形
//////枚举
////enum Color
////{
////	red,
////	blue,
////	gery,
////}
//class Array
//{
//public:
//	T& operator[](size_t pos)
//	{
//		return a[pos];
//	}
//private:
//	T a[N];
//	size_t _size;
//};
//int main()
//{
//	//Array<int,10> a1;
//
//	system("pause");
//	return 0;
//}