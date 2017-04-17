#include <stdio.h>
#include <ctype.h>
#define cc(a,b){a=b%2;}

int main(){
    char c;
    int CHANCE=0,flag=1;
    while ((c=getchar())!=EOF) {
        if (flag==1) {
            cc(CHANCE, c);
            flag=0;
        }
        if (c=='\n') {
            flag=1;
        }
        if (CHANCE==0) {
            putchar(c);
        } else {
            if (isupper(c)) {
                putchar(c-'A'+'a');
                continue;
            }
            if (islower(c)) {
                putchar(c-'a'+'A');
                continue;
            }
            putchar(c);
        }
    }
    return 0;
}
