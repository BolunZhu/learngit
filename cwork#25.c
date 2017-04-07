#include <stdio.h>

int main()
{
    double n,a;
    int m;
    while (scanf("%lf",&n)==1&&n) {
        a=0;
        m=(n-1)/1000;
        switch (m) {
            default:
                m=5;
                a=a+1000*0.20;
                n-=1000;
            case 4:
                a=a+1000*0.15;
                n-=1000;
            case 3:
                 a=a+1000*0.10;
                n-=1000;
            case 2:
                 a=a+1000*0.05;
                n-=1000;
            case 1:
                n-=1000;
                break;
            case 0:
                break;
           
        }
            a+= m*0.05*n;
        printf("%lf\n",a);
    }
    return 0;
}
