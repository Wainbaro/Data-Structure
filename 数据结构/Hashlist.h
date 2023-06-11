#pragma once

#include<stdio.h>
#include<malloc.h>
typedef enum
{
    Empty, Active, Deleted
} KindOfItem;              //����״̬��ö������

typedef struct
{
    DataType data;
    KindOfItem info;
}HashItem;   //����ṹ��

typedef struct
{
    HashItem* ht;       //��ϣ������
    int tableSize;        //�������
    int currentSize;       //��ǰ�������
}HashTable;
int Initiate(HashTable* hash, int mSize)//��ʼ������
{
    hash->tableSize = mSize;
    hash->ht = (HashItem*)malloc(sizeof(HashItem) * mSize);
    if (hash->ht == NULL) return 0;
    else
    {
        hash->currentSize = 0;
        return 1;
    }


}
int Find(HashTable* hash, DataType x)		//����
{
    int i = x.key % hash->tableSize;
    int j = i;
    while (hash->ht[j].info == Active && hash->ht[j].data.key != x.key)
        //˵�����ڳ�ͻ
    {
        j = (j + 1) % hash->tableSize; 	//�ù�ϣ��ͻ������������
        if (j == i) 	//˵���ѱ���������ϣ��δ�ҵ��ұ�����
            return -hash->tableSize;
    }
    if (hash->ht[j].info == Active)
        return j;	//�ҵ���������ֵ
    else
        return -j;			//δ�ҵ������ظ�ֵ
}int Insert(HashTable* hash, DataType x)                  //����
{
    int i = Find(hash, x); 			//����Find(x)
    if (i > 0) return 0;			//����Ԫ��x�Ѿ�����
    else if (i != -hash->tableSize)	//����Ԫ��x�������ҹ�ϣ��δ��
    {
        hash->ht[-i].data = x;		//����Ԫ�ظ�ֵ
        hash->ht[-i].info = Active;	//�û���
        hash->currentSize++;		//��ǰ���������1
        return 1;			//���ز���ɹ�
    }
    else return 0;				//���ز���ʧ��
}
int Delete(HashTable* hash, DataType x)		             //ɾ��
{
    int i = Find(hash, x); 					//����Find(x)
    if (i >= 0)					//���ҵ�
    {
        hash->ht[i].info = Deleted;		//��ɾ�����
        hash->currentSize--;			//��ǰ���������1
        return 1;			//����ɾ���ɹ�
    }
    else return 0;					//����ɾ��ʧ��
}
void Destroy(HashTable* hash)                                               //ɾ��
{
    free(hash->ht);
}
