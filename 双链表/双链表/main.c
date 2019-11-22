
#include"DoubleList.h"
	List p;

void ListInit(List* plist)//��ʼ��˫����
{
	//ע��ͷ��㲻��������
	//ֻ��һ�����ҵ���̽��Ľ��
	//ͷ����next��prev��ָ���Լ�,����˫��ѭ��
	ListNode*head=BuyListNode(-1);
	assert(plist);
	head->_next=head;
	head->_prev=head;
	plist->_head=head;
}
 ListNode* BuyListNode(LTDataType x)//�����㣬�����ڴ棻
 {
	 ListNode*newnode=(ListNode*)malloc(sizeof(ListNode));
	 newnode->_next=NULL;
	 newnode->_prev=NULL;
	 newnode->_data=x;
	 return newnode;
 }
void ListDestory(List* plist)//ɾ��˫���� 
{
	ListNode*cur=plist->_head->_next;
	assert(plist);
	while(cur!=plist->_head)//�������ɾ��
	{
		ListNode* next=cur->_next;//�ȱ�����һ�������ɾ����ǰ�Ľ��
		free(cur);
		cur=cur->_next;
	}
	free(plist->_head);
	plist->_head=NULL;
}
void ListPushBack(List* plist, LTDataType x)//β��
{
	//β�岻������������ѭ��������β��ֻ��Ҫͨ����ͷ���Ϳ����ҵ�β
	//��������ָ��
	ListNode*head=plist->_head;
	ListNode*tail=head->_prev;//βҲ����ͷ��prev
	ListNode*newnode=BuyListNode(x);
	assert(plist);
	tail->_next=newnode;
	newnode->_prev=tail;
	newnode->_next=head;
	head->_prev=newnode;
}

void ListPrint(List* plist)//��ӡ��������
{
	ListNode*cur=plist->_head->_next;
	assert(plist);
	printf("<-head->");
	while(cur!=plist->_head)//ע�������ǲ�Ϊͷ����ʾ����������һ��
	{

		printf("<-%d->",cur->_data);
		cur=cur->_next;
	}
	printf("\n");
}
void ListPopBack(List* plist)//βɾ
{    //ͬ�����ҵ�β
	ListNode*head=plist->_head;
	ListNode*tail=head->_prev;
	ListNode*tailprev=tail->_prev;//�ҵ�β��ǰ��
	assert(plist&&plist->_head->_next!=plist->_head);
	tailprev->_next=plist->_head;
	head->_prev=tailprev;
}
void ListPushFront(List* plist, LTDataType x)//ͷ��
{
	//�ҵ�ͷ��ͷ������һ�����
	ListNode*head=plist->_head;
	ListNode*headnext=head->_next;
	ListNode*newnode=BuyListNode(x);//�����ڴ�
	assert(plist&&plist->_head->_next!=NULL);
	head->_next=newnode;
	newnode->_prev=head;
	newnode->_next=headnext;
	headnext->_prev=newnode;
}
void ListPopFront(List* plist)//ͷɾ
{   //ͬ�����ҵ�ͷ��ͷ����һ�����
	ListNode*head=plist->_head;
	ListNode*headnext=head->_next->_next;
	assert(plist&&plist->_head->_next!=NULL);
	free(head->_next);//�ͷŽ��
	head->_next=headnext;
	head=headnext->_prev;
	
}
LTDataType ListFind(List* plist, LTDataType x)//�������ݷ������ݵ�λ��
{
     int count=1;
	 ListNode*head=plist->_head;
	 ListNode*cur=head->_next;
	 assert(plist&&head);//��������Ϊ��
	 if(cur->_next==head)//���ֻ��һ���������ȷ���1
	 {
		 if(cur->_data==x) return 1;
		 else return -1;
	 }
	 	 while(cur!=head)//������1ѭ������
	 {
		 if(cur->_data==x)
		{
			return count;//����λ��
		}
		 if(cur->_data!=x)
		 {
				cur=cur->_next;
				count++;
		 }	
	 }
	return -1;//��û���ҵ�����-1
}
void ListInsert(List* plist,LTDataType pos, LTDataType x,LTDataType size)//��pos��ǰ����в���
{
	int tmp=size;
	int count=1;
	ListNode*head=plist->_head;
	ListNode*cur=head->_next;
	ListNode*newnode=BuyListNode(x);
	assert(plist&&head->_next);//��֤����Ϊ��
	if(tmp<pos)//����λ���жϣ��������֮������ʾ������
	{
			printf("λ�ò��Ϸ�\n");
			return ;
	}
	if(pos==1)//ͷ��
	{
		head->_next=newnode;
		newnode->_prev=head;
		newnode->_next=cur;
		cur->_prev=newnode;
	}
	while(cur->_next!=head)//�ҵ�λ��
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
LTDataType ListSize(List* plist)//����Ԫ�ظ���
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
void ListErase(List* plist,LTDataType pos,LTDataType size)// ɾ��posλ�õĽڵ�
{        //ͬ������λ��
	int count=1;
	ListNode*head=plist->_head;
	ListNode*cur=head->_next;
	ListNode*Next=cur->_next;
	if(pos>size)//������С��Χ
	{
		printf("λ�ò��Ϸ�\n");
		return ;
	}
	if(pos==1)//�൱��ͷɾ
	{
		head->_next=Next;
		Next->_prev=cur->_prev;
		free(cur);
		cur=NULL;
        return;
	}
	while(cur->_next!=head)//�ҵ�λ��
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
