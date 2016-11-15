//
//  queue.c
//  QueueImplement
//
//  Created by 朱博抡 on 2016/10/19.
//  Copyright © 2016年 朱博抡. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//局部函数
static void CopyToNode(Item item,Node *pn);
static void CopyToItem(Node *pn,Item*pi);

void InitializeQueue(Queue *pq)
{
    pq->front=pq->rear=NULL;
    pq->items=0;
}

bool QueueIsFull(const Queue*pq)
{
    return pq->items==MAXQUEUE;
}

bool QueueIsEmpty(const Queue*pq)
{
    return pq->items==0;
}

int QueueItemCount(const Queue*pq)
{
    return pq->items;
}

bool EnQueue (Item item,Queue *pq)
{
    Node *pnew;
    if (QueueIsFull(pq)) {
        return false;
    }
    pnew=(Node*)malloc(sizeof(Node));
    if (pnew==NULL) {
        fprintf(stderr,"fail to allocate memory");
        exit(1);
    }
    CopyToNode(item, pnew);//将参数中输入的数据复制到pnew所分配的内存中
    if (QueueIsEmpty(pq))//如果队列空只需设置队列首项为pnew
        pq->front=pnew;
     else                   //否则设置队列末项中指向下一项的指针指向pnew
        pq->rear->next=pnew;
    pq->rear=pnew;         //将最后一项设置为pnew
    pq->items++;            //总项数加一
    
    return true;
    
}

bool DeQueue(Item *pitem,Queue*pq)
{
    Node*pt;
    if (QueueIsEmpty(pq))
        return false;
    CopyToItem(pq->front, pitem);//将删除的Item值赋给*pitem 便于之后返回删除的值时什么
    pt=pq->front;
    pq->front=pq->front->next;
    free(pt);
    pq->items--;
    if (pq->items==0) {
        pq->rear=NULL;
    }
    return true;
}

void EmptyTheQueue(Queue*pq)
{
    Item dummy;
    while (!QueueIsEmpty(pq)) {
        DeQueue(&dummy, pq);
    }
}

//局部函数
static void CopyToNode(Item item,Node*pn)
{
    pn->item=item;
}
static void CopyToItem(Node* pn,Item*pi)
{
    *pi=pn->item;
}
