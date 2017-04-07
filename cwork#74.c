#include <stdio.h>
int ss[101]={0};
int gd(int m);
int main()
{
    int n,m;
    for (int i=2; i<101; i++) {
        for (int j=2; i*j<101; j++) {
            ss[i*j]=1;
        }
    }
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&m);
        gd(m);
    }
    
    return 0;
}
int gd(int m){
    for (int j=2; j<101; j++) {
        if (ss[j]==0) {
            if (ss[m-j]==0) {
                printf("%d=%d+%d\n",m,j,m-j);
                return 0;
            }
        }
    }
    return 0;
}
