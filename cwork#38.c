#include <stdio.h>
#include <string.h>
#include <ctype.h>
int sixteen(char a);
int main(){
    int n;
    char ch[20];
    scanf("%d",&n);
    for (int i=0,sum; i<n; i++) {
        scanf("%s",ch);
        sum=0;
        for (int j=2; j<strlen(ch); j++) {
            sum=sum*16;
            sum+=sixteen(ch[j]);
        }
        printf("%d\n",sum);
    }
    return 0;
}
int sixteen(char a){
    if (isdigit(a)) {
        return a-'0';
    }
    if (islower(a)) {
        return a-'a'+10;
    }
    if (isupper(a)) {
        return a-'A'+10;
    }
    return 0;
}
