//
//  Double-Tree.c
//  testplayground
//
//  Created by 朱博抡 on 2016/11/25.
//  Copyright © 2016年 朱博抡. All rights reserved.
//

#include "Double-Tree.h"
#include <stdio.h>
#include <stdlib.h>



struct tree* TreeInitial(void)
{
    struct tree* root=NULL;
    return root;
}
int TreeInsert(struct tree * root,struct tree* head,Item item,int right)
{
    struct tree* p;
    p->item=item;
    p->head=head;
    p->left=NULL;
    p->right=NULL;
    if (head!=NULL) {
        if (right) {
            head->right=p;
        } else {
            head->left=p;
        }
    }
    else
    {
        
    }
    return 0;
}
bool IsEmpty(struct tree* root)
{
    if (root==NULL) {
        return true;
    }
    return false;
}
int TreeDelete(struct tree* p)
{
    if (p==NULL)
    {
        return 0;
    }
    if (p->left!=NULL||p->right!=NULL)
    {
        TreeDelete(p->left);
        TreeDelete(p->right);
        if(p->head->left==p)
        {
            p->head->left=NULL;
        }
        else
        {
            p->head->right=NULL;
        }
    }
    free(p);
    return 0;
}


