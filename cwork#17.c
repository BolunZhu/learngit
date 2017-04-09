#include <stdio.h>

int main(){
    int n,m,y,b,max,min;
    while (scanf("%d%d",&n,&m)==2&&(n||m)){
        if (n==m) {
            printf("%d %d\n",n,n);
            continue;
        }
        if (n>m) {
            max=n;
            min=m;
        }
        else{
            max=m;
            min=n;
        }
        for (int i=1; i<=min; i++) {
            if (n%i==0&&m%i==0) {
                y=i;
            }
        }
        for (int i=m*n; i>=max; i--) {
            if (i%n==0&&i%m==0) {
                b=i;
            }
        }
        printf("%d %d\n",y,b);
    }
    return 0;
}

