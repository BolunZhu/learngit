#include <stdio.h>
int thr(int a,int b);
int tm,point;
int bitsum(int a,int b);
int main(){
    int n,a,b;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d%d",&a,&b);
        tm=0;
        point=0;
        thr(a,b);
    }
    return 0;
}
int thr(int a,int b){
    int sum=bitsum(a,b);
    tm++;
    if (tm==1) {
        if (sum==7||sum==11) {
            printf("success!\n");
            return 0;
        }
        if (sum==2||sum==3||sum==12) {
            printf("fail!\n");
            return 0;
        }
        point=sum;
        thr(a+tm, b+tm);
    }
    else {
        if (sum==point) {
            printf("success!\n");
            return 0;
        }
        if (sum==7) {
            printf("fail!\n");
            return 0;
        }
        thr(a+tm, b+tm);
    }
    return 0;
}
int bitsum(int a,int b){
    int ax=0,bx=0;
    while (a) {
        ax+=a%10;
        a=a/10;
    }
    while (b) {
        bx+=b%10;
        b=b/10;
    }
    return ((ax)%6+(bx)%6+2);
}
