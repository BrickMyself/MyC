#include"DoubleList.h"
void 	TestDlist()
{
	List p;
	int ret;
	int set;
    ListInit(&p);
    ListPushBack(&p, 1);//β��
	ListPushBack(&p, 2);
	ListPushBack(&p, 3);
	ListPushBack(&p, 4);
    ListPrint(&p);//��ӡ��������
    ListPopBack(&p);//βɾ
    ListPrint(&p);//��ӡ��������
    ListPushFront(&p, 0);//ͷ��
    ListPrint(&p);//��ӡ��������
    ListPopFront(&p);//ͷɾ
    ListPrint(&p);//��ӡ��������
    ret=ListFind(&p, 3);//�������ݷ������ݵ�λ��
	if(ret>0)
	{
		printf("�ҵ���λ���ǣ�%d\n",ret);
	}
	else
	{
		printf("û���ҵ���\n");
	}
  	set=ListSize(&p);//����Ԫ�ظ���
    ListInsert(&p,3,5,set); // ��pos��ǰ����в���
	ListPrint(&p);//��ӡ��������
	ListErase(&p,3,set);// ɾ��posλ�õĽڵ�
	ListPrint(&p);//��ӡ��������
    system("pause");
}

int main()
{
	TestDlist();
  system("pause");
  return 0;
}