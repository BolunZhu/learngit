nclude <stdio.h>
#include <string.h>

char st[10000][100];
int main()
{
    int T,n;
    scanf("%d",&T);
    for (int i=1; i<=T;i++) {
        scanf("%d",&n);
        printf("Case #%d: ",i);
        for (int j=0; j<n; j++) {
            memset(st[j],0, sizeof(st[j]));
            scanf("%s",st[j]);
        }
        for (int j=0; j<n; j++) {
            for (int k=1; st[j][k]>64; k++) {
                if (st[j][k]-st[j][0]<0) {
                    st[j][k]=st[j][k]-st[j][0]+27+26;
                }
                else{st[j][k]=st[j][k]-st[j][0]+27;}
            }
            st[j][0]=27;
            
        }
        int times=0;
        for (int j=0; j<n; j++) {
            if (st[j][0]==0) {
                continue;
            }
            int cis=0;
            for (int k=j+1; k<n; k++) {
                if(strcmp(st[j], st[k])==0)
                {
                    cis++;
                    memset(st[k], 0, sizeof(st[k]));
                }
            }
            times+=( cis*(cis+1) )/2;
        }
        printf("%d\n",times);
    }
    return 0;
}
