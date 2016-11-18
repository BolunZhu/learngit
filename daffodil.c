include <stdio.h>
int main(void)
{
    for (int i=100; i<1000; i++) {
        int a=i/100;
        int b=(i/10)%10;
        int c=i%10;
        a=a*a*a;
        b=b*b*b;
        c=c*c*c;
        if (i==a+b+c) {
            printf("%d\n",i);
        }
    }
    return 0;
}
