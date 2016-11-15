//
//  main.c
//  test2
//
//  Created by 朱博抡 on 2016/10/11.
//  Copyright © 2016年 朱博抡. All rights reserved.
//

#include <stdio.h>
#define M 300

void first (char *st1,char *st2);//控制数字的输入
int  second (char *st1,char *st2);//检查输入是否正确
void third (char *st1,char *st2,char *st3,char *st4,char *st5,char *st6);//实现两个数字的相加 结果为st6
/*      1.将两个数以数组的形式输入 first函数
        2.                          
 */

int main(int argc, const char * argv[])
{
    char st1[M],st2[M];  //用于记录输入的数字
    char st3[M],st4[M];  //用于将数字倒序对齐
    char st5[M],st6[M];
    st5[0]='0';
    first(st1,st2);
    printf("输入的第一个数字是%s\n输入的第二个数字是%s\n",st1,st2); //测试first函数调用完成阶段两数字值
    while (second(st1, st2)==1) {     //调用second函数检查输入是否正确
        first(st1,st2);            //若返回值为1表示不正确则要求重新输入
    }
    third(st1, st2, st3, st4, st5,  st6);
    printf("两数之和为%s\n",st6);
    return 0;
}
void first (char *st1,char *st2) //控制数字的输入
{
    printf("请输入第一个数\n");
    scanf("%s",st1);
    printf("请输入第二个数\n");
    scanf("%s",st2);
}
int second (char *st1,char *st2)//检查输入是否正确
{
    unsigned int a,b,i=0;
    a=strlen(st1);
    b=strlen(st2);
    for (i=0; i<a&&st1[i]>='0'&&st1[i]<='9'; i++) {
        ;
    }
    if (i<a) {
        printf("输入有误，请重新输入两个数字");
        return 1;
    }
    for (i=0; i<b&&st2[i]>='0'&&st2[i]<='9'; i++) {
        ;
    }
    if (i<b) {
        printf("输入有误，请重新输入两个数字\n");
        return 1;
    }
    return 0;
}
void third (char *st1,char *st2,char *st3,char *st4,char *st5,char *st6)
{
    int i,j,a,b,x=0;
    a=strlen(st1);
    b=strlen(st2);
    for(i=a-1,j=0;i>=0;i--,j++)   //将st1中的数字倒序传给st3
    {
        st3[i]=st1[j];
    }
    for(i=b-1,j=0;i>=0;i--,j++)   //将st2中的数字倒序传给st4
    {
        st4[i]=st2[j];
    }

    if (a>=b) {                   //给位数少的数字的倒序后面用0补齐
        for (i=b; i<a; i++) {
            st4[i]='0';
        }
    }
    else {
        for (i=a; i<b; i++) {
            st3[i]='0';
        }
    }
    x= a>b? a:b;                   //确定最高位
    for (i=0; i<x; i++)            //将倒序后的两个数字相加
    {
        int c,d,f;
        c=st3[i]-'0';
        d=st4[i]-'0';
        f=c+d;
        st5[i+1]='0';              //提前将后一位数字初始化
        if (f>=10) {               //计算并且进位
            f-=10;
            st5[i+1]++;
        }
        st5[i]=f+'0'+(st5[i]-'0'); //防止忽略特殊的进位
        if (st5[i]>'9') {
            st5[i]-=10;
            st5[i+1]++;		
        }
    }
    for (i=strlen(st5)-1,j=0; i>=0; i--,j++) {  //将最终结果重新倒序还原
        st6[j]=st5[i];
    }
    if (st6[0]=='0') {                           //防止首位为0，将其替换为空格
        st6[0]='\ ';
    }
}
