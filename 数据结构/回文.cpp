//#include <string.h>
//#include <stdio.h>
//#define MaxStackSize 80
//#define MaxQueueSize 80
//typedef char DataType;
//#include "SeqStack.h"
//#include "SeqCQueue.h"
//
//void Palindrome(char str[], int n)
//{
//	SeqStack myStack;
//	SeqCQueue myQueue;
//	char x, y;
//	int i;
//
//	StackInitiate(&myStack);
//	QueueInitiate(&myQueue);
//	for (i = 0; i < n; i++)
//	{
//		QueueAppend(&myQueue, str[i]);
//		StackPush(&myStack, str[i]);
//	}
//	while (QueueNotEmpty(myQueue) == 1 && StackNotEmpty(myStack) == 1)
//	{
//		QueueDelete(&myQueue, &x);
//		StackPop(&myStack, &y);
//		if (x != y)
//		{
//			printf("不是回文.\n");
//			return;
//		}
//
//	}
//	printf("是回文.\n");
//}
//
//void EnterStr(char str[], int* n)
//{
//	printf("输入字符串（不能超过80个字符）:");
//	scanf("%s", str);
//	*n = strlen(str);
//}
//
//void main(void)
//{
//	char str[80];
//
//	int n,flag;
//
//	while (1)
//	{
//		EnterStr(str, &n);
//		Palindrome(str, n);
//		printf("\n要继续吗?(1/0):\n");
//		scanf("%d", &flag);
//		if (flag==1) continue;
//		else return;
//	}
//}