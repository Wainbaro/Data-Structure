#pragma once

#include<stdio.h>
#include<malloc.h>
typedef enum
{
    Empty, Active, Deleted
} KindOfItem;              //表项状态的枚举类型

typedef struct
{
    DataType data;
    KindOfItem info;
}HashItem;   //表项结构体

typedef struct
{
    HashItem* ht;       //哈希表数组
    int tableSize;        //数组个数
    int currentSize;       //当前表项个数
}HashTable;
int Initiate(HashTable* hash, int mSize)//初始化函数
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
int Find(HashTable* hash, DataType x)		//查找
{
    int i = x.key % hash->tableSize;
    int j = i;
    while (hash->ht[j].info == Active && hash->ht[j].data.key != x.key)
        //说明存在冲突
    {
        j = (j + 1) % hash->tableSize; 	//用哈希冲突方法继续查找
        if (j == i) 	//说明已遍历整个哈希表未找到且表已满
            return -hash->tableSize;
    }
    if (hash->ht[j].info == Active)
        return j;	//找到，返回正值
    else
        return -j;			//未找到，返回负值
}int Insert(HashTable* hash, DataType x)                  //插入
{
    int i = Find(hash, x); 			//调用Find(x)
    if (i > 0) return 0;			//数据元素x已经存在
    else if (i != -hash->tableSize)	//数据元素x不存在且哈希表未满
    {
        hash->ht[-i].data = x;		//数据元素赋值
        hash->ht[-i].info = Active;	//置活动标记
        hash->currentSize++;		//当前表项个数加1
        return 1;			//返回插入成功
    }
    else return 0;				//返回插入失败
}
int Delete(HashTable* hash, DataType x)		             //删除
{
    int i = Find(hash, x); 					//调用Find(x)
    if (i >= 0)					//查找到
    {
        hash->ht[i].info = Deleted;		//置删除标记
        hash->currentSize--;			//当前表项个数减1
        return 1;			//返回删除成功
    }
    else return 0;					//返回删除失败
}
void Destroy(HashTable* hash)                                               //删除
{
    free(hash->ht);
}
