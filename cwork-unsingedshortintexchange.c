#include<stdio.h>


int main()
{
    int n;
    unsigned short int m=5678;
    scanf("%d",&n);
    for (int i=0;i<n; i++) {
        scanf("%hu",&m);
        m=(0xf000&m)>>12|(0x000f&m)<<12|(0x0ff0&m);
        printf("%hu\n",m);
    }
    
    return  0;
}
