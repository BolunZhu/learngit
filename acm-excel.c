nclude <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main()
{
    int T,m;
    long long num;
    char ch[20];
    scanf("%d",&T);
    for (int i=1; i<=T; i++) {
        long long n=0;
        memset(ch, 0, sizeof(ch));
        scanf("%s",ch);
        printf("Case #%d: ",i);
        if (isalpha(ch[0])) {
            n=ch[0]-64;
            for (int j=1; isalpha(ch[j]); j++) {
                n=26*n+ch[j]-64;
            }
            printf("%lld",n);
        } else {
            num=ch[0]-48;
            m=0;
            for (int j=1; isdigit(ch[j]); j++) {
                num=num*10+ch[j]-48;
            }
            //num--;
            for (int j=0; num/26; j++) {
                if (num%26==0) {
                    ch[j]='Z';
                    num=num/26-1;
                }
                else{
                    ch[j]=num%26+64;
                    num=num/26;}
                m++;
            }
            if (num<=0) {
                m--;
            }else{
            ch[m]=num%26+64;
                if (ch[m]=='@')ch[m]='Z';}
            for (int j=m; j>=0; j--) {
                printf("%c",ch[j]);
            }
        }
        if (i!=T) {
            printf("\n");
        }
    }
    return 0;
}
