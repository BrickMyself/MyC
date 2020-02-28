//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int a=1,b=3,i;
//	i=a;a=b;b=i;
//	printf("%d %d\n",a,b);
//	system("pause");
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//         int a[10];
//         int max,i;
//         for(i=0;i<10;i++)
//         scanf("%d",&a[i]);
//         max=a[0];
//   for(i=0;i<10;i++)
//         {  if( max<a[i])
//
//          {     
//			  max=a[i];
//           }
//         }
//     printf("%d\n",max);
//	   system("pause");
//	     return 0;
//}
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a,b,c,i,j,k;
	scanf("%d%d%d",&a,&b,&c);
	if(a<b)
	{   i=a;
	    a=b;
		b=i;
	}
	if(b<c)
	{  j=b;
	   b=c;
	   c=j;
	}
	if(a<b)
	{
		k=b;
		a=b;
		b=k;
	}
	printf("%d %d %d",a,b,c);
	system("pause");
	return 0;
}

 


 
