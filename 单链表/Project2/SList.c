#include"SList.h"
Slist lt;//定义一个Slist 的变量 lt;

void InitSlist(Slist* plt)//初始化单链表
{
	assert(plt);
	plt->head=NULL;
	if(plt->head==NULL)
	{
	printf("初始化成功！\n");
	}
	else
	{
		printf("初始化失败！");
	}

}
void SLTPushBack (Slist*plt, SDataType value)//尾插
{      //尾插的基本思想是，先把数据存放到新节点的数据域并把next置空
	//然后找到尾节点插入即可
	
	SListNode* newnode=(SListNode*)malloc(sizeof(SListNode));//为新结点开辟空间
	SListNode*cur=plt->head;
	newnode->_data=value;
	newnode->_next=NULL;
	if(plt->head==NULL)//如果链表为空，直接将头指针指向新结点
	{
		plt->head=newnode;
	}
	else//找到单链表的尾
	{
		while(cur->_next!=NULL)
		{
			cur=cur->_next;
		}
		cur->_next=newnode;//
	}
}
void SLTPushFront (Slist*plt, SDataType value)//头插
{    //和尾插做法一致
	//不过这里要考虑插入的顺序，先将要插入的新结点和原来的头结点链上，
	//再和头指针链上
	
    SListNode*newnode=(SListNode*)malloc(sizeof(SListNode));
	assert(plt);
	newnode->_data=value;
	newnode->_next=NULL;
	newnode->_next=plt->head;
	plt->head=newnode;
}
void SLTPopBack(Slist* plt)//尾删
{
	//首先要找到尾然后进行删除，不过这里有几种特殊的情况
	SListNode* cur=plt->head;
	assert(plt);
	if(cur==NULL)//如果链表为空
	{
		return;
	}
	else if((cur->_next)==NULL)//只有一个数据
	{
		free(cur);
		plt->head=NULL;
	}
	else {
		while((cur->_next->_next)!=NULL)//正常情况找到尾结点的前一个
		{      
			cur=cur->_next;
		}
		//将前一个结点的next 释放掉，然后再置空
		//若果直接释放最后一个导致倒数第二个的next既找不到下一个结点也不为空
		//因此是释放倒数第二个的next,将倒数第二个的next置空
		free(cur->_next);
		cur->_next=NULL;
	}
}
void SLTPopFront(Slist* plt)//头删
{
	//头删也就是把头指针和第一个结点的next链起来，并且释放掉第一个结点
	//但要注意的是先链起来再释放否则找不到第一个结点的next
	assert(plt);
	if(plt->head==NULL)
	{
		return ;
	}
	else
	{
	SListNode*cur=plt->head;
	plt->head=cur->_next;
	free(cur);
	cur=NULL;
	}
}
SDataType   SLTFind(Slist* plt, SDataType x)//查找数据返回位置
 {   
	 int count=1;//定义一个计数器用作位置的返回值
	 SListNode*cur=plt->head;
	 assert(plt&&x);
	 
	 if(plt->head==NULL)
	 {
		 return -1;
	 }
	 if(cur->_data==x&&cur->_next!=NULL)
	 {
		 return 1;//如果第一个就是返回位置1
	 }
	 else
	 {	 
		 while(cur->_next!=NULL)
		 { 
			 if(cur->_data!=x)//不相等计数器就++，并且继续向后走遍历一遍
			 {
				count++;	
				cur=cur->_next;
			 } 
	     }
		  if(cur->_data==x)
		    {
		  	    return count;//找到就返回位置
		    }
		   else
				 return -1;//都没有找到返回-1
     }
}


void SListInsertAfter(Slist*plt,SDataType pos, SDataType x)//在给定位置之后插入一个新节点
{
	SDataType count=1;
	SListNode*cur=plt->head;
	SListNode*newnode=(SListNode*)malloc(sizeof(SListNode));
	newnode->_data=x;
	newnode->_next=NULL;
	while(count!=pos&&cur->_next!=NULL)//找到pos位置的结点
	{
		count++;
		cur=cur->_next;
	}
	if(count==pos)//找到时插入
	{
	  newnode->_next=cur->_next;//先将新结点的next链上前面结点的next
	  cur->_next=newnode;
	}


}
void SListEraseAfter(Slist*plt,SDataType pos)//在删除指定位置的节点
{
	SDataType count=1;
	SListNode*cur1=plt->head;
	if(pos==1)
	{
    SListNode*cur=plt->head;
	plt->head=cur->_next;
	free(cur);
	cur=NULL;
	}
	while(count!=pos&&cur1->_next!=NULL)//找到pos位置的结点
	{
		count++;
		cur1=cur1->_next;
	}
	if((pos)==count&&pos!=1)
	{
		SListNode*Next=cur1->_next->_next;
		free(cur1->_next);
		cur1->_next=NULL;
		cur1->_next=Next;

	}


}
void SListEraseAfterAll(Slist*plt,SDataType pos)//在删除指定位置的节点
{
	SDataType count=1;
	SListNode*cur=plt->head;
	assert(plt);
	if(pos==1)
	{
		free(cur->_next);
		cur->_next=NULL;
	}
	while(count!=pos&&cur->_next!=NULL)//找到pos位置的结点
	{
		count++;
		cur=cur->_next;
	}
	if((pos)==count&&pos!=1)
	{
		free(cur->_next);
		cur->_next=NULL;
	}

}

void SListPrintf(Slist*plt)//打印数据
{
	SListNode*cur=plt->head;
    assert(plt);
	while(cur!=NULL)
	{
		printf("%d ",cur->_data);
		cur=cur->_next;
	}
	printf("\n");
}
