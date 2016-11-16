//
//  selectionsort.c
//  Selectionsort
//
//  Created by 朱博抡 on 2016/10/13.
//  Copyright © 2016年 朱博抡. All rights reserved.
//
/*大致思路如下
 1.排序函数 sort
    1.1比较函数
    1.2交换函数
 2.比较函数 less
 3.交换函数 exch
 4.输出函数 show
 5.有序检测函数 isSorted
 6.输入函数 readint
 7.主函数 main
    7.1输入函数
    7.2排序函数
    7.3有序检测函数
    7.4输出函数
*/
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define M 30
void exch(int a[],int i,int j);
void show(int a[]);
_Bool isSorted(int a[]);
_Bool less(int i,int j);
void readint(int a[]);
void sort(int a[]);
int main(int argc, const char * argv[])
{
    int a[M];
    readint(a);
    sort(a);
    if(isSorted(a))
    {
        printf("排序检查完成\n");
        show(a);
    }
    else
    {
        printf("排序有误，请检查\n");
    }
       return 0;
}
void exch(int a[],int i,int j)
{
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
}
void show (int a[])
{

    for (int i=0; i<M; i++) {
        printf("%d ",a[i]);
    
    }
    printf(" ");
}
_Bool isSorted (int a[])//判断大小函数
{
    for (int i=0; i<strlen(a); i++) {
        if (less(a[i], a[i-1])) {
            return false;
        };
    }
    return true;
}
_Bool less(int i,int j) //第一个参数小则返回true
{
    if (i<j) {
        return true ;
    }
    return false;
}
void readint(int a[])
{
    for (int i=0; i<M; i++) {
        if ((scanf("%d",&a[i]))==0) {
            printf("输入有误，请重新输入\n");
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF) ;
            i=-1;
        }
    }
    
}
void sort(int a[])
{
    int N=M;
    for (int i=0; i<N; i++) {  //将a[i]与后面的元素进行比较并且交换位置
        int min =i;
        for (int j =i+1;j<N;j++)
            if (less(a[j], a[min])) min = j;
        exch(a, i, min);
    }
    
}
