#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    int flag=1;
    char c;
    FILE * f1=NULL;
    f1=fopen("test.txt", "w");
    if(!f1){
        return 1;
    }
    while ((c=getchar())!=EOF) {
        if (flag==1) {
            if (islower(c)) {
                c=c+'A'-'a';
            }
        }
        if (c==' '||c=='\n') {
            flag=1;
        }
        else{
            flag=0;
        }
        fputc(c, f1);
    }
    fputc(0, f1);
    fclose(f1);
    return 0;
}
