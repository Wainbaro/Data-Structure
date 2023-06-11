#include<iostream>
#include<malloc.h>
using namespace std;
typedef int KeyType;
typedef struct
{
	KeyType key;
}DataType;
#include "LQueue.h"
void RadixSort(DataType a[], int n, int m, int d)
{
	int i, j, k, power = 1;
	LQueue* tub;
	tub = (LQueue*)malloc(sizeof(LQueue) * d);
	for (i = 0; i < d; i++)
		QueueInitiate(&tub[i]);
	for (i = 0; i < m; i++)
	{
		if (i == 0) power = 1;
		else power = power * d;
		//将数据元素按关键码第k位的大小放到相应的队列中
		for (j = 0; j < n; j++)
		{
			k = a[j].key / power - (a[j].key / (power * d)) * d;
			QueueAppend(&tub[k], a[j]);
		}

		k = 0;
		for (j = 0; j < d; j++)
		{
			while (QueueNotEmpty(tub[j]) != 0)
			{
				QueueDelete(&tub[j], &a[k]);
				k++;
			}
		}


	}
}

void main(void)
{

	DataType test[] = { 710,342,45,686,6,841,429,134,68,246 };
	int i, n = 10, m = 3, d = 10;
	RadixSort(test, n, m, d);
	for (i = 0; i < n; i++)
		printf("%d   ", test[i].key);
}
