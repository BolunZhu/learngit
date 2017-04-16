#include <stdio.h>
int i=1;
void hailstone(int n);
int main(){
    int n;
    while (scanf("%d",&n)&&n) {
        i=1;
        hailstone(n);
        printf("\n");
    }
}

void hailstone(int n){
    printf("%5d",n);
    if (i%6==0) {
        printf("\n");
    }
    if (n==1) {
        if (i%6) {
            printf("\n");
        }
        return;
    }
    if (n%2) {
        n=n*3+1;
    }
    else{
        n=n/2;
    }
    
    i++;
    hailstone(n);
    return;
}
