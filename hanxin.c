#include <stdio.h>
int main(void)
{
    int a=0,b=0,c=0,num=1;
    while (scanf("%d",&a)==1) {
        scanf("%d",&b);
        scanf("%d",&c);
        for (int i=10; i<100; i++) {
            if ((a==i%3)&&(b==i%5)&&(c==i%7)) {
                printf("Case %d: %d\n",num,i);
                break;
            }
            if (i==99) {
                printf("Case %d: No answer\n",num);
            }
        }
        num++;
    }
    return 0;
}
