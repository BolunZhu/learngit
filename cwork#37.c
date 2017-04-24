#include <stdio.h>
#include <string.h>
#include <ctype.h>
int mycpy(char * s,char * t,int n);
int main(){
    int N,n;
    char t[1001];
    char s[1001];
    scanf("%d",&N);
    getchar();
    for (int i=0; i<N; i++) {
        fgets(t, 1000, stdin);
        scanf("%d",&n);
        getchar();
        mycpy(s,t,n);
        puts(s);
    }
    return 0;
}
int mycpy(char * s,char * t,int n){
    for (int i=0; i<n; i++) {
        if (t[i]=='\n') {
            s[i]='\0';
            return 1;
        }
        s[i]=t[i];
    }
    s[n]='\0';
    return 1;
}
