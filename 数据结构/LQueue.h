#pragma once
#ifndef LQueue_h
#define LinQueue_h
#include<iostream>
typedef struct qnode
{
    DataType data;
    struct qnode* next;
}LQNode;
typedef struct
{
    LQNode* front;
    LQNode* rear;
}LQueue;
void QueueInitiate(LQueue* Q)    //初始化
{
    Q->rear = NULL;
    Q->front = NULL;
}
int QueueNotEmpty(LQueue Q)      //非空否
{
    if (Q.front == NULL) return 0;
    else return 1;
}
void QueueAppend(LQueue* Q, DataType x)   //入队列
//把数据元素x插入链式队列Q的队尾，成功返回1，否则返回0
{
    LQNode* p;
    p = (LQNode*)malloc(sizeof(LQNode));
    p->data = x;
    p->next = NULL;
    if (Q->front != NULL) Q->rear->next = p;
    Q->rear = p;
    if (Q->front == NULL) Q->front = p;
}
int QueueDelete(LQueue* Q, DataType* d)
{
    LQNode* p;
    if (Q->front == NULL)
    {
        printf("队列已空!\n");
        return 0;
    }
    else
    {
        *d = Q->front->data;
        p = Q->front;
        Q->front = Q->front->next;
        if (Q->front == NULL)Q->rear = NULL;
        free(p);
        return 1;

    }

}
int QueueGet(LQueue Q, DataType* d)
{
    if (Q.front == NULL)
    {
        printf("队列已空!\n");
        return 0;
    }
    else
    {
        *d = Q.front->data;
        return 1;
    }
}
void Destroy(LQueue  Q)
//取链式队列Q的队头数据元素，值由参数d带回，成功返回1，否则返回0
{
    LQNode* p, * p1;
    p = Q.front;
    while (p != NULL)
    {
        p1 = p;
        p = p->next;
        free(p1);
    }
}
#endif
#pragma once
