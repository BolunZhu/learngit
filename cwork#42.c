#include <stdio.h>
int inttochar(char * ch,int num);
int main(){
    int n,num[100];
    char ch[65];
    ch[sizeof(int)*8]='\0';
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&num[i]);
    }
    for (int i=0; i<n; i++) {
        inttochar(ch, num[i]);
        printf("%s\n",ch);
    }
    return 0;
}
int inttochar(char * ch,int num){
    int ruler=1;
    int a=0;
    for (int i=sizeof(int)*8-1; i>=0; i--) {
        //
        a=(ruler&num)+'0';
        ch[i]=(char)a;
        //
        ch[i]=(ruler&num)+'0';
        num=num>>1;
    }
    return 0;
}
