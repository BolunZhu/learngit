include<stdio.h>

int main (void)
{
    int n;
    while(scanf("%d",&n)==1&&n){
        while (n>0) {
        printf("%d",n%10);
        n=n/10;
        }
        printf("\n");
    }
    return 0;
}

