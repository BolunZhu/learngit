#include <stdio.h>
int converse(char * ch);
int inttochar(char * ch,int num);
int main(){
    int n,num;
    char ch[65];
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&num);
        if (num<0) {
            //写出-(num-1)的二进制再取反
            inttochar(ch, -num-1);
            converse(ch);
        }
        else{
            inttochar(ch, num);
        }
        printf("%s\n",ch);
    }
    return 0;
}
int inttochar(char * ch,int num){
    for (int i=sizeof(int)*8-1; i>=0; i--) {
        ch[i]='0'+num%2;
        num=num/2;
    }
    return 0;
}
int converse(char * ch){
    int i=0;
    while (ch[i]!='\0') {
        if (ch[i]=='0') {
            ch[i]='1';
        } else {
            ch[i]='0';
        }
        i++;
    }
    return 0;
}
