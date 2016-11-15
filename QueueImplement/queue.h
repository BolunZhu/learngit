//
//  Header.h
//  QueueImplement
//
//  Created by 朱博抡 on 2016/10/19.
//  Copyright © 2016年 朱博抡. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
#include<stdbool.h>
//此处插入Item的类型的定义，可以随需要修改 此处我用int
typedef int Item;
#define MAXQUEUE 10

typedef struct node
{
    Item item;
    struct node*next;
}Node;

typedef struct queue
{
    Node*front;
    Node*rear;
    int items;
}Queue;

void InitializeQueue(Queue*pq);

bool QueueIsFull(const Queue*pq);

bool QueueIsEmpty(const Queue*pq);

int QueueItemCount(const Queue*pq);

bool EnQueue(Item item,Queue*pq);

bool DeQueue(Item *pitem,Queue *pq);

void EmptyTheQueue(Queue*pq);

#endif /* Queue_h */
