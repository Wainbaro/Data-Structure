#pragma once
typedef struct
{
	DataType queue[MaxQueueSize];
	int rear;
	int front;
}SeqCQueue;

void QueueInitiate(SeqCQueue* Q)
{
	Q->rear = 0;
	Q->front = 0;
}

int QueueNotEmpty(SeqCQueue Q)
{
	if (Q.front == Q.rear) return 0;
	else return 1;
}

int QueueAppend(SeqCQueue* Q, DataType x)
{
	if ((Q->rear + 1) % MaxQueueSize == Q->front)
	{
		printf("队列已满无法插入.\n");
		return 0;
	}
	else
	{
		Q->queue[Q->rear] = x;
		Q->rear = (Q->rear + 1) % MaxQueueSize;
		return 1;
	}
}

int QueueDelete(SeqCQueue* Q, DataType* d)
{
	if (Q->front == Q->rear)
	{
		printf("循环队列已空无数据元素出队列.\n");
		return 0;
	}
	else
	{
		*d = Q->queue[Q->front];
		Q->front = (Q->front + 1) % MaxQueueSize;
		return 1;
	}
}

int QueueGet(SeqCQueue Q, DataType* d)
{
	if (Q.front == Q.rear)
	{
		printf("循环队列已空无数据元素可取.\n");
		return 0;
	}
	else
	{
		*d = Q.queue[Q.front];
		return 1;
	}
}

