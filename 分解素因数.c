#include <stdio.h>
#include <string.h>

int main()
{
    int k=0,n,num,min;
    scanf("%d",&k);
    while (k--) {
        n=0;
        num=0;
        min=2;
        
        scanf("%d",&num);
        
        while (num>=min) {
            if (num%min==0) {
                num=num/min;
                if (n==0) {
                    printf("%d",min);
                } else {
                    printf("*%d",min);
                }
                n++;
            }
            else min++;
        }
        printf("\n");
    }
    return 0;
}
