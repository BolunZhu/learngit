#include <stdio.h>
#include <string.h>
int main()
{
    int n=0,m=0,pre,back;//n用于存储行数  m用于确定是否存在有确值的数
    int ch[26];
    char buf[5];
    while (scanf("%d",&n)) {
        if (n==-1) {
            return 0;
        }
        getchar();
        memset(ch,0,sizeof(ch));
        ch[0]=1;
        m=0;                            //错误出现在m没有重置，下一次循环的时候m还是1！！通过每次开头赋值为0消除！
        for (int i=0; i<n; i++) {
            fgets(buf,5,stdin);
            pre=buf[0]-97;
            back=buf[2]-97;
            ch[pre]=ch[back];
        }
        for (int i=0; i<26; i++) {
            if (ch[i])
            {
                if (m) {
                    printf(" %c",97+i);
                } else {
                    printf("%c",97+i);
                }
                m=1;
                
            }
        }
        if (!m) {
            printf("none");
        }
        printf("\n");
    }
    
    /*char buf[5];  //for debug
    fgets(buf, 5, stdin);
    
    for (int i=0; i<5; i++) {
        printf("%c",buf[i]);
    }*/
    return 0;
}
