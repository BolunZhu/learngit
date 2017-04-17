#include <stdio.h>
#include <string.h>
int huiwen(char * begin,char * end);
int main(){
    int n;
    char ch[200];
    scanf("%d",&n);
    getchar();
    for (int i=0,a=0; i<n; i++) {
        fgets(ch, 199, stdin);
        a=huiwen(ch,&ch[strlen(ch)-2]);
        if (a==1) {
            printf("Yes!\n");
        }else{
            printf("No!\n");
        }
    }
}
int huiwen(char * begin,char * end){
    if((end-begin)<2){
        return 1;
    }
    if (*begin!=*end) {
        return 0;
    }
    return huiwen(begin+1, end-1);
}
