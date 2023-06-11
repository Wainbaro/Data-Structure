//#include<stdio.h>
//#include<stdlib.h>
//#define maxvalue 10000
//#define maxbit 5
//#include"haffman.h"
//int main()
//{
//	int i, j, n = 4;
//	int weight[] = { 1,3,5,7 };
//	haffnode* myhaffTree = (haffnode*)malloc(sizeof(code) * (2 * n - 1));
//	code* myhaffcode = (code*)malloc(sizeof(code) * n);
//	if (n > maxbit)
//	{
//		printf("给出的n越界，修改MaxN！\n");
//		exit(1);
//	}
//	haffman(weight, n, myhaffTree);
//	haffmancode(myhaffTree, n, myhaffcode);
//	for (i = 0; i < n; i++)
//	{
//		printf("Weight=%d  code= ", myhaffcode[i].weight);
//		for (j = myhaffcode[i].start; j < n; j++)
//			printf("%d", myhaffcode[i].bit[j]);
//		printf("\n");
//	}
//	getchar();
//	return 0;
//}