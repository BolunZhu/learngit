#include <stdio.h>
int GYS(int a, int b);
int main(){
    int a,b;
    while (scanf("%d%d",&a,&b)==2&&a) {
        printf("%d\n",GYS(a,b));
    }
    return 0;
}
int GYS(int a, int b){
    int temp;
    if (a<b) {
        temp=a;
        a=b;
        b=temp;
    }
    if (a%b==0) {
        return b;
    }
    a=a%b;
    return GYS(a, b);
}
