//////#include<stdlib.h>
//////#include<stdio.h>
//////int main()
//////{
//////	int *arry;
//////	int i=0;
//////	int j=0;
//////	printf("请输入要申请的元素的个数:\n");
//////	scanf("%d",&i);
//////	arry=(int*)malloc(sizeof(int)*i);
//////	arry=(int*)malloc(16);
//////	printf("数组初始值是：");
//////	for(j=0;j<i;j++)
//////	{
//////		printf("%d ",arry[j]);
//////	}
//////	printf("\n");
//////	printf("手动初始化后数组元素为：");
//////	for(j=0;j<i;j++)
//////	{
//////		arry[j]=j;
//////		printf("%d ",arry[j]);
//////	}
//////	printf("\n");
//////	system("pause");
//////	return 0;
//////}
////#include <stdio.h>      
////#include <stdlib.h>     
////int main ()
////{
////  int i,n;
////  int * arry;
////  printf("请输入要申请的元素的个数:\n");
////  scanf("%d",&n);
////  arry=(int*)calloc(n,sizeof(int));
////  printf("初始化时元素的初始值：\n");
////  for(i=0; i<n; i++)
////  {
////	  printf("%d ",arry[i]);
////  }
////  printf("\n");
////  printf("手动初始化后为:\n");
////  for(i=0; i<n; i++)
////  {
////	  arry[i]=i;
////	  printf("%d ",arry[i]);
////  }
////  printf("\n");
////  system("pause");
////  return 0;
////}
//#include <stdio.h>      /* printf, scanf, puts */
//#include <stdlib.h>     /* realloc, free, exit, NULL */
//
//int main ()
//{
//  int input,n;
//  int count = 0;
//  int* numbers = NULL;
//  int* more_numbers = NULL;
//
//  do {
//     printf ("Enter an integer value (0 to end): ");
//     scanf ("%d", &input);
//     count++;
//
//     more_numbers = (int*) realloc (numbers, count * sizeof(int));
//
//     if (more_numbers!=NULL) {
//       numbers=more_numbers;
//       numbers[count-1]=input;
//     }
//     else {
//       free (numbers);
//       puts ("Error (re)allocating memory");
//       exit (1);
//     }
//  } while (input!=0);
//
//  printf ("Numbers entered: ");
//  for (n=0;n<count;n++) printf ("%d ",numbers[n]);
//  free (numbers);
//  system("pause");
//  return 0;
//}
#include <stdlib.h> 
#include <stdio.h> 
main() 
{ 
char *p; 
p=(char *)malloc(100); 
if(p) 
printf("Memory Allocated at: %x",p); 
else 
printf("Not Enough Memory!/n"); 
getchar(); 
p=(char *)realloc(p,1000); 
if(p) 
printf("Memory Reallocated at: %x",p); 
else 
printf("Not Enough Memory!/n"); 
free(p); 
getchar(); 
system("pause");
return 0; 
} 