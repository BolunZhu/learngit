#include <stdio.h>
#include <string.h>
#define maxn 101


int main()
{
    int m,n;      //m行n字符
    char ch[maxn][maxn];
    while (scanf("%d%d",&m,&n)==2&&m) {
        memset(ch, '0', sizeof(ch));
        getchar();
        for (int i=1; i<m+1; i++) {
            for (int j=1; j<n+1; j++) {
                scanf("%c",&ch[i][j]);
            }
            getchar();
        }
        //双层for 结束
        for (int i=1; i<m+1; i++)
        {
            for (int j=1; j<n+1; j++)
            {
                if (ch[i][j]=='.') {
                    ch[i][j]='0';
                }
                //if结束
            }
        }//双层for结束
        for (int i=1; i<m+1; i++)
        {
            for (int j=1; j<n+1; j++)
            {
                if(ch[i][j]=='*')
                {
                    if(ch[i-1][j-1]!='*') ch[i-1][j-1]++;
                    if(ch[i-1][j]!='*') ch[i-1][j]++;
                    if(ch[i-1][j+1]!='*') ch[i-1][j+1]++;
                    if(ch[i][j-1]!='*') ch[i][j-1]++;
                    if(ch[i][j+1]!='*') ch[i][j+1]++;
                    if(ch[i+1][j-1]!='*') ch[i+1][j-1]++;
                    if(ch[i+1][j]!='*') ch[i+1][j]++;
                    if(ch[i+1][j+1]!='*') ch[i+1][j+1]++;
                }//if结束
            }
        }//双层for结束
        for (int i=1; i<m+1; i++)
        {
            for (int j=1; j<n+1; j++)
            {
                printf("%c",ch[i][j]);
            }
            printf("\n");
        }//双层for结束
        printf("\n");
    }//while结束
    return 0;
}
