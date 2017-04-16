#include <stdio.h>

int bt(long int a,long int b);

int main(){
    unsigned long int a,b;
    char ch;
    do {
        scanf("%ld%ld",&a,&b);
        printf("%d\n",bt(a, b));
        
    } while ((ch=getchar())!=EOF);
}
int bt(long int a,long int b){
    int num=0;
    while (a) {
        num=a%10;
        a=a/10;
        b--;
        if (b==0) {
            return num;
        }
    }
    return -1;
}
