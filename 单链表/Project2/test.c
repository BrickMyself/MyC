#include"SList.h"
 void SListTest1()
{
	Slist lt;//����һ��Slist �ı��� lt;
	SDataType ret;
   InitSlist(&lt);//��ʼ��������//ע����Ҫ����ַ�����ܸı�ṹ�����
   SLTPushBack (&lt,1);//β��
   SLTPushBack (&lt,2);//β��
   SLTPushBack (&lt,3);//β��
   SLTPushBack (&lt,4);//β��
   SLTPushBack (&lt,5);//β��
   SListPrintf(&lt);//��ӡ����
   SLTPushFront (&lt, 0);//ͷ��
   SListPrintf(&lt);//��ӡ����
   SLTPopBack(&lt);//βɾ
   SListPrintf(&lt);//��ӡ����
   SLTPopFront(&lt);//ͷɾ
   SListPrintf(&lt);//��ӡ����
   ret=SLTFind(&lt, 4);//�������ݷ���λ��
   if(ret>0)
   {
	   printf("�ҵ��ˣ�λ���ǣ�%d\n",ret);
   }
   else
   {
	   printf("�Ҳ���\n");
   }
   
   SListInsertAfter(&lt,1 ,9);//�ڸ���λ��֮�����һ���½ڵ�
   SListPrintf(&lt);//��ӡ����

   SListEraseAfter(&lt,3);//��ɾ��ָ��λ��֮��Ľڵ�
   SListPrintf(&lt);//��ӡ����

   SListEraseAfterAll(&lt,2);//ɾ��ָ��λ��֮������н��
   SListPrintf(&lt);//��ӡ����
}
int main()
{
  SListTest1();

  system("pause");
}
