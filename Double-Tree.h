//
//  Double-Tree.h
//  testplayground
//
//  Created by 朱博抡 on 2016/11/25.
//  Copyright © 2016年 朱博抡. All rights reserved.
//

#ifndef Double_Tree_h
#define Double_Tree_h

#include <stdio.h>
#include<stdbool.h>
typedef int Item;
typedef struct tree
{
    struct tree * head;
    struct tree * left;
    struct tree * right;
    Item item;
}Tree;
//初始化二叉树
//返回值为一个头指针root指向初始化后的数组
struct tree* TreeInitial(void);
//给出他的父节点的指针和判别左右的int值
//0为左1为右
//将其头指向父节点，并赋值
int TreeInsert(struct tree* root,struct tree* head,Item item,int right);
//给出节点的指针
//若节点为空则直接返回0
//若节点不为空但无子节点则free该节点
//若存在子节点则递归调用改函数将子节点删除
int TreeDelete(struct tree* p);

bool IsEmpty(struct tree* root);

#endif /* Double_Tree_h */
