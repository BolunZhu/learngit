#include <stdio.h>

int main (void)
{
    int n;
    scanf("%d",&n);
    while (getchar()!='\n') {
        ;
    }
    for (int i=0; i<n; i++) {
        char c;
        int flag=0;
        while ((c=getchar())!='\n'){
            if (c==' ') {
                if (flag==1) {
                    continue;
                }
                else{
                    flag=1;
                }
            }
            else{
                flag=0;
            }
            putchar(c);
        }
        putchar('\n');
    }
    
    return 0;
}
