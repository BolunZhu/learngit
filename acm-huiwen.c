nclude <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
int ds[9] = {2,3,4,5,6,7,8,9,10};
int circle(int n,int d);
int ishui(int n);
int main()
{
    int T,N,S;
    while (scanf("%d",&T)==1&&T) {
        for (int i=1; i<=T; i++) {
            scanf("%d%d",&N,&S);
            printf("Case #%d:\n",i);
            int times=0;
            for (int j=S+1; times<N; j++) {
                if (ishui(j)) {
                    printf("%d\n",j);
                    times++;
                
                }
                
            }
        }
    }
    return 0;
}




int ishui(int n)
{

    //要被判断的正整数
    
    //保存进制数
    int i = 0;
    int ci=0;
    for(i = 0;i < sizeof(ds)/sizeof(ds[0]);i++){
        int isCircle = circle(n,ds[i]);
        
        if (isCircle) {
            ci++;
        }
        if (ci==2) {
            return 1;
        }
    }
    
    return 0;
}

int circle(int n,int d){
    
    int s = 0;
    int m = n;
    
    while(m){
        s = s * d + m % d;
        m /= d;
    }
    
    return s == n;
}
