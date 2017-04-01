#include<stdio.h>
int yh(int x,int y);
int main (void)
{
    int n;
    while (scanf("%d",&n)==1&&n>0) {
        for (int i=1; i<=n; i++) {
            for (int j=0; j<2*(n-i); j++) {
                printf(" ");
            }
            for (int j=0; j<i; j++) {
                if (j==0) {
                    printf("%d",yh(i-1, j));
                }
                else{
                    printf("%4d",yh(i-1,j));
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
int yh(int x,int y){
    if (y==0) {
        return 1;
    }
    return (x-y+1)*yh(x, y-1)/y;
}
