#include <stdio.h>

int main(){
    int n,k;
    int ch[60];
    do {
        scanf("%d%d",&n,&k);
        for (int i=0; i<n; i++) {
            scanf("%d",&ch[i]);
        }
        for (int i=0; i<n-k; i++) {
            for (int j=0,tmp1,tmp2=ch[n-1]; j<n; j++) {
                tmp1=ch[j];
                ch[j]=tmp2;
                tmp2=tmp1;
            }
        }
        for (int i=0; i<n-1; i++) {
            printf("%d ",ch[i]);
        }
        printf("%d\n",ch[n-1]);
    } while (getchar()!=EOF);
}
