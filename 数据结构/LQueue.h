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
void QueueInitiate(LQueue* Q)    //��ʼ��
{
    Q->rear = NULL;
    Q->front = NULL;
}
int QueueNotEmpty(LQueue Q)      //�ǿշ�
{
    if (Q.front == NULL) return 0;
    else return 1;
}
void QueueAppend(LQueue* Q, DataType x)   //�����
//������Ԫ��x������ʽ����Q�Ķ�β���ɹ�����1�����򷵻�0
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
        printf("�����ѿ�!\n");
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
        printf("�����ѿ�!\n");
        return 0;
    }
    else
    {
        *d = Q.front->data;
        return 1;
    }
}
void Destroy(LQueue  Q)
//ȡ��ʽ����Q�Ķ�ͷ����Ԫ�أ�ֵ�ɲ���d���أ��ɹ�����1�����򷵻�0
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
