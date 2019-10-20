#include"SList.h"
 void SListTest1()
{
	Slist lt;//定义一个Slist 的变量 lt;
	SDataType ret;
   InitSlist(&lt);//初始化单链表//注意需要传地址，才能改变结构体变量
   SLTPushBack (&lt,1);//尾插
   SLTPushBack (&lt,2);//尾插
   SLTPushBack (&lt,3);//尾插
   SLTPushBack (&lt,4);//尾插
   SLTPushBack (&lt,5);//尾插
   SListPrintf(&lt);//打印数据
   SLTPushFront (&lt, 0);//头插
   SListPrintf(&lt);//打印数据
   SLTPopBack(&lt);//尾删
   SListPrintf(&lt);//打印数据
   SLTPopFront(&lt);//头删
   SListPrintf(&lt);//打印数据
   ret=SLTFind(&lt, 4);//查找数据返回位置
   if(ret>0)
   {
	   printf("找到了，位置是：%d\n",ret);
   }
   else
   {
	   printf("找不到\n");
   }
   
   SListInsertAfter(&lt,1 ,9);//在给定位置之后插入一个新节点
   SListPrintf(&lt);//打印数据

   SListEraseAfter(&lt,3);//在删除指定位置之后的节点
   SListPrintf(&lt);//打印数据

   SListEraseAfterAll(&lt,2);//删除指定位置之后的所有结点
   SListPrintf(&lt);//打印数据
}
int main()
{
  SListTest1();

  system("pause");
}
