//
//  main.c
//  QueueImplement
//
//  Created by 朱博抡 on 2016/10/19.
//  Copyright © 2016年 朱博抡. All rights reserved.
//

#include <stdio.h>
#include "queue.h"


int main(int argc, const char * argv[]) {
    Queue line;
    Item temp;
    char ch;
    
    InitializeQueue(&line);
    
    puts("Testing the Queue interface,Type 'a' to add a value");
    puts("type 'd' to delete a value,and type q to quit.");
    
    while ((ch=getchar())!='q') {
        if(ch!='a'&&ch!='d')
            continue;
        if (ch=='a') {
            printf("请输入要加入到队列的数\n");
            scanf("%d",&temp);
            if (!QueueIsFull(&line)) {
                printf("你加入了%d至队列中\n",temp);
                EnQueue(temp, &line);
            }
            else
                puts("Queue is full!");
        }
        if (ch=='d') {
            if (!QueueIsEmpty(&line)) {
                DeQueue(&temp, &line);
                printf("你将队列中的%d删除了\n",temp);
            } else {
                printf("队列已空，无法删除\n");
            }
        }
        printf("队列中还有%d个项\n",QueueItemCount(&line));
        puts("type 'a' to add,'d' to delete,'q' to quit.");
    }
    EmptyTheQueue(&line);
    puts("bye!");
    return 0;
}
