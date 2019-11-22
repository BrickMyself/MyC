#include"DoubleList.h"
void 	TestDlist()
{
	List p;
	int ret;
	int set;
    ListInit(&p);
    ListPushBack(&p, 1);//尾插
	ListPushBack(&p, 2);
	ListPushBack(&p, 3);
	ListPushBack(&p, 4);
    ListPrint(&p);//打印链表数据
    ListPopBack(&p);//尾删
    ListPrint(&p);//打印链表数据
    ListPushFront(&p, 0);//头插
    ListPrint(&p);//打印链表数据
    ListPopFront(&p);//头删
    ListPrint(&p);//打印链表数据
    ret=ListFind(&p, 3);//查找数据返回数据的位置
	if(ret>0)
	{
		printf("找到了位置是：%d\n",ret);
	}
	else
	{
		printf("没有找到！\n");
	}
  	set=ListSize(&p);//链表元素个数
    ListInsert(&p,3,5,set); // 在pos的前面进行插入
	ListPrint(&p);//打印链表数据
	ListErase(&p,3,set);// 删除pos位置的节点
	ListPrint(&p);//打印链表数据
    system("pause");
}

int main()
{
	TestDlist();
  system("pause");
  return 0;
}