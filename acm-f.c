nclude <stdio.h>
#include <string.h>
int ch[10000];

int main()
{
    int T;
    int n,q;
    int pre,aft;
    int sum;
    scanf("%d",&T);
    for (int i=1; i<=T; i++) {
        scanf("%d%d",&n,&q);
        memset(ch, 0, sizeof(ch));
        
        for (int j=0; j<n; j++) {
            scanf("%d",&ch[j]);
        }
        printf("Case #%d:\n",i);
        for (int j=0; j<q-1; j++) {
            scanf("%d%d",&pre,&aft);
            sum=0;
            for (int m=pre-1; m<aft; m++) {
                sum+=ch[m];
            }
            printf("%d ",sum);
        }
        scanf("%d%d",&pre,&aft);
        sum=0;
        for (int m=pre-1; m<aft; m++) {
            sum+=ch[m];
        }
        printf("%d\n",sum);
    }
    return 0;
}

