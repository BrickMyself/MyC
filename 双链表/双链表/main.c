
#include"DoubleList.h"
	List p;

void ListInit(List* plist)//初始化双链表
{
	//注意头结点不保存数据
	//只做一个能找到后继结点的结点
	//头结点的next和prev都指向自己,构成双向循环
	ListNode*head=BuyListNode(-1);
	assert(plist);
	head->_next=head;
	head->_prev=head;
	plist->_head=head;
}
 ListNode* BuyListNode(LTDataType x)//创造结点，申请内存；
 {
	 ListNode*newnode=(ListNode*)malloc(sizeof(ListNode));
	 newnode->_next=NULL;
	 newnode->_prev=NULL;
	 newnode->_data=x;
	 return newnode;
 }
void ListDestory(List* plist)//删除双链表 
{
	ListNode*cur=plist->_head->_next;
	assert(plist);
	while(cur!=plist->_head)//逐个遍历删除
	{
		ListNode* next=cur->_next;//先保存下一个结点再删除当前的结点
		free(cur);
		cur=cur->_next;
	}
	free(plist->_head);
	plist->_head=NULL;
}
void ListPushBack(List* plist, LTDataType x)//尾插
{
	//尾插不用像单链表那样循环遍历找尾，只需要通过，头结点就可以找到尾
	//定义两个指针
	ListNode*head=plist->_head;
	ListNode*tail=head->_prev;//尾也就是头的prev
	ListNode*newnode=BuyListNode(x);
	assert(plist);
	tail->_next=newnode;
	newnode->_prev=tail;
	newnode->_next=head;
	head->_prev=newnode;
}

void ListPrint(List* plist)//打印链表数据
{
	ListNode*cur=plist->_head->_next;
	assert(plist);
	printf("<-head->");
	while(cur!=plist->_head)//注意条件是不为头，表示把整个遍历一遍
	{

		printf("<-%d->",cur->_data);
		cur=cur->_next;
	}
	printf("\n");
}
void ListPopBack(List* plist)//尾删
{    //同样先找到尾
	ListNode*head=plist->_head;
	ListNode*tail=head->_prev;
	ListNode*tailprev=tail->_prev;//找到尾的前驱
	assert(plist&&plist->_head->_next!=plist->_head);
	tailprev->_next=plist->_head;
	head->_prev=tailprev;
}
void ListPushFront(List* plist, LTDataType x)//头插
{
	//找到头和头结点的下一个结点
	ListNode*head=plist->_head;
	ListNode*headnext=head->_next;
	ListNode*newnode=BuyListNode(x);//申请内存
	assert(plist&&plist->_head->_next!=NULL);
	head->_next=newnode;
	newnode->_prev=head;
	newnode->_next=headnext;
	headnext->_prev=newnode;
}
void ListPopFront(List* plist)//头删
{   //同样先找到头和头的下一个结点
	ListNode*head=plist->_head;
	ListNode*headnext=head->_next->_next;
	assert(plist&&plist->_head->_next!=NULL);
	free(head->_next);//释放结点
	head->_next=headnext;
	head=headnext->_prev;
	
}
LTDataType ListFind(List* plist, LTDataType x)//查找数据返回数据的位置
{
     int count=1;
	 ListNode*head=plist->_head;
	 ListNode*cur=head->_next;
	 assert(plist&&head);//断言链表不为空
	 if(cur->_next==head)//如果只有一个结点且相等返回1
	 {
		 if(cur->_data==x) return 1;
		 else return -1;
	 }
	 	 while(cur!=head)//结点大于1循环遍历
	 {
		 if(cur->_data==x)
		{
			return count;//返回位置
		}
		 if(cur->_data!=x)
		 {
				cur=cur->_next;
				count++;
		 }	
	 }
	return -1;//都没有找到返回-1
}
void ListInsert(List* plist,LTDataType pos, LTDataType x,LTDataType size)//在pos的前面进行插入
{
	int tmp=size;
	int count=1;
	ListNode*head=plist->_head;
	ListNode*cur=head->_next;
	ListNode*newnode=BuyListNode(x);
	assert(plist&&head->_next);//保证链表不为空
	if(tmp<pos)//进行位置判断，如果超过之后则提示并返回
	{
			printf("位置不合法\n");
			return ;
	}
	if(pos==1)//头插
	{
		head->_next=newnode;
		newnode->_prev=head;
		newnode->_next=cur;
		cur->_prev=newnode;
	}
	while(cur->_next!=head)//找到位置
	{
		if(cur->_data!=x)
		{
		cur=cur->_next;
		count++;
		}
		if(count==pos)
		{
			ListNode*prev=cur->_prev;
			newnode->_prev=prev;
			prev->_next=newnode;
			newnode->_next=cur;
			cur->_prev=newnode;
		}
	}
}
LTDataType ListSize(List* plist)//链表元素个数
{
	int count=1;
	ListNode*head=plist->_head;
	ListNode*cur=head->_next;
	assert(plist);
	if(cur->_next==head&&head!=NULL)
	{
          return 1;
	}
	while(cur->_next!=head&&head!=NULL)
	{
		cur=cur->_next;
		count++;
	}
	return count;
}
void ListErase(List* plist,LTDataType pos,LTDataType size)// 删除pos位置的节点
{        //同样先找位置
	int count=1;
	ListNode*head=plist->_head;
	ListNode*cur=head->_next;
	ListNode*Next=cur->_next;
	if(pos>size)//超出大小范围
	{
		printf("位置不合法\n");
		return ;
	}
	if(pos==1)//相当于头删
	{
		head->_next=Next;
		Next->_prev=cur->_prev;
		free(cur);
		cur=NULL;
        return;
	}
	while(cur->_next!=head)//找到位置
	{
		cur=cur->_next;
		count++;
	if(pos==count)
	{
		ListNode*prev=cur->_prev;
		ListNode*next=cur->_next;
		prev->_next=next;
		next->_prev=prev;
		free(cur);
		cur=NULL;
		return ;
	}
	}
}
