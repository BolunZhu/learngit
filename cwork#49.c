#include <stdio.h>

int main(){
    int n=0;
    char ch[20][100]={0};
    char sh[2000]={0};
    char *p;
    while (scanf("%d",&n)&&n) {
        getchar();
        for (int i=0; i<n; i++) {
            fgets(ch[i], 100, stdin);
            for (int j=99; j>-1; j--) {
                if (ch[i][j]=='\n') {
                    ch[i][j]=0;
                }
            }
        }
        p=sh;
        for (int i=0; i<20; i++) {
            if(ch[i][0]==0){
                break;
            }
            for (int j=0; ch[i][j]&&j<100; j++) {
                *(p++)=ch[i][j];
            }
        }
        *p=0;
        printf("%s\n",sh);
    }
    return 0;
}
