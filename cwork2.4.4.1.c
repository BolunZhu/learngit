#include <stdio.h>
//#define ZZXC

void exchange(int * a,int * b);
int GYS(int a,int b);

int main(){
    int a,b,c;
    scanf("%d%d",&a,&b);
    c=GYS(a,b);
    printf("最大公约数是%d\n",c);
    return 0;
}
#ifdef ZZXC
int GYS(int a, int b){
    if (a<b) {
        exchange(&a, &b);
    }
    if (a%b==0) {
        return b;
    }
    a=a%b;
    return GYS(a, b);
}
#endif

#ifndef ZZXC
int GYS(int a,int b){
    if (a==b) {
        return a;
    }
    if (a<b) {
        exchange(&a,&b);
    }
    a=a-b;
    return  GYS(a, b);
}
#endif

void exchange(int * a,int * b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
