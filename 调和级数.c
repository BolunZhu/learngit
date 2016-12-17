#include <stdio.h>
#include <string.h>

int main()
{
    int num=0;
    double sum;
    while (scanf("%d",&num)==1) {
        int i;
        sum=0;
        for (i=1; sum<=num; i++) {
            sum+=1.0/i;
        }
        printf("%d\n",i-1);
    }
    return 0;
}
