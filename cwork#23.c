#include <stdio.h>
int strle(char * a);
int main(){
    int n;
    char ch[100];
    scanf("%d",&n);
    getchar();
    for (int i=0; i<n; i++) {
        fgets(ch, 100, stdin);
        printf("%d\n",strle(ch)-1);
    }
    return 0;
}
int strle(char * a){
    if (*a=='\0') {
        return 0;
    }
    return 1+strle(a+1);
}
