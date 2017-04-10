#include <stdio.h>
void gd(int i);
int ss(int j);
int main(){
    int a,b;
    while ((scanf("%d%d",&a,&b)==2)&&b) {
        a=a+a%2;
        b=b-b%2;
        for (int i=a; i<=b; i=i+2) {
            gd(i);
        }
        printf("\n");
    }
    
    return 0;
}
void gd(int i){
    for (int j=3; j<i/2+1; j=j+2) {
        if (ss(j)&&ss(i-j)) {
            printf("%d=%d+%d\n",i,j,i-j);
            break;
        }
    }
}
int ss(int j){
    for (int i=2; i<(j/2+1); i++) {
        if (j%i==0) {
            return 0;
        }
    }
    return 1;
}
